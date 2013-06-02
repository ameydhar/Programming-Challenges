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
#include <limits>
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
static inline int popcount(int N)
{
	N = (N & 0x55555555) + ((N & 0xaaaaaaaa) >> 1);
	N = (N & 0x33333333) + ((N & 0xcccccccc) >> 2);
	N = (N & 0x0f0f0f0f) + ((N & 0xf0f0f0f0) >> 4);
	N = (N & 0x00ff00ff) + ((N & 0xff00ff00) >> 8);
	N = (N & 0x0000ffff) + ((N & 0xffff0000) >> 16);
	return N;
}

string dec2bin(int val)
{
	string sbin;  
   while(val != 0)
   {
   	sbin += (val & 1) ? '1' : '0';
      val >>= 1;
   }
   reverse(sbin.begin(),sbin.end());
   return sbin;
}

int main()
{
	int x;
	string bin;
	while(scanf("%d",&x))
	{
		if(x == 0) break;
		bin = dec2bin(x);
		printf("The parity of %s is %d (mod 2).\n",bin.c_str(),popcount(x));
	}

	return 0;
}

/*Critical input:
2147483647
500000000
999999999
Critical output:
The parity of 1111111111111111111111111111111 is 31 (mod 2).
The parity of 11101110011010110010100000000 is 13 (mod 2).
The parity of 111011100110101100100111111111 is 21 (mod 2).*/