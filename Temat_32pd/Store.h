#include "Date.h"
#include "MyString.h"

struct Store
{
	int storage;			// •	Номер склада 
	int commodity;		  //  •	Код товара 
	MyString namecom;		  //   •	Наименование товара 
	Date arrive;		 //	   •	Дата поступления на склад
	int bestbefore;		 //	   •	Срок хранения в днях 
	int numberofunits;	//		•	Количество единиц товара 
	float priceforone;		//	•	Цена за одну единицу товара 

	void fillStore();	// заполнение 
	void showStore();

};

void showAllStore(Store* arr, int size);	//2.	Вывод всех товаров
void showCurrentObj(Store* arr, int size, int obj);	// вывод списка товаров в выбранном складе
float totalCost(Store* arr, int size, int N); // суммарную стоимость товаров на складе по его номеру.
void findOverdue(Store* arr, int size);	//Поиск всех товаров, у которых на текущую дату истек срок хранения
void addObj(Store*& arr, int& size);		// 3.	Добавление нового товара
void deleteObj(Store*& arr, int& size, char* itemName);	//4.	Удаление товара со склада
