#include <bits/stdc++.h>
using namespace std;
map<char,int> myMap;
vector < vector <int> > adjList;
vector<bool> awake;
vector<int> toBeAdded;
int total,connections;
char c1,c2,c3;

int main()
{
  while(1)
  {
  	int v = 0,years = 0;
  	scanf("%d",&total);

  	awake.clear();
  	adjList.clear();
  	myMap.clear();
    toBeAdded.clear();
  	awake.assign(total,0);
  	adjList.resize(total);

  	scanf("%d\n%c%c%c\n",&connections,&c1,&c2,&c3);
  	myMap[c1]=v++; myMap[c2]=v++; myMap[c3]=v++;
  	awake[myMap[c1]] = 1; awake[myMap[c2]] = 1; awake[myMap[c3]] = 1;

    while(connections--)
    {
      scanf("%c%c\n",&c1,&c2);

      if(myMap.find(c1) == myMap.end())
      {
        myMap[c1] = v++;
        awake[myMap[c1]] = 0;
      }

      if(myMap.find(c2) == myMap.end())
      {
        myMap[c2] = v++;
        awake[myMap[c2]] = 0;
      }
      adjList[myMap[c2]].push_back(myMap[c1]);
      adjList[myMap[c1]].push_back(myMap[c2]);
    }

    while(1)
    {
      int sumAdded = 0; bool allAwake = true;
      for(int i = 0; i < adjList.size(); i++)
        if(!awake[i])
        {

          allAwake = false;
          int count = 0;
          for(int j = 0; j < adjList[i].size(); j++)
          {
            if(awake[adjList[i][j]])
              count++;   //          printf("Not awake connected %d\n",adjList[i][j]);}
            if(count == 3)
            {
              toBeAdded.push_back(i);
              sumAdded++;
              break;
            }
          }

        }

      years++;             //printf("One year passed \n");

      for(int i =0; i < toBeAdded.size();i++)
        awake[toBeAdded[i]] = 1;
        
	  if(allAwake)
      {
        printf("WAKE UP IN, %d, YEARS\n",years-1);
        break;
      } 
      else if(sumAdded == 0)
      {
        printf("THIS BRAIN NEVER WAKES UP\n");
        break;
      }
       
    }
  	if(cin.peek() == EOF) break;
  }
  return 0;
}
