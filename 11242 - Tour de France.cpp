#include <bits/stdc++.h>
using namespace std;
vector< double > values;
vector<int> frontT,rearT;
int f,r;
int testcases;
int main()
{
  ios_base::sync_with_stdio(false);
  while(1)
  {
    frontT.clear();
    rearT.clear();
    cin >> f;
    if(!f) break;
    cin >> r;
    int tmp;
    for(int i = 0; i < f; i++) {cin >> tmp; frontT.push_back(tmp);}
    for(int i = 0; i < r; i++) {cin >> tmp; rearT.push_back(tmp);}

    for(int i = 0; i < f; i++)
    for(int j = 0; j < r; j++)
    {
      values.push_back(rearT[j]*1.0/frontT[i]);
    }
    
    sort(values.begin(),values.end());
    double maxe = -1e9;
    
    for(int i = 1; i < values.size();i++)
    {
      maxe = max(maxe,values[i]/values[i-1]);
    }
    cout << fixed << setprecision(2) << maxe << endl;
  }

  return 0;
}
