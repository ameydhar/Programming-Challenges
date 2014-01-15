#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cassert>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <complex>
#include <cctype>
#include <ctime>
using namespace std;

//Main code begins here
int FindLargestUnique(vector < int > a)
{
	int n = a.size();
	map < int, int > m;
	int lo = 0, hi = 0, ret = 0;
	while(hi < n)
	{
		if(m.find(a[hi]) == m.end())
		{
			m[a[hi]]++;
			hi++;
		}
		else
		{
			ret = max(ret, hi - lo);
			while(a[lo] != a[hi])
			{
				m.erase(a[lo]);
				lo++;
			}
			lo++;
			hi++;
		}
	}
	ret = max(ret, hi - lo);
	return ret;
}

int main()
{
	int kase, x, n;
	for(scanf("%d", &kase); kase > 0; --kase)
	{
		scanf("%d", &n);
		vector < int > a;
		for(int i = 0; i < n; ++i)
		{
			scanf("%d", &x);
			a.push_back(x);
		}
		int ret = FindLargestUnique(a);
		printf("%d\n", ret);
	}

	//system("pause");
	return 0;
}
