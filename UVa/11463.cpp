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
#define UNIQUE(a)       SORT(a);(a).resize(unique(ALL(a))-(a).begin())
#define IN(a,b)         ((b).find(a)!=(b).end())
#define fill(x,a)       memset(x, a, sizeof(x))
#define abs(a)          ((a)<0?-(a):(a))
#define maX(a,b)        ((a)>(b)?(a):(b))
#define miN(a,b)        ((a)<(b)?(a):(b))
#define checkbit(n,b)   ((n>>b)&1)

//Main code begins here
int n,r;
int adj[105][105];

void init()
{
	for(int i=0; i<n; ++i)
	{
		for(int j=0; j<n; ++j)
		{
			adj[i][j] = (i==j)?0:(int)1e9;
		}
	}	
}

int main()
{
	int kase,a,b;
	scanf("%d",&kase);
	for(int x=1; x<=kase; ++x)
	{
		scanf("%d",&n);
		scanf("%d",&r);
		init();
		for(int i=0; i<r; ++i)
		{
			scanf("%d %d",&a,&b);
			adj[a][b]=adj[b][a]=1;
		}
		for(int k=0; k<n; ++k)
		{
			for(int i=0; i<n; ++i)
			{
				for(int j=0; j<n; ++j)
				{
					adj[i][j]=min(adj[i][j],adj[i][k]+adj[k][j]);
				}
			}
		}
		int ans=-1, beg, end;
		scanf("%d %d",&beg,&end);
		for(int i=0; i<n; ++i)
		{
			ans=max(ans,adj[beg][i]+adj[i][end]);
		}
		printf("Case %d: %d\n",x,ans);
	}
	return 0;
}
