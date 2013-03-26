#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <string.h>
#include <list>
#include <bitset>
#include <sstream>
#include <functional>
#include <numeric>
#include <cstdlib>
#include <cctype>
#include <fstream>
using namespace std;

#define FOR(i,a,b)      for(int i=a;i<b;i++)
#define REP(i,n)        FOR(i,0,n)
#define SZ(a)           (int)(a.size())
#define ALL(a)          a.begin(),a.end()
#define SORT(a)         sort(ALL(a));
#define REVERSE(a)      reverse(ALL(a))
#define UNIQUE(a)       SORT(a),(a).resize(unique(ALL(a))-(a).begin())
#define FOREACH(i,a)    for(typeof((a).begin()) i=(a).begin();i!=(a).end();i++)
#define fill(x,a)       memset(x, a, sizeof(x))
#define pb              push_back
#define mp              make_pair
#define INF             (int)1e9
#define EPS             double(1e-9)
#define abs(a)          ((a)<0?-(a):(a))
#define dbg(x)          (cerr << #x << ":" << (x) << endl)

typedef long long LL;
typedef vector < int > VI;
typedef pair < int, int > PII;

const int MAXN = 1005;
char str[MAXN];
int dp[MAXN][MAXN], p[MAXN][MAXN];

int solve(int x, int y)
{
    if(x>=y) return 0;
    if(dp[x][y]!=-1) return dp[x][y];
    if(str[x]==str[y]) dp[x][y]=solve(x+1,y-1), p[x][y]=0;
    else if(solve(x+1,y)<=solve(x,y-1)) dp[x][y]=solve(x+1,y)+1, p[x][y]=1;
    else dp[x][y]=solve(x,y-1)+1, p[x][y]=-1;
    return dp[x][y];
}

void Print(int x, int y)
{
    if(x>y) return;
    if(x==y) printf("%c",str[x]);
    else if(p[x][y]==0) printf("%c",str[x]), Print(x+1,y-1), printf("%c",str[x]);
    else if(p[x][y]==1) printf("%c",str[x]), Print(x+1,y), printf("%c",str[x]);
    else if(p[x][y]==-1) printf("%c",str[y]), Print(x,y-1), printf("%c",str[y]);
}
    
int main()
{
    while(scanf("%s",str)!=EOF)
    {
        int len=strlen(str);
        fill(dp,-1);
        printf("%d ",solve(0,len-1));
        Print(0,len-1);
        printf("\n");
    }
    return 0;
}
