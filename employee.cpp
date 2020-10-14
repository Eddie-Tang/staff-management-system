#include<iostream>
#include"employee.h"
using namespace std;

//constructor function
Employee::Employee(int id, string name, int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}
//show employee information
void Employee::show_info()
{
	cout << "id: " << setw(8) << left << this->m_Id
	     << "name: " << setw(15) << left << this->m_Name
	     << setw(25) << left << "position: employee"
	     << "task: finish the task from manager"
	     << endl;
}
