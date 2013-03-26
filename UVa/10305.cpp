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
int n,m,p;
int od[105];
bool v[105];
vector < int > x[105];

void dfs(int a)
{
	if(v[a]) return;
	v[a]=true;
	for(int i=0; i<SZ(x[a]); ++i)
	{
		dfs(x[a][i]);
	}
	od[p]=a; p--;
}

int main()
{
	int a,b;
	while(scanf("%d %d",&n,&m))
	{
		if(n==0 && m==0) break;
		for(int i=0; i<m; ++i)
		{
			scanf("%d %d",&a,&b);
			a--, b--;
			x[a].push_back(b);
		}
		for(int i=0; i<n; ++i) v[i]=false;
		p=n-1;
		for(int i=0; i<n; ++i)
		{
			if(!v[i]) dfs(i);
		}
		for(int i=0; i<n; ++i)
		{	
			printf("%d ",od[i]+1);
		}
		printf("\n");
	}
	return 0;
}
