#include"staffManager.h"

//constructor function
WorkerManager::WorkerManager()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	
	//1.当文件不存在时，进行如下初始化 
	if(!ifs.is_open())
	{
		//cout << "file is not exist" << endl;
	    this->m_FileIsEmpty = true;
	    this->m_EmpNum = 0;//initilize the staff number
    	this->m_EmpArray = NULL;//initialize the staff array pointer
    	ifs.close();
    	return;
	}
	//2.当文件存在但是文件为空时，进行如下初始化
	char ch;
	ifs >> ch;
	if(ifs.eof())
	{
		//cout << "file is empty" << endl;
	    this->m_FileIsEmpty = true;
	    this->m_EmpNum = 0;//initilize the staff number
    	this->m_EmpArray = NULL;//initialize the staff array pointer
    	ifs.close();
    	return;
	}
	//3.当文件不为空，则把文件内容读入程序中
	//cout << "there is data in the file" << endl;
	int num = this->get_empNum();
	this->m_EmpNum = num;
	this->m_EmpArray = new Worker*[this->m_EmpNum];
	this->ini_emp();
	this->m_FileIsEmpty = false;
	ifs.close();
}

//destructor function
WorkerManager::~WorkerManager()
{
	if(this->m_EmpArray != NULL)
	{
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}

//show menu
void WorkerManager::show_menu()
{
	cout << "***********************************************************" << endl;
	cout << "*********  welcome to use staff management system *********" << endl;
	cout << "*********  0. Exit the system                     *********" << endl;
	cout << "*********  1. Add staff information               *********" << endl;
	cout << "*********  2. Show all the staff information      *********" << endl;
	cout << "*********  3. Delete staff information            *********" << endl;
	cout << "*********  4. Modify staff information            *********" << endl;
	cout << "*********  5. Find staff information              *********" << endl;
	cout << "*********  6. Sort accordiong to staff id         *********" << endl;
	cout << "*********  7. Delete all the staff information    *********" << endl;
	cout << "***********************************************************" << endl;
	cout <<endl;
}

//exit system
void WorkerManager::exit_system()
{
	cout << "welcome to use again!" << endl;
	system("pause");
	exit(0);
}
//add staff
void WorkerManager::add_staff()
{
	cout << "input the amount of staff you will add:" << endl;
	int addNum;
	cin >> addNum;
	
	if(addNum > 0)
	{
		int newNum = this->m_EmpNum + addNum;
		Worker **newArray = new Worker*[newNum];
		
		//copy the original data
		if(this->m_EmpArray != NULL)
		{
			for(int i = 0; i < this->m_EmpNum; i++)
			{
				newArray[i] = this->m_EmpArray[i]; 
			}
		}
		//add new data
		for(int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int deptId;
			
			cout << "input the NO." << i+1 << " staff's id:" << endl;
			cin >> id;
			cout << "input the NO." << i+1 << " staff's name:" << endl;
			cin >> name;
			cout << "input the NO." << i+1 << " staff's position:" << endl;
			cout << "1.employee" <<endl;
			cout << "2.manager" << endl;
			cout << "3.boss" << endl;
			cin >> deptId;
			
			Worker *worker = NULL;
			switch(deptId)
			{
				case 1: //employee
				    worker = new Employee(id, name, deptId);
				    break;
				case 2: //manager
				    worker = new Manager(id, name, deptId);
				    break;
				case 3: //boss
				    worker = new Boss(id, name, deptId);
				    break;
				default:
					break;
			}
			//update staff array
			newArray[this->m_EmpNum + i] = worker;
			
		}
		
		delete[] this->m_EmpArray;
		this->m_EmpNum = newNum;
		this->m_EmpArray = newArray;
		this->m_FileIsEmpty = false;
		
		cout << "add " << addNum << " staffs successfully" <<endl;
		this->save();
	} 
	else
	{
		cout << "input error!" <<endl;
	} 
}

//save the data to file
void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	
	for(int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << "    "
		    << this->m_EmpArray[i]->m_Name << "    "
		    << this->m_EmpArray[i]->m_DeptId << endl;
	}
	
	ofs.close();
}
//get the number of staff in the file
int WorkerManager::get_empNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int deptId;
	int num = 0;
	
	while(ifs >> id && ifs >> name && ifs >> deptId)
	{
		num++;
	}
	ifs.close();
	
	return num;
}
//realize the function of reading the data to the program
void WorkerManager::ini_emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int deptId;
	
	for(int index=0; ifs>>id && ifs>>name && ifs>>deptId; index++)
	{
		Worker *worker = NULL;
		switch(deptId)
		{
			case 1://employee
			    worker = new Employee(id, name, deptId);
			    break;
			case 2://manager
			    worker = new Manager(id, name, deptId);
			    break;
			case 3://boss
			    worker = new Boss(id, name, deptId);
			    break;
			default:
				break;
		}
		this->m_EmpArray[index] = worker;
	}
}
//show all the staff
void WorkerManager::show_emp()
{
	if(this->m_FileIsEmpty)
	{
		cout << "the file is empty" << endl;
		return ;
	}
	for(int i=0; i<this->m_EmpNum; i++)
	{
		this->m_EmpArray[i]->show_info();
	}
}
//delete staff
void WorkerManager::delete_staff()
{
	if(this->m_FileIsEmpty)
	{
		cout << "the file is empty!" << endl;
		return;
	}
	int id;
	cout << "input the id you want to delete:" << endl;
	cin >> id;
	
	int index = this->is_exist(id);
	if(index != -1)
	{
		for(int i=index; i<this->m_EmpNum-1; i++)
		{
			this->m_EmpArray[i] = this->m_EmpArray[i+1];
		}
		this->m_EmpNum--;
		this->save();
		cout << "delete success" << endl;
	}  
	else
	{
		cout << "delete fail! the staff is not exist!" << endl;
	}
}
//judge a staff is exist or not, return the position of the exist staff in the array, or return -1
int WorkerManager::is_exist(int id)
{
	int index = -1;
	
	for(int i = 0; i < this->m_EmpNum; i++)
	{
		if(id == this->m_EmpArray[i]->m_Id)
		{
			index = i;
			break;
		}
	}
	return index;
}
	
//find staff
void WorkerManager::find_staff()
{
	if(this->m_FileIsEmpty)
	{
		cout << "file is empty!" << endl;
		return;
	}
	int choice;
	int id;
	string name;
	
	cout << "input the way you want to find a staff:" <<endl;
	cout << "1.according to id" << endl;
	cout << "2.according to name" <<endl;
	cin >> choice;
	
	if(choice == 1)
	{
		cout << "input the id you want to find:" <<endl;
		cin >> id;
		int index = this->is_exist(id);
		if(index == -1)
		{
			cout << "Find failure! The staff is not exist!" << endl;
		}
		else
		{
			cout << "Find success! The staff's information is as follows:" << endl;
			this->m_EmpArray[index]->show_info();
		}
		
	}
	else if(choice == 2)
	{
		cout << "input the name you want to find:" << endl;
		cin >> name;
		
		for(int i=0; i < this->m_EmpNum; i++)
		{
			if(name == this->m_EmpArray[i]->m_Name)
			{
				cout << "Find success! The staff's information is as follows:" << endl;
				this->m_EmpArray[i]->show_info();
				return;
			}
		}
		cout << "Find failure! The staff is not exist!" << endl;
	}
	else
	{
		cout << "input error! please input a correct choice!" << endl;
	}
	
}
	
//modify staff
void WorkerManager::modify_staff()
{
	if(this->m_FileIsEmpty)
	{
		cout << "the file is empty!" << endl;
		return;
	}
	
	int id;
	int index;
	int newId;
	string newName;
	int newDeptId;
	
	cout << "input the staff's id you want to modify:" <<endl;
	cin >> id;
	index = this->is_exist(id);
	
	if(index == -1)
	{
		cout << "Failure! The staff is not exist!" <<endl;
	}
	else
	{
		cout << "the staff's information is as follows:" << endl;
		this->m_EmpArray[index]->show_info();
		cout << "input a new id:" <<endl;
		cin >> newId;
		cout << "input a new name:" <<endl;
		cin >> newName;
		cout << "input a new department id(1.employee  2.manager  3.boss):" <<endl;
		cin >> newDeptId;
		
		this->m_EmpArray[index]->m_Id = newId;
		this->m_EmpArray[index]->m_Name = newName;
		this->m_EmpArray[index]->m_DeptId = newDeptId;
		
		this->save();
		
	}
}
	
//sort staff according to id
void WorkerManager::sort_staff()
{
	if(this->m_FileIsEmpty)
	{
		cout << "the file is empty!" << endl;
		return ;
	}
	
	cout << "select the way to sort:" << endl;
	cout << "1.from max to min" << endl;
	cout << "2.from min to max" << endl;
	int select;
	cin >> select;
	
	if(select == 1)
	{
		int max;
	    for(int i = 0; i < this->m_EmpNum; i++)
	    {
	    	max = i;
	    	for(int j = i + 1; j < this->m_EmpNum; j++)
	    	{
	    		if(this->m_EmpArray[j]->m_Id > this->m_EmpArray[max]->m_Id)
	    		{
	    			max = j;
				}
			}
			if(max != i)
			{
			    Worker *temp = NULL;
				temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[max];
				this->m_EmpArray[max] = temp;
			}
		}
	}
	else if(select == 2)
	{
		int min;
	    for(int i = 0; i < this->m_EmpNum; i++)
	    {
	    	min = i;
	    	for(int j = i + 1; j < this->m_EmpNum; j++)
	    	{
	    		if(this->m_EmpArray[j]->m_Id < this->m_EmpArray[min]->m_Id)
	    		{
	    			min = j;
				}
			}
			if(min != i)
			{
			    Worker *temp = NULL;
				temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[min];
				this->m_EmpArray[min] = temp;
			}
		}
	}
	else
	{
		cout << "input error! please select a correct number!" << endl;
	}
	this->save();
}
	
//delete all staff
void WorkerManager::delete_all()
{
	if(this->m_FileIsEmpty)
	{
		cout << "the file is empty!" << endl;
		return ;
	}
	this->m_EmpNum = 0;
	this->m_FileIsEmpty = true;
	this->save();
	cout << "success! the file is deleted!" << endl;
}


















