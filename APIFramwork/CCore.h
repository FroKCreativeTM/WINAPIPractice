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
	HDC				m_hDC;
	RESOLUTION		m_windowResolution;
	
public : 
	bool Init(HINSTANCE hInst);
	int Run();

private : 
	// ���� �޼���
	void Logic();
	// �Է� �޼���(�ð� ����̴�.)
	void Input(float fDeltaTime);
	// ������Ʈ �޼���
	int Update(float fDeltaTime);
	// ���� ������Ʈ(�浹 ���� ��ó�� ���� ����)
	int LateUpdate(float fDeltaTime);
	void Collision(float fDeltaTime);
	void Render(float fDeltaTime);


private : 
	// ¥�� ���������� INSTANCE�� ��ü ������ ���鲨��
	// �� ���� ���� �޼ҵ忡 �Ұ��ϱ� ������ �ܺο� �巯�� �ʿ䰡 ����.
	ATOM myRegisterClass();
	BOOL create();

public : 
	// WndProc�� �⺻������ ������ ���̱� ������ �ϴ� static�� �ٿ��д�.
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
};