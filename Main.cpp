#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "Storage.h"
#include "Stock.h"
#include "Box.h"

int Box::count=0;

int CountCase3(Stock* fStockBase, Date& fdate, int fcount);

void menu(int* command)
{

    cout << "===============МЕНЮ===============" << endl;

    cout << "Доступные действия:" << endl;

    cout << "\t" << "1) Поиск товара по номеру секции" << endl;
    cout << "\t" << "2) Сортировать по быванию стоимости" << endl;
    cout << "\t" << "3) Поиск товара с датой больше, чем заданная" << endl;
    cout << "\t" << "4) Печать базы" << endl;
    cout << "\t" << "5) Добавить данные" << endl;
    cout << "\t" << "6) Приход товара на склад" << endl;
    cout << "\t" << "7) Расход со склада" << endl;
    cout << "\t" << "8) Завершение программы" << endl;

    cout << "==============================" << endl;

    cout << "Введите цифру от 1 до 6: " << endl;

    cout << "==============================" << endl << endl;

    *(command) = controlCommand();

}

int main()
{
    setlocale(LC_ALL, "Russian");

    Box box;
    Box MassiveFor3thCase;
    Date DateFor3thCase;
    int CountProductsWhatWeNeed = 0;

    int command;

    box.read();

    do
    {

        menu(&command);
        switch (command)
        {

        case 1:
            box.search();

            break;

        case 2:
            box.sort();

            break;

        case 3:
            if (CountProductsWhatWeNeed != 0)
            {
                delete[] MassiveFor3thCase.CommonBase;
                delete[] MassiveFor3thCase.StockBase;
                delete[] MassiveFor3thCase.StorageBase;
                Box MassiveFor3thCase;
            }
            CountProductsWhatWeNeed = 0;
            CountProductsWhatWeNeed = CountCase3(box.StockBase, DateFor3thCase, Box::count);
            box.Case3(MassiveFor3thCase.CommonBase, MassiveFor3thCase.StockBase, MassiveFor3thCase.StorageBase, DateFor3thCase, CountProductsWhatWeNeed);

            break;

        case 4:
            if (Box::count == 0)
            {
                std::cout << "Еще ничего нет, начинайте добавлять объекты" << std::endl;
            }
            else
            {
                box.show_data();
            }

            break;

        case 5:
            box.addElement();

            break;

        case 6:
            box.ArrivedProduct();

            break;

        case 7:
            box.ConsumptionProduct();

            break;

        case 8:
            //delete[] MassiveFor3thCase.CommonBase;
            //delete[] MassiveFor3thCase.StockBase;
            //delete[] MassiveFor3thCase.StorageBase;
            box.save();

            break;

        default:
            cout << "Неверно введен номер действия";

            break;

        }

    } while (command != 8);

    return 0;
}
