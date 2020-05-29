#pragma once

// 인라인 구현이 가능해보이긴 한데...
#define SAFE_DELETE(x) if(x) {delete x; x = nullptr;} 
#define SAFE_DELETE_ARRAY(x)  if(x) {delete[] x; x = nullptr;}

// 변수나 타입이 둘 다 들어올 수 있다.
// 매크로는 한 줄로만 만들 수 있는데 이는 너무 불편하다.
// 고로 \\ 를 사용해서 여러줄을 표현하자
// 단 이 방식은 디버깅이 힘들다!!!
#define DECLARE_SINGLE(Type) \
	private :\
		static Type* m_Inst;\
	public :\
		static Type* GetInst()\
		{\
			if(!m_Inst)\
				m_Inst = new Type;\
			return m_Inst;\
		}\
		static void DestroyInst()\
		{\
			SAFE_DELETE(m_Inst);\
		}\
\
	private :\
		Type();\
		~Type();\

#define DEFINITION_SINGLE(Type) Type * Type::m_Inst = nullptr;
#define GET_SINGLE(Type) Type::GetInst()
#define DESTROY_SINGLE(Type) Type::DestroyInst()