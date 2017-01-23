#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
using namespace std;
#define pii pair<int,int>
int main()
{
	pii a,b,c;
	cin >> a.first >> a.second;
	cin >> b.first >> b.second;
	cin >> c.first >> c.second;
	pii v1,v2,v3,i1,i2,i3;
	v1.first = a.first - b.first;
	v1.second = a.second - b.second;
	i1.first = -v1.first, i1.second = -v1.second;

	v2.first = b.first - c.first;
	v2.second = b.second - c.second;
	i2.first = -v2.first, i2.second = -v2.second;

	v3.first = c.first - a.first;
	v3.second = c.second - a.second;
	i3.first = -v3.first, i3.second = -v3.second;

	set<pii> s;
	s.insert(pii(a.first + v2.first, a.second + v2.second));
	s.insert(pii(a.first + i2.first, a.second + i2.second));
	s.insert(pii(b.first + v3.first, b.second + v3.second));
	s.insert(pii(b.first + i3.first, b.second + i3.second));
	s.insert(pii(c.first + v1.first, c.second + v1.second));
	s.insert(pii(c.first + i1.first, c.second + i1.second));
	cout << s.size() << endl;
	for(set<pii>::iterator it = s.begin();it!=s.end();it++)
	{
		cout << it->first << ' ' << it->second << endl;
	}





	return 0;
}