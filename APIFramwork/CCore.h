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

private : 
	static bool			m_loopWindow;

private : 
	HINSTANCE		m_hInst;
	HWND			m_hWnd;
	RESOLUTION		m_windowResolution;
	
public : 
	bool Init(HINSTANCE hInst);
	int Run();

private : 
	// 짜피 레지스터할 INSTANCE는 객체 내에서 만들꺼고
	// 이 놈은 헬퍼 메소드에 불과하기 때문에 외부에 드러낼 필요가 없다.
	ATOM myRegisterClass();
	BOOL create();

public : 
	// WndProc는 기본적으로 전역인 놈이기 때문에 일단 static을 붙여둔다.
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
};