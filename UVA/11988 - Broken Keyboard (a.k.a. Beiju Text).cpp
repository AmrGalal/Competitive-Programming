#include <bits/stdc++.h>
using namespace std;
list<char> myList;
list<char>::iterator it;
int main()
{
  ios_base::sync_with_stdio(false);
  string s;
  while(cin >> s)
  {
  	myList.clear();
    it = myList.end();
    for(int i = 0; i < s.length(); i++)
    {
      if(s[i] == '[')
        it = myList.begin();
      else if(s[i] == ']') {it = myList.end();}
      else myList.insert(it,s[i]);
      

    }
    for(it=myList.begin(); it!=myList.end(); ++it)
      cout << *it;
    cout <<endl;
  }
  return 0;
}
