#include<iostream>
#include<fstream>
#include<string>
#include<cstring>

using namespace std;
//these are prototypes
void search();
void delete_record();
void update();
int display();
int balance();
int deposit(int);
void withdraw();
int transfer();
void exit();
//here we create a structure
struct new_record1
{
	int acc;
	string f_name;
	string l_name;
	string city;
	string state;
	int zip;
	string tel_no;
	int  balance;
	int day;
	int month;
	int year;

};
//here we create an array
new_record1 arr[100];
//this is main function
int main()
{
	//using file hand handling
	ofstream new_record; // this is start of ofstream
	ifstream new_record2; // this is the start of ifstream
	new_record2.open("banksystem.txt");// this create a text file to store our information/data

	cout << "~~Welcome to H&M Bank~~" << endl;//this is the name of our bank
	int a;
	int j = 0;

	cout << "press 1 to enter new costumer's data" << endl;
	cout << "press 2 for main menu" << endl;
	cin >> a;

	if (a == 1)//use if statement to fulfil user's choice
	{
	record: //this is starting point of goto function which we used below
		cout << "for how many costumers you want to enter data";
		int e;
		cin >> e;

		int i;
		while (j < e)// here we use while loop to enter record of one's customer
		{
			cout << "enter serial number=";
			cin >> i;
		d:
			cout << "assigned account number=" << endl;
			cin >> arr[i].acc;
			if (arr[i].acc != i)
			{
				cout << endl;
				cout << "account number must be your serial number ";
				goto d;
			}

			cin.ignore();

			cout << "enter your first name=" << endl;
			getline(cin, arr[i].f_name); // we use getline to input string

			cout << "enter your last name=" << endl;
			getline(cin, arr[i].l_name);// we use getline to input string


			cout << "Enter your city=" << endl;
			getline(cin, arr[i].city);// we use getline to input string


			cout << "enter your state=" << endl;
			getline(cin, arr[i].state);// we use getline to input string


			cout << "enter you zip/postal code=" << endl;
			cin >> arr[i].zip;

			cin.ignore();
			cout << "enter your telephone number=" << endl;
			getline(cin, arr[i].tel_no); // we use getline to input string


			cout << "enter amount which you want to deposit=" << endl;
			cin >> arr[i].balance;
			cin.ignore();

			cout << "enter today's date" << endl;
			cout << "dd-mm-yyyy" << endl;
			cin >> arr[i].day;
			cin >> arr[i].month;
			cin >> arr[i].year;



			// in below few lines we write values on text file
			new_record.open("banksystem.txt", ios::app);
			new_record << arr[i].acc << endl;
			new_record << arr[i].f_name << " " << arr[i].l_name << endl;
			new_record << arr[i].city << endl;
			new_record << arr[i].state << endl;
			new_record << arr[i].zip << endl;
			new_record << arr[i].tel_no << endl;
			new_record << arr[i].balance << endl;
			new_record << arr[i].day << "-" << arr[i].month << "-" << arr[i].year << endl;
			new_record.close(); // closing ofstream



			// in below few line we extract values from text file
			new_record2 >> arr[i].acc;
			new_record2 >> arr[i].f_name >> arr[i].l_name;
			new_record2 >> arr[i].city;
			new_record2 >> arr[i].state;
			new_record2 >> arr[i].zip;
			new_record2 >> arr[i].tel_no;
			new_record2 >> arr[i].balance;
			new_record2 >> arr[i].day >> arr[i].month >> arr[i].year;



			j++; // using increment operator                                                            
		}
		new_record2.close();


	i: // this is starting point of goto function that we used below

		// In below lines of code we are giving extra facility from which user can either enter another customer record or go to main menu
		cout << "press 1 to enter another costumer's record" << endl;
		cout << "press 2 to go to main menu";

		int z;
		cin >> z;
		if (z == 1)
		{
			goto record;
		}
		else if (z == 2)
		{
			goto start; // this keyword will take the user to word start used below.
		}
		else
		{
			cout << "invalid input try again=";
			goto i;
		}
	}
	else if (a == 2) // using else if, if user enter 2 and this will show 10 options.
	{
	start: // this is starting point of goto function that we used above
		cout << "choose any one number for further processing" << endl;

		int b;
		// this is the main menu from which user have to select	atleast one option	
		cout << " press 1 for new record" << endl;

		cout << " press 2 to Search for a particular customer's record" << endl;

		cout << " press 3 to delete one's costumer record" << endl;

		cout << " press 4 to change in one's costumer record" << endl;

		cout << " press 5 to display all costumer's record" << endl;

		cout << " press 6 for balance inquiry" << endl;

		cout << " press 7 to deposit amount" << endl;

		cout << " press 8 to withdraw amount" << endl;

		cout << " press 9 to transfer amount" << endl;

		cout << " press 10 to exit from program" << endl;

		cin >> b;

		switch (b) // using switch statement to open desired option given by user
		{
		case 1:
			goto record;
			break; // using break statement to leave switch statement
		case 2:
			search();  // calling function
			break;  // using break statement to leave switch statement
		case 3:
			delete_record();  // calling function
			break;  // using break statement to leave switch statement
		case 4:
			update();  // calling function
			break;  // using break statement to leave switch statement
		case 5:

			display();  // calling function
			break;  // using break statement to leave switch statement
		case 6:
			balance();  // calling function
			break;  // using break statement to leave switch statement
		case 7:
			cout << "enter your account number to deposit amount=";
			int j;
			cin >> j;
			deposit(j);  // calling function


			break;  // using break statement to leave switch statement

		case 8:
			withdraw();  // calling function
			break;  // using break statement to leave switch statement
		case 9:
			transfer();  // calling function
			break;  // using break statement to leave switch statement
		case 10:
			exit();  // calling function
			break;  // using break statement to leave switch statement
		default:
			cout << "invalid number";
		}
	}
	else

		cout << "invalid input try again";
	goto start;

	return 1; // returning 1 because return type of main function is integer.






}


void search() // a function with return type void
{
	cout << "welcome to H&M bank search center" << endl;
	cout << "enter any account number ";
	int n; // declaring variable to input account number from the user.
	cin >> n;
	ifstream new_record2;
	new_record2.open("banksystem.txt"); // opening file in append mode to read data

	for (int i = 0; i < 10; i++) // using for loop to extract and display in required array's index
	{
		// in below few lines we are extracting data from already stored text file
		/*if (i == n)
		{*/
		new_record2 >> arr[i].acc;
		new_record2 >> arr[i].f_name >> arr[i].l_name;
		new_record2 >> arr[i].city;
		new_record2 >> arr[i].state;
		new_record2 >> arr[i].zip;
		new_record2 >> arr[i].tel_no;
		new_record2 >> arr[i].balance;
		new_record2 >> arr[i].day >> arr[i].month >> arr[i].year;

		if (i == n) // using if statement to show the data of required account 
		{
			cout << "costumer's account=" << arr[i].acc << endl;
			cout << "costumer's name=" << arr[i].f_name << " " << arr[i].l_name << endl;
			cout << "costumer's city=" << arr[i].city << endl;
			cout << "costumer's state=" << arr[i].state << endl;
			cout << "costumer's zip/postal code=" << arr[i].zip << endl;
			cout << "costumer's telephone number=" << arr[i].tel_no << endl;
			cout << "costumer's total balance=" << arr[i].balance << endl;
			cout << "costumer's last payment date=" << arr[i].day << "-" << arr[i].month << "-" << arr[i].year << endl;
			break;
		}
		/*	}
			continue;*/
	}
	new_record2.close();

}

void delete_record() // creating function
{
	cout << "welcome to H&M " << endl;
	cout << "enter your account number to delete=";
	int t;
	cin >> t;
	ifstream new_record2;
	new_record2.open("banksystem.txt", ios::in);
	for (int i = 0; i < 10; i++) // using for loop to extract and display in required array's index 
	{
		// in below few lines we are extracting data from already stored text file
		new_record2 >> arr[i].acc;
		new_record2 >> arr[i].f_name >> arr[i].l_name;
		new_record2 >> arr[i].city;
		new_record2 >> arr[i].state;
		new_record2 >> arr[i].zip;
		new_record2 >> arr[i].tel_no;
		new_record2 >> arr[i].balance;
		new_record2 >> arr[i].day >> arr[i].month >> arr[i].year;
		if (i == t)
		{
			cout << "costumer's account=" << arr[i].acc << endl;
			cout << "costumer's name=" << arr[i].f_name << " " << arr[i].l_name << endl;
			cout << "costumer's city=" << arr[i].city << endl;
			cout << "costumer's state=" << arr[i].state << endl;
			cout << "costumer's zip/postal code=" << arr[i].zip << endl;
			cout << "costumer's telephone number=" << arr[i].tel_no << endl;
			cout << "costumer's total balance=" << arr[i].balance << endl;
			cout << "costumer's last payment date=" << arr[i].day << "-" << arr[i].month << "-" << arr[i].year << endl;
			break;
		}
	}
	cout << "press 1 to delete?";
	int h;
	cin >> h;
	if (h == 1)
	{

		ofstream record1;
		record1.open("banksystem.txt");
		int k = 0;
		if (arr[k].acc != t)
		{
			record1 << arr[k].acc << endl;
			record1 << arr[k].f_name << " " << arr[k].l_name << endl;
			record1 << arr[k].city << endl;
			record1 << arr[k].state << endl;
			record1 << arr[k].zip << endl;
			record1 << arr[k].tel_no << endl;
			record1 << arr[k].balance << endl;
			record1 << arr[k].day << "-" << arr[k].month << "-" << arr[k].year << endl;
		}

		record1.close();
		ofstream record;
		record.open("banksystem.txt", ios::app);
		for (int i = 1; i < 10; i++)
		{
			if (arr[i].acc != t)
			{

				record << arr[i].acc << endl;
				record << arr[i].f_name << " " << arr[i].l_name << endl;
				record << arr[i].city << endl;
				record << arr[i].state << endl;
				record << arr[i].zip << endl;
				record << arr[i].tel_no << endl;
				record << arr[i].balance << endl;
				record << arr[i].day << "-" << arr[i].month << "-" << arr[i].year << endl;
			}
		}

		record.close();

	}

}

void update() // creating function
{
	cout << "welcome to H&M " << endl;
	cout << "enter your account number to update";
	int h;
	cin >> h;
	ifstream new_record2;
	new_record2.open("banksystem.txt", ios::in);
	for (int i = 0; i < 10; i++) // using for loop to extract and display in required array's index 
	{
		// in below few lines we are extracting data from already stored text file
		new_record2 >> arr[i].acc;
		new_record2 >> arr[i].f_name >> arr[i].l_name;
		new_record2 >> arr[i].city;
		new_record2 >> arr[i].state;
		new_record2 >> arr[i].zip;
		new_record2 >> arr[i].tel_no;
		new_record2 >> arr[i].balance;
		new_record2 >> arr[i].day >> arr[i].month >> arr[i].year;
		if (i == h)
		{
			cout << "enter serial number=";
			cin >> i;

			cout << "assigned account number=" << endl;
			cin >> arr[i].acc;

			cin.ignore();

			cout << "enter your first name=" << endl;
			getline(cin, arr[i].f_name); // we use getline to input string

			cout << "enter your last name=" << endl;
			getline(cin, arr[i].l_name);// we use getline to input string


			cout << "Enter your city=" << endl;
			getline(cin, arr[i].city);// we use getline to input string


			cout << "enter your state=" << endl;
			getline(cin, arr[i].state);// we use getline to input string


			cout << "enter you zip/postal code=" << endl;
			cin >> arr[i].zip;

			cin.ignore();
			cout << "enter your telephone number=" << endl;
			getline(cin, arr[i].tel_no); // we use getline to input string

			cin.ignore();
			cout << "enter amount which you want to deposit=" << endl;
			cin >> arr[i].balance;
			cin.ignore();

			cout << "enter today's date" << endl;
			cout << "dd-mm-yyyy" << endl;
			cin >> arr[i].day;
			cin >> arr[i].month;
			cin >> arr[i].year;
			cout << arr[i].day << "-" << arr[i].month << "-" << arr[i].year << endl;

			cout << "costumer's account=" << arr[i].acc << endl;
			cout << "costumer's name=" << arr[i].f_name << " " << arr[i].l_name << endl;
			cout << "costumer's city=" << arr[i].city << endl;
			cout << "costumer's state=" << arr[i].state << endl;
			cout << "costumer's zip/postal code=" << arr[i].zip << endl;
			cout << "costumer's telephone number=" << arr[i].tel_no << endl;
			cout << "costumer's total balance=" << arr[i].balance << endl;
			cout << "costumer's last payment date=" << arr[i].day << "-" << arr[i].month << "-" << arr[i].year << endl;

			break;
		}
	}
	ofstream record;
	record.open("banksystem.txt");
	record << arr[0].acc << endl;
	record << arr[0].f_name << " " << arr[0].l_name << endl;
	record << arr[0].city << endl;
	record << arr[0].state << endl;
	record << arr[0].zip << endl;
	record << arr[0].tel_no << endl;
	record << arr[0].balance << endl;
	record << arr[0].day << "-" << arr[0].month << "-" << arr[0].year << endl;
	record.close();
	for (int i = 1; i < 10; i++)
	{
		record.open("banksystem.txt", ios::app);
		record << arr[i].acc << endl;
		record << arr[i].f_name << " " << arr[i].l_name << endl;
		record << arr[i].city << endl;
		record << arr[i].state << endl;
		record << arr[i].zip << endl;
		record << arr[i].tel_no << endl;
		record << arr[i].balance << endl;
		record << arr[i].day << "-" << arr[i].month << "-" << arr[i].year << endl;

	}
	record.close();
	new_record2.close();
}



int display() // creating function
{



	ifstream new_record2;
	new_record2.open("banksystem.txt");  // opening already stored file in append mode to read data

	cout << "Welcome to H&M Bank Display Center" << endl;

	for (int i = 0; i < 10; i++) // using for loop to extract and display in required array's index 
	{
		// in below few lines we are extracting data from already stored text file
		new_record2 >> arr[i].acc;
		new_record2 >> arr[i].f_name >> arr[i].l_name;
		new_record2 >> arr[i].city;
		new_record2 >> arr[i].state;
		new_record2 >> arr[i].zip;
		new_record2 >> arr[i].tel_no;
		new_record2 >> arr[i].balance;
		new_record2 >> arr[i].day >> arr[i].month >> arr[i].year;

		// displaying required data
		cout << "costumer's account=" << arr[i].acc << endl;
		cout << "costumer's name=" << arr[i].f_name << " " << arr[i].l_name << endl;
		cout << "costumer's total balance=" << arr[i].balance << endl << endl;



	}
	new_record2.close(); // closing ifstream 
	return 1; // returning 1 because return type of main function is integer.
}

int balance() // creating function
{
up: // this is starting point of goto function that we used below 
	cout << "welcome to H & M bank Balance inquery" << endl;
	cout << "enter your account number to check balance";
	int j;   // declaring variable to input account number from the user.
	cin >> j;

	ifstream new_record2;
	new_record2.open("banksystem.txt");// opening already stored file in append mode to read data
	for (int i = 0; i < 10; i++) // using for loop to extract and display in required array's index 
	{
		// in below few lines we are extracting data from already stored text file
		new_record2 >> arr[i].acc;
		new_record2 >> arr[i].f_name >> arr[i].l_name;
		new_record2 >> arr[i].city;
		new_record2 >> arr[i].state;
		new_record2 >> arr[i].zip;
		new_record2 >> arr[i].tel_no;
		new_record2 >> arr[i].balance;
		new_record2 >> arr[i].day >> arr[i].month >> arr[i].year;
		if (i == j) // using if statement to show the data of required account
		{
			// displaying required data
			cout << "costumer's account=" << arr[j].acc << endl;
			cout << "costumer's name=" << arr[j].f_name << " " << arr[j].l_name << endl;
			cout << "costumer's last payment date=" << arr[j].day << "-" << arr[j].month << "-" << arr[j].year << endl << endl;
			cout << "your current balance is =" << arr[j].balance << endl;
			cout << "thanks for using H&M "; // fine compliment :)
		}
	}



	// In below lines of code we are giving extra facility from which user can either check his/her balance again or go to main menu
	cout << "press 1 to check your balance again" << endl;

	int h;
	cin >> h;
	if (h == 1)
	{
		goto up;
	}


	return 1;  // returning 1 because return type of main function is integer.
	new_record2.close();// closing ifstream 
}

int deposit(int j) // creating function
{
	cout << "welcome to H & M bank " << endl;

	ifstream new_record2;
	new_record2.open("banksystem.txt", ios::in);     // opening already stored file in append mode to read data
	for (int i = 0; i < 10; i++) // using for loop to extract and display in required array's index
	{
		// in below few lines we are extracting data from already stored text file
		new_record2 >> arr[i].acc;
		new_record2 >> arr[i].f_name >> arr[i].l_name;
		new_record2 >> arr[i].city;
		new_record2 >> arr[i].state;
		new_record2 >> arr[i].zip;
		new_record2 >> arr[i].tel_no;
		new_record2 >> arr[i].balance;
		new_record2 >> arr[i].day >> arr[i].month >> arr[i].year;
		if (i == j) // using if statement to show the data of required account 
		{
			cout << "costumer's account=" << arr[j].acc << endl;
			cout << "costumer's name=" << arr[j].f_name << " " << arr[j].l_name << endl;
			cout << "costumer's last payment date=" << arr[j].day << "-" << arr[j].month << "-" << arr[j].year << endl;
			cout << "your current balance is =" << arr[j].balance << endl;
			cout << "how much amount you want to deposit";
			int g;
			cin >> g;
			arr[j].balance = arr[j].balance + g;
			cout << "your balance after depositing amount is=" << arr[j].balance << endl;
			cout << "thanks for using H&M ";

			break;

		}
	}

	ofstream record;
	record.open("banksystem.txt");
	record << arr[0].acc << endl;
	record << arr[0].f_name << " " << arr[0].l_name << endl;
	record << arr[0].city << endl;
	record << arr[0].state << endl;
	record << arr[0].zip << endl;
	record << arr[0].tel_no << endl;
	record << arr[0].balance << endl;
	record << arr[0].day << "-" << arr[0].month << "-" << arr[0].year << endl;
	record.close();
	for (int i = 1; i < 10; i++)
	{
		record.open("banksystem.txt", ios::app);
		record << arr[i].acc << endl;
		record << arr[i].f_name << " " << arr[i].l_name << endl;
		record << arr[i].city << endl;
		record << arr[i].state << endl;
		record << arr[i].zip << endl;
		record << arr[i].tel_no << endl;
		record << arr[i].balance << endl;
		record << arr[i].day << "-" << arr[i].month << "-" << arr[i].year << endl;

	}
	record.close();
	new_record2.close();
	return 1;  // returning 1 because return type of main function is integer.
}

void withdraw()
{

	cout << "welcome to H & M bank " << endl;
	cout << "enter your account number to withdraw amount=";
	int j; // declaring variable to input account number from the user.
	cin >> j;
	ifstream new_record2;
	new_record2.open("banksystem.txt", ios::in);// opening already stored file in append mode to read data

	for (int i = 0; i < 10; i++) // using for loop to extract and display in required array's index
	{
		// in below few lines we are extracting data from already stored text file
		new_record2 >> arr[i].acc;
		new_record2 >> arr[i].f_name >> arr[i].l_name;
		new_record2 >> arr[i].city;
		new_record2 >> arr[i].state;
		new_record2 >> arr[i].zip;
		new_record2 >> arr[i].tel_no;
		new_record2 >> arr[i].balance;
		new_record2 >> arr[i].day >> arr[i].month >> arr[i].year;

		if (arr[i].acc == j) // using if statement to show the data of required account
		{

			cout << "costumer's account=" << arr[j].acc << endl;
			cout << "costumer's name=" << arr[j].f_name << " " << arr[j].l_name << endl;
			cout << "costumer's last payment date=" << arr[j].day << "-" << arr[j].month << "-" << arr[j].year << endl;
			cout << "your current balance is =" << arr[j].balance << endl;
			cout << "how much amount you want to withdraw";
			int g;
			cin >> g;
			arr[j].balance = arr[j].balance - g;

			cout << "your balance after withdraw  is=" << arr[j].balance << endl;
			cout << "thanks for using H&M ";


			break;

		}

	}
	ofstream record;
	record.open("banksystem.txt");
	record << arr[0].acc << endl;
	record << arr[0].f_name << " " << arr[0].l_name << endl;
	record << arr[0].city << endl;
	record << arr[0].state << endl;
	record << arr[0].zip << endl;
	record << arr[0].tel_no << endl;
	record << arr[0].balance << endl;
	record << arr[0].day << "-" << arr[0].month << "-" << arr[0].year << endl;
	record.close();
	for (int i = 1; i < 10; i++)
	{
		record.open("banksystem.txt", ios::app);
		record << arr[i].acc << endl;
		record << arr[i].f_name << " " << arr[i].l_name << endl;
		record << arr[i].city << endl;
		record << arr[i].state << endl;
		record << arr[i].zip << endl;
		record << arr[i].tel_no << endl;
		record << arr[i].balance << endl;
		record << arr[i].day << "-" << arr[i].month << "-" << arr[i].year << endl;

	}
	record.close();
	new_record2.close();




}
int transfer()
{

	cout << "welcome to H & M bank transfer section " << endl;
	cout << "enter any account to tarnsfer money";
	int j;  // declaring variable to input account number from the user.
	cin >> j;

	ifstream new_record2;
	new_record2.open("banksystem.txt", ios::app); // opening already stored file in append mode to read data
	for (int i = 0; i <= j; i++) // using for loop to extract and display in required array's index
	{
		// in below few lines we are extracting data from already stored text file
		new_record2 >> arr[i].acc;
		new_record2 >> arr[i].f_name >> arr[i].l_name;
		new_record2 >> arr[i].city;
		new_record2 >> arr[i].state;
		new_record2 >> arr[i].zip;
		new_record2 >> arr[i].tel_no;
		new_record2 >> arr[i].balance;
		new_record2 >> arr[i].day >> arr[i].month >> arr[i].year;
		if (i == j) // using if statement to show the data of required account
		{
			cout << "costumer's account=" << arr[j].acc << endl;
			cout << "costumer's name=" << arr[j].f_name << " " << arr[j].l_name << endl;
			cout << "costumer's last payment date=" << arr[j].day << "-" << arr[j].month << "-" << arr[j].year << endl;
			cout << "your current balance is =" << arr[j].balance << endl;
			cout << "enter account number to which you want to transfer amount ";
			int o;
			cin >> o;
			cout << "how much amount you want to tarnsfer =";
			int g;
			cin >> g;
			while (g > arr[j].balance || g < 0)
			{
				cout << "you have insufficient balance or you enter negative value enter your amount again=";
				cin >> g;
			}
			arr[j].balance = arr[j].balance - g;
			arr[o].balance = arr[o].balance + g;
			cout << "now your balance is=";
			cout << arr[j].balance;
		}
	}
	ofstream record;
	record.open("banksystem.txt");
	record << arr[0].acc << endl;
	record << arr[0].f_name << " " << arr[0].l_name << endl;
	record << arr[0].city << endl;
	record << arr[0].state << endl;
	record << arr[0].zip << endl;
	record << arr[0].tel_no << endl;
	record << arr[0].balance << endl;
	record << arr[0].day << "-" << arr[0].month << "-" << arr[0].year << endl;
	record.close();
	for (int i = 1; i < 100; i++)
	{
		record.open("banksystem.txt", ios::app);
		record << arr[i].acc << endl;
		record << arr[i].f_name << " " << arr[i].l_name << endl;
		record << arr[i].city << endl;
		record << arr[i].state << endl;
		record << arr[i].zip << endl;
		record << arr[i].tel_no << endl;
		record << arr[i].balance << endl;
		record << arr[i].day << "-" << arr[i].month << "-" << arr[i].year << endl;

	}
	record.close();

	return 1;  // returning 1 because return type of main function is integer.

}

void exit() // creating function
{
	exit(1);
}