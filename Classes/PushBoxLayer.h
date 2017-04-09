#ifndef _PushBoxLayer_H_
#define _PushBoxLayer_H_
#include "cocos2d.h"
#include "Rocker4AWithTrans.h"
#include "Config\GidParser.h"
USING_NS_CC;

class PushBoxLayer : public Layer
{
private:
	// 英雄坐标索引
	Vec2 m_posHero;
	// 行走层
	TMXLayer* walkLayer;

	Rocker4AWithTrans* m_pRocker;
public:

	virtual bool init() override;
	static Scene* createScene();
	CREATE_FUNC(PushBoxLayer);


	void moveUpdate(float dt);

	// 按钮回调
	void RightCallBack(Ref* ref);
	void LeftCallBack(Ref* ref);
	void UpCallBack(Ref* ref);
	void DownCallBack(Ref* ref);

	void moveFun(int x, int y);
};

#endif