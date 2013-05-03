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


class DeerInZooDivTwo 
{
public:
vector <int> getminmax( int n, int k ) 
{
	vector < int > res;
	if(k == 0)
	{
		res.push_back(n);
		res.push_back(n);
		return res;
	}
	int b = n - (k/2) - (k%2);
	int a = max(0,n -k);
	res.push_back(a);
	res.push_back(b);
	return res;
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
	
	template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi=v.begin(); vi!=v.end(); ++vi) { if (vi != v.begin()) os << ","; os << " " << *vi; } os << " }"; return os; }

	int verify_case(int casenum, const vector <int> &expected, const vector <int> &received, clock_t elapsed) { 
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
			int N                     = 3;
			int K                     = 2;
			int expected__[]          = {1, 2 };

			clock_t start__           = clock();
			vector <int> received__   = DeerInZooDivTwo().getminmax(N, K);
			return verify_case(casenum, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			int N                     = 3;
			int K                     = 3;
			int expected__[]          = {0, 1 };

			clock_t start__           = clock();
			vector <int> received__   = DeerInZooDivTwo().getminmax(N, K);
			return verify_case(casenum, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			int N                     = 10;
			int K                     = 0;
			int expected__[]          = {10, 10 };

			clock_t start__           = clock();
			vector <int> received__   = DeerInZooDivTwo().getminmax(N, K);
			return verify_case(casenum, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 3: {
			int N                     = 654;
			int K                     = 321;
			int expected__[]          = {333, 493 };

			clock_t start__           = clock();
			vector <int> received__   = DeerInZooDivTwo().getminmax(N, K);
			return verify_case(casenum, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 4: {
			int N                     = 100;
			int K                     = 193;
			int expected__[]          = {0, 3 };

			clock_t start__           = clock();
			vector <int> received__   = DeerInZooDivTwo().getminmax(N, K);
			return verify_case(casenum, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int N                     = ;
			int K                     = ;
			int expected__[]          = ;

			clock_t start__           = clock();
			vector <int> received__   = DeerInZooDivTwo().getminmax(N, K);
			return verify_case(casenum, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 6: {
			int N                     = ;
			int K                     = ;
			int expected__[]          = ;

			clock_t start__           = clock();
			vector <int> received__   = DeerInZooDivTwo().getminmax(N, K);
			return verify_case(casenum, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 7: {
			int N                     = ;
			int K                     = ;
			int expected__[]          = ;

			clock_t start__           = clock();
			vector <int> received__   = DeerInZooDivTwo().getminmax(N, K);
			return verify_case(casenum, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
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
    while(1);
}
// END CUT HERE
