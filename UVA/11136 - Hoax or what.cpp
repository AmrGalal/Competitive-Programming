#include <bits/stdc++.h>
using namespace std;
int main()
{
    multiset<int> urn;
    multiset<int>::iterator it;
    while(true)
    {
        int n; cin >> n;
        if(n == 0) break;
        urn.clear();
        long long count = 0;
        for (int i = 0; i < n; i++)
        {
            int k;
            cin >> k;
            for (int j = 0; j < k; j++)
            {
                int temp; 
                cin >> temp;
                urn.insert(temp);
            }
            it = urn.end();
            it--;
            count += *it;
            urn.erase(it);
            it = urn.begin();
            count -= *it;
            urn.erase(it);
        }
        cout << count << endl;
    }
    return 0;
}
