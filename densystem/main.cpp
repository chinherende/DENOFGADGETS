#include<iostream>
#include<string.h>
#include<conio.h>
#include<math.h>
#include<fstream>
#include <windows.h>

       using namespace std;
int i,n;
ifstream fin;
ofstream fout;
fstream fio;
void disp();
class stock
{
		char name[20],pass[10];
	float pr; int quant;

public:
	void get();
	void get2();
	void show();
    int stchk(char nm[30]);
    void withd(int qty);
    void refil(int qty);
}st;
void stock::withd(int qty)
{
	if(quant>=qty)
	{
		quant-=qty;
		std::cout<<"\n\n  **Stock updated.**\n";
		std::cout<<"\n\nTotal price to be paid:"<<pr*qty;
    }
	else
	   std::cout<<"\n\n**Insufficient stock**";
	    getch();


}

void stock::refil(int qty)
{

		quant+=qty;
		std::cout<<"\n\n***Stock updated.***";
	    getch();


}
int stock::stchk(char nm[30])
{
	if(strcmp(nm,name)==0)
	 return 0;
	else
	return 1;
}
void stock::get()
{
	std::cin>>name>>pr>>quant;

}
void stock::get2()
{
	std::cin>>name>>quant;
}

void stock::show()
{

	std::cout<<"\n"<<name<<"\t\t\t"<<quant<<"\t\t\t"<<pr;
}
void addnew()
{

    system("cls");
	disp();
	getch();
	system("cls");

	std::cout<<"\n___Enter the No. of Gadgets that you wish to add: ";
    std::cin>>n;


    if (n!=0)
    {

	int j,l,sum=0;
	fout.open("shop.dat",ios::binary|ios::app);
	for(i=0;i<n;i++)

	{

		std::cout<<"\n\nInput the name, price and the quantity of item \n\n";
	    st.get();
	    fout.write((char*)&st,sizeof(st));
        std::cout<<"\n\n**item updated**";
		std::cin.get();


    }
    std::cout<<"\n\n***Stock Updated***";


    fout.close();
    std::cin.get();
    system("cls");
    disp();
}

	else
{

	fout.close();
	std::cin.get();
	system("cls");
	std::cout<<"\n\n Number of items to be added :";

}
}




void withdraw()
{
	system("cls");
	char temp[100];int qty;
	int i=0;
	long pos=0;
	disp();
	std::cout<<"\n\nEnter the Gadget's name : \n"<<endl;
	std::cin>>temp;
	std::cout<<"\n\nEnter quantity : \n"<<endl;
	std::cin>>qty;
	fio.open("shop.dat",ios::binary|ios::out|ios::in);
     while(fio)
     {
	    pos=fio.tellp();
	    fio.read((char*)&st,sizeof(st));
	    if(st.stchk(temp)==0)
	    {

		  st.withd(qty);
		  fio.seekp(pos);
		  fio.write((char*)&st,sizeof(st));
		  i++;break;
	    }
     }


     if(i!=1)
       std::cout<<"\n\n!!Record not found??";
     fio.close();
    std::cin.get();
    system("cls");
	 disp();
	getch();
}
void disp()
{
	int i=1;
	std::cout<<"\n\n...............\tTHE STOCK ITEMS ARE\t..............";
	std::cout<<"\n\n**********************************************************\n";
	std::cout<<"\n\nPARTICULARS..........STOCK AVAILABLE .............PRICE";
	std::cout<<"\n\n**********************************************************\n";
	 fin.open("shop.dat",ios::binary);
     while(!fin.eof())
     {
	  fin.read((char*)&st,sizeof(st));
	  if(!fin.eof())
	  {
	     if(fin.tellg()<0)
	     {	i=0; break;}
	     st.show();
	  }
     }
     if(i==0)
     {	std::cout<<"\n\n\t\t\t!!Empty record room!!";
	getch();
     }
     fin.close();

}
void refill()
{
	system("cls");
	char temp[100];int qty;
	int i=0;
	long pos=0;
	disp();
	std::cout<<"\n\nEnter the products name \n"<<endl;
	std::cin>>temp;
	std::cout<<"\n\nEnter quantity: \n"<<endl;
	std::cin>>qty;
	fio.open("shop.dat",ios::binary|ios::out|ios::in);
     while(fio)
     {
	    pos=fio.tellp();
	    fio.read((char*)&st,sizeof(st));
	    if(st.stchk(temp)==0)
	    {

		  st.refil(qty);
		  fio.seekp(pos);
		  fio.write((char*)&st,sizeof(st));
		  i++;break;
	    }
     }
     if(i!=1)
       std::cout<<"\n\n!!Record not found!!";
     fio.close();
    system("cls");
    std::cin.get();
	 disp(); std::cin.get();


}
void remove()
{
	system("cls");
	 int i=0;
     char temp[30];
     std::cout<<"\n\t\t\t\tDelete Record";
     std::cout<<"\n\nEnter the name of the Gadget:";
     std::cin>>temp;
     fout.open("temp.dat",ios::binary);
     fin.open("shop.dat",ios::binary);
     while(!fin.eof())
     {
	  fin.read((char*)&st,sizeof(st));
	  if(!fin.eof())
	    if(st.stchk(temp)==0)
	    {
		  st.show();
		  std::cout<<"\n\n\t\tRecord deleted";
		  i++;
	    }
	    else
		  fout.write((char*)&st,sizeof(st));
     }
     if(i==0)
       std::cout<<"\n\n!!Record not found!!";
     fin.close();
     fout.close();
     remove("shop.dat");
     rename("temp.dat","shop.dat");
}
int main()
{
	char pass[10],pass2[10];
	int i,j;
	HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(color, 3);
        std::cout<<"\n\n\n\n\n\n\n\n\n\n\n \t\t\t^^^^^^^^^^^^WELCOME TO DEN OF GADGETS^^^^^^^^^^^^^^^";

	getch();
	system("cls");
    system("Color b9");
	std::cout<<"\n\t\t   ****DEN OF GADGETS****\n";
	std::cout<<"--------------------------------------------------------------";
	std::cout<<"\n\n\t\t 1. INVENTORY \n\n\t\t 2. CLIENTS \n\n\t\t 3. Gadgets ";

	std::cout<<"\n\n--------- Please Enter Your Choice:";
	std::cin>>j;
	if(j==1)
	{

	system("cls");

    system("cls");
    std::cout<<"\n\n\n\n\n\n\n\t\t\t\t\tEnter the password letter by letter: ";

	for(int z=0;z<6;z++)
	{
		pass[z]=getch();
		system("cls");
		std::cout<<"\n\n\n\n\n\n\n\t\t\t\t\tEnter the password letter by letter: ";
		for(i=1;i<=(z+1);i++)
		{
			std::cout<<"*";
		}
	}
if(strcmp(pass,"gadget")==0)
	{

    system("cls");
	gadgetmenu:
	system("cls");


	std::cout<<"\n\n\t\t\t   Stock MENU\n 1. Add new product\n 2. Display stock\n 3. Refill\n 4. Remove an item\n 5. Exit:";
	std::cout<<"\n\n\n==========================END OF MENU=============================";
	std::cout<<"\n\n Enter your Choice :\t";
	std::cin>>i;
	if(i==1)
	{
		addnew();getch();
	goto gadgetmenu;
	}

	else if(i==2)
	{
		system("cls");
	disp();getch();goto gadgetmenu;
	}
	else if(i==3)
	{
		refill();goto gadgetmenu;
	}
	else if(i==4)
	{
		remove();getch();goto gadgetmenu;
	}
	else
	{
		system("cls");
	std::cout<<"\n\n\n\t\t\t******DENOFGADGETS******";
	getch();
	exit(0);
}
}
else
{
	std::cout<<"\n\n\nAuthorised Personnel Only\n\n";
	getch();
	getch();
	getch();
	getch();
	getch();
	getch();
	exit(0);
}
	}
	if(j==2)
	{
		custmenu:
	system("cls");
	 system("Color 9");

	std::cout<<"\n\n\t\t\t    CUSTOMER MENU\n 1. Purchase\n 2. Display stock\n 3. Exit:";
	std::cout<<"\n\n\n-----------------------------END OF MENU--------------------------------";
	std::cout<<"\n\n Please Enter your Choice :\t";
	std::cin>>i;



	if (i==1)
	{
	withdraw();getch();goto custmenu;
	}
	else if(i==2)
	{
		system("cls");
	disp();getch();goto custmenu;
	}

	else
	{
		system("cls");
	std::cout<<"\n\n\n\t\t\t ****DEN OF GADGETS PROJECT****";
	getch();
	exit(0);
}

}
if(j==3)

{
	system("cls");
	std::cout<<"\n\n\n\n\n\n\n\t\t\t\t\t *Please Enter  password : ";

	for(int z=0;z<3;z++)
	{
		pass2[z]=getch();
		system("cls");
		std::cout<<"\n\n\n\n\n\n\n\t\t\t\t\t *Please Enter the password : ";
		for(i=1;i<=(z+1);i++)
		{
			std::cout<<"*";
		}
	}
	if(strcmp(pass2,"bvc")==0)
	{
	bvcmenu:
	system("cls");

	std::cout<<"\n\n\t\t\t Gadgets MENU\n 1. Display stock\n 2. Refill\n 3. Exit";
	std::cout<<"\n\n\n--------------------------END OF MENU-----------------------------";
	std::cout<<"\n\n Please Enter your Choice :\t";
	std::cin>>i;
	if(i==1)
	{
		system("cls");
	disp();getch();goto bvcmenu;
	}
	else if(i==2)
	{
		refill();goto bvcmenu;
	}
	else
	{
		system("cls");
	std::cout<<"\n\n\n\t\t\t***Thank You!!***";
	getch();
	exit(0);
}
}
else
{
	std::cout<<"\n\nSorry!! Access Denied..\n\n";
	getch();
	getch();
	getch();
	getch();
	getch();

	exit(0);
}

	}

	getch();

}
