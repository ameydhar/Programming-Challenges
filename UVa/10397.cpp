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
#define FREOPEN 			freopen("inp.txt","r",stdin); freopen("out.txt","w",stdout)

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
#define MAXN	(1005)

int n, m;
int x[MAXN], y[MAXN];
int parent[MAXN], rank[MAXN];
double tot;
bool con[MAXN][MAXN];
vector < pair < double, pair < int, int > > > graph;

double dist(int a, int b)
{
	return ((double)(sqrt((double)((x[a]-x[b])*(x[a]-x[b])) + (double)((y[a]-y[b])*(y[a]-y[b])))));
}

int find(int x)
{
	return parent[x] = (x == parent[x] ? x : find(parent[x]));
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

void kruskal()
{
	int pu, pv;
	SORT(graph);
	for(int i = 0; i < SZ(graph); ++i)
	{
		pu = find(graph[i].second.first);
		pv = find(graph[i].second.second);
		if(pu != pv)
		{
			tot += graph[i].first;
			join(pu, pv);
		}
	}
}

int main()
{
	int a, b;
	while(scanf("%d",&n) == 1)
	{
		tot = 0;
		graph.clear();
		for(int i = 0; i < MAXN; ++i)
		{
			for(int j = 0; j < MAXN; ++j)
			{
				con[i][j] = 0;
			}
		}
		for(int i = 0; i < n; ++i)
		{
			scanf("%d %d",&x[i], &y[i]);
			parent[i] = i;
			rank[i] = 0;
		}
		scanf("%d",&m);
		for(int i = 0; i < m; ++i)
		{
			scanf("%d %d",&a,&b);
			a--, b--;
			con[a][b] = con[b][a] = 1;
		}
		for(int i = 0; i < n; ++i)
		{
			for(int j = i+1; j < n; ++j)
			{
				if(con[i][j]) graph.push_back(make_pair(0, make_pair(i,j)));
				else graph.push_back(make_pair(dist(i,j), make_pair(i,j)));
			}
		}
		kruskal();
		printf("%.2lf\n",tot);
	}

	//system("pause");
	return 0;
}
