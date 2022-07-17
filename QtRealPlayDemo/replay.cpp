/*
this program is based on i8_playSDK.h and provided functions
I8H_SDK provides essential http toolkits.
*/

#include "replay.hpp"

replay::replay(HANDLE handle, QWidget * parent) : QWidget(parent) {
	UHandle = handle;

	ui.setupUi(this);
	initSDK();
	ui.slider->setEnabled(false);
	setupSlider();

	connect(ui.playBtn, SIGNAL(clicked()), this, SLOT(playClicked()));
	connect(ui.closeBtn, SIGNAL(clicked()), this, SLOT(close()));
	connect(ui.slider, SIGNAL(sliderPressed()), this, SLOT(slider_progress_clicked()) );
	connect(ui.slider, &QAbstractSlider::sliderMoved, this, &replay::slider_progress_moved);
	connect(ui.slider, SIGNAL(sliderReleased()), this, SLOT(slider_progress_released()));
}

replay::~replay() {
	ConvertMP4_Demuxer_Close(reHandle);
	delete timer;
}


//initialization, including definition of essential variables
bool replay::initSDK() {
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

	//info = NULL;

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

//after log in, use i8 to play video in widget
void replay::playClicked() {
	I8H_CLIENTINFO struClientInfo;

	HANDLE hRealPlay = NULL;

	
	memset(&struClientInfo, 0, sizeof(I8H_CLIENTINFO));

	int nChannel = 1;

	struClientInfo.lChannel = nChannel;
//	if (m_lpClientInfo != NULL)
//	{
	I8H_DEVICEINFO strDevInfo = { 0 };
	char *szServerIp = "10.0.0.239";
	int serverPort = int(80);
	char *szUserName = "admin";
	char *szPassWord = "123456";

	//HANDLE hUserId = I8H_SDK_Login(szServerIp, serverPort, szUserName, szPassWord, &strDevInfo);
	
	
	reHandle = ConvertMP4_Demuxer_Open(filename, 0);
	

	setupSlider();
	
		hRealPlay = I8H_SDK_RealPlay(UHandle, &struClientInfo, fStreamDataCallBack, this);

		qDebug() << "starting replay";
		I8_MP4Play_Play(m_dwPort, (HWND)ui.reViewer->winId());



	return;
}

//call back function. provides information of each frame. this is called every frame
VOID CALLBACK replay::fStreamDataCallBack(HANDLE hHandle, DWORD dwOption, DWORD dwDataType, BYTE *lpBuffer, DWORD dwBufferSize, LPVOID lpUser) {
	
	
	replay* lpDialog = (replay*)lpUser;

	int size;
	BYTE *buffer = new BYTE;
	ConvertMP4_Demuxer_getPacket(lpDialog->reHandle, buffer, size);
	lpDialog->i8h = (AntsFrameHeader*)buffer;
	lpDialog->playTime = lpDialog->i8h->uiFrameTime;
	I8_MP4Play_InputData(lpDialog->m_dwPort, (PBYTE)buffer, size);

	delete buffer;

}

void replay::setupSlider() {


	ui.slider->setEnabled(true);
	ui.slider->setRange(0, maxValue);
	timer = new QTimer();
	timer->setInterval(1000);
	timer->start();

	duration = ConvertMP4_GetFileDuration(filename);



	connect(timer, SIGNAL(timeout()), this, SLOT(onTimerOut()));


}

void replay::onTimerOut() {
	ui.slider->setValue(playTime *maxValue / (duration/1000/1000));
}


void replay::slider_progress_clicked()
{
	timer->stop();
	ConvertMP4_Demuxer_Seek(reHandle, qreal(ui.slider->value()) / maxValue*(duration / 1000 / 1000));
	qDebug() << qreal(ui.slider->value()) / maxValue*(duration / 1000 / 1000);
	qDebug() << ui.slider->value();
}

void replay::slider_progress_moved()
{
	ConvertMP4_Demuxer_Seek(reHandle, qreal(ui.slider->value()) / maxValue*(duration / 1000 / 1000));
	//qDebug()<<ui.slider->value() / maxValue*(duration / 1000 / 1000);
}

void replay::slider_progress_released()
{
	timer->start();
}