#ifndef _ABS_PARSER_H_
#define _ABS_PARSER_H_

/*
	@name	: AbsParser.h
	@auther	: PengYao
	@time	: 2017/1/2
	@des	: Parser�ĳ������
*/
namespace yUtils
{
	class CAbsParser
	{
	public:
		virtual ~CAbsParser()
		{
		}

		/*
		@brief : �������������һ��xml�ļ�
		@param fileName : xml�ļ��洢�������Ϊ�ĵ�ַ
		*/
		virtual bool Parse(const char* fileName) = 0;
	};
}

#endif