#include <bits/stdc++.h>
using namespace std;
vector< int > values;
;
int main()
{
  ios_base::sync_with_stdio(false);
  while(1)
  {
    int n; cin >> n;
    if(!n) break;
    values.clear();
    for(int i = 0; i < n; i++)
    {
      int tmp; cin >> tmp; values.push_back(tmp);
    }
    for(int fr1 = 0;fr1 <= n-6; fr1++)
    for(int fr2 = fr1+1;fr2 <= n-5; fr2++)
    for(int fr3 = fr2+1;fr3 <= n-4; fr3++)
    for(int fr4 = fr3+1;fr4 <= n-3; fr4++)
    for(int fr5 = fr4+1;fr5 <= n-2; fr5++)
    for(int fr6 = fr5+1;fr6 <= n-1; fr6++)
    printf("%d %d %d %d %d %d\n",values[fr1],values[fr2],values[fr3],values[fr4],values[fr5],values[fr6]);
    printf("\n");
  }

  return 0;
}
