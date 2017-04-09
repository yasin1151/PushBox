#ifndef __Rocker4A__H__
#define __Rocker4A__H__

#include "RockerBase.h"

/*
	@class : Rocker4A
	@brief : �ĸ������ҡ��
*/
class Rocker4A : public RockerBase
{
protected:
	
	/*
		@brief : ��д�����setState������
				 ����ֻʵ��4�������״̬
	*/
	virtual void setState(float radian) override;

public:
	/*
	@brief : ����һ��ҡ��
	@param szBgFileName : ����ͼƬ�ļ���
	@param szRockerFileName : ҡ��ͼƬ�ļ���
	@param pos : ��ʼ�����
	*/
	static Rocker4A* create(const char* szBgFileName, const char* szRockerFileName, const Vec2& pos);
};

#endif