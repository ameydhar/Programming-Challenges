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

class TypoCoderDiv2 {
public:
int count( vector <int> rating );
};

int TypoCoderDiv2::count( vector <int> rating )
{
	int n = SZ(rating);
	int c = 0, ret = 0;
	for(int i = 0; i < n; ++i)
	{
		if(c == 0 && rating[i] >= 1200) {c = 1; ret++;}
		else if(c == 1 && rating[i] < 1200) {c = 0; ret++;}
	}
	return ret;

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
			int rating[]              = {1000,1200,1199};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = TypoCoderDiv2().count(vector <int>(rating, rating + (sizeof rating / sizeof rating[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int rating[]              = {1500,2200,900,3000};
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = TypoCoderDiv2().count(vector <int>(rating, rating + (sizeof rating / sizeof rating[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int rating[]              = {600,700,800,900,1000,1100,1199};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = TypoCoderDiv2().count(vector <int>(rating, rating + (sizeof rating / sizeof rating[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int rating[]              = {0,4000,0,4000,4000,0,0};
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = TypoCoderDiv2().count(vector <int>(rating, rating + (sizeof rating / sizeof rating[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int rating[]              = {575,1090,3271,2496,859,2708,3774,2796,1616,2552,3783,2435,1111,526,562};
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = TypoCoderDiv2().count(vector <int>(rating, rating + (sizeof rating / sizeof rating[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

      case 5: {
			int rating[]              = {1200,1199,1200,1199};
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = TypoCoderDiv2().count(vector <int>(rating, rating + (sizeof rating / sizeof rating[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
/*      case 6: {
			int rating[]              = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TypoCoderDiv2().count(vector <int>(rating, rating + (sizeof rating / sizeof rating[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int rating[]              = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TypoCoderDiv2().count(vector <int>(rating, rating + (sizeof rating / sizeof rating[0])));
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
