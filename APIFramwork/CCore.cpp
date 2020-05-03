#include "CCore.h"

CCore* CCore::m_Inst = nullptr;
bool CCore::m_loopWindow = true;

CCore::CCore() 
{
}

CCore::~CCore()
{
}

bool CCore::Init(HINSTANCE hInst)
{
	m_hInst = hInst;

	// ������ Ŭ������ �����ϰ� �̸� �������Ϳ� ����Ѵ�.
	myRegisterClass();

    // �ػ� ����
    this->m_windowResolution.width = 1280;
    this->m_windowResolution.height = 720;

    create();

	return true;
}

int CCore::Run()
{
    MSG message;

    // �⺻ �޽��� �����Դϴ�.
    while (this->m_loopWindow)
    {
        // PeekMessage�� �޽����� �޽���ť�� ��� �ٷ� �������´�.
        // �޽����� �ִ� ��쿡�� true, ������ false�� ��ȯ�ϸ�
        // �޽����� ���� �ð��� �������� ���� Ÿ���̴�.
        if (PeekMessage(&message, nullptr, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&message);
            DispatchMessage(&message);
        }
        // ������ ����Ÿ���� ��� (���� ���� �ڵ�� ���⿡ �ۼ��մϴ�.)
        else
        {

        }
    }

    // ����� ���� �޽��� ��ȯ
    return (int)message.wParam;
}

ATOM CCore::myRegisterClass()
{
    WNDCLASSEX wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = CCore::WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = this->m_hInst;
    wcex.hIcon = LoadIcon(this->m_hInst, MAKEINTRESOURCE(IDI_ICON1));
    wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = NULL; // MAKEINTRESOURCE(IDC_MYAPP);
    wcex.lpszClassName = L"200503 WINAPI PRACTICE";
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_ICON1));

    return RegisterClassExW(&wcex);
}

BOOL CCore::create()
{
    // �ν��Ͻ� �ڵ��� �̹� ����Ǿ��ִ�.
    // ��� ������ â�� ��������
    this->m_hWnd = CreateWindowW(L"200503 WINAPI PRACTICE", L"200503 WINAPI PRACTICE",
        WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, this->m_hInst, nullptr);

    if (!this->m_hWnd)
    {
        return FALSE;
    }

    // ���� ������ Ÿ��Ʋ �ٿ� �޴��� ������ �������� ũ�⸦ �����Ѵ�.
    RECT rc = { 0,0,
        this->m_windowResolution.width
        ,this->m_windowResolution.height };

    AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, FALSE);  // �޴��ٴ� �ʿ����.

    // ������ ������ ũ��� ������ Ŭ���̾�Ʈ ������ ũ�⸦ ���ϴ� ũ��� ��������Ѵ�.
    SetWindowPos(this->m_hWnd, HWND_TOPMOST, 100, 100, rc.right-rc.left, 
        rc.bottom - rc.top, SWP_NOMOVE | SWP_NOZORDER);

    // �����츦 ����.
    ShowWindow(this->m_hWnd, SW_SHOW);
    UpdateWindow(this->m_hWnd);

    return TRUE;
}

LRESULT CCore::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_PAINT : 
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);
        // TODO : ���⿡ hdc�� ����ϴ� �׸��� �ڵ带 �߰��մϴ�.
        // ����̽� ���ؽ�Ʈ�� �̿��ؼ� �����쿡 �׸��� ����
        EndPaint(hWnd, &ps);
    }
    break;

    // �����츦 ���� ��ų �� ������ �޽����Դϴ�.
    case WM_DESTROY : 
        m_loopWindow = false;       // ������ ������ ������.
        PostQuitMessage(0);
        break;

    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }

    return 0;
}
