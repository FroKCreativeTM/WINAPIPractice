#pragma once

#include "../Game.h"

// 게임에 그려지는 모든 것들은 이것을 상속받는다.
class CObj
{
protected : 
	CObj();
	virtual ~CObj();

protected : 
	// 모든 물체는 위치와 크기를 가진다.
	POSITION m_tPos;
	_SIZE m_tSize;
};

