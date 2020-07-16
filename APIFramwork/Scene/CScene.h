#pragma once

#include "../Game.h"

// ���������� �Ҵ��Ѵٸ� �θ� Ÿ���� �����Ϳ� �ڽ��� �Ҵ��Ͽ� ���
// �ᱹ �Ҹ��� �� �θ��� �Ҹ��ڸ� ����ϱ⿡ �ڽ� Ŭ������ �Ҹ��ڰ� �ҷ����� ����
// �׷��⿡ �̷��� ������ ���� ���� virtual�� �ٿ��ش�.

// �������̽�ȭ �� Ŭ����
class CScene
{
// �� ���� ��ӹ޴� Ŭ������ CSceneManager�� ���� �����ȴ�.
protected:
	friend class CSceneManager;

protected:
	// ��� ���� ���̾ ������.
	list<class CLayer*> m_LayerList;

// �ܺ��� ħ���� ���´�.
protected : 
	CScene();
	virtual ~CScene() = 0;		// �߻� Ŭ����

public : 
	// �ʱ�ȭ �Լ�
	virtual bool Init();
	virtual void Input(float fDeltaTime);
	virtual int Update(float fDeltaTime);
	virtual int LateUpdate(float fDeltaTime);
	virtual void Collision(float fDeltaTime);
	virtual void Render(HDC hDC, float fDeltaTime);		// �׸��� ���ؼ��� ����̽� ���ؽ�Ʈ�� �ٷ� �ʿ䰡 �ִ�.

	// �ڽ��� ��� �� ����� ��� �޴´�.
	class CLayer* CreateLayer(const string& strTag,
		int nZOrder = 0);

	static bool LayerSort(class CLayer* pLayer1, class CLayer* pLayer2);
};

