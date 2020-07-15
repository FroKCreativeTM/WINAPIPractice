#include "CScene.h"
#include "CLayer.h"

CScene::CScene()
{
	CLayer* pLayer = CreateLayer("Default");
	pLayer = CreateLayer("UI", INT_MAX);		// UI�� �� �� ���ĵȴ�.
}

CScene::~CScene()
{
	// ��� ���̾ �����Ѵ�.
	Safe_Delete_VecList(m_LayerList);
}

bool CScene::Init()
{
	return true;
}

// ���̾ ������ִ� �޼ҵ��Դϴ�.
CLayer* CScene::CreateLayer(const string& strTag, int nZOrder)
{
	CLayer* newLayer = new CLayer;

	newLayer->SetTag(strTag); 
	newLayer->SetZOrder(nZOrder);
	newLayer->SetScene(this);

	m_LayerList.push_back(newLayer);

	// ���̾ �ڵ����� ���ĵȴ�.
	// �� �� ���� ������? �Լ� �����ͷ� �Ѱ��ش�.
	if (m_LayerList.size() >= 2)
		m_LayerList.sort(LayerSort);

	return nullptr;
}

bool CScene::LayerSort(CLayer* pLayer1, CLayer* pLayer2)
{
	// =�� �����ؾ��Ѵ�.
	// ���� STL Ư���� ���״� �̰ſ��� ������.
	return pLayer1->GetZOeder() < pLayer2->GetZOeder();
}
