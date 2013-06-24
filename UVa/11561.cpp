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
int w, h, ret;
char g[55][55];

int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};

bool isin(int x, int y)
{
	if(x<0 || x>=h || y<0 || y>=w) return false;
	return true;
}

bool isthreat(int x, int y)
{
	if(isin(x,y) && g[x][y] == 'T') return true;
	for(int i = 0; i < 4; ++i)
	{
		if(isin(x+dx[i], y+dy[i]))
		{
			if(g[x+dx[i]][y+dy[i]] == 'T') return true;
		}
	}
	return false;
}

void move(int x, int y)
{
	if(!isin(x,y) || g[x][y]=='#' || g[x][y]=='T') return;
	if(g[x][y] == 'G') {ret++; g[x][y] = '#';}
	if(isthreat(x,y)) return;

	g[x][y] = '#';

	for(int i = 0; i < 4; ++i)
	{
		move(x+dx[i], y+dy[i]);
	}
}

int main()
{
	while(scanf("%d %d", &w, &h) == 2)
	{
		ret = 0;
		for(int i = 0; i < h; ++i)
		{
			for(int j = 0; j < w; ++j)
			{
				cin>>g[i][j];
			}
		}
		for(int i = 0; i < h; ++i)
		{
			for(int j = 0; j < w; ++j)
			{
				if(g[i][j] == 'P') move(i,j);
			}
		}
		printf("%d\n",ret);
	}

	//system("pause");
	return 0;
}
