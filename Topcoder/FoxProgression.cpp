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

class FoxProgression {
public:
int theCount( vector <int> seq );
};

int FoxProgression::theCount( vector <int> seq )
{
	int n = SZ(seq);
	if(n == 1) return -1;
	int api = seq[1] - seq[0];
	int gpi = seq[1]/seq[0];
	bool ap = true, gp = true;
	for(int i = 1; i < n; ++i)
	{
		if(seq[i] - seq[i-1] != api) {ap = false; break;}
	}
	for(int i = 1; i < n; ++i)
	{
		if(seq[i]/seq[i-1] != gpi || seq[i]%seq[i-1] != 0) {gp = false; break;}
	}
	vector < int > v;
	if(ap) v.push_back(seq[n-1] + api);
	if(gp) v.push_back(seq[n-1] * gpi);
	UNIQUE(v);
	return SZ(v);
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
			int seq[]                 = {1, 2, 4, 8};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = FoxProgression().theCount(vector <int>(seq, seq + (sizeof seq / sizeof seq[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int seq[]                 = {5, 3, 1};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = FoxProgression().theCount(vector <int>(seq, seq + (sizeof seq / sizeof seq[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int seq[]                 = {1, 1};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = FoxProgression().theCount(vector <int>(seq, seq + (sizeof seq / sizeof seq[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int seq[]                 = {8, 4};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = FoxProgression().theCount(vector <int>(seq, seq + (sizeof seq / sizeof seq[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int seq[]                 = {1};
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = FoxProgression().theCount(vector <int>(seq, seq + (sizeof seq / sizeof seq[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int seq[]                 = {4, 8};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = FoxProgression().theCount(vector <int>(seq, seq + (sizeof seq / sizeof seq[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 6: {
			int seq[]                 = {1, 3, 4};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = FoxProgression().theCount(vector <int>(seq, seq + (sizeof seq / sizeof seq[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 7: {
			int seq[]                 = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = FoxProgression().theCount(vector <int>(seq, seq + (sizeof seq / sizeof seq[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int seq[]                 = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = FoxProgression().theCount(vector <int>(seq, seq + (sizeof seq / sizeof seq[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 9: {
			int seq[]                 = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = FoxProgression().theCount(vector <int>(seq, seq + (sizeof seq / sizeof seq[0])));
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
