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
#define UNIQUE(a)       SORT(a),(a).resize(unique(ALL(a))-(a).begin())
#define IN(a,b)         ((b).find(a)!=(b).end())
#define fill(x,a)       memset(x, a, sizeof(x))
#define abs(a)          ((a)<0?-(a):(a))
#define maX(a,b)        ((a)>(b)?(a):(b))
#define miN(a,b)        ((a)<(b)?(a):(b))
#define checkbit(n,b)   ((n>>b)&1)
#define FREOPEN 		freopen("in.txt","r",stdin); freopen("out.txt","w",stdout)

//For debugging purpose
#define debug(args...)      {dbg,args; cout<<endl;}
struct debugger
{
  template<typename T> debugger& operator , (const T& v)
  {  
    cout<<v<<" ";  
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
char g[6][6];
bool doit()
{
	for(int i=0; i<3; ++i)
	{
		for(int j=0; j<3; ++j)
		{
			char col=g[i][j];
			if(g[i+1][j]==col && g[i][j+1]==col && g[i+1][j+1]==col) return true;
		}
	}
	return false;
}

int main()
{
	for(int i=0; i<4; ++i)
	{
		for(int j=0; j<4; ++j)
		{
			cin>>g[i][j];
		}
	}
	if(doit()) {cout<<"YES"<<endl; return 0;}
	for(int i=0; i<4; ++i)
	{
		for(int j=0; j<4; ++j)
		{
			if(g[i][j]=='#') g[i][j]='.';
			else if(g[i][j]=='.') g[i][j]='#';
			if(doit()){cout<<"YES"<<endl; return 0;}
			if(g[i][j]=='#') g[i][j]='.';
			else if(g[i][j]=='.') g[i][j]='#';
		}
	}
	cout<<"NO"<<endl;
    return 0;
}
