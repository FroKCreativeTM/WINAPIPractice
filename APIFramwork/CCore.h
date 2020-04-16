#pragma once

#include "Game.h"

class CCore
{
private : 
	// 싱글톤을 위한 선언
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

// 다른 놈은 생성자에 접근하지 못하게
private : 
	CCore();
	~CCore();
};