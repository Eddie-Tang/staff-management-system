//******task description******
//--Three kinds of staff: employee, manager, boss
//--The information of staff: id, name, position, task
//the task of employee: finish the task from manager
//the task of manager: finish the task from boss and give task to employee
//the task of boss: manage all affairs of the company

//the function of the staff management system:
// 1.exit the management system: 
//2.show all the staff information:
// 3.add staff information: batch add information to file, the information is: staff id, name , department id
//4.delete staff information:
//5.find staff information: find a staff according to name or id
//6.modify staff information:
//7.sort according to id: the rule is decided by user
//8.delete all the staff information(need to confirm):

//关键点：1.三类职工具有共性，也有个性，所以可以对其利用多态技术
//2.利用一个Worker*类型的指针数组来存储文件中的数据，所有的增删查改都是先对这个数组进行操作，操作完成后再利用save()函数更新到文件 

#include<iostream>
#include"staffManager.h"

using namespace std;

int main()
{
	system("title Staff Management System");
	system("color 0F");
	WorkerManager wm;
	int choice = 0;
	while(true)
	{
		wm.show_menu();
		cout << "please input your choice:" << endl;
		cin >> choice;
		switch(choice)
		{
			case 0: //exit system
			    wm.exit_system();
			    break;
			case 1: //add staff
			    wm.add_staff();
			    break;
			case 2: //show all staff
			    wm.show_emp();
			    break;
			case 3: //delete staff
			    wm.delete_staff();
			    break;
			case 4: //modify staff
			    wm.modify_staff();
			    break;
		    case 5: //find staff
		        wm.find_staff();
		        break;
		    case 6: //sort staff
		        wm.sort_staff();
		        break;
		    case 7: //delete all staff
		        wm.delete_all();
		        break;
		    default:
		    	break;
		}
		system("pause");
		system("cls");
	}
	
	system("pause");
	return 0;
} 
