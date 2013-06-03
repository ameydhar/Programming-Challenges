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


class BettingStrategy 
{
public:
int finalSum( int initSum, string outcome ) ;
};

int BettingStrategy::finalSum( int initSum, string outcome )
{
	int n = SZ(outcome);
	int k = 1, rem = initSum, next = 1;
	for(int i = 0; i < n; ++i)
	{
		if(rem < next) return rem;
		if(outcome[i] == 'W')
		{
			rem += next;
			next = 1;
		}
		else if(outcome[i] == 'L')
		{
			rem -= next;
			next *= 2;
		}
	}
	return rem;

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

	int run_test_case(int casenum) {
		switch (casenum) {
		case 0: {
			int initSum               = 12;
			string outcome            = "WWWWWWWW";
			int expected__            = 20;

			clock_t start__           = clock();
			int received__            = BettingStrategy().finalSum(initSum, outcome);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int initSum               = 15;
			string outcome            = "LLLWLLLL";
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = BettingStrategy().finalSum(initSum, outcome);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int initSum               = 20;
			string outcome            = "WLWLWLWL";
			int expected__            = 23;

			clock_t start__           = clock();
			int received__            = BettingStrategy().finalSum(initSum, outcome);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int initSum               = 925;
			string outcome            = "WLLLLLWLLLLLLWWWWWLWLLWLLLLLLWL";
			int expected__            = 934;

			clock_t start__           = clock();
			int received__            = BettingStrategy().finalSum(initSum, outcome);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

      case 4: {
			int initSum               = 12;
			string outcome            = "LLLLLLLL";
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = BettingStrategy().finalSum(initSum, outcome);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
      case 5: {
			int initSum               = 42;
			string outcome            = "LLWLLWWWWLLLLLWLLWLLLWWLW";
			int expected__            = 16;

			clock_t start__           = clock();
			int received__            = BettingStrategy().finalSum(initSum, outcome);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
/*      case 6: {
			int initSum               = ;
			string outcome            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = BettingStrategy().finalSum(initSum, outcome);
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
