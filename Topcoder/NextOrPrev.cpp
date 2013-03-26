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
#define SZ(a)			(int)(a.size())
#define ALL(a)			(a).begin(),(a).end()
#define SORT(a)			sort(ALL(a));
#define UNIQUE(a)		SORT(a);(a).resize(unique(ALL(a))-(a).begin())
#define fill(x,a)		memset(x, a, sizeof(x))

class NextOrPrev {
public:
int getMinimum( int nextCost, int prevCost, string start, string goal )
{
	int ret=(int)1e9;
	int n=SZ(start);
	for(int i=0; i<n; ++i)
	{
		for(int j=i+1; j<n; ++j)
		{
			if((start[i]>start[j] && goal[i]<goal[j])||(start[i]<start[j] && goal[i]>goal[j])) return -1;
		}
	}
	int c=0,ne=0,p=0;
	for(int i=0; i<n; ++i)
	{
		c=(goal[i]-start[i]);
		if(c>0) ne+=c;
		else if(c<0) p+=abs(c);
	}
	ret=min(ret,(p*prevCost + ne*nextCost));
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
			int nextCost              = 5;
			int prevCost              = 8;
			string start              = "ae";
			string goal               = "bc";
			int expected__            = 21;

			clock_t start__           = clock();
			int received__            = NextOrPrev().getMinimum(nextCost, prevCost, start, goal);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int nextCost              = 5;
			int prevCost              = 8;
			string start              = "ae";
			string goal               = "cb";
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = NextOrPrev().getMinimum(nextCost, prevCost, start, goal);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int nextCost              = 1;
			int prevCost              = 1;
			string start              = "srm";
			string goal               = "srm";
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = NextOrPrev().getMinimum(nextCost, prevCost, start, goal);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int nextCost              = 10;
			int prevCost              = 1;
			string start              = "acb";
			string goal               = "bdc";
			int expected__            = 30;

			clock_t start__           = clock();
			int received__            = NextOrPrev().getMinimum(nextCost, prevCost, start, goal);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			int nextCost              = 10;
			int prevCost              = 1;
			string start              = "zyxw";
			string goal               = "vuts";
			int expected__            = 16;

			clock_t start__           = clock();
			int received__            = NextOrPrev().getMinimum(nextCost, prevCost, start, goal);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 5: {
			int nextCost              = 563;
			int prevCost              = 440;
			string start              = "ptrbgcnlaizo";
			string goal               = "rtscedkiahul";
			int expected__            = 10295;

			clock_t start__           = clock();
			int received__            = NextOrPrev().getMinimum(nextCost, prevCost, start, goal);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 6: {
			int nextCost              = 126;
			int prevCost              = 311;
			string start              = "yovlkwpjgsna";
			string goal               = "zpwnkytjisob";
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = NextOrPrev().getMinimum(nextCost, prevCost, start, goal);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 7: {
			int nextCost              = ;
			int prevCost              = ;
			string start              = ;
			string goal               = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = NextOrPrev().getMinimum(nextCost, prevCost, start, goal);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int nextCost              = ;
			int prevCost              = ;
			string start              = ;
			string goal               = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = NextOrPrev().getMinimum(nextCost, prevCost, start, goal);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 9: {
			int nextCost              = ;
			int prevCost              = ;
			string start              = ;
			string goal               = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = NextOrPrev().getMinimum(nextCost, prevCost, start, goal);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 10: {
			int nextCost              = ;
			int prevCost              = ;
			string start              = ;
			string goal               = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = NextOrPrev().getMinimum(nextCost, prevCost, start, goal);
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
