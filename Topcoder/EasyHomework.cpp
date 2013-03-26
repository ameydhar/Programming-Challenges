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

class EasyHomework {
public:
string determineSign( vector <int> A )
{
	int n=SZ(A);
	int ret=1;
	for(int i=0; i<n; ++i)
	{
		if(A[i]==0) ret=0;
		else if(A[i]<0) ret*=(-1);
	}
	if(ret==0) return "ZERO";
	if(ret<0) return "NEGATIVE";
	return "POSITIVE";

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
	
	int verify_case(int casenum, const string &expected, const string &received, clock_t elapsed) { 
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
			cerr << "    Expected: \"" << expected << "\"" << endl; 
			cerr << "    Received: \"" << received << "\"" << endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum) {
		switch (casenum) {
		case 0: {
			int A[]                   = {5, 7, 2};
			string expected__         = "POSITIVE";

			clock_t start__           = clock();
			string received__         = EasyHomework().determineSign(vector <int>(A, A + (sizeof A / sizeof A[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int A[]                   = {-5, 7, 2};
			string expected__         = "NEGATIVE";

			clock_t start__           = clock();
			string received__         = EasyHomework().determineSign(vector <int>(A, A + (sizeof A / sizeof A[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int A[]                   = {5, 7, 2, 0};
			string expected__         = "ZERO";

			clock_t start__           = clock();
			string received__         = EasyHomework().determineSign(vector <int>(A, A + (sizeof A / sizeof A[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int A[]                   = {3, -14, 159, -26};
			string expected__         = "POSITIVE";

			clock_t start__           = clock();
			string received__         = EasyHomework().determineSign(vector <int>(A, A + (sizeof A / sizeof A[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			int A[]                   = {-1000000000};
			string expected__         = "NEGATIVE";

			clock_t start__           = clock();
			string received__         = EasyHomework().determineSign(vector <int>(A, A + (sizeof A / sizeof A[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 5: {
			int A[]                   = {123, -456, 789, -101112, 131415, 161718, 192021, 222324, 252627, 282930, 313233, 343536, 373839, 404142, 434445, 464748, 495051, 525354, 555657};
			string expected__         = "POSITIVE";

			clock_t start__           = clock();
			string received__         = EasyHomework().determineSign(vector <int>(A, A + (sizeof A / sizeof A[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int A[]                   = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = EasyHomework().determineSign(vector <int>(A, A + (sizeof A / sizeof A[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int A[]                   = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = EasyHomework().determineSign(vector <int>(A, A + (sizeof A / sizeof A[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int A[]                   = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = EasyHomework().determineSign(vector <int>(A, A + (sizeof A / sizeof A[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 9: {
			int A[]                   = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = EasyHomework().determineSign(vector <int>(A, A + (sizeof A / sizeof A[0])));
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
}
// END CUT HERE
