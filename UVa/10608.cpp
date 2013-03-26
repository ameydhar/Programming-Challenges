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
int n,m;
int parent[30005], rank[30005];
//map <int, int> M;

void initUF()
{
	for(int i=0; i<n; ++i)
	{
		parent[i]=i;
		rank[i]=0;
	}
}

int find(int x)
{
	if(parent[x]==x) return x;
	return find(parent[x]);
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

int main()
{
	int kase,x,y,a,b;
	for(scanf("%d",&kase);kase>0;kase--)
	{
		int ret=-1;
		scanf("%d %d",&n,&m);
		initUF();
		for(long long i=0; i<m; ++i)
		{
			scanf("%d %d",&a,&b);
			x=find(a);
			y=find(b);
			if(x!=y) Union(x,y);
		}
		for(int i=0; i<n; ++i)
		{
			parent[i]=parent[parent[i]];
			cout<<parent[i]<<" ";
		}
	}
	return 0;
}
