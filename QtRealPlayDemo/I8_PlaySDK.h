#ifndef _I8_PLAYSDK_
#define _I8_PLAYSDK_

#define  I8_MP4Play_NOERROR						0	//!û�д���
#define  I8_MP4Play_PARA_OVER				    	1	//!��������Ƿ���
#define  I8_MP4Play_ORDER_ERROR					2	//!����˳�򲻶ԣ�
#define  I8_MP4Play_DEC_VIDEO_ERROR				4	//!��Ƶ����ʧ�ܣ�
#define  I8_MP4Play_DEC_AUDIO_ERROR				5	//!��Ƶ����ʧ�ܣ�
#define  I8_MP4Play_SUPPORT_OPEN_ONLY	       		6	//!ֻ���ڲ������򲥷��ļ�ʱ����ʹ�ô˽ӿ�
#define  I8_MP4Play_OPEN_FILE_ERROR				7	//!�ļ�����ʧ�ܣ�
#define  I8_MP4Play_CREATE_OBJ_ERROR		 	8	//!�����߳��¼���ʧ�ܣ�
#define  I8_MP4Play_CREATE_DDRAW_ERROR			9	//!����directDrawʧ�ܣ�
#define  I8_MP4Play_CREATE_OFFSCREEN_ERROR    	10	//!������˻���ʧ�ܣ�
#define  I8_MP4Play_BUF_OVER			       		11	//!����������������ʧ�ܣ�
#define  I8_MP4Play_CREATE_SOUND_ERROR	       		12	//!������Ƶ�豸ʧ�ܣ�
#define  I8_MP4Play_SET_VOLUME_ERROR	       		13	//!��������ʧ�ܣ�
#define  I8_MP4Play_SUPPORT_FILE_ONLY	       		14	//!ֻ���ڲ����ļ�ʱ����ʹ�ô˽ӿڣ�
#define  I8_MP4Play_SUPPORT_STREAM_ONLY	   	15	//!ֻ���ڲ�����ʱ����ʹ�ô˽ӿڣ�
#define  I8_MP4Play_SYS_NOT_SUPPORT		   		16	//!ϵͳ��֧�֣�������ֻ�ܹ�����Pentium 3���ϣ�
#define  I8_MP4Play_FILEHEADER_UNKNOWN        		17	//!û���ļ�ͷ��
#define  I8_MP4Play_VERSION_INCORRECT	       		18	//!�������ͱ������汾����Ӧ��
#define  I8_MP4Play_INIT_DECODER_ERROR        		19	//!��ʼ��������ʧ�ܣ�
#define  I8_MP4Play_CHECK_FILE_ERROR	       		20	//!�����ļ�ͷβ����ʱû���ҵ���Ч���ݣ��ļ�̫�̻������޷�ʶ��
#define  I8_MP4Play_BLT_ERROR			       		22	//!λ����ʧ�ܣ�
#define  I8_MP4Play_UPDATE_ERROR		       		23	//!��ʾoverlayʧ�ܣ�

#define I8_STREAM_NO		 					0x0	//!�ļ���ʽ
#define I8_STREAME_FILE	 					0x1	//!������룬�ʺ��ļ�������	
#define I8_STREAME_REALTIME 					0x2	//!ʵʱ���룬�ʺϰ忨���ɵ�ʵʱ��������Ĭ��ֵ

//!����֡��Ϣ
typedef struct {
	DWORD nFrameNum;           	//!֡��
	unsigned	long	nTime;          
	unsigned	long	nFilePos;    	//!֡���ļ��е�λ��
}I8_FRAME_POS ,*LPI8_FRAME_POS;

//!����֡��Ϣ
typedef struct {
	DWORD nFrameNum;           		//!֡��
	unsigned	long	nTime;          
	unsigned	long	nFilePos;    		//!֡���ļ��е�λ�� 
}I8_FRAME_POSEX ,*LPI8_FRAME_POSEX;

//!֡��Ϣ
typedef struct{
	long nWidth;
	long nHeight;
	long nStamp;
	long nType;
	long nFrameRate;
}I8_FRAME_INFO,*LPI8_FRAME_INFO;


typedef int (CALLBACK *I8FASTBACKCALLBACK )(ULONG channelNumber);
typedef void (CALLBACK *I8DISPLAYCBFUN)(long nPort,char *pBuf,long nSize,long nWidth,long nHeight,long nType,long nReserved1,long nReserved2);
typedef void (CALLBACK *I8FILEREFDONE)(DWORD nPort,DWORD nUser);
typedef void (CALLBACK *I8DECCBFUN)(long nPort,char *pBuf,long nSize,I8_FRAME_INFO *pFrameInfo,long nReserved1,long nReserved2); 
typedef long (CALLBACK *I8DECCBFUNEx)(long nPort,const char *pBuf,long nSize,I8_FRAME_INFO *pFrameInfo,long lParam);
typedef void (CALLBACK *I8SOURCEBUFFUN)(long nPort,DWORD nBufSize,DWORD dwUser,void *pResvered);
typedef void (CALLBACK *I8DRAWFUN)(long nPort,HDC hDC,LONG nUser);
typedef long (CALLBACK *I8DRAWFUNEx)(long nPort,HDC hDC,unsigned int width , unsigned int heigth ,LONG nUser);

typedef void (CALLBACK *I8TIMECTRLFUN)(long nPort,unsigned char *pFrameHead ,unsigned char *buffer , int size , void *pUser);

#ifndef I8_T_YV420 
#define I8_T_YV420 0
#endif

#ifndef I8_T_YV422 
#define I8_T_YV422 1
#endif

#ifndef I8_T_YV444 
#define I8_T_YV444 2
#endif

#ifndef I8_T_AUDIO16
#define I8_T_AUDIO16 101
#endif

#ifndef I8_T_AUDIO16EX
#define I8_T_AUDIO16EX 102
#endif

BOOL __stdcall I8_MP4Play_InitDDraw(HWND hWnd);
BOOL __stdcall I8_MP4Play_RealeseDDraw();

BOOL __stdcall I8_MP4Play_OpenFile(LONG nPort,LPSTR sFileName);
BOOL __stdcall I8_MP4Play_CloseFile(LONG nPort);
BOOL __stdcall I8_MP4Play_Play(LONG nPort, HWND hWnd);
BOOL __stdcall I8_MP4Play_Stop(LONG nPort);
BOOL __stdcall I8_MP4Play_Pause(LONG nPort,DWORD nPause);
BOOL __stdcall I8_MP4Play_Fast(LONG nPort);
BOOL __stdcall I8_MP4Play_Slow(LONG nPort);
BOOL __stdcall I8_MP4Play_OneByOne(LONG nPort);

BOOL __stdcall I8_MP4Play_SetFileEndMsg(LONG nPort,HWND hWnd,UINT nMsg);
BOOL __stdcall I8_MP4Play_SetVolume(LONG nPort,WORD nVolume);
BOOL __stdcall I8_MP4Play_StopSound();
BOOL __stdcall I8_MP4Play_PlaySound(LONG nPort);
BOOL __stdcall I8_MP4Play_OpenStream(LONG nPort,PBYTE pFileHeadBuf,DWORD nSize,DWORD nBufPoolSize);
BOOL __stdcall I8_MP4Play_InputData(LONG nPort,PBYTE pBuf,DWORD nSize);
BOOL __stdcall I8_MP4Play_InputDataEx(LONG nPort,PBYTE pBuf,DWORD nSize);//����һ����֡����
BOOL __stdcall I8_MP4Play_CloseStream(LONG nPort);
int  __stdcall I8_MP4Play_GetCaps();
DWORD __stdcall I8_MP4Play_GetFileTime(LONG nPort);
DWORD __stdcall I8_MP4Play_GetPlayedTimeEx(LONG nPort);

DWORD __stdcall I8_MP4Play_GetCurrentFrameNum(LONG nPort);
BOOL __stdcall I8_MP4Play_SetPlayPos(LONG nPort,float fRelativePos);
float __stdcall I8_MP4Play_GetPlayPos(LONG nPort);
LONG __stdcall I8_MP4Play_GetStreamOpenMode(LONG nPort);
BOOL __stdcall I8_MP4Play_SetOverlayMode(LONG nPort,BOOL bOverlay,COLORREF colorKey);
LONG __stdcall I8_MP4Play_GetOverlayMode(LONG nPort);
COLORREF __stdcall I8_MP4Play_GetColorKey(LONG nPort);
WORD __stdcall I8_MP4Play_GetVolume(LONG nPort);
BOOL __stdcall I8_MP4Play_GetPictureQuality(LONG nPort,BOOL *bHighQuality);
BOOL __stdcall I8_MP4Play_OneByOneBack(LONG nPort);

BOOL __stdcall I8_MP4Play_SetCurrentFrameNum(LONG nPort,DWORD nFrameNum);
BOOL __stdcall I8_MP4Play_GetKeyFramePos(LONG nPort,DWORD nValue, DWORD nType, LPI8_FRAME_POS pFramePos);
BOOL __stdcall I8_MP4Play_GetNextKeyFramePos(LONG nPort,DWORD nValue, DWORD nType, LPI8_FRAME_POS pFramePos);
BOOL __stdcall I8_MP4Play_SetDisplayCallBack(LONG nPort,I8DISPLAYCBFUN DisplayCBFun);
BOOL __stdcall I8_MP4Play_SetFileRefCallBack(LONG nPort,I8FILEREFDONE FileRefDone,DWORD nUser);
BOOL __stdcall I8_MP4Play_ConvertToBmpFile(char * pBuf,long nSize,long nWidth,long nHeight,long nReserved1,long nReserved2,char *sFileName);
BOOL __stdcall I8_MP4Play_ConvertToBmpFileEx(char * pBuf,long nSize,long nWidth,long nHeight,long nType,long nReserved1,long nReserved2,char *sFileName);
BOOL __stdcall I8_MP4Play_ChangeContrast(LONG nPort,int degree);
BOOL __stdcall I8_MP4Play_ChangeBright(LONG nPort,int degree);
DWORD __stdcall I8_MP4Play_GetSdkVersion();
DWORD __stdcall I8_MP4Play_GetLastError(LONG nPort);

BOOL __stdcall I8_MP4Play_GetPictureSize(LONG nPort,LONG *pWidth,LONG *pHeight);
BOOL __stdcall I8_MP4Play_RefreshPlay(LONG nPort);
DWORD __stdcall I8_MP4Play_GetFileHeadLength();
DWORD __stdcall I8_MP4Play_GetPlayedTime(LONG nPort);
BOOL __stdcall I8_MP4Play_LocalZoom(LONG nPort,BOOL bLocalZoom,int Left,int Top,int Width,int Height);
BOOL __stdcall I8_MP4Play_SetDecCallBack(LONG nPort,I8DECCBFUN DecCBFun);
BOOL __stdcall I8_MP4Play_SetDecCallBackEx(LONG nPort,I8DECCBFUNEx DecCBFun);
DWORD __stdcall I8_MP4Play_GetSourceBufferRemain(LONG nPort);
BOOL __stdcall I8_MP4Play_ResetSourceBuffer(LONG nPort);
BOOL __stdcall I8_MP4Play_SetSourceBufCallBack(LONG nPort,DWORD nThreShold,I8SOURCEBUFFUN SourceBufFun,DWORD dwUser,void *pReserved);
BOOL __stdcall I8_MP4Play_ResetSourceBufFlag(LONG nPort);

BOOL __stdcall I8_MP4Play_SetStreamOpenMode(LONG nPort,DWORD nMode);
DWORD __stdcall I8_MP4Play_GetDisplayBuf(LONG nPort);
BOOL __stdcall I8_MP4Play_SetPlayedTimeEx(LONG nPort,DWORD nTime);
DWORD __stdcall I8_MP4Play_GetCurrentFrameRate(LONG nPort);
BOOL __stdcall I8_MP4Play_SetDisplayBuf(LONG nPort,DWORD nNum);
BOOL __stdcall I8_MP4Play_ThrowBFrameNum(LONG nPort,DWORD nNum);
BOOL __stdcall I8_MP4Play_PlaySoundShare(LONG nPort);
BOOL __stdcall I8_MP4Play_StopSoundShare(LONG nPort);
DWORD __stdcall I8_MP4Play_GetFileTotalFrames(LONG nPort);
BOOL __stdcall I8_MP4Play_SetPicQuality(LONG nPort,BOOL bHighQuality);

BOOL __stdcall I8_MP4Play_SetPlaySpeed(LONG nPort,int nSpeed);
void __stdcall I8_MP4Play_AutoSync(BOOL bSync);
BOOL __stdcall I8_MP4Play_RigisterDrawFun(LONG nPort,I8DRAWFUN DrawFun,LONG nUser);
BOOL __stdcall I8_MP4Play_RigisterDrawFunEx(LONG nPort,I8DRAWFUNEx DrawFun,LONG nUser);
BOOL __stdcall I8_MP4Play_GetKeyFramePosEx(LONG nPort,DWORD nValue, DWORD nType,RECT *rc, LPI8_FRAME_POS pFramePos);
BOOL __stdcall I8_MP4Play_SetDisplayRegion(LONG nPort,DWORD nRegionNum, RECT *pSrcRect, HWND hDestWnd, BOOL bEnable);
BOOL __stdcall I8_MP4Play_FastBack(LONG nPort,HWND hWnd,int nSpeed, I8FASTBACKCALLBACK pFastBackCallBack);

//!added by itman for HuXinHuTong 07-11-19
BOOL __stdcall I8_MP4Play_OpenStreamEx(LONG nPort,PBYTE pFileHeadBuf,DWORD nSize,DWORD nBufPoolSize,long lSpeedControl); 
BOOL __stdcall I8_MP4Play_GetPlaySpeed(LONG nPort,long *pSpeed);
BOOL __stdcall I8_MP4Play_Refresh(LONG nPort);
BOOL __stdcall I8_MP4Play_GetSysHead(LONG nPort,unsigned char *pSysHead,int *pSysLen);
BOOL __stdcall I8_MP4Play_StartRecord(LONG nPort,const char *sFileName);
BOOL __stdcall I8_MP4Play_StopRecord(LONG nPort);

//!added by itman for VideoAnalysis 2008-05-30
BOOL __stdcall I8_MP4Play_StopVideoAnalysis(LONG nPort, DWORD nStopVideoAnalysis );

//!add by sqy 2011-5-12
BOOL __stdcall I8_MP4Play_SetPlayerBufNumber(LONG nPort,DWORD dwBufNum);
BOOL __stdcall I8_MP4Play_SetAudioMode(DWORD dwMode);
DWORD __stdcall I8_MP4Play_GetPlayedOSDTime(LONG nPort);

BOOL __stdcall I8_MP4Play_SetColor(LONG nPort, DWORD nRegionNum, int nBrightness, int nContrast, int nSaturation, int nHue);
BOOL __stdcall I8_MP4Play_GetColor(LONG nPort, DWORD nRegionNum, int *pBrightness, int *pContrast, int *pSaturation, int *pHue);
int __stdcall I8_MP4Play_GetFreePort();
BOOL  __stdcall I8_MP4Play_IsFreePort(int nPort);

BOOL  __stdcall I8_MP4Play_SetOverlayMode();

BOOL __stdcall I8_MP4Play_PlaySoundEX();

BOOL __stdcall I8_MP4Play_StopSoundEX();

BOOL __stdcall I8_MP4Play_InputAudioEX(unsigned char *pbuffer , int nLen ,int ntype);

BOOL __stdcall I8_MP4Play_SetVolumeEX(WORD nVolume);

WORD __stdcall I8_MP4Play_GetVolumeEX();

BOOL __stdcall I8_MP4Play_SetRealPlayDelay(unsigned int MinDelayCount , unsigned int NormalDelayCount,unsigned int MaxDelayCount );

void  __stdcall I8_MP4Play_SetDecoderMode(int bfastdecoder);

//����ȥ����

BOOL  __stdcall I8_MP4Play_StartDefog(LONG nPort);

BOOL  __stdcall I8_MP4Play_SetDefogLevel(LONG nPort, int nlevel) ;

BOOL  __stdcall I8_MP4Play_StoptDefog(LONG nPort);

BOOL __stdcall I8_MP4Play_GetFileStartTime(LONG nPort , DWORD *pStartTime);

BOOL __stdcall I8_MP4Play_ConverRTPtoH264(unsigned char *InBuffer , int InSize , unsigned char *OutBuffer , int *OutSize);

BOOL __stdcall I8_MP4Play_SetTimeCtrlCallBack(LONG nPort,I8TIMECTRLFUN TimeCtrlCBFun,void *pUser);

//ת��YUV���ݳ�JPG�ļ�
BOOL __stdcall I8_MP4Play_ConvertToJpgFileEx(char * pBuf,long nSize,long nWidth,long nHeight,long nType,long nReserved1,long nReserved2,char *sFileName);

BOOL __stdcall I8_MP4Play_StartOSD(LONG nPort,char *pBuffer, int nLen);

BOOL __stdcall I8_MP4Play_StopOSD(LONG nPort);

BOOL __stdcall I8_MP4Play_GetPlayedOSDTimeEx(LONG nPort,unsigned int *uiFrameTime , unsigned int *uiFrameTickCount); //NVR 2.0 ��Ч

#endif

