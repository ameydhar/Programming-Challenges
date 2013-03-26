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
int n;
char g[1010][1010];
vector < pair < int, int > >  o, t;

int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		o.clear(); t.clear();
		for(int i=0; i<n; ++i)
		{
			for(int j=0; j<n; ++j)
			{
				cin>>g[i][j];
				if(g[i][j]=='1') o.push_back(make_pair(i,j));
				else if(g[i][j]=='3') t.push_back(make_pair(i,j));
			}
		}
		int ret=-1;
		for(int i=0; i<SZ(o); ++i)
		{
			int dist = (int)1e9;
			for(int j=0; j<SZ(t); ++j)
			{
				dist=min(dist, abs(o[i].first-t[j].first)+abs(o[i].second-t[j].second));
			}
			ret=max(ret,dist);
		}
		printf("%d\n",ret);
	}
	return 0;
}
