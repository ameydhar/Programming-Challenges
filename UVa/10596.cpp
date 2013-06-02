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
int n,r;
int deg[205];

int main()
{
	int a,b;
	while(scanf("%d %d",&n,&r) == 2)
	{
		for(int i = 0; i < n; ++i)
		{
			deg[i] = 0;
		}
		for(int i = 0; i < r; ++i)
		{
			scanf("%d %d",&a,&b);
			deg[a]++;
			deg[b]++;
		}
		bool poss = true;
		for(int i = 0; i < n; ++i)
		{
			if(deg[i] == 0 || deg[i]&1)
			{
				poss = false;
				break;
			}
		}
		if(poss) printf("Possible\n");
		else printf("Not Possible\n");
	}

	//system("pause");
	return 0;
}
