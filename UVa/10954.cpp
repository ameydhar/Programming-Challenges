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
#include <list>
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

struct comp
{
	bool operator() (const int &a, const int &b)
	{
		return a>b;
	}
};

int main()
{
    int n, num;
    long long cost, pcost;
    while(scanf("%d",&n) && n!=0)
    {
        cost = pcost = 0;
        priority_queue < int, vector <int>, comp > q;
        for(int i=0; i<n; ++i)
        {
            scanf("%d",&num);
            q.push(num);
        }
        while(SZ(q)>1)
        {
            pcost = q.top(); q.pop();
            pcost += q.top(); q.pop();
            cost += pcost;
            q.push(pcost);
        }
        printf("%lld\n",cost);
    }
    return 0;
}