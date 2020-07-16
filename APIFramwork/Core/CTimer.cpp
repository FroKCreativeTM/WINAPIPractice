#include "CTimer.h"

DEFINITION_SINGLE(CTimer)

CTimer::CTimer()
{

}

CTimer::~CTimer()
{

}

bool CTimer::Init()
{
	QueryPerformanceFrequency(&m_tSecond);
	QueryPerformanceCounter(&m_tTime);

	m_fDeltaTime = 0.f;
	m_fFPS = 0.f;
	m_fFPSTime = 0.f;
	m_nFrameMax = 60;
	m_nFrame = 0;

	return false;
}

void CTimer::Update()
{
	LARGE_INTEGER tTime;
	QueryPerformanceCounter(&tTime);

	m_fDeltaTime = (tTime.QuadPart - m_tTime.QuadPart) / (float)m_tSecond.QuadPart;
}

void Update()
{
}
