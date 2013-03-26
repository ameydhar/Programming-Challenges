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
#define UNIQUE(a)       SORT(a),(a).resize(unique(ALL(a))-(a).begin())
#define IN(a,b)         ((b).find(a)!=(b).end())
#define fill(x,a)       memset(x, a, sizeof(x))
#define abs(a)          ((a)<0?-(a):(a))
#define maX(a,b)        ((a)>(b)?(a):(b))
#define miN(a,b)        ((a)<(b)?(a):(b))
#define checkbit(n,b)   ((n>>b)&1)
#define FREOPEN         freopen("in.txt","r",stdin); freopen("out.txt","w",stdout)

//For debugging purpose
#define debug(args...)      {dbg,args; cout<<endl;}
struct debugger
{
  template<typename T> debugger& operator , (const T& v)
  {  
    cout<<v<<" ";  
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
long long n,k,maxi;
    
bool solve(int x)
{
    long long l=(k*(long long)x)-((long long)x*((long long)x+1LL)/2LL)+1LL;
    if(l>=n) return true;
    return false;
}

int main()
{
    cin>>n>>k;
    long long maxi=(k*(k+1LL)/2LL)-1LL-(k-2LL);
    if(n>maxi) {cout<<-1<<endl; return 0;}
    if(n==1) {cout<<0<<endl; return 0;}
    if(n<=k) {cout<<1<<endl; return 0;}
    int lo=1;
    int hi=k-1;
    int mid;
    while(hi>lo)
    {
        mid=lo+(hi-lo)/2;
        if(solve(mid)) hi=mid;
        else lo=mid+1;
    }
    cout<<lo<<endl;
    return 0;
}
