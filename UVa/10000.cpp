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

//Main code begins here
int n;
int dist[105][105];

int main()
{
	int start, last, p, q, maxi, kase = 0;
	while(1)
	{
		if(kase > 0) printf("\n");
		scanf("%d", &n);
		if(n == 0) break;
		for(int i = 0; i < n; ++i)
		{
			for(int j = 0; j < n; ++j)
			{
				dist[i][j] = -(int)1e9;
			}
		}
		scanf("%d", &start);
		start--;
		while(scanf("%d %d", &p, &q))
		{
			if((p == 0) && (q == 0)) break;
			dist[p-1][q-1] = 1;
			dist[q-1][p-1] = -(int)1e9;
		}
		for(int k = 0; k < n; ++k)
		{
			for(int i = 0; i < n; ++i) if(i != k)
			{
				for(int j = 0; j < n; ++j) if((j != k) && (j != i))
				{
					dist[i][j] = max(dist[i][j], dist[i][k]+dist[k][j]);
				}
			}
		}
		maxi = -(int)1e9, last = 0;
		for(int i = 0; i < n; ++i)
		{
			if(i == start) continue;
			if(dist[start][i] > maxi)
			{
				maxi = dist[start][i];
				last = i;
			}
		}
		printf("Case %d: The longest path from %d has length %d, finishing at %d.\n", ++kase, ++start, maxi, ++last);
	}

	//system("pause");
	return 0;
}
