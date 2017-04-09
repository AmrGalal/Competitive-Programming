#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int number;

int main()
{
    vector <int> from;
    vector <int> to;                
    while(cin >> number,number > 0)
    {
        while(true)
        {
            bool end = false;
            from.clear();
            to.clear();
            for (int i = 1; i <= number; i++)
            {
                int temp;
                cin >> temp; if(temp == 0) { end = true; break;}
                from.push_back(i);
                to.push_back(temp);
            }
            if(end) break;
            int fromIndex = 0;
            int toIndex = 0;
            stack <int> S;

            while(true)
            {
                if(!S.empty())
                {
                   if(S.top() == to[toIndex])
                   {
                        S.pop();
                        toIndex++;
                        continue;
                   }
                }
                if(fromIndex >= number) break;
                S.push(from[fromIndex++]);
            }

            if(S.empty())
                cout << "Yes\n";
            else
                cout << "No\n";
        }
        cout << endl;
    }
    return 0;
}
