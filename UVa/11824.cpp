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
#include <list>
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
#define INDEX(arr,ind)	(lower_bound(all(arr),ind)-arr.begin())
#define FREOPEN 			freopen("in.txt","r",stdin); freopen("out.txt","w",stdout)

//Main code begins here
int l[50];

long long calc(long long base, long long power)
{
	long long ret = 1LL;
	if(power == 0LL) return ret;
	if(power == 1LL) return base;
	for(int i = 0; i < power; ++i)
	{
		ret *= base;
	}
	return ret;
}

int main()
{
	int kase, x;
	for(scanf("%d", &kase); kase > 0; --kase)
	{
		int i = 0;
		bool done = true;
		while(scanf("%d", &x) && x!=0)
		{
			l[i++] = x;
		}
		int y = i;
		long long ret = 0;
		sort(l, l+i);
		for(int k = 0; k < i; ++k)
		{
			if(ret > 5000000LL) {done = false; break;}
			ret += (2LL * calc((long long)l[k], (long long)y));
			y--;
		}
		if(!done) printf("Too expensive\n");
		else printf("%lld\n", ret);
	}
	return 0;
}
