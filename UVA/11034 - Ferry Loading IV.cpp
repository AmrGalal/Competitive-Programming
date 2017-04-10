#include <bits/stdc++.h>
using namespace std;
int main()
{
    int testcases;
    cin >> testcases;
    while(testcases--)
    {
        int l,m,count = 0, boatSide = 0;
        queue<int> q[2];
        cin >> l >> m;
        l *= 100;
        for (int i = 0;i < m; i++)
        {
            int le; string s;
            cin >> le >> s;
            if(s == "left")
                q[0].push(le);
            else q[1].push(le);
        }
        while(!q[0].empty() || !q[1].empty())
        {
            int availableLength = l;
            if(!q[boatSide].empty())
            {
                while(true)
                {
                    availableLength -= q[boatSide].front();
                    q[boatSide].pop();
                    if(q[boatSide].empty()) break;
                    if(q[boatSide].front() > availableLength)
                        break;
                }
            }
            else
            {
                boatSide ^= 1;
                count++;
                continue;
            }
            boatSide ^= 1;
            count++;
        }
        cout << count << endl;
    }
    return 0;
}
