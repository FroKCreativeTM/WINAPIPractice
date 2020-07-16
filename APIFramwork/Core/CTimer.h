#pragma once

#include "../Game.h"

class CTimer
{
private : 
	LARGE_INTEGER m_tSecond;
	LARGE_INTEGER m_tTime;
	float m_fDeltaTime;
	float m_fTimeScale;
	float m_fFPS;
	float m_fFPSTime;
	int m_nFrameMax;
	int m_nFrame;

public :
	DECLARE_SINGLE(CTimer)

public : 
	float GetDeltaTime() const { return m_fDeltaTime * m_fTimeScale; }
	float GetFPS() const { return m_fFPS; }
	float GetTimeScale() const { return m_fTimeScale; }

public : 
	void SetTimeScale(float fTimeScale)
	{
		m_fTimeScale = fTimeScale;
	}

public : 
	bool Init();
	void Update();
};

