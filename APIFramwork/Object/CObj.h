#pragma once

#include "../Game.h"

// ���ӿ� �׷����� ��� �͵��� �̰��� ��ӹ޴´�.
class CObj
{
protected : 
	CObj();
	virtual ~CObj();

protected : 
	// ��� ��ü�� ��ġ�� ũ�⸦ ������.
	POSITION m_tPos;
	_SIZE m_tSize;
};

