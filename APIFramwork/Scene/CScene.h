#pragma once

#include "../Game.h"

// 다형성으로 할당한다면 부모 타입의 포인터에 자식을 할당하여 사용
// 결국 소멸할 땐 부모의 소멸자를 사용하기에 자식 클래스의 소멸자가 불러오지 않음
// 그렇기에 이러한 현상을 막기 위해 virtual을 붙여준다.

// 인터페이스화 된 클래스
class CScene
{
// 이 씬을 상속받는 클래스는 CSceneManager에 의해 관리된다.
protected:
	friend class CSceneManager;

// 외부의 침입을 막는다.
protected : 
	CScene();
	virtual ~CScene() = 0;		// 추상 클래스

public : 
	// 초기화 함수
	virtual bool Init();
};

