#define _CRT_SECURE_NO_WARNINGS

#pragma once
#include <iostream>
#include "Storage.h"
#include "Stock.h"

using namespace std;

int controlCommand();

class Box
{
public:
    Storage* StorageBase;
    Stock* StockBase;
    Common* CommonBase;
    static int count;

    Box();

    void addElement();
    void show_data();
    void sort();
    void save();
    void read();
    void search();
    void Case3(Common*& fCommon, Stock*& fStock, Storage*& fStorage, Date& fdate, int fCountProductsWhatWeNeed);
    void ArrivedProduct();
    void ConsumptionProduct();

    friend int CountCase3(Stock* fStockBase, Date& fdate, int fcount);

    ~Box();
};
