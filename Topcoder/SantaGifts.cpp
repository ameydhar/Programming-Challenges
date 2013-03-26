#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <string>
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
#define FOR(i,a,b)	for(int i=a;i<b;i++)
#define REP(i,n)	for(int i=0;i<n;i++)
#define SZ(a)		(int)(a.size())
#define SORT(CONTAINER)	sort((CONTAINER).begin(),(CONTAINER).end()); 
#define pb		push_back
#define fill(x,a)		memset(x, a, sizeof(x))

class SantaGifts {
public:
vector <string> distribute( vector <string> gifts, int n )
{
	vector < string > ret(n,"");
	vector < int > c(n,0);
	for(int i=0; i<SZ(gifts); ++i)
	{
		if(c[i%n]<4)
		{
			if(c[i%n]!=0) ret[i%n]+=' ';
			ret[i%n]+=gifts[i];
			c[i%n]++;
		}
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
	
	template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi=v.begin(); vi!=v.end(); ++vi) { if (vi != v.begin()) os << ","; os << " " << *vi; } os << " }"; return os; }
	template<> ostream& operator<<(ostream &os, const vector<string> &v) { os << "{"; for (vector<string>::const_iterator vi=v.begin(); vi!=v.end(); ++vi) { if (vi != v.begin()) os << ","; os << " \"" << *vi << "\""; } os << " }"; return os; }

	int verify_case(int casenum, const vector <string> &expected, const vector <string> &received, clock_t elapsed) { 
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
			string gifts[]            = {"ball","plane","robot","puzzle"};
			int N                     = 3;
			string expected__[]       = {"ball puzzle", "plane", "robot" };

			clock_t start__           = clock();
			vector <string> received__ = SantaGifts().distribute(vector <string>(gifts, gifts + (sizeof gifts / sizeof gifts[0])), N);
			return verify_case(casenum, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			string gifts[]            = {"ball","plane","robot","puzzle","bike"};
			int N                     = 1;
			string expected__[]       = {"ball plane robot puzzle" };

			clock_t start__           = clock();
			vector <string> received__ = SantaGifts().distribute(vector <string>(gifts, gifts + (sizeof gifts / sizeof gifts[0])), N);
			return verify_case(casenum, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			string gifts[]            = {"ball","ball","plane","plane"};
			int N                     = 2;
			string expected__[]       = {"ball plane", "ball plane" };

			clock_t start__           = clock();
			vector <string> received__ = SantaGifts().distribute(vector <string>(gifts, gifts + (sizeof gifts / sizeof gifts[0])), N);
			return verify_case(casenum, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 3: {
			string gifts[]            = {"ball","plane","robot"};
			int N                     = 5;
			string expected__[]       = {"ball", "plane", "robot", "", "" };

			clock_t start__           = clock();
			vector <string> received__ = SantaGifts().distribute(vector <string>(gifts, gifts + (sizeof gifts / sizeof gifts[0])), N);
			return verify_case(casenum, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			string gifts[]            = ;
			int N                     = ;
			string expected__[]       = ;

			clock_t start__           = clock();
			vector <string> received__ = SantaGifts().distribute(vector <string>(gifts, gifts + (sizeof gifts / sizeof gifts[0])), N);
			return verify_case(casenum, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 5: {
			string gifts[]            = ;
			int N                     = ;
			string expected__[]       = ;

			clock_t start__           = clock();
			vector <string> received__ = SantaGifts().distribute(vector <string>(gifts, gifts + (sizeof gifts / sizeof gifts[0])), N);
			return verify_case(casenum, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 6: {
			string gifts[]            = ;
			int N                     = ;
			string expected__[]       = ;

			clock_t start__           = clock();
			vector <string> received__ = SantaGifts().distribute(vector <string>(gifts, gifts + (sizeof gifts / sizeof gifts[0])), N);
			return verify_case(casenum, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 7: {
			string gifts[]            = ;
			int N                     = ;
			string expected__[]       = ;

			clock_t start__           = clock();
			vector <string> received__ = SantaGifts().distribute(vector <string>(gifts, gifts + (sizeof gifts / sizeof gifts[0])), N);
			return verify_case(casenum, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
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
