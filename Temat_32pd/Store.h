#include "Date.h"
#include "MyString.h"

struct Store
{
	int storage;			// �	����� ������ 
	int commodity;		  //  �	��� ������ 
	MyString namecom;		  //   �	������������ ������ 
	Date arrive;		 //	   �	���� ����������� �� �����
	int bestbefore;		 //	   �	���� �������� � ���� 
	int numberofunits;	//		�	���������� ������ ������ 
	float priceforone;		//	�	���� �� ���� ������� ������ 

	void fillStore();	// ���������� 
	void showStore();

};

void showAllStore(Store* arr, int size);	//2.	����� ���� �������
void showCurrentObj(Store* arr, int size, int obj);	// ����� ������ ������� � ��������� ������
float totalCost(Store* arr, int size, int N); // ��������� ��������� ������� �� ������ �� ��� ������.
void findOverdue(Store* arr, int size);	//����� ���� �������, � ������� �� ������� ���� ����� ���� ��������
void addObj(Store*& arr, int& size);		// 3.	���������� ������ ������
void deleteObj(Store*& arr, int& size, char* itemName);	//4.	�������� ������ �� ������
