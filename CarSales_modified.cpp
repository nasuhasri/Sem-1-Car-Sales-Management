#include <iostream>
#include <string.h>
#include <windows.h>
using namespace std;
void table ();
void extraAcc ();
double calcAcc(char, double&);
double priceCars(char*);
double pCars(int);
double calcNet ();
void payment(char*, int&, double&, double&);

int main()
{
	system ("color B0");
	char type[11], name[31], choice, Access, passw[11], answer;
	int user, cars;
	double price, priceComm, tPrice, priceAcc, netProfit, totalprice=0, totalComm, net, rev, exp;
	
	
	cout << "Press any key to start or 'N' to exit: ";
	cin >> answer;
	Sleep(100);
	system ("cls");
	
	while (answer!='N')
	{
		cout << "\n\n\n\n\n\n\n\n\n\t\t\t                          User Type\n\n\n";
		cout << "                                            1. Admin\n                                            2. User\n\n";
		cout << "                                           Option: ";
		cin >> user;
		Sleep(200);
		system ("cls");
		
		//cout << "*************************************************************************************************************\n";
		if(user==1)
		{
			cout << endl << endl;
			cout << "Hello admin!\n";
			cin.ignore();
			cout << "Password: ";
			cin.getline(passw,10);
			cout << endl;
			
			if (strcmpi(passw,"Admin00")==0)
			{
				cout << "Hi admin.\n";
				totalComm = 0.03*totalprice;
				cout << "Commision received (RM) : " << totalComm << endl ;
				cout << "Total car sales: RM " << totalprice << endl;
				net = calcNet () ;
			}
			
			else
		   		cout << "INVALID PASSWORD !\n" ;
			
		}
	
		else if(user ==2)
		{
			table ();
			extraAcc ();
			cout << endl;
			
			cin.ignore();
			cout << "Customer's Name: ";
			cin.getline(name,30);
			cout << "Type Of Car [Manual/Auto]: ";
			cin.getline(type,10);
			
			if (strcmpi(type,"manual")==0)
			{
				cout << "Name Of Car [Manual:1/2/3 or Auto:4/5]: ";
				cin >> cars;
			
				if (cars==1)
					price=170000;
		
				else if (cars==2)
					price=150000;
		
				else if (cars==3)
					price=190000;
					
				else
				{
					cout << "Invalid code!!\n";
					cout << "Name Of Car [Manual:1/2/3 or Auto:4/5]: ";
					cin >> cars;
					price=pCars(cars);
				}
			}
			
			else if (strcmpi(type,"auto")==0)
			{
				cout << "Name Of Car [Manual:1/2/3 or Auto:4/5]: ";
				cin >> cars;
			
				if (cars==4)
					price=150000;
		
				else if (cars==5)
					price=180000;
				
				else
				{
					cout << "Invalid code!!\n";
					cout << "Name Of Car [Manual:1/2/3 or Auto:4/5]: ";
					cin >> cars;
					price=pCars(cars);
				}
			}
			
			else 
			{
				cout << "Invalid code!!\n";
				cout << "Type Of Car [Manual/Auto]: ";
				cin.getline(type,10);
				price = priceCars(type);
			}
			
			cout << "Accessories [Enter the code A/F/S/C]: ";
			cin >> Access;
			calcAcc(Access, priceAcc);
			Sleep(200);
			system ("cls");
			payment(name, cars, priceAcc, tPrice);
			
			totalprice = totalprice + tPrice;
		}
		
		cout << "\n\n\n";
		cout << "Press any key to continue or 'N' to exit: ";
		cin >> answer;
		system ("cls");
	}
	
		cout << "***************************Thank you! Please come again :)*************************\n";
	
	return 0;
}

void table ()
{
	cout << "                                             AUTO PERFECT HOLDING SDN BHD" << endl;
	cout << "                                 Lot 123, Jalan Permata 1/10 Taman Muzaffar Height, 75050 Melaka.\n";
	cout << endl;
	cout << "                                            Welcome To Our Paradise Of Car!" << endl; 
	
	cout << "                                  __________________________________________________________\n";
	cout << "                                 |  Type Of Car     |  Name Of Car          |  Price        |" << endl;
	cout << "                                 |==========================================================|\n";
	cout << "                                 |Manual            |1.Audi R8              |  RM 170K      |" << endl;
	cout << "                                 |                  |2.Aston Martin Vantage |  RM 150K      |" << endl;
	cout << "                                 |                  |3.Lamborghini Aventador|  RM 190K      |" << endl;
	cout << "                                 |==========================================================|\n";
	cout << "                                 |Auto              |4.Ferrari 458 Italia   |  RM 150K      |" << endl;
	cout << "                                 |                  |5.Bugatti Veyron       |  RM 180K      |" << endl;
	cout << "                                 |__________________________________________________________|\n\n\n";
}

void extraAcc()
{
	cout << "                                     Extra Accessories For Your Super Convenient Car ^_^\n";
	cout << "                              _________________________________________________________\n";
	cout << "                             |  Accessories        |     Code       |    Price         |" << endl;
	cout << "                             |=========================================================|\n";
	cout << "                             |Alarm                |      A         |    RM 200        |" << endl;
	cout << "                             |Floor Mats           |      F         |    RM 120        |" << endl;
	cout << "                             |Speaker              |      S         |    RM 80         |" << endl;
	cout << "                             |Seat Covers          |      C         |    RM 100        |" << endl;
	cout << "                             |_________________________________________________________|\n\n";
	cout << "                              P/s: Enter 'X' if you do not want any accessories." << endl;
}

double calcAcc (char Access, double& priceAcc)
{	
	if(Access=='A' || Access=='a')
		priceAcc=200;
	else if (Access=='F' || Access=='f')
		priceAcc=120;
	else if(Access=='S' || Access=='s')
		priceAcc=80;
	else if(Access=='C' || Access=='c')
		priceAcc=100;
	else if (Access=='X' || Access=='x')
		priceAcc=0;
	else
		priceAcc=0;
	
	//return priceAcc;
}

double priceCars(char* type)
{
	double price;
	int cars;
	
	if (strcmpi(type,"manual")==0)
			{
				cout << "Name Of Car [Manual:1/2/3 or Auto:4/5]: ";
				cin >> cars;
			
				if (cars==1)
					price=170000;
		
				else if (cars==2)
					price=150000;
		
				else if (cars==3)
					price=190000;
				
				else
					price=0;
			}
			
	else if (strcmpi(type,"auto")==0)
			{
				cout << "Name Of Car [Manual:1/2/3 or Auto:4/5]: ";
				cin >> cars;
			
				if (cars==4)
					price=150000;
		
				else if (cars==5)
					price=180000;
				
				else
					price=0;
			}
			
	return price;
}

double pCars(int cars)
{
	double price;
			
	if (cars==1)
		price=170000;
		
	else if (cars==2)
		price=150000;
		
	else if (cars==3)
		price=190000;
					
	else if (cars==4)
		price=150000;
		
	else if (cars==5)
		price=180000;
	
	else
		price=0;
		
	return price;
}

double calcNet ()
{
	double net ;
	char month[15] , key ;
	int rev, exp, num,gross ;

	cout << "Enter any key to start calculate MONTHLY net profit/loss or 'N' to exit : " ;
	cin >> key ;
	
	while (key != 'N')
	{
		cout << "Month : " ;
		cin.ignore() ;
		cin.getline(month,14) ;
		
		cout << "Enter [ PROFIT = 1 / LOSS = 0 ] : " ;
		cin >> num ;
		
			if ( num == 1 )
			{
				cout << "Gross profit (RM) : " ;
				cin >> gross ;
			}
			else if ( num == 0)
			{
				cout << "Gross loss (RM) [Example: -20000] : " ;
				cin >> gross ;
			}
	
		cout << "Total revenues (RM) : " ;
		cin >> rev ;
		cout << "Total expenses (RM) : " ;
		cin >> exp ;
		net = gross + rev - exp ;
		cout << endl << endl ;
			
			if (net > 0)
			{
				cout << "NET PROFIT : " << "RM " << net ;
				cout << endl << endl;	
			}
			else if ( net < 0)
			{
				cout << "NET LOSS : " << "RM " << net ;
				cout << endl << endl ;
			}
	
		cout << "Enter any key to continue calculate MONTHLY net profit/loss or 'N' to exit : " ;
		cin >> key ;
		cout << "________________________________________________________________________" << endl << endl ;
	}
	
	cout << "Enter any key to start calculate YEARLY net profit/loss and 'N' to exit : " ;
	cin >> key ;
	
	while (key != 'N')
	{
		cout << "Enter [ PROFIT = 1 / LOSS = 0 ] : " ;
		cin >> num ;
		
		if ( num == 1 )
		{
			cout << "Gross profit (RM) : " ;
			cin >> gross ;
		}
		else if ( num == 0)
		{
			cout << "Gross loss (RM) [Example: -20000] : " ;
			cin >> gross ;
		}
	
		cout << "Total revenues (RM) : " ;
		cin >> rev ;
		cout << "Total expenses (RM) : " ;
		cin >> exp ;
		net = gross + rev - exp ;
		cout << endl << endl ;
			
			if (net > 0)
			{
				cout << "NET PROFIT : " << "RM " << net ;
				cout << endl << endl;	
			}
			else if ( net < 0)
			{
				cout << "NET LOSS : " << "RM " << net ;
				cout << endl << endl ;
			}
		
		cout << "Enter any key to continue calculate YEARLY net profit/loss or 'N' to exit : " ;
		cin >> key ;
		cout << "____________________________________________________________________" << endl ;	
	}
	return net ;
}

void payment(char*name, int&cars, double&priceAcc, double&tPrice )
{
	double price;
	cout << "*****************************************\n";
	cout << "                 Payment Info\n";
	cout << "*****************************************\n\n";
	
	cout << "Customer's name: " << name << endl;
	if (cars==1)
	{
		cout << "Car purchase: Audi R8" << endl;
		price=170000;
	}	
	else if (cars==2)
	{
		cout << "Car purchase: Aston Martin Vantage" << endl;
		price=150000;
	}
	else if (cars==3)
	{
		cout << "Car purchase: Lamborghini Aventador" << endl;
		price=190000;
	}			
	else if (cars==4)
	{
		cout << "Car purchase: Ferrari 458 Italia"<< endl;
		price=150000;
	}	
	else if (cars==5)
	{
		cout << "Car purchase: Bugatti Veyron" << endl;
		price=180000;
	}
	else price=0;
		
	cout << "Cost of car: RM " << price << endl;
	cout << "Cost of accessories: RM " << priceAcc << endl;
	tPrice=priceAcc+price;
	cout << "Total price of car including extra accessories: RM " << tPrice << endl;
}

		


