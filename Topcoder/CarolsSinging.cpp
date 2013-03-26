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

class CarolsSinging {
public:
int choose( vector <string> lyrics )
{
	int mem=SZ(lyrics);
	int n=SZ(lyrics[0]);
	int ans=(int)1e9;
	for(int carols=0; carols<(1<<n); ++carols)
	{
		bool done=true;
		for(int i=0; i<mem; ++i)
		{
			bool sings=false;
			for(int j=0; j<n; ++j)
			{
				if(lyrics[i][j]=='Y' && (carols & (1<<j))) sings=true;
			}
			if(!sings) {done=false; break;}
		}
		if(done) ans=min(ans, __builtin_popcount(carols));
	}
	return ans;

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
			string lyrics[]           = {"YN","NY"};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = CarolsSinging().choose(vector <string>(lyrics, lyrics + (sizeof lyrics / sizeof lyrics[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string lyrics[]           = {"YN","YY","YN"};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = CarolsSinging().choose(vector <string>(lyrics, lyrics + (sizeof lyrics / sizeof lyrics[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string lyrics[]           = {"YNN","YNY","YNY","NYY","NYY","NYN"};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = CarolsSinging().choose(vector <string>(lyrics, lyrics + (sizeof lyrics / sizeof lyrics[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string lyrics[]           = {"YNNYYY","YYNYYY","YNNYYN","NYYNNN","YYYNNN","YYYNNY","NYYYYY","NYNYYY","NNNNYY",
 "YYYYYY","YNNNNN","YYYYNY","YYNNNN","NNYYYN","NNNNYY","YYYNNN","NYNNYN","YNNYYN",
 "YYNNNY","NYYNNY","NNYYYN","YNYYYN","NNNYNY","YYYYNN","YYNYNN","NYYNYY","YYNYYN"};
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = CarolsSinging().choose(vector <string>(lyrics, lyrics + (sizeof lyrics / sizeof lyrics[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			string lyrics[]           = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = CarolsSinging().choose(vector <string>(lyrics, lyrics + (sizeof lyrics / sizeof lyrics[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			string lyrics[]           = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = CarolsSinging().choose(vector <string>(lyrics, lyrics + (sizeof lyrics / sizeof lyrics[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string lyrics[]           = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = CarolsSinging().choose(vector <string>(lyrics, lyrics + (sizeof lyrics / sizeof lyrics[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string lyrics[]           = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = CarolsSinging().choose(vector <string>(lyrics, lyrics + (sizeof lyrics / sizeof lyrics[0])));
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
