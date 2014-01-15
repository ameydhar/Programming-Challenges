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

class CellRemoval {
public:
int cellsLeft( vector <int> parent, int deletedCell );
};

vector < int > p;
int d;
bool rem[55], notleaf[55];

int CellRemoval::cellsLeft( vector <int> parent, int deletedCell )
{
	p = parent;
	d = deletedCell;
	int n = SZ(p), cur;
	for(int i = 0; i < 55; ++i)
	{
		notleaf[i] = 0;
		rem[i] = 0;
	}
	for(int i = 0; i < n; ++i)
	{
		cur = i;
		while(cur != d && cur != -1)
		{
			cur = p[cur];
			if(cur != -1) notleaf[cur] = 1;
		}
		if(cur == d) rem[i] = 0;
		else if(cur == -1) rem[i] = 1; 
	}
	int ret = 0;
	for(int i = 0; i < n; ++i)
	{
		if(notleaf[i] == 0 && rem[i]) ret++;
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
			int parent[]              = {-1,0,0,1,1};
			int deletedCell           = 2;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = CellRemoval().cellsLeft(vector <int>(parent, parent + (sizeof parent / sizeof parent[0])), deletedCell);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int parent[]              = {-1,0,0,1,1};
			int deletedCell           = 1;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = CellRemoval().cellsLeft(vector <int>(parent, parent + (sizeof parent / sizeof parent[0])), deletedCell);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int parent[]              = {-1,0,0,1,1};
			int deletedCell           = 0;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = CellRemoval().cellsLeft(vector <int>(parent, parent + (sizeof parent / sizeof parent[0])), deletedCell);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int parent[]              = {-1,0,0,2,2,4,4,6,6};
			int deletedCell           = 4;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = CellRemoval().cellsLeft(vector <int>(parent, parent + (sizeof parent / sizeof parent[0])), deletedCell);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int parent[]              = {26,2,32,36,40,19,43,24,30,13,21,14,24,21,19,4,30,10,44,12,7,32,17,43, 35,18,7,36,10,16,5,38,35,4,13,-1,16,26,1,12,2,5,18,40,1,17,38,44,14};
			int deletedCell           = 24;
			int expected__            = 14;

			clock_t start__           = clock();
			int received__            = CellRemoval().cellsLeft(vector <int>(parent, parent + (sizeof parent / sizeof parent[0])), deletedCell);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int parent[]              = ;
			int deletedCell           = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = CellRemoval().cellsLeft(vector <int>(parent, parent + (sizeof parent / sizeof parent[0])), deletedCell);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int parent[]              = ;
			int deletedCell           = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = CellRemoval().cellsLeft(vector <int>(parent, parent + (sizeof parent / sizeof parent[0])), deletedCell);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int parent[]              = ;
			int deletedCell           = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = CellRemoval().cellsLeft(vector <int>(parent, parent + (sizeof parent / sizeof parent[0])), deletedCell);
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
