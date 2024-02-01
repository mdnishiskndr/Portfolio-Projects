#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

//function prototype
void printIntroMenu();
void printMainMenu();
void start();
void login();
void createAccount();
void requestBalance(); // function for getting balance
void depositMoney(); // function for depositing money
void withdrawMoney(); //function for withdraw money

//global variable
char menuInput;
double amount=0;
string loginName;
int loginPassword;


struct Bank //struct variable
{
	string username;
	int password;
	double balance;	
	
	void writeToFile()
{
   	std::ofstream outputFile;
    outputFile.open("Registered BankAcc.txt");
    outputFile << username <<" "<< password << " " << balance << std::endl;
    outputFile.close();
}

};

Bank BankMemberList[100];
Bank B;  //struct member B also can be used




int main()
{
	cout<<"Hi! Welcome to MEBENG ATM Machine"; // TO WRITE A WELCOME MESSAGE HERE
	
	// call the function start
	start();
	
	return 0;
		
}

void start()
{
	// EXPLANATION OF CODE THAT GOES HERE IS BELOW	
	cout<<"\nPlease select an option from the menu below:";
		
	printIntroMenu();
	
	cin>>menuInput;
	
	switch (menuInput)
	{
		case 'l':
			login();
			break;
			
		case 'c':	
			createAccount();	
			break;
				
		case 'q':	
			cout<<"Thanks for stopping by!\n";
			exit(0);		
	}	
}

void printIntroMenu()
{
	// WRITE CODE HERE
	cout<<"\nl-> Login"<<endl;
	cout<<"c-> Create New Account"<<endl;
	cout<<"q-> Quit"<<endl;
	cout<<"\n>";	
}

void createAccount()
{
	// WRITE CODE HERE
	cout<<"\nPlease enter your user id: ";
	cin>>B.username;
	
	cout<<"Please enter your password: ";
	cin>>B.password;
	
	cout<<"\nPlease enter your balance:RM";
	cin>>B.balance;
	
	B.writeToFile();
	
	cout<<"Your account has been created!\n";
	
	printIntroMenu();
	
	cin>>menuInput;
	
	switch (menuInput)
	{
		case 'l':
			login();
			break;

		case 'c':
			createAccount();	
			break;
						
		case'q':
			cout<<"Thanks for stopping by!\n";		
			exit(0);
	}	
}

void login()
{
	// WRITE CODE HERE
	
	cout<<"\nPlease enter your user id: ";
	cin>>loginName;
	
	cout<<"\nPlease enter your password: ";
	cin>>loginPassword;
	
	ifstream fin;
	fin.open("Registered BankAcc.txt");
	
	if(fin.fail())
	{
		cout<<"\nError in opening file"<<endl;
		exit(1);
	}
	
	int i=0;
	while(!fin.eof())
	{
		getline(fin,BankMemberList[i].username,' ');		
		fin>>BankMemberList[i].password;
	 	fin.ignore(1);
	 	fin>>BankMemberList[i].balance;

		if(BankMemberList[i].username==loginName && BankMemberList[i].password==loginPassword)
		{
			cout<<"Access Granted!\n";
			printMainMenu();
		}

		i++;
	}
	cout<<"********LOGIN FAILED!********\n";
	start();	
	fin.close();
}

void printMainMenu()
{
	// WRITE CODE HERE
	while (menuInput!='q')
	{
		cout<<"\nd -> Deposit Money";
		cout<<"\nw -> Withdraw Money";
		cout<<"\nr -> Request balance";
		cout<<"\nq -> Quit";		
		cout<<"\n>";
		cin>>menuInput;
	
		switch (menuInput)
		{
			case 'd':
				cout<<"Enter the amount to depost:RM";
				depositMoney();
				break;

			case 'w':
				cout<<"Enter the amount to withdraw:RM";
				withdrawMoney();
				break;
		
			case 'r':			
				requestBalance();
				break;
		
			case 'q':
				cout << "\nThanks for stopping by!";		
				exit(0);
			
	}
	
	}	
}


void requestBalance() //Function to request balance in Bank Accout
{
	ifstream fin;
	ofstream fout;
	fin.open("Registered BankAcc.txt");
	fout.open("Existing BankAcc.txt");
		
	if(fin.fail())
	{
		cout<<"\nError in opening file"<<endl;
		exit(1);
	}
	
	int i=0;
	while(!fin.eof())
	{
		getline(fin,BankMemberList[i].username, ' ');
		fin>>BankMemberList[i].password;
		fin.ignore(1);
		fin>>BankMemberList[i].balance;


		if(BankMemberList[i].username==loginName && BankMemberList[i].password==loginPassword)
		{
			cout<<"Bank Account of "<<BankMemberList[i].username<<"\n\n"
				<<"DESCRIPTION"<<endl
				<<"\tBalance in your account\t\t\t\t\tRM"<<BankMemberList[i].balance<<endl;
  		 	fout<<BankMemberList[i].username<<" "<<BankMemberList[i].password<<" "<<BankMemberList[i].balance<<endl;				
				break;
		}
		i++;
	}
	fin.close();
	fout.close();	
}

void depositMoney() //Function to deposit into Bank Account
{
	cin>>amount;
	
	ifstream fin;
	ofstream fout;
	fin.open("Registered BankAcc.txt");
	fout.open("Existing BankAcc.txt");
		
	if(fin.fail())
	{
		cout<<"\nError in opening file"<<endl;
		exit(1);
	}
	
	int i=0;
	while(!fin.eof())
	{
		getline(fin,BankMemberList[i].username, ' ');
		fin>>BankMemberList[i].password;
		fin.ignore(1);
		fin>>BankMemberList[i].balance;

		if(BankMemberList[i].username==loginName && BankMemberList[i].password==loginPassword)
		{
			BankMemberList[i].balance=BankMemberList[i].balance+amount;
			cout<<"Bank Account of "<<BankMemberList[i].username<<"\n\n"
				<<"DESCRIPTION"<<endl
				<<"\tThe amount that has been deposit into your account\t\t\tRM"<<amount<<endl
				<<"\tBalance in your account\t\t\t\t\tRM"<<BankMemberList[i].balance<<endl;
			fout<<BankMemberList[i].username<<" "<<BankMemberList[i].password<<" "<<BankMemberList[i].balance<<endl;
				break;				
		}
		i++;
	}
	fin.close();
	fout.close();	
}

void withdrawMoney() //Function to withdraw from Bank Account
{
	cin>>amount;
	
	ifstream fin;
	ofstream fout;
	fin.open("Registered BankAcc.txt");
	fout.open("Existing BankAcc.txt");
		
	if(fin.fail())
	{
		cout<<"\nError in opening file"<<endl;
		exit(1);
	}
	
	int i=0;
	while(!fin.eof())
	{
		getline(fin,BankMemberList[i].username, ' ');
		fin>>BankMemberList[i].password;
		fin.ignore(1);
		fin>>BankMemberList[i].balance;

		if(BankMemberList[i].username==loginName && BankMemberList[i].password==loginPassword)
		{
			if(BankMemberList[i].balance>amount)
			{
				BankMemberList[i].balance=BankMemberList[i].balance-amount;
				cout<<"Bank Account of "<<BankMemberList[i].username<<"\n\n"
					<<"DESCRIPTION"<<endl
					<<"\tThe amount that has been withdraw\t\t\tRM"<<amount<<endl
					<<"\tBalance in your account\t\t\t\t\tRM"<<BankMemberList[i].balance<<endl;	
				fout<<BankMemberList[i].username<<" "<<BankMemberList[i].password<<" "<<BankMemberList[i].balance<<endl;
					break;						
			}
			else
			{
				cout<<"********INSUFFICIENT BALANCE!********\n";
				start();
			}
		}
		i++;
	}
	fin.close();
	fout.close();
}






