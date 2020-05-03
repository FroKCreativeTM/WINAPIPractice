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

	// 윈도우 클래스를 제작하고 이를 레지스터에 등록한다.
	myRegisterClass();

    // 해상도 설정
    this->m_windowResolution.width = 1280;
    this->m_windowResolution.height = 720;

    create();

	return true;
}

int CCore::Run()
{
    MSG message;

    // 기본 메시지 루프입니다.
    while (this->m_loopWindow)
    {
        // PeekMessage는 메시지가 메시지큐에 없어도 바로 빠져나온다.
        // 메시지가 있는 경우에는 true, 없으면 false를 반환하며
        // 메시지가 없는 시간이 윈도우의 데드 타임이다.
        if (PeekMessage(&message, nullptr, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&message);
            DispatchMessage(&message);
        }
        // 윈도우 데드타임인 경우 (실제 게임 코드는 여기에 작성합니다.)
        else
        {

        }
    }

    // 종료시 종료 메시지 반환
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
    // 인스턴스 핸들은 이미 저장되어있다.
    // 고로 윈도우 창을 생성하자
    this->m_hWnd = CreateWindowW(L"200503 WINAPI PRACTICE", L"200503 WINAPI PRACTICE",
        WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, this->m_hInst, nullptr);

    if (!this->m_hWnd)
    {
        return FALSE;
    }

    // 실제 윈도우 타이틀 바와 메뉴를 포함한 윈도우의 크기를 저장한다.
    RECT rc = { 0,0,
        this->m_windowResolution.width
        ,this->m_windowResolution.height };

    AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, FALSE);  // 메뉴바는 필요없다.

    // 위에서 구해준 크기로 윈도우 클라이언트 영역의 크기를 원하는 크기로 맞춰줘야한다.
    SetWindowPos(this->m_hWnd, HWND_TOPMOST, 100, 100, rc.right-rc.left, 
        rc.bottom - rc.top, SWP_NOMOVE | SWP_NOZORDER);

    // 윈도우를 띄운다.
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
        // TODO : 여기에 hdc를 사용하는 그리기 코드를 추가합니다.
        // 디바이스 컨텍스트를 이용해서 윈도우에 그리는 공간
        EndPaint(hWnd, &ps);
    }
    break;

    // 윈도우를 종료 시킬 때 들어오는 메시지입니다.
    case WM_DESTROY : 
        m_loopWindow = false;       // 윈도우 루프가 끝난다.
        PostQuitMessage(0);
        break;

    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }

    return 0;
}
