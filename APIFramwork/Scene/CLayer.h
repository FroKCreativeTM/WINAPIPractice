#pragma once

#include "../Game.h"

// 두가지 속성을 가진다.
// 1. 태그(id) : 선형 탐색을 한다.
class CLayer
{
private : 
	friend class CScene;

// 씬에서만 생성한다.
private : 
	CLayer();

public : 
	~CLayer();

private : 
	class CScene* m_pScene;	// 레이어 또한 내 씬의 정보를 가지고 있는다.

	string	m_strTag;		// 아이디값 같은 것
	int		m_nZOrder;		// 레이어가 여러 개일 경우 순서가 어떻게 되는가. (Z-buffer같은 게 없으니 이걸 이용한다.)
							// 즉 자동으로 레이어가 정렬되게 만들어야 한다.

public : 
	void SetTag(const string& strTag) {	m_strTag = strTag; }
	void SetZOrder(int nZOrder) { m_nZOrder = nZOrder; }
	int GetZOeder() const { return m_nZOrder; }
	string GetTag() const {	return m_strTag; }
	void SetScene(class CScene* pScene) { m_pScene = pScene; }
	class CScene* GetScene() const { return m_pScene; }
};

