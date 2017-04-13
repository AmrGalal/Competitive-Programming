#include <bits/stdc++.h>
using namespace std;
int main()
{
    priority_queue<int> pq;
    stack<int> s;
    queue<int> q;
    vector<bool> flags;
    int n;
    while(cin >> n)
    {
        flags.clear();
        flags.resize(3,true);       //all data structures are into consideration
        while(!s.empty()) s.pop();
        while(!q.empty()) q.pop();
        while(!pq.empty()) pq.pop();
        int command,x;
        while(n--)
        {
            cin >> command >> x;
            if(command == 1)
            {
                s.push(x);
                q.push(x);
                pq.push(x);
            }
            else
            {
                int sout,qout,pqout;
                if(!s.empty()) {sout = s.top(); s.pop();} else flags[0] = false;
                if(!q.empty()){qout = q.front(); q.pop();} else flags[1] = false;
                if(!pq.empty()){pqout = pq.top(); pq.pop();} else flags[2] = false;
                if(sout != x)
                    flags[0] = false;
                if(qout != x)
                    flags[1] = false;
                if(pqout != x)
                    flags[2] = false;
            }
        }
        int count = 0,index; 
        for (int i = 0; i < 3; i++)
            if(flags[i]) {count++; index = i;}
        
        if(count == 0)
            cout << "impossible\n";
        else
            if(count > 1)
                cout << "not sure\n";
            else
                if(index == 0)
                    cout << "stack\n";
                else
                    if(index == 1)
                        cout << "queue\n";
                    else cout << "priority queue\n";

    }
    return 0;
}
