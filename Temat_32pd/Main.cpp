#include "Store.h"
#include <windows.h>
using namespace std;


int main()
{
	setlocale(0, "");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	int sizeStore = 0; // кол-во склада => размерность массива
	Store* arr = NULL; // указатель на динамический массив
	int menu = 0;
	int point = 0;
	int numstore = 0;

	do
	{
	cout	<< "1. Добавить новый товар.\n"
			<< "2. Показать список всех товаров.\n"
			<< "3. Показать список просроченных товаров.\n"
			<< "4. Удалить товар.\n"
			<< "5. Вывод списка товаров в выбранном складе.\n"
			<< "6. Суммарная стоимость товаров на складе по его номеру.\n"
			<< "0. Выход из меню.\n"
			<< "Выбор: ";
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
			cout << "Введите название товара для удаления:\n";
			cin.ignore();
			cin.get(s, 100);
			deleteObj(arr, sizeStore, s); break;

		case 5:
			cout << "Какой требуется склад: ";
			cin >> point;
			showCurrentObj(arr, sizeStore, point); break;
		
		case 6:
			cout << "Номер склада: ";
			cin >> numstore;

			cout << "Итого: " << totalCost(arr, sizeStore, numstore) << " гривен.\n\n"; break;

		default:	
			cout << "Неверно выбран пункт меню, просьба нажать на кнопку из меню и выбрать необходимую операцию (1-6) или выйти (0)\n\n"; break;
		}

	} while (menu != 0);







	system("pause");
	return 0;
}