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

void CScene::Input(float fDeltaTime)
{
	// 반복을 돌려야 모든 레이어를 처리할 수 있다.
	list<CLayer*>::iterator iter;
	list<CLayer*>::iterator iterEnd = m_LayerList.end();
	
	for (iter = m_LayerList.begin(); iter != iterEnd; ++iter)
	{
		(*iter)->Input(fDeltaTime);
	}
}

int CScene::Update(float fDeltaTime)
{
	// 반복을 돌려야 모든 레이어를 처리할 수 있다.
	list<CLayer*>::iterator iter;
	list<CLayer*>::iterator iterEnd = m_LayerList.end();

	for (iter = m_LayerList.begin(); iter != iterEnd; ++iter)
	{
		(*iter)->Update(fDeltaTime);
	}
	return 0;
}

int CScene::LateUpdate(float fDeltaTime)
{
	// 반복을 돌려야 모든 레이어를 처리할 수 있다.
	list<CLayer*>::iterator iter;
	list<CLayer*>::iterator iterEnd = m_LayerList.end();

	for (iter = m_LayerList.begin(); iter != iterEnd; ++iter)
	{
		(*iter)->LateUpdate(fDeltaTime);
	}
	return 0;
}

void CScene::Collision(float fDeltaTime)
{
	// 반복을 돌려야 모든 레이어를 처리할 수 있다.
	list<CLayer*>::iterator iter;
	list<CLayer*>::iterator iterEnd = m_LayerList.end();

	for (iter = m_LayerList.begin(); iter != iterEnd; ++iter)
	{
		(*iter)->Collision(fDeltaTime);
	}
}

void CScene::Render(HDC hDC, float fDeltaTime)
{
	// 반복을 돌려야 모든 레이어를 처리할 수 있다.
	list<CLayer*>::iterator iter;
	list<CLayer*>::iterator iterEnd = m_LayerList.end();

	for (iter = m_LayerList.begin(); iter != iterEnd; ++iter)
	{
		(*iter)->Render(hDC, fDeltaTime);
	}
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

CLayer* CScene::FindLayer(const string& strTag)
{
	// 반복을 돌려야 모든 레이어를 처리할 수 있다.
	list<CLayer*>::iterator iter;
	list<CLayer*>::iterator iterEnd = m_LayerList.end();

	for (iter = m_LayerList.begin(); iter != iterEnd; ++iter)
	{
		if ((*iter)->GetTag() == strTag)
		{
			return *iter;
		}
	}
	return nullptr;
}

bool CScene::LayerSort(CLayer* pLayer1, CLayer* pLayer2)
{
	// =는 주의해야한다.
	// 보통 STL 특성상 버그는 이거에서 터진다.
	return pLayer1->GetZOeder() < pLayer2->GetZOeder();
}
