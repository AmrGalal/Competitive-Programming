#include <iostream>
#include <map>
#include <iomanip>
#include <string>
using namespace std;
map <char,int> table;
int result;
void process(string line)
{
    for (int i =0; i < line.length(); i++)
        result += table[line[i]];
}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int number,strlines,charlines,value; char temp; string line;
    cin >> number;
    while(number--)
    {
        result = 0;
        cin >> charlines;
        while(charlines--)
        {
            cin >> temp >> value;
            table[temp] = value;
        }
        cin >> strlines;
        strlines++; //it takes /n for the first time
        while(strlines--)
        {
            getline(cin,line);
            process(line);
        }

        cout << fixed << setprecision(2) << double(result/100.0) << '$' << endl;
        table.clear();
    }
    return 0;
}
