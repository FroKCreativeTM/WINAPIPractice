#pragma once

#include "Game.h"

class CCore
{
// �̱��� �ڵ� �� private ó���Ͽ� ���簡 ���� �ʰ� ���� ������ �� �Ҹ���
DECLARE_SINGLE(CCore)

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