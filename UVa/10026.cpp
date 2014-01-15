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
int input_int()
{
	int cc = getc(stdin);
	for (;cc < '0' || cc > '9';)  cc = getc(stdin);
		int ret = 0;
	for (;cc >= '0' && cc <= '9';)
	{
		ret = ret * 10 + cc - '0';
		cc = getc(stdin);
	}
	return ret;
}

//Main code begins here
#define MAXN	(1005)
pair < pair < int, int > , int > p[MAXN];

bool mysort(const pair < pair < int, int > , int >& p1, const pair < pair < int, int > , int >& p2)
{
	double r1 = (double)p1.first.first/(double)p1.first.second;
	double r2 = (double)p2.first.first/(double)p2.first.second;
	if(abs(r1 - r2) > double(1e-9)) return (r1 > r2);
	return p1.second < p2.second;
}

int main()
{
	int kase = input_int();
	int t, f, n;
	bool firstcase = true;
	for(int z = 0; z < kase; ++z)
	{
		if(!firstcase) printf("\n");
		n = input_int();
		for(int i = 0; i < n; ++i)
		{
			t = input_int();
			f = input_int();
			p[i] = make_pair(make_pair(f, t), i+1);
		}
		sort(p, p + n, mysort);
		for(int i = 0; i < n; ++i)
		{
			printf("%d", p[i].second);
			if(i != n - 1) printf(" ");
		}
		printf("\n");
		if(z != kase - 1) printf("\n");
	}
	
	return 0;
}
