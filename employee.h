#pragma once
#include<iostream>
using namespace std;
#include "worker.h"

class Employee: public Worker
{
public:
	//constructor function
	Employee(int id, string name, int dId);
	//show employee information
	void show_info();
	
};
