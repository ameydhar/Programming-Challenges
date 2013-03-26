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
vector < int > coins;
long long ways[10005][22];

void gen()
{
	for(int i=1; i<=21; ++i)
	{
		coins.push_back(i*i*i);
	}
	return;
}

void solve()
{
	for(int i=0; i<SZ(coins); ++i)
	{
		ways[0][i]=1;
	}
	for(int i=1; i<=10000; ++i)
	{
		for(int j=0; j<SZ(coins); ++j)
		{
			ways[i][j] = ((i>=coins[j])?(ways[i-coins[j]][j]):0) + ((j>=1)?(ways[i][j-1]):0);
		}
	}
}


int main()
{
	int amt;
	gen();
	solve();
	while(scanf("%d",&amt)!=EOF)
	{
		printf("%lld\n",ways[amt][SZ(coins)-1]);
	}
	return 0;
}
