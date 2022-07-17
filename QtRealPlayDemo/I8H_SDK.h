#ifndef __I8H_SDK_H__
#define __I8H_SDK_H__

#ifdef WIN32 
#include <windows.h>
#define I8H_SDK_API 	extern "C" __declspec(dllexport)
#define I8H_SDK_CALL	
#else
typedef unsigned int    	DWORD;
typedef unsigned int   		UINT;
typedef unsigned short  	WORD;
typedef unsigned short  	USHORT;
typedef int            		LONG;
typedef int 				BOOL;
typedef unsigned char		BYTE;
typedef unsigned int*  		LPDWORD; 
typedef void* 				LPVOID;
typedef void* 				HANDLE;

#ifndef TRUE
#define	TRUE			1
#endif

#ifndef FALSE
#define	FALSE 			0
#endif

#ifndef	NULL
#define	NULL 			0
#endif

#define CALLBACK 
#define I8H_SDK_API 	extern "C"
#define I8H_SDK_CALL	
#endif


//!�궨��
#define I8H_NAME_LEN			    						32  //!�û�������
#define I8H_PASSWD_LEN			    						32  //!���볤��
#define I8H_SERIALNO_LEN		    						48  //!���кų���
#define I8H_MACADDR_LEN			    						6   //!mac��ַ����
#define I8H_MAX_PRESET										256 //!�豸֧�ֵ���̨Ԥ�õ��� 
#define I8H_MAX_TRACK										256 //!�豸֧�ֵ���̨�켣�� 
#define I8H_MAX_CRUISE										256 //!�豸֧�ֵ���̨Ѳ���� 
#define I8H_CRUISE_MAX_PRESET_NUMS							32  //!һ��Ѳ������Ѳ���� 
#define I8H_MAX_CHANNUM			        					64  //!�豸���ͨ����
#define I8H_MAX_ALARMOUT									4
#define I8H_MAX_DISKNUM										24


	
/************************************************************************
			   ȫ�ִ�����궨��  
*************************************************************************/	
#define I8H_ERROR_CODE_NOERROR 								0	//!û�д���
#define I8H_ERROR_CODE_FAIL									1   //!ʧ��
#define I8H_ERROR_CODE_PASSWORD_ERROR 						2	//!�û����������
#define I8H_ERROR_CODE_NOENOUGHPRI 							3	//!Ȩ�޲���
#define I8H_ERROR_CODE_NOINIT 								4	//!û�г�ʼ��
#define I8H_ERROR_CODE_HASINIT 	     						5	//!�Ѿ���ʼ��
#define I8H_ERROR_CODE_ORDER_ERROR							6	//!���ô������
#define I8H_ERROR_CODE_PARAMETER_ERROR 						7  //!��������
#define I8H_ERROR_CODE_ALLOC_RESOURCE_ERROR					8  //!��Դ�������
#define I8H_ERROR_CODE_CALL3THAPI_ERROR						9	//!���õ������ӿڴ���
#define I8H_ERROR_CODE_CHAN_ERROR	 						10	//!ͨ���Ŵ���
#define I8H_ERROR_CODE_CHAN_NOTSUPPORT             			11 	//!ͨ����֧�ָò���
#define I8H_ERROR_CODE_OVER_MAXLINK 						12	//!���ӵ�DVR�Ŀͻ��˸����������
#define I8H_ERROR_CODE_VERSIONNOMATCH						13	//!�汾��ƥ��
#define I8H_ERROR_CODE_NETWORK_FAIL							14   //!�������(�������� ���� ���յȴ���)
#define I8H_ERROR_CODE_OPENFILE_FAIL						15  //!���ļ�����
#define I8H_ERROR_CODE_UPGRADE_FAIL							16  //!DVR����ʧ��
#define I8H_ERROR_CODE_DATASERIALIZE_FAIL					17	//!�������л�����
#define I8H_ERROR_CODE_DATADESERIALIZE_FAIL					18	//!���ݷ����л�����
#define I8H_ERROR_CODE_NOENOUGH_BUF							19	//!������̫С
#define I8H_ERROR_CODE_USERNOTEXIST							20	//!�û�������
#define I8H_ERROR_CODE_COMMAND_UNSUPPORT					21	//!���֧��
#define I8H_ERROR_CODE_INVALID_HANDLE						22  //!��Ч���
#define I8H_ERROR_CODE_SERVER_FORBIDDEN						23  //!�����ֹ
#define I8H_ERROR_CODE_CONNECT_SSL_ERROR					24  //!SSL���Ӵ���
#define I8H_ERROR_CODE_OPTERATION_BUSY						25 //!����æ


/************************************************************************
			   ��̨��������궨��  
*************************************************************************/	
#define I8H_LIGHT_PWRON										2	//! ��ͨ�ƹ��Դ 
#define I8H_WIPER_PWRON										3	//! ��ͨ��ˢ���� 
#define I8H_FAN_PWRON										4	//! ��ͨ���ȿ��� 
#define I8H_HEATER_PWRON									5	//! ��ͨ���������� 
#define I8H_AUX_PWRON1										6	//! ��ͨ�����豸���� 
#define I8H_AUX_PWRON2										7	//! ��ͨ�����豸���� 
#define I8H_SET_PRESET										8	//! ����Ԥ�õ� 
#define I8H_CLE_PRESET										9	//! ���Ԥ�õ� 

#define I8H_ZOOM_IN											11	//! �������ٶ�SS���(���ʱ��) 
#define I8H_ZOOM_OUT										12	//! �������ٶ�SS��С(���ʱ�С) 
#define I8H_FOCUS_NEAR      								13  //! �������ٶ�SSǰ�� 
#define I8H_FOCUS_FAR       								14  //! �������ٶ�SS��� 
#define I8H_IRIS_OPEN       								15  //! ��Ȧ���ٶ�SS���� 
#define I8H_IRIS_CLOSE      								16  //! ��Ȧ���ٶ�SS��С 

#define I8H_TILT_UP											21	//! ��̨��SS���ٶ����� 
#define I8H_TILT_DOWN										22	//! ��̨��SS���ٶ��¸� 
#define I8H_PAN_LEFT										23	//! ��̨��SS���ٶ���ת 
#define I8H_PAN_RIGHT										24	//! ��̨��SS���ٶ���ת 
#define I8H_UP_LEFT											25	//! ��̨��SS���ٶ���������ת 
#define I8H_UP_RIGHT										26	//! ��̨��SS���ٶ���������ת 
#define I8H_DOWN_LEFT										27	//! ��̨��SS���ٶ��¸�����ת 
#define I8H_DOWN_RIGHT										28	//! ��̨��SS���ٶ��¸�����ת 
#define I8H_PAN_AUTO										29	//! ��̨��SS���ٶ������Զ�ɨ�� 

#define I8H_ADD_CRUISE_ROUTE_POINT							30	//!���Ѳ������Ѳ���� 
#define I8H_DEL_CRUISE_ROUTE_POINT							31	//!ɾ��Ѳ������Ѳ����
#define I8H_DEL_CRUISE_ROUTE								32	//!ɾ��Ѳ������
#define I8H_RUN_CRUISE_ROUTE								33	//!����Ѳ������
#define I8H_STOPRUN_CRUISE_ROUTE							34	//!ֹͣ����Ѳ������

#define I8H_START_TRACK										35	//!��ʼ��¼�켣
#define I8H_STOP_TRACK										36	//!ֹͣ��¼�켣
#define I8H_RUN_TRACK										37  //!���м�¼�켣
#define I8H_GOTO_PRESET										39	//! ����Ԥ�õ� 



/************************************************************************
			   �طſ�������궨��   
*************************************************************************/	
#define I8H_PLAYBACK_PLAYPAUSE								1	//!��ͣ����
#define I8H_PLAYBACK_PLAYRESTART							2	//!�ָ�����
#define I8H_PLAYBACK_PLAYSTARTAUDIO							3	//!������
#define I8H_PLAYBACK_PLAYSTOPAUDIO							4	//!�ر�����
#define I8H_PLAYBACK_SETSPEED								5	//!���������ٶ�
#define I8H_PLAYBACK_PLAYSETTIME							6	//!������ʱ�䶨λ,�ṹΪI8H_TIME
#define I8H_PLAYBACK_ADDCHAN								7	//!�ط����ͨ��
#define I8H_PLAYBACK_DELCHAN								8	//!�ط�ɾ��ͨ��



/************************************************************************
			 Ԥ����������궨��   
*************************************************************************/	
#define I8H_REALPLAY_ADDCHAN								1	//!���ͨ������,���Ԥ��Ч��һ��,���ǲ�����������,��֮ǰ�򿪵�Ԥ������һ������;ͬһ�豸�Ĳ�ͬͨ��֧�ִ˲���,��ͬ���豸��֧�ּ���Ĺ���
#define I8H_REALPLAY_DELCHAN								2	//!ɾ��ͨ��
#define I8H_REALPLAY_PLAYSTARTAUDIO							3	//!������
#define I8H_REALPLAY_PLAYSTOPAUDIO							4	//!�ر�����



/************************************************************************
			   ������ʽ���ͺ궨��
*************************************************************************/	
#define I8H_COMM_ALARM										0x1100	//!������Ϣ�����ϴ�
#define I8H_COMM_TRADEINFO									0x1500 	//!ATMDVR�����ϴ�������Ϣ
#define I8H_COMM_IPCCFG			        					0x4001	//!�豸IPC�������øı䱨����Ϣ�����ϴ�



/************************************************************************
			   �����쳣����(��Ϣ��ʽ, �ص���ʽ(����))�궨��
*************************************************************************/	
#define I8H_EXCEPTION_EXCHANGE								0x8000	//!�û�����ʱ�쳣
#define I8H_EXCEPTION_AUDIOEXCHANGE							0x8001	//!�����Խ��쳣
#define I8H_EXCEPTION_ALARM									0x8002	//!�����쳣
#define I8H_EXCEPTION_PREVIEW								0x8003	//!����Ԥ���쳣
#define I8H_EXCEPTION_SERIAL								0x8004	//!͸��ͨ���쳣
#define I8H_EXCEPTION_RECONNECT								0x8005	//!Ԥ��ʱ����
#define I8H_EXCEPTION_ALARMRECONNECT						0x8006	//!����ʱ����
#define I8H_EXCEPTION_SERIALRECONNECT						0x8007	//!͸��ͨ������
#define I8H_SERIAL_RECONNECTSUCCESS 						0x8008	//!͸��ͨ�������ɹ�
#define I8H_EXCEPTION_PLAYBACK	        					0x8010	//!�ط��쳣
#define I8H_EXCEPTION_DISKFMT	        					0x8011	//!Ӳ�̸�ʽ��
#define I8H_EXCEPTION_PASSIVEDECODE     					0x8012 	//!���������쳣
#define I8H_EXCEPTION_EMAILTEST            					0x8013 	//!�ʼ������쳣    
#define I8H_EXCEPTION_BACKUP               					0x8014 	//!�����쳣
#define I8H_PREVIEW_RECONNECTSUCCESS      					0x8015 	//!Ԥ��ʱ�����ɹ�
#define I8H_ALARM_RECONNECTSUCCESS     						0x8016 	//!����ʱ�����ɹ�
#define I8H_DEVICE_ONLINE     								0x8017 	//!�豸���߳ɹ�
#define I8H_DEVICE_OFFLINE     								0x8018 	//!�豸����



/************************************************************************
			   Ԥ���ص������������ͺ궨��
*************************************************************************/	
#define I8H_STREAMDATA_SYSHEAD								0x0001	//!ϵͳͷ����
#define I8H_STREAMDATA_STREAMDATA							0x0002	//!��Ƶ�����ݣ�����������������Ƶ�ֿ�����Ƶ�����ݣ�
#define I8H_STREAMDATA_AUDIOSTREAMDATA						0x0003	//!��Ƶ������
#define I8H_STREAMDATA_STD_VIDEODATA						0x0004	//!��׼��Ƶ������
#define I8H_STREAMDATA_STD_AUDIODATA						0x0005	//!��׼��Ƶ������



/************************************************************************
			   �豸�ͺź궨��
*************************************************************************/	
#define I8H_PRODUCT_DVR										0x0001
#define I8H_PRODUCT_NVR										0x0002
#define I8H_PRODUCT_IPC										0x0003
#define I8H_PRODUCT_DEC										0x0004
#define I8H_PRODUCT_NVR2									0x0005


/************************************************************************
			   �豸����汾�궨��
*************************************************************************/	
#define I8H_DVR_GO_AHEAD									0x0001
#define I8H_NVR1_GO_AHEAD									0x0002
#define I8H_IPC_GO_AHEAD									0x0003
#define I8H_DEC_GO_AHEAD									0x0004
#define I8H_NVR2_GO_AHEAD									0x0005
#define I8H_DVR_NGINX										0x0006
#define I8H_NVR1_NGINX										0x0007
#define I8H_IPC_NGINX										0x0008
#define I8H_DEC_NGINX										0x0009
#define I8H_NVR2_NGINX										0x000A
#define I8H_IPC_JULONG_NGINX								0x000B
#define I8H_IPC_OVFS_NGINX									0x000C
#define I8H_IPC_FISHEYE_NGINX								0x000D
#define I8H_IPC_AI                                          0x000E
#define I8H_NVR_AI                                          0x000F

/************************************************************************
			   �������ͺ궨��
*************************************************************************/	
#define I8H_ALARMTYPE_ALARMIN 								0	//!�ź�������
#define I8H_ALARMTYPE_DISKFULL 								1	//!Ӳ����
#define I8H_ALARMTYPE_VIDEOLOSS								2	//!�źŶ�ʧ
#define I8H_ALARMTYPE_MOTION								3	//!�ƶ����
#define I8H_ALARMTYPE_DISKNOFORMAT							4	//!Ӳ��δ��ʽ��
#define I8H_ALARMTYPE_DISKIOERROR							5	//!��дӲ�̳���
#define I8H_ALARMTYPE_MASK									6	//!�ڵ�����
#define I8H_ALARMTYPE_VIDEOSTANDARDEXCEPTION				7	//!��ʽ��ƥ��
#define I8H_ALARMTYPE_ILLEGEACCESS							8	//!�Ƿ�����
#define I8H_ALARMTYPE_VIDEOEXCEPTION						9	//!��Ƶ�ź��쳣
#define I8H_ALARMTYPE_RECEXCEPTION							10	//!¼���쳣

#define I8H_ALARMTYPE_RETICLEDISCONNECT						20	//!���߶�
#define I8H_ALARMTYPE_IPCONELICT							21	//!IP��ͻ
#define I8H_ALARMTYPE_IVS_COUNTWIRE							22	//!�������
#define I8H_ALARMTYPE_IVS_DETECTWIRE						23	//!���߼��
#define I8H_ALARMTYPE_IVS_DETECTREGION						24	//!������
#define I8H_ALARMTYPE_IVS_OBJECTREGION						25	//!��Ʒ���
#define I8H_ALARMTYPE_IVS_SOUNDALARM						26	//!�쳣��������
#define I8H_ALARMTYPE_IVS_PLATEDETECT_ALARM					27	//!����ʶ��
#define I8H_ALARMTYPE_IVS_FACEDETECT_ALARM					28	//!�������
#define I8H_ALARMTYPE_IVS_FIREDETECT_ALARM					29	//!������
#define I8H_ALARMTYPE_IVS_VIDEODIAGNOSE_COLOR				30	//!��Ƶ���_ƫɫ
#define I8H_ALARMTYPE_IVS_VIDEODIAGNOSE_BRIGHT				31	//!��Ƶ���_ƫ��
#define I8H_ALARMTYPE_IVS_VIDEODIAGNOSE_BLUR				32	//!��Ƶ���_ģ�� 
#define I8H_ALARMTYPE_IVS_MOTION_DETECT						33	//!�����ƶ����
#define I8H_ALARMTYPE_IVS_VIDEODIAGNOSE_DARK				34	//!��Ƶ���_ƫ��
#define I8H_ALARMTYPE_IVS_VIDEODIAGNOSE_VI_LOST				35	//!��Ƶ���_��Ƶ��ʧ
#define I8H_ALARMTYPE_IVS_PERSONDETECT_ALARM				36	//!���μ�ⱨ��


typedef enum
{
	I8H_EVENT_MAIN_TYPE_UNKNOW = 0x0,        //δ֪������(�����в�Ӧ�ó��ִ�����)
	I8H_EVENT_MAIN_TYPE_ANY,                 //����������

	I8H_EVENT_CH_EVENT,						 //ͨ������¼�                         
	I8H_EVENT_DISK_EVENT,					 //Ӳ������¼�         
	I8H_EVENT_NET_EVENT,                     //��������¼�      
	I8H_EVENT_ALARM_EVENT,                   //��������¼�   

	I8H_EVENT_MAIN_MAX,                      //�¼����������ֵ�������в�Ӧ�ó��ִ�����      
}I8H_EVENT_MAIN_TYPE;


typedef enum 
{
	I8H_EVENT_SUB_TYPE_UNKNOW = 0x0,               
	I8H_EVENT_SUB_TYPE_ANY,                                 

	/*ͨ�����¼�*/
	I8H_EVENT_MD,                             //�ƶ����
	I8H_EVENT_OD,                             //��Ƶ�ڵ�
	I8H_EVENT_VIDEO_LOST,                     //��Ƶ��ʧ
	I8H_EVENT_SMART_OBJECT_COUNT,             //Ŀ�����
	I8H_EVENT_SMART_CROSS_LINE,               //���߼��
	I8H_EVENT_SMART_REGION_DETECT,            //������ 
	I8H_EVENT_SMART_GOODS_DETECT,             //��Ʒ���
	I8H_EVENT_SMART_SCENE_CHNAGE,             //�龰�任
	I8H_EVENT_SMART_SOUND_DETECT,             //�������
	I8H_EVENT_SMART_FIRE_DETECT,              //���ּ��
	I8H_EVENT_SMART_FACE_DETECT,              //�������
	I8H_EVENT_SMART_CAR_PLATE_DETECT,         //���Ƽ��
	I8H_EVENT_SMART_CAR_PLATE_BLACK,          //���ƺ�����
	I8H_EVENT_SMART_CAR_PLATE_WHITE,          //���ư�����    
	I8H_EVENT_SMART_VIDEO_DIAGNOSE,           //��Ƶ���

	/*�������¼�*/
	I8H_EVENT_DISK_FULL,                      //������
	I8H_EVENT_DISK_LOST,                      //���̶�ʧ
	I8H_EVENT_DISK_ERROR,                     //���̴���
	I8H_EVENT_DISK_DISCONNECT,                //���̵���(�������)
	I8H_EVENT_DISK_READ_ONLY,                 //����ֻ��
	I8H_EVENT_DISK_RAID_DEGRADED,             //���̽���(RAID)
	I8H_EVENT_DISK_RAID_FAULT,                //��������(RAID)
	I8H_EVENT_DISK_SMART_ERROR,               //����Smart��Ϣ����

	/*�������¼�*/
	I8H_EVENT_NET_DISCONNECT,                 //����Ͽ�
	I8H_EVENT_NET_IP_CONFLICT,                //IP��ͻ

	/*�������¼�*/
	I8H_EVENT_LOCAL_ALRAM_IN,                 //���ر�������
	I8H_EVENT_REMOTE_ALARM_IN,                //Զ�˱�������
	
	I8H_EVENT_SMART_PERSON_DETECT,              //���μ��

	I8H_EVENT_SUB_MAX,                        //�¼����������ֵ,�����в�Ӧ�ó��ִ�������
}I8H_EVENT_SUB_TYPE;


typedef enum 
{
	I8H_EVENT_THIRD_TYPE_UNKNOW = 0x0,	      //δ֪��������
	I8H_EVENT_THIRD_TYPE_ANY,                 //����������

	/*�������������¼�*/
	I8H_EVENT_SMART_BABY_CRY,                 //Ӥ������
	I8H_EVENT_SMART_SCREAM,                   //�����
	I8H_EVENT_SMART_GUNSHOTS,                 //ǹ��
	I8H_EVENT_SMART_EXPLOSION,                //��ը��

	/*��Ƶ��������¼�*/
	I8H_EVENT_SMART_VIDEO_DIM,                //��Ƶ�谵
	I8H_EVENT_SMART_VIDEO_BRIGHT,             //��Ƶ����
	I8H_EVENT_SMART_VIDEO_FRINGE,             //��Ƶ����
	I8H_EVENT_SMART_VIDEO_SNOW,               //��Ƶѩ��
	I8H_EVENT_SMART_VIDEO_OD,                 //��Ƶ�ڵ�
	I8H_EVENT_SMART_VIDEO_FREEZE,             //��Ƶ����
	I8H_EVENT_SMART_VIDEO_LOST,               //��Ƶ��ʧ
	I8H_EVENT_SMART_VIDEO_OBSCURE,            //��Ƶģ��            
	I8H_EVENT_SMART_VIDEO_SHAKE,              //��Ƶ����
	I8H_EVENT_SMART_VIDEO_COLOR_CAST,	      //��Ƶƫɫ
	I8H_EVENT_SMART_VIDEO_PTZ_ABNORMAL,		  //PTZ�쳣

	I8H_EVENT_THIRD_MAX,                      //�¼������������ֵ,�����в�Ӧ�ó��ִ�����
}I8H_EVENT_THIRD_TYPE;



/************************************************************************
			   �㲥�޸Ĳ�������
*************************************************************************/	
typedef enum MODIFY_CMD
{
	I8H_MODIFY_IPADDR = 0x0001,
	I8H_MODIFY_GOOLINK,
	I8H_MODIFY_UMEYE,
}I8H_MODIFY_COMMAND ;


typedef enum 
{
	//!������֡����
	I8H_PktError=0x0,
	I8H_PktIFrames=0x01,
	I8H_PktAudioFrames=0x08,
	I8H_PktPFrames=0x09,
	I8H_PktBBPFrames=0x0a,
	I8H_PktMotionDetection=0x0b,
	I8H_PktDspStatus=0x0c,
	I8H_PktOrigImage=0x0d,
	I8H_PktSysHeader=0x0e,
	I8H_PktBPFrames=0x0f,
	I8H_PktSFrames=0x10,

	//!������֡����
	I8H_PktSubSysHeader=0x11,
	I8H_PktSubIFrames=0x12,
	I8H_PktSubPFrames=0x13,
	I8H_PktSubBBPFrames=0x14,

	//!���ܷ�����Ϣ֡����
	I8H_PktVacEventZones=0x15,
	I8H_PktVacObjects=0x16,

	//!��������֡����
	I8H_PktThirdSysHeader=0x17,
	I8H_PktThirdIFrames=0x18,
	I8H_PktThirdPFrames=0x19,
	I8H_PktThirdBBPFrames=0x1a,

	//!���ܼ��֡����
	I8H_PktSmartIFrames=0x1b,
	I8H_PktSmartPFrames=0x1c,

	// APP metedata֡.
	I8H_PktAppFrames=0x20,

	// I8HComb ֡
	I8H_PktI8HCombFrames=0x21,
}I8H_FrameType;



/************************************************************************
						��Ƶ֡��������
*************************************************************************/	
typedef enum 
{
	I8H_H264 = 1,
	I8H_MJPEG ,
	I8H_H265 ,   
	I8H_SVAC ,
	I8H_VIDEO_UNKNOWN ,
}I8H_VideoCodecType;


/************************************************************************
						��Ƶ֡��������
*************************************************************************/	
typedef enum 
{
	I8H_G711A = 1,
	I8H_G711U ,
	I8H_AUDIO_UNKNOWN ,
}I8H_AudioCodecType;


/************************************************************************
			  Nvr2.0�豸¼������
*************************************************************************/	
typedef enum
{
	I8H_REC_TRIG_NONE = 0,

	I8H_REC_TRIG_BY_REGULAR		= 0x01,		//����¼��
	I8H_REC_TRIG_BY_MD 			= 0x02,		//�ƶ����¼��
	I8H_REC_TRIG_BY_AI 			= 0x04,		//����¼��
	I8H_REC_TRIG_BY_COUNTER    = 0x08,
	I8H_REC_TRIG_BY_WIRE       = 0x10, 
	I8H_REC_TRIG_BY_REGION     = 0x20,
	I8H_REC_TRIG_BY_OBJECT     = 0x40,
	I8H_REC_TRIG_BY_SCENCE		= 0x80,		//����ͻ��¼��
	I8H_REC_TRIG_BY_SOUND		= 0x100,	//�����澯¼��
	I8H_REC_TRIG_BY_FIRE    	= 0x200,	//���ּ��¼��
	I8H_REC_TRIG_BY_FACE    	= 0x400,	//�������¼��
	I8H_REC_TRIG_BY_PLATE    	= 0x800,	//���Ƽ��¼��
	/*****���������¼�����ͣ��ǵ�ͬ�����ӵ�I8H_REC_TRIG_BY_ALL��ȥŶ********/

	I8H_REC_TRIG_BY_PRE = I8H_REC_TRIG_NONE,	//Ԥ¼
	//�������͵�ȫ������ò�Ҫ��0xFFFFFFFF�������ˣ�����һ�����ͣ����޸�һ��ȫ���Ķ��壬�����û���ѯ��ʱ��ѡ��ȫ�� + ͬʱ���� ��ʱ����ܲ�õ�
	I8H_REC_TRIG_BY_ALL = I8H_REC_TRIG_BY_REGULAR\
	| I8H_REC_TRIG_BY_MD\
	| I8H_REC_TRIG_BY_AI\
	| I8H_REC_TRIG_BY_COUNTER\
	| I8H_REC_TRIG_BY_WIRE\
	| I8H_REC_TRIG_BY_REGION\
	| I8H_REC_TRIG_BY_OBJECT\
	| I8H_REC_TRIG_BY_SCENCE\
	| I8H_REC_TRIG_BY_SOUND\
	| I8H_REC_TRIG_BY_FIRE\
	| I8H_REC_TRIG_BY_FACE\
	| I8H_REC_TRIG_BY_PLATE,
}I8H_REC_TRIG_TYPE;


/************************************************************************
			   ��ȡ���ú��������õĺ궨��
*************************************************************************/

typedef enum
{
	I8H_SET_ENABLE_ALARM_CFG = 0x0001,
	
	I8H_SET_TIME_CFG = 0x1000,
	
	I8H_GET_TIME_CFG = 0x2000,
	
}I8H_CONFIG_CMD ;



/************************************************************************
			   SDK��ʼ������
*************************************************************************/	
typedef struct
{
	BOOL bAsync ;
	BYTE byKeyPath[256] ;
	DWORD dwUnicastSTX ;
	DWORD dwUnicastETX ;
	BYTE  byEnableHeartBeat ;
	BYTE  byManageMem ; //�Ƿ��Լ������ͷ�RTSP���ڴ�,NVR2.0�ڲ�ר��,�ⲿ�Խ�(����Ϊ0����)����ʹ��  0:�� 1:��
	BYTE  byCaptureJPEGIntervalTime ;//!JPEGץͼ���ʱ��(��λ:��)
	BYTE byRes[117] ;	
}I8H_INIT_PARAM, *LPI8H_INIT_PARAM ;


/************************************************************************
			   �豸��ز����ṹ����
*************************************************************************/	

/************************************************************************
			   �豸����������Ϣ
*************************************************************************/	
typedef struct
{
	BYTE bySerialNumber[I8H_SERIALNO_LEN];					//!���к�
	WORD wAlarmInNum ;										//!������������
	WORD wAlarmOutNum ;										//!�����������
	WORD wDiskNum ;											//!Ӳ������
	WORD wDVRType ;											//!�豸���� 1-DVR 2-NVR 3-IPC 4-DEC 5-NVR2.0
	WORD wChanNum ;											//!��Ƶͨ������
	WORD wStartChan ;										//!��Ƶ��ʼͨ����
	WORD wAudioChanNum ;									//!����ͨ������
	WORD wZeroChanNum ;										//!��ͨ������
	DWORD dwSupport ;										//!����,λ����0-��ʾ��֧�� 1-��ʾ֧��
															//!dwSupport & 0x01 ��ʾ�Ƿ�֧����������
															//!dwSupport & 0x02 ��ʾ�Ƿ�֧��֧�ֱ���
															//!dwSupport & 0x04 ��ʾ�Ƿ�֧��ѹ������������ȡ
															//!dwSupport & 0x08 ��ʾ�Ƿ�֧�ֶ�����
															//!dwSupport & 0x10 ��ʾ�Ƿ�֧��Զ��SADP															
	BYTE byVer; 											//!1:DVR_GO_AHEAD    2:NVR1.0_GO_AHEAD   3:IPC_GO_AHEAD   4:DEC_GO_AHEAD  5:NVR2.0_GO_AHEAD   6:DVR_NGINX    7:NVR1.0_NGINX   8:IPC_NGINX  9:DEC_NGINX 10:NVR2.0_NGINX 11:I8H_IPC_JULONG_NGINX 12:I8H_IPC_OVFS_NGINX 13:I8H_IPC_FISHEYE_NGINX 14:I8H_IPC_AI 15:
	BYTE byRes[63];											//!����
}I8H_DEVICEINFO, *LPI8H_DEVICEINFO;


/************************************************************************
				Ԥ��������Ϣ
*************************************************************************/	
typedef struct
{
	LONG lChannel ; 		//!bit0~bit15:ͨ����  bit28~bit31:���������� ��һλ:��ʾ��ȡ����Ƶ�� �ڶ�λ:��ʾ��ȡ������ ����λ:���� ����λ:����
	LONG lLinkMode ;		//!Bit0-Bit7   ��ʾ�������ӷ�ʽ 0-TCP���ӷ�ʽ 1-UDP���ӷ�ʽ 2-�鲥��ʽ
							//!Bit8-Bit15  ��ʾ�������� 0-������ 1-������ 2-�������� 
							//!Bit16-Bit31 ��ʾSocket������,Ϊ0��ʾʹ��Ĭ��ֵ(64kb),��λkb
	char* lpMultiCastIP ;	//!�ಥ���ַ
}I8H_CLIENTINFO, *LPI8H_CLIENTINFO;


/************************************************************************
				ʱ�������Ϣ
*************************************************************************/	
typedef struct 
{
	WORD wYear ;		//!��
	WORD wMonth ;		//!��
	WORD wDay ;			//!��
	WORD wHour ;		//!ʱ
	WORD wMinute ;		//!��
	WORD wSecond ;		//!��
	WORD wZoneTime ;	//!ʱ�� ��:������ wZoneTime = 8 ������ wZoneTime = -8  
	WORD wRes ;			//!����
}I8H_TIME, *LPI8H_TIME;


/************************************************************************
				Ѳ���������Ϣ
*************************************************************************/	
typedef struct 
{
	BYTE byPresetNo;			//!Ԥ�õ�
	BYTE byDWell;				//!ͣ��ʱ��
	BYTE bySpeed;				//!�ٶ�
	BYTE byReserve;				//!����
}I8H_CRUISE_POINT, *LPI8H_CRUISE_POINT;

typedef struct 
{
	I8H_CRUISE_POINT struCruisePoint[32];	//!���֧��32��Ѳ����
}I8H_CRUISE_RET, *LPI8H_CRUISE_RET;


/************************************************************************
				¼���ļ����������ṹ��Ϣ
*************************************************************************/	
//!��2.0���豸ʹ�ô˽ṹ��
typedef struct 
{
	WORD wChannel ;				//!ͨ����									
	WORD wFileType ;			//!¼���ļ����� 0xFF-ȫ�� 0-��ʱ¼�� 1-�ƶ���� 2-�������� 3-����|�ƶ���� 4-����&�ƶ���� 5-����� 6-�ֶ�¼��
	I8H_TIME struStartTime ;	//!�ļ���ѯ��ʼʱ��	
	I8H_TIME struStopTime ;		//!�ļ���ѯ����ʱ��
	WORD wRes[16] ; 
}I8H_FILECOND, *LPI8H_FILECOND;



//!2.0���豸ʹ�ô˽ṹ��
typedef struct 
{
	WORD wChannel ;				//!ͨ����		
	WORD wIsAnd;				//0:��������, 1:ͬʱ����;NVR2.0���豸��Ҫ��д
	DWORD wFileType ;			//!¼���ļ�����NVR2.0���豸��Ҫ��д,�����豸������д,������豸�ͺŲμ�   �豸����������Ϣ,����μ�I8H_REC_TRIG_TYPE															
	I8H_TIME struStartTime ;	//!�ļ���ѯ��ʼʱ��	
	I8H_TIME struStopTime ;		//!�ļ���ѯ����ʱ��								
	WORD wRes[14] ; 
}I8H_FILECONDV2, *LPI8H_FILECONDV2;



/************************************************************************
				¼���ļ������ṹ��Ϣ
*************************************************************************/	
typedef struct 
{
	char szFileName[128] ;  	//!�ļ���
	I8H_TIME struStartTime ;	//!�ļ���ʼʱ��
	I8H_TIME struStopTime ;		//!�ļ�����ʱ��
	DWORD dwFileSize ;		//!�ļ���С
	WORD wFileType ;		//!�ļ�����
	WORD wRes[15] ;			//!����		
	DWORD dwFileType ;		//!�ļ�����(wFileType�޷�������ʾ��������,������չ�ĸ��ֽ�������)
}I8H_FINDDATA,*LPI8H_FINDDATA;


/************************************************************************
				�����ϴ������ṹ��Ϣ
*************************************************************************/	
//typedef struct _tagAlarmInfo
//{
//	DWORD dwAlarmType ;			//!��������
//	WORD wParam ;				//!������������
//	WORD wState ;				//!��15λ��ʾ��������״̬,��1��ʾ������״̬,��0��ʾ������״̬;	
//	DWORD dwTimeStamp ;			//!����ʱ���(ȡ�豸����ʱ��(��λ:��))
//}I8H_ALARMINFO, *LPI8H_ALARMINFO ;


typedef struct _tagAlarmInfov2
{
	DWORD dwMainAlarmType ;			//!����������
	DWORD dwSubAlarmType ;			//!����������
	DWORD dwThirdAlarmType ;	    //!������������
	BYTE *lpBuffer ;			    //!��������
	WORD wSize ;				    //!�������ַ�����
	WORD wState ;				    //!��15λ��ʾ��������״̬,��1��ʾ������״̬,��0��ʾ������״̬;	
	DWORD dwTimeStamp ;			    //!����ʱ���(ȡ�豸����ʱ��(��λ:��))
}I8H_ALARMINFO_V2, *LPI8H_ALARMINFO_V2 ;


/************************************************************************
				�����豸�����ṹ��Ϣ
*************************************************************************/	
typedef struct
{
	char szIP[16];
	char szMask[16];
	char szGateWay[16];
	char szDns1[16];
	char szDns2[16];
	BYTE byMacAddr[I8H_MACADDR_LEN];
	BYTE byRes[14];
}I8H_DEV_NET_INFO,*LPI8H_DEV_NET_INFO ;

typedef struct
{
	I8H_DEV_NET_INFO struNetInfos[3];			//!�豸���������Ϣ 0-eth0 1-wifi 2-3G
	WORD wPorts[4];								//!0-˽�м����˿� 1-Http�����˿� 2-Rtsp�����˿� 3-����
	BYTE bySerialNo[I8H_SERIALNO_LEN];			//!�豸���к�	
	char szName[I8H_NAME_LEN];					//!�豸�û���¼��
	char szPwd[I8H_PASSWD_LEN];					//!�豸�û���¼����
	char szDeviceType[32];						//!�豸���� ��:DVR-04 DVR-08 DVR-16 NVR-04 NVR-08 NVR-16 IPC
	DWORD dwSoftwareVersion;					//!����汾��,��16λ�����汾,��16λ�Ǵΰ汾
	DWORD dwSoftwareBuildDate;					//!�����������,0xYYYYMMDD
	BYTE byOldPrograms ; 						//!��Խ���������,
	BYTE byDeviceModel[16] ;					//!�豸�ͺ�
 	BYTE byI8Valid:1;       					//!bit0:I8��Ч,����״̬δ����,���ϰ汾����
	BYTE byI8Status:1;       					//!bit1:I8����,״̬����ʱ,����״̬��Ч,1-����
	BYTE byOnvifValid:1;       					//!bit2:ONVIF ����
	BYTE byOnvifStatus:1;    					//!bit3:ONVIF����
	BYTE byRTSPValid:1;       					//!bit4:RTSP ����
	BYTE byRTSPStatus:1;    					//!bit5:RTSP����
	BYTE byRTMPValid:1;      					//!bit6:RTMP ����
	BYTE byRTMPStatus:1;   						//!bit7:RTMP����
	BYTE bI8S_ServerValid:1;       				//!bit8:I8S ����
	BYTE bI8S_ServerStatus:1;       			//!bit9:I8S����
	BYTE bGB28181_ServerValid:1;       			//!bit10:GB28181 ����
	BYTE bGB28181_ServerStatus:1;       		//!bit11:GB28181����
	BYTE bWebApi_ServerValid:1;       			//!bit12:WebApi ����
	BYTE bWebApi_ServerStatus:1;       			//!bit13:WebApi����״̬
	BYTE bWebNginx_ServerValid:1;       		//!bit14:WebApi Nginx����
	BYTE bWebNginx_ServerStatus:1;       		//!bit15:WebApi Nginx����״̬
	BYTE bOvfs_IPC:1;       					//!bit16:�Ƿ�ΪOVFS�ܹ� 
	BYTE bT8S_ServerValid:1;       				//!bit17:�Ƿ�ΪT8S��OVFS�ܹ� 
	BYTE bT8S_ServerStatus:1;       			//!bit18:�Ƿ�ΪT8S��OVFS�ܹ� 
	BYTE bFaceValid:1;							//!bit19:�Ƿ�֧������ʶ��
	BYTE bRes:4;       							//!bit3~bit7:����
	BYTE byRes[4] ;	
}I8H_DEV_NODE,*LPI8H_DEV_NODE ;


/************************************************************************
				ͨ�����ɾ���ṹ��Ϣ
*************************************************************************/	
typedef struct
{
	BYTE byStreamType ;
	BYTE byAudioFlag ;
	WORD wChannel ;
	BYTE byRes[8] ;
}I8H_CHANNEL_INFO,*LPI8H_CHANNEL_INFO ;


/************************************************************************
				¼��طŲ���
*************************************************************************/
typedef struct
{
	WORD wChannel ;					  //!ͨ����,Ĭ����ʼͨ��Ϊ1
	WORD wStreamType ;				  //!�������� 0-������  1-������
	WORD wLinkMode ;				  //!����ģʽ
	WORD wIsAnd;					  //!0:��������,1:ͬʱ����;NVR2.0���豸��Ҫ��д
	DWORD dwFileType ;				  //!¼���ļ�����NVR2.0���豸��Ҫ��д,�����豸������д,������豸�ͺŲμ�   �豸����������Ϣ,����μ�I8H_REC_TRIG_TYPE															
	DWORD dwSelfClean ;				  //!bit0:�Ƿ������û�����������֤ bit1:�Ƿ��ֶ�����ڴ�
	DWORD dwBuffSize ;				  //!socket��������С,��λ�ֽ�
	BYTE byUserName[I8H_NAME_LEN] ;	  //!�û���
	BYTE byPassWord[I8H_PASSWD_LEN] ; //!����
	I8H_TIME struStartTime ;		  //!�ļ���ѯ��ʼʱ��	
	I8H_TIME struStopTime ;			  //!�ļ���ѯ����ʱ��	
	BYTE byReplayModel ;			  //!0:��ͨ�ٶȻط�,1:����ٶȻط�
	BYTE byRes[27] ;				  //!Ԥ��
}I8H_PLAYBACK_COND,*LPI8H_PLAYBACK_COND ;


/************************************************************************
				�ص���������
*************************************************************************/	
//!�����ص�����
typedef void (CALLBACK *fDiscoveryCallBack)(LPI8H_DEV_NODE lpDev, LPVOID lpUser) ; 

//!�쳣��Ϣ�ص�����
typedef void (CALLBACK *fExceptionCallBack)(DWORD dwType, HANDLE hUserId, HANDLE hHandle, LPVOID lpUser) ; 

//!������Ϣ�ص����� lCommand ��31λ��1,���ʾlpAlarmInfo��Ҫ����I8H_SDK_FreeMemory�ͷ��ڴ�;��0,���ʾ����Ҫ����I8H_SDK_FreeMemory�ͷ��ڴ�
typedef void (CALLBACK *fAlarmDataCallBack)(HANDLE hUserId, HANDLE hAlarmHandle, LONG lCommand, LPVOID lpAlarmInfo, DWORD dwAlarmInfoLen, LPVOID lpUser) ; 

//!�豸������Ϣ/״̬��Ϣ�ص�����(��չ�ص� 1.Ӳ��״̬ 2.������Ϣ 3.¼��״̬)  
typedef void (CALLBACK *fAlarmDataCallBackV2)(BYTE *lpBuffer, DWORD dwBufferSize, LPVOID lpUser) ; 

//!������Ϣ�ص����� lCommand ��31λ��1,���ʾlpAlarmInfo��Ҫ����I8H_SDK_FreeMemory�ͷ��ڴ�;��0,���ʾ����Ҫ����I8H_SDK_FreeAlarm�ͷ��ڴ�
typedef void (CALLBACK *fAlarmDataCallBackV3)(HANDLE hUserId, HANDLE hAlarmHandle, LONG lCommand, LPVOID lpAlarmInfo, DWORD dwAlarmInfoLen, LPVOID lpUser) ; 

//!�豸RTSP����ԭʼ��Ϣ͸���ص�����(Onvif��ʽ��XML��Ϣ)  
typedef void (CALLBACK *fTransAlarmCallBack)(HANDLE hUserId, BYTE *lpBuffer, DWORD dwBufferSize, LPVOID lpUser) ; 

//!�����ݻص�����  dwOption:Bit0~7:��ʾ�������� 0-������ 1-������ Bit8~15:�������� Bit16~31:��ʾͨ����
typedef void (CALLBACK *fStreamDataCallBack)(HANDLE hHandle, DWORD dwOption, DWORD dwDataType, BYTE *lpBuffer, DWORD dwBufferSize, LPVOID lpUser) ; 

//!��׼H264���ݻص�����  dwOption:Bit0~7:��ʾ�������� 0-������ 1-������ Bit8~15:�������� Bit16~31:��ʾͨ����  dwDataType:Bit16-31��ʾ���� Bit8-15��ʾ֡�� Bit0-7��ʾ֡����
typedef void (CALLBACK *fStandardStreamDataCallBack)(HANDLE hHandle, DWORD dwOption, DWORD dwDataType, unsigned long long AbsTimeStamp, unsigned long long RelTimeStamp, BYTE *lpBuffer, DWORD dwBufferSize, LPVOID lpUser) ; 

//!��׼H264���ݻص�����V2  dwOption:Bit0~7:��ʾ�������� 0-������ 1-������ Bit8~15:�������� Bit16~31:��ʾͨ����  dwDataType:Bit16-31��ʾ���� Bit8-15��ʾ֡�� Bit0-7��ʾ֡����
typedef void (CALLBACK *fStandardStreamDataCallBackV2)(HANDLE hHandle, DWORD dwOption, DWORD dwDataType, DWORD dwFrameTime, DWORD dwFrameTickCount, DWORD dwRelTimeStamp, BYTE *lpBuffer, DWORD dwBufferSize, LPVOID lpUser) ; 

//!�����Խ����ݻص�����
typedef void (CALLBACK *fVoiceDataCallBack)(HANDLE hVoiceHandle, BYTE *lpBuffer, DWORD dwBufferSize, BYTE byAudioFlag, LPVOID lpUser) ; 

//!�����Խ����ݻص�����(��չ�ص�)
typedef void (CALLBACK *fVoiceDataCallBackV2)(HANDLE hVoiceHandle, BYTE *lpBuffer, DWORD dwBufferSize, DWORD dwAudioFlag, LPVOID lpUser) ; 


//!SDK�ӿں�������
I8H_SDK_API BOOL I8H_SDK_CALL I8H_SDK_Init(BOOL bAsync);
I8H_SDK_API BOOL I8H_SDK_CALL I8H_SDK_Initv2(LPI8H_INIT_PARAM lpParam);
I8H_SDK_API BOOL I8H_SDK_CALL I8H_SDK_Cleanup( );

I8H_SDK_API BOOL I8H_SDK_CALL I8H_SDK_SetExceptionCallBack(fExceptionCallBack fpExceptionCallBack, LPVOID lpUser);
I8H_SDK_API BOOL I8H_SDK_CALL I8H_SDK_SetAlarmDataCallBack(fAlarmDataCallBack fpMessageCallBack, LPVOID lpUser);
I8H_SDK_API BOOL I8H_SDK_CALL I8H_SDK_SetAlarmDataCallBackv2(fAlarmDataCallBackV2 fpMessageCallBack, LPVOID lpUser);
I8H_SDK_API BOOL I8H_SDK_CALL I8H_SDK_SetAlarmDataCallBackv3(fAlarmDataCallBackV3 fpMessageCallBack, LPVOID lpUser);
I8H_SDK_API BOOL I8H_SDK_CALL I8H_SDK_SetTransAlarmCallBack(fTransAlarmCallBack fpTransAlarmCallBack, LPVOID lpUser);

I8H_SDK_API BOOL I8H_SDK_CALL I8H_SDK_SetConnectTime(DWORD dwWaitTime, DWORD dwTryTimes);
I8H_SDK_API BOOL I8H_SDK_CALL I8H_SDK_SetReconnect(DWORD dwInterval, BOOL bEnableRecon);
I8H_SDK_API DWORD I8H_SDK_CALL I8H_SDK_GetSDKVersion( );
I8H_SDK_API DWORD I8H_SDK_CALL I8H_SDK_GetSDKBuildVersion( );
I8H_SDK_API DWORD I8H_SDK_CALL I8H_SDK_IsSupport( );
I8H_SDK_API DWORD I8H_SDK_CALL I8H_SDK_GetLastError( );
I8H_SDK_API char* I8H_SDK_CALL I8H_SDK_GetErrorMsg(DWORD dwLastError);


//!����ģ��
I8H_SDK_API BOOL I8H_SDK_CALL I8H_SDK_StartDiscovery(char *lpIfName, fDiscoveryCallBack fpDiscoveryCallBack, LPVOID lpUser);
I8H_SDK_API BOOL I8H_SDK_CALL I8H_SDK_StopDiscovery( );
I8H_SDK_API BOOL I8H_SDK_CALL I8H_SDK_ModifyDev(char *lpIfName, I8H_MODIFY_COMMAND eCmd, LPVOID lpBuffer, DWORD dwBufSize);


//!ע��ע��ģ��
I8H_SDK_API HANDLE I8H_SDK_CALL I8H_SDK_Login(char *lpDevIP, WORD wDevPort, char *lpUserName, char *lpPassword, LPI8H_DEVICEINFO lpDeviceInfo);
//�ڲ��ԽӶ�˳ר�ýӿ�,�ⲿ��Ա�Խ���Ū���֮������Ƿ�ʹ��,���Լ�����ͨ��SLINK I8H�Լ�T8S, nProtocolType: 0:��ͨ��SLINK I8H   1:T8SЭ��
I8H_SDK_API HANDLE I8H_SDK_CALL I8H_SDK_Loginv2(char *lpDevIP, WORD wDevPort, char *lpUserName, char *lpPassword, int nProtocolType, LPI8H_DEVICEINFO lpDeviceInfo);
I8H_SDK_API BOOL I8H_SDK_CALL I8H_SDK_Logout(HANDLE hUserId);


//!Ԥ����ؽӿ�
I8H_SDK_API HANDLE I8H_SDK_CALL I8H_SDK_RealPlay(HANDLE hUserId, LPI8H_CLIENTINFO lpClientInfo, fStreamDataCallBack fpRealDataCallBack, LPVOID lpUser);
I8H_SDK_API HANDLE I8H_SDK_CALL I8H_SDK_RealPlayv2(HANDLE hUserId, char *lpUserName, char *lpPassword, BYTE bySelfClean, LPI8H_CLIENTINFO lpClientInfo, fStreamDataCallBack fpRealDataCallBack, LPVOID lpUser);
I8H_SDK_API BOOL I8H_SDK_CALL I8H_SDK_StopRealPlay(HANDLE hRealHandle);
I8H_SDK_API BOOL I8H_SDK_CALL I8H_SDK_ControlRealPlay(HANDLE hRealHandle, DWORD dwControl, LPVOID lpInBuffer, DWORD dwInLen);
I8H_SDK_API BOOL I8H_SDK_CALL I8H_SDK_SetStandardCallBack4RealPlay(HANDLE hRealHandle, fStandardStreamDataCallBack fpStandardStreamCallBack, LPVOID lpUser);
I8H_SDK_API BOOL I8H_SDK_CALL I8H_SDK_SetStandardCallBack4RealPlayV2(HANDLE hRealHandle, fStandardStreamDataCallBackV2 fpStandardStreamCallBackV2, LPVOID lpUser);
I8H_SDK_API BOOL I8H_SDK_CALL I8H_SDK_StartRealPlayRecord(HANDLE hRealHandle, LPI8H_CHANNEL_INFO lpChannelInfo,  BYTE byFileType , char *lpSavedFileName) ;
I8H_SDK_API BOOL I8H_SDK_CALL I8H_SDK_StopRealPlayRecord(HANDLE hRealHandle, LPI8H_CHANNEL_INFO lpChannelInfo,   BYTE byFileType) ;


//!��̬����I֡
I8H_SDK_API BOOL I8H_SDK_CALL I8H_SDK_MakeKeyFrame(HANDLE hUserId, LONG lChannel);
I8H_SDK_API BOOL I8H_SDK_CALL I8H_SDK_MakeKeyFrameSub(HANDLE hUserId, LONG lChannel);


//!��̨������ؽӿ�
I8H_SDK_API BOOL I8H_SDK_CALL I8H_SDK_PTZControl(HANDLE hUserId, LONG lChannel, DWORD dwPtzCmd, DWORD dwStop, DWORD dwSpeed) ;
I8H_SDK_API BOOL I8H_SDK_CALL I8H_SDK_TransPTZ(HANDLE hUserId, LONG lChannel, BYTE *lpBuffer, DWORD dwSize) ;
I8H_SDK_API BOOL I8H_SDK_CALL I8H_SDK_PTZPreset(HANDLE hUserId, LONG lChannel, DWORD dwPtzPresetCmd, DWORD dwPresetIndex);
I8H_SDK_API BOOL I8H_SDK_CALL I8H_SDK_PTZCruise(HANDLE hUserId, LONG lChannel, DWORD dwPtzCruiseCmd, BYTE byCruiseRoute, BYTE byCruisePoint, DWORD wInput);//byCruiseRoute:Ѳ����� 1~255;  byCruisePoint:Ѳ���� 1~32; wInput:������� bit0-bit15:dwell, bit16-bit23:speed, bit24-bit32:preset
I8H_SDK_API BOOL I8H_SDK_CALL I8H_SDK_PTZTrack(HANDLE hUserId, LONG lChannel, DWORD dwPtzTrackCmd, DWORD dwPtzTrackId);

I8H_SDK_API BOOL I8H_SDK_CALL I8H_SDK_GetPTZCruise(HANDLE hUserId, LONG lChannel, LONG lCruiseRoute, LPI8H_CRUISE_RET lpCruiseRet);
I8H_SDK_API BOOL I8H_SDK_CALL I8H_SDK_PTZSet3D(HANDLE hUserId, LONG lChannel, DWORD dwXTop, DWORD dwYTop, DWORD dwXBottom, DWORD dwYBottom);


//!�ļ�����  ��ѯʱ�䲻�ܿ���   ���I8H_FINDDATA������Ҫ���� I8H_SDK_FreeMemory �ͷ�   I8H_FINDDATA[0]|I8H_FINDDATA[1]|I8H_FINDDATA[2]---
I8H_SDK_API BOOL I8H_SDK_CALL I8H_SDK_FindFile(HANDLE hUserId, LPI8H_FILECOND lpFindCond, BYTE **lpFileData, DWORD *lpOutSize);
I8H_SDK_API BOOL I8H_SDK_CALL I8H_SDK_FindFilev2(HANDLE hUserId, LPI8H_FILECONDV2 lpFindCondv2, BYTE **lpFileData, DWORD *lpOutSize);
I8H_SDK_API BOOL I8H_SDK_CALL I8H_SDK_FindFile4Monthly(HANDLE hUserId, LONG lChannel, LONG lStartYear, LONG lStartMonth, LONG lDaysOfMonth, DWORD *lpResult);
I8H_SDK_API BOOL I8H_SDK_CALL I8H_SDK_FindFile4Monthlyv2(HANDLE hUserId, LONG lChannel, LONG lStartYear, LONG lStartMonth, LONG lStartDay, LONG lDaysOfMonth, DWORD *lpResult);


//!���볬ʱֵ�ͳ��Դ���dwTime = (second << 16) | (trycount ) 
I8H_SDK_API BOOL I8H_SDK_CALL I8H_SDK_FindFileByTime(HANDLE hUserId, LPI8H_FILECOND lpFindCond, BYTE **lpFileData, DWORD *lpOutSize, DWORD dwTime);
I8H_SDK_API BOOL I8H_SDK_CALL I8H_SDK_FindFilev2ByTime(HANDLE hUserId, LPI8H_FILECONDV2 lpFindCondv2, BYTE **lpFileData, DWORD *lpOutSize, DWORD dwTime);
I8H_SDK_API BOOL I8H_SDK_CALL I8H_SDK_FindFile4MonthlyByTime(HANDLE hUserId, LONG lChannel, LONG lStartYear, LONG lStartMonth, LONG lDaysOfMonth, DWORD *lpResult, DWORD dwTime);
I8H_SDK_API BOOL I8H_SDK_CALL I8H_SDK_FindFile4Monthlyv2ByTime(HANDLE hUserId, LONG lChannel, LONG lStartYear, LONG lStartMonth, LONG lStartDay, LONG lDaysOfMonth, DWORD *lpResult, DWORD dwTime);


//!�ļ��ط�//dwOpt bit0 --bit7:stream type  0:main stream 1:sub stream   bit8--bit15:link mode  bit15--bit31:channel
I8H_SDK_API HANDLE I8H_SDK_CALL I8H_SDK_PlayBackByTime(HANDLE hUserId, DWORD dwOpt, LPI8H_TIME lpStartTime, LPI8H_TIME lpStopTime, fStreamDataCallBack fpPlayDataCallBack, LPVOID lpUser);
I8H_SDK_API HANDLE I8H_SDK_CALL I8H_SDK_PlayBackByTimev2(HANDLE hUserId, LPI8H_PLAYBACK_COND lpPalyBackCond, fStreamDataCallBack fpPlayDataCallBack, LPVOID lpUser);
I8H_SDK_API BOOL I8H_SDK_CALL I8H_SDK_PlayBackControl(HANDLE hPlayHandle, DWORD dwControl, LPVOID lpInBuffer, DWORD dwInLen, LPVOID lpOutBuffer, DWORD *lpOutLen);
I8H_SDK_API BOOL I8H_SDK_CALL I8H_SDK_StopPlayBack(HANDLE hPlayHandle);
I8H_SDK_API BOOL I8H_SDK_CALL I8H_SDK_SetStandardCallBack4PlayBack(HANDLE hPlayHandle, fStandardStreamDataCallBack fpStandardStreamCallBack, LPVOID lpUser);
I8H_SDK_API BOOL I8H_SDK_CALL I8H_SDK_SetStandardCallBack4PlayBackV2(HANDLE hPlayHandle, fStandardStreamDataCallBackV2 fpStandardStreamCallBackV2, LPVOID lpUser);



//!�ļ�����
I8H_SDK_API HANDLE I8H_SDK_CALL I8H_SDK_GetFileByTime(HANDLE hUserId, LONG lChannel, LPI8H_TIME lpStartTime, LPI8H_TIME lpStopTime, char *lpSavedFileName);
I8H_SDK_API BOOL I8H_SDK_CALL I8H_SDK_StopGetFile(HANDLE hFileHandle);
I8H_SDK_API int I8H_SDK_CALL I8H_SDK_GetDownloadPos(HANDLE hFileHandle);


//!����
I8H_SDK_API HANDLE I8H_SDK_CALL I8H_SDK_Upgrade(HANDLE hUserId, char *lpFileName);
I8H_SDK_API int I8H_SDK_CALL I8H_SDK_GetUpgradeState(HANDLE hUpgradeHandle);
I8H_SDK_API int I8H_SDK_CALL I8H_SDK_GetUpgradeProgress(HANDLE hUpgradeHandle);
I8H_SDK_API BOOL I8H_SDK_CALL I8H_SDK_CloseUpgradeHandle(HANDLE hUpgradeHandle);


//!����
I8H_SDK_API HANDLE I8H_SDK_CALL I8H_SDK_SetupAlarmChan(HANDLE hUserId);
I8H_SDK_API BOOL I8H_SDK_CALL I8H_SDK_CloseAlarmChan(HANDLE hAlarmHandle);

I8H_SDK_API BOOL I8H_SDK_CALL I8H_SDK_SubscribeNotify(HANDLE hUserId, char *lpRemoteIP, WORD wRemotePort, BOOL bSubscribe);

I8H_SDK_API HANDLE I8H_SDK_CALL I8H_SDK_SetupAlarmByRTSP(HANDLE hUserId);
I8H_SDK_API BOOL I8H_SDK_CALL I8H_SDK_CloseAlarmByRTSP(HANDLE hAlarmHandle);


//!�����Խ�(Ĭ����Ƶ��������ΪG711-A dwAudioType����Ƶ��������ȡֵ��Χ 0-OggVorbis;1-G711_U;2-G711_A 3-G726)
I8H_SDK_API HANDLE I8H_SDK_CALL I8H_SDK_StartVoiceCom(HANDLE hUserId, DWORD dwVoiceChan, fVoiceDataCallBack fpVoiceDataCallBack, LPVOID lpUser, DWORD dwAudioType);
I8H_SDK_API BOOL I8H_SDK_CALL I8H_SDK_VoiceComSendData(HANDLE hVoiceComHandle, BYTE *lpBuffer, DWORD dwSize);

//!�����Խ�(Ĭ����Ƶ��������ΪG711-A dwAudioType����Ƶ��������ȡֵ��Χ 0-OggVorbis;1-G711_U;2-G711_A 3-G726, Ŀǰ��֧��G711U��G711A���ͣ�������8000��λ��16������������Ƶ������������)
I8H_SDK_API HANDLE I8H_SDK_CALL I8H_SDK_StartVoiceComv2(HANDLE hUserId, DWORD dwVoiceChan, fVoiceDataCallBackV2 fpVoiceDataCallBack, LPVOID lpUser, DWORD dwAudioType);
//!dwOpt bit0~bit7:��Ƶ��������, 0--OggVorbis 1--G711_U  2--G711_A 3--G726  bit8~bit15:������,0--8000;bit16~bit23:λ��,0--16,1--32;bit24~bit32:����,0-������,1-˫����
I8H_SDK_API BOOL I8H_SDK_CALL I8H_SDK_VoiceComSendDatav2(HANDLE hVoiceComHandle, DWORD dwVoiceOpt, BYTE *lpBuffer, DWORD dwSize);

I8H_SDK_API BOOL I8H_SDK_CALL I8H_SDK_StopVoiceCom(HANDLE hVoiceComHandle);


//!�豸ץͼ
I8H_SDK_API BOOL I8H_SDK_CALL I8H_SDK_CaptureJPEGPicture(HANDLE hUserId, LONG lChannel, BYTE *lpJpegBuffer, DWORD dwJpegSize, DWORD *lpOutJpegSize);

I8H_SDK_API BOOL I8H_SDK_CALL I8H_SDK_CaptureJPEGPicturev2(HANDLE hUserId, LONG lChannel, char *lpFileName);

//!�豸�ָ�Ĭ��ֵ ������� ���� �ػ�����
I8H_SDK_API BOOL I8H_SDK_CALL I8H_SDK_RestoreConfig(HANDLE hUserId);
I8H_SDK_API BOOL I8H_SDK_CALL I8H_SDK_SaveConfig(HANDLE hUserId);
I8H_SDK_API BOOL I8H_SDK_CALL I8H_SDK_RebootDVR(HANDLE hUserId);
I8H_SDK_API BOOL I8H_SDK_CALL I8H_SDK_ShutDownDVR(HANDLE hUserId);

I8H_SDK_API BOOL I8H_SDK_CALL I8H_SDK_TranData(HANDLE hUserId, BYTE *lpUrl, BYTE *lpInBuffer, DWORD dwInSize, BYTE *lpOutBuffer, DWORD dwOutBufSize, DWORD *lpOutSize);
I8H_SDK_API BOOL I8H_SDK_CALL I8H_SDK_TranDatav2(HANDLE hUserId,  BYTE *lpUrl, BYTE *lpInBuffer, DWORD dwInSize, BYTE *lpOutBuffer, DWORD dwOutBufSize, DWORD *lpOutSize,DWORD dwTimeout);//!dwTimeout = (��ʱʱ��(��)<< 16)|(���Դ���)
//!dwTimeout = (��ʱʱ��(��)<< 16)|(���Դ���) dwBufSize��Ҫ���Ļ�����(���ֽ�Ϊ��λ,Ĭ��Ϊ1 * 1024 * 1024)
I8H_SDK_API BOOL I8H_SDK_CALL I8H_SDK_TranDatav3(HANDLE hUserId, BYTE *lpUrl, BYTE *lpInBuffer, DWORD dwInSize, BYTE *lpOutBuffer, DWORD dwOutBufSize, DWORD *lpOutSize, DWORD dwTimeout, DWORD dwBufSize);//!dwTimeout = (��ʱʱ��(��)<< 16)|(���Դ���)
I8H_SDK_API BOOL I8H_SDK_CALL I8H_SDK_FreeMemory(BYTE *lpBuffer);


//!������ȡ������
I8H_SDK_API BOOL I8H_SDK_CALL I8H_SDK_GetConfig(HANDLE hUserId, DWORD dwCommand, BYTE *lpInBuffer, DWORD dwInSize, BYTE *lpOutBuffer, DWORD dwOutBufSize, DWORD *lpOutSize);
I8H_SDK_API BOOL I8H_SDK_CALL I8H_SDK_SetConfig(HANDLE hUserId, DWORD dwCommand, BYTE *lpInBuffer, DWORD dwInSize, BYTE *lpOutBuffer, DWORD dwOutBufSize, DWORD *lpOutSize);


#endif 

