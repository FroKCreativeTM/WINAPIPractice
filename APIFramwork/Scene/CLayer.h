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
	class CScene* m_pScene;	// ���̾� ���� �� ���� ������ ������ �ִ´�.

	string	m_strTag;		// ���̵� ���� ��
	int		m_nZOrder;		// ���̾ ���� ���� ��� ������ ��� �Ǵ°�. (Z-buffer���� �� ������ �̰� �̿��Ѵ�.)
							// �� �ڵ����� ���̾ ���ĵǰ� ������ �Ѵ�.

public : 
	void SetTag(const string& strTag) {	m_strTag = strTag; }
	void SetZOrder(int nZOrder) { m_nZOrder = nZOrder; }
	int GetZOeder() const { return m_nZOrder; }
	string GetTag() const {	return m_strTag; }
	void SetScene(class CScene* pScene) { m_pScene = pScene; }
	class CScene* GetScene() const { return m_pScene; }
};

