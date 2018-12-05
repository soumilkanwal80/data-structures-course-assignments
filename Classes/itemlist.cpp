#include "header.h"
#include<climits>
using namespace std;

void itemList::insertNode()
{
	cout<<"Is it a fruit or vegetable?\n";
	cout<<"1. Fruit\n";
	cout<<"2. Vegetable\n";
	int input;
	cin>>input;

	if(input == 1)
	{

		fruitNode* temp = new fruitNode;
		if(head == NULL)
		{
			head = temp;
			tail = temp;
		}

		else
		{
			tail->next = temp;
			tail = tail->next;
		}
	}
	


	else if(input == 2)
	{

		vegNode *temp = new vegNode;
		if(head == NULL)
		{
			head = temp;
			tail = temp;
		}

		else
		{
			tail->next = temp;
			tail = tail->next;
		}

	}

	else
		cout<<"Invalid input\n";
}

void itemList::insertNode(string s, int x, int y, float weight, int price, int calories, int units, bool b)
{
	if( b== 1)
	{
		fruitNode *temp = new fruitNode(s, x, y, weight, price, calories, units);
		if(head == NULL)
		{
			head = temp;
			tail = temp;
		}

		else
		{
			tail->next = temp;
			tail = tail->next;
		}
	}

	else
	{
		vegNode *temp = new vegNode(s, x, y, weight, price, calories, units);
		if(head == NULL)
		{
			head = temp;
			tail = temp;
		}
		else
		{
			tail->next = temp;
			tail = tail->next;
		}
	}
}

void itemList::printList()
{
	itemNode *temp = head;
	cout<<"S.No"<<setw(16)<<"ID"<<setw(20)<<"Name"<<setw(20)<<"X"<<setw(20)<<"Y"<<setw(24)<<"Price Per Unit(kg)"<<setw(24)<<"Weight Per Unit(kg)"<<setw(24)<<"Calories per Unit(kg)"<<setw(20)<<"Amount Available"<<setw(8)<<"Time"<<"\n";
	int count = 1;
	while(temp!=NULL)
	{
		cout<<count++<<setw(20)<<temp->returnID()<<setw(20);
		temp->print();
		temp = temp->next;
	}
}

void itemList::searchList(int inp)
{

	if(inp == 1)
	{
		cout<<"Enter the name of item you want to find: ";
		string s;
		cin>>s;
		itemNode *temp = head;
		bool count = 0;
		while(temp!=NULL)
		{
			count = max(temp->searchNode(s), count);
			temp = temp->next;
		}
		if(count == 0)
			cout<<"Not Found"<<endl;
	}

	else if(inp == 2)
	{
		cout<<"Enter location: ";
		int xs, ys;
		cin>>xs>>ys;
		long long int r;
		cout<<"Enter radius: ";
		cin>>r;
		r = r*r;
		itemNode *temp = head;
		int count = 1;
		cout<<"S.No"<<setw(16)<<"ID"<<setw(20)<<"Name"<<setw(20)<<"X"<<setw(20)<<"Y"<<setw(24)<<"Price Per Unit(kg)"<<setw(24)<<"Weight Per Unit(kg)"<<setw(24)<<"Calories per Unit(kg)"<<setw(20)<<"Amount Available"<<setw(8)<<"Time"<<"\n";
		while(temp!=NULL)
		{
			int xt = temp->returnX();
			int yt = temp->returnY(); 
			long long dist = pow(xt - xs, 2) + pow(yt - ys, 2);
			
			if(dist <= r)
			{
				cout<<count++<<setw(20)<<temp->returnID()<<setw(20);
				temp->print();
			}
			temp = temp->next;
		}

		if(count == 0)
			cout<<"No item available in given area\n"<<endl;
	}

	else if(inp == 3)
	{
		cout<<"Enter calories: "; 
		int cal;
		cin>>cal;
		int mincal = INT_MAX, cl = 0;
		int cnt = 0;
		itemNode *tmp = head;
		while(tmp!=NULL)
		{
			if(tmp->returnIsFruit() == 1)
			{
			
				fruitNode *ftemp = (fruitNode *) tmp;
				cnt += ftemp->returnCalories()*ftemp->returnAmount();
			}
			
			else
			{
				vegNode * vtemp = (vegNode *) tmp;
				cnt += vtemp->returnCalories()*vtemp->returnAmount();
			}
			tmp = tmp->next;
		}
		
		if(cnt<cal)
		{
			cout<<"Enough amount not available in the store\n";
			return;
		
		}
		while(cal>0)
		{
			bool flag = 0;
			itemNode *temp = head;
			while(temp != NULL)
			{
				if(temp->returnIsFruit() == 1 && temp->isVisited == 0)
				{
					fruitNode *ftemp = (fruitNode *) temp;
					mincal = min(mincal, ftemp->returnCalories());
				}

				else if(temp->returnIsFruit() == 0 && temp->isVisited == 0) 
				{
					vegNode *vtemp = (vegNode *) temp;
					mincal = min(mincal, vtemp->returnCalories());
				}
				temp = temp->next;
			}

			temp = head;
			while(temp!=NULL)
			{
				if(temp->returnIsFruit() == 1 && temp->isVisited == 0)
				{
					fruitNode *ftemp = (fruitNode *) temp;
					if(ftemp->returnCalories() == mincal)
					{
						if(mincal * ftemp->returnAmount()<cal)
						{
							cal -= mincal * ftemp->returnAmount();
							flag = 1;
							
							cout<<"You can buy "<<ftemp->returnAmount()<<" "<<ftemp->returnName()<<" each containing "<<ftemp->returnCalories()<<" calories"<<endl;
							ftemp->modifyAmount(ftemp->returnAmount());
						}

						else
						{
							int amtreqd = cal/ftemp->returnCalories();
							if(amtreqd!=0)
							{
								cal = 0;
								flag = 1;
								
								cout<<"You can buy "<<amtreqd<<" "<<ftemp->returnName()<<" each containing "<<ftemp->returnCalories()<<" calories"<<endl;
								ftemp->modifyAmount(amtreqd);
							}
						}
						temp->isVisited = 1;
					}
					
				}

				else if(temp->returnIsFruit() == 0 && temp->isVisited == 0) 
				{
					vegNode *vtemp = (vegNode *) temp;
					if(vtemp->returnCalories() == mincal)
					{
						if(mincal * vtemp->returnAmount()<cal)
						{
							cal -= mincal * vtemp->returnAmount();
							flag = 1;
							
							cout<<"You can buy "<<vtemp->returnAmount()<<" "<<vtemp->returnName()<<" each containing "<<vtemp->returnCalories()<<" calories"<<endl;
							vtemp->modifyAmount(vtemp->returnAmount());
						}

						else
						{
							int amtreqd = cal/vtemp->returnCalories();
							if(amtreqd != 0)
							{
								cal = 0;
								flag = 1;
								
								cout<<"You can buy "<<amtreqd<<" "<<vtemp->returnName()<<" each containing "<<vtemp->returnCalories()<<" calories"<<endl;
								vtemp->modifyAmount(amtreqd);
							}
						}
						temp->isVisited = 1;
					}
					
				}
				temp = temp->next;
			}

			mincal = INT_MAX;
			if(flag == 0)
				break;
		}

		itemNode *temp = head;
		while(temp!=NULL)
		{
			temp->isVisited = 0;
			temp = temp->next;
		}
		
		temp = head;
		while(temp!=NULL)
		{
	
			if(temp->returnIsFruit()== 1)
			{
				fruitNode *ftemp = (fruitNode *) temp;
				if(ftemp->returnAmount() == 0)
				{

					// cout<<"Found the node to be deleted\n";
					itemNode *temp2 = head;
					itemNode *temp3 = head;
					while(temp2->next!=temp)
						temp2 = temp2->next;

					temp3 = temp;
					if(temp->next!=NULL)
						temp = temp->next;
					else
						temp = NULL;
					// Deleting Begins
					temp2->next = temp3->next;
					temp3->next = NULL;
					delete temp3;
				
				}

				else
					if(temp->next!=NULL)
						temp = temp->next;
					else
						temp = NULL;
			}
			else
			{
				vegNode *vtemp = (vegNode *) temp;
				if(vtemp->returnAmount() == 0)
				{
					itemNode *temp2 = head;
					itemNode *temp3 = head;
					while(temp2->next!=temp)
					temp2 = temp2->next;

					temp3 = temp;
					if(temp->next!=NULL)
						temp  = temp->next;
					else
						temp = NULL;
				// Deleting Begins
					temp2->next = temp3->next;
					temp3->next = NULL;
					delete temp3;
				}
	
				else
					if(temp->next!=NULL)
						temp = temp->next;
					else
						temp = NULL;
			
			}	
			
		}
	}
}

bool operator ==(fruitNode *obj, string s)
{
	string t = obj->returnName();
	return t == s;
}

bool operator ==(vegNode *obj, string s)
{
		return obj->returnName() == s;
}


void itemList::itemBuy()
{
	cout<<"Enter name: ";
	string s;
	cin>>s;
	cout<<"Enter units/kg to buy: ";
	int amt;
	cin>>amt; 

	itemNode *temp = head;

	long long tid;
	bool b = 0;
	while(temp!=NULL)
	{
		b = max(b, temp->isAvail(s));
		temp = temp->next;
	}
	
	if(b == 0)
	{
		cout<<"Item doesn't exist in store\n";
		return;
	}

	temp = head;
	int count = 0;
	int cost = 0;
	while(temp!=NULL)
	{
		if(temp->returnIsFruit() == 1)
		{
			fruitNode *ftemp = (fruitNode *) temp;
			if(ftemp == s)
			{
				count += ftemp->returnAmount();
			}
		}

		else
		{
			vegNode *vtemp = (vegNode *)temp;
			if(vtemp == s)
			{

				count += vtemp->returnAmount();
			}
		}
		temp = temp->next;
	}

	if(count<amt)
	{
		cout<<"Sufficient amount not available in store\n";
		return;
	}

	long long mini = INT_MAX, dist;
	int it = 15000;
	while(1)
	{
		temp = head;
		while(temp!=NULL)
		{
			if(temp->returnIsFruit() == 1)
			{
			
				fruitNode *ftemp = (fruitNode *) temp;
				if(ftemp == s && temp->isVisited == 0)
				{
					dist = temp->returnX()*temp->returnX() + temp->returnY() * temp->returnY();
					mini = min(mini, dist);
				}
			}
			else
			{
				vegNode *vtemp = (vegNode *)temp;
				if(vtemp == s && temp->isVisited == 0)
				{
					dist = temp->returnX()*temp->returnX() + temp->returnY() * temp->returnY();
					mini = min(mini, dist);
				}
			}
			temp = temp->next;
		}

		long long dist2;
		temp = head;
		int ccount = 0; 
		int mincost = INT_MAX;

		while(temp != NULL)
		{
			if(temp->returnIsFruit() == 1)
			{
				fruitNode *ftemp = (fruitNode *) temp;
				dist2 = temp->returnX()*temp->returnX() + temp->returnY() * temp->returnY();
				if(ftemp == s)
				{
					if(dist2 == mini && temp->isVisited == 0)
					{
						ccount++;
						mincost = min(mincost, ftemp->returnPrice());
					}
				}
			}

			else
			{
				vegNode *vtemp = (vegNode *) temp;
				dist2 = temp->returnX()*temp->returnX() + temp->returnY() * temp->returnY();
				if(vtemp == s)
				{
					if(dist2 == mini && temp->isVisited == 0)
					{
						ccount++;
						mincost = min(mincost, vtemp->returnPrice());
					}
				}	
			}
			temp = temp->next;
		}
   
		temp = head;
		while(temp!=NULL)
		{	
			if(temp->returnIsFruit() == 1)
			{
			
				fruitNode *ftemp = (fruitNode*) temp;
				dist2 = temp->returnX()*temp->returnX() + temp->returnY() * temp->returnY();
				if(ftemp == s)
				{
					if(dist2 == mini && temp->isVisited == 0 && mincost == ftemp->returnPrice())
					{
						if(amt<=ftemp->returnAmount())
						{
							cost += ftemp->returnPrice()*amt;
							ftemp->modifyAmount(amt);
							amt = 0;
						}

						else
						{
							int availamt = ftemp->returnAmount();
							amt -= availamt;
							cost += ftemp->returnPrice()*availamt;
							ftemp->modifyAmount(availamt);
							temp->isVisited = 1;

						}

						break;

					}
					
				}
				
			
			}
			else
			{
				vegNode *vtemp = (vegNode*) temp;
				dist2 = temp->returnX()*temp->returnX() + temp->returnY() * temp->returnY();
				if(vtemp == s)
				{
					if(dist2 == mini && temp->isVisited == 0 && mincost == vtemp->returnPrice())
					{
						if(amt<=vtemp->returnAmount())
						{
							cost += vtemp->returnPrice()*amt;
							vtemp->modifyAmount(amt);
							amt = 0;
						}

						else
						{
							int availamt = vtemp->returnAmount();
							amt -= availamt;
							cost += vtemp->returnPrice()*availamt;
							vtemp->modifyAmount(availamt);
							temp->isVisited = 1;
						}
						break;
					}
					
				}
				
			}
			
			temp = temp->next;
			
		}	

		mini = INT_MAX;
		if(amt == 0)
			break;
	}
	temp = head;
	while(temp!=NULL)
	{
		temp->isVisited = 0;
		temp = temp->next;
	}

	cout<<"Your bill is "<<cost<<endl;
	cout<<"Thanks for shopping with us"<<endl;

	temp = head;
	while(temp!=NULL)
	{

		if(temp->returnIsFruit()== 1)
		{
			fruitNode *ftemp = (fruitNode *) temp;
			if(ftemp->returnAmount() == 0)
			{

				// cout<<"Found the node to be deleted\n";
				itemNode *temp2 = head;
				itemNode *temp3 = head;
				while(temp2->next!=temp)
					temp2 = temp2->next;

				temp3 = temp;
				temp  = temp->next;
				// Deleting Begins
				temp2->next = temp3->next;
				temp3->next = NULL;
				delete temp3;
				
			}

			else
				temp = temp->next;
		}
		else
		{
			vegNode *vtemp = (vegNode *) temp;
			if(vtemp->returnAmount() == 0)
			{
				itemNode *temp2 = head;
				itemNode *temp3 = head;
				while(temp2->next!=temp)
					temp2 = temp2->next;

				temp3 = temp;
				temp  = temp->next;
				// Deleting Begins
				temp2->next = temp3->next;
				temp3->next = NULL;
				delete temp3;
			}

			else
				temp = temp->next;
		}	
	}
}

itemList::~itemList()
{
	itemNode *temp = head;
	while(temp!=NULL)
	{
		itemNode *nxt = temp->next;
		delete temp;
		temp = nxt;
	}
	head = NULL;

}
