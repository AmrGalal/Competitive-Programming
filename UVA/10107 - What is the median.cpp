#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	long number;
	vector <long> arr;
	while(scanf("%ld",&number)!= EOF)
	{
		arr.push_back(number);
		sort(arr.begin(),arr.end());
		if(arr.size() % 2 == 1)
		cout << arr[arr.size()/2] << endl;
		else
		cout << (arr[arr.size()/2] + arr[arr.size()/2 -1]) /2 << endl;
	}
	return 0;
}
