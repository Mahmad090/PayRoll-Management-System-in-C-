#include<iostream>
#include<conio.h>
#include<string>
#include<fstream>
void newrecord();
using namespace std;
const int  d = 30;
struct employee // struct for data
{
	string id;
	char name[30];
	char designation[50];
	int basic_salary; //Basix Salary
	string month;
	int leave;
	int allow_leave;
	int Deduction_rate; //Deduction rate
	int salary;
};
struct slip //struct for salaryslip
{
	string id;
	string name;
	string month;
	string designation;
	string salary;
};
float salarycal(float a, int b, int c, int d)
{
	return a - ((c - b) * d);
}
void addrecord()//1st module
{
	employee data;
	string choice = "", choice1, temp = "";
	do
	{
		system("cls");
		int a = 0;
		fstream file;
		file.open("EmployeesManagementSystem.txt", ios::in);
		if (file.is_open())//take values
		{
			cout << "Ente Information about Employee. Type -1 to exit \n" << "Enter Employee ID :";
			cin >> data.id;
			if (data.id == "-1")
				break;
			if (file.is_open())
			{
				while (!file.eof())
				{
					getline(file, temp, ':');//store month in temp(i.e january:s001:Ahmad riaz:manager:10000:3:4:10222) read untill : reached
					getline(file, temp, ':');//store id in temp
					if (temp == data.id)
					{
						a = 1;
						break;
					}
					else
						getline(file, temp);
				}
				if (a == 1)
				{
					file.close();
					cout << "Employee Exists\n";
					cout << "Enter Employee Name :";
					cin.ignore();
					cin.getline(data.name, 30);
					cout << "Enter Employee Designation :";
					cin.getline(data.designation, 50);
					cout << "Enter Employee Basic Salary :";
					cin >> data.basic_salary;
				month:
					cout << "Enter Working Month :";
					cin >> data.month;
					if (data.month == "january" || data.month == "febuary" || data.month == "march" || data.month == "april" || data.month == "may" || data.month == "june" || data.month == "july" || data.month == "august" || data.month == "september" || data.month == "october" || data.month == "november" || data.month == "december")
					{
						cout << "Enter Leaves :";
						cin >> data.leave;
						cout << "Enter Allowed Leaves :";
						cin >> data.allow_leave;
						cout << "Enter Per Leave Deduction Rate :";
						cin >> data.Deduction_rate;
						if (data.allow_leave < data.leave)
							data.salary = salarycal(data.basic_salary, data.allow_leave, data.leave, data.Deduction_rate);
						else
							data.salary = data.basic_salary;
						file.open("EmployeesManagementSystem.txt", ios::app);
						file << data.month << ":" << data.id << ":" << data.name << ":" << data.designation << ":" << data.salary << ":" << data.leave << ":" << data.allow_leave << ":" << data.basic_salary << endl;
						file.close();
					}
					else
					{
						cout << "Invalid Input.Please enter month name properly(january,febuary etc)" << endl;
						goto month;
					}
					cout << "Do you want to enter another record (yes/no) ";
					cin >> choice;
				}
				else
				{
					cout << "Employee do not exist select 3 from menu to add new employee" << endl;
					cout << "Do you want do add new record (yes/no)";
					cin >> choice1;
					if (choice1 == "yes")
					{
						file.close();
						newrecord();
					}
					else
						break;
				}
			}
		}
		else
		{
			cout << "File Not Found" << endl;
			cout << "Select 3 to add new record \n" << "Want to add new record (yes/no) :";
			cin >> choice1;
			if (choice1 == "yes")
				newrecord();
			else
				break;
		}

	} while (choice == "YES" || choice == "yes" || choice == "Yes");
}
void newrecord()//3rd Module
{
	fstream file;
	file.open("EmployeesManagementSystem.txt", ios::app);
	file.close();
	employee data;
	string choice = "", choice1, temp = "";
	system("cls");
	int a = 0;
	fstream files;
	files.open("EmployeesManagementSystem.txt");
	//take values
	if (files.is_open())
	{
		cout << "Ente Information about Employee.\n";

		cout << "Enter Employee ID :";
		cin >> data.id;
		if (files.is_open())
		{
			while (!files.eof())
			{
				getline(files, temp, ':');
				getline(files, temp, ':');
				if (temp == data.id)
				{
					a = 1;
					break;
				}
				else
					getline(files, temp);
			}
			if (a == 1)
			{
				cout << "Employee already exist select 1 from menu to add employee salary" << endl;
				cout << "Do you want do add new record (yes/no)";
				cin >> choice1;
				if (choice1 == "yes")
				{
					files.close();
					addrecord();
				}
			}
			else
			{
				files.close();
				cout << "Enter Employee Name :";
				cin.ignore();
				cin.getline(data.name, 30);
				cout << "Enter Employee Designation :";
				cin.getline(data.designation, 50);
				cout << "Enter Employee Basic Salary :";
				cin >> data.basic_salary;
			month:
				cout << "Enter Working Month :";
				cin >> data.month;
				if (data.month == "january" || data.month == "febuary" || data.month == "march" || data.month == "april" || data.month == "may" || data.month == "june" || data.month == "july" || data.month == "august" || data.month == "september" || data.month == "october" || data.month == "november" || data.month == "december")
				{
					cout << "Enter Leaves :";
					cin >> data.leave;
					cout << "Enter Allowed Leaves :";
					cin >> data.allow_leave;
					cout << "Enter Per Leave Deduction Rate :";
					cin >> data.Deduction_rate;
					if (data.allow_leave < data.leave)
						data.salary = salarycal(data.basic_salary, data.allow_leave, data.leave, data.Deduction_rate);
					else
						data.salary = data.basic_salary;
					file.open("EmployeesManagementSystem.txt", ios::app);
					file << data.month << ":" << data.id << ":" << data.name << ":" << data.designation << ":" << data.salary << ":" << data.leave << ":" << data.allow_leave << ":" << data.basic_salary << endl;
					file.close();
				}
				else
				{
					cout << "Invalid Input.Please enter month name properly(january,febuary etc)" << endl;
					goto month;
				}
			}
		}
	}
}
void salaryslip()
{
	system("cls");
	int a = 0;
	string  line, m;
	slip info;
	cout << "Enter Month:";
	cin >> m;
	fstream fin;
	fin.open("EmployeesManagementSystem.txt", ios::in);
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			getline(fin, info.month, ':');
			if (info.month == m)
			{
				getline(fin, info.id, ':');
				getline(fin, info.name, ':');
				getline(fin, info.designation, ':');
				getline(fin, info.salary, ':');
				getline(fin, line);
				ofstream file;
				file.open(info.id + "_" + info.name + "_" + "_" + info.month + "_" + "SalarySlip.txt",ios_base::out);
				file << "Salary Month:" << info.month << endl;
				file << "Employee Name:" << info.name << endl;
				file << "Designaion:" << info.designation << endl;
				file << "Salary:" << info.salary << endl << "\n";
				file.close();
				cout << "Salary Month:" << info.month << endl;
				cout << "Employee Name:" << info.name << endl;
				cout << "Designation:" << info.designation << endl;
				cout << "Salary:" << info.salary << endl;
				cout << "File Generated as:" << info.id << "_" << info.name << "_" << info.month << "_" << "SalarySlip\n\n";
				a = 1;
			}
			else
				getline(fin, line);
		}
		fin.close();
		if (a == 0)
			cout << "Data of " << m << " does not exist " << endl;
		cout << "Enter any key To Exit ";
		_getch();
	}
}
int main()
{
	int choice = 1;
	while (choice != 4)
	{
		system("cls");
		cout << "                                  --------------------------------------\n";
		cout << "                                  |Welcome To Payroll Management System|" << endl;
		cout << "                                  --------------------------------------\n";
		cout << "1.Enter 1 to enter information of employee to manage salary of specific month\n";
		cout << "2.Enter 2 to Print Salary Slip\n";
		cout << "3.Enter 3 to enter information of new employee\n";
		cout << "4.Enter 4 to Quit\n";
		cin >> choice;
		if (choice == 1)
			addrecord();
		else if (choice == 3)
			newrecord();
		else if (choice == 2)
			salaryslip();
		else if (choice == 4)
			return 0;
		else
		{
			system("cls");
			cout << "\t\t\t\t\tInvalid Input\n\t\t\tPress enter to return to main menu ";
			_getch();
		}
	}
}
