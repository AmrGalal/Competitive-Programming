#include <stdio.h>
using namespace std;
int main()
{
    int N;
    int a,b;
    while(true)
    {
        scanf("%d",&N);
        if(N == 0) break;
        a = 0; b = 0; 
        bool turnA = true;
        for (int i = 0; i < 32; i++)
            if(((N >> i) & 1) == 1)
                {
                    if(turnA)
                            a = a ^ (1u << i);
                        else
                            b = b ^ (1u << i);
                    turnA = !turnA;
                }
        printf("%d %d\n",a,b);
    }
    return 0;
}
