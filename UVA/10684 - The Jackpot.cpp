#include <bits/stdc++.h>
using namespace std;
int main()
{
  int N;
  while(1)
  {
    scanf("%d",&N);
    if(N == 0 ) break;
    int t, sum = 0, ans = INT_MIN;
    while(N--)
    {
      scanf("%d",&t);
      sum+=t;
      if(sum < 0) sum = 0;
      ans = max(ans,sum);
    }
    if(sum == 0) printf("Losing streak.\n");
    else printf("The maximum winning streak is %d.\n", ans);
  }
  return 0;
}
