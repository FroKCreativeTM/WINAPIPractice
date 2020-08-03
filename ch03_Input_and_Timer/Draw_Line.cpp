#include <Windows.h>

const int MAX_LOADSTRING = 100;
const int M = 5;

/* ========== ���� ���� ========== */
HINSTANCE g_hInstance;
WCHAR g_strTitle[MAX_LOADSTRING] = L"Ch.01 Window Basic";
WCHAR g_strWindowClass[MAX_LOADSTRING] = L"Ch.01 Window Basic";

INT WIN_WIDTH = 800;
INT WIN_HEIGHT = 600;

/* ========== �Լ� ���� ========== */
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

INT WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	PSTR strCmdLine,
	INT nCmdLine)
{
	// ������ Ŭ���� ���
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

	// ������ ����
	HWND hWnd = CreateWindow(
		g_strWindowClass,		// Ŭ���� ���ڿ�
		g_strTitle,				// Ÿ��Ʋ ���ڿ�
		WS_OVERLAPPEDWINDOW,	// ������ ��Ÿ��
		CW_USEDEFAULT, 0,		// ǥ�� ��ġ
		CW_USEDEFAULT, 0,		// ������ ũ��
		nullptr, nullptr, hInstance, nullptr);

	// ������ ���̱� �� ����
	ShowWindow(hWnd, nCmdLine);
	UpdateWindow(hWnd);

	MSG message;
	// �޽��� ����
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