#include <bits/stdc++.h>
using namespace std;
map <int,int> mapToIndex;
map <int,int>::iterator it;
vector <vector<int> > numbers;
int n,m;

int main()
{
  while(scanf("%d%d",&n,&m) != EOF)
  {
    int count = 0;
    mapToIndex.clear();
    numbers.clear();
    numbers.resize(100001);
    for(int i = 0; i < n; i++)
    {
      int temp;
      scanf("%d",&temp);
      if(mapToIndex.find(temp) == mapToIndex.end()) //number isn't in the map
      {
        mapToIndex[temp] = count++;
      }
      numbers[mapToIndex[temp]].push_back(i+1);
    }
    for (int i = 0; i < m; i++)
    {
      int k,v;
      scanf("%d%d",&k,&v);
      if(numbers[mapToIndex[v]].size() >= k)
      {
        printf("%d\n",numbers[mapToIndex[v]][k-1]);
      }
      else
      {
        printf("%d\n",0);
      }
    }

  }
  return 0;
}
