#include <bits/stdc++.h>
using namespace std;
vector <bool> av;
vector <bool> con;
int main()
{
    int testcases; cin >> testcases;
    while(testcases--)
    {
        char c; 
        int edges = 0, vert = 0;
        av.assign(26,false);
        con.assign(26,false);
        while(true) //loop for edges
        {
            cin >> c;
            if(c == '*') break;
            else
            {
                cin >> c;
                cin.ignore();
                int first = int(c) - 65;
                cin >> c; cin.ignore();
                int second = int(c) - 65;
                con[first] = con[second] = true;
                edges++;
            }
        }
       while(cin.peek() == int('*')) cin >> c;
	
       while(true)
       {
            cin >> c; int first = int(c) - 65; 
            vert++;
            av[first] = true;
            if(cin.peek() == 10 || cin.peek() == EOF) break;
            cin >> c; //,
            

       }
        int acorn = 0;
        for (int i = 0; i < 26; i++)
            if(av[i] && !con[i]) acorn++;
        cout << "There are " << vert-edges-acorn << " tree(s) and " << acorn << " acorn(s).\n";
    }
    return 0;
}
