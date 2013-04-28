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
#define MAXN	(2505)
#define INF_MIN	(-2147483647)

int e;
vector < int > friends[MAXN];
int days[MAXN];

void bfs(int root)
{
	queue < int > q;
	q.push(root);
	days[root] = 0;
	while(!q.empty())
	{
		int x = q.front(); q.pop();
		for(int i = 0; i < SZ(friends[x]); ++i)
		{
			if(days[friends[x][i]] == INF_MIN)
			{
				days[friends[x][i]] = days[x] + 1;
				q.push(friends[x][i]);
			}
		}
	}
}

void print_res(int root)
{
	int freq[MAXN];
	fill(freq, 0);
	for(int i = 0; i < e; ++i)
	{
		if(days[i] != INF_MIN) freq[days[i]]++;
	}
	int maxi = INF_MIN, ind;
	for(int i = 1; i < e; ++i)
	{
		if(maxi < freq[i])
		{
			maxi = freq[i];
			ind = i;
		}
	}
	if(SZ(friends[root]) == 0) printf("0\n");
	else printf("%d %d\n", freq[ind], ind);
}

int main()
{
	int x, start, n, kase;
	scanf("%d", &e);
	for(int i = 0; i < e; ++i)
	{
		scanf("%d", &n);
		while(n--)
		{
			scanf("%d", &x);
			friends[i].push_back(x);
		}
	}
	for(scanf("%d", &kase); kase>0; kase--)
	{
		for(int i = 0; i < e; ++i)
		{
			days[i] = INF_MIN;
		}
		scanf("%d", &start);
		bfs(start);
		print_res(start);
	}

	//system("pause");
	return 0;
}
