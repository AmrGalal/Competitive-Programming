#include <bits/stdc++.h>
using namespace std;
vector<int> values;
vector<int > permu;
set<string> comb;
int main()
{
  ios_base::sync_with_stdio(false);
  values.push_back(50);
  values.push_back(0);
  for(int i = 1; i <= 20; i++)
  {
    values.push_back(i);
    values.push_back(2*i);
    values.push_back(3*i);
  }

  while(1)
  {
    int n; cin >> n;
    if(n<=0) {printf("END OF OUTPUT\n"); break;}
    int rem = n, sz = values.size(), cp = 0;
    comb.clear();
    for(int i = 0; i < sz; i++)
    {
      rem = n;
      rem -= values[i];
      if(rem < 0) continue;

      for(int j = 0; j < sz; j++)
      {
        int s1 = rem;
        s1 -= values[j];

        if(s1 < 0)  continue;

        for(int k = 0; k < sz; k++)
        {
          int s2 = s1;
          s2 -= values[k];
          if(s2 != 0)  continue;
          else {
            cp++;
            permu.clear();
            permu.push_back(values[i]);
            permu.push_back(values[j]);
            permu.push_back(values[k]);
            sort(permu.begin(), permu.end());
            string st = "";
            for(int i = 0;i <3; i++)
              st += to_string(permu[i]);
            comb.insert(st);
          }
        }
      }
    }

    if(cp != 0)
    {
      printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\n",n,comb.size());
      printf("NUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n",n,cp);
    } else  printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n",n);

    for(int i = 0; i < 70; i++)
	cout << '*';
	cout << endl;
  }

  return 0;
}
