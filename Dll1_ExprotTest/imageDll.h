#pragma once //�ҽ� �ڵ� ������ �������� �� �����Ϸ��� ��� ������ �� ���� ���Եǵ��� �����մϴ�.
/*
* ���� ifdef ����� DLL���� �������� �۾��� �� ����ȭ�ϴ� ��ũ�θ� �����ǥ�� ����Դϴ�.
* �� DLL�� ��� �ִ� ������ ��� ����ٿ� ���ǵ� *������(IMAGEDLL_EXPORTS -> DLL1EXPROTTEST_EXPORTS)��ȣ�� �����ϵ˴ϴ�.
* �� DLL�� ����ϴ� ������Ʈ������ �� ��ȣ�� ������ �� �����ϴ�.
* �̷��� �ϸ� �ҽ� ���Ͽ� �� ������ ���Ե� �ٸ� ��� ������Ʈ������ *������(IMAGEDLL_API -> DLLTEST_API) �Լ��� DLL���� �������� ������ ǥ�õǴ� �ݸ�,
* �� DLL������ �� ��ũ�η� ���ǵ� ��ȣ�� ���������� ������ ǥ�õ˴ϴ�.
* [������Ʈ]-[�Ӽ�]-[C/C++]-[��ó����] ���� DLL1EXPROTTEST_EXPORTS Ȯ��
*/
#ifdef DLL1EXPROTTEST_EXPORTS
#define DLLTEST_API __declspec(dllexport)
#else
#define DLLTEST_API __declspec(dllimport)
#endif

#include <Windows.h>

//ù��° ����
class DLLTEST_API CExampleA {
public:
	CExampleA(void);
	// TODO: ���⿡ �޼��带 �߰��մϴ�.
};
extern DLLTEST_API int x;
DLLTEST_API int fnExample(void);

/*
* extern "C" : C++ �ҽ����� ������ ���� ������ �Լ��� C���� ����ؾ� �� ���
*/
//�ι�° ����
extern "C" DLLTEST_API double Sum(double a, double b);
extern "C" DLLTEST_API double Sub(double a, double b);
extern "C" DLLTEST_API double Mul(double a, double b);
extern "C" DLLTEST_API double Div(double a, double b);
