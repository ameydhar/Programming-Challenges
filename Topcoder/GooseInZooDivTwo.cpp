#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <string>
#include <string.h>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <sstream>
#include <cassert>
#include <ctype.h>
#include <stdlib.h>

using namespace std;
#define REP(i,n)		for(int i=0;i<n;i++)
#define SZ(a)			(int)(a.size())
#define SORT(CONTAINER)	sort((CONTAINER).begin(),(CONTAINER).end()); 
#define pb				push_back
#define INF				1000000000000000LL
#define fill(x,a)		memset(x, a, sizeof(x))
#define MOD				(1000000007)

class GooseInZooDivTwo 
{
public:
bool vis[55][55];
int dd, n, m;
vector < string > ff;

int mdist(int a, int b, int c, int d)
{
	return (abs(a-c)+abs(b-d));
}

void dfs(int i, int j)
{
	if(i<0 || i>=n || j<0 || j>=m) return;
	if(vis[i][j] || ff[i][j] == '.') return;
	vis[i][j] = true;
	for(int a = 0; a < n; ++a)
	{
		for(int b = 0; b < m; ++b)
		{
			if(mdist(a,b,i,j) <= dd) dfs(a,b);
		}
	}
}

int count( vector <string> field, int dist ) 
{
	m=SZ(field[0]); n=SZ(field);
	dd = dist;
	ff = field;
	fill(vis, false);
	int r = 0;
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			if(field[i][j] == 'v' && !vis[i][j])
			{
				r++;
				dfs(i,j);
			}
		}
	}
	if(r == 0) return 0;
	int ways = 1;
	for(int i = 0; i < r; ++i)
	{
		 ways *= 2;
		 ways %= MOD;
	}
	return ways - 1;
}

};

// BEGIN CUT HERE
namespace moj_harness {
	int run_test_case(int);
	void run_test(int casenum = -1, bool quiet = false) {
		if (casenum != -1) {
			if (run_test_case(casenum) == -1 && !quiet) {
				cerr << "Illegal input! Test case " << casenum << " does not exist." << endl;
			}
			return;
		}
		
		int correct = 0, total = 0;
		for (int i=0;; ++i) {
			int x = run_test_case(i);
			if (x == -1) {
				if (i >= 100) break;
				continue;
			}
			correct += x;
			++total;
		}
		
		if (total == 0) {
			cerr << "No test cases run." << endl;
		} else if (correct < total) {
			cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << endl;
		} else {
			cerr << "All " << total << " tests passed!" << endl;
		}
	}
	
	int verify_case(int casenum, const int &expected, const int &received, clock_t elapsed) { 
		cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if (expected == received) {
			verdict = "PASSED";
		} else {
			verdict = "FAILED";
		}
		
		cerr << verdict;
		if (!info.empty()) {
			cerr << " (";
			for (int i=0; i<(int)info.size(); ++i) {
				if (i > 0) cerr << ", ";
				cerr << info[i];
			}
			cerr << ")";
		}
		cerr << endl;
		
		if (verdict == "FAILED") {
			cerr << "    Expected: " << expected << endl; 
			cerr << "    Received: " << received << endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum) {
		switch (casenum) {
		case 0: {
			string field[]            = {"vvv"};
			int dist                  = 0;
			int expected__            = 7;

			clock_t start__           = clock();
			int received__            = GooseInZooDivTwo().count(vector <string>(field, field + (sizeof field / sizeof field[0])), dist);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string field[]            = {"."};
			int dist                  = 100;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = GooseInZooDivTwo().count(vector <string>(field, field + (sizeof field / sizeof field[0])), dist);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string field[]            = {"vvv"};
			int dist                  = 1;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = GooseInZooDivTwo().count(vector <string>(field, field + (sizeof field / sizeof field[0])), dist);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string field[]            = {"v.v..................v............................"
,".v......v..................v.....................v"
,"..v.....v....v.........v...............v......v..."
,".........vvv...vv.v.........v.v..................v"
,".....v..........v......v..v...v.......v..........."
,"...................vv...............v.v..v.v..v..."
,".v.vv.................v..............v............"
,"..vv.......v...vv.v............vv.....v.....v....."
,"....v..........v....v........v.......v.v.v........"
,".v.......v.............v.v..........vv......v....."
,"....v.v.......v........v.....v.................v.."
,"....v..v..v.v..............v.v.v....v..........v.."
,"..........v...v...................v..............v"
,"..v........v..........................v....v..v..."
,"....................v..v.........vv........v......"
,"..v......v...............................v.v......"
,"..v.v..............v........v...............vv.vv."
,"...vv......v...............v.v..............v....."
,"............................v..v.................v"
,".v.............v.......v.........................."
,"......v...v........................v.............."
,".........v.....v..............vv.................."
,"................v..v..v.........v....v.......v...."
,"........v.....v.............v......v.v............"
,"...........v....................v.v....v.v.v...v.."
,"...........v......................v...v..........."
,"..........vv...........v.v.....................v.."
,".....................v......v............v...v...."
,".....vv..........................vv.v.....v.v....."
,".vv.......v...............v.......v..v.....v......"
,"............v................v..........v....v...."
,"................vv...v............................"
,"................v...........v........v...v....v..."
,"..v...v...v.............v...v........v....v..v...."
,"......v..v.......v........v..v....vv.............."
,"...........v..........v........v.v................"
,"v.v......v................v....................v.."
,".v........v................................v......"
,"............................v...v.......v........."
,"........................vv.v..............v...vv.."
,".......................vv........v.............v.."
,"...v.............v.........................v......"
,"....v......vv...........................v........."
,"....vv....v................v...vv..............v.."
,".................................................."
,"vv........v...v..v.....v..v..................v...."
,".........v..............v.vv.v.............v......"
,".......v.....v......v...............v............."
,"..v..................v................v....v......"
,".....v.....v.....................v.v......v......."};
			int dist                  = 3;
			int expected__            = 797922654;

			clock_t start__           = clock();
			int received__            = GooseInZooDivTwo().count(vector <string>(field, field + (sizeof field / sizeof field[0])), dist);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			string field[]            = ;
			int dist                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = GooseInZooDivTwo().count(vector <string>(field, field + (sizeof field / sizeof field[0])), dist);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			string field[]            = ;
			int dist                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = GooseInZooDivTwo().count(vector <string>(field, field + (sizeof field / sizeof field[0])), dist);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string field[]            = ;
			int dist                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = GooseInZooDivTwo().count(vector <string>(field, field + (sizeof field / sizeof field[0])), dist);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
		default:
			return -1;
		}
	}
}
 

int main(int argc, char *argv[]) {
    if (argc == 1) {
        moj_harness::run_test();
    } else {
        for (int i=1; i<argc; ++i)
            moj_harness::run_test(atoi(argv[i]));
    }
    system("pause");
}
// END CUT HERE
