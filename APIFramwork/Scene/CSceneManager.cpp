#include "CSceneManager.h"
#include "CInGameScene.h"

// �� �̱��� ��ü�� �ν��Ͻ��Դϴ�.
// �ϳ��� ������ �����մϴ�.
DEFINITION_SINGLE(CSceneManager);

CSceneManager::CSceneManager()
	: m_pScene(nullptr), m_pNextScene(nullptr)	
{

}

CSceneManager::~CSceneManager()
{
	SAFE_DELETE(m_pScene);
}

bool CSceneManager::Init()
{
	// �⺻ ����� �����.
	CreateScene<CInGameScene>(SC_CURRENT);

	return true;
}