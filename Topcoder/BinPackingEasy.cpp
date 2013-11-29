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

class BinPackingEasy {
public:
	int minBins( vector <int> item );
};

int vis[55];

int BinPackingEasy::minBins( vector <int> item )
{
	int n = SZ(item), ret = 0, rem;
	for(int i = 0; i < 55; ++i)
	{
		vis[i] = false;
	}
	SORT(item);
 
	for(int z = 0; z < n; ++z)
	{
		if(vis[z]) continue;
		vis[z] = 1;
		ret++;
		rem = 300 - item[z];
		for(int i = n-1; i > z; --i)
		{
			if(vis[i]) continue;
			if(!vis[i] && item[i] > rem) continue;
			if(!vis[i] && item[i] <= rem)
			{
				rem -= item[i];
				vis[i] = true;
			}
		}
	}
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
			int item[]                = {150, 150, 150, 150, 150};
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = BinPackingEasy().minBins(vector <int>(item, item + (sizeof item / sizeof item[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int item[]                = {130, 140, 150, 160};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = BinPackingEasy().minBins(vector <int>(item, item + (sizeof item / sizeof item[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int item[]                = {101, 101, 101, 101, 101, 101, 101, 101, 101};
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = BinPackingEasy().minBins(vector <int>(item, item + (sizeof item / sizeof item[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int item[]                = {101, 200, 101, 101, 101, 101, 200, 101, 200};
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = BinPackingEasy().minBins(vector <int>(item, item + (sizeof item / sizeof item[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int item[]                = {123, 145, 167, 213, 245, 267, 289, 132, 154, 176, 198};
			int expected__            = 8;

			clock_t start__           = clock();
			int received__            = BinPackingEasy().minBins(vector <int>(item, item + (sizeof item / sizeof item[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

      case 5: {
			int item[]                = {199, 102};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = BinPackingEasy().minBins(vector <int>(item, item + (sizeof item / sizeof item[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
      case 6: {
			int item[]                = {160, 150, 140, 150};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = BinPackingEasy().minBins(vector <int>(item, item + (sizeof item / sizeof item[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
/*      case 7: {
			int item[]                = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = BinPackingEasy().minBins(vector <int>(item, item + (sizeof item / sizeof item[0])));
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
