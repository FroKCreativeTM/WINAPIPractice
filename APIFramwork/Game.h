#pragma once

#include <Windows.h>
#include <list>
#include <vector>
#include <unordered_map>

using namespace std;

#include "Macro.h"
#include "resource.h"
#include "Flag.h"
#include "Types.h"

// 인자가 들어오면 바꿔줘야 하기 때문에 레퍼런스 타입으로 받는다.
template <typename T>
void Safe_Delete_VecList(T& p)
{
	typename T::iterator iter;
	typename T::iterator iterEnd = p.end();

	for (iter = p.begin(); iter != iterEnd; ++iter)
	{
		SAFE_DELETE((*iter));
	}

	p.clear();
}

template <typename T>
void Safe_Release_VecList(T& p)
{
	typename T::iterator iter;
	typename T::iterator iterEnd = p.end();

	for (iter = p.begin(); iter != iterEnd; ++iter)
	{
		SAFE_RELEASE((*iter));
	}

	p.clear();
}