#include "CInGameScene.h"
#include "../Object/CPlayer.h"
#include "CLayer.h"

CInGameScene::CInGameScene()
{
}

CInGameScene::~CInGameScene()
{
}

bool CInGameScene::Init()
{
    // 부모 씬 클래스의 초기화 함수를 호출한다.
    if (!CScene::Init())
        return false;

    // 레이어를 찾는다.

    return true;
}
