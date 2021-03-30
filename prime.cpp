#include<iostream>                                                      //headers
#include<ctime>
#include<cstdlib>
using namespace std;
int main()                                                              //main
{
        while(true)
        {
                system("clear");
                int prime[999999];                                      //declarations
                prime[0]=2;
                prime[1]=3;
                prime[2]=5;
                prime[3]=7;
                int comp=0,tempa =0;                                    //comparisons
                int count =4;
                int num = 8;
                int number;
                int flag;

                flag = 1;
                cout<<"\nenter number to be searched\n";
                cin>>number;
                int start_s=clock();                                    //clock start

                comp++;
                if(number<7)
                {
                        flag = 0;
                        comp++;
                        if(number == 2||number == 3||number == 5||number == 7)
                        {
                                cout<<"\nPRIME\n";goto label;
                        }
                        else
                        {
                                cout<<"\nNot PRIME\n";goto label;
                        }
                }

                number++;



                for(int l=0;l<=number+1;l++)                            //logic
                {
                        for(int i=0;i<=count+1;i++)
                        {
                                comp++;
                                if(num>=number){break;}
                                comp++;
                                if((num%prime[i])==0)
                                {
                                        num++;
                                        if((num-1)==(number-1)){tempa = prime[i];}
                                        break;
                                }
                                else
                                {
                                        comp++;
                                        if(i==count-1)
                                        {
                                                prime[count] = num; count++;
                                        }
                                }
                        }
                }
                label:
                int stop_s=clock();                                     //clock end
                cout << "\ntime: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;
                number--;                                               //last number will be the prime
                if(flag!=0)
                {
                        if(prime[count-1]== number)
                        {
                                cout<<"\nPRIME\n";
                        }
                        else{cout<<"NOT PRIME , MULTIPLE of ="<<tempa;cout<<" Divisible by: "<<number/tempa; }
                        cout<<"\n\n\n";
                        cout<<"enter 0 to view all";                            //optional
                        int choice;
                        choice = 1;
                        cin>>choice;
                        if(choice==0)
                        {
                                long int sum =0;
                                for(int g = 0;g<count ; g++)
                                {
                                        cout<<"\n"<<prime[g];
                                        sum = sum+(double)prime[g];
                                }
                                cout<<"\ncount: "<<count;
                                cout<<"\nsum: "<<sum;
                                cout<<"\ncomparisons: "<<comp;
                                cout<<"\nspeed: "<<comp/((stop_s-start_s)/double(CLOCKS_PER_SEC)*1000)<<" comparisons/ms";
                        }

                        if(choice ==0)
                        {
                                cin>>choice;
                        }
                }
                else
                {
                        cin>>number;
                }
        }
}
