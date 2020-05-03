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
	// ¥�� ���������� INSTANCE�� ��ü ������ ���鲨��
	// �� ���� ���� �޼ҵ忡 �Ұ��ϱ� ������ �ܺο� �巯�� �ʿ䰡 ����.
	ATOM myRegisterClass();
	BOOL create();

public : 
	// WndProc�� �⺻������ ������ ���̱� ������ �ϴ� static�� �ٿ��д�.
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
};