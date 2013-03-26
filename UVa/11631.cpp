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
#define MAXN	(200005)

int n,m;
int parent[MAXN], rank[MAXN];
long long tot,alltot;
vector < pair < int, pair < int, int > > > graph;

int find(int x)
{
	if(parent[x]!=x) return find(parent[x]);
	return x;
}

void initk()
{
	for(int i=1; i<=n; ++i)
	{
		parent[i]=i;
		rank[i]=0;
	}
}

void Union(int a, int b)
{
    if(rank[a]<rank[b])
    {
        parent[a]=b;
        rank[a]+=rank[b];
    }
    else
    {
        parent[b]=a;
        if(rank[a]==rank[b]) rank[b]++;
        else rank[b]+=rank[a];
    }
}

void kruskal()
{
	int pu,pv;
	SORT(graph);
	for(int i=0; i<m; ++i)
	{
		pu=find(graph[i].second.first);
		pv=find(graph[i].second.second);
		if(pu!=pv)
		{
			tot+=graph[i].first;
			Union(pu,pv);
		}
	}
}

int main()
{
	int x,y,z;
	while(scanf("%d %d",&n, &m))
	{
		if(n==0 && m==0) return 0;
		graph.clear(); tot=0; alltot=0;
		initk();
		for(int i=0; i<m; ++i)
		{
			scanf("%d %d %d",&x,&y,&z);
			x++; y++;
			alltot+=z;
			graph.push_back(pair < int, pair < int, int > > (z,pair < int, int > (x,y)));
		}
		kruskal();
		printf("%lld\n",alltot-tot);
	}
	return 0;
}
