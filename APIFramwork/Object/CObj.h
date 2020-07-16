#pragma once

#include "../CRef.h"

// ���ӿ� �׷����� ��� �͵��� �̰��� ��ӹ޴´�.
class CObj : public CRef
{
protected : 
	CObj();
	CObj(const CObj& obj);
	virtual ~CObj();

protected : 
	class CScene* m_pScene;
	class CLayer* m_pLayer;

public : 
	void SetScene(class CScene* pScene)
	{
		m_pScene = pScene;
	}
	void SetLayer(class CLayer* pLayer)
	{
		m_pLayer = pLayer;
	}

	class CScene* GetScene() const
	{
		return m_pScene;
	}
	class CLayer* GetLayer() const
	{
		return m_pLayer;
	}

protected : 
	string m_strTag;
	// ��� ��ü�� ��ġ�� ũ�⸦ ������.
	POSITION m_tPos;
	_SIZE m_tSize;
	POSITION m_tPivot;

public : 
	virtual bool Init() = 0;
	virtual void Input(float fDeltaTime);
	virtual int Update(float fDeltaTime);
	virtual int LateUpdate(float fDeltaTime);
	virtual void Collision(float fDeltaTime);
	virtual void Render(HDC hDC, float fDeltaTime);

public : 
	// Ŭ���� ������ �پ����� ���̴�. �̿� �����ϱ� ���ؼ� ���ø� ���
	// null�� ��� ���̾ ���� ������ ������Ʈ�� �߰����� �ʰ�
	// null�� �ƴ� ��� �߰�
	template <typename T>
	static T* CreateObj(const string& strTag, class CLayer* pLayer = nullptr)
	{
		T* pObj = new T;

		if (!pObj->Init())
		{
			SAFE_RELEASE(pObj);
			return nullptr;
		}

		// ���̾ �ִٸ�
		if (pLayer)
		{
			pLayer->AddObject(pObj);
		}

		pObj->AddRef();
		return pObj;
	}

public : 
	/* setter */
	void SetTag(const string& str)
	{
		m_strTag = str;
	}

	// ��ġ
	void SetPos(const POSITION& pos)
	{
		m_tPos = pos;
	}

	void SetPos(float x, float y)
	{
		m_tPos.x = x;
		m_tPos.y = y;
	}

	void SetPos(const POINT& pt)
	{
		m_tPos = pt;
	}

	// ������
	void SetSize(const _SIZE& pos)
	{
		m_tSize = pos;
	}

	void SetSize(float x, float y)
	{
		m_tSize.x = x;
		m_tSize.y = y;
	}

	void SetSize(const POINT& pt)
	{
		m_tSize = pt;
	}

public : 
	/* getter */
	string GetTag() const
	{
		return m_strTag;
	}

	POSITION GetPosition() const
	{
		return m_tPos;
	}

	_SIZE GetSize() const
	{
		return m_tSize;
	}
};

	

