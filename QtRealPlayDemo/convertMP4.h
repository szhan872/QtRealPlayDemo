#pragma once

#ifndef HANDLE
typedef void* HANDLE;
#endif // !HANDLE

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

	void ConvertMP4_init();		//初始化
	void ConvertMP4_uninit();	//反初始化

	//这里来处理写入
	HANDLE ConvertMP4_Open(char* filename);
	bool ConvertMP4_SavePacket(HANDLE handle, unsigned char* pData, int length);
	void ConvertMP4_Close(HANDLE handle);
	__int64 ConvertMP4_GetFileDuration(char* filename);								//获取文件时长 单位为微妙us

	//这里新添加解封装MP4文件接口
	HANDLE ConvertMP4_Demuxer_Open(char* filename,unsigned int beginTime);			//文件视频起始时间由外部传入,为unix时间戳
	bool ConvertMP4_Demuxer_getPacket(HANDLE handle, unsigned char* &pData, int &length);
	void ConvertMP4_Demuxer_Close(HANDLE handle);
	bool ConvertMP4_Demuxer_Seek(HANDLE handle, unsigned int seektime);				//seek录像
	bool ConvertMP4_Demuxer_IFrameOnly(HANDLE handle, bool bIFrameOnly);			//只弹I帧
	void ConvertMP4_Demuxer_Release(void *pBuf);									//释放申请的帧数据

#ifdef __cplusplus
}
#endif // __cplusplus
