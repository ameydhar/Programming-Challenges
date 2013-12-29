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
#define MAXN	(1000020)
int parent[MAXN], rank[MAXN];
vector < pair < int, pair < int, int > > > graph;

int find(int x)
{
	return parent[x] = (x == parent[x] ? x : find(parent[x]));
}

void init_uf(int n)
{
	for(int i = 0; i <= n; ++i)
	{
		parent[i] = i;
		rank[i] = 0;
	}
}

void join(int x, int y)
{
	int a = find(x);
	int b = find(y);
	if(a == b) return;
	if(rank[a] < rank[b])
	{
		parent[a] = b;
		rank[a] += rank[b];
	}
	else
	{
		parent[b] = a;
		if(rank[a] == rank[b]) rank[b]++;
		else rank[b] += rank[a];
	}
}

int kruskal()
{
	int pu, pv, totalb = 0;
	SORT(graph);
	for(int i = 0; i < SZ(graph); ++i)
	{
		pu = find(graph[i].second.first);
		pv = find(graph[i].second.second);
		if(pu != pv)
		{
			totalb += graph[i].first;
			join(pu, pv);
		}
	}
	return totalb;
}

int main()
{
	int n, a, b, c, k, m;
	int totala, totalb;
	int ntest = 0;
	while(scanf("%d", &n) == 1)
	{
		totala = 0;
		totalb = 0;
		graph.clear();
		ntest++;
		if(ntest > 1) printf("\n");
		init_uf(n+1);
		for(int i = 0; i < n-1; ++i)
		{
			scanf("%d %d %d", &a, &b, &c);
			totala += c;
		}
		scanf("%d", &k);
		for(int i = 0; i < k; ++i)
		{
			scanf("%d %d %d", &a, &b, &c);
			graph.push_back(make_pair(c, make_pair(a - 1, b - 1)));
		}
		scanf("%d", &m);
		for(int i = 0; i < m; ++i)
		{
			scanf("%d %d %d", &a, &b, &c);
			graph.push_back(make_pair(c, make_pair(a - 1, b - 1)));
		}
		totalb = kruskal();
		printf("%d\n%d\n", totala, totalb);
	}

	//system("pause");
	return 0;
}
