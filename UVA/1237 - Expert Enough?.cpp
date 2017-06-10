#include <bits/stdc++.h>
using namespace std;
int testcases, DBn, qs;
struct item
{
  string M; int L,H;
};
bool cmp(item a, item b)
{
  return a.L < b.L;
}
vector<item> DB;
int main()
{
  scanf("%d",&testcases);
  while(testcases--)
  {
    DB.clear();
    scanf("%d",&DBn);
    while(DBn--)
    {
      item a;
      cin >> a.M >> a.L >> a.H;
      DB.push_back(a);
    }
    sort(DB.begin(),DB.end(),cmp);
    scanf("%d",&qs);
    while(qs--)
    {
      int temp, count = 0, index;
      scanf("%d",&temp);
      for(int i = 0; i < DB.size(); i++)
      {

        if(temp < DB[i].L) break;
        if(temp >= DB[i].L && temp <= DB[i].H)
          {
            index = i; count++;
          }
      }
      if(count != 1) cout << "UNDETERMINED\n";
        else cout << DB[index].M << endl;
    }
    if(testcases) cout << endl;
  }
  return 0;
}
