#include<iostream>
#include"manager.h"
using namespace std;

//constructor function
Manager::Manager(int id, string name, int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}
//show manager information
void Manager::show_info()
{
	cout << "id: " << setw(8) << left << this->m_Id
	     << "name: " << setw(15) << left << this->m_Name
	     << setw(25) << left << "position: manager"
	     << "task: finish the task from boss and give task to employee"
	     << endl;
}
