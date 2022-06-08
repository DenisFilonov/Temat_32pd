#include"Store.h"

void Store::fillStore()
{
	char tmp[100];
	cout << "Номер склада: ";
	cin >> storage;

	cout << "Код товара: ";
	cin >> commodity;

	cout << "Наименование товара: ";
	cin.ignore();
	cin.getline(tmp,100);
	namecom.setMyString(tmp);

	cout << "Дата поступления на склад, ";
	arrive.fillDate();

	cout << "Срок хранения, кол-во дней: ";
	cin >> bestbefore;

	cout << "Кол-во единиц товара: ";
	cin >> numberofunits;

	cout << "Цена за единицу: ";
	cin >> priceforone;
	cout << endl;
}

void Store::showStore()
{
	cout << "Номер склада: " << storage << endl;

	cout << "Код товара: " << commodity << endl;

	cout << "Наименование товара: " << namecom.str << endl;

	cout << "Дата поступления на склад: " << arrive.toString() << endl;

	cout << "Срок хранения, кол-во дней: " << bestbefore << endl;

	cout << "Кол-во единиц товара: " << numberofunits << endl;

	cout << "Цена за единицу: " << priceforone << endl;
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
			cout << "\nПросроченный товар # " << i + 1 << endl << endl;
			cout << "Номер склада: " << arr[i].storage << endl;
			cout << "Код товара: " << arr[i].commodity << endl;
			cout << "Наименование товара: " << arr[i].namecom.str << endl;
			cout << "Дата поступления на склад: " << arr[i].arrive.toString() << endl;
			cout << "Срок хранения, кол-во дней: " << arr[i].bestbefore << endl;
			cout << "Срок хранения истёк на дату: "; finish.printDate(); cout << endl;
			cout << "====================================================\n\n";
			noOverdue++;
		}
	}

	if (noOverdue == 0) cout << "Нет просроченных продуктов.\n\n";
}



void showAllStore(Store* arr, int size)
{
	cout << endl;
	for (int i = 0; i < size; i++)
	{
		cout << "\t Товар #" << i + 1 << endl;
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
			cout << "Код товара: " << arr[i].commodity << endl;

			cout << "Наименование товара: " << arr[i].namecom.str << endl;

			cout << "Дата поступления на склад: " << arr[i].arrive.toString() << endl;

			cout << "Срок хранения, кол-во дней: " << arr[i].bestbefore << endl;

			cout << "Кол-во единиц товара: " << arr[i].numberofunits << endl;

			cout << "Цена за единицу: " << arr[i].priceforone << endl;
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

	cout << "Информация о новом товаре:\n";
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
			cout << itemName << " с кодом товара " << arr[i].commodity << ", находящиеся на складе номер " << arr[i].storage << ", которые поступили на склад по дате "
			<< arr[i].arrive.toString() << " находятся по id номеру в системе # " << i + 1 << endl << endl;
			id = 1;
		}
	}

	if (id == -1)
	{
		cout << "Товар " << itemName << " не найден.\n";
	}
	else
	{
		cout << "Номер удаляемого товара: ";
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

		cout << "Товар \"" << itemName << "\" удалён из базы данных.\n\n";
	}
}
