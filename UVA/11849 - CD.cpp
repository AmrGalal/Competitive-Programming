#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N,M; long long count;
    set<int> collection;
    while(true)
    {
        cin >> N >> M;
        collection.clear();
        count = 0;
        if(N == 0 && M == 0) break;
        for (int i = 0; i < N; i++)
        {
            int t; cin >> t;
            if(collection.insert(t).second == false)
                count++;
        }
        for (int i = 0; i < M; i++)
        {
            int t; cin >> t;
            if(collection.insert(t).second == false)
                count++;
        }

        cout << count << endl;
    }
    return 0;
}
