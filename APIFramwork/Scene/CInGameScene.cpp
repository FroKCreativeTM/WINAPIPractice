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
    // �θ� �� Ŭ������ �ʱ�ȭ �Լ��� ȣ���Ѵ�.
    if (!CScene::Init())
        return false;

    // ���̾ ã�´�.

    return true;
}
