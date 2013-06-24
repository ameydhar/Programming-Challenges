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
#define FREOPEN 			freopen("in.txt","r",stdin); freopen("out2.txt","w",stdout)

//Main code begins here
#define MAXN	(25)

int m, n, ret, c;
int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};
char g[MAXN][MAXN];
char land, water;

void startmove(int x, int y)
{
	if(x<0 || x>=m || y<0 || y>=n) return;
	if(g[x][y] != land) {water = g[x][y]; return;}
	g[x][y] = water;
	for(int i = 0; i < 4; ++i)
	{
		startmove(x+dx[i], (y+dy[i]+n)%n);
	}
}

void doit(int x, int y)
{
	if(x<0 || x>=m || y<0 || y>=n || g[x][y] != land) return;
	c++;
	g[x][y] = water;
	for(int i = 0; i < 4; ++i)
	{
		doit(x+dx[i], (y+dy[i]+n)%n);
	}
}

int main()
{
	int sx, sy;
	while(scanf("%d %d", &m, &n) != EOF)
	{
		for(int i = 0; i < m; ++i)
		{
			for(int j = 0; j < n; ++j)
			{
				cin>>g[i][j];
			}
		}
		scanf("%d %d",&sx, &sy);
		land = g[sx][sy];
		water = ' ';
		startmove(sx, sy);
		ret = 0;
		for(int i = 0; i < m; ++i)
		{
			for(int j = 0; j < n; ++j)
			{
				if(g[i][j] == land)
				{
					c = 0;
					doit(i,j);
					ret = max(ret, c);
				}
			}
		}
		printf("%d\n", ret);
	}
		return 0;
}