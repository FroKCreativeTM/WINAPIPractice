#pragma once

#include "Game.h"

// 각 객체가 몇 번 참조되는가에 대한 정보를 저장하기 위한 클래스
class CRef
{
protected:
	CRef();
	virtual ~CRef() = 0;

protected : 
	int m_nRef;

public : 
	void AddRef() 
	{
		++m_nRef;
	}

	int Release()
	{
		--m_nRef;

		if (m_nRef == 0)
		{
			delete this;
			return 0;
		}

		return m_nRef;
	}
};

