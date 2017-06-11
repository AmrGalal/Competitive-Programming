#include <bits/stdc++.h>
using namespace std;
vector<pair <int,int> > ones,threes;

int main()
{
  ios_base::sync_with_stdio(false);
  int n;
  while(scanf("%d",&n) != EOF)
  {
  	ones.clear();
  	threes.clear();
  	for(int i = 0; i < n; i++)
  	for(int j = 0; j < n; j++)
  	{
  		char tmp;
  		scanf("\n%c\n",&tmp);
  		if((int(tmp) - 48) == 1) ones.push_back(make_pair(i,j));
  		else if((int(tmp) - 48) == 3) threes.push_back(make_pair(i,j));
  	}
  	
  	int maxx = INT_MIN;
  	for(int i = 0; i < ones.size(); i++)
  	{
  		int minn = INT_MAX;
	  	for(int j = 0; j < threes.size(); j++)
	  	{
	  		int diff = abs(ones[i].first - threes[j].first) + abs(ones[i].second - threes[j].second);
	  		minn  = min(minn,diff);
	  	}
	  	maxx = max(maxx,minn);
  	}
  	printf("%d\n",maxx);
  }

  return 0;
}
