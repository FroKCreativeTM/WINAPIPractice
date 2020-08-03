#include <Windows.h>

const int MAX_LOADSTRING = 100;
const int STEP = 10;
const int R = 50;

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
	static POINT ptCircle;
	static RECT rtClient;
	static int iDirection = VK_RIGHT;
	switch (message)
	{
	case WM_CREATE : 
	{
		SetTimer(hwnd, 1, 50, nullptr);
	}
	break;		
	case WM_SIZE : 
	{
		GetClientRect(hwnd, &rtClient);
		ptCircle.x = rtClient.right / 2;
		ptCircle.y = rtClient.bottom / 2;
	}
	break;
	case WM_KEYDOWN:
		// ���� �Է��� ����������.
		if (GetAsyncKeyState(VK_LEFT) & 0x8000) iDirection = VK_LEFT;
		if (GetAsyncKeyState(VK_RIGHT) & 0x8000) iDirection = VK_RIGHT;
		if (GetAsyncKeyState(VK_UP) & 0x8000) iDirection = VK_UP;
		if (GetAsyncKeyState(VK_DOWN) & 0x8000) iDirection = VK_DOWN;
		break;
	case WM_TIMER : 
	{
		switch (iDirection)
		{
		case VK_LEFT :
			ptCircle.x -= STEP;
			break;
		case VK_RIGHT:
			ptCircle.x += STEP;
			break;
		case VK_UP:
			ptCircle.y -= STEP;
			break;
		case VK_DOWN:
			ptCircle.y += STEP;
			break;
		}

		// ��踦 �����ϸ� ���� ����
		if (ptCircle.x - R <= 0)
		{
			ptCircle.x = R;
			iDirection = VK_RIGHT;
		}
		if (ptCircle.x + R >= rtClient.right)
		{
			ptCircle.x = rtClient.right - R;
			iDirection = VK_LEFT;
		}
		if (ptCircle.y - R <= 0)
		{
			ptCircle.y = R;
			iDirection = VK_DOWN;
		}
		if (ptCircle.y + R >= rtClient.bottom)
		{
			ptCircle.y = rtClient.bottom - R;
			iDirection = VK_UP;
		}

		InvalidateRect(hwnd, nullptr, TRUE);
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