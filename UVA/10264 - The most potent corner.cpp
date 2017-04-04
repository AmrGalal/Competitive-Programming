#include <vector>
#include <stdio.h>
#include <cmath>
#include <algorithm>
using namespace std;
int N;
struct corner
{
    int data;
    long sum = 0;
    int *p = new int[N];
};
vector <corner> list;
bool compare(corner &a, corner &b)
{
    return a.sum > b.sum;
}

int main()
{
    while(scanf("%d",&N) != EOF)
    {
        list.clear();
        list.resize(pow(2,N));
        for (int i = 0; i < pow(2,N); i++)
        {
            int temp;
            scanf("%d",&temp);
            list[i].data = temp;
        }
        for (int i = 0; i < pow(2,N); i++)
        {
            int count = 0;
            for(int j = 0; j < N; j++)
            {
                int temp = i;
                //printf("The index is %d and j is %d \n",temp, j);
                temp = temp ^ (1u << j);
                list[i].p[count++] = temp;
               // printf("Storing with %d \n",temp);
            }
        }

         for (int i = 0; i < pow(2,N); i++)
        {
            for (int j = 0; j < N; j++)
                    list[i].sum += list[list[i].p[j]].data;
                
        }

        long highestSum = -1; bool found = false;

        for (int i = 0; i < pow(2,N); i++)
            for (int j = 0; j < N; j++)
                if(list[i].sum + list[list[i].p[j]].sum > highestSum)
                        highestSum =list[i].sum + list[list[i].p[j]].sum;
                
        printf("%ld\n",highestSum);

    }
    return 0;
}
