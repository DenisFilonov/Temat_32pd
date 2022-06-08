#include "Store.h"
#include <windows.h>
using namespace std;


int main()
{
	setlocale(0, "");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	int sizeStore = 0; // ���-�� ������ => ����������� �������
	Store* arr = NULL; // ��������� �� ������������ ������
	int menu = 0;
	int point = 0;
	int numstore = 0;

	do
	{
	cout	<< "1. �������� ����� �����.\n"
			<< "2. �������� ������ ���� �������.\n"
			<< "3. �������� ������ ������������ �������.\n"
			<< "4. ������� �����.\n"
			<< "5. ����� ������ ������� � ��������� ������.\n"
			<< "6. ��������� ��������� ������� �� ������ �� ��� ������.\n"
			<< "0. ����� �� ����.\n"
			<< "�����: ";
		cin >> menu;

		switch (menu)
		{
		case 1:
			cin.ignore();
			addObj(arr, sizeStore); break;

		case 2:
			showAllStore(arr, sizeStore); break;

		case 3:
			findOverdue(arr, sizeStore); break;

		case 4:
			char s[100];
			cout << "������� �������� ������ ��� ��������:\n";
			cin.ignore();
			cin.get(s, 100);
			deleteObj(arr, sizeStore, s); break;

		case 5:
			cout << "����� ��������� �����: ";
			cin >> point;
			showCurrentObj(arr, sizeStore, point); break;
		
		case 6:
			cout << "����� ������: ";
			cin >> numstore;

			cout << "�����: " << totalCost(arr, sizeStore, numstore) << " ������.\n\n"; break;

		default:	
			cout << "������� ������ ����� ����, ������� ������ �� ������ �� ���� � ������� ����������� �������� (1-6) ��� ����� (0)\n\n"; break;
		}

	} while (menu != 0);







	system("pause");
	return 0;
}