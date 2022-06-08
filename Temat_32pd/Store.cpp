#include"Store.h"

void Store::fillStore()
{
	char tmp[100];
	cout << "����� ������: ";
	cin >> storage;

	cout << "��� ������: ";
	cin >> commodity;

	cout << "������������ ������: ";
	cin.ignore();
	cin.getline(tmp,100);
	namecom.setMyString(tmp);

	cout << "���� ����������� �� �����, ";
	arrive.fillDate();

	cout << "���� ��������, ���-�� ����: ";
	cin >> bestbefore;

	cout << "���-�� ������ ������: ";
	cin >> numberofunits;

	cout << "���� �� �������: ";
	cin >> priceforone;
	cout << endl;
}

void Store::showStore()
{
	cout << "����� ������: " << storage << endl;

	cout << "��� ������: " << commodity << endl;

	cout << "������������ ������: " << namecom.str << endl;

	cout << "���� ����������� �� �����: " << arrive.toString() << endl;

	cout << "���� ��������, ���-�� ����: " << bestbefore << endl;

	cout << "���-�� ������ ������: " << numberofunits << endl;

	cout << "���� �� �������: " << priceforone << endl;
	cout << "====================================================\n\n";
}

void findOverdue(Store* arr, int size)
{
	int noOverdue = 0;
	cout << endl;

	for (int i = 0; i < size; i++)
	{
		Date finish = arr[i].arrive;
		for (int j = 0; j < arr[i].bestbefore; j++)
		{
			finish.toNextDay();
		}

		Date acheck;
		acheck.getNowDate();
		if (strcmp(finish.toString(), acheck.toString()) <= 0)
		{
			cout << "\n������������ ����� # " << i + 1 << endl << endl;
			cout << "����� ������: " << arr[i].storage << endl;
			cout << "��� ������: " << arr[i].commodity << endl;
			cout << "������������ ������: " << arr[i].namecom.str << endl;
			cout << "���� ����������� �� �����: " << arr[i].arrive.toString() << endl;
			cout << "���� ��������, ���-�� ����: " << arr[i].bestbefore << endl;
			cout << "���� �������� ���� �� ����: "; finish.printDate(); cout << endl;
			cout << "====================================================\n\n";
			noOverdue++;
		}
	}

	if (noOverdue == 0) cout << "��� ������������ ���������.\n\n";
}



void showAllStore(Store* arr, int size)
{
	cout << endl;
	for (int i = 0; i < size; i++)
	{
		cout << "\t ����� #" << i + 1 << endl;
		arr[i].showStore();
	}
}

void showCurrentObj(Store* arr, int size, int obj)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i].storage == obj)
		{
			cout << endl;
			cout << "��� ������: " << arr[i].commodity << endl;

			cout << "������������ ������: " << arr[i].namecom.str << endl;

			cout << "���� ����������� �� �����: " << arr[i].arrive.toString() << endl;

			cout << "���� ��������, ���-�� ����: " << arr[i].bestbefore << endl;

			cout << "���-�� ������ ������: " << arr[i].numberofunits << endl;

			cout << "���� �� �������: " << arr[i].priceforone << endl;
			cout << "====================================================\n\n";

		}
	}
}

float totalCost(Store* arr, int size, int N)
{
	int sum = 0;

	for (int i = 0; i < size; i++)
	{
		if (arr[i].storage == N)
		{
			sum += arr[i].priceforone * arr[i].numberofunits;
		}
	}
	return sum;
}

void addObj(Store*& arr, int& size)
{
	cout << endl;
	Store* tmp = new Store[++size];

	for (int i = 0; i < size - 1; i++)
	{
		tmp[i] = arr[i];
	}

	cout << "���������� � ����� ������:\n";
	tmp[size - 1].fillStore();

	if (arr != NULL) delete[] arr;

	arr = tmp;
}

void deleteObj(Store*& arr, int& size, char* itemName)
{
	cout << endl;
	int id = -1;
	for (int i = 0; i < size; i++)
	{
		if (strcmp(arr[i].namecom.str, itemName) == 0)
		{
			cout << itemName << " � ����� ������ " << arr[i].commodity << ", ����������� �� ������ ����� " << arr[i].storage << ", ������� ��������� �� ����� �� ���� "
			<< arr[i].arrive.toString() << " ��������� �� id ������ � ������� # " << i + 1 << endl << endl;
			id = 1;
		}
	}

	if (id == -1)
	{
		cout << "����� " << itemName << " �� ������.\n";
	}
	else
	{
		cout << "����� ���������� ������: ";
		cin >> id;
		id--;

		Store* tmp = new Store[--size];

		for (int i = 0; i < size; i++)
		{
			if (i < id) tmp[i] = arr[i];
			else if (i >= id) tmp[i] = arr[i + 1];
		}

		if (arr != NULL) delete[] arr;
		arr = tmp;

		cout << "����� \"" << itemName << "\" ����� �� ���� ������.\n\n";
	}
}
