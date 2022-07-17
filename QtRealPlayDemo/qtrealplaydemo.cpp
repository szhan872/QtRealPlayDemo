#define G711U_LEN 320
#define PCM_FRAME_LEN 640
#include "qtrealplaydemo.h"
#include <QMessageBox>
#include <QDebug>
#include <direct.h>
#include  <qapplication.h>

void Http_RealData_CallBack(long hRtspHandle, unsigned long dwDataType, unsigned long dwProp, unsigned char *lpBuffer, unsigned long dwBufSize, void* lpUser) {
	//	if (dwDataType == ANTS_RTSP_DATATYPE_STREAMDATA_ANTSCOMB) {

	if (dwDataType == ANTS_RTSP_DATATYPE_AUDIOSTREAMDATA || ANTS_RTSP_DATATYPE_TALK_AUDIODATA == dwDataType)
	{
		AntsFrameHeader *i8Header = (AntsFrameHeader *)lpBuffer;
		///////////
		QtRealPlayDemo *mainWidget = (QtRealPlayDemo*)lpUser;

		int nCount = 4;
		BOOL bInputData = FALSE;
		int frameLen = sizeof(AntsIPCFrameHeader_T) + G711U_LEN;
		/////////

		for (int index = 0; index < dwBufSize / frameLen; index++) {
			AntsIPCFrameHeader_T *i8header = (AntsIPCFrameHeader_T*)(lpBuffer + index*frameLen);

			if (i8header->uiFrameType == 1)
			{
				if (I8_MP4Play_InputAudioEX(lpBuffer, G711U_LEN, i8header->uMedia.struAudioHeader.cCodecId)) {
					I8_MP4Play_PlaySoundEX();
				}
			}
		}

		qDebug() << mainWidget->_port << *lpBuffer;
	}

}

QtRealPlayDemo::QtRealPlayDemo(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	//setup UI
	setUpForm();
	m_bInit = false;

	m_bInit = initSDK();

	connect(ui.LoginButton, SIGNAL(clicked()), this, SLOT(login_clicked()));
	connect(ui.StartButton, SIGNAL(clicked()), this, SLOT(start_clicked()));
	connect(ui.StopButton, SIGNAL(clicked()), this, SLOT(close()));
	connect(ui.drawButton, SIGNAL(clicked()), this, SLOT(draw_clicked()));
	connect(ui.hangButton, SIGNAL(clicked()), this, SLOT(hang_clicked()));
	connect(ui.talkButton, SIGNAL(clicked()), this, SLOT(talk_clicked()));
	connect(ui.RecButton, SIGNAL(clicked()), this, SLOT(startMP4()));
	connect(ui.unRecBtn, SIGNAL(clicked()), this, SLOT(stopMP4()));
	connect(ui.ReplayBtn, SIGNAL(clicked()), this, SLOT(startReplay()));
	ui.Viewer->installEventFilter(this);
}

QtRealPlayDemo::~QtRealPlayDemo()
{
	ConvertMP4_uninit();
}

void QtRealPlayDemo::login_clicked() {
	char szServerIp[32] = {0};
	char szUserName[32] = { 0 };
	char szPassWord[32] = { 0 };
	//char szSerialNo[48] = {0};
	char szPort[32] = { 0 };
	int serverPort = 0;
	HANDLE hUserId = NULL;
	I8H_DEVICEINFO strDevInfo = {0};

	m_lpClientInfo = new I8H_BASIC_INFO;
	
	stringToChar(ui.IPBox->text(), szServerIp);
	//szServerIp[ba.length()] = "\0";
	stringToChar(ui.UserNameBox->text(), szUserName);
	//szUserName[ba.length()] = "\0";
	stringToChar(ui.PassWordBox->text(), szPassWord);
	//szPassWord[ba.length()] = "\0";
	stringToChar(ui.PortBox->text(), szPort);
	//szPort[ba.length()] = "\0";

	if (strlen(szServerIp) == 0 || strlen(szUserName) == 0 || strlen(szPort) == 0)
	{
		return;
	}
	serverPort = atoi(szPort);
	hUserId = I8H_SDK_Login(szServerIp, serverPort, szUserName, szPassWord, &strDevInfo);
	//qDebug() << I8H_SDK_GetLastError();
	if (hUserId == NULL) {
		if (m_lpClientInfo != NULL)
		{
			delete m_lpClientInfo;

			m_lpClientInfo = NULL;
		}

		ui.IPBox->setStyleSheet("border: 2px solid red");
		ui.UserNameBox->setStyleSheet("border: 2px solid red");
		ui.PassWordBox->setStyleSheet("border: 2px solid red");
		ui.PortBox->setStyleSheet("border: 2px solid red");
		QMessageBox::information(NULL, "", "Login Failed!",
			QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);

		return;
	}
	else {
		m_lpClientInfo->wChanNum = strDevInfo.wChanNum;

		m_lpClientInfo->hUserId = hUserId;

		ui.UserNameBox->setStyleSheet("border: 2px solid black");
		ui.PassWordBox->setStyleSheet("border: 2px solid black");
		ui.PortBox->setStyleSheet("border: 2px solid black");
		QMessageBox::information(NULL, "", "Login Success!",
			QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);

	}
}

void QtRealPlayDemo::start_clicked() {
	I8H_CLIENTINFO struClientInfo;

	HANDLE hRealPlay = NULL;

	memset(&struClientInfo, 0, sizeof(I8H_CLIENTINFO));

	int nChannel = 1;

	struClientInfo.lChannel = nChannel;
	if (m_lpClientInfo != NULL)
	{
		hRealPlay = I8H_SDK_RealPlay(m_lpClientInfo->hUserId, &struClientInfo, fStreamDataCallBack, this);

		if (hRealPlay != NULL)
		{
			I8_MP4Play_Play(m_dwPort, (HWND)ui.Viewer->winId());

			m_lpClientInfo->hRealPlay = hRealPlay;



		}
	}

	//playSound();


	return;
}

void QtRealPlayDemo::draw_clicked() {
	drawing();
}

void QtRealPlayDemo::setUpForm() {
	ui.IPBox->setText("10.0.0.5");
	ui.PortBox->setText("80");
	ui.UserNameBox->setText("admin");
	ui.PassWordBox->setText("123456");
}

//convert given qstring to allocated char.
void QtRealPlayDemo::stringToChar(QString str, char* ch) {
	QByteArray ba = str.toLatin1();//QString to char generic method
	memcpy(ch, ba.data(), ba.length());
}

bool QtRealPlayDemo::initSDK() {
	BOOL ret = FALSE;

	char *lpKeyPath = NULL;

	lpKeyPath = _getcwd(NULL, 0);

	I8H_INIT_PARAM struInitParam;

	memset(&struInitParam, 0, sizeof(I8H_INIT_PARAM));

	strcpy((char*)struInitParam.byKeyPath, QCoreApplication::applicationDirPath().toUtf8().data());

	strcat((char*)struInitParam.byKeyPath, "\\self.pem");

	if (lpKeyPath != NULL)
	{
		free(lpKeyPath);
	}

	struInitParam.bAsync = 1;

	m_dwPort = -1;

	m_lpClientInfo = NULL;

	BYTE byFileHeaders[28] = { 0x00,0x00,0x01,0xAA,0x03,0x00,0x00,0x00,0x19,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00 };

	m_dwPort = I8_MP4Play_GetFreePort();

	if (m_dwPort == -1)
	{
		return FALSE;
	}

	I8_MP4Play_SetStreamOpenMode(m_dwPort, I8_STREAME_REALTIME);

	I8_MP4Play_OpenStream(m_dwPort, byFileHeaders, sizeof(byFileHeaders), 2 * 1024 * 1024);

	I8_MP4Play_SetDisplayCallBack(m_dwPort, NULL);

	I8_MP4Play_SetPlayerBufNumber(m_dwPort, 100);

	ret = I8H_SDK_Initv2(&struInitParam);

	I8H_SDK_SetConnectTime(2, 2);

	return ret;
}

VOID CALLBACK QtRealPlayDemo::fStreamDataCallBack(HANDLE hHandle, DWORD dwOption, DWORD dwDataType, BYTE *lpBuffer, DWORD dwBufferSize, LPVOID lpUser)
{
	int nCount = 4;
	BOOL bInputData = FALSE;
	WORD wChannel = (dwOption >> 16) & 0xFFFF;
	WORD wStreameType = dwOption & 0xFF;
	int wFreePort = -1;
	QtRealPlayDemo* lpDialog = (QtRealPlayDemo*)lpUser;

	while (!bInputData && nCount)
	{
		bInputData = I8_MP4Play_InputData(lpDialog->m_dwPort, (PBYTE)lpBuffer, dwBufferSize);

		if (!bInputData)
		{
			nCount--;

			Sleep(10);

			continue;
		}

		break;
	}

	if (lpDialog->recordFlag && bInputData) {
		bool a = ConvertMP4_SavePacket(lpDialog->MP4Handle, lpBuffer, dwBufferSize);
	}
}

void QtRealPlayDemo::drawing() {
	int nCount = 4;
	BOOL drawFinish = FALSE;

	while (!drawFinish && nCount) {

		drawFinish = I8_MP4Play_RigisterDrawFunEx(m_dwPort, I8DRAWFUNEx, (LONG)this);
		if (!drawFinish)
		{
			nCount--;

			Sleep(10);

			continue;
		}
		break;
	}
}


LONG CALLBACK QtRealPlayDemo::I8DRAWFUNEx(long nPort, HDC hDC, unsigned int width, unsigned int height, LONG nUser) {
	QtRealPlayDemo *mainWidget = (QtRealPlayDemo*)nUser;
	HPEN hPen = CreatePen(PS_SOLID, 4, RGB(255, 0, 0));
	HPEN hOldPen = (HPEN)SelectObject(hDC, hPen);
	
	draw(hDC, mainWidget->rect, width, height, nUser);
	
	return NULL;
}

void QtRealPlayDemo::draw(HDC hDC, QRect rect, unsigned int width, unsigned int height, LONG nUser) {
	if ((rect.x() == 0 && rect.y() == 0) || (rect.width() == 0 && rect.height() == 0)) {
		return;
	}
	QtRealPlayDemo *mainWidget = (QtRealPlayDemo*)nUser;
	int UiWidth = mainWidget->ui.Viewer->width();
	int UiHeight = mainWidget->ui.Viewer->height();
	//QPoint point = mainWidget->ui.Viewer->pos();
	QPointF firstPos = QPointF(qreal(rect.x())/ UiWidth*width, qreal(rect.y())/ UiHeight*height);
	qDebug() << (rect.x() - mainWidget->ui.Viewer->pos().x());
	//qDebug() << (10 - 4) / 2;
	QPointF secondPos = QPointF(firstPos.x()+ qreal(rect.width())*width / UiWidth, firstPos.y() + qreal(rect.height())*height / UiHeight);
	//qDebug() << (int)firstPos.x();
	qDebug() << rect.width();
	//qDebug() << (int)secondPos.x();
	MoveToEx(hDC, (int)firstPos.x(), (int)firstPos.y(), NULL);
	LineTo(hDC, (int)secondPos.x(), (int)firstPos.y());
	LineTo(hDC, (int)secondPos.x(), (int)secondPos.y());
	LineTo(hDC, (int)firstPos.x(), (int)secondPos.y());
	LineTo(hDC, (int)firstPos.x(), (int)firstPos.y());
	//MoveToEx(hDC, rect.x(), rect.y(), NULL);

	
}

VOID CALLBACK VoiceDataCallBackV2(HANDLE hVoiceHandle, BYTE *lpBuffer, DWORD dwBufferSize, DWORD dwAudioFlag, LPVOID lpUser)
{
	QtRealPlayDemo *mainWidget = (QtRealPlayDemo*)lpUser;

	//mainWidget->_voiceHandle = (int)hVoiceHandle;
	
	int nCount = 4;
	BOOL bInputData = FALSE;
	int frameLen = sizeof(AntsIPCFrameHeader_T) + G711U_LEN;

	/*
	for (int index = 0; index < dwBufferSize/frameLen; index++) {
		AntsIPCFrameHeader_T *i8header = (AntsIPCFrameHeader_T*)(lpBuffer + index*frameLen);

		if (i8header->uiFrameType == 1) 
		{
			if (I8_MP4Play_InputAudioEX(lpBuffer, G711U_LEN, 1)) {
				I8_MP4Play_PlaySoundEX();
			}
		}
		return;
	}
	*/

	AntsIPCFrameHeader_T *i8header = (AntsIPCFrameHeader_T*)(lpBuffer + frameLen);

	
	I8_MP4Play_InputAudioEX(lpBuffer, G711U_LEN, 1);
	

	return VOID();
}


void QtRealPlayDemo::playSound()
{		
	HANDLE voice = I8H_SDK_StartVoiceComv2(m_lpClientInfo->hUserId, 0, VoiceDataCallBackV2, (LPVOID)this, 1);
	_voiceHandle = voice;
	int result = I8H_SDK_GetLastError();
	qDebug() << "I8H_SDK_GetLastError" << result;
}

void QtRealPlayDemo::sendSound()
{
	format.setSampleRate(8000);
	format.setChannelCount(1);
	format.setSampleSize(16);
	format.setCodec("audio/pcm");
	format.setByteOrder(QAudioFormat::LittleEndian);
	format.setSampleType(QAudioFormat::UnSignedInt);



	//recognize input audio device
	QList<QAudioDeviceInfo> devices = QAudioDeviceInfo::availableDevices(QAudio::AudioInput);

	//info = QAudioDeviceInfo::defaultInputDevice();
	info = devices[0];
	qDebug() << info.deviceName();
	if (!info.isFormatSupported(format))
	{
		format = info.nearestFormat(format);
	}
	//qDebug() << info.deviceName();
	input = new QAudioInput(format, this);
	//QTimer::singleShot(3000, this, SLOT(stopRecording()));
	//input->setBufferSize(640);
	audioInBuffer = input->start();
	//input->start(buffer);
	qDebug() << "/////////////start recording";
	if (audioInBuffer != NULL) {
		connect(audioInBuffer, SIGNAL(readyRead()), this, SLOT(audioCompress()));
	}
	
	
}

void QtRealPlayDemo::stopRecording() {
	disconnect(audioInBuffer, SIGNAL(readyRead()), this, SLOT(audioCompress()));
	input->stop();

	delete input;
	qDebug() << "record end";
}

void QtRealPlayDemo::startMP4() 
{

	ConvertMP4_init();
	recordFlag = true;
	
	char *fileName = "test.mp4";
	MP4Handle = ConvertMP4_Open(fileName);
	if (MP4Handle != NULL) 
	{
		qDebug() << "start downloading to " << fileName;
	}



	return;
}

void QtRealPlayDemo::stopMP4() {
	recordFlag = false;
	ConvertMP4_Close(MP4Handle);
	ConvertMP4_uninit();	//·´³õÊ¼»¯
	qDebug() << "stop downloading";
}


void QtRealPlayDemo::mousePressEvent(QMouseEvent *e) {
	qDebug() << ui.centralWidget->pos() << ui.groupBox->pos() << ui.Viewer->pos();
	origin = e->pos() - ui.centralWidget->pos() - ui.groupBox->pos() - ui.Viewer->pos();
}

void QtRealPlayDemo::mouseReleaseEvent(QMouseEvent *e) {
	//drawing();
}

void QtRealPlayDemo::mouseMoveEvent(QMouseEvent *e) {
	end = e->pos() - ui.centralWidget->pos() - ui.groupBox->pos() - ui.Viewer->pos();
	rect = QRect(origin, end);
	//drawing();
}

void QtRealPlayDemo::hang_clicked() {
	//HANDLE handle = HANDLE(_handle);
	qDebug()<< "comm hanged"<< I8H_SDK_StopVoiceCom(_voiceHandle);
	g711_release(m_lpG711_enc_state);
}

void QtRealPlayDemo::talk_clicked() {
	if (ui.talkButton->text().compare("talk") == 0) {
		//sendSound();
		ui.talkButton->setText("stop talk");
	}
	else {
		stopRecording();
		ui.talkButton->setText("talk");
	}
}

void QtRealPlayDemo::audioCompress() 
{
	QByteArray ba = audioInBuffer->readAll();
	int Isize = ba.size();
	qDebug()<<Isize;
	m_lpG711_enc_state = g711_init(NULL, G711_ULAW);

	if (Isize > 0) {
		char *pCh = ba.data();
		int iCount = Isize / PCM_FRAME_LEN;
		for (int i = 0; i < iCount; i++) 
		{
			int16_t *pSrcVoice = (int16_t *)(pCh + i*PCM_FRAME_LEN);
			uint8_t *pDstVoice = new uint8_t[G711U_LEN];

			int iEncReally = g711_encode(m_lpG711_enc_state, pDstVoice, pSrcVoice, PCM_FRAME_LEN / sizeof(int16_t));

			char codeId = 1;
			char sampleRate = 0;
			char bitRate = 0;
			char channels = 1;
			DWORD dwOpt = codeId | (sampleRate << 8) | (bitRate << 16) | (channels << 24);

			bool b = I8H_SDK_VoiceComSendDatav2(_voiceHandle, dwOpt, pDstVoice, PCM_FRAME_LEN);
			delete[] pDstVoice;
		}
	}
}

void QtRealPlayDemo::startReplay() {
	replay *re = new replay(m_lpClientInfo->hUserId);
	re->show();
}
