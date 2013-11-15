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
#define FOREACH(i,a)	for(typeof((a).begin()) i=(a).begin();i!=(a).end();i++)
#define SZ(a)		(int)(a.size())
#define ALL(a)		(a).begin(),(a).end()
#define SORT(a)	sort(ALL(a));
#define UNIQUE(a)	SORT(a);(a).resize(unique(ALL(a))-(a).begin())
#define fill(x,a)		memset(x, a, sizeof(x))

class ColorfulRoad {
public:
	int getMin( string road );
};

int cost[16];

int ColorfulRoad::getMin( string road )
{
	int n = SZ(road);
	char cur;
	for(int i = 0; i < 16; ++i)
	{
		cost[i] = (int)1e9;
	}
	cost[0] = 0;
	for(int i = 1; i < n; ++i)
	{
		cur = road[i];
		if(cur == 'R')
		{
			for(int k = i-1; k >=0 ; --k)
			{
				if(road[k] == 'B') {cost[i] = min(cost[i], cost[k]+(k-i)*(k-i));}	
			}
		}
		else if(cur == 'G')
		{
			for(int k = i-1; k >=0 ; --k)
			{
				if(road[k] == 'R') {cost[i] = min(cost[i], cost[k]+(k-i)*(k-i));}	
			}
		}
		else if(cur == 'B')
		{
			for(int k = i-1; k >=0 ; --k)
			{
				if(road[k] == 'G') {cost[i] = min(cost[i], cost[k]+(k-i)*(k-i));}	
			}
		}
	}
	if(cost[n-1] == (int)1e9) return -1;
	return cost[n-1];

	return 0;
}

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

int run_test_case(int casenum__) {
	switch (casenum__) {
		case 0: {
			string road               = "RGGGB";
			int expected__            = 8;

			clock_t start__           = clock();
			int received__            = ColorfulRoad().getMin(road);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string road               = "RGBRGBRGB";
			int expected__            = 8;

			clock_t start__           = clock();
			int received__            = ColorfulRoad().getMin(road);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string road               = "RBBGGGRR";
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = ColorfulRoad().getMin(road);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string road               = "RBRRBGGGBBBBR";
			int expected__            = 50;

			clock_t start__           = clock();
			int received__            = ColorfulRoad().getMin(road);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string road               = "RG";
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = ColorfulRoad().getMin(road);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			string road               = "RBRGBGBGGBGRGGG";
			int expected__            = 52;

			clock_t start__           = clock();
			int received__            = ColorfulRoad().getMin(road);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			string road               = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ColorfulRoad().getMin(road);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string road               = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ColorfulRoad().getMin(road);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string road               = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ColorfulRoad().getMin(road);
			return verify_case(casenum__, expected__, received__, clock()-start__);
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
