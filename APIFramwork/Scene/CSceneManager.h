#pragma once

#include "../Game.h"

// 매인 프래임이 여러개의 서브 시스템을 관리하는 방식이다.
class CSceneManager
{
// 싱글톤 코드 및 private 처리하여 복사가 되지 않게 만든 생성자 및 소멸자
DECLARE_SINGLE(CSceneManager)

public : 
	// 이 객체를 초기화하는 멤버 메소드
	bool Init();
};