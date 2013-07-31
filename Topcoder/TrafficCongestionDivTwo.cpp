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

class TrafficCongestionDivTwo {
public:
long long theMinCars( int treeHeight );
};

long long ret[65];

long long TrafficCongestionDivTwo::theMinCars( int treeHeight )
{
	ret[0] = 1;
	ret[1] = 1;
	ret[2] = 3;
	for(int i = 3; i < treeHeight + 1; ++i)
	{
		ret[i] = (long long)ret[i-1] + (2LL*(long long)ret[i-2]);
	}
	return ret[treeHeight];


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
	
	int verify_case(int casenum, const long long &expected, const long long &received, clock_t elapsed) { 
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
			int treeHeight            = 1;
			long long expected__      = 1;

			clock_t start__           = clock();
			long long received__      = TrafficCongestionDivTwo().theMinCars(treeHeight);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int treeHeight            = 2;
			long long expected__      = 3;

			clock_t start__           = clock();
			long long received__      = TrafficCongestionDivTwo().theMinCars(treeHeight);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int treeHeight            = 3;
			long long expected__      = 5;

			clock_t start__           = clock();
			long long received__      = TrafficCongestionDivTwo().theMinCars(treeHeight);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int treeHeight            = 10;
			long long expected__      = 683;

			clock_t start__           = clock();
			long long received__      = TrafficCongestionDivTwo().theMinCars(treeHeight);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int treeHeight            = 60;
			long long expected__      = 768614336404564651LL;

			clock_t start__           = clock();
			long long received__      = TrafficCongestionDivTwo().theMinCars(treeHeight);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

      case 5: {
			int treeHeight            = 0;
			long long expected__      = 1;

			clock_t start__           = clock();
			long long received__      = TrafficCongestionDivTwo().theMinCars(treeHeight);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
      case 6: {
			int treeHeight            = 32;
			long long expected__      = 2863311531;

			clock_t start__           = clock();
			long long received__      = TrafficCongestionDivTwo().theMinCars(treeHeight);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
/*      case 7: {
			int treeHeight            = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = TrafficCongestionDivTwo().theMinCars(treeHeight);
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
