#pragma once 
#include<iostream>
using namespace std;
#include"worker.h"

class Manager: public Worker
{
public:
	//constructor function
	Manager(int id, string name, int dId);
	//show manager information
	void show_info();
};
