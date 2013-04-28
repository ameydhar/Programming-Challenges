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
#define MAXN	(1000003)

int a, b;
vector < long long > plist;
bool primes[MAXN];

void gen()
{
	plist.clear();
	primes[0] = primes[1] = false;
	int m = (int)sqrt(int(MAXN));
	for(int i=2; i<MAXN; ++i) primes[i] = true;
	for(int i = 2; i <= m; ++i)
	{
		if(primes[i])
		{
			for(int j=i*i; j < MAXN; j+=i) primes[j] = false;
		}
	}
	for(int i=2; i<MAXN; ++i) if(primes[i]) plist.push_back(i);
}

int main()
{
	int kase, ret, ind;
	gen();
	for(scanf("%d",&kase); kase>0; --kase)
	{
		scanf("%d %d", &a, &b);
		ret = 0;
		ind = 0;
		map < int, int > gaps;
		for(int i = 0; i < SZ(plist)-1; ++i)
		{
			if(plist[i]>=a && plist[i+1]<=b)
			{
				gaps[plist[i+1]-plist[i]]++;
			}
			else if(plist[i+1] > b) break;
		}
		FOREACH(it, gaps)
		{
			if(it->second > ret)
			{
				ret = it->second;
				ind = it->first;
			}
			else if(it->second == ret)
			{
				ret = 0;
				break;
			}
		}
		if(ret == 0) printf("No jumping champion\n");
		else printf("The jumping champion is %d\n",ind);
	}

	return 0;
}
