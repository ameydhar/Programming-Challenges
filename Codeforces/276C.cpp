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

template<class T> inline T lowbit(T n) {return (n^(n-1))&n;}

int m,a[200005],q,l,r;
long long s[200005],query[200005],ret;

void addS(long long s[], int pos, int val)
{
	//m is the size of the array s.
	for(;pos<=m;pos+=lowbit(pos)) s[pos]+=val;
}

long long getS(long long s[], int l, int r)
{
	if(l>r) return 0;
	else if(l==1)
	{
		long long res=0;
		for(;r>0;r-=lowbit(r)) res+=s[r];
		return res;
	}
	else
	{
		return getS(s,1,r) - getS(s,1,l-1);
	}
}

int main()
{
	cin>>m>>q;
	for(int i=0; i<m; ++i)
	{
		cin>>a[i];
	}
	sort(a,a+m);
	for(int i=0; i<q; ++i)
	{
		cin>>l>>r;
		addS(s,l,1);
		addS(s,r+1,-1);
	}
	for(int i=0; i<m; ++i)
	{
		query[i]=getS(s,1,i+1);
	}
	sort(query,query+m);
	
	for(int i=0; i<m; ++i)
	{
		ret+=query[i]*(long long)a[i];
	}
	cout<<ret<<endl;
	return 0;
}
