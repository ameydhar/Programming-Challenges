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
int num;

int calc(int n)
{
	int ret = 0;
	while(n)
	{
		ret += ((n%10)*(n%10));
		n /= 10;
	}
	return ret;
}

void solve(int n, int cases)
{
	if(n == 1) {printf("Case #%d: %d is a Happy number.\n",cases,num); return;}
	if(n < 10) {printf("Case #%d: %d is an Unhappy number.\n",cases,num); return;}
	return solve(calc(n), cases);
}

int main()
{
	int kase;
	scanf("%d", &kase);
	for(int i = 1; i<=kase; ++i)
	{
		scanf("%d", &num);
		solve(calc(num), i);
	}

	return 0;
}
