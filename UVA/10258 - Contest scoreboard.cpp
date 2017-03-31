#include<string>
#include<vector>
#include<algorithm>
#include <iostream>
#include <sstream>
using namespace std;
struct team
{
	int problems = 0;
	int number = -1;
	bool list[9] = { 0,0,0,0,0,0,0,0,0 };
	int penalty[9] = { 0,0,0,0,0,0,0,0,0};
	int sum = 0;
};

bool compare(team &a, team &b)
{
	if (a.number == -1)
		return false;
	else if (b.number == -1) return true;
	if (a.problems != b.problems)
		return a.problems > b.problems;
	else
		if (a.sum != b.sum)
			return a.sum < b.sum;
		else
			return a.number < b.number;
}
int main()
{
	vector <team> cont;
	string input;
	int number; char temp; string t;
	scanf("%d%c", &number, &temp);
	getline(cin, t);
	while (number--)
	{
		cont.clear();
		cont.resize(100);
		while (getline(cin, input))
		{	
			if (input == "")
				break;
			istringstream iss(input);
			int te, prob, tim; char result;
			iss >> te; te--;
			iss >> prob; prob--;
			iss >> tim;
			iss >> result;

			cont[te].number = te + 1;
			if (result == 'C')
			{
				if (!cont[te].list[prob])
				{
					cont[te].problems++;
					cont[te].list[prob] = true;
					cont[te].penalty[prob] += tim;
				}
			}
			else
				if (result == 'I' && !cont[te].list[prob])
					cont[te].penalty[prob] += 20;
		}
		for (int i = 0; i < 100; i++)
		{
			if(cont[i].number == -1)
			continue;
			for (int j = 0; j < 9; j++)
				if (cont[i].list[j])
						cont[i].sum += cont[i].penalty[j];
		}
		sort(cont.begin(),cont.end(),compare);

		for (int i = 0; (cont[i].number != -1) && i < 100; i++)
			printf("%d %d %d\n", cont[i].number, cont[i].problems, cont[i].sum);

		if (number != 0)
			cout << "\n";
	}
	return 0;
}
