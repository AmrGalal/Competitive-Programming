#include <bits/stdc++.h>
using namespace std;
int testcases;
int frshps;
vector<int> p;
vector<int> rankk;
vector<int> sum;
map<string,int> nameToInd;

int findSet(int i)
{
  if(p[i] == i)
    return p[i];
  else return p[i] = findSet(p[i]);
}

bool isSameSet(int i,int j)
{
  return findSet(i) == findSet(j);
}

void UnionSet(int i, int j)
{
  if(!isSameSet(i,j))
  {
    int p1 = findSet(i); int p2 = findSet(j);
    if(rankk[p1] > rankk[p2])
    {
      p[p2] = p1;
      sum[p1] += sum[p2];
    }else
    {
      p[p1] = p2;
      sum[p2] += sum[p1];
      if(rankk[p1] == rankk[p2])
        rankk[p2]++;
    }
  }
}

int main()
{
  scanf("%d",&testcases);
  while(testcases--)
  {
    int v = 0;                //value of each name
    nameToInd.clear();
    p.clear();
    rankk.clear();
    sum.clear();
    scanf("%d",&frshps);
    while(frshps--)
    {
      string n1,n2;
      cin >> n1 >>n2;
      if(nameToInd.find(n1) == nameToInd.end())    //n1 not available
      {
        nameToInd[n1] = v++;
        p.push_back(v-1);
        rankk.push_back(0);
        sum.push_back(1);
        p[p.size()-1] = p.size() - 1;
      }

      if(nameToInd.find(n2) == nameToInd.end())    //n2 not available
      {
        nameToInd[n2] = v++;
        p.push_back(v-1);
        rankk.push_back(0);
        sum.push_back(1);
        p[p.size()-1] = p.size() - 1;
      }
      UnionSet(nameToInd[n1],nameToInd[n2]);
      printf("%d\n",sum[findSet(nameToInd[n1])]);
    }
  }
  return 0;
}
