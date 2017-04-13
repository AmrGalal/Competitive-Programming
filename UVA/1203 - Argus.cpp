#include <bits/stdc++.h>
using namespace std;
struct query
{
    int ID,value,increase;
};
struct compare
{
    bool operator()(query i, query j)
    {
        if(i.value != j.value)
            return i.value > j.value;
        return i.ID > j.ID;
    }
};
int main()
{
    priority_queue<query, vector< query >, compare> pq;
    int k;
    while(true)
    {
        char c;
        cin >> c;
        if(c == '#')
           break;
        else
        {
            string t; int ID,period;
            cin >> t >> ID >> period;
            query a; a.ID = ID; a.value = a.increase = period;
            pq.push(a);
        }
    }
    cin >> k;
    while(k--)
    {
        query temp;
        temp = pq.top();
        cout << temp.ID << endl;
        pq.pop();
        temp.value += temp.increase;
        pq.push(temp);
    }
    return 0;
}
