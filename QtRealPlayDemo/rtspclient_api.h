#ifndef _RTSP_CLIENT_API_H_
#define _RTSP_CLIENT_API_H_

typedef enum
{
    ANTS_RTPTransProto_AUTO,
    ANTS_RTPTransProto_UDP,
    ANTS_RTPTransProto_MULTICAST,
    ANTS_RTPTransProto_TCP,
    ANTS_RTPTransProto_HTTP,
    ANTS_RTPTransProto_BUTT

}ANTS_RTPTransProto;

typedef enum
{
    ANTS_RTPClientCallbackType_Stream = 0,
    ANTS_RTPClientCallbackType_RTCP,
    ANTS_RTPClientCallbackType_Status,
    ANTS_RTPClientCallbackType_Error,
    ANTS_RTPClientCallbackType_BUTT
}ANTS_RTPClientCallbackType;


typedef enum
{
    
    ANTS_RTSP_STREAM_H264 = 0,
    ANTS_RTSP_STREAM_MPEG4,
    ANTS_RTSP_STREAM_JPEG,
    ANTS_RTSP_STREAM_G711A,
    ANTS_RTSP_STREAM_G711U,
    ANTS_RTSP_STREAM_G726 = 5,
    ANTS_RTSP_STREAM_AAC,
    ANTS_RTSP_STREAM_H265,
    ANTS_RTSP_STREAM_AntsComb,
    ANTS_RTSP_STREAM_APP = 20,
    ANTS_RTSP_STREAM_UNKNOW = 0x10000, //��16λΪ��Ӧ�ı����
}ANTS_RTSP_STREAM_TYPE;

typedef enum
{
    ANTS_RTSP_RTCP_Video,
    ANTS_RTSP_RTCP_Audio,
}ANTS_RTSP_RTCPTYPE;
typedef enum
{
    ANTS_RTSP_STATUS_Connected,
    ANTS_RTSP_STATUS_Disconnected,
    ANTS_RTSP_STATUS_Error,
    ANTS_RTSP_STATUS_RECONNECT,
    ANTS_RTSP_STATUS_BUFFERFILL, // �������ϴο��˺󣬵�һ�����������
    ANTS_RTSP_STATUS_BUFFERFULL,
}ANTS_RTSP_STATUS_TYPE;
typedef enum
{
    ANTS_RTSP_ERROR_NoError = 0,
    ANTS_RTSP_ERROR_NoAnyData,
    ANTS_RTSP_ERROR_MallocError,
    ANTS_RTSP_ERROR_BufferTooSmall,
    ANTS_RTSP_ERROR_SocketClose,
    ANTS_RTSP_ERROR_SocketError = 5,
    ANTS_RTSP_ERROR_InvSeqNo,
    ANTS_RTSP_ERROR_ResError,
    ANTS_RTSP_ERROR_ParseError,
    ANTS_RTSP_ERROR_InvSdpParam,
    ANTS_RTSP_ERROR_SDP_PlayloadType = 10,
    ANTS_RTSP_ERROR_SDP_Rtpmap,
    ANTS_RTSP_ERROR_InvSessionID,
    ANTS_RTSP_ERROR_InvTransPort,
    ANTS_RTSP_ERROR_InvStreamDataLen,
    ANTS_RTSP_ERROR_Authenticate = 15,
    ANTS_RTSP_ERROR_NoSupportIPV6,
    ANTS_RTSP_ERROR_InvalidMulticast,
    ANTS_RTSP_ERROR_DisMatchPlayloadType = 18,
}ANTS_RTSP_ERROR_TYPE;

typedef struct
{
    int nStatusType; // ANTS_RTSP_STATUS_TYPE
    int nStatusCode; // ANTS_RTSP_ERROR_TYPE
    unsigned char byOPResult;// 0- Ĭ�ϲ�����1-����״̬
    unsigned char byRes[3];
    int nRes[5];
}ANTS_RTSP_STATUS_T;

#ifndef __ANTS_RTSP_DAYTIME__
#define __ANTS_RTSP_DAYTIME__
typedef struct _Ants_RtspDayTime
{
    unsigned short wYear;
    unsigned char byMon;
    unsigned char byDay;

    unsigned char byHour;
    unsigned char byMin;
    unsigned char bySec;
    unsigned char byZone;

    unsigned short wMsec;
    unsigned short wRes;

}Ants_RtspDayTime;
#endif
#ifndef ANTS_RTSP_ANTS_HEADER_DEFINE
#define ANTS_RTSP_ANTS_HEADER_DEFINE
#pragma pack(push,1)
typedef  struct _tagAudioHeader{
    char cCodecId;			//!��Ƶ��������
    char cSampleRate;			//!������
    char cBitRate;				//!������
    char cChannels;			//!ͨ����
    char cResolution;			//!�ֱ���
    char cResv[3];			//!����λ
}AntsAudioHeader,*pAntsAudioHeader;

typedef  struct _tagVideoHeader{
    unsigned short usWidth;				//!��Ƶ���
    unsigned short usHeight;				//!��Ƶ�߶�
    char cCodecId;				//!��Ƶ��������
    char cColorSpace;         // 0-yuv420,1-yuv422,2-444
    char cResv[2];					//!����λ
}AntsVideoHeader,*pAntsVideoHeader;

typedef  struct _tagANTSAPPHeader{
    unsigned char byAppPayloadType;				//!APP ��������
    unsigned char byAppNameLen;                 //! APP ���Ƴ���,����֡ͷ֮������֮ǰ,���255���ֽ� nul����
    unsigned char byRes[6];
}AntsAppHeader,*pAntsAppHeader;

typedef  struct _tagAntsFrameHeader{
    unsigned int uiStartId;					//!֡ͬ��ͷ
    unsigned int uiFrameType;				//!֡����
    unsigned int uiFrameNo;				//!֡��
    unsigned int uiFrameTime;				//!UTCʱ��
    unsigned int uiFrameTickCount;			//!����Ϊ��λ�ĺ���ʱ��
    unsigned int uiFrameLen;				//!֡�س���
    //!������,���ڴ洢��Ƶ֡������Ƶ֡��Ϣ
    union {
        AntsAudioHeader struAudioHeader;	//!��Ƶ֡��Ϣ
        AntsVideoHeader struVideoHeader;	//!��Ƶ֡��Ϣ
        AntsAppHeader   struAppHeader;
    }uMedia; // 8bytes
    //unsigned char ucReserve[4];				//!����λ		
    unsigned int uiTimeStamp;
}AntsFrameHeader,*pAntsFrameHeader;

typedef  struct _tagAntsFileHeader{
    unsigned int uiFileStartId;				//!�ļ���ʼͷ���
    unsigned int uiStreamType;				//!����ʽ
    unsigned int uiFrameRate;				//!֡��
    unsigned int uiReserve[4];				//!����λ	
}AntsFileHeader,*pAntsFileHeader;

typedef enum {
    AntsH264_hisi=1,//base/main
    AntsMJPEG_hisi=2,
    AntsH264_advance=3,
    AntsH264_hisi_high=4,//high
    AntsH264_hisi_RTP=8,//high
    AntsH264_RTP_PACK=9, // 
    AntsH265=16, // 
    AntsH265_RTP_PACK=17, // 
}eAntsVideoCodecId;

typedef enum{
    AntsOggVorbis=0,
    AntsG711A=1,
    AntsG711U=2,
    AntsG722Ex=3,
    AntsG726Ex=4,
    AntsADPCM=8,
}eAntsVoiceCodecId;

#pragma pack(pop)
typedef enum {
    //!������֡����
    AntsPktError=0x0,
    AntsPktIFrames=0x01,
    AntsPktAudioFrames=0x08,
    AntsPktPFrames=0x09,
    AntsPktBBPFrames=0x0a,
    AntsPktMotionDetection=0x0b,
    AntsPktDspStatus=0x0c,
    AntsPktOrigImage=0x0d,
    AntsPktSysHeader=0x0e,
    AntsPktBPFrames=0x0f,
    AntsPktSFrames=0x10,
    //!������֡����
    AntsPktSubSysHeader=0x11,
    AntsPktSubIFrames=0x12,
    AntsPktSubPFrames=0x13,
    AntsPktSubBBPFrames=0x14,
    //!���ܷ�����Ϣ֡����
    AntsPktVacEventZones=0x15,
    AntsPktVacObjects=0x16,
    // APP metedata֡.
    AntsPktAppFrames=0x20,
    // AntsComb ֡
    AntsPktAntsCombFrames=0x21,
}eAntsFrameType;
#define ANTS_FRAME_STARTCODE    0xAB010000
#define ANTS_FILE_STARTCODE    0xAA010000
#define ANTS_MOTION_STARTCODE    0xAC010000
#define ANTS_APP_STARTCODE    0xAD010000
#endif

// Ӧ����Ч�����δ���?
typedef enum
{
    ANTS_RTSP_CONTROL_CMD_START = 1, // ��ʼ���ӷ�����.
    ANTS_RTSP_CONTROL_CMD_PAUSE,// ��ͣ
    ANTS_RTSP_CONTROL_CMD_PLAY,//���� (int)=0Ĭ��1x���� >0 ����:1-1x,2-2x,3-3x... < 0 ����:-1 1x,-2 2X,-3 3X...
    ANTS_RTSP_CONTROL_CMD_SEEK, // seek,Ants_RtspDayTime *pSeekTime
    ANTS_RTSP_CONTROL_CMD_RATECONTROL = 5, // �趨�������Ƿ��������(int) 0-���������������ʣ�1-��������������
    ANTS_RTSP_CONTROL_CMD_ONLYIFRAME, // (int)ֻҪI֡,0-����֡,1-ֻI֡
    ANTS_RTSP_CONTROL_CMD_STEP,       // ��֡��
    ANTS_RTSP_CONTROL_CMD_RCVBUFFSIZE, // ���ý��ջ����С
    ANTS_RTSP_CONTROL_CMD_TALKDATA = 20, // �����Խ�����
    ANTS_RTSP_CONTROL_CMD_ANTSCOMB_ADDCH, // pInBuffer = int ch[] ,�������������������Ǹ�,nInSize = count
    ANTS_RTSP_CONTROL_CMD_ANTSCOMB_DECCH
}ANTS_RTSP_CONTROL_CMD_TYPE;

//!Ԥ���ص�����
#define ANTS_RTSP_DATATYPE_STATUS				            0		//! ״̬  ANTS_RTSP_STATUS_T
#define ANTS_RTSP_DATATYPE_SYSHEAD							1		//!ϵͳͷ����
#define ANTS_RTSP_DATATYPE_STREAMDATA						2		//!��Ƶ�����ݣ�����������������Ƶ�ֿ�����Ƶ�����ݣ�
#define ANTS_RTSP_DATATYPE_AUDIOSTREAMDATA			        3		//!��Ƶ������
#define ANTS_RTSP_DATATYPE_STD_VIDEODATA				    4		//!��׼��Ƶ������
#define ANTS_RTSP_DATATYPE_STD_AUDIODATA				    5		//!��׼��Ƶ������
#define ANTS_RTSP_DATATYPE_TALK_AUDIODATA				    6		//!�Խ���Ƶ������
#define ANTS_RTSP_DATATYPE_STREAMDATA_ANTSCOMB				7		//! ��ͨ����������



#ifdef __cplusplus
extern "C" {
#endif

typedef int (*ANTS_RTSPCLIENTCALLBACK) (int hRtspHandle,ANTS_RTPClientCallbackType nCallbackType,int nSubType,int nDataType, void *pData,int nDataLen,void *pUserData);
typedef void (*ANTS_RTSPREALDATACALLBACKFXN)(long lRealHandle,unsigned long dwDataType,unsigned char *lpBuffer,unsigned long dwBufSize,void* lpUser);


    int Ants_RTSPClient_Init(int bUnInit);
    int Ants_RTSPClient_Open(char *pUrl,ANTS_RTPTransProto nProto,ANTS_RTSPCLIENTCALLBACK pCallback,char *pUserName,char *pPassword,void *pUserData);
    int Ants_RTSPClient_Open_Ex(char *pUrl,ANTS_RTPTransProto nProto,ANTS_RTSPREALDATACALLBACKFXN pCallback,char *pUserName,char *pPassword,void *pUserData);
    /*********
    *Ants_RTSPClient_Open_Ex��Ants_RTSPClient_Open�����ǻص�������ͬ
    *Ants_RTSPClient_Open_Ex2������ͨר�ýӿ�
    */
    int Ants_RTSPClient_Open_Ex2(char *pUrl,ANTS_RTPTransProto nProto,ANTS_RTSPREALDATACALLBACKFXN pCallback,char *pUserName,char *pPassword,void *pUserData);
    int Ants_RTSPClient_GetTstConfig(int hRtspHandle,int *pVideoType,int *pAudioType,char *pConfig,int nConfigBufsize,int *pWidth,int *pHeight,int *pFrameFrate);
    int Ants_RTSPClient_Close(int hRtspHandle);

    // dwProp : bit0(�ڴ����ģʽ:0-�ɵ������ͷţ�1-�ɱ��������ͷ�); 
    //   dwDataType==ANTS_RTSP_DATATYPE_STREAMDATA_ANTSCOMBʱ       bit8-15: nStreamIdx,bit16-31:nChan
    // ��ʷ��ʱ,dwDataType==ANTS_RTSP_DATATYPE_STREAMDATA,bit16-31:=dwApplyID��ʾ���������õ�ID����Control�ӿ��趨
typedef void (*ANTS_RTSPREALDATACALLBACKFXN_V2)(long hRtspHandle,unsigned long dwDataType,unsigned long dwProp,unsigned char *lpBuffer,unsigned long dwBufSize,void* lpUser);
    // dwProp : bit0(�ڴ����ģʽ:0-�ɵ������ͷţ�1-�ɱ��������ͷ�) ; bit1(0-һ��ӿڣ�1-������ר�ýӿ�) ,
    // bit2(0-ʵʱ����1-��ʷ��),��ʷ��ʱ�����Զ����ӣ���Ҫ�ÿ�ʼ���������ӣ�Ҳ�����Զ�������
    // [bit3-��Ƶ,bit4-��Ƶ,bit5-onvif metedata (bit[3-5]�ɻ����,ȫ���趨ʱ��Ĭ�Ͽ�����/��Ƶ)] 
    // bit6-�����Խ�
    // bit7-: 0-�Զ����� ,1-���Զ�����
    // bit8: 0- ���ص���ʽ,1-����ȡ��ʽ
    // bit9: 0-�Զ�������1-���Զ�����(�����Խ�/�طţ�Ĭ�ϲ�����)
    // bit24-31:nPhyIdx, 0- Ĭ�����أ�1-eth0,2-eth1
    int Ants_RTSPClient_Open_V2(char *pUrl,ANTS_RTPTransProto nProto,unsigned long dwProp,ANTS_RTSPREALDATACALLBACKFXN_V2 pCallback,char *pUserName,char *pPassword,void *pUserData);
    // dwApplyID:�趨������Ч��ID,16bits����֤Ψһֵ���ɡ�
    int Ants_RTSPClient_Control(int hRtspHandle,int nCmd,unsigned long dwApplyID,void *pInBuffer,int nInSize,void *pOutBuffer,int nOutSize);

    // nChan: 
    // nStream: 
    // nStreamType: 0-��Ƶ,1-��Ƶ,2-�Խ�,3-app
    // ����:��ǰ������֡��(�������ڶ�ȡ��֡)
    int Ants_RTSPClient_Read(long hRtspHandle,int *nChan,int *nStream,int *nStreamType,unsigned char **lpBuffer,unsigned long *dwBufSize);
    int Ants_RTSPClient_ReadRelease(long hRtspHandle);

#ifdef __cplusplus
}
#endif
#endif 