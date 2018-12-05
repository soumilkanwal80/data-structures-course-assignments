#include "header.h"

using namespace std;
int main()
{
    string file = "capitals.txt";
    cout<<"Enter file name: ";
    cin>>file;
    fstream f;
    vector<string> s;
    f.open(file.c_str(), ios::in);
    string state1, state2;
    float dist;
    while(f>>state1)
    {
        f>>state2>>dist;
        s.push_back(state1);
        s.push_back(state2);
    }
    sort(s.begin(), s.end());
    s.erase(unique(s.begin(), s.end()), s.end());
    f.close();
    f.open(file.c_str(), ios::in);
    Graph g(s);
    int choice;
    while(f>>state1)
    {
        
        f>>state2>>dist;
        g.insert(state1, state2, dist);
    }
    f.close();
    
    while(1)
    {
        cout<<"1. Distance\n2. Hops\n3. Largest Area\n4. Exit\n";
        cin>>choice;
        if(choice == 1 || choice == 2)
        {
            string from, to;
            cin>>from>>to;
            g.dijkstra(from, to, choice);
        }
        
        else if(choice == 3)
        {
            g.largestArea();
        }
        
        else
            break;
    }
    
}
