#include <bits/stdc++.h>
using namespace std;
vector< int > values;
int testcases;
int main()
{
  ios_base::sync_with_stdio(false);
  cin >> testcases;
  while(testcases--)
  {
    int n; cin >> n;
    values.clear();
    int count = 0;
    for(int i = 0; i < n; i++)
    {
      int tmp; cin >> tmp; values.push_back(tmp);
      for(int j = 0; j < i && i != 0; j++)
      {
        if(values[j]<= values[i])
        count++;
      }
    }
    cout << count << endl;
  }

  return 0;
}
