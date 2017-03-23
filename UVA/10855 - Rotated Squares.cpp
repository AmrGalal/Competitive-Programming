#include <iostream>
using namespace std;
char **large;
char **small;
char **rotate;
int lsize,ssize;
int search(char ** a)
{
    int count = 0;
    bool found = true;
    for (int i = 0; i <= lsize-ssize; i++)
    {
        for (int j = 0; j <= lsize-ssize; j++)
        {
            if(large[i][j] == a[0][0])
            {
                for ( int k = 0; k < ssize; k++)
                {
                    for (int m = 0; m < ssize; m++)
 
                        if(large[i+k][j+m] != a[k][m])
                        {
                            found = false;
                            break;
                        }
                    if(!found)
                        break;
                }
                if(found)
                    count++;
                found = true;
            }
        }
 
    }
 
    return count;
}
void rot()
{
    for (int i = 0; i < ssize; i++)
        for (int j = 0; j < ssize; j++)
            rotate[i][j] = small[ssize-1-j][i];
}
int main() {
    while(true)
    {   char temp;
        cin >> lsize >> ssize;
        if(lsize == 0 && ssize == 0)
            break;
        large = new char*[lsize];
        small = new char*[ssize];
        rotate = new char*[ssize];
        for (int i = 0; i < lsize; i++)
            large[i] = new char [lsize];
        for (int i = 0; i < ssize; i++)
        {
            small[i] = new char[ssize];
            rotate[i] = new char[ssize];
        }
        for(int i = 0; i < lsize; i++)
            for ( int j = 0; j < lsize; j++)
            {
                cin >> temp;
                large[i][j] = temp;
            }
 
        for(int i = 0; i < ssize; i++)
            for ( int j = 0; j < ssize; j++)
            {
                cin >> temp;
                small[i][j] = temp;
            }
        cout << search(small) <<" ";
 
        rot();
        cout << search(rotate) <<" ";
        for (int i = 0; i < ssize; i++)
            for (int j = 0; j < ssize; j++)
                small[i][j] = rotate[i][j];
        rot();
        cout << search(rotate) <<" ";
        for (int i = 0; i < ssize; i++)
            for (int j = 0; j < ssize; j++)
                small[i][j] = rotate[i][j];
        rot();
        cout << search(rotate) <<"\n";
    }
    return 0;
}
