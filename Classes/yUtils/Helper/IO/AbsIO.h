#ifndef _ABS_IO_H_
#define _ABS_IO_H_

/*
	name   : AbsIO.h
	auther : PengYao
	time   : 2017/1/11
	des	   : ����io�ӿڣ��������Լ���yFile�⣬����ӿ�
*/

#include "../yfile.h"
#include <string>

namespace Helper
{
	class CAbsIO
	{
	protected:
		yUtils::CFile* m_cFileMgr;
	public:
		CAbsIO(const char* fileName = nullptr, const char* mode = nullptr)
		{
			m_cFileMgr = new yUtils::CFile;
			if (fileName && mode)
			{
				m_cFileMgr->load(fileName, mode);
			}
		}

		virtual ~CAbsIO()
		{
			if (m_cFileMgr)
			{
				delete m_cFileMgr;
			}
		}

		/*
			@brief : ����xml�ļ�
			@param szPath : xml�ļ���·��
			@warning : ����ʵ�ֿ�������
		*/
		virtual std::string LoadXml(std::string szPath)
		{
			return "";
		}

		/*
			@brief : ����xml�ļ���ָ��·��
			@param szData : xml����
			@param szPath : xml�����·��
			@warning �� ����ʵ�ֿ�������
		*/
		virtual bool SaveAsXml(std::string szDate, std::string szPath)
		{
			return false;
		}


		//��ȡ�ļ�ָ��
		FILE* GetFilePtr() const
		{
			if (m_cFileMgr->isOpen())
			{
				return m_cFileMgr->getFilePtr();
			}
			return nullptr;
		}
	};
}

#endif