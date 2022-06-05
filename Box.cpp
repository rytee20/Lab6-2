#define _CRT_SECURE_NO_WARNINGS

#include "Box.h"

int ControlDay(int fyear, int fmounth);
int ControlMounth();
int ControlYear();
int ControlCommand2();
int ControlAmount();
int ControlSection();

Box::Box()
{
    StorageBase = new Storage[0];
    StockBase = new Stock[0];
    CommonBase = new Common[0];
}

void Box::addElement() {
    Storage* tmpStorage;
    Stock* tmpStock;
    Common* tmpCommon;


    if (count == 0)
    {
        StorageBase = new Storage[count+1];
        StockBase = new Stock[count+1];
        CommonBase = new Common[count+1];
        
        CommonBase[count].add_data();
        StorageBase[count].add_data();
        StockBase[count].add_data();
        

        count++;
    }

    else if (count != 0)
    {
        tmpStorage = new Storage[count + 1];
        tmpStock = new Stock[count + 1];
        tmpCommon = new Common[count + 1];

        for (int i = 0; i < count; i++)
        {
            tmpStorage[i] = StorageBase[i];
            tmpStock[i] = StockBase[i];
            tmpCommon[i] = CommonBase[i];
        }

        delete[] StorageBase;
        delete[] StockBase;
        delete[] CommonBase;
        StorageBase = tmpStorage;
        StockBase = tmpStock;
        CommonBase = tmpCommon;

        count++;
        cout << "Товар есть в наличии на складе? Введите 1, если да, и 0, если нет: ";
        CommonBase[count - 1].add_data();
        bool its_ok = true;
        if (CommonBase[count - 1].availability == 1)
        {
            while (its_ok)
            {
                cin >> StorageBase[count - 1];
                for (int i = 0; i < count - 1; i++)
                {
                    if (StorageBase[count - 1].cost == StorageBase[i].cost && strcmp(StorageBase[count - 1].name, StorageBase[i].name))
                        its_ok = false;
                }
                if (!its_ok)
                {
                    cout << "Такой товар уже есть, повторите ввод:" << endl;
                    its_ok = true;
                }
                else its_ok = false;
            }
            //cin >> StorageBase[count - 1];
            cin >> StockBase[count - 1];
        }
        else
        {
            while (its_ok)
            {
                cin >> StorageBase[count - 1];
                for (int i = 0; i < count - 1; i++)
                {
                    if (StorageBase[count - 1].cost == StorageBase[i].cost && !strcmp(StorageBase[count - 1].name, StorageBase[i].name))
                        its_ok = false;
                }
                if (!its_ok)
                {
                    cout << "Такой товар уже есть, повторите ввод:" << endl;
                    its_ok = true;
                }
                else its_ok = false;
            }
            //cin >> StorageBase[count - 1];
            StockBase[count - 1].sectionnumber = 0;
            StockBase[count - 1].amount = 0;
            StockBase[count - 1].arriveddate.day = 0;
            StockBase[count - 1].arriveddate.mounth = 0;
            StockBase[count - 1].arriveddate.year = 0;
        }
    }
}

void Box::show_data() 
{
    cout << "Вы хотите распечатать только товары, которые есть в наличии (нажмите 1), или товары, которых нет в наличии (нажмите 0)?" << endl;
    int choise;
    choise = ControlCommand2();
    if (choise == 1)
    {
        cout << "Содержимое файла:" << endl << "НАЗВАНИЕ" << "\t\t" << "ЦЕНА" << "\t\t" << "СЕКЦИЯ" << "\t\t" << "ДАТА" << "\t\t" << "КОЛИЧЕСТВО" << endl;
        for (int i = 0; i < count; i++)
        {
            if (CommonBase[i].availability == 1)
            {
                StorageBase[i].show_data();
                StockBase[i].show_data(CommonBase[i].availability);
                cout << endl;
            }
        }
    }
    else
    {
        cout << "Содержимое файла:" << endl << "НАЗВАНИЕ" << "\t\t" << "ЦЕНА" << endl;
        for (int i = 0; i < count; i++)
        {
            if (CommonBase[i].availability == 0)
            {
                StorageBase[i].show_data();
                StockBase[i].show_data(CommonBase[i].availability);
                cout << endl;
            }
        }
    }
}

void Box::sort()
{
    for (int i = count - 1; i >= 0; i--) {
        for (int j = 0; j < i; j++) {
            if (StorageBase[j].GetCost() < StorageBase[j + 1].GetCost()) {
                swap(CommonBase[j], CommonBase[j + 1]);
                swap(StorageBase[j], StorageBase[j + 1]);
                swap(StockBase[j], StockBase[j + 1]);

            }
        }
    }
}

void Box::save()
{
    ofstream record("Base.txt", ios::out);

    if (record)
    {
        record << count << endl;
        for (int i = 0; i < count - 1; i++)
        {
            record << CommonBase[i].availability << " ";
            if (CommonBase[i].availability==1)
            {
                record << StorageBase[i].name << " " << StockBase[i].GetAmount() << " " << StorageBase[i].GetCost() << " " << StockBase[i].GetSectionnumber() << " " << StockBase[i].arriveddate.day << " " << StockBase[i].arriveddate.mounth << " " << StockBase[i].arriveddate.year << endl;

            }
            else
            {
                record << StorageBase[i].name << " " << StorageBase[i].GetCost() << endl;
            }
        }
        record << CommonBase[count-1].availability << " ";
        if (CommonBase[count - 1].availability == 1)
        {
            record << StorageBase[count - 1].name << " " << StockBase[count - 1].GetAmount() << " " << StorageBase[count - 1].GetCost() << " " << StockBase[count - 1].GetSectionnumber() << " " << StockBase[count - 1].arriveddate.day << " " << StockBase[count - 1].arriveddate.mounth << " " << StockBase[count - 1].arriveddate.year;

        }
        else
        {
            record << StorageBase[count - 1].name  << " " << StorageBase[count - 1].GetCost();
        }
    }
    else
    {
        cout << "ОШИБКА ЗАПИСИ ДАННЫХ НА ДИСК" << endl;
    }
    record.close();
}

void Box::read()
{
    ifstream fin;
    int count1 = 0;
    fin.open("Base.txt");
    char* str = new char[1024];

    if (!fin.is_open()) cout << "Не удается открыть файл" << endl; //если с файлом плохо
    else
    {
        if (fin.peek() == EOF) cout << "Файл пуст" << endl; //файл пуст или его нет
        else // иначе все хорошо и мы считываем
        {
            fin.close();
            fin.open("Base.txt");

            char* fname = new char[50];
            int fday;
            int fmounth;
            int fyear;
            double fcost;
            int famount;
            int fsectionnumber;
            int favailability;
            
            fin >> count;
            cout << count;

            StorageBase = new Storage[count];
            StockBase = new Stock[count];
            CommonBase = new Common[count];

            for (int i = 0; i < count; i++) 
            {
                fin >> favailability;
                CommonBase[i].availability = favailability;

                if (favailability==1)
                {
                    fin >> fname >> famount >> fcost >> fsectionnumber >> fday >> fmounth >> fyear;

                    strcpy(StorageBase[i].name, fname);
                    StockBase[i].arriveddate.day = fday;
                    StockBase[i].arriveddate.mounth = fmounth;
                    StockBase[i].arriveddate.year = fyear;
                    StorageBase[i].cost = fcost;
                    StockBase[i].amount = famount;
                    StockBase[i].sectionnumber = fsectionnumber;
                }
                else
                {
                    fin >> fname >> fcost;

                    strcpy(StorageBase[i].name, fname);
                    StorageBase[i].cost = fcost;
                    StockBase[i].arriveddate.day = 0;
                    StockBase[i].arriveddate.mounth = 0;
                    StockBase[i].arriveddate.year = 0;
                    StockBase[i].amount = 0;
                    StockBase[i].sectionnumber = 0;
                }
            }
        }
    }
    cout << "Считано " << count << " объектов из файла" << endl;

    fin.close();
}

void Box::search()
{
    int fsection, i = 0, fcount = 0;
    fsection = ControlSection();

    cout << "Товары в заданной секции: " << endl << "НАЗВАНИЕ  ДАТА  ЦЕНА  КОЛИЧЕСТВО  СЕКЦИЯ" << endl;

    while (i < count)
    {
        if (StockBase[i].sectionnumber == fsection)
        {
            fcount++;
            StorageBase[i].show_data();
            StockBase[i].show_data(CommonBase[i].availability);
            cout << endl;
        }
        i++;
    }

    if (fcount == 0) cout << "Не найдено товаров в заданной секции" << endl;
}

int CountCase3(Stock* fStockBase, Date& fdate, int fcount)
{
    cout << "Итак введите дату, и все товаты поступившие после будут выведены на экран и сложены в массив" << endl;
    fdate.year = ControlYear();
    fdate.mounth = ControlMounth();
    fdate.day = ControlDay(fdate.year, fdate.mounth);
    int fCountProductsWhatWeNeed = 0;
    for (int i = 0; i < fcount; i++)
    {
        if (fStockBase[i] > fdate)
        {
            fCountProductsWhatWeNeed++;
        }
    }
    return fCountProductsWhatWeNeed;
}

void Box::Case3(Common*& fCommon, Stock*& fStock, Storage*& fStorage, Date& fdate, int fCountProductsWhatWeNeed)
{
    fStorage = new Storage[fCountProductsWhatWeNeed + 1];
    fStock = new Stock[fCountProductsWhatWeNeed + 1];
    fCommon = new Common[fCountProductsWhatWeNeed + 1];
    int fcount = 0;
    for (int i = 0; i < count; i++)
    {
        if (StockBase[i] > fdate)
        {
            fCommon[fcount] = CommonBase[i];
            fStock[fcount] = StockBase[i];
            fStorage[fcount] = StorageBase[i];
            fcount++;

            StorageBase[i].show_data();
            StockBase[i].show_data(CommonBase[i].availability);
            cout << endl;
        }
    }
}

void Box::ArrivedProduct()
{
    Storage* tmpStorage = new Storage[1];
    int fcount = 0;
    int plase;
    int famount;

    cout << "Введите название и цену товара, который прибыл на склад" << endl;
    tmpStorage[0].add_data();

    for (int i = 0; i < count; i++)
    {
        if (!strcmp(StorageBase[i].name, tmpStorage[0].name) && StorageBase[i].cost == tmpStorage[0].cost)
        {
            fcount++;
            plase = i;
        }
    }
    if (fcount == 0) {
        cout << "В нашем ассортименьте нет товара с указанными названием и ценой, добавьте его как новый товар" << endl;
    }
    else
    {
        cout << "Товар найден" << endl;
        if (StockBase[plase].amount == 0)
        {
            cout << "Товара ранее не было на складе, введите все заново" << endl;
            cin >> StockBase[plase];
            CommonBase[plase].availability = 1;
        }
        else
        {
            cout << "Товар уже есть на складе, введите сколько прибыло в новой партии и дату прибытия" << endl;
            famount= ControlAmount();
            StockBase[plase].amount = StockBase[plase].amount + famount;
            StockBase[plase].arriveddate.year = ControlYear();
            StockBase[plase].arriveddate.mounth = ControlMounth();
            StockBase[plase].arriveddate.day = ControlDay(StockBase[plase].arriveddate.year, StockBase[plase].arriveddate.mounth);
        }
    }
}

void Box::ConsumptionProduct()
{
    Storage* tmpStorage = new Storage[1];
    int fcount = 0;
    int plase;
    int famount;

    cout << "Введите название и цену товара, который прибыл на склад" << endl;
    cin >> tmpStorage[0];

    for (int i = 0; i < count; i++)
    {
        if (!strcmp(StorageBase[i].name, tmpStorage[0].name) && StorageBase[i].cost == tmpStorage[0].cost)
        {
            fcount++;
            plase = i;
        }
    }

    if (fcount == 0)
    {
        cout << "Такого товара нет" << endl;
    }
    else
    {
        if (StockBase[plase].amount == 0)
        {
            cout << "Товар найден, но его уже нет на складе" << endl;
        }
        else
        {
            cout << "Товар найден, введите сколько закончилось:" << endl;
            famount = ControlAmount();
            while (famount > StockBase[plase].amount)
            {
                cout << "Нельзя потратить больше товара, чем есть на складе, повторите ввод" << endl;
                famount = ControlAmount();
            }
            if (StockBase[plase].amount== famount)
            {
                StockBase[plase].amount = 0;
                StockBase[plase].arriveddate.year = 0;
                StockBase[plase].arriveddate.mounth = 0;
                StockBase[plase].arriveddate.day = 0;
                StockBase[plase].sectionnumber = 0;
                CommonBase[plase].availability = 0;
            }
            else
            {
                StockBase[plase].amount = StockBase[plase].amount - famount;
            }
        }
    }
}

Box::~Box() {
    delete[] CommonBase;
    delete[] StorageBase;
    delete[] StockBase;
    cout << "Почистилос" << endl;
}
