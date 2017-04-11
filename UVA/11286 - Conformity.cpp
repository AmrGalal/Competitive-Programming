#include <bits/stdc++.h>
using namespace std;
int main()
{
    map<string,int> list;
    while(true)
    {
        int number;
        cin >> number;
        if (number == 0) break;
        for (int i = 0; i < number; i++)
        {
            vector<int> temp;
            string freq = "";
            temp.clear();
            for (int j = 0; j < 5; j++)
            {
                int course;
                cin >> course;
                temp.push_back(course);
            }
            sort(temp.begin(),temp.end());
            for(int s = 0; s < 5; s++)
                freq += to_string(temp[s]);
            list[freq]++;
        }
        int countStudents = 0, maxRepeat = -1; 
        for (auto i = list.cbegin(); i != list.cend(); i++)
            maxRepeat = max(maxRepeat,(*i).second);
        
        for (auto i = list.cbegin(); i != list.cend(); i++)
            if((*i).second == maxRepeat)
                countStudents++;

        cout << maxRepeat << endl;
    }
    return 0;
}
