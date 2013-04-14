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
int n;
int parent[105], rank[105];
double tot;
vector < pair < double, pair < int, int > > > graph;

double dist(double x1,double y1,double x2,double y2) {return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));} 

void initk()
{
	for(int i = 1; i <= n; ++i) {parent[i] = i; rank[i] = 0;}
	return;
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
	return;
}

void kruskal()
{
	int pu, pv;
	SORT(graph);
	for(int i = 0; i < n*(n-1)/2; ++i)
	{
		pu = find(graph[i].second.first);
		pv = find(graph[i].second.second);
		if(pu != pv)
		{
			tot += graph[i].first;
			Union(pu, pv);
		}
	}

}

int main()
{
	int kase;
	double x[105], y[105], d[105][105];
	for(scanf("%d",&kase); kase>0; kase--)
	{
		scanf("%d",&n);
		graph.clear();
		initk();
		tot = 0;
		for(int i = 0; i < n; ++i)
		{
			scanf("%lf %lf",&x[i], &y[i]);
		}
		for(int i = 0; i < n; ++i)
		{
			for(int j = i+1; j < n; ++j)
			{
				d[i][j] = dist(x[i], y[i], x[j], y[j]);
				graph.push_back(make_pair(d[i][j],make_pair(i+1,j+1)));
			}
		}
		kruskal();
		printf("%.2lf\n", tot);
		if(kase != 1) printf("\n");
	}
	return 0;
}
