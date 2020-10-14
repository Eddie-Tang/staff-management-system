#pragma once
#include<iostream>
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
#include<fstream>
#define FILENAME "staff_information.txt"

using namespace std;

//管理类：各种功能函数都封装在这个类中 
//1.show menu
//2.add,delete,find,modify
//3.read-write interaction with file 
class WorkerManager
{
public:
	//constructor function，initial three variables 
	WorkerManager(); 
	
	//show menu
	void show_menu();
	
	//exit system
	void exit_system();
	
	//add staff 
	void add_staff();
	
	//save the data to file
	//所有对文件中数据的操作都是间接性的，需要先对程序中的数据进行操作，然后将操作结果保存到文件 
	void save();
	
	//get the number of staff in the file
	int get_empNum(); 
	
	//多态realize the function of reading the data to the program
	void ini_emp();
	
	//show all the staff
	void show_emp(); 
	
	//delete staff
	void delete_staff();
	
	//judge a staff is exist or not, return the position of the exist staff in the array, or return -1
	int is_exist(int id); 
	
	//find staff
	void find_staff();
	
	//modify staff
	void modify_staff();
	
	//sort staff according to id
	void sort_staff();
	
	//delete all staff
	void delete_all();
	
	//destructor function
	~WorkerManager();
	
		
    int m_EmpNum;//the number of staff in the file
    Worker **m_EmpArray;//the pointer of staff array
    bool m_FileIsEmpty;//mark the file is empty or not
};
