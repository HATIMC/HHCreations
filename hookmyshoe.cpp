#include<iostream>										//Header_Files
#include<stdlib.h>
#include <termios.h>
#include<unistd.h>
#include <cstdlib>
#include<string.h>
#include<fstream>
#include <stdlib.h>
using namespace std;										//STD NAMESPACE
class bms											//CLASS 1
{
	public:											//ACCESS
	string movie[5],actor[5],actress[5],name,timings[5],newpass,newusername,un;					//DECLARATION
	int p1seats[50],g1seats[50],s1seats[50],s3seat[50],i,p2seats[50],g2seats[50],s2seats[50],p3seats[50],g3seats[50],s3seats[50],choice,rate[50][50],j,srate,grate,prate,choice1,CustSeat[50],SeatCount,cost,choice2,quit,data,screen,ratings[5],Myway,yeah;
	bms()											//CONSTRUCTOR-AUTO VALUES
	{	
		data=1;	
		
	}
void foo()
{for(i=1;i<=50;i++)
		{
			p1seats[i]=g1seats[i]=s1seats[i]=i;
			p2seats[i]=g2seats[i]=s2seats[i]=i;
			p3seats[i]=g3seats[i]=s3seats[i]=i;
			CustSeat[i]=0;
		}
	sfileout();
}
void shfilein()										//Load hidden sales
{
	std::ifstream myfile (".movies.txt");
	//myfile>>counter;
	//myfile>>tsale;
	for (int i = 1; i <=3 ; i++) 
	{
		myfile >> movie[i];
		myfile >> actor[i];
		myfile >> actress[i];
        	myfile >> timings[i];
		myfile >> ratings[i];
		
	}
	myfile.close();
}
void shfileout()									//write hidden movies
{
	
	std::ofstream myfile(".movies.txt");
	//myfile<<3<<"\n";
	//myfile<<tsale<<"\n";
	for(i=1;i<=3;i++)
		{
			myfile<<movie[i]<<"\n"<<actor[i]<<"\n"<<actress[i]<<"\n"<<timings[i]<<"\n"<<ratings[i]<<"\n";
		}
	myfile.close();
}
void sfileout()									//write hidden seats
{
	
	std::ofstream myfile(".seats.txt");
	//myfile<<3<<"\n";
	//myfile<<tsale<<"\n";
	for(i=1;i<=50;i++)
		{
			myfile<<s1seats[i]<<"\n"<<s2seats[i]<<"\n"<<s3seats[i]<<"\n"<<g1seats[i]<<"\n"<<g2seats[i]<<"\n"<<g3seats[i]<<"\n"<<p1seats[i]<<"\n"<<p2seats[i]<<"\n"<<p3seats[i]<<"\n";
		}
	myfile.close();
}
void Sfilein()										//Load hidden sales
{
	std::ifstream myfile (".seats.txt");
	for (int i = 1; i < 51 ; i++) 
	{
		myfile >> s1seats[i];
		myfile >> s2seats[i];
		myfile >> s3seats[i];
        	myfile >> g1seats[i];
		myfile >> g2seats[i];
		myfile>>g3seats[i];
		myfile>>p1seats[i];
		myfile>>p2seats[i];
		myfile>>p3seats[i];		
	}
	myfile.close();
}
void Hide()											//HIDE KEYBOARD ECHO
{
    termios tty;
    tcgetattr(STDIN_FILENO, &tty);
    /* we want to disable echo */
    tty.c_lflag &= ~ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &tty);
}
void Show()											//SHOW KEYBOARD ECHO
{
   termios tty;
    tcgetattr(STDIN_FILENO, &tty);
    /* we want to reenable echo */
    tty.c_lflag |= ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &tty);
}	
	void getrate()										//GET RATES FOR SCREENS
	{system("clear");
	cout<<"\nEnter rate for Silver class  ";cin>>bms::srate;
	cout<<"Enter rate for Gold class  ";cin>>bms::grate;
	cout<<"Enter rate for Platinum class  ";cin>>bms::prate;
	}
void disprate()											//DISPLAY RATE FOR SCREENS
	{	
std::ifstream myfile (".rates.txt");
	
		myfile >> srate;
		myfile >> grate;
		myfile >> prate;
	myfile.close();
		system("clear");
		cout<<"\nRate for silver: "<<srate;
		cout<<"\nRate for Gold: "<<grate;
		cout<<"\nRate for Platinum: "<<prate;
		cout<<"\n\nDo you want to Edit?(1/0)";
		cin>>quit;
		if(quit==1)
		{	
			system("clear");
			cout<<"\nEnter rate for Silver class";cin>>srate;
			cout<<"Enter rate for Gold class";cin>>grate;
			cout<<"Enter rate for Platinum class";cin>>prate;
		std::ofstream myfile(".rates.txt");
				myfile<<srate<<"\n"<<grate<<"\n"<<prate;
				myfile.close();
		}
		else{system("beep");system("sleep 1");system("beep");}
	}
	void getMovie()										//ADMINISTRATION ADD MOVIES
	{
		cout<<"\n\nEnter Movie Details: \n";
		for(i=1;i<4;i++)
		{		
			cout<<"\n\nFor Screen "<<i<<endl<<endl;
			cout<<"Enter Movie: ";
			cin>>movie[i];
			cout<<"Enter Actor: ";
			cin>>actor[i];
			cout<<"Enter Actress: ";
			cin>>actress[i];
			cout<<"Enter Timings: ";
			cin>>timings[i];
			cout<<"Enter Likes: ";
			cin>>ratings[i];		
		}
		shfileout();
	}
	void editMovie()									//ADMINISTRATION EDIT MOVIES
	{
		for(i=1;i<4;i++)
		{
			cout<<"\n\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
			cout<<"Movie:"<<movie[i];
			cout<<"\nActor:"<<actor[i];
			cout<<"\nActress"<<actress[i];
			cout<<"\nTIME:"<<timings[i];cout<<endl;
			cout<<"Screen: "<<i;
			cout<<"\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n";
		}
		cout<<"\n\nEnter Screen_Number\n";
		cin>>screen;
			cout<<"For Screen "<<screen<<endl<<endl;
			cout<<"Enter Movie: ";
			cin>>movie[screen];
			cout<<"Enter Actor: ";
			cin>>actor[screen];
			cout<<"Enter Actress: ";
			cin>>actress[screen];
			cout<<"Enter Timings: ";
			cin>>timings[screen];
			cout<<"Enter Likes: ";
			cin>>ratings[screen];
			shfileout();
	}
	void dispMovie()									//BANNERS FOR MOVIES
	{
		for(i=1;i<4;i++)
		{
			cout<<"\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
			cout<<"Movie:"<<movie[i];
			cout<<"\nActor:"<<actor[i];
			cout<<"\nActress:"<<actress[i];
			cout<<"\nTIME:"<<timings[i];cout<<endl;
			cout<<"Screen: "<<i;
			cout<<"\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
		}
	}
	void dispSeat(int)									//SEAT ARRANGEMENTS FOR SCREEN1
	{
		cout<<"\t\t\tSCREEN\n";
		cout<<"\n\n1.Silver section\n";
		for(i=1;i<51;i++)
		{
			cout<<s1seats[i]<<"\t";
			if((s1seats[i]%10)==0&&s1seats[i]!=0)
			{
				cout<<"\n";
			}
		}
		cout<<"\n\n2.Gold section\n";
		for(i=1;i<51;i++)
		{
			cout<<g1seats[i]<<"\t";
			if((g1seats[i]%10)==0&&g1seats[i]!=0)
			{
				cout<<"\n";
			}
		}
		cout<<"\n\n3.Platinum section\n";
		for(i=1;i<51;i++)
		{
			cout<<p1seats[i]<<"\t";
			if((p1seats[i]%10)==0&&p1seats[i]!=0)
			{
				cout<<"\n";
			}
		}	
	}
		void dispSeat(double)								//SEAT ARRANGEMENTS FOR SCREEN2
	{
		cout<<"\t\t\tSCREEN\n";
		cout<<"\n\n1.Silver section\n";
		for(i=1;i<51;i++)
		{
			cout<<s2seats[i]<<"\t";
			if((s2seats[i]%10)==0&&s2seats[i]!=0)
			{
				cout<<"\n";
			}
		}
		cout<<"\n\n2.Gold section\n";
		for(i=1;i<51;i++)
		{
			cout<<g2seats[i]<<"\t";
			if((g2seats[i]%10)==0&&g2seats[i]!=0)
			{
				cout<<"\n";
			}
		}
		cout<<"\n\n3.Platinum section\n";
		for(i=1;i<51;i++)
		{
			cout<<p2seats[i]<<"\t";
			if((p2seats[i]%10)==0&&p2seats[i]!=0)
			{
				cout<<"\n";
			}
		}
	}
	void dispSeat()										//SEATS ARRANGEMENT FOR SCREEN3
	{
		cout<<"\t\t\tSCREEN\n";
		cout<<"\n\n1.Silver section\n";
		for(i=1;i<51;i++)
		{
			cout<<s3seats[i]<<"\t";
			if((s3seats[i]%10)==0&&s3seats[i]!=0)
			{
				cout<<"\n";
			}
		}
		cout<<"\n\n2.Gold section\n";
		for(i=1;i<51;i++)
		{
			cout<<g3seats[i]<<"\t";
			if((g3seats[i]%10)==0&&g3seats[i]!=0)
			{
				cout<<"\n";
			}
		}
		cout<<"\n\n3.Platinum section\n";
		for(i=1;i<51;i++)
		{
			cout<<p3seats[i]<<"\t";	
			if((p3seats[i]%10)==0&&p3seats[i]!=0)
			{
				cout<<"\n";
			}
		}
	}
	void sale()										//ADMINISTRATION SALES PURPOSES
	{
		dispMovie();
		cout<<"Enter Screen Number";
		cin>>choice1;
		system("clear");
		cout<<"\n\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
			cout<<"Movie:"<<movie[choice1];
			cout<<"\nActor:"<<actor[choice1];
			cout<<"\nActress:"<<actress[choice1];
			cout<<"\nTIME:"<<timings[choice1];cout<<endl;
			cout<<"Screen: "<<choice1;
			cout<<"\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n";	
		switch(choice1)
		{
			case 1:	dispSeat(1);break;
			case 2: dispSeat(1.0);break;
			case 3: dispSeat();break;
			default:system("beep");system("sleep 1");system("beep");break;
		}
		cout<<"\nenter choice ";cin>>choice2;
		switch(choice2)
		{
			case 1:	if(choice1==1)						//CASE FOR SCREEN 1
				{
					cout<<"How many seats you want?";cin>>SeatCount;
					for(i=1;i<=SeatCount;i++)
					{if(SeatCount>50)
						{break;}
						cout<<"enter seat number";cin>>CustSeat[i];if(CustSeat[i]==0)
						{cout<<"Seat Already Booked";cin>>quit;}
					}
					for(i=1;i<=SeatCount;i++)
					{if(SeatCount>50)
						{break;}
						for(j=1;j<51;j++)
						{
							if(CustSeat[i]==s1seats[j])
							{
								s1seats[j]=0;
							}
						}
					}
				}sfileout();
				if(choice1==2)
				{
					cout<<"How many seats you want?";cin>>SeatCount;
					for(i=1;i<=SeatCount;i++)
					{if(SeatCount>50)
						{break;}
						cout<<"enter seat number";cin>>CustSeat[i];if(CustSeat[i]==0)
						{cout<<"Seat Already Booked";cin>>quit;}
					}
					for(i=1;i<=SeatCount;i++)
					{if(SeatCount>50)
						{break;}
						for(j=0;j<50;j++)
						{
							if(CustSeat[i]==s2seats[j])
							{
								s2seats[j]=0;
							}
						}
					}
				}sfileout();
				if(choice1==3)
				{
					cout<<"How many seats you want?";cin>>SeatCount;
					for(i=1;i<=SeatCount;i++)
					{if(SeatCount>50)
						{break;}
						cout<<"enter seat number";cin>>CustSeat[i];if(CustSeat[i]==0)
						{cout<<"Seat Already Booked";cin>>quit;}
					}
					for(i=1;i<=SeatCount;i++)
					{if(SeatCount>50)
						{break;}
						for(j=1;j<51;j++)
						{
							if(CustSeat[i]==s3seats[j])
							{
								s3seats[j]=0;
							}
						}
					}
				
				}cout<<"\nenter customer name:\n";cin>>name;
		system("clear");
		cout<<"\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
		cout<<"\nName: ";cout<<name<<"\t\t\tHookMyShoe";
		cout<<"\nMovie Name:  "; cout<<movie[choice1]<<endl;
		cout<<"TIME:"<<timings[choice1];cout<<endl;
		cout<<"class: ";
		if(choice2==1)
		{
		cout<<"Silver\n";
		}
		if(choice2==2)
		{
		cout<<"Gold\n";
		}
		if(choice2==3)
		{
		cout<<"Platinum\n";
		}
		cout<<"Seats: ";
		for(i=1;i<=SeatCount;i++)
		{

			{
				cout<<CustSeat[i]<<" ";
			}
		}
				cost=SeatCount*srate;
		cout<<"\nTotal Fare: ";cout<<cost;
		cout<<"\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";cin>>quit;sfileout();
	cout<<"\n\nPrint?<1/0>";cin>>yeah;
		if(yeah==1)
		{
		Rfileout();
		system("gedit Ticket ");	}			
		break;	
			case 2:	if(choice1==1)							//CASE FOR SCREEN 2
				{
					cout<<"How many seats you want?";cin>>SeatCount;
					for(i=1;i<=SeatCount;i++)
					{if(SeatCount>50)
						{break;}
						cout<<"enter seat number";cin>>CustSeat[i];
						if(CustSeat[i]==0)
						{cout<<"Seat Already Booked";cin>>quit;}
					}
					for(i=1;i<=SeatCount;i++)
					{if(SeatCount>50)
						{break;}
						for(j=1;j<51;j++)
						{
							if(CustSeat[i]==g1seats[j])
							{
								g1seats[j]=00;
							}
						}
					}
				}sfileout();
				if(choice1==2)
				{
					cout<<"How many seats you want?";cin>>SeatCount;
					for(i=1;i<=SeatCount;i++)
					{if(SeatCount>50)
						{break;}
						if(SeatCount>50)
						{break;}
						cout<<"enter seat number";cin>>CustSeat[i];
						if(CustSeat[i]==0)
						{cout<<"Seat Already Booked";cin>>quit;}
					}
					for(i=1;i<=SeatCount;i++)
					{if(SeatCount>50)
						{break;}
						for(j=0;j<50;j++)
						{
							if(CustSeat[i]==g2seats[j])
							{
								g2seats[j]=0;
							}
						}
					}
				}sfileout();
				if(choice1==3)
				{
					cout<<"How many seats you want?";cin>>SeatCount;
					for(i=1;i<=SeatCount;i++)
					{if(SeatCount>50)
						{break;}
						cout<<"enter seat number";cin>>CustSeat[i];if(CustSeat[i]==0)
						{cout<<"Seat Already Booked";cin>>quit;}
					}
					for(i=1;i<=SeatCount;i++)
					{if(SeatCount>50)
						{break;}
						for(j=1;j<51;j++)
						{
							if(CustSeat[i]==g3seats[j])
							{
								g3seats[j]=0;
							}
						}
					}
				}cout<<"\nenter customer name:\n";cin>>name;sfileout();
		system("clear");
		cout<<"\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
		cout<<"\nName: ";cout<<name<<"\t\t\tHookMyShoe";
		cout<<"\nMovie Name:  "; cout<<movie[choice1]<<endl;
		cout<<"TIME:"<<timings[choice1];cout<<endl;
		cout<<"class: ";
		if(choice2==1)
		{
		cout<<"Silver\n";
		}
		if(choice2==2)
		{
		cout<<"Gold\n";
		}
		if(choice2==3)
		{
		cout<<"Platinum\n";
		}
		cout<<"Seats: ";
		for(i=1;i<=SeatCount;i++)
		{

			{
				cout<<CustSeat[i]<<" ";
			}
		}
				cost=SeatCount*grate;
		cout<<"\nTotal Fare: ";cout<<cost;
		cout<<"\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";cin>>quit;
		cout<<"\n\nPrint?<1/0>";cin>>yeah;
		if(yeah==1)
		{
		Rfileout();
		system("gedit Ticket ");
		}
		break;
		default:system("beep");system("sleep 1");system("beep");break;
			case 3:	if(choice1==1)						//CASE FOR SCREEN 3
				{
					cout<<"How many seats you want?";cin>>SeatCount;
					for(i=1;i<=SeatCount;i++)
					{if(SeatCount>50)
						{break;}
						cout<<"Enter Seats";cin>>CustSeat[i];if(CustSeat[i]==0)
						{cout<<"Seat Already Booked";cin>>quit;}
					}
					for(i=1;i<=SeatCount;i++)
					{if(SeatCount>50)
						{break;}
						for(j=1;j<51;j++)
						{
							if(CustSeat[i]==p1seats[j])
							{
								p1seats[j]=0;
							}
						}
					}
				}sfileout();
				if(choice1==2)
				{
					cout<<"How many seats you want?";cin>>SeatCount;
					for(i=1;i<=SeatCount;i++)
					{if(SeatCount>50)
						{break;}
						cout<<"enter seat number";cin>>CustSeat[i];if(CustSeat[i]==0)
						{cout<<"Seat Already Booked";cin>>quit;}
					}
					for(i=1;i<=SeatCount;i++)
					{if(SeatCount>50)
						{break;}
						for(j=1;j<51;j++)
						{
							if(CustSeat[i]==p2seats[j])
							{
								p2seats[j]=0;
							}
						}
					}
				}sfileout();
				if(choice1==3)
				{
					cout<<"How many seats you want?";cin>>SeatCount;
					for(i=1;i<=SeatCount;i++)
					{if(SeatCount>50)
						{break;}
						cout<<"enter seat number";cin>>CustSeat[i];if(CustSeat[i]==0)
						{cout<<"Seat Already Booked";cin>>quit;}
					}
					for(i=1;i<=SeatCount;i++)
					{if(SeatCount>50)
						{break;}
						for(j=1;j<51;j++)
						{
							if(CustSeat[i]==p3seats[j])
							{
								p3seats[j]=0;
							}
						}
					}
				
				}cout<<"\nenter customer name:\n";cin>>name;sfileout();
		system("clear");
		cout<<"\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
		cout<<"\nName: ";cout<<name<<"\t\t\tHookMyShoe";
		cout<<"\nMovie Name:  "; cout<<movie[choice1]<<endl;
		cout<<"TIME:"<<timings[choice1];cout<<endl;
		cout<<"\nclass: ";
		if(choice2==1)
		{
		cout<<"Silver\n";
		}
		if(choice2==2)
		{
		cout<<"Gold\n";
		}
		if(choice2==3)
		{
		cout<<"Platinum\n";
		}
		cout<<"Seats: ";
		for(i=1;i<=SeatCount;i++)
		{
			{
				cout<<CustSeat[i]<<" ";
			}
		}
				cost=SeatCount*prate;
		cout<<"\nTotal Fare: ";cout<<cost;
		data++;
		cout<<"\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";cin>>quit;
		cout<<"\n\nPrint?<1/0>";cin>>yeah;
		if(yeah==1)
		{
		Rfileout();
		system("gedit Ticket ");	}			
		}
//		break;
	}
	void Rfileout()											// Register File out
	{	
		ofstream myfile ("Ticket");
		for(i=1;i<=data;i++)
		{
			myfile<<"\n";	
			myfile<<"----------------------------------------------------------------------------------------";
			myfile<<"\nName: "<<name<<"\t\t\t\t\tHookMyShoe";
			myfile<<"\nMovie Name:  "<<movie[choice1]<<endl;
			myfile<<"TIME:"<<timings[choice1];cout<<endl;
			myfile<<"\nclass: ";
			if(choice2==1)
			{
			myfile<<"Silver\n";
			}
			if(choice2==2)
			{
			myfile<<"Gold\n";
			}
			if(choice2==3)
			{
			myfile<<"Platinum\n";
			}
			myfile<<"Seats: ";
			for(i=1;i<=SeatCount;i++)
			{
				{
					myfile<<CustSeat[i]<<" ";
				}
	
		}
			myfile<<"\nTotal Fare: ";myfile<<cost;
			myfile<<"\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
			myfile<<"---------------------------------------------------------------------------------------\n"; 
			}
		myfile.close();
		}
	void DispSeati()									//INTERACTIVE SEATS VIEW
	{
		dispMovie();
		cout<<"Enter Screen Number";		cin>>screen;
		switch(screen)
		{
			case 1:	system("clear");dispSeat(1);break;
			case 2: system("clear");dispSeat(1.0);break;
			case 3: system("clear");dispSeat();break;
		}
	}
	void reset()										//RESET
	{
		cout<<"<- Settings \n\n\n";
		cout<<"\n1.Reset_Movies\n2.Reset_Seats\n3.Movies_Entry\n4.Initial_use\n5.Back\n";
		cin>>Myway;
		switch(Myway)
		{
			case 1:	for(i=1;i<4;i++)
				{	
					movie[i]=actor[i]=actress[i]=timings[i]="unknown";
					ratings[i]=0;		
				}
					shfileout();
				break;
			case 2:	
					dispMovie();
					cout<<"Enter screen_number: ";cin>>Myway;
					switch(Myway)
				{
					case 1: 	for(i=1;i<51;i++)
							{	
							p1seats[i]=g1seats[i]=s1seats[i]=i;
							//p2seats[i]=g2seats[i]=s2seats[i]=i;
							//p3seats[i]=g3seats[i]=s3seats[i]=i;
							}sfileout();break;
					case 2: 	for(i=1;i<51;i++)
							{
							//p1seats[i]=g1seats[i]=s1seats[i]=i;
							p2seats[i]=g2seats[i]=s2seats[i]=i;
							//p3seats[i]=g3seats[i]=s3seats[i]=i;
							}sfileout();break;
					case 3: 	for(i=1;i<51;i++)
							{
							//p1seats[i]=g1seats[i]=s1seats[i]=i;
							//p2seats[i]=g2seats[i]=s2seats[i]=i;
							p3seats[i]=g3seats[i]=s3seats[i]=i;
							}
							sfileout();break;
					default:system("beep");system("sleep 1");system("beep");break;
						}break;
			default:system("beep");system("sleep 1");system("beep");break;
			case 3: getMovie();break;
			case 4: for(i=1;i<51;i++)
							{
							p1seats[i]=g1seats[i]=s1seats[i]=i;
							p2seats[i]=g2seats[i]=s2seats[i]=i;
							p3seats[i]=g3seats[i]=s3seats[i]=i;
							}
							sfileout();for(i=1;i<4;i++)
				{	
					movie[i]=actor[i]=actress[i]=timings[i]="unknown";
					ratings[i]=0;		
				}
					
					shfileout();getrate();break;
			case 5: break;
		}
	}
	void init()
	{
		for(i=1;i<51;i++)
							{
							p1seats[i]=g1seats[i]=s1seats[i]=i;
							p2seats[i]=g2seats[i]=s2seats[i]=i;
							p3seats[i]=g3seats[i]=s3seats[i]=i;
							}
		for(i=1;i<4;i++)
				{	
					movie[i]=actor[i]=actress[i]=timings[i]="unknown";
					ratings[i]=0;
				}
					getMovie();		
					shfileout();
					shfilein();		
				}
void checkpass()
{
	std::ifstream myfile (".password.txt");	
		myfile >> un;
		//myfile >> pw;
		if((un.empty()))
		{pass();}
	myfile.close();
}
void pass()
{
	system("clear");
	cout<<"\n\n\n\t\t\t\t\t\t\t:HookMyShoe:\n\n\n";	
	cout<<"\n\n\n\t:CHANGE/CREATE PASSWORD:\n\n\n";
	cout<<"Enter New Username...";cin>>newusername;
	cout<<"Enter New Password...";cin>>newpass;
	cout<<"Do you want to change password?(1/0)";
	cin>>quit;
	if(quit==1)
	{
		std::ofstream myfile(".password.txt");
				myfile<<newusername<<"\n"<<newpass;
				myfile.close();
	}
}
void format()
{
	cout<<"Formatting in progress...\t\tDo you Want to Continue?(1/0)";
	cin>>quit;
	if(quit==1)
		{system("rm .movies.txt");
		system("rm .seats.txt");
		system("rm .password.txt");
		system("rm .rates.txt");
		system("rm Ticket");}
	
}
	void extendedview()									//EXTENDED MOVIES REVIEWS
	{	
		dispMovie();
		cout<<"Enter Screen_Number";
		cin>>screen;
		system("clear");
		cout<<"\n\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
			cout<<"Movie:"<<movie[screen];
			cout<<"\nActor:"<<actor[screen];
			cout<<"\nActress"<<actress[screen];
			cout<<"\nTIME:"<<timings[screen];cout<<endl;
			cout<<"Screen: "<<screen<<endl;
			cout<<"Likes: "<<ratings[screen];
			cout<<"\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n";
	}	
	void help()
{	system("clear");
	cout<<"1 beep:  system condition is good\n2 beeps:  system condition is wrong!\n\ncodes:\n1.reset movies::4 1\n2.reset seats::4 2\n3.For_initial_use:: 4 4\n4.Reset Username And password:: 21\n5.Format System(warning!!):: 69";cin>>quit;
}
};
int main()											//MAIN FUNCTION
{
label2:	
	system("sudo modprobe pcspkr");
	system("touch Ticket");
	system("touch .movies.txt");
	system("touch .seats.txt");
	system("touch .rates.txt");	
	system("touch .password.txt");
	string emp;
	int choice,q,error,me,logout=1;
	bms obj;
	system("clear");
	cout<<"\n\n\t\tEnter Your Name::";cin>>emp;
	obj.checkpass();
	string uname,pass,un="admin";
	string pw="admin";
std::ifstream myfile (".password.txt");
		myfile >> un;
		myfile >> pw;
	myfile.close();
label1: 
	system("clear");
	system("clear");
	cout<<"\n\n\n\n\n\n\n\n\n\n1 beep = system status good\n2 beeps = system status bad\n\n\n\n\n\n\t\tWelcome to HookmyShoe\n\n\n";
	cout<<"\tEnter USERNAME...";cin>>uname;
	obj.Hide();
	cout<<"\tEnter PASSWORD...";cin>>pass;
	obj.Show();
	if(un.compare(uname)!=0)
	{system("beep");system("sleep 1");system("beep");goto label1;}
	else{goto label;}
	if(pw.compare(pass)!=0)
	{system("beep");system("sleep 1");system("beep");goto label1;}
	else{goto label;}
	choice=1;
label:
system("clear");
cout<<"\n\n\n\t\t::Welcome to HookmyShoe::\n\n\t\tBest Viewed in fullscreen!\n\t\t\t\t\t\t\t\tPress CTRL+WINDOOWS+UP\n\tEnter 1 to Continue...\n\t      2 for Initialisation...";cin>>q;
if(q==2)
{obj.init();}
obj.shfilein();
obj.Sfilein();
system("beep");
while(choice!=9)										//LOOP
{
obj.shfilein();
obj.Sfilein();
system("clear");	
cout<<"\n\t\t::Welcome to HookmyShoe::"<<"\t\temployee: "<<emp<<endl<<endl;
	cout<<"\n\n\t\tONGOING:  ";
	obj.dispMovie();
cout<<"\n0.Help\t\t\t1.Tickets_Sale\n2.Display seats\t\t3.Edit movie\n4.Settings\t\t5.Ratings\n6.Rate Analytics\t7.About\n8.Logout\t\t9.Exit\n";cout<<"Enter Your_Choice"<<endl;cin>>choice;
switch(choice)
	{
	case 1:system("clear");
		obj.sale();break;
	case 2:system("clear");
		obj.DispSeati();cin>>q;system("beep");break;
	case 3:system("clear");
		obj.editMovie();cin>>q;system("beep");break;
	case 4:system("clear");
		obj.reset();system("beep");break;
	case 5:system("clear");
		obj.extendedview();system("beep");break;
	case 6:system("clear");
		obj.disprate();break;
	case 7:system("clear");
		cout<<"Copyright @HHcreations Inc.\nThis Application HookMyShoe and its content is copyright of HHcreations Inc - © The 7evenZ 2016.\nwe, together with our licensors, own and control all the copyright and other intellectual property rights in our application and \nthe material in our application,all the copyright and other intellectual property rights in our application and the material in our application are reserved.\nAll rights reserved 7evenz Inc. 2016-2017 .\nFor More Information follow me on \nG+:\t+hatimchathiwala";cin>>q;system("beep");break;
	case 0:obj.help();break;
	case 8:obj.shfileout();obj.sfileout();system("clear");system("beep");goto label1;break;
	case 9:system("beep");system("sleep 1");system("beep");system("sudo modprobe -r pcspkr");obj.shfileout();obj.sfileout();system("clear");break;
	case 52: obj.foo();system("beep");break;
	case 21:obj.pass();system("beep");break;
	case 69: obj.format();system("beep");goto label2;break;
	default:system("beep");system("sleep 1");system("beep");break;
}
}
}
