#include <Windows.h>

const int MAX_LOADSTRING = 100;
const int M = 5;

/* ========== 전역 변수 ========== */
HINSTANCE g_hInstance;
WCHAR g_strTitle[MAX_LOADSTRING] = L"Ch.01 Window Basic";
WCHAR g_strWindowClass[MAX_LOADSTRING] = L"Ch.01 Window Basic";

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
		CW_USEDEFAULT, 0,		// 윈도우 크기
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
	static HPEN hBluePen;
	static BOOL bDraw = FALSE;
	static POINT ptStart, ptEnd;
	switch (message)
	{
	case WM_CREATE: 
	{
		hBluePen = CreatePen(PS_DASH, 1, RGB(0, 0, 255));
	}
	break;
	case WM_LBUTTONDOWN :
	{
		ptStart.x = LOWORD(lParam);
		ptStart.y = HIWORD(lParam);
		ptEnd = ptStart;
	}
	break;
	case WM_LBUTTONUP :
	{
		bDraw = TRUE;
		InvalidateRect(hwnd, nullptr, TRUE);
	}
	break;
	case WM_MOUSEMOVE : 
	{
		if (wParam & MK_LBUTTON)
		{
			// #1
			HDC hdc = GetDC(hwnd);
			int iOldMode = SetROP2(hdc, R2_NOTXORPEN);

			HPEN hOldPen = (HPEN)SelectObject(hdc, hBluePen);
			MoveToEx(hdc, ptStart.x, ptStart.y, nullptr);
			LineTo(hdc, ptEnd.x, ptEnd.y);

			// #2
			ptEnd.x = LOWORD(lParam);
			ptEnd.y = HIWORD(lParam);

			MoveToEx(hdc, ptStart.x, ptStart.y, nullptr);
			LineTo(hdc, ptEnd.x, ptEnd.y);

			SelectObject(hdc, hOldPen);
			SetROP2(hdc, iOldMode);
			ReleaseDC(hwnd, hdc);
		}
	}
	break;
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hwnd, &ps);
		{
			if (bDraw)
			{
				MoveToEx(hdc, ptStart.x, ptStart.y, nullptr);
				LineTo(hdc, ptEnd.x, ptEnd.y);
				Rectangle(hdc, ptStart.x - M, ptStart.y - M, ptStart.x + M, ptStart.y + M);
				Rectangle(hdc, ptEnd.x - M, ptEnd.y - M, ptEnd.x + M, ptEnd.y + M);
			}
		}
		EndPaint(hwnd, &ps);
	}
	break;
	case WM_DESTROY:
	{
		DeleteObject(hBluePen);
		PostQuitMessage(0);
	}
	break;
	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
	}
	return 0;
}