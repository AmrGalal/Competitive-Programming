#include <bits/stdc++.h>
using namespace std;
vector < queue<int> > stations;
int main()
{
    int testcases;
    cin >> testcases;
    while(testcases--)
    {
        int n,s,q;
        cin >> n >> s >> q;
        int position = 0;
        int timee = 0;
        stations.clear();
        stack<int> carrier;
        for (int i = 0; i < n; i++)
        {
            queue<int> temp; 
            int number; cin >> number;
            for (int j = 0; j < number; j++)
            {
                int cargo; cin >> cargo; cargo--;
                temp.push(cargo);
            }
            stations.push_back(temp);
        }

        while(true)
        {
            while(!carrier.empty() && (carrier.top() == position || stations[position].size() < q))
            {
                int save = carrier.top();
                carrier.pop(); timee += 1;
                if(save != position)    //platfrom B
                stations[position].push(save);
            }
            
            while(carrier.size() < s && !stations[position].empty())
            {
                int save = stations[position].front();
                carrier.push(save);
                stations[position].pop(); timee += 1;
            }
            position = (position + 1) % n;
            bool done = true;
            for (int i = 0; i < n; i++)
             if(!stations[i].empty())
                done = false;
            if(done && carrier.empty()) break;
            timee += 2;
        }  
        cout << timee << endl;
    }
    return 0;
}
