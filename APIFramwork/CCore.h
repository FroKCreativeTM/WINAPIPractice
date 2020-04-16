#pragma once

#include "Game.h"

class CCore
{
private : 
	// �̱����� ���� ����
	static CCore* m_Inst;

public : 
	static CCore* GetInst()
	{
		if (!m_Inst)
			m_Inst = new CCore;
		return m_Inst;
	}

	static void DestroyInst()
	{
		SAFE_DELETE(m_Inst);
	}

// �ٸ� ���� �����ڿ� �������� ���ϰ�
private : 
	CCore();
	~CCore();
};