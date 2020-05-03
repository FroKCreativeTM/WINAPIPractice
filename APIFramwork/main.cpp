#include "CCore.h"

int WINAPI wWinMain(_In_ HINSTANCE hPrevInstance,
	_In_opt_ HINSTANCE hInstance,
	_In_ LPWSTR lpCmdLine,
	_In_ int nCmdShow)
{
	if (!CCore::GetInst()->Init(hInstance))
	{
		CCore::DestroyInst();
		return 0;
	}

	int returnValue = CCore::GetInst()->Run();

	CCore::DestroyInst();

	return returnValue;
}