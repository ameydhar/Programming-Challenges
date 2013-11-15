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

class FoxAndSightseeing {
public:
int getMin( vector <int> position );
};

vector < int > e;
int calc()
{
	int ret = 0;
	for(int i = 1; i < SZ(e); ++i)
	{
		ret += abs(e[i] - e[i-1]);
	}
	return ret;
}

int FoxAndSightseeing::getMin( vector <int> position )
{
	int n = SZ(position);
	int mini = (int)1e9, ans = 0;
	for(int i = 1; i < n-1; ++i)
	{
		int s = i, d = 0;
		e.clear();
		for(int j = 0; j < n; ++j)
		{
			if(j != s)
			{
				e.push_back(position[j]);
			}
		}
		d = calc();
		if(d < mini) {mini = d;}
	}
	return mini;

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
			int position[]            = {1, 4, -1, 3};
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = FoxAndSightseeing().getMin(vector <int>(position, position + (sizeof position / sizeof position[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int position[]            = {-2, 4, 3};
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = FoxAndSightseeing().getMin(vector <int>(position, position + (sizeof position / sizeof position[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int position[]            = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
			int expected__            = 9;

			clock_t start__           = clock();
			int received__            = FoxAndSightseeing().getMin(vector <int>(position, position + (sizeof position / sizeof position[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int position[]            = {100, -100, 99, -99};
			int expected__            = 199;

			clock_t start__           = clock();
			int received__            = FoxAndSightseeing().getMin(vector <int>(position, position + (sizeof position / sizeof position[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int position[]            = {74,84,92,23,5,-70,-47,-59,24,-86,-39,99,85,-42,54,100,47,-3,42,38};
			int expected__            = 836;

			clock_t start__           = clock();
			int received__            = FoxAndSightseeing().getMin(vector <int>(position, position + (sizeof position / sizeof position[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int position[]            = {2,-3,5,7,-11,-13,17,-19,23,29,-31,-37,-41,43,-47,-53,-59,61,-67,71};
			int expected__            = 535;

			clock_t start__           = clock();
			int received__            = FoxAndSightseeing().getMin(vector <int>(position, position + (sizeof position / sizeof position[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int position[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = FoxAndSightseeing().getMin(vector <int>(position, position + (sizeof position / sizeof position[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int position[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = FoxAndSightseeing().getMin(vector <int>(position, position + (sizeof position / sizeof position[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int position[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = FoxAndSightseeing().getMin(vector <int>(position, position + (sizeof position / sizeof position[0])));
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
