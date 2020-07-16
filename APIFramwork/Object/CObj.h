#pragma once

#include "../Game.h"

// ���ӿ� �׷����� ��� �͵��� �̰��� ��ӹ޴´�.
class CObj
{
protected : 
	CObj();
	virtual ~CObj();

protected : 
	int m_nRef;		// ���� Ƚ���� �����մϴ�.

	string m_strTag;
	// ��� ��ü�� ��ġ�� ũ�⸦ ������.
	POSITION m_tPos;
	_SIZE m_tSize;

public : 
	void AddRef()
	{
		++m_nRef;
	}

	int Release()
	{
		--m_nRef;

		if (m_nRef == 0)
		{
			// ���� ���̾ ���ٸ� �ڱ� �ڽ��� �����.
			delete this;
			return 0;
		}

		return m_nRef;
	}

public : 
	virtual bool Init();
	virtual void Input(float fDeltaTime);
	virtual int Update(float fDeltaTime);
	virtual int LateUpdate(float fDeltaTime);
	virtual void Collision(float fDeltaTime);
	virtual void Render(HDC hDC, float fDeltaTime);

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

	

