//#ifdef ��ó���� Ư���� �̿�. ���� �������� ����Ǳ����� ����
//#endif

#include "pch.h"
#include "framework.h"
#include "ImageDLL.h"

#include <iostream>
#include <chrono> //�ð����� ���̺귯��


//ù��° ����
// ������ ������ �����Դϴ�.
DLLTEST_API int x = 0;

// ������ �Լ��� �����Դϴ�.
DLLTEST_API int fnExample(void)
{
    return 1;
}
// ������ Ŭ������ �������Դϴ�.
CExampleA::CExampleA()
{
    return;
}

//�ι�° ����
double Sum(double a, double b) {
	return a + b;
}

double Sub(double a, double b) {
	return a - b;
}

double Mul(double a, double b) {
	return a * b;
}

double Div(double a, double b) {
	return a / b;
}
