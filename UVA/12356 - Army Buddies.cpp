#include <iostream>
using namespace std;
int s,b;
int l,r;
 
int main() {
	int left[100000];
	int right[100000];	
	while(1)
	{
		cin >> s >> b;
 
		if((s == 0) && (b == 0))
		break;
 
		for (int i = 1; i <= s; i++)
		{
			left[i] = i-1;
			right[i] = i+1;
		}
 
		right[s] = -1;
		left[1] = -1;
 
		while(b--)
		{
			cin >> l >> r;
 
			if(left[l] != -1)
			right[left[l]] = right[r];
 
			if(right[r] != -1)
			left[right[r]] = left[l];
 
			if(left[l] == -1)
			cout << "*";
			else
			cout << left[l];
 
			if(right[r] == -1)
			cout << " *\n";
			else
			cout << " " << right[r] << endl;
 
		}
		cout <<"-\n";
	}
	return 0;
}
