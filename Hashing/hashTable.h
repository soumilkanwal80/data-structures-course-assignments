#include "header.h"

using namespace std;
struct dict
{
    string word;
    string meaning;
    bool isDeleted;
    bool isOccupied;
    dict()
    {
        isDeleted = 0;
        isOccupied = 0;
    }
};

class hashTable
{
private:
    unsigned int hash1(string str);
    unsigned int hash2(string str);
    unsigned int compress(unsigned int);
    dict *hash_table;
    int size_hash_table;
    int no_words;
    int del_words;
    void rehash();
    int spellCheckUtil(string c_word);

public:
    hashTable(int size);
    void add(string s_word, string smeaning, bool isrehash);
    void remove(string c_word);
    unsigned int returnNoWords();
    void spellCheck(string c_word);
    unsigned int next_prime(unsigned int prime);
    int collision;    
};

hashTable::hashTable(int size)
{
    if(size == 0)
        size = 1;
    size_hash_table = size;
    hash_table = new dict[size_hash_table];
    no_words = 0;
    collision = 0;
}

unsigned int hashTable::compress(unsigned int num)
{
    unsigned int a = 3;
    unsigned int b = 7;
    unsigned int p = 9027;
    unsigned int prod = a*num + b;
    prod%=p;
    prod %= size_hash_table;
    return (unsigned int) prod;
}
unsigned int hashTable::hash1(string str)
{
    unsigned int b    = 378551;
    unsigned int a    = 63689;
    unsigned int hash = 0;
    
    for(size_t i = 0; i < str.length(); i++)
    {
        hash = hash * a + str[i];
        a    = a * b;
    }
    
    return compress((hash & 0x7FFFFFFF));
}

unsigned int hashTable::hash2(string str)
{
    unsigned int hash = 1315423911;
    
    for(size_t i = 0; i < str.length(); i++)
    {
        hash ^= ((hash << 5) + str[i] + (hash >> 2));
    }
    
    return compress((hash & 0x7FFFFFFF));
}

void hashTable::add(string s_word, string s_meaning, bool isrehash)
{
    string temp_word = s_word;
    // for(int i=0;i<temp_word.length();i++)
    //     temp_word[i] = tolower(temp_word[i]);
    unsigned int hval1 = hash1(temp_word);
    unsigned int hval2 = hash2(temp_word);

    int i = 0;
    while(1)
    {
        float ftemp = no_words*1.0/size_hash_table;
        if(ftemp>0.5)
        {
            rehash();
        }
        unsigned int pos = (hval1 + i*hval2)%size_hash_table;
        if(i!=0)
        	collision++;

        if(hash_table[pos].isOccupied == 0 || (hash_table[pos].isOccupied == 1 && hash_table[pos].isDeleted == 1))
        {

            hash_table[pos].word = s_word;
            hash_table[pos].meaning = s_meaning;
            hash_table[pos].isOccupied = 1;
            hash_table[pos].isDeleted = 0;
            if(isrehash == 0)
                no_words++;
            break;
        }
        
        else if(hash_table[pos].isOccupied == 1 && hash_table[pos].isDeleted == 0)
        {
        	if(hash_table[pos].word == s_word)
        	{
                cout<<"Updated word's meaning\n";
        		hash_table[pos].meaning = s_meaning;
        		break; 
        	}
            i++;
        }
    }
}

void hashTable::remove(string c_word)
{
    int i=0;
    int hval1 = hash1(c_word);
    int hval2 = hash2(c_word);
    unsigned int key;
    while(1)
    {
        key = (hval1 + i*hval2)%size_hash_table;
        if(i == size_hash_table)
        {
            cout<<"No such word present\n";
            return;
        }
        // if(hash_table[key].isOccupied == 0 || (hash_table[key].isOccupied == 1 && hash_table[key].isDeleted == 1))
        // {
        //     cout<<"No such word present\n";
        //     return;
        // }

        if(hash_table[key].word == c_word)
        {
            if(hash_table[key].isDeleted == 0 && hash_table[key].isOccupied == 1 )
            {
                hash_table[key].isDeleted = 1;
                cout<<"Word deleted!!!\n";
                no_words--;

                return;
            }
        }
        i++;
    }
}

unsigned int hashTable::returnNoWords()
{
    return this->no_words;
}

int hashTable::spellCheckUtil(string c_word)
{
    string temp_word = c_word;
    // for(int i=0;i<temp_word.length();i++)
    //     temp_word[i] = tolower(temp_word[i]);

    unsigned int hval1 = hash1(temp_word);
    unsigned int hval2 = hash2(temp_word);
    int i = 0;
    int pos = hval1;
//    cout<<pos<<endl;
    while(1)
    {
        pos = (hval1 + i*hval2)%size_hash_table;
        if(i == size_hash_table)
            return -1;
        // cout<<i<<" "<<pos<<endl;
//        cout<<hash_table[pos].isOccupied<<" "<<hash_table[pos].isDeleted<<endl;
        if(hash_table[pos].isOccupied == 1 && hash_table[pos].isDeleted == 0 && pos<size_hash_table)
        {
//            cout<<c_word<<" "<<hash_table[pos].word<<endl;
            string temp_word2 = hash_table[pos].word;
            // for(int i=0;i<temp_word2.length();i++)
            //     temp_word2[i] = tolower(temp_word2[i]);

            if(c_word == temp_word2)
            {
                
                return pos;
            }
        }
        
        else if(hash_table[pos].isOccupied == 0 && pos<size_hash_table)
        {
            break;
        }
        i++;
    }
    
    return -1;
    
}


void hashTable::spellCheck(string c_word)
{
    // Check is the original string is present in Hash Table
    int pos = spellCheckUtil(c_word);
//    cout<<pos<<endl;
    if(pos != -1)
    {
        cout<<hash_table[pos].meaning<<endl;
        return;
    }
    
    cout<<"The given word is not present in the dictionary!!!"<<endl;
    vector<string> svec;
    // Case: 1 Character Swaps
    // cout<<"1"<<endl;
    if(c_word.size() != 1)
    {
        for(int i = 0;i<c_word.size() - 1;i++)
        {
            swap(c_word[i], c_word[i+1]);
            pos = spellCheckUtil(c_word);
            if(pos!=-1)
            {
                svec.push_back(c_word);
            }
            swap(c_word[i], c_word[i+1]);
        
        }
    }
    
    // Case 2: inserting a single character between 2 adjacent letters
    // cout<<"2"<<endl;
    for(int i=0;i<c_word.length()+1;i++)
    {
        
        for(char j = 'a';j!='z' + 1;j++)
        {
            string temp = c_word;
            string letter(1, j);
            temp.insert(i, letter);
            pos = spellCheckUtil(temp);
            if(pos!=-1)
            {
                svec.push_back(temp);
            }
            
        }
    }
    // Case 3: Deleting a single character from the word
    // cout<<"3"<<endl;
    for(int i = 0;i<c_word.length();i++)
    {
        string temp = c_word;
        temp.erase(i, 1);
        pos = spellCheckUtil(temp);
        if(pos!=-1)
        {
            svec.push_back(temp);
        }
        
    }
    // Case 4: Replacing a character with another character
    // cout<<"4"<<endl;
    for(int i=0;i<c_word.size();i++)
    {
        char temp = c_word[i];
        for(char j = 'a'; j!='z' + 1;j++)
        {
            c_word[i] = j;
            pos = spellCheckUtil(c_word);
            if(pos!=-1)
            {
                svec.push_back(c_word);
            }
        }
        c_word[i] = temp;
    }
    if(svec.size() == 0)
    {
        cout<<"No similar words are present in dictionary"<<endl;
    }
    
    else
    {
        cout<<"Following are the most similar words present in dictionary: \n";
        for(int i=0;i<svec.size();i++)
        {
            cout<<svec[i]<<endl;
        }
    }
    
}

unsigned int hashTable::next_prime(unsigned int prime)
{
    // if(prime == 0)
    //     prime+=1;
    unsigned int i = prime + 1;
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

void hashTable::rehash()
{
    int new_size = next_prime(2*size_hash_table);
    dict *temp_hash = new dict[new_size];
    for(int i=0;i<size_hash_table;i++)
    {
        temp_hash[i] = hash_table[i];
    }
    collision = 0;
    hash_table = new dict[new_size];
    int old_size = size_hash_table;
    size_hash_table = new_size;
    for(int i=0;i<old_size;i++)
    {
        if(temp_hash[i].isOccupied == 1 && temp_hash[i].isDeleted == 0)
        {
            add(temp_hash[i].word, temp_hash[i].meaning, 1);
        }
    }

    delete[] temp_hash;
}
