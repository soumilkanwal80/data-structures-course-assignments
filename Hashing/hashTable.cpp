#include "header.h"
using namespace std;

unsigned int next_prime(unsigned int prime)
{
    unsigned int i = prime;
    while(1)
    {
        int count = 0;
        for(unsigned int j = 2;j*j<=i;j++)
        {
            if(i%j == 0)
            {
                count++;
                break;
            }
        }

        if(count == 0)
            return i;
        i++;
    }
}


int main()
{
	cout<<"Enter the name of file\n";
	string s = "words.txt";
	cin>>s;

	fstream f;
	f.open(s.c_str(), ios::in);
	while(!f.is_open())
	{
		cout<<"Wrong File Name\nEnter the name of file: ";
		cin>>s;
		f.open(s.c_str(), ios::in);
	}
	int size_hash_table = 2003;
	cout<<"Do you want to enter the size of hash table\n1. Yes\n2. No\n";
	bool choice;
	cin>>choice;
	if(choice & 1)
		cin>>size_hash_table;
	hashTable ht(next_prime(size_hash_table));
	string word, meaning;
	while(f>>word)
	{
		for(int i=0;i<word.size();i++)
			word[i] = tolower(word[i]);
		getline(f, meaning);
		// cout<<word<<meaning<<endl;
		ht.add(word, meaning, 0);
	}
	//cout<<ht.collision<<endl;
	cout<<"No of words read: "<<ht.returnNoWords()<<endl;
	int inp;
	cin.clear();
	while(1)
	{
		cout<<"1. Add entry\n2. Remove Key\n3. Number of Words\n4. Spell Check Word\n5. Exit\n";
		// scanf("%d", &inp);
		cin>>inp;

		if(inp == 1)
		{
			cout<<"Enter word: ";
			cin>>word;
			for(int i=0;i<word.size();i++)
				word[i] = tolower(word[i]);
			cout<<"Enter Meaning: ";
			// cin>>meaning;
			cin.ignore();
			getline(cin, meaning);
			ht.add(word, meaning, 0);
		}

		else if(inp == 2)
		{
			cout<<"Enter a word to remove\n";
			cin>>word;
			cin.ignore();
			for(int i=0;i<word.size();i++)
				word[i] = tolower(word[i]);
			ht.remove(word);
		}

		else if(inp == 3)
		{
			cout<<"No of words are: "<<ht.returnNoWords()<<endl;
		}

		else if(inp == 4)
		{
			cout<<"Enter word: ";
			cin>>word;
			for(int i=0;i<word.size();i++)
				word[i] = tolower(word[i]);
			ht.spellCheck(word);
		}
		else
		{
			break;
		}

	}
}
