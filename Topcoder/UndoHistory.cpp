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

class UndoHistory {
public:
	int minPresses( vector <string> lines );
};


bool prefix(string pre, string s)
{
	if(SZ(pre) <= SZ(s) && s.substr(0,SZ(pre)) == pre) return true;
	return false;
}

int UndoHistory::minPresses( vector <string> lines )
{
	vector < string > undo;
	int n = SZ(lines);
	undo.push_back("");
	string curr = "";
	int press = 0, best;

	for(int i = 0; i < n; ++i)
	{
		best = (int)1e9;

		if(prefix(curr, lines[i]))
		{
			best = min(best, SZ(lines[i])-SZ(curr)+1);
		}
		for(int j = 0; j < SZ(undo); ++j)
		{
			if(prefix(undo[j], lines[i]))
			{
				best = min(best, SZ(lines[i])-SZ(undo[j])+1+2);
			}
		}
		press += best;
		for(int j = 0; j < SZ(lines[i]); ++j)
		{
			undo.push_back(lines[i].substr(0,j));
		}
		curr = lines[i];
	}
	return press;
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
			string lines[]            = {"tomorrow", "topcoder"};
			int expected__            = 18;

			clock_t start__           = clock();
			int received__            = UndoHistory().minPresses(vector <string>(lines, lines + (sizeof lines / sizeof lines[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string lines[]            = {"a","b"};
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = UndoHistory().minPresses(vector <string>(lines, lines + (sizeof lines / sizeof lines[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string lines[]            = {"a", "ab", "abac", "abacus" };
			int expected__            = 10;

			clock_t start__           = clock();
			int received__            = UndoHistory().minPresses(vector <string>(lines, lines + (sizeof lines / sizeof lines[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string lines[]            = {"pyramid", "sphinx", "sphere", "python", "serpent"};
			int expected__            = 39;

			clock_t start__           = clock();
			int received__            = UndoHistory().minPresses(vector <string>(lines, lines + (sizeof lines / sizeof lines[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			string lines[]            = {"ba","a","a","b","ba"}
			;
			int expected__            = 13;

			clock_t start__           = clock();
			int received__            = UndoHistory().minPresses(vector <string>(lines, lines + (sizeof lines / sizeof lines[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string lines[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = UndoHistory().minPresses(vector <string>(lines, lines + (sizeof lines / sizeof lines[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string lines[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = UndoHistory().minPresses(vector <string>(lines, lines + (sizeof lines / sizeof lines[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string lines[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = UndoHistory().minPresses(vector <string>(lines, lines + (sizeof lines / sizeof lines[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string lines[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = UndoHistory().minPresses(vector <string>(lines, lines + (sizeof lines / sizeof lines[0])));
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
