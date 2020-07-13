#pragma once

#include "../Game.h"

// 매인 프래임이 여러개의 서브 시스템을 관리하는 방식이다.
class CSceneManager
{
private : 
	class CScene* m_pScene;
	class CScene* m_pNextScene;

public : 
	// 이 객체를 초기화하는 멤버 메소드
	bool Init();

public : 
	template <typename T>
	T* CreateScene(SCENE_CREATE sc)
	{
		T* pScene = new T;

		if (!pScene->Init())
		{
			SAFE_DELETE(pScene);
			return NULL;
		}
		switch (sc)
		{
		case SC_CURRENT:
			SAFE_DELETE(m_pScene);
			m_pScene = pScene;
			break;
		case SC_NEXT:
			SAFE_DELETE(m_pNextScene);
			m_pNextScene = pScene;
			break;
		}

		return pScene;
	}

// 싱글톤 코드 및 private 처리하여 복사가 되지 않게 만든 생성자 및 소멸자
	DECLARE_SINGLE(CSceneManager)
};