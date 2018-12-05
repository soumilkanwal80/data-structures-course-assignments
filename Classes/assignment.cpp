#include "header.h"
using namespace std;

int main()
{
	itemList a;
		

	fstream ifruit("fruits.txt", ios::in);
	fstream iveg("vegetables.txt", ios::in);
	string type;
	int x, y, price, calories, units, volume;
	float weight;
	while(!ifruit.eof())
	{
		ifruit>>type>>x>>y>>weight>>price>>calories>>units;
		a.insertNode(type, x, y, weight, price, calories, units, 1);
	}

	while(!iveg.eof())
	{
		iveg>>type>>x>>y>>price>>weight>>calories>>units;
		a.insertNode(type, x, y, weight, price, calories, units, 0);
	}

	while(1)
	{
		cout<<"Select an option:\n";
		cout<<"1. Add fruits or vegetables\n";
		cout<<"2. Buy fruits or vegetables\n";
		cout<<"3. Get details about a fruit or vegetable\n";
		cout<<"4. Display all items\n";
		cout<<"5. Find all the items in given area\n";
		cout<<"6. Find fruit having less than specificied calories\n";
		cout<<"7. Exit\n";

		int n;
		cin>>n;
		if(n == 1)
			a.insertNode();

		else if(n == 2)
			a.itemBuy();

		else if(n == 3)
			a.searchList(1);

		else if(n == 4)
			a.printList();
		
		else if(n == 5)
			a.searchList(2);

		else if(n == 6)
			a.searchList(3);
		else
			break;
	}

}
