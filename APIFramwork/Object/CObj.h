#pragma once

#include "../CRef.h"

// 게임에 그려지는 모든 것들은 이것을 상속받는다.
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
	// 모든 물체는 위치와 크기를 가진다.
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
	// 클래스 종류가 다양해질 것이다. 이에 대응하기 위해서 템플릿 사용
	// null인 경우 레이어에 지금 생성한 오브젝트를 추가하지 않고
	// null이 아닌 경우 추가
	template <typename T>
	static T* CreateObj(const string& strTag, class CLayer* pLayer = nullptr)
	{
		T* pObj = new T;

		if (!pObj->Init())
		{
			SAFE_RELEASE(pObj);
			return nullptr;
		}

		// 레이어가 있다면
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

	// 위치
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

	// 사이즈
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

	

