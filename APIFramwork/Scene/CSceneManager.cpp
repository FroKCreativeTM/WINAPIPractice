#include "CSceneManager.h"
#include "CInGameScene.h"

// 이 싱글톤 객체의 인스턴스입니다.
// 하나만 생성이 가능합니다.
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
	// 기본 장면을 만든다.
	CreateScene<CInGameScene>(SC_CURRENT);

	return true;
}

void CSceneManager::Input(float fDeltaTime)
{
	m_pScene->Input(fDeltaTime);
}

int CSceneManager::Update(float fDeltaTime)
{
	m_pScene->Update(fDeltaTime);
	return 0;
}

int CSceneManager::LateUpdate(float fDeltaTime)
{
	m_pScene->LateUpdate(fDeltaTime);
	return 0;
}

void CSceneManager::Collision(float fDeltaTime)
{
	m_pScene->Collision(fDeltaTime);
}

void CSceneManager::Render(HDC hDC, float fDeltaTime)
{
	m_pScene->Render(hDC, fDeltaTime);
}
