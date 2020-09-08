#define _USE_MATH_DEFINES
#include <Windows.h>
#include <cmath>		// M_PI

#define RADIUS 100
#define RADIAN(X) ((X) * M_PI / 180)

const int MAX_LOADSTRING = 100;
const int M = 5;

/* ========== 전역 변수 ========== */
HINSTANCE	g_hInstance;
WCHAR		g_strTitle[MAX_LOADSTRING]			= L"시계";
WCHAR		g_strWindowClass[MAX_LOADSTRING]	= L"Clock";

INT WIN_WIDTH = 800;
INT WIN_HEIGHT = 600;

/* ========== 함수 선언 ========== */
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

INT WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	PSTR strCmdLine,
	INT nCmdLine)
{
	// 윈도우 클래스 등록
	WNDCLASSEX wcex;
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = nullptr;
	wcex.lpszClassName = g_strWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, IDI_APPLICATION);
	RegisterClassEx(&wcex);

	g_hInstance = hInstance;

	// 윈도우 생성
	HWND hWnd = CreateWindow(
		g_strWindowClass,		// 클래스 문자열
		g_strTitle,				// 타이틀 문자열
		WS_OVERLAPPEDWINDOW,	// 윈도우 스타일
		CW_USEDEFAULT, 0,		// 표시 위치
		640, 480,				// 윈도우 크기
		nullptr, nullptr, hInstance, nullptr);

	// 윈도우 보이기 및 갱신
	ShowWindow(hWnd, nCmdLine);
	UpdateWindow(hWnd);

	MSG message;
	// 메시지 루프
	while (GetMessage(&message, nullptr, 0, 0))
	{
		TranslateMessage(&message);
		DispatchMessage(&message);
	}

	return (INT)message.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	SYSTEMTIME systime;
	POINT pt;
	double theta;

	static RECT rtClient;
	static WCHAR szTime[128];
	static POINT ptCircle;
	static double sec, minute, hour;
	static HPEN hPen[3];

	switch (message)
	{
	case WM_CREATE:
		hPen[0] = CreatePen(PS_SOLID, 8, RGB(0, 0, 255));
		hPen[1] = CreatePen(PS_SOLID, 4, RGB(0, 255, 255));
		hPen[2] = CreatePen(PS_SOLID, 2, RGB(255, 0, 255));
		SetTimer(hwnd, 1, 1000, nullptr);
		SendMessage(hwnd, WM_TIMER, 1, 0);			// 즉시 WM_TIMER로 메시지를 보내기 위한 용도
		break;
	case WM_SIZE:
		GetClientRect(hwnd, &rtClient);
		ptCircle.x = rtClient.right / 2;
		ptCircle.y = rtClient.bottom / 2;
		break;
	case WM_TIMER:
		GetLocalTime(&systime);
		wsprintf(szTime, L"(%d-%d-%d : %d:%d:%d)", systime.wYear, systime.wMonth, systime.wDay,
			systime.wHour, systime.wMinute, systime.wSecond);
		sec = systime.wSecond;
		minute = systime.wMinute + sec / 60.0;
		hour = systime.wHour + minute / 60.0;
		InvalidateRect(hwnd, nullptr, TRUE);
		break;
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hwnd, &ps);

		DrawText(hdc, szTime, -1, &rtClient, DT_CENTER);
		Ellipse(hdc, ptCircle.x - RADIUS, ptCircle.y - RADIUS, ptCircle.x + RADIUS, ptCircle.y + RADIUS);

		// 1 시계의 텍스트를 그린다.
		for (int i = 0; i <= 12; i++)
		{
			theta = (i - 3) * 30;
			pt.x = (int)(RADIUS * cos(RADIAN(theta)) + ptCircle.x + 0.5);
			pt.y = (int)(RADIUS * sin(RADIAN(theta)) + ptCircle.y + 0.5);

			WCHAR str[10];
			wsprintf(str, L"%d", i);
			RECT rt;
			SetRect(&rt, pt.x - 10, pt.y - 10, pt.x + 10, pt.y + 10);
			DrawText(hdc, str, -1, &rt, DT_CENTER);
		}

		// 2 시침 그리기
		theta = (hour * 30 - 90);
		pt.x = (int)((RADIUS - 20) * cos(RADIAN(theta)) + ptCircle.x + 0.5);
		pt.y = (int)((RADIUS - 20) * sin(RADIAN(theta)) + ptCircle.y + 0.5);

		HPEN hOldPen = (HPEN)SelectObject(hdc, hPen[0]);
		MoveToEx(hdc, ptCircle.x, ptCircle.y, nullptr);
		LineTo(hdc, pt.x, pt.y);

		// 3 분침 그리기 
		theta = (minute * 6 - 90);
		pt.x = (int)((RADIUS - 10) * cos(RADIAN(theta)) + ptCircle.x + 0.5);
		pt.y = (int)((RADIUS - 10) * sin(RADIAN(theta)) + ptCircle.y + 0.5);

		SelectObject(hdc, hPen[1]);
		MoveToEx(hdc, ptCircle.x, ptCircle.y, nullptr);
		LineTo(hdc, pt.x, pt.y);

		// 4 초침 그리기
		theta = (sec * 6 - 90);
		pt.x = (int)((RADIUS - 5) * cos(RADIAN(theta)) + ptCircle.x + 0.5);
		pt.y = (int)((RADIUS - 5) * sin(RADIAN(theta)) + ptCircle.y + 0.5);

		SelectObject(hdc, hPen[2]);
		MoveToEx(hdc, ptCircle.x, ptCircle.y, nullptr);
		LineTo(hdc, pt.x, pt.y);

		SelectObject(hdc, hOldPen);

		EndPaint(hwnd, &ps);
	}
	break;
	case WM_DESTROY:
		for (int i = 0; i < 3; i++)
		{
			DeleteObject(hPen[i]);
		}
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
	}
	return 0;
}