#ifndef __Rocker4AWithTrans__H__
#define __Rocker4AWithTrans__H__

#include "Rocker4A.h"


//Ϊ��������ֵ�ĺ궨��
//���£���Ϊ1/3, ��Ϊ3/4 ��������
#define ROCKER_LD \
	(Rect(0, 0, Director::getInstance()->getVisibleSize().width / 3,\
		Director::getInstance()->getVisibleSize().height * 3 / 4))
//���£���Ϊ1/3, ��Ϊ3/4 ��������
#define ROCKER_RD \
	(Rect(Director::getInstance()->getVisibleSize().width * 2 / 3, 0, \
		Director::getInstance()->getVisibleSize().width / 3, \
		Director::getInstance()->getVisibleSize().height * 3 / 4))

/*
	@class : Rocker4AWithTrans
	@brief : һ��ֻ����4�����򣬲�����һ��������ʾ��ҡ��
*/
class Rocker4AWithTrans : public Rocker4A
{
protected:
	Rect m_touchRect;		//����������ڽ��д����Ż���ʾҡ��

	/*
		@brief : ��ʾ������ҡ�˵�λ��
		@param pos : ҡ�˵�λ��
	*/
	void setRockerPosWithShow(const Vec2& pos);

	/*
		@brief : ����ҡ�˵���ʾ���
		@param bIsShow : �Ƿ���ʾ
	*/
	void setRockerShow(bool bIsShow);
public:
	static Rocker4AWithTrans* create(const char* szBgFileName, const char* szRockerFileName, const Vec2& pos, const Rect& touchRect);

	bool init(const char* szBgFileName, const char* szRockerFileName, const Vec2& pos, const Rect& touchRect); 

	virtual void initTouchEvent() override;

	virtual bool onTouchBegan(Touch *touch, Event *unused_event) override;

	virtual void onTouchEnded(Touch *touch, Event *unused_event) override;

};


#endif