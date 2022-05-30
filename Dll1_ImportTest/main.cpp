/*
* �Ͻ�����ũ(���μ����� ������ �� dll ������)
* �Ͻ�����ũ���� dll���ϰ� lib������ ��� �ʿ��ϴ�
* dll���� �ʿ����� dll�� �ִ� ��Լ��� ����Ѵٰ� ȣ���� �������ִ� �κ��� �־���Ѵ�.
* (��� ���� .h ���Ϸ� �����ֱ� ����)
* ���α׷� ����� dll ���� �ҷ��� �� ȣ���� �Լ��� �ִ��� �˻��Ѵ�. ������ kill
* 
* �������ũ(���μ��� ���� ���϶� dll ������)
* ������������ ���� dll�� �ҷ����� �𸣴� ��� ���, �������Ͽ� ���� dll������ �ٲ�� ���
* ������ �Լ��� �ʿ��ϴ� (LoadLibrary, GetProcAddress, FreeLibrary)
* 
*/
#include <iostream>
#include <stdio.h>


//�Ͻ�����ũ - 1.������� ����ϱ�(��� ������ �𸦶� ��밡������?)
//#include "../Dll1_ExprotTest/imageDll.h"
//�Ͻ�����ũ - 2.�Լ� ������ֱ�(�ϳ��� �� ����ؾ���)
//extern "C" __declspec(dllimport) double Sum(double a, double b);
//extern __declspec(dllimport) int x;
//extern __declspec(dllimport) int fnExample(void);

//#pragma comment(lib, "../Debug/Dll1_ExprotTest.lib")

//int main() {
//	//ù��° ����
//	std::cout << "x: " << x << std::endl;
//	std::cout << "fnExample: " << fnExample() << std::endl;
//
//	//�ι�° ����
//	std::cout << "Sum: " << Sum(5.0, 1.0) << std::endl;
//}

// -----------------------------------------------------------------------------------------
#include "windows.h"

//1.�������ũ - �Լ�������
//������ (*)�� �ƽôٽ��� NULL�� ��������� ���۷��� (&)�� NULL�� ������ �ʽ��ϴ�.

typedef double(*pFunctionDLL)(double, double);
pFunctionDLL pFunction = NULL;

int main(int argc, char* argv[]) {
	HMODULE hMod = NULL;
	hMod = LoadLibraryA("Dll1_ExprotTest.dll");

	if (hMod == NULL) {
		printf("DLL Load Fail! \n");
		return 0;
	}
	else {
		printf("DLL Find OK! \n");
	}

	pFunction = (pFunctionDLL)GetProcAddress(hMod, "Sum");
	std::cout << "Sum: " << pFunction(5.0, 1.0) << std::endl;
}