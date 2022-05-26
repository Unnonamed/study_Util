#pragma once //�ҽ� �ڵ� ������ �������� �� �����Ϸ��� ��� ������ �� ���� ���Եǵ��� �����մϴ�.
/* 
* ���� ifdef ����� DLL���� �������� �۾��� �� ����ȭ�ϴ� ��ũ�θ� �����ǥ�� ����Դϴ�.
* �� DLL�� ��� �ִ� ������ ��� ����ٿ� ���ǵ� IMAGEDLL_EXPORTS ��ȣ�� �����ϵ˴ϴ�. 
* �� DLL�� ����ϴ� ������Ʈ������ �� ��ȣ�� ������ �� �����ϴ�.
* �̷��� �ϸ� �ҽ� ���Ͽ� �� ������ ���Ե� �ٸ� ��� ������Ʈ������ IMAGEDLL_API �Լ��� DLL���� �������� ������ ǥ�õǴ� �ݸ�,
* �� DLL������ �� ��ũ�η� ���ǵ� ��ȣ�� ���������� ������ ǥ�õ˴ϴ�. 
*/
#ifdef IMAGEDLL_EXPORTS
#define IMAGEDLL_API __declspec(dllexport)
#else
#define IMAGEDLL_API __declspec(dllimport)
#endif

#include <Windows.h>

class IMAGEDLL_API CExampleA {
public:
	CExampleA(void);
	// TODO: ���⿡ �޼��带 �߰��մϴ�.

};

CExampleA::CExampleA() {
	return;
}
//Ȯ���ʿ�
extern IMAGEDLL_API int nImageDLL;
IMAGEDLL_API int fnImageDLL(void);
//����

/* 
* extern "C" : C++ �ҽ����� ������ ���� ������ �Լ��� C���� ����ؾ� �� ���
*/
extern "C" IMAGEDLL_API VOID printAPI();