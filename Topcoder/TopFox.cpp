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

class TopFox {
public:
int possibleHandles( string familyName, string givenName );
};

int TopFox::possibleHandles( string familyName, string givenName )
{
	set <string> s; 
	int a = SZ(familyName), b = SZ(givenName); 
	for(int i = 1; i <= a; ++i) 
	{ 
	  for(int j = 1; j <= b; ++j) 
	  { 
	    s.insert(familyName.substr(0,i) + givenName.substr(0,j)); 
	  } 
	} 
	int ret = SZ(s); 
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
			string familyName         = "ab";
			string givenName          = "cd";
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = TopFox().possibleHandles(familyName, givenName);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string familyName         = "abb";
			string givenName          = "bbc";
			int expected__            = 7;

			clock_t start__           = clock();
			int received__            = TopFox().possibleHandles(familyName, givenName);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string familyName         = "fox";
			string givenName          = "ciel";
			int expected__            = 12;

			clock_t start__           = clock();
			int received__            = TopFox().possibleHandles(familyName, givenName);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string familyName         = "abbbb";
			string givenName          = "bbbbbbbc";
			int expected__            = 16;

			clock_t start__           = clock();
			int received__            = TopFox().possibleHandles(familyName, givenName);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string familyName         = "abxy";
			string givenName          = "xyxyxc";
			int expected__            = 21;

			clock_t start__           = clock();
			int received__            = TopFox().possibleHandles(familyName, givenName);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			string familyName         = "ababababab";
			string givenName          = "bababababa";
			int expected__            = 68;

			clock_t start__           = clock();
			int received__            = TopFox().possibleHandles(familyName, givenName);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			string familyName         = ;
			string givenName          = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TopFox().possibleHandles(familyName, givenName);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string familyName         = ;
			string givenName          = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TopFox().possibleHandles(familyName, givenName);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string familyName         = ;
			string givenName          = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TopFox().possibleHandles(familyName, givenName);
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
