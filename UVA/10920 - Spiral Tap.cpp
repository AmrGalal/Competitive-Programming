#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
long long size,number;
int main()
{
    while(true)
    {
        scanf("%lld%lld",&size,&number);
        if(size==0 && number==0)
        break;
        if(size == 1)
        {
        	printf("Line = %lld, column = %lld.\n", 1, 1);
        	continue;
        }
        bool found = false;
        ll ring = sqrt(number);
        if(ring % 2 == 0)
            ring++;
        if(number > ring*ring)
        ring += 2;
        ll count = ring*ring;
        ll order = ring - ring/2;
        ll  x,y;
        y = (size/2) + order - 1;
        x = (size/2) - order + 1;
        //printf("Ring = %lld, order = %lld, x = %lld, y = %lld.\n", ring , order, x, y);
        if(number == 1)
        {printf("Line = %lld, column = %lld.\n", size-x, y+1); continue;}
        while(true)
        {
            if(found)
                break;
            for(int i = 0; i < ring-1 && !found; i++,count--)
                if(count == number)
                { found = true; break;}
                else
                    x++;
                
              for(int i = 0; i < ring-1 && !found; i++,count--)
                if(count == number)
                { found = true; break;}
                else
                {
                    y--;
                } 

                for(int i = 0; i < ring-1 && !found; i++,count--)
                if(count == number)
                { found = true; break;}
                else
                {
                    x--;
                }
                
              for(int i = 0; i < ring-1 && !found; i++,count--)
                if(count == number)
                { found = true; break;}
                else
                {
                    y++;
                }  

               printf("Line = %lld, column = %lld.\n", size-x, y+1);
        }

    }
    return 0;
}
