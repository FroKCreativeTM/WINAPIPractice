#include <Windows.h>

const int MAX_LOADSTRING = 100;

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
	// static HFONT hFont;
	// static HPEN hPen;
	// static HBRUSH hBrush;
	// static HBRUSH hBrush[3];
	// static HBRUSH hBrush2;
	// static HRGN hRgn[3];
	// static POINT pts[3] = { {200,200},{200,300},{300,300} };
	// RECT rt = { 50,50,200,200 };
	static HBRUSH hRedBrush, hBlueBrush;

	switch (message)
	{
	case WM_CREATE : 
	{
		// hFont = CreateFont(100, 0, 0, 0, FW_NORMAL, 0, 0, 0, HANGEUL_CHARSET, 0, 0, 0, 0, L"����");
		// hPen = CreatePen(PS_DASH, 1, RGB(0, 0, 255));
		// hBrush = CreateSolidBrush(RGB(0, 0, 255));
		// hBrush2 = CreateHatchBrush(HS_BDIAGONAL, RGB(0, 0, 255));

		// hBrush[0] = CreateSolidBrush(RGB(255, 0, 0));
		// hBrush[1] = CreateSolidBrush(RGB(0, 0, 255));
		// hBrush[2] = CreateSolidBrush(RGB(0, 255, 0));
		// 
		// hRgn[0] = CreateRectRgnIndirect(&rt);
		// hRgn[1] = CreateEllipticRgnIndirect(&rt);
		// hRgn[2] = CreatePolygonRgn(pts, 3, ALTERNATE);

		hRedBrush = CreateSolidBrush(RGB(255, 0, 0));
		hBlueBrush = CreateSolidBrush(RGB(0, 0, 255));
	} 
		break;
	case WM_PAINT :
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hwnd, &ps);
		// TODO : ���⿡ hdc�� ����ϴ� �׸��� �ڵ带 �߰��մϴ�.
		// �ణ ���̷�ƮX9.0�̳� glut�� ������ ����. ������ �̷��� �� ���ϴ�.
		{
			/* TEXT Part */
			// SetTextColor(hdc, RGB(255, 0, 0));	// ���� �����
			// SetBkColor(hdc, RGB(0, 0, 255));	// ���� ����
			// TextOut(hdc, 100, 100, L"Test", wcslen(L"Test"));
			// 
			// SetTextAlign(hdc, TA_BOTTOM | TA_RIGHT);	// ���� ���� ��ġ
			// TextOut(hdc, 100, 100, L"�ȳ�", wcslen(L"�ȳ�"));

			// RECT rt;
			// GetClientRect(hwnd, &rt);
			// DrawText(hdc, L"Test", -1, &rt, DT_CENTER);
			// DrawText(hdc, L"�ȳ�", -1, &rt, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

			/* Point */
			// for (size_t y = 0; y <= 200; y++)
			// {
			// 	for (size_t x = 0; x <= 400; x++)
			// 	{
			// 		SetPixel(hdc, x, y, RGB(0, 0, 255));
			// 	}
			// }

			/* line */
			// MoveToEx(hdc, 200, 200, nullptr);
			// LineTo(hdc, 200, 400);
			// LineTo(hdc, 400, 400);
			// LineTo(hdc, 400, 200);
			// LineTo(hdc, 200, 200);

			/* rectangle, ellipse */
			//Rectangle(hdc, 100, 100, 200, 200);
			//Ellipse(hdc, 100, 100, 200, 200);
			//
			//// Ÿ���� �� �׷��� (�簢���� ������)
			//Ellipse(hdc, 200, 200, 400, 400);
			//Rectangle(hdc, 200, 200, 400, 400);

			/* �׸��� �Ӽ� ���� */
			//HFONT hOldFont = (HFONT)SelectObject(hdc, hFont);
			//TextOut(hdc, 100, 200, L"Test", wcslen(L"Test"));
			//
			//SelectObject(hdc, hOldFont);
			//TextOut(hdc, 100, 100, L"�ȳ�", wcslen(L"�ȳ�"));

			/* �� ���� */
			// MoveToEx(hdc, 100, 100, nullptr);
			// HPEN hOldPen = (HPEN)SelectObject(hdc, hPen);
			// LineTo(hdc, 100, 200);
			// LineTo(hdc, 200, 200);
			// 
			// SelectObject(hdc, hOldPen);
			// LineTo(hdc, 200, 100);
			// LineTo(hdc, 100, 100);

			/* �귯�� ���� */
			// #1
			// HBRUSH hOldBrush = (HBRUSH)SelectObject(hdc, hBrush);
			// Rectangle(hdc, 50, 50, 400, 400);
			// SelectObject(hdc, hOldBrush);
			// 
			// // #2
			// HPEN hOldPen = (HPEN)SelectObject(hdc, GetStockObject(NULL_PEN));
			// Rectangle(hdc, 100, 100, 200, 200);
			// SelectObject(hdc, hOldPen);
			// 
			// // #3
			// hOldBrush = (HBRUSH)SelectObject(hdc, GetStockObject(NULL_BRUSH));
			// Rectangle(hdc, 250, 100, 350, 200);
			// SelectObject(hdc, hOldBrush);
			// 
			// // #4
			// hOldBrush = (HBRUSH)SelectObject(hdc, hBrush2);
			// Rectangle(hdc, 100, 250, 200, 350);
			// SelectObject(hdc, hOldBrush);

			/* DC ���� �� ���� ������Ʈ �������� */
			// SetDCPenColor(hdc, RGB(255, 0, 0));
			// SetDCBrushColor(hdc, RGB(0, 0, 255));
			// 
			// HPEN hOldPen = (HPEN)SelectObject(hdc, (HPEN)GetStockObject(DC_PEN));
			// HBRUSH hOldBrush = (HBRUSH)SelectObject(hdc, (HBRUSH)GetStockObject(DC_BRUSH));
			// Rectangle(hdc, rt.top, rt.top, rt.right, rt.bottom);
			// 
			// SelectObject(hdc, hOldPen);
			// SelectObject(hdc, hOldBrush);
			// 
			// SetRect(&rt, 200, 200, 300, 300);
			// FillRect(hdc, &rt, (HBRUSH)GetStockObject(DC_BRUSH));

			/* ���� - ���� �ΰ� �ٰ����� �׸� �� ����ϱ⵵ �Ѵ�. */
			// for (size_t i = 0; i < 3; i++)
			// {
			// 	FillRgn(hdc, hRgn[i], hBrush[i]);
			// }

			/* �����Ͷ����� */
			
			// #1
			HPEN hOldPen = (HPEN)SelectObject(hdc, GetStockObject(NULL_PEN));
			HBRUSH hOldBrush = (HBRUSH)SelectObject(hdc, hRedBrush);
			Rectangle(hdc, 50, 50, 200, 200);
			SelectObject(hdc, hOldBrush);

			// #2
			SetROP2(hdc, R2_NOTXORPEN);
			hOldBrush = (HBRUSH)SelectObject(hdc, hBlueBrush);
			Rectangle(hdc, 150, 150, 300, 300);
			SelectObject(hdc, hOldBrush);
		}
		EndPaint(hwnd, &ps);
	}
		break;
	case WM_DESTROY:
	{
		// DeleteObject(hFont);
		// DeleteObject(hPen);
		// DeleteObject(hBrush);
		// DeleteObject(hBrush2);
		// for (size_t i = 0; i < 3; i++)
		// {
		// 	DeleteObject(hBrush[i]);
		// 	DeleteObject(hRgn[i]);
		// }

		DeleteObject(hRedBrush);
		DeleteObject(hBlueBrush);

		PostQuitMessage(0);
	}
	break;
	default :
		return DefWindowProc(hwnd, message, wParam, lParam);
	}
	return 0;
}