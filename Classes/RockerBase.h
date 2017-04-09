#ifndef __RockerBase__H__
#define __RockerBase__H__

#include "cocos2d.h"
#include "yUtils\Utils\yUtils.h"

USING_NS_CC;

enum class RockerState : int
{
	Stay,
	Up,
	Down,
	Left,
	Right,
	LeftUp,
	LeftDown,
	RightUp,
	RightDown
};

/*
	@class : RockerBase
	@brief : ҡ����
*/
class RockerBase : public Layer
{
protected:
	Sprite* m_spBg;
	Sprite* m_spRocker;
	bool m_bIsTouchRocker;			//�Ƿ�����ҡ��
	int m_iState;					//��ǰ�˶��ķ���


	/*
		@brief :onTouchMoved���ã�����һ�����ȣ�-pi ~ pi�� 
				ͨ�����������õ�ǰ�˶��ķ���,
				����ͨ����д�÷�������չ���õ�״̬
		@param radian : ����()
	*/
	virtual void setState(float radian) = 0;

	/*
		@brief : ͨ��create���õĳ�ʼ������
		@param szBgFileName : ����ͼƬ�ļ���
		@param szRockerFileName : ҡ��ͼƬ�ļ���
		@param pos : ��ʼ�����
	*/

public:

	RockerBase();
	
	virtual ~RockerBase();

	bool init(const char* szBgFileName, const char* szRockerFileName, const Vec2& pos);

	/*
		@brief : ��ʼ��touch�¼�
				 ���������д����������滻�����onTouch����
	*/
	virtual void initTouchEvent();

	/*
		@brief : ��õ�ǰ�˶���״̬
	*/
	RockerState getState() const;

	virtual bool onTouchBegan(Touch *touch, Event *unused_event) override;

	virtual void onTouchMoved(Touch *touch, Event *unused_event) override;

	virtual void onTouchEnded(Touch *touch, Event *unused_event) override;

};


#endif