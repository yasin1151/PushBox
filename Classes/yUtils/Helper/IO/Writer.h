/*
name	: TaskWriter.h
auther	: PengYao
time	: 2016/12/15
des		: ����ʵ��AbsTaskIO��SaveAsXml�ӿ�
*/

#ifndef _WRITER_H_
#define _WRITER_H_

#include "AbsIO.h"

namespace Helper
{
	class CWriter : public CAbsIO
	{
	public:
		CWriter(const char* fileName = nullptr, const char* mode = nullptr)
			:CAbsIO(fileName, mode)
		{}
		/*
		@brief : ����xml�ļ���ָ��·��
		@param szData : xml����
		@param szPath : xml�����·��
		@return : ����ɹ����� true , ����ʧ�ܷ��� false
		*/
		virtual bool SaveAsXml(std::string szDate, std::string szPath) override;
	};
}
#endif