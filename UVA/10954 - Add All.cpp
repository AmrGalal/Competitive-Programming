#include <bits/stdc++.h>
using namespace std;
int main()
{
    priority_queue<int> pq;
    while(true)
    {
        int N;
        cin >> N;
        int count = 0;
        while(!pq.empty()) pq.pop();
        if(N == 0)break;
        else
        {
            for (int i = 0;i < N; i++)
            {
                int t; cin >> t;
                pq.push(-t);
            }
            while(pq.size() > 1)
            {
                int l1,l2;
                l1 = -1*pq.top(); pq.pop();
                l2 = -1*pq.top(); pq.pop();
                count = count + l1 + l2;
                pq.push(-1*(l1+l2));
            }
        }
        cout << count << endl;
    }
    return 0;
}
