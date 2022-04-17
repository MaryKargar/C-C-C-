// 1.cpp : Defines the entry point for the console application.


#include "stdafx.h"
#include "iostream"
#include "conio.h"


typedef struct student
{
char name[21];
int id;
}


student  st[10];

int c = -1;
void pop();
void push();
void display();
void menu();


int _tmain(int argc, _TCHAR* argv[])
{

	return 0;
}

void menu()
{
	int n, f = 0;
	while (f)
	{
		cout << "\n)Add:  ";
		cout << "\n)delete:  ";
		cout << "\n)display:  ";
		cout << "\n)exit:  ";
		cout << "\n)select item 1,2,3,4:  ";
		cin >> n;

		switch (n)
		{
                 case 1:
                push();
		break;
		case 2:
		pop();
		break;
		case 3:
		display();
		break;
		case 4:
		f=0;
		break;
		
		}
	}

}
void push()
{
++c;
if(c!=10)
{
cout<<"enter name:   ";
cin>>st[c].name;
cout<<"enter id:   ";
cin>>st[c].id;
cout<<"name and id add in list";

}
else
cout<<"stack is full";
}
 void pop()
{
if(c!=-1)
{
--c;
cout<<"\n item is delete";

}
else 
cout<<"stack is empty";

}
void display()
{
int i;

if(c!=-1)
{
for(i=0;i<c;++i)
cout<<"\nname=  "<<st[i].name<<"\nid=  "<<st[i].id"<<endl;
}
else
cout<<"stack is empty";

}