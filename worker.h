#pragma once
#include<iostream>
#include<string>
#include<iomanip>//Ìá¹©setw()º¯Êý 
using namespace std;

//abstrct class: Worker
class Worker
{
public:
	//show personal information
    virtual void show_info() = 0;	
    
    int m_Id; //worker id
    string m_Name; //worker name
    int m_DeptId; //worker's department id
};
