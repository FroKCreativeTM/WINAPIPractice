#pragma once

#include "../Game.h"

// �ΰ��� �Ӽ��� ������.
// 1. �±�(id) : ���� Ž���� �Ѵ�.
class CLayer
{
private : 
	friend class CScene;

// �������� �����Ѵ�.
private : 
	CLayer();

public : 
	~CLayer();

private : 
	class CScene* m_pScene;			// ���̾� ���� �� ���� ������ ������ �ִ´�.

	string	m_strTag;				// ���̵� ���� ��
	int		m_nZOrder;				// ���̾ ���� ���� ��� ������ ��� �Ǵ°�. (Z-buffer���� �� ������ �̰� �̿��Ѵ�.)
									// �� �ڵ����� ���̾ ���ĵǰ� ������ �Ѵ�.
	list<class CObj*> m_ObjList;	//  

public : 
	void SetTag(const string& strTag) {	m_strTag = strTag; }
	void SetZOrder(int nZOrder) { m_nZOrder = nZOrder; }
	void SetScene(class CScene* pScene) { m_pScene = pScene; }
	string GetTag() const {	return m_strTag; }
	int GetZOeder() const { return m_nZOrder; }
	class CScene* GetScene() const { return m_pScene; }

public : 
	void AddObject(class CObj* pObj);

public : 
	void Input(float fDeltaTime);
	int Update(float fDeltaTime);
	int LateUpdate(float fDeltaTime);
	void Collision(float fDeltaTime);
	void Render(HDC hDC, float fDeltaTime);
};

