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
#define UNIQUE(a)       SORT(a);(a).resize(unique(ALL(a))-(a).begin())
#define IN(a,b)         ((b).find(a)!=(b).end())
#define fill(x,a)       memset(x, a, sizeof(x))
#define abs(a)          ((a)<0?-(a):(a))
#define maX(a,b)        ((a)>(b)?(a):(b))
#define miN(a,b)        ((a)<(b)?(a):(b))
#define checkbit(n,b)   ((n>>b)&1)
#define INDEX(arr,ind)	(lower_bound(all(arr),ind)-arr.begin())
#define FREOPEN 			freopen("in.txt","r",stdin); freopen("out.txt","w",stdout)

//Debug functions
#define debugger cerr
#define debug(args...)			{mdbg,args; debugger<<endl;}
#define PRINT_CONTAINER(o,v)    {if(v.size()==0) return o<<"{}"; o<<"{"; FOREACH(it,v) o<<*it<<" "; return o<<"\b}";}
struct multidebug {template<typename T> multidebug& operator , (const T &v) {debugger<<v<<" "; return *this;}} mdbg;
template<class T> ostream& operator << (ostream& o,const vector<T> &v) PRINT_CONTAINER(o,v)
template<class T> ostream& operator << (ostream& o,const set<T> &v) PRINT_CONTAINER(o,v)
template<class A,class B> ostream& operator << (ostream& o,const map<A,B> &v) PRINT_CONTAINER(o,v)
template<class A,class B> ostream& operator << (ostream& o,const pair<A,B> &p) {o<<"("<<p.first<<","<<p.second<<")"; return o;}
template<class T> void debugarr(T* v,int n) {debugger<<"{"; for(int i=0;i<n;i++) debugger<<v[i]<<" "; debugger<<"\b}"<<endl;}

//Main code begins here
#define MAXN	(10005)

int n, m, a, airport;
long long tot;
int parent[MAXN], rank[MAXN];
set < int > airportset;
vector < pair < int, pair < int, int > > > graph; 

void initk()
{
	for(int i = 1; i < n+1; ++i)
	{
		parent[i] = i;
		rank[i] = 0;
	}
}

int find(int x)
{
	if(parent[x] != x) parent[x] = find(parent[x]);
	return parent[x];
}

void Union(int a, int b)
{
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

void kruskal()
{
	int pu, pv;
	SORT(graph);
	for(int i = 0; i < m; ++i)
	{
		pu = find(graph[i].second.first);
		pv = find(graph[i].second.second);
		if(pu != pv)
		{
			if(a > graph[i].first)
			{
				tot += graph[i].first;
				Union(pu,pv);
			}
		}
	}
}

int main()
{
	int kase, x, y, c;
	scanf("%d",&kase);
	for(int t = 1; t <= kase; ++t)
	{
		scanf("%d %d %d",&n, &m, &a);
		tot = 0;
		airport = 0;
		graph.clear();
		airportset.clear();
		initk();
		for(int i = 0; i < m; ++i)
		{
			scanf("%d %d %d", &x, &y, &c);
			graph.push_back(pair < int, pair < int, int > >(c, pair < int, int >(x,y)) );
		}
		kruskal();
		for(int i = 1; i < n+1; ++i)
		{
			airportset.insert(find(parent[i]));
		}
		airport = SZ(airportset);
		printf("Case #%d: %lld %d\n",t,tot+(airport*a),airport);
	}
	system("pause");
	return 0;
}
