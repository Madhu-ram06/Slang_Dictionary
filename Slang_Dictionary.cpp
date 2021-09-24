#include<iostream>
#include<stdlib.h>
#include<unistd.h>
#include<fstream>
#include<string.h>
using namespace std;





int showMeaning(char search[200])
{
	int count=0,ifabsent=0;
	char s[200],string[1000][400],ch[400];

	ifstream name("word.txt");
	ifstream mean("meaning.txt");

	if(!name && !mean)
	{
		cout<<"Cannot open file\n";
		return 1;
	}



	while(!name.eof())
	{

		name>>s;
		if(strcmp(search,s)==0)
		{
		ifabsent=1;
		break;
		}


		else
		count++;



	}
	if(ifabsent==0)
	{
		try{
			throw 0;
		}
		catch(int i)
                             {
                                cout<<"\n\t\t\t\tCaught an exception.\n "<<endl;
                                cout<<"\n\n\t\t\t\t WORD NOT FOUND IN DICTIONARY, PLEASE TRY AGAIN\n";
                                return 1;
                             }
        }


	for(int i=0;i<=count;i++)
	{
		mean.getline(ch,400,'$');
		strcpy(string[i],ch);


		if(i==count)
		cout<<"\n\n\t\t\t\t\tThe meaning of the word is\n"<<string[count]<<endl;

	}

	name.close();
	mean.close();


}
int usage(char search[200])
{
	int count=0,ifabsent=0;
	char s[200];
	ifstream use("usage.txt");
	ifstream name("word.txt");
	while(!name.eof())
	{
		name>>s;
		if(strcmp(search,s)==0)
		{
		ifabsent=1;
		break;
		}



		else
		count++;


	}
	if(ifabsent==0)
	{
		try{
			throw 0;
		}
		catch(int i)
                             {
                                cout<<"\n\t\t\t\tCaught an exception.\n "<<endl;
                                cout<<"\n\n\t\t\t\t WORD NOT FOUND IN DICTIONARY, PLEASE TRY AGAIN\n";
                                return 1;
                             }
        }


	char ch1[400],usestr[1000][400];
	for(int i=0;i<=count;i++)
	{
		use.getline(ch1,400,'$');
		strcpy(usestr[i],ch1);

		if(i==count)
		{
		cout<<"\n\n\t\t\t\t The USAGE of the word is\n\n";
		cout<<"\t\t\t "<<usestr[count]<<endl;
		}
	}
	use.close();
	name.close();
}
class loadProject
{

	public: void loadfunc()
	{
		for(int i=0;i<483;i++)
		{
			cout<<"*";
		}

		cout<<"\n\n\n\n\n";
		for(int i=0;i<161;i++)
		{
			cout<<"~";
		}
		cout<<"\n\n\n\n\n";
		cout<<"\t\t\t\t\t\t\t\t   SLANG DICTIONARY\n\n";
		cout<<"\n\t\t\tMADHUMITHA R\t\t\tMEGHANA REDDY\t\t\tSHREYA SHETTAR\t\t\tTEJASHREE KRISHNAMURTHY\n\n\n";
		cout<<"\t\t\t\t\t\t\t\t\tLOADING\n\n\n";
		 for (int i=0;i<=99;i++)
		 {

		  int num=0;
		while(num<=100)
		{
		 cout<<"\t\t\t\t\t\t\t\t\t "<<i<<"%\r";
		 num++;
		 }


		  usleep(80000);



		 }
		 for(int i=0;i<161;i++)
		{
			cout<<"~";
		}
	}
};
class menu
 {
  public : int choice;char search[200];
  	    char hist[200][200];
	public : void show()
		{
      		     int hcount=0;
	            cout<<"\n\n\n\n\n\n\t\t\t\t\t\t   >>>>>>>>>>>>>>>>     MENU    <<<<<<<<<<<<<<<<<<<\n\n";
		    cout<<"\n\n\n\n\t\t\t\t\t\t ENTER THE SEARCH WORD\n";
		    cout<<"\t\t\t\t\t\t  ";
		    cin>>search;
		    strcpy(hist[hcount++],search);

		    while(choice!=5)
		    {
		    cout<<"\n\n\n\n\n";
		    cout<<"\t\t\t\t PRESS 1 TO SHOW THE MEANING\n";
		    cout<<"\n\t\t\t\t PRESS 2 TO SHOW THE USAGE IN A SENTENCE\n";
		    cout<<"\n\t\t\t\t PRESS 3 TO SEARCH ANOTHER WORD\n";
		    cout<<"\n\t\t\t\t PRESS 4 TO SHOW HISTORY \n";
	            cout<<"\n\t\t\t\t PRESS 5 TO EXIT \n";
		    cout<<"\n\t\t\t\t\t";
		    cin>>choice;

		    switch(choice)
		    {

			    case 1:
		            showMeaning(search);

		            break;

	                    case 2:

		            usage(search);

		            break;

			    case 3:

		            cout<<"\n\n\n\t\t\t\t ENTER THE SEARCH WORD\n\n\t\t\t\t\t";
		            cin>>search;
		            strcpy(hist[hcount],search);
		            hcount++;

			    break;

			    case 4:
			    cout<<"\n\n\t\t\t\t THE HISTORY OF THE USER IS\n\n";
		            for(int i=0;i<=hcount;i++)
		            cout<<"\t\t\t\t\t"<<hist[i]<<endl<<endl;
		            break;

			    case 5:
		            for(int i=0;i<161;i++)
				{
					cout<<"~";
				}
                            cout<<"\n\n\n\t\t\t\t\t\t    THANK YOU FOR USING OUR SLANG DICTIONARY !!!!! \n\n\n\n";
                            for(int i=0;i<161;i++)
				{
					cout<<"~";
				}
				cout<<"\n\n\n\n";
				for(int i=0;i<483;i++)
				{
					cout<<"*";
				}
			       exit(1);
                            break;

		            default:
                            try{
                                throw 10;
                                }


                            catch(int i)
                             {
                                cout<<"Caught an exception and value is "<<i<<endl;
                             }

                            cout<<"Invalid option\n";
		            cout<<"End \n";
                            break;

	    }
         }
      }
 };




int main()
{
	loadProject obj2;
	obj2.loadfunc();

	 menu obj;
	 obj.show();

}
