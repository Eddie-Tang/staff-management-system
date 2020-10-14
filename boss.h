#pragma once 
#include<iostream>
using namespace std;
#include"worker.h"

class Boss: public Worker
{
public:
	//constructor function
	Boss(int id, string name, int dId);
	//show boss information
	void show_info();
};
