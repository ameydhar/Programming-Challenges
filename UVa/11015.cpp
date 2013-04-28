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
#define MAXN	(250)
int n, m;
int g[MAXN][MAXN];
char name[25][15];

int solve()
{
	for(int k = 0; k < n; ++k)
	{
		for(int i = 0; i < n; ++i) if(i!=k)
		{
			for(int j = 0; j < n; ++j) if(j!=i && j!=k)
			{
				g[i][j] = min(g[i][j], g[i][k]+g[k][j]);
			}
		}
	}
	int mini = (int)1e9, c, ret = 0;
	for(int dest = 0; dest < n; ++dest)
	{
		c = 0;
		for(int i = 0; i < n; ++i) if(i!=dest)
		{
			c += g[i][dest];
		}
		if(c < mini)
		{
			mini = c;
			ret = dest;
		}
	}
	return ret;
}

int main()
{
	int kase = 1, a, b, c, ans;
	while(scanf("%d %d",&n, &m))
	{
		if(n == 0) break;
		for(int i = 0; i < MAXN; ++i)
		{
			for(int j = 0; j < MAXN; ++j)
			{
				g[i][j] = (int)1e9;
			}
		}
		for(int i = 0; i < n; ++i)
		{
			scanf("%s", name[i]);
		}
		for(int i = 0; i < m; ++i)
		{
			scanf("%d %d %d",&a,&b,&c);
			a--; b--;
			g[a][b] = c;
			g[b][a] = c;
		}
		ans = solve();
		printf("Case #%d : %s\n", kase++, name[ans]);
	}
	return 0;
}

