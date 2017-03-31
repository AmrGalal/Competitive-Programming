#include <iostream>
#include<string>
#include <algorithm>
using namespace std;

int main() {
	string in;
	while(1)
	{
		cin >> in;
		if(in == "#")
		break;
		else
		if(next_permutation(in.begin(),in.end()))
			cout << in << endl;
			else
			cout << "No Successor\n";
	}
	return 0;
}
