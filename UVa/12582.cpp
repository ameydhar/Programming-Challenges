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
int n, cnt[30], parent[30];
bool vis[30];

int main()
{
	int kase, prev, cur, t = 0;
	string inp;
	scanf("%d", &kase);
	while(t < kase)
	{
		cin >> inp;
		fill(vis, false);
		fill(cnt, 0);

		int len = SZ(inp);
		prev = inp[0] - 'A';
		vis[prev] = true;
		for(int i = 1; i < len; ++i)
		{
			cur = inp[i] - 'A';
			if(!vis[cur])
			{
				parent[cur] = prev;
				cnt[cur]++;
				cnt[prev]++;
				vis[cur] = true;
				prev = cur;
			}
			else
			{
				prev = parent[cur];
			}
		}
		printf("Case %d\n", ++t);
		for(int i = 0; i < 26; ++i)
		{
			if(cnt[i]) printf("%c = %d\n", char(i+'A'), cnt[i]);
		}
	}	

	//system("pause");
	return 0;
}
