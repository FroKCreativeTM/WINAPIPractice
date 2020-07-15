#include "CScene.h"
#include "CLayer.h"

CScene::CScene()
{
	CLayer* pLayer = CreateLayer("Default");
	pLayer = CreateLayer("UI", INT_MAX);		// UI가 들어갈 때 정렬된다.
}

CScene::~CScene()
{
	// 모든 레이어를 해제한다.
	Safe_Delete_VecList(m_LayerList);
}

bool CScene::Init()
{
	return true;
}

// 레이어를 만들어주는 메소드입니다.
CLayer* CScene::CreateLayer(const string& strTag, int nZOrder)
{
	CLayer* newLayer = new CLayer;

	newLayer->SetTag(strTag); 
	newLayer->SetZOrder(nZOrder);
	newLayer->SetScene(this);

	m_LayerList.push_back(newLayer);

	// 레이어가 자동으로 정렬된다.
	// 이 때 정렬 기준은? 함수 포인터로 넘겨준다.
	if (m_LayerList.size() >= 2)
		m_LayerList.sort(LayerSort);

	return nullptr;
}

bool CScene::LayerSort(CLayer* pLayer1, CLayer* pLayer2)
{
	// =는 주의해야한다.
	// 보통 STL 특성상 버그는 이거에서 터진다.
	return pLayer1->GetZOeder() < pLayer2->GetZOeder();
}
