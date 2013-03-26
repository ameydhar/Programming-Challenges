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
#define INF 			(1<<29)

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
int n, v, ret, w;
char age, dir, x, y, initx, inity;
char place;
int g[30][30][2];
vector < pair < int, char > > p;

void initgraph()
{
	ret=INF;
	p.clear();
	for(int i=0; i<26; ++i)
	{
		for(int j=0; j<26; ++j)
		{
			g[i][j][0]=INF;
			g[i][j][1]=INF;
		}
	}
	for(int i=0; i<26; ++i)
	{
		g[i][i][0]=0;
		g[i][i][1]=0;
	}
}

void solve()
{
	for(int z=0; z<2; ++z)
	{
		for(int k=0; k<26; ++k)
		{
			for(int i=0; i<26; ++i) if(i!=k)
			{
				for(int j=0; j<26; ++j) if(j!=i && j!=k)
				{
					g[i][j][z] = min(g[i][j][z], g[i][k][z]+g[k][j][z]);
				}
			}
		}
	}
	
	for(int i=0; i<26; ++i)
	{
		p.push_back(pair < int, char > (g[initx-'A'][i][0] + g[inity-'A'][i][1], i+'A'));
	}
	SORT(p);
	ret = p[0].first;
	if(ret>=INF) printf("You will never meet.\n");
	else
	{
		printf("%d",ret);
		for(int i=0; i<26; ++i)
		{
			if(p[i].first==ret) cout<<" "<<p[i].second;
		}
		printf("\n");
	}
}

int main()
{
	while(scanf("%d",&n)!=EOF && n!=0)
	{
		initgraph();
		for(int i=0; i<n; ++i)
		{
			cin>>age;
			w=(age=='Y')?0:1;
			cin>>dir>>x>>y>>v;
			if(g[x-'A'][y-'A'][w]>v) g[x-'A'][y-'A'][w]=v;
			if(dir=='B' && g[y-'A'][x-'A'][w]>v) g[y-'A'][x-'A'][w]=v;
		}
		
		cin>>initx>>inity;
		solve();
	}
	return 0;
}
