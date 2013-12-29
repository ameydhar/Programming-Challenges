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

//Commonly used macros
#define FOREACH(i,a)    for(typeof((a).begin()) i=(a).begin();i!=(a).end();i++)
#define SZ(a)           (int)(a.size())
#define ALL(a)          (a).begin(),(a).end()
#define SORT(a)         sort(ALL(a));
#define REVERSE(a)      reverse(ALL(a))
#define UNIQUE(a)       SORT(a),(a).resize(unique(ALL(a))-(a).begin())
#define IN(a,b)         ((b).find(a)!=(b).end())
#define fill(x,a)       memset(x, a, sizeof(x))
#define abs(a)          ((a)<0?-(a):(a))
#define maX(a,b)        ((a)>(b)?(a):(b))
#define miN(a,b)        ((a)<(b)?(a):(b))
#define checkbit(n,b)   ((n>>b)&1)
#define INDEX(arr,ind)	(lower_bound(all(arr),ind)-arr.begin())
#define FREOPEN 			freopen("in.txt","r",stdin); freopen("out.txt","w",stdout)

//Main code begins here
int m[105][105], to[105];
int a, b, n, c = 1;

int main()
{
	while(scanf("%d %d", &a, &b), (a || b))
	{
		fill(to, -1);
		for(int i = 0; i < 105; ++i)
		{
			for(int j = 0; j < 105; ++j)
			{
				if(i == j) m[i][j] = 0;
				else m[i][j] = (int)1e9;
			}
		}
		n = 0;
		if(to[a] == -1) to[a] = n++;
		if(to[b] == -1) to[b] = n++;
		m[to[a]][to[b]] = 1;
		while(scanf("%d %d", &a, &b), (a || b))
		{
			if(to[a] == -1) to[a] = n++;
			if(to[b] == -1) to[b] = n++;
			m[to[a]][to[b]] = 1;
		}
		for(int k = 0; k < n; ++k)
		{
			for(int i = 0; i < n; ++i)
			{
				for(int j = 0; j < n; ++j)
				{
					m[i][j] = min(m[i][j], m[i][k] + m[k][j]);
				}
			}
		}
		double s = 0.0;
		for(int i = 0; i < n; ++i)
		{
			for(int j = 0; j < n; ++j)
			{
				s += m[i][j];
			}
		}
		s /= (double)n*(n - 1.0);
		printf("Case %d: average length between pages = %.3lf clicks\n", c++, s);
	}

	//system("pause");
	return 0;
}
