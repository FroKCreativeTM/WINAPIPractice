#include <Windows.h>

/* ========== 전역 변수 ========== */
const int MAX_LOADSTRING = 100;
const int STEP = 10;
const int R = 50;

HINSTANCE g_hInstance;
WCHAR g_strTitle[MAX_LOADSTRING] = L"Ch.01 Window Basic";
WCHAR g_strWindowClass[MAX_LOADSTRING] = L"Ch.01 Window Basic";

INT WIN_WIDTH = 800;
INT WIN_HEIGHT = 600;

POINT ptCircle;
RECT rtClient;
int iDirection = VK_RIGHT;

/* ========== 함수 선언 ========== */
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
void Timerproc(HWND hwnd, UINT message, UINT_PTR nID, DWORD dwTime);

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
	switch (message)
	{
	case WM_CREATE:
	{
		SetTimer(hwnd, 1, 50, (TIMERPROC)Timerproc);
	}
	break;
	case WM_SIZE:
	{
		GetClientRect(hwnd, &rtClient);
		ptCircle.x = rtClient.right / 2;
		ptCircle.y = rtClient.bottom / 2;
	}
	break;
	case WM_KEYDOWN: 
	{
		// 동시 입력이 가능해진다.
		if (GetAsyncKeyState(VK_LEFT) & 0x8000) iDirection = VK_LEFT;
		if (GetAsyncKeyState(VK_RIGHT) & 0x8000) iDirection = VK_RIGHT;
		if (GetAsyncKeyState(VK_UP) & 0x8000) iDirection = VK_UP;
		if (GetAsyncKeyState(VK_DOWN) & 0x8000) iDirection = VK_DOWN;
	}
	break;
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hwnd, &ps);
		{
			Ellipse(hdc, ptCircle.x - R, ptCircle.y - R, ptCircle.x + R, ptCircle.y + R);
		}
		EndPaint(hwnd, &ps);
	}
	break;
	case WM_DESTROY:
	{
		KillTimer(hwnd, 1);
		PostQuitMessage(0);
	}
	break;
	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
	}
	return 0;
}

void Timerproc(HWND hwnd, UINT message, UINT_PTR nID, DWORD dwTime)
{
	switch (iDirection)
	{
	case VK_LEFT:
		ptCircle.x -= STEP;
		if (ptCircle.x <= R)
		{
			iDirection = VK_RIGHT;
		}
		break;
	case VK_RIGHT:
		ptCircle.x += STEP;
		if (ptCircle.x >= rtClient.right - R)
		{
			iDirection = VK_LEFT;
		}
		break;
	case VK_UP:
		ptCircle.y -= STEP;
		if (ptCircle.y <= R)
		{
			iDirection = VK_DOWN;
		}
		break;
	case VK_DOWN:
		ptCircle.y += STEP;
		if (ptCircle.y >= rtClient.bottom - R)
		{
			iDirection = VK_UP;
		}
		break;
	}
	RECT rt;
	SetRect(&rt, ptCircle.x - R - 10, ptCircle.y - R - 10, ptCircle.x + R + 10, ptCircle.y + R + 10);
	InvalidateRect(hwnd, &rt, TRUE);
}
