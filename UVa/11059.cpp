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

int main()
{
	int n, a[20], kase = 0;
	while(scanf("%d",&n)!=EOF)
	{
		long long ret=0LL, prod=1LL;
		for(int i=0; i<n; ++i)
		{
			scanf("%d",&a[i]);
		}
		for(int i=0; i<n; ++i)
		{
			prod=1LL;
			for(int j=i; j<n; ++j)
			{
				prod*=a[j];
				ret=max(ret,prod);
			}
		}
		printf("Case #%d: The maximum product is %lld.\n\n",++kase,ret);
	}
	return 0;
}
