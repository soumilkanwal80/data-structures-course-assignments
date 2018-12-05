// #pragma once
#include "header.h"

class lab_comp
{	
public:
	bool operator() (Lab a, Lab b)
	{
		return a.area<b.area;
	}
};

class lec_comp
{
public:
	bool operator() (Lecture a, Lecture b)	
	{
		return a.n_chair<b.n_chair;
	}
};

int main()
{
	fstream flab("lab.txt", ios::in);
	fstream flec("lec.txt", ios::in);
	string name;
	float area;
	int n_doors;
	int x, y;
	int n_var;

	pQueue<Lab, lab_comp> pqlab;
	pQueue<Lecture, lec_comp> pqlec;

	vector<Lab> l1;
	vector<Lecture> l2;
	int itr = 0;
	while(flab>>name>>area>>n_doors>>x>>y>>n_var)
	{
		Lab l;
		l.create_object(name, area, n_doors, x, y, n_var);
		l1.push_back(l);
		pqlab.insert(l);

	}
	cout<<l1.size()<<endl;
	// pqlab.bottomUpConst(l1, l1.size());

	// cout<<pqlab.returnMin().name<<endl;

	while(flec>>name>>area>>n_doors>>x>>y>>n_var)
	{
		
		Lecture l;
		l.create_object(name, area, n_doors, x, y, n_var);
		l2.push_back(l);
		pqlec.insert(l);
	}
	cout<<l2.size()<<endl;
	// pqlec.bottomUpConst(l2, l2.size());
	// cout<<pqlec.returnMin().name<<endl;
	while(1)
	{
		cout<<"Select 1 option: \n";
		int inp;
		cout<<"1. Insert in Lab\n";
		cout<<"2. Insert in Lecture\n";
		cout<<"3. Replace last inserted in lab\n";
		cout<<"4. Replace last inserted in lecture\n";
		cout<<"5. Remove last inserted from lab\n";
		cout<<"6. Remove last inserted from lecture\n";
		cout<<"7. Print Lab\n";
		cout<<"8. Print Lecture\n";
		cout<<"9. Remove Minimum from lab\n";
		cout<<"10. Remove Minimum from lecture\n";
		cout<<"11. Exit\n";
		cin>>inp;
		if(inp == 1)
		{
			cout<<"Name: ";
			cin>>name;
			cout<<"Area: ";
			cin>>area;
			cout<<"Number of Doors: ";
			cin>>n_doors;
			cout<<"Location: ";
			cin>>x>>y;
			cout<<"Number of Computers: ";
			cin>>n_var;
			Lab l;
			l.create_object(name, area, n_doors, x, y, n_var);
			pqlab.insert(l);
		}

		else if(inp == 2)
		{
			cout<<"Name: ";
			cin>>name;
			cout<<"Area: ";
			cin>>area;
			cout<<"Number of Doors: ";
			cin>>n_doors;
			cout<<"Location: ";
			cin>>x>>y;
			cout<<"Number of Chairs: ";
			cin>>n_var;
			Lecture l;
			l.create_object(name, area, n_doors, x, y, n_var);
			pqlec.insert(l);
		}

		else if(inp == 3)
		{
			cout<<"Name: ";
			cin>>name;
			cout<<"Area: ";
			cin>>area;
			cout<<"Number of Doors: ";
			cin>>n_doors;
			cout<<"Location: ";
			cin>>x>>y;
			cout<<"Number of Computers: ";
			cin>>n_var;
			Lab l;
			l.create_object(name, area, n_doors, x, y, n_var);
			pqlab.replace(l);
		}

		else if(inp == 4)
		{
			cout<<"Name: ";
			cin>>name;
			cout<<"Area: ";
			cin>>area;
			cout<<"Number of Doors: ";
			cin>>n_doors;
			cout<<"Location: ";
			cin>>x>>y;
			cout<<"Number of Chairs: ";
			cin>>n_var;
			Lecture l;
			l.create_object(name, area, n_doors, x, y, n_var);
			pqlec.replace(l);
		}

		else if(inp == 5)
			pqlab.remove();
		else if(inp == 6)
			pqlec.remove();
		else if(inp == 7)
			pqlab.print();
		else if (inp == 8)
			pqlec.print();
		else if(inp == 9)
			pqlab.removeMin();
		else if(inp == 10)
			pqlec.removeMin();
		else
			break;

	}




	// int num = 1<<6;
	// cout<<num<<endl;


}
