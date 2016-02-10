//# HHCreations
//simple Book_Store_Program with Output Files generations
#include<iostream>										//Header_Files
#include<stdlib.h>
#include <termios.h>
#include<unistd.h>
#include <cstdlib>
#include<string.h>
#include<fstream>
#include <stdlib.h>
using namespace std;
class book											//Class book
{
	public:
		string auth[50],title[50],pub[50],edit[50],buffername[50],employ[50];
		int price[50],stock[50],data=1,cnt[50],i,n,h,copy,bill,sc,els,addstock,tsale=0,counter=1,bufferprice[50],bufferrate[50],buffercopy[50],cop,salecounter;
	book()
	{
		for(i=1;i<51;i++)
		{
			cnt[i]=i;
		}
	}
	void get()										//Book_Entry
	{
		system("clear");
		cout<<"\nEnter the number of book entries you'd like to have::\n\t";
		cin>>n;
		for(i=1;i<=n;i++)
		{
			cout<<"\nEnter the Title_Name for book ::"<<i<<"\n";
			cin>>title[data];
			for(i=0;i<data;i++)
			{
				if(title[data].compare(title[i])==0)
					{
						cop=1;
					}
				else
					{
						cop=0;
					}
			}
			if(cop==1)
			{
				cout<<"Book_Named_"<<title[data]<<"_Already_Available\nEnter 1 to Edit_Stock\tor\n0 to Redirect_To_Home";	
				cin>>els;
				if(els==1)
				{
		cout<<"--------------------------------------------------------------------------------";
				cout<<"\nIndex::"<<cnt[i-1];
				cout<<"\nAuthor_Name:: "<<auth[i-1];
				cout<<"\nTitle_Name:: \t\t\t"<<title[i-1];
				cout<<"\nPublisher_Name:: "<<pub[i-1];
				cout<<"\nPrice:: "<<price[i-1]<<" $";
				cout<<"\nStock:: "<<stock[i-1];if(stock[i-1]<=10){cout<<"\t\t-Low_Stock_Detected-\n";}else{cout<<"\t\t-High_Stock_Detected-\n";}
				cout<<"--------------------------------------------------------------------------------";
				cout<<"\n\nEnter the Stock to fill up::\n";
				cin>>addstock;
				stock[i-1]=stock[i-1]+addstock;
				cout<<"Stock_Added_Successfully!!\nEnter 1 to continue::\t";cin>>els;
				 
					break;
				}
				else{break;}
			}
			cout<<"\nEnter the Author_Name for book ::"<<i<<"\n";
			cin>>auth[data];
			cout<<"\nEnter the Publisher_Name for book ::"<<i<<"\n";
			cin>>pub[data];
			cout<<"\nEnter the Price for book ::"<<i<<"\n";
			cin>>price[data];
			cout<<"\nEnter the Stock for book ::"<<i<<"\n";
			cin>>stock[data];
			data++; 
		}
	}
	void dispall()											//Book_Register
	{
		if(data==1)
		{
			cout<<"Nill_Entries_Found!!\n\npress 1 to continue:: \n";
			//cin>>els;
		}
		else
		{
			system("clear");
			cout<<"\nBooks_RECORD\n";
			for(i=1;i<data;i++)
			{	
				cout<<"--------------------------------------------------------------------------------";
				cout<<"\nIndex::"<<cnt[i];
				cout<<"\nTitle_Name:: \t\t\t"<<title[i];
				cout<<"\nAuthor_Name:: "<<auth[i];
				cout<<"\nPublisher_Name:: "<<pub[i];
				cout<<"\nPrice:: "<<price[i]<<" $";
				cout<<"\nStock:: "<<stock[i];if(stock[i]<=10){cout<<"\t\t-Low_Stock_Detected-\n";}else{cout<<"\t\t-High_Stock_Detected-\n";}
				cout<<"--------------------------------------------------------------------------------\n";
			}
			cout<<"\n\nEnter 1 to continue::\n";
		}
	}
	void edits()										//Book_Edit
	{
		system("clear");
		cout<<"\nEnter the book name you want to edit::";
		cin>>edit[1];
		for(i=1;i<data;i++)
		{
			if(edit[1].compare(title[i]) == 0)
			{
				cout<<"--------------------------------------------------------------------------------";
				cout<<"\nIndex::"<<cnt[i];
				cout<<"\nTitle_Name:: \t\t\t"<<title[i];
				cout<<"\nAuthor_Name:: "<<auth[i];
				cout<<"\nPublisher_Name:: "<<pub[i];
				cout<<"\nPrice:: "<<price[i];
				cout<<"\nStock:: "<<stock[i];if(stock[i]<=10){cout<<"\t\t-Low_Stock_Detected-\n";}else{cout<<"\t\t-High_Stock_Detected-\n";}
				cout<<"--------------------------------------------------------------------------------";
				cout<<"\nEnter the Title_Name::\n";
				cin>>title[i];
				cout<<"\n\nEnter the Author_Name::\n";
				cin>>auth[i];
				cout<<"\nEnter the Publisher_Name::\n";
				cin>>pub[i];
				cout<<"\nEnter the Price::\n";
				cin>>price[i]; 
							
			}
			else if(edit[1].compare(title[i]) != 0)
			{
				system("clear");cout<<"Book_Named_"<<edit[1]<<"_Not_Available";cin>>els; 
			}
		}
	}
void Hide()
{
    termios tty;

    tcgetattr(STDIN_FILENO, &tty);

    /* we want to disable echo */
    tty.c_lflag &= ~ECHO;

    tcsetattr(STDIN_FILENO, TCSANOW, &tty);
}
void Show()
{
   termios tty;

    tcgetattr(STDIN_FILENO, &tty);

    /* we want to reenable echo */
    tty.c_lflag |= ECHO;

    tcsetattr(STDIN_FILENO, TCSANOW, &tty);
}
	void sedits()										//stock edit
	{
		system("clear");
		cout<<"\nEnter the book name you want to edit stock::";
		cin>>edit[1];
		for(i=1;i<data;i++)
		{
			if(edit[1].compare(title[i]) == 0)
			{
				cout<<"--------------------------------------------------------------------------------";
				cout<<"\nIndex::"<<cnt[i];
				cout<<"\nTitle_Name:: \t\t\t"<<title[i];
				cout<<"\nAuthor_Name:: "<<auth[i];
				cout<<"\nPublisher_Name:: "<<pub[i];
				cout<<"\nPrice:: "<<price[i]<<" $";
				cout<<"\nStock:: "<<stock[i];if(stock[i]<=10){cout<<"\t\t-Low_Stock_Detected-\n";}else{cout<<"\t\t-High_Stock_Detected-\n";}
				cout<<"--------------------------------------------------------------------------------";
				
				cout<<"\n\nEnter the Stock to fill up::\n";
				cin>>addstock;
				stock[i]=stock[i]+addstock;
				cout<<"Stock_Added_Successfully!!\nEnter 1 to continue::\t";cin>>els;	 	
			}
			if(edit[1].compare(title[i]) != 0)
			{
				system("clear");cout<<"Book_Named_"<<edit[1]<<"_Not_Available\nEnter 1 to continue";cin>>els; 
			}
		}
	}
	void sale()												//sales_service
	{
		system("clear");
		cout<<"\nEnter the book name you want to sell::";
		cin>>edit[1];
		for(i=1;i<=data;i++)
		{
			if(edit[1].compare(title[i]) == 0)
			{
				cout<<"--------------------------------------------------------------------------------";
				cout<<"\nIndex::"<<cnt[i];
				cout<<"\nTitle_Name:: \t\t\t"<<title[i];
				cout<<"\nAuthor_Name:: "<<auth[i];
				cout<<"\nPublisher_Name:: "<<pub[i];
				cout<<"\nPrice:: "<<price[i]<<" $";
				cout<<"\nStock:: "<<stock[i]<<"\n";
				cout<<"--------------------------------------------------------------------------------";
				cout<<"\n\n\nEnter the number of copies you want to sell:: ";
				cin>>copy; 
				if(copy>stock[i])
				{
					cout<<"Number_of_Copies_Unavailable!\nRefill_Stock!\n\nPress 1 to continue::\n";cin>>els;break; 
				}
				else
				{
					bill=copy*price[i];					
					cout<<"\nTotal_Bill:: "<<bill;
					tsale=bill+tsale;		
					buffername[counter]=title[i];
					bufferprice[counter]=tsale;
					bufferrate[counter]=price[i];
					buffercopy[counter]=copy;
					cout<<"\nSale_confirm:: (1/0)";
					cin>>sc; 
					if(sc==1)
					{
						salecounter=1;
						stock[i]=stock[i]-copy;
						cout<<"Enter Employee_Sign::\t\t";cin>>employ[counter];
						counter++;
						cout<<":::::::Sale_Successful:::::::\n\n::Thank_You_For_purchasing_From_HHCbook_Stores::\n\n::Visit_Again::\n\nEnter 1 to continue::\n";cin>>els;break; 
					}
					else
					{
						cout<<":::::::Sale_Unsuccessful::::::\n\nEnter 1 to continue::\n";cin>>els;break;
					}
				}
			}
			else
			{
				cout<<"Book Named "<<edit[1]<<" Not_Available!\nEnter 1 to Continue:: ";;
				cin>>els;break;
			}
		}
	}
	void totalsale()										//Total sale
	{	
		if(salecounter==0)
		{
			cout<<"No_Transactions_Performed\n"; 
		}
		else
		{
			system("clear");
			cout<<"Total_Sale:: "<<tsale<<" $\n\n\n";
			for(i=1;i<counter;i++)
			{	
				cout<<"\n--------------------------------------------------------------------------------";
				cout<<"\nBook_Title::\t\t"<<buffername[i]<<"\nBook_Rate::\t"<<bufferrate[i]<<"\nCopies::\t"<<buffercopy[i]<<"\nTotal::\t\t\t"<<bufferprice[i]<<"$\n"<<"Employee_Sign::\t\t"<<employ[i]<<"\n";
				cout<<"--------------------------------------------------------------------------------\n"; 
			}
		}
	}
void Rfileout()											// Register File out
	{	
		ofstream myfile ("Book_Store/Register.txt");
		myfile<<"\n-------------REGISTER_RECORD----------\n\n";
		for(i=1;i<data;i++)
		{
			myfile<<"\n";	
			myfile<<"--------------------------------------------------------------------------------";
			myfile<<"\nIndex::"<<cnt[i];
			myfile<<"\nAuthor_Name:: "<<auth[i];
			myfile<<"\nTitle_Name:: \t\t\t"<<title[i];
			myfile<<"\nPublisher_Name:: "<<pub[i];
			myfile<<"\nPrice:: "<<price[i]<<" $";
			myfile<<"\nStock:: "<<stock[i];if(stock[i]<=10){myfile<<"\t\t-Low_Stock_Detected-\n";}else{myfile<<"\t\t-High_Stock_Detected-\n";}
			myfile<<"--------------------------------------------------------------------------------\n"; 
		}
	myfile.close();
	}
void Sfileout()											//Sales File out
	{
		ofstream myfile ("Book_Store/Sales.txt");
		myfile<<"\n-------------SALES_RECORD-----------------\n\n";
		for(i=1;i<counter;i++)
		{
			
			myfile<<"\n--------------------------------------------------------------------------------";
				myfile<<"\nBook_Title::\t\t"<<buffername[i]<<"\nBook_Rate::\t"<<bufferrate[i]<<"\nCopies::\t"<<buffercopy[i]<<"\nTotal::\t\t\t"<<bufferprice[i]<<"$\n"<<"Employee_Sign::\t\t"<<employ[i]<<"\n";
				myfile<<"--------------------------------------------------------------------------------\n";
		} 
	myfile.close();
	}
void Rhfilein()										//Load hidden register
{
	std::ifstream myfile (".sys.txt");
	myfile >> data;
	for (int i = 1; i <data ; i++) 
	{
		myfile >> auth[i];
		myfile >> title[i];
		myfile >> pub[i];
        	myfile >> price[i];
		myfile >> stock[i];		
	}
	myfile.close();
}
void Rhfileout()									//write hidden register
{	
	std::ofstream myfile(".sys.txt");
	myfile<<data<<"\n";
	for(i=1;i<data;i++)
		{
			myfile<<auth[i]<<"\n";
			myfile<<title[i]<<"\n";
			myfile<<pub[i]<<"\n";
			myfile<<price[i]<<"\n";
			myfile<<stock[i]<<"\n";
		}
	myfile.close();
	system("clear");
}
void Shfileout()									//write hidden sales
{
	
	std::ofstream myfile(".syss.txt");
	myfile<<counter<<"\n";
	myfile<<tsale<<"\n";
	for(i=1;i<counter;i++)
		{
			myfile<<buffername[i]<<"\n"<<bufferrate[i]<<"\n"<<buffercopy[i]<<"\n"<<bufferprice[i]<<"\n"<<employ[i]<<"\n";
		}
	myfile.close();
}
void Shfilein()										//Load hidden sales
{
	std::ifstream myfile (".syss.txt");
	myfile>>counter;
	myfile>>tsale;
	for (int i = 1; i < counter ; i++) 
	{
		myfile >> buffername[i];
		myfile >> bufferrate[i];
		myfile >> buffercopy[i];
        	myfile >> bufferprice[i];
		myfile >> employ[i];
		
	}
	myfile.close();
}
void Reset()											//Format_And_Backup
{
	cout<<"Do_You_Want_To_Backup_And_Format_Data?(1/0)";
	cin>>els;
	if(els==1)
	{	
		system("mkdir .backup");system("clear");
		system("cp .sys.txt .backup");
		system("cp .syss.txt .backup");
		system("rm .sys.txt");
		system("rm .syss.txt");
	}
	else{cout<<"Formatting cancelled...\n";}
}
	void help()
		{
			system("clear");cout<<"This is a freeware App for Book Store Conviniency.\nDeveloper:Hatim Chathiwala\nYou can follow me at Google+ :  +HATIMCHATHIWALA\tor\nEmail_: Hatim.cathiwala@gmail.com\n\nEnjoy The Free Program\n\n";cin>>els;
		}
	
};		
int main()												//main
{
	system("mkdir Book_Store");
	int choice,x;
	string login[10],idlog[10],pass[10],passlog[10];
	idlog[1]="hatim";	passlog[1]="cool";
	idlog[2]="abbasali";	passlog[2]="abbasali";
	idlog[3]="admin";	passlog[3]="admin";
	book a;
	a.Rhfilein();
	a.Shfilein();
	system("clear");
	cout<<"\t::WELCOME TO HHC_Book_Store::\t\t\n\n";
	cout<<"Enter_Your_Login_Id::\t";
	cin>>login[1];
	cout<<"Enter_Your_Password::\t";a.Hide();
	cin>>pass[1];a.Show();
for(x=1;x<4;x++)
{
if(login[1].compare(idlog[x])==0)
{ if(pass[1].compare(passlog[x])==0)
   {	
	while(choice!=11)
	{
		if(choice!=11)
		{
			system("clear");
			cout<<"\t::WELCOME TO HHC_Book_Store::\t\t"<<"Employee_Name:: "<<idlog[x]<<"\n\n";
			cout<<"\n1)Book_Entry\t\t\t2)Book_Edit\n\n3)Book_Register\t\t\t4)Total_Sales\n\n5)Fill_Stock\t\t\t6)Sale_Services\n\n7)Register_File_Out\t\t8)Sales_File_Out\n\n9)Settings\t\t\t10)About_App\n\n\t\t11)Save_And_Logout\n\nYour_choice::  ";
			cin>>choice;
			switch(choice)
			{
				case 1:	a.get();break;
				case 2: a.edits();break;
				case 3: a.dispall();cin>>x;break;
				case 4: system("clear");a.totalsale();cout<<"\n\nEnter 1 to Continue";cin>>x;break;
				case 5:	a.sedits();break;
				case 6: a.sale();break;
				case 7: system("clear");cout<<"Processing...";sleep(2);a.Rfileout();cout<<"Do_You_Want_To_Open_Register_file?(1/0))";cin>>x;if(x==1){system("gedit Book_Store/Register.txt");} break;
				case 8: system("clear");cout<<"Processing...";sleep(2);a.Sfileout();cout<<"Do_You_Want_To_Open_Register_file?(1/0))";cin>>x;if(x==1){system("gedit Book_Store/Sales.txt");} break;
				case 9:	system("clear");
					cout<<"\n1)Restar_Program\t\t2)Reset_program\t\t3)Back\n";
					cin>>x;
					switch(x)
					{
						case 1:system("g++ book.cpp");sleep(2);system("./a.out");break;
						case 2:a.Reset();choice=11;break;
						case 3:break;
					}
					break;
				case 10:a.help();break;
				case 11: cout<<"Saving_Register_file...\nEnter 1 to continue..";a.Rhfileout();a.Shfileout();cin>>x;break;
				
	
			}
		}
		else 
		{
			break;
		}
	}
}else{cout<<"Invalid_Login_Id or Password\n\n";}
}//else{cout<<"Invalid_Login_Id or Password\n\n";}
	
}
}
