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
#define INF 			(2147483645)

//Main code begins here
int n;
double d[105][105];

template<class T> inline T sqr(T x){return x*x;}
double dist(double x1,double y1,double x2,double y2){return sqrt(sqr(x1-x2)+sqr(y1-y2));}

void init()
{
	for(int i=0; i<n; ++i)
	{
		for(int j=0; j<n; ++j)
		{
			d[i][j] = INF;
		}
	}
}

void solve()
{
	for(int k=0; k<n; ++k)
	{
		for(int i=0; i<n; ++i)
		{
			for(int j=0; j<n; ++j)
			{
				d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
			}
		}
	}	
}

int main()
{
	int kase, x[105], y[105];
	double m;
	scanf("%d",&kase);
	for(int t=1; t<=kase; ++t)
	{
		scanf("%d",&n);
		init();
		for(int i=0; i<n; ++i) scanf("%d %d",&x[i], &y[i]);
		for(int i=0; i<n; ++i)
		{
			for(int j=0; j<n; ++j)
			{
				m=dist((double)x[i],(double)y[i],(double)x[j],(double)y[j]);
				if(m<=10.0) d[i][j]=m;
			}
		}
		solve();
		double maxi=-1.0;
		for(int i=0; i<n; ++i)
		{
			for(int j=0; j<n; ++j)
			{
				maxi = max(maxi, d[i][j]);
			}
		}
		printf("Case #%d:\n",t);
		if(maxi!=INF) printf("%0.4lf\n\n",maxi);
		else printf("Send Kurdy\n\n");
	}
	return 0;
}
