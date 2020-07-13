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