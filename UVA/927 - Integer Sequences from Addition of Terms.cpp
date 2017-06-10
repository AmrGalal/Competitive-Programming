#include <bits/stdc++.h>
using namespace std;
vector<int> coeff;
int testcases;
int main()
{
  ios_base::sync_with_stdio(false);
  cin >> testcases;
  while(testcases--)
  {
    coeff.clear();
    int degree; cin >> degree;
    for(int i = 0; i < degree+1; i++){int tmp; cin >> tmp; coeff.push_back(tmp);}
    int d,k;
    cin >> d>> k;
    long long nNeeded,sum = 0, i=1;
    while(1)
    {
      sum += i*d;
      if(k <= sum)
      {
        nNeeded = i;
        break;
      }
      i++;
    }
    long long result = 0;
    for(int i = 0; i < coeff.size(); i++)
    {
      result += coeff[i] * pow(nNeeded,i);
    }
    cout << result << endl;
  }
  return 0;
}
