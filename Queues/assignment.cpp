#include "header.h"
using namespace std;

int main()
{
	sQueue<itemNode> q;

	fstream ifruit("fruits.txt", ios::in);
	fstream iveg("vegetables.txt", ios::in);
	string type;
	int x, y, price, calories, units, volume;
	float weight;
	while(!ifruit.eof())
	{
		ifruit>>type>>x>>y>>weight>>price>>calories>>units;
		fruitNode *temp = new fruitNode(type, x, y, weight, price, calories, units);
		q.enqueue((itemNode*)temp);
		// cout<<calories<<" "<<q.returnCalories2()<<endl;
		// cout<<q.returndq()<<endl;
	}

	while(!iveg.eof())
	{
		iveg>>type>>x>>y>>price>>weight>>calories>>units;
		vegNode *temp = new vegNode(type, x, y, weight, price, calories, units);
		q.enqueue((itemNode *)temp);
	}

	while(1)
	{
		cout<<"Select an option:\n";
		cout<<"1. enqueue\n";
		cout<<"2. dequeue\n";
		cout<<"3. front\n";
		cout<<"4. min\n";
		cout<<"5. size\n";
		cout<<"6. Exit\n";

		int n;
		cin>>n;
		if(n == 1)
		{
			cout<<"Is it a fruit or vegetable?\n";
			cout<<"1. Fruit\n";
			cout<<"2. Vegetable\n";
			int input;
			cin>>input;

			if(input == 1)
			{
				fruitNode *temp = new fruitNode;
				q.enqueue((itemNode *) temp);
			}

			else
			{
				vegNode *temp = new vegNode;
				q.enqueue((itemNode *)temp);
			}
		}


		else if(n == 2)
			q.dequeue();

		else if(n == 3)
		{
			const itemNode *tfront = &(q.returnFront());
			if(tfront->returnIsFruit() == 1)
			{
				const fruitNode *ftemp = (fruitNode *) tfront;
				cout<<ftemp->returnName()<<" X: ";
			}

			else
			{
				const vegNode *vtemp = (vegNode *) tfront;
				cout<<vtemp->returnName()<<" X: ";
			}

			cout<<tfront->returnX()<<" Y: "<<tfront->returnY()<<" Calories: ";
			cout<<tfront->returnCalories()<<endl;
		}
		
		else if(n == 4)
		{
			const itemNode *tmin = &(q.returnMin());
			
			if(tmin->returnIsFruit() == 1)
			{
				const fruitNode *ftemp = (fruitNode *) tmin;
				cout<<ftemp->returnName()<<" X: ";
			}

			else
			{
				const vegNode *vtemp = (vegNode *) tmin;
				cout<<vtemp->returnName()<<" X: ";
			}

			cout<<tmin->returnX()<<" Y: "<<tmin->returnY()<<" Calories: ";
			cout<<tmin->returnCalories()<<endl;
		}

		else if(n == 5)
		{
			cout<<q.returnSize()<<endl;
		}
		else
			break;
	}

}
