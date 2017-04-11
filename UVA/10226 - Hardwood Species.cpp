#include <bits/stdc++.h>
using namespace std;
int main()
{
    map<string,int> list;
    int testcases;
    cin >> testcases;
    cin.ignore();
    cin.ignore();
    while(testcases--)
    {
        float count = 0;
        list.clear();
        string tree;
        while(getline(cin,tree)&& tree != "")
        {
            list[tree]++;
            count++;
        }
        for(auto it=list.cbegin(); it != list.cend(); it++)
        {
            cout << fixed;
            cout << (*it).first << " " << setprecision(4) << (*it).second * 100/count << endl;
        }
        if(testcases)
        	cout << endl;
    }
    return 0;
}
