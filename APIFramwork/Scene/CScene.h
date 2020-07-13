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

// �ܺ��� ħ���� ���´�.
protected : 
	CScene();
	virtual ~CScene() = 0;		// �߻� Ŭ����

public : 
	// �ʱ�ȭ �Լ�
	virtual bool Init();
};

