#define _CRT_SECURE_NO_WARNINGS

#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <Windows.h>
#include <locale>

using namespace std;

class Common 
{
	friend class Box;

protected:

	//char* name;
	int availability;

public:

	Common();

	Common& operator=(const Common& equal);

	virtual void add_data();
	virtual void show_data();
};
