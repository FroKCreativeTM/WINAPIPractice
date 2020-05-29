#pragma once

// �ζ��� ������ �����غ��̱� �ѵ�...
#define SAFE_DELETE(x) if(x) {delete x; x = nullptr;} 
#define SAFE_DELETE_ARRAY(x)  if(x) {delete[] x; x = nullptr;}

// ������ Ÿ���� �� �� ���� �� �ִ�.
// ��ũ�δ� �� �ٷθ� ���� �� �ִµ� �̴� �ʹ� �����ϴ�.
// ��� \\ �� ����ؼ� �������� ǥ������
// �� �� ����� ������� �����!!!
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