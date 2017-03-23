#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int table[3][3];
int table2[3][3]; //to store the new value
bool flag = false;
int c;
 
void count()
{
    flag = false;
 
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if(table[i][j] != 0)  // we need to recurse more
                flag = true;
    if(flag)
    {
        c++;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
            {
                if(i != 0)
                    table2[i][j] += table[i-1][j];
 
                if(j != 0)
                    table2[i][j] += table[i][j-1];
 
                if(i != 2)
                    table2[i][j] += table[i+1][j];
 
                if(j != 2)
                    table2[i][j] += table[i][j+1];
 
                table2[i][j] %= 2;
            }
        memcpy(table,table2,sizeof(table));
        memset(table2,0,sizeof(table2[0][0])*3*3);
 
        count();
    }
}
 
int main() {
 
    int number;
    string input;
    cin >> number;
    while(number--) {
        c = 0;
        scanf(" ");
        for (int i = 0; i < 3; i++) {
            getline(cin, input);
            for (int j = 0; j < 3; j++)
                table[i][j] = int(input[j]) - 48;
        }
        count();
        if(c == 0)
            cout << -1 << endl;
        else
            cout << c-1 << endl;
    }
    return 0;
}
