#include<iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
struct car
{
    int time;
    int side;
    int number;
};
queue <car> Q[2];
int n,t,m;
int timee;
int boatSide;
int arrival [10001];
int main()
{
    int testcases;
    cin >> testcases;
    while(testcases--)
    {
        cin >> n >> t >> m;
        boatSide = 0; //left
        int index = 0;
        timee = 0;
        int count = 0;
        for (int i = 0; i < m; i++)
        {
            int temp;
            string te;
            cin >> temp >> te;
            car a; a.time = temp;
            a.side = te == "left" ? 0 : 1;
            a.number = count++;
            if(te == "left")
                Q[0].push(a);
            else
                Q[1].push(a);
        }
    
        while(!Q[0].empty() || !Q[1].empty())
        {
            if(Q[0].empty())
                index = 1;
            else
                if(Q[1].empty())
                    index = 0;
                else
                    if(Q[index].front().time <= timee)
                        index = index;                  //to avoid getting index by comparing time
                    else
                        if(Q[1].front().time < Q[0].front().time)
                            index = 1;
                            else
                            index = 0;
            
            if(Q[index].front().time > timee)
                timee = Q[index].front().time;

            if(boatSide != index)
                {timee += t; boatSide ^= 1;}

            bool sameSide = true;
            for (int j = 0; j < n && sameSide && !Q[index].empty(); j++)
            {
                int ind = Q[index].front().number;
                Q[index].pop();
                arrival[ind] = timee+t;
                if(!Q[index].empty())
                    sameSide = ((boatSide == Q[index].front().side) && (timee >= Q[index].front().time)); 
            }
            timee += t; boatSide ^= 1; index ^= 1;
        }
          for (int i = 0; i < m; i++)
            cout << arrival[i] << endl;

        if(testcases)
            cout <<endl;
    }
    return 0;
}
