/*
	name	: TaskReader.h
	auther	: PengYao
	time	: 2017/1/2
	des		: ����ʵ��CAbsIO��LoadXml�ӿ�
*/
#ifndef _READER_H_
#define _READER_H_

#include "AbsIO.h"

namespace Helper
{
	class CReader : public CAbsIO
	{
	public:
		CReader(const char* fileName = nullptr, const char* mode = nullptr)
			:CAbsIO(fileName, mode)
		{}

		/*
		@brief : ����xml�ļ���������xml����
		@param szPath : xml�ļ���·��
		*/
		virtual std::string LoadXml(std::string szPath) override;
	};
}
#endif