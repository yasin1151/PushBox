#include "PushBoxLayer.h"
Scene* PushBoxLayer::createScene()
{
	Scene* pScene = Scene::create();
	PushBoxLayer* pLayer = PushBoxLayer::create();
	pScene->addChild(pLayer);
	return pScene;
}
bool PushBoxLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}

	GidParser parser ;
	parser.Parse("Config/GidConfig.xml");

	// 1.创建瓦片地图
	TMXTiledMap* tmxMap = TMXTiledMap::create("map.tmx");
	// 2.添加到当前层
	this->addChild(tmxMap);

	// 获取图层（参数：图层名字）
	walkLayer = tmxMap->getLayer("walkLayer");
	bool bIsFind = false;
	int camalGid = GID["camel"];
	for (int i = 0; i < tmxMap->getMapSize().width; i++)
	{
		if (bIsFind)
		{
			break;
		}
		for (int j = 0; j < tmxMap->getMapSize().height; j++)
		{
			// 找gid值
			int gid = walkLayer->getTileGIDAt(Vec2(i, j));
			if (camalGid == gid)
			{
				m_posHero = Vec2(i, j);
				bIsFind = true;
				break;
			}
		}
	}


	MenuItemFont* itemRight = 
		MenuItemFont::create(yUtils::GBK2UTF("右").c_str(), this, menu_selector(PushBoxLayer::RightCallBack));
	itemRight->setPosition(Vec2(100, 100));

	MenuItemFont* itemLeft =
		MenuItemFont::create(yUtils::GBK2UTF("左").c_str(), this, menu_selector(PushBoxLayer::LeftCallBack));
	itemLeft->setPosition(Vec2(20, 100));

	MenuItemFont* itemUp =
		MenuItemFont::create(yUtils::GBK2UTF("上").c_str(), this, menu_selector(PushBoxLayer::UpCallBack));
	itemUp->setPosition(Vec2(60, 150));

	MenuItemFont* itemDown =
		MenuItemFont::create(yUtils::GBK2UTF("下").c_str(), this, menu_selector(PushBoxLayer::DownCallBack));
	itemDown->setPosition(Vec2(60, 100));

	Menu* menu = Menu::create(itemRight, itemLeft, itemUp, itemDown, NULL);
	this->addChild(menu);
	menu->setPosition(0, 0);
	menu->setAnchorPoint(Vec2(0, 0));
	


	//摇杆不好用
//	m_pRocker = Rocker4AWithTrans::create("Direction_bc.png", "Direction_bt.png", Vec2(100, 100), ROCKER_LD);
//	this->addChild(m_pRocker);

//	this->schedule(SEL_SCHEDULE(&PushBoxLayer::moveUpdate), 0.3f, -1, 0.0f);
	return true;
}



void PushBoxLayer::moveUpdate(float dt)
{
	switch (m_pRocker->getState())
	{
	case RockerState::Up:
		UpCallBack(nullptr);
		break;
	case RockerState::Down:
		DownCallBack(nullptr);
		break;
	case RockerState::Left:
		LeftCallBack(nullptr);
		break;
	case RockerState::Right:
		RightCallBack(nullptr);
		break;
	default:
		break;
	}
}

// 按钮回调
void PushBoxLayer::RightCallBack(Ref* ref)
{
	moveFun(1, 0);
}

void PushBoxLayer::LeftCallBack(Ref* ref)
{
	moveFun(-1, 0);
}

void PushBoxLayer::UpCallBack(Ref* ref)
{
	moveFun(0, -1);
}

void PushBoxLayer::DownCallBack(Ref* ref)
{
	moveFun(0, 1);
}

void PushBoxLayer::moveFun(int x, int y)
{
	int iCurGid = walkLayer->getTileGIDAt(m_posHero);
	int iNextGid = walkLayer->getTileGIDAt(m_posHero + Vec2(x, y));

	//如果当前位置是空地
	if (GID["camel"] == iCurGid)
	{
		if (GID["space"] == iNextGid)
		{
			walkLayer->setTileGID(GID["space"], m_posHero);
			walkLayer->setTileGID(GID["camel"], m_posHero += Vec2(x, y));
		}
		else if (GID["sheep"] == iNextGid)
		{
			int iNext2Gid = walkLayer->getTileGIDAt(m_posHero + Vec2(x + x, y + y));
			if (GID["space"] == iNext2Gid)
			{
				//马羊空
				walkLayer->setTileGID(GID["space"], m_posHero);
				walkLayer->setTileGID(GID["camel"], m_posHero += Vec2(x, y));
				walkLayer->setTileGID(GID["sheep"], m_posHero + Vec2(x, y));

			}
			else if (GID["riverDefault"] == iNext2Gid)
			{
				//马羊河
				walkLayer->setTileGID(GID["space"], m_posHero);
				walkLayer->setTileGID(GID["camel"], m_posHero += Vec2(x, y));
				walkLayer->setTileGID(GID["riverSheep"], m_posHero + Vec2(x, y));
			}
		}
		else if (GID["riverSheep"] == iNextGid)
		{
			int iNext2Gid = walkLayer->getTileGIDAt(m_posHero + Vec2(x + x, y + y));
			if (GID["space"] == iNext2Gid)
			{
				//
				walkLayer->setTileGID(GID["space"], m_posHero);
				walkLayer->setTileGID(GID["riverCamel"], m_posHero += Vec2(x, y));
				walkLayer->setTileGID(GID["sheep"], m_posHero + Vec2(x, y));
			}
		}
		else if (GID["riverDefault"] == iNextGid)
		{
			walkLayer->setTileGID(GID["space"], m_posHero);
			walkLayer->setTileGID(GID["riverCamel"], m_posHero += Vec2(x, y));
		}
	}
	//如果当前位置是河流中
	else if (GID["riverCamel"] == iCurGid)
	{
		if (GID["space"] == iNextGid)
		{
			walkLayer->setTileGID(GID["riverDefault"], m_posHero);
			walkLayer->setTileGID(GID["camel"], m_posHero += Vec2(x, y));
		}
		else if (GID["sheep"] == iNextGid)
		{
			int iNext2Gid = walkLayer->getTileGIDAt(m_posHero + Vec2(x + x, y + y));
			if (GID["space"] == iNext2Gid)
			{
				//河羊空
				walkLayer->setTileGID(GID["riverDefault"], m_posHero);
				walkLayer->setTileGID(GID["camel"], m_posHero += Vec2(x, y));
				walkLayer->setTileGID(GID["sheep"], m_posHero + Vec2(x, y));

			}
		}
	}

}
