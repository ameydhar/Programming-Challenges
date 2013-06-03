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
#define ALL(a)          (a).begin(),(a).end()
#define SORT(CONTAINER)	sort((CONTAINER).begin(),(CONTAINER).end());
#define REVERSE(a)      reverse(ALL(a))
#define pb				push_back
#define INF				1000000000000000LL
#define fill(x,a)		memset(x, a, sizeof(x))


class MarbleNecklace 
{
public:
string normalize( string necklace ) ;
};

string MarbleNecklace::normalize( string necklace )
{
	int n = SZ(necklace);
	string s = necklace + necklace;
	set < string > seq;
	int fs = SZ(s) - n + 1;
	for(int i = 0; i < n; ++i)
	{
		seq.insert(s.substr(i,n));
	}
	REVERSE(s);
	for(int i = 0; i < n; ++i)
	{
		seq.insert(s.substr(i,n));
	}
	typeof((seq).begin()) it=(seq).begin();
	return *it;

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
			string necklace           = "CDAB";
			string expected__         = "ABCD";

			clock_t start__           = clock();
			string received__         = MarbleNecklace().normalize(necklace);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string necklace           = "RGB";
			string expected__         = "BGR";

			clock_t start__           = clock();
			string received__         = MarbleNecklace().normalize(necklace);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string necklace           = "TOPCODER";
			string expected__         = "CODERTOP";

			clock_t start__           = clock();
			string received__         = MarbleNecklace().normalize(necklace);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string necklace           = "SONBZELGFEQMSULZCNPJODOWPEWLHJFOEW";
			string expected__         = "BNOSWEOFJHLWEPWODOJPNCZLUSMQEFGLEZ";

			clock_t start__           = clock();
			string received__         = MarbleNecklace().normalize(necklace);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			string necklace           = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = MarbleNecklace().normalize(necklace);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			string necklace           = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = MarbleNecklace().normalize(necklace);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string necklace           = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = MarbleNecklace().normalize(necklace);
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
