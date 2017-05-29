#include <bits/stdc++.h>
using namespace std;
vector <int> p;
int testcases;
void UnionInit(int size)
{
  p.clear();
  p.resize(size+1);
  for(int i =0; i < size; i++)
  {
    p[i] = i;
  }
}
int findSet(int i)
{
  if(p[i] == i)
  return p[i];
  else
  return p[i] = findSet(p[i]);
}
bool isSameSet(int i, int j)
{
  return findSet(i) == findSet(j);
}
void UnionSet(int i, int j)
{
  if(!isSameSet(i,j))
  {
    int p1 = findSet(i);
    int p2 = findSet(j);
    p[p1] = p2;
  }
}
int main()
{
  scanf("%d",&testcases);
  while(testcases--)
  {
    int succ = 0,unsucc = 0;
    int machines;
    scanf("\n%d\n",&machines);
    UnionInit(machines);
    char c; int m1,m2;
    while(1)
    {
      string s;
      if(!getline(cin,s) || s.empty()) break;
      sscanf(s.c_str()," %c %d %d",&c,&m1,&m2);
      if(c == 'c')
        UnionSet(m1,m2);
      else
      {
        if(isSameSet(m1,m2)) succ++;
        else unsucc++;
      }
    }
    printf("%d,%d\n",succ, unsucc);
    if(testcases) {printf("\n"); scanf(" ");}
  }
  return 0;
}
