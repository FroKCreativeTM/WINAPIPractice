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
	static POINT ptCircle = { 100,100 };
	switch (message)
	{
	case WM_KEYDOWN : 
	{
		switch (wParam)
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
		case VK_ESCAPE : 
		{
			if (MessageBox(hwnd, L"����", L"msg", MB_OKCANCEL | MB_ICONQUESTION) == IDOK)
			{
				DestroyWindow(hwnd);
			}
		}
			break;
		default:
			break;
		}
	}
	InvalidateRect(hwnd, nullptr, TRUE);
		break;
	case WM_DESTROY: 
	{
		PostQuitMessage(0);
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
	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
	}
	return 0;
}