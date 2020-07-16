#pragma once

#include "Game.h"

// �� ��ü�� �� �� �����Ǵ°��� ���� ������ �����ϱ� ���� Ŭ����
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

