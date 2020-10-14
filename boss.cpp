#include<iostream>
#include"boss.h"
using namespace std;

//constructor function
Boss::Boss(int id, string name, int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}
//show boss information
void Boss::show_info()
{
	cout << "id: " << setw(8) << left << this->m_Id
	     << "name: " << setw(15) << left << this->m_Name
	     << setw(25) << left << "position: boss"
	     << "task: manage all affairs of the company"
	     << endl;
}
