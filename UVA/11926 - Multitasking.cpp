#include <stdio.h>
#include <bitset>
using namespace std;
bitset<1000010> list;

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m), (n || m))
    {
        int start,end;
        bool conflict = false;
        list.reset();
        for (int i = 0; i < n; i++)
        {
            scanf("%d%d",&start,&end);
            for (size_t j = start; (j < end) && !conflict; ++j)
            {
                if(list[j] == 1)
                    conflict = true;
                else
                    list[j] = 1;
            }
        }

        int repeat;
        for(int i = 0; i < m; ++i)
        {
            scanf("%d%d%d",&start,&end,&repeat);
            for(size_t k = 0; (k < 1000001 - end) & !conflict; k += repeat)
            {
                for (size_t j = start+k; j < (end+k) && !conflict; ++j)
                if(list[j] == 1)
                    conflict = true;
                else
                    list[j] = 1;
            }
        }

        if(conflict)
        printf("CONFLICT\n");
        else
        printf("NO CONFLICT\n");
    }
    return 0;
}
