#pragma once
#include <QWidget>
#include "ui_replay.h"
#include "I8H_SDK.h"
#include "I8_PlaySDK.h"
#include "ants_g711.h"
#include "ui_qtrealplaydemo.h"
#include "ants_ipc_api.h"
#include <direct.h>
#include <QDebug>
#include <QTimer>
#include "convertMP4.h"
#include "rtspclient_api.h"

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

class replay : public QWidget {
	Q_OBJECT

public:
	replay(HANDLE handle, QWidget * parent = Q_NULLPTR);
	~replay();

private:
	Ui::replay ui;
	HANDLE UHandle;
	DWORD m_dwPort;
	HANDLE reHandle;
	QTimer *timer;
	
	char* filename = "test.mp4";

	//for mp4 time position;
	AntsFrameHeader *i8h;
	int playTime = 0;
	int maxValue = 1000;
	int duration = 1;

	bool initSDK();
	void setupSlider();


	static VOID CALLBACK fStreamDataCallBack(HANDLE hHandle, DWORD dwOption, DWORD dwDataType, BYTE *lpBuffer, DWORD dwBufferSize, LPVOID lpUser);

	void stringToChar(QString str, char* ch);
private slots:
	void playClicked();
	void onTimerOut();

	void slider_progress_clicked();

	void slider_progress_released();

	void slider_progress_moved();

};


