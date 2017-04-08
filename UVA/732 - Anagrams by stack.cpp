#include <iostream>
#include <vector>
#include <string>
using namespace std;
int Flen, Tlen;
vector <string> answer;
void dfs(string from, string to, bool i, string progress,string result, string stack,int count, int insertN)
{
    if(count >= 2*Flen)
    {
        if(result == to && i)
            answer.push_back(progress);
        return;
    }
    else
    {
        if(i)
        {
            if(!from.empty() && insertN < Flen)
            {
                stack += from[0]; 
            progress += 'i';
            insertN++;
            from.erase(0,1);}
            else
                return;
        }
        else
            if(!stack.empty())
            {
                progress += 'o';
                result += stack[stack.length()-1];
                stack.pop_back();

               for (int i = 0; i <result.length(); i++)
                   if(result[i] != to[i])
                        return;          
            }
            else 
                return;
        
            count++;
            dfs(from,to,true,progress,result,stack,count,insertN);
            dfs(from,to,false,progress,result,stack,count,insertN);
    }
}

int main()
{
    string from,to;
    while (cin >>from)
    {
        cin >> to;
        answer.clear();
        if(to.length() != from.length())
        {
            cout << '[' << endl << ']' << endl;
            continue;
        }
        else
        {
            int asciF = 0, asciT = 0;
            for (int i = 0;i < from.length(); i++)
            {
                asciF += int(from[i]);
                asciT += int(to[i]);
            }
            if(asciT != asciF)
            {
                cout << '[' << endl << ']' << endl;
                continue;
            }
        }
        Flen = from.length(); Tlen = to.length();
        dfs(from,to,true,"","","",0,0);
        cout << "[\n";
        for (int i = 0; i < answer.size();i++)
            {
                for (int j = 0; j < 2*Flen; j++)
                {
                    cout << answer[i][j];
                    if(j == 2*Flen-1) cout << '\n';
                    else cout << ' ';
                }
            }
        cout << "]\n";

    }
    return 0;
}
