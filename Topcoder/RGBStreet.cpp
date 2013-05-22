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
#define FOREACH(i,a)    for(typeof((a).begin()) i=(a).begin();i!=(a).end();i++)
#define SZ(a)			(int)(a.size())
#define SORT(CONTAINER)	sort((CONTAINER).begin(),(CONTAINER).end()); 
#define pb				push_back
#define INF				1000000000000000LL
#define fill(x,a)		memset(x, a, sizeof(x))


class RGBStreet 
{
public:
int estimateCost( vector <string> houses ) ;
};

int dp[25][3];

vector < string > split(string s, string del = " ")
{
	s += del[0];
	string w;
	vector < string > res;
	FOREACH(it,s)
	{
		if(find(del.begin(),del.end(),*it) == del.end()) w += *it;
		else if(w != "") {res.push_back(w); w="";}
	}
	return res;
}

int toInt(string s){int r=0;istringstream sin(s);sin>>r;return r;}

vector < int > strtovi(string s, string del = " ")
{
	vector < string > v = split(s,del);
	vector < int > res; 
	FOREACH(it,v) res.push_back(toInt(*it));
	return res;
}

int RGBStreet::estimateCost( vector <string> houses )
{
	int n = SZ(houses);
	vector < int > rate;
	int cost[n][3];
	for(int i = 0; i < n; ++i)
	{
		rate = strtovi(houses[i]);
		for(int j = 0; j < SZ(rate); ++j)
		{
			cost[i][j] = rate[j];
		}
	}
	fill(dp, (int)1e9);

	for(int i = 0; i < 3; ++i)
	{
		dp[0][i] = cost[0][i];
	}

	for(int i = 1; i < n; ++i)
	{
		dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + cost[i][0];
		dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + cost[i][1];
		dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + cost[i][2];
	}
	return min(dp[n-1][0], min(dp[n-1][1], dp[n-1][2]));

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
			string houses[]           = {"1 100 100", "100 1 100", "100 100 1"};
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = RGBStreet().estimateCost(vector <string>(houses, houses + (sizeof houses / sizeof houses[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string houses[]           = {"1 100 100", "100 100 100", "1 100 100"};
			int expected__            = 102;

			clock_t start__           = clock();
			int received__            = RGBStreet().estimateCost(vector <string>(houses, houses + (sizeof houses / sizeof houses[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string houses[]           = {"26 40 83", "49 60 57", "13 89 99"};
			int expected__            = 96;

			clock_t start__           = clock();
			int received__            = RGBStreet().estimateCost(vector <string>(houses, houses + (sizeof houses / sizeof houses[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string houses[]           = {"30 19 5", "64 77 64", "15 19 97", "4 71 57", "90 86 84", "93 32 91"};
			int expected__            = 208;

			clock_t start__           = clock();
			int received__            = RGBStreet().estimateCost(vector <string>(houses, houses + (sizeof houses / sizeof houses[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			string houses[]           = {"71 39 44", "32 83 55", "51 37 63", "89 29 100", 
 "83 58 11", "65 13 15", "47 25 29", "60 66 19"};
			int expected__            = 253;

			clock_t start__           = clock();
			int received__            = RGBStreet().estimateCost(vector <string>(houses, houses + (sizeof houses / sizeof houses[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string houses[]           = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = RGBStreet().estimateCost(vector <string>(houses, houses + (sizeof houses / sizeof houses[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string houses[]           = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = RGBStreet().estimateCost(vector <string>(houses, houses + (sizeof houses / sizeof houses[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string houses[]           = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = RGBStreet().estimateCost(vector <string>(houses, houses + (sizeof houses / sizeof houses[0])));
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
