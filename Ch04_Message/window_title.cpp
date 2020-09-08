#define _USE_MATH_DEFINES
#include <Windows.h>
#include <cmath>		// M_PI

#define RADIUS 100
#define RADIAN(X) ((X) * M_PI / 180)

const int MAX_LOADSTRING = 100;
const int M = 5;

/* ========== 전역 변수 ========== */
HINSTANCE	g_hInstance;
WCHAR		g_strTitle[MAX_LOADSTRING] = L"시계";
WCHAR		g_strWindowClass[MAX_LOADSTRING] = L"Clock";

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
	static WCHAR szTime[128];

	switch (message)
	{
	case WM_CREATE:
		SetTimer(hwnd, 1, 1000, nullptr);
		SendMessage(hwnd, WM_TIMER, 1, 0);			// 즉시 WM_TIMER로 메시지를 보내기 위한 용도
		break;
	case WM_TIMER:
		GetLocalTime(&systime);
		wsprintf(szTime, L"(%d-%d-%d : %d:%d:%d)", systime.wYear, systime.wMonth, systime.wDay,
			systime.wHour, systime.wMinute, systime.wSecond);
		// SetWindowText(hwnd, szTime);	// 이 윈도우 창의 이름을 설정한다.
		SendMessage(hwnd, WM_SETTEXT, 0, (LPARAM)szTime);
		break;
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hwnd, &ps);
		EndPaint(hwnd, &ps);
	}
	break;
	case WM_DESTROY:
		KillTimer(hwnd, 1);
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
	}
	return 0;
}