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

//For debugging purpose
#define debug(args...)  {dbg,args; cerr<<endl;}

struct debugger
{
    template <typename T>
    debugger & operator , (const T& v)
    {
        cerr << v << " ";
        return *this;
    }
} dbg;

void debugarr(int * a, int n)
{
    printf("[ ");
    for(int i=0;i<n;i++) printf("%d ",a[i]);
    printf("]\n");
}

//Main code begins here
int n,m;
int g[2005][2005];
int main()
{
	while(scanf("%d %d",&n,&m) && (n!=0 && m!=0))
	{
		int v,w,p;
		bool d=0;
		for(int i=0; i<n; ++i)
		{
			for(int j=0; j<n; ++j)
			{
				if(i==j) g[i][j]=1;
				else g[i][j]=2050;
			}
		}
		for(int i=0; i<m; ++i)
		{
			scanf("%d %d %d",&v,&w,&p);
			g[v-1][w-1]=1;
			if(p==2) g[w-1][v-1]=1;
		}
		for(int k=0; k<n; ++k)
		{
			for(int i=0; i<n; ++i) if(i!=k)
			{
				for(int j=0; j<n; ++j) if(j!=i && j!=k)
				{
					g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
				}
			}
		}
		for(int i=0; i<n; ++i)
		{
			for(int j=0; j<n; ++j)
			{
				if(max(g[i][j],g[j][i])==2050) {d=1; break;}
			}
		}
		if(d==1) printf("0\n"); 
		else printf("1\n");
	}
	return 0;
}
