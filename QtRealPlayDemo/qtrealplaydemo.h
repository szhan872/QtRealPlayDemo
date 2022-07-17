#ifndef QTREALPLAYDEMO_H
#define QTREALPLAYDEMO_H

#include <QtWidgets/QMainWindow>
#include <QMouseEvent>
#include <QAudio>
#include <QAudioFormat>
#include <QAudioInput>
#include <QAudioOutput>
#include <QAudioRecorder>
#include <QAudioDeviceInfo>
#include <QTimer>
#include <QUrl>
#include <QAudioBuffer>
#include <QMediaRecorder>
#include <QCamera>
#include "I8H_SDK.h"
#include "I8_PlaySDK.h"
#include "ui_qtrealplaydemo.h"
#include "ants_ipc_api.h"
#include "rtspclient_api.h"
#include "ants_g711.h"
#include "convertMP4.h"
#include "replay.hpp"

#ifndef _TAGBASICINFO
#define _TAGBASICINFO
typedef struct _tagBasicInfo
{
	WORD wStreamType;
	WORD wChanNum;
	HANDLE hUserId;
	HANDLE hRealPlay;

}I8H_BASIC_INFO, *LPI8H_BASIC_INFO;
#endif

class QtRealPlayDemo : public QMainWindow
{
	Q_OBJECT

public:
	int _port;
	HANDLE _voiceHandle;

	QtRealPlayDemo(QWidget *parent = 0);
	~QtRealPlayDemo();

private:
	Ui::QtRealPlayDemoClass ui;
	LPI8H_BASIC_INFO m_lpClientInfo;
	QRect rect;
	QPoint origin;
	QPoint end;

	void setUpForm();
	void stringToChar(QString str, char* ch);

	bool m_bInit;
	bool initSDK();
	DWORD m_dwPort;

	//for audio part
	QAudioFormat format;
	QAudioDeviceInfo info;
	QAudioInput *input;
	QAudioOutput *outAudio;
	QFile outputFile;
	QFile *file;
	QAudioRecorder *audioRecorder;
	QIODevice* audioInBuffer;
	g711_state_t *m_lpG711_enc_state;
	QMediaRecorder *recorder;
	QCamera *camera;

	//convertMP4
	HANDLE MP4Handle;
	bool recordFlag = false;


	static VOID CALLBACK fStreamDataCallBack(HANDLE hHandle, DWORD dwOption, DWORD dwDataType, BYTE *lpBuffer, DWORD dwBufferSize, LPVOID lpUser);

	static LONG CALLBACK I8DRAWFUNEx(long nPort, HDC hDC, unsigned int width, unsigned int heigth, LONG nUser);


	void drawing();
	static void draw(HDC hDC, QRect rect, unsigned int width, unsigned int height, LONG nUser);

	void playSound();
	void sendSound();
	//void recordVideo();

	
	//replay
	bool Replaying;


	//mouse events
	void mousePressEvent(QMouseEvent *e);
	void mouseReleaseEvent(QMouseEvent *e);
	void mouseMoveEvent(QMouseEvent *e);


	private slots:
	void login_clicked();
	void start_clicked();
	void draw_clicked();
	void hang_clicked();
	void talk_clicked();
	void startReplay();
	void audioCompress();
	void stopRecording(); //intercom audio input 
	void startMP4();
	void stopMP4();

};
#endif // QTREALPLAYDEMO_H
