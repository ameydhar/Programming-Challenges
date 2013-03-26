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


class Chopsticks 
{
int s[105];
public:
int getmax( vector <int> length ) 
{
	SORT(length); 
	int n=SZ(length); 
	if(SZ(length)<2) return 0; 
	int ret=0; 
	for(int i=0; i<n; ++i) 
	{ 
		s[length[i]]++; 
	} 
	for(int i=0; i<105; ++i) 
	{	 
		ret+=(s[i])/2; 
	} 
	return ret; 
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
			int length[]              = {5,5};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = Chopsticks().getmax(vector <int>(length, length + (sizeof length / sizeof length[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int length[]              = {1,2,3,2,1,2,3,2,1};
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = Chopsticks().getmax(vector <int>(length, length + (sizeof length / sizeof length[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int length[]              = {1};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = Chopsticks().getmax(vector <int>(length, length + (sizeof length / sizeof length[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int length[]              = {1,2,3,4,5,6,7,8,9};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = Chopsticks().getmax(vector <int>(length, length + (sizeof length / sizeof length[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			int length[]              = {35,35,35,50,16,30,10,10,35,50,16,16,16,30,50,30,16,35,50,30,10,50,50,16,16, 10,35,50,50,50,16,35,35,30,35,10,50,10,50,50,16,30,35,10,10,30,10,10,16,35};
			int expected__            = 24;

			clock_t start__           = clock();
			int received__            = Chopsticks().getmax(vector <int>(length, length + (sizeof length / sizeof length[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

      case 5: {
			int length[]              = {100,2,37,37,2,100,2,100,37,2};
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = Chopsticks().getmax(vector <int>(length, length + (sizeof length / sizeof length[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
/*      case 6: {
			int length[]              = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = Chopsticks().getmax(vector <int>(length, length + (sizeof length / sizeof length[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int length[]              = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = Chopsticks().getmax(vector <int>(length, length + (sizeof length / sizeof length[0])));
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
