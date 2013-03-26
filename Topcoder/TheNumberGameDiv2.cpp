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

class TheNumberGameDiv2 {
public:
template<class T> string toString(T n){ostringstream ost;ost<<n;ost.flush();return ost.str();}

int minimumMoves( int a, int b )
{
	string sa,sb,sar="";
	sa=toString(a);
	for(int i=SZ(sa)-1; i>=0; --i)
	{
		sar+=sa[i];
	}
	sb=toString(b);
	if(sa.find(sb)==string::npos && sar.find(sb)==string::npos) return -1;
	
	int ret=(int)1e9, c=0;
	int la=SZ(sa), lb=SZ(sb);
	unsigned int found1=sa.find(sb), found2=sar.find(sb);
	
	if(found1!=string::npos)
	{
		c=la-found1-lb;
		if(found1!=0) c+=2;
		c+=found1;
		ret=min(ret,c);
	}
	c=0;
	if(found2!=string::npos)
	{
		c+=1;
		c+=la-found2-lb;
		c+=found2;
		ret=min(ret,c);
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
			int A                     = 25;
			int B                     = 5;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = TheNumberGameDiv2().minimumMoves(A, B);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int A                     = 5162;
			int B                     = 16;
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = TheNumberGameDiv2().minimumMoves(A, B);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int A                     = 334;
			int B                     = 12;
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = TheNumberGameDiv2().minimumMoves(A, B);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int A                     = 218181918;
			int B                     = 9181;
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = TheNumberGameDiv2().minimumMoves(A, B);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			int A                     = 9798147;
			int B                     = 79817;
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = TheNumberGameDiv2().minimumMoves(A, B);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

      case 5: {
			int A                     = 12345;
			int B                     = 54321;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = TheNumberGameDiv2().minimumMoves(A, B);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
      case 6: {
			int A                     = 121212;
			int B                     = 21;
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = TheNumberGameDiv2().minimumMoves(A, B);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
      case 7: {
			int A                     = 2121212;
			int B                     = 12;
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = TheNumberGameDiv2().minimumMoves(A, B);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
      case 8: {
			int A                     = 41378;
			int B                     = 31;
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = TheNumberGameDiv2().minimumMoves(A, B);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
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
