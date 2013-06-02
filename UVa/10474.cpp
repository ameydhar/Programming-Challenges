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

int main()
{
	int n, q, m, k, kase = 0;
	long long ret;
	while(scanf("%d %d",&n, &q))
	{
		if(n==0 && q==0) break;
		map < int, long long > pos;
		for(int i = 0; i < n; ++i)
		{
			scanf("%d",&m);
			if(pos.find(m) == pos.end()) pos.insert(pair < int, long long > (m,1));
			else pos[m]++;
		}
		printf("CASE# %d:\n",++kase);
		for(int i = 0; i < q; ++i)
		{
			scanf("%d",&k);
			ret = 0;
			if(pos.find(k) == pos.end()) printf("%d not found\n",k);
			else
			{
				FOREACH(it, pos)
				{
					if(it->first < k) ret += (long long)it->second;
					else break;
				}
				printf("%d found at %lld\n",k, ret+1LL);
			}
		}
	}

	//system("pause");
	return 0;
}
