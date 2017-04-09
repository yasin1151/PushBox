#include "Rocker4A.h"

void Rocker4A::setState(float radian)
{
	m_iState = static_cast<int>(RockerState::Stay);
	using std::_Pi;
	if (radian > _Pi / 4 && radian <= _Pi * 3 / 4)
	{
		//up
		m_iState = static_cast<int>(RockerState::Up);
	}
	else if ((radian > _Pi * 3 / 4 && radian < _Pi) ||
		(radian > -_Pi && radian < -_Pi * 3 / 4))
	{
		//left		
		m_iState = static_cast<int>(RockerState::Left);
	}
	else if (radian > -_Pi * 3 / 4 && radian <= -_Pi / 4)
	{
		//down
		m_iState = static_cast<int>(RockerState::Down);
	}
	else if (radian > - _Pi && radian <= _Pi / 4)
	{
		//right
		m_iState = static_cast<int>(RockerState::Right);
	}

}

Rocker4A* Rocker4A::create(const char* szBgFileName, const char* szRockerFileName, const Vec2& pos)
{
	Rocker4A* pRet = new Rocker4A();
	if (pRet && pRet->init(szBgFileName, szRockerFileName, pos))
	{
		pRet->autorelease();
	}
	else
	{
		CC_SAFE_DELETE(pRet);
	}
	return pRet;
}

