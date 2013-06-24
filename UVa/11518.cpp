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
#define MAXN	(10005)

int n, m, l, ret;
vector < int > g[MAXN];
bool vis[MAXN];

void doit(int x)
{
	if(vis[x]) return;
	vis[x] = true;
	ret++;
	for(int i = 0; i < SZ(g[x]); ++i)
	{
		doit(g[x][i]);
	}
}

int main()
{
	int kase, x, y, z;
	for(scanf("%d",&kase); kase>0; --kase)
	{
		ret = 0;
		fill(vis, false);
		scanf("%d %d %d", &n, &m, &l);
		for(int i = 0; i < MAXN; ++i)
		{
			g[i].clear();
		}
		for(int i = 0; i < m; ++i)
		{
			scanf("%d %d", &x, &y);
			x--, y--;
			g[x].push_back(y);
		}
		for(int i = 0; i < l; ++i)
		{
			scanf("%d", &z);
			z--;
			doit(z);
		}
		printf("%d\n",ret);
	}

	//system("pause");
	return 0;
}
