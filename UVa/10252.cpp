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

//For debugging purpose
#define debug(args...)  {dbg,args; cerr<<endl;}

struct debugger
{
    template <typename T>
    debugger & operator , (const T& v)
    {
        cerr << v << " ";
        return *this;
    }
} dbg;

void debugarr(int * a, int n)
{
    printf("[ ");
    for(int i=0;i<n;i++) printf("%d ",a[i]);
    printf("]\n");
}

//Main code begins here
string s,t;
int sl, tl;
int sc[27], tc[27];
string ret;

int main()
{
	while(getline(cin,s) && getline(cin,t))
	{
		sl=SZ(s); tl=SZ(t);
		fill(sc,0), fill(tc,0);
		ret="";
		for(int i=0; i<sl; ++i)
		{
			sc[s[i]-'a']++;
		}
		for(int i=0; i<tl; ++i)
		{
			tc[t[i]-'a']++;
		}
		for(int i=0; i<26; ++i)
		{
			if(sc[i]>0 && tc[i]>0)
			{
				for(int j=0; j<min(sc[i],tc[i]); ++j)
				{
					ret+=('a'+i);
				}
			}
		}
		cout<<ret<<"\n";
	}
	return 0;
}
