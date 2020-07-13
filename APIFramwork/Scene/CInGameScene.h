#pragma once

#include "CScene.h"

class CInGameScene : public CScene
{

public : 
	// 씬 매니저를 통해서 생성되는 씬들
	CInGameScene();
	~CInGameScene();

public : 
	virtual bool Init();
};

