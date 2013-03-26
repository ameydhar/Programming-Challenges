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
int a[4][4], b[4][4];
int dx[5]={0,-1,0,0,1};
int dy[5]={0,0,1,-1,0};

int solve(int x, int y)
{
	int cnt=0;
	for(int i=0; i<5; ++i)
	{
		if(x+dx[i]<0 && x+dx[i]>=3 && y+dy[i]<0 && y+dy[i]>=3) continue;
		cnt+=a[x+dx[i]][y+dy[i]];
	}
	return cnt;	
}

int main()
{
	int c=0;
	for(int i=0; i<3; ++i)
	{
		for(int j=0; j<3; ++j)
		{
			cin>>a[i][j];
		}
	}
	for(int i=0; i<3; ++i)
	{
		for(int j=0; j<3; ++j)
		{
			c=solve(i,j);
			if(c%2==0) cout<<1;
			else cout<<0;
		}
		cout<<endl;
	}
	return 0;
}
