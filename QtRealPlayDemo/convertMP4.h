#pragma once

#ifndef HANDLE
typedef void* HANDLE;
#endif // !HANDLE

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

	void ConvertMP4_init();		//��ʼ��
	void ConvertMP4_uninit();	//����ʼ��

	//����������д��
	HANDLE ConvertMP4_Open(char* filename);
	bool ConvertMP4_SavePacket(HANDLE handle, unsigned char* pData, int length);
	void ConvertMP4_Close(HANDLE handle);
	__int64 ConvertMP4_GetFileDuration(char* filename);								//��ȡ�ļ�ʱ�� ��λΪ΢��us

	//��������ӽ��װMP4�ļ��ӿ�
	HANDLE ConvertMP4_Demuxer_Open(char* filename,unsigned int beginTime);			//�ļ���Ƶ��ʼʱ�����ⲿ����,Ϊunixʱ���
	bool ConvertMP4_Demuxer_getPacket(HANDLE handle, unsigned char* &pData, int &length);
	void ConvertMP4_Demuxer_Close(HANDLE handle);
	bool ConvertMP4_Demuxer_Seek(HANDLE handle, unsigned int seektime);				//seek¼��
	bool ConvertMP4_Demuxer_IFrameOnly(HANDLE handle, bool bIFrameOnly);			//ֻ��I֡
	void ConvertMP4_Demuxer_Release(void *pBuf);									//�ͷ������֡����

#ifdef __cplusplus
}
#endif // __cplusplus
