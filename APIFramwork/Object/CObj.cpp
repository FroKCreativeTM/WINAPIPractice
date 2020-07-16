#include "CObj.h"

CObj::CObj() 
{
}

CObj::CObj(const CObj& obj)
{
	*this = obj;
}

CObj::~CObj()
{
}

void CObj::Input(float fDeltaTime)
{
}

int CObj::Update(float fDeltaTime)
{
	return 0;
}

int CObj::LateUpdate(float fDeltaTime)
{
	return 0;
}

void CObj::Collision(float fDeltaTime)
{
}

void CObj::Render(HDC hDC, float fDeltaTime)
{
}
