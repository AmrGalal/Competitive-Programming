#include <bits/stdc++.h>
using namespace std;
struct slot{
    int row, col, data;
};

bool cmp(slot a, slot b)
{
	if(a.row != b.row)
		return a.row < b.row;
	else
		return a.col < b.col;
}

vector <slot> nonZero;
vector <int> column;

int main()
{
    int n,m,number;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
      nonZero.clear();
    	for (int j = 0; j < n; j++)
    	{
    		cin >> number;
    		if(number == 0)
    			cin.ignore();
        for(int i = 0; i < number; i++)
        {
            int x; cin >> x;
            column.push_back(x);
        }

        for(int i = 0; i < number; i++)
        {
            int v; cin >> v;
            slot a;
            a.data = v; a.col = j+1; a.row = column[i];
            nonZero.push_back(a);
        }
        column.clear();
    	}

		sort(nonZero.begin(),nonZero.end(),cmp);
		//for (int i = 0; i < nonZero.size(); i++)
		//	cout << nonZero[i].row << " " << nonZero[i].col << " " << nonZero[i].data << endl;
		cout << m << " " << n <<endl;
		int count,begin = 0, end = 0;
		for (int i = 1; i <= m; i++)
		{
			count = 0;
			begin = end;
			//cout << i << "i\n";
			for(int j = begin; j < nonZero.size(); j++)
				if(nonZero[j].row != i)
					break;
				else count++;
			//cout << "Here is count: " << count << endl;
			//cout << "here is begin: " << begin << endl;
			//cout << "Here is end: " << end << endl;
			end = count + begin;
			if(count == 0)
			{
				cout << count << endl;
				cout << endl;
				continue;
			}

			cout << count;
			for(int j = begin; j < end; j++)
					cout << " " << nonZero[j].col;
			cout << endl;

			for(int j = begin; j < end; j++)
				{
					cout << nonZero[j].data;
					if(j == end - 1)
						cout << endl;
					else
						cout << " ";
				}

		} 
  }
    return 0;
}
