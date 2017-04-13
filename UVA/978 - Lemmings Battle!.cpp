#include <bits/stdc++.h>
using namespace std;
int main()
{
    int testcases;
    cin >> testcases;
    multiset<int> green,blue;
    multiset<int>::iterator git,bit;
    vector <int> greenS,blueS;
    while(testcases--)
    {
        int B,SG,SB;
        cin >> B >> SG >> SB;
        green.clear();
        blue.clear();
        int temp;

        for (int i = 0; i < SG; ++i)
        {
            cin >> temp;
            green.insert(temp);
        }

        for (int i = 0; i < SB; ++i)
        {
            cin >> temp;
            blue.insert(temp);
        }
        
        while(!green.empty() && !blue.empty())
        {
            int count = 0;
            greenS.clear();
            blueS.clear();
            while(count < B && !green.empty() && !blue.empty())
            {
                git = green.end();
                git--;
                greenS.push_back(*git);
                green.erase(git);
                bit = blue.end();
                bit--;
                blueS.push_back(*bit);
                blue.erase(bit);
                count++;
            }

            for (int i =0; i < count; i++)
            {
                int minn = min(blueS[i],greenS[i]);
                blueS[i] -= minn;
                greenS[i] -= minn;
                if(blueS[i] != 0) blue.insert(blueS[i]);
                if(greenS[i] != 0) green.insert(greenS[i]);
            }
        }

        if(green.empty() && blue.empty()) cout << "green and blue died\n";
        else
        {
            if(green.empty()) {cout << "blue wins\n";
            for(auto r = blue.crbegin(); r != blue.crend(); r++)
                cout << *r << endl;}
            else
            {
                cout << "green wins\n";
                for(auto r = green.crbegin(); r != green.crend(); r++)
                cout << *r << endl;
            }
        }
        if(testcases)
            cout << endl;
    }

    return 0;
}
