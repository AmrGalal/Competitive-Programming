#include <bits/stdc++.h>
using namespace std;
int main()
{
    int testcases;
    map<int,int> lastUsed;  //map each int to the index it was last used
    cin >> testcases;
    vector<int> flakes;
    while(testcases--)
    {
        int number;
        cin >> number;
        int count = 0;
        lastUsed.clear();
        flakes.clear();
        while(number--)
        {
            int x; cin >> x;
            lastUsed[x] = -1;
            flakes.push_back(x);
        }
        int maxCount = -1;
        int saveIndex = 0; //to save where the new sequence started
        for (int i = 0; i <flakes.size(); i++)
        {
            if(lastUsed[flakes[i]] >= saveIndex) //if the number was called after sequence started
            {
                saveIndex = lastUsed[flakes[i]] + 1;
                count = i - lastUsed[flakes[i]];
            }
            else count++;
            lastUsed[flakes[i]] = i;
            maxCount = max(maxCount,count);
        }
        cout << maxCount << endl;
    }

    return 0;
}
