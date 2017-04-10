#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

int main()
{
    string line;
    int countCase = 1;
    bool alphabet[26];
    vector< stack<char> > list;
    while(cin >> line, line != "end")
    {
        int countA = 0, countB; int result;
        fill_n(alphabet,26,false);
        list.clear();
        for (char c: line)
        {
            int value = int(c) - 65;
            if(!alphabet[value])
            {
                countA++;
                alphabet[value] = true;
            }
        }

        for(int i = 0; i < line.length(); i++)
        {
            bool canBePut = false;
            int minIndex = 1000; int minChar = '[';
            if(i == 0)
            {
                stack<char> S;
                list.push_back(S);
                list[0].push(line[i]);
            }
            else
            {
                for (int j = 0; j < list.size(); j++)
                {
                    if(list[j].top() == line[i])        //best case
                    {  
                        canBePut = true;
                        minIndex = j;
                        break;
                    }else
                    if(line[i] < list[j].top() && list[j].top() < minChar)
                    {
                        canBePut = true;
                        minChar = list[j].top(); minIndex = j;
                    }
                }
                if(canBePut)
                    list[minIndex].push(line[i]); //cout << "pushed " << line[i] << " to index: " << minIndex << "\n";}
                else
                {
                    stack<char> S;
                    list.push_back(S);
                    list[list.size()-1].push(line[i]);
                }
            }
        }
        countB = list.size();

        result = min(countA,countB);
        cout << "Case " << countCase++ << ": " << result << endl;
    }

    return 0;
}
