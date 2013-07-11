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

class Egalitarianism {
public:
int maxDifference( vector <string> f, int d );
};

#define MAXN	(55)
int parent[MAXN], rank[MAXN];
int n, d[MAXN][MAXN];
vector < string > f;

int find(int x)
{
	return parent[x] = (x == parent[x] ? x : find(parent[x]));
}

int init_uf()
{
	for(int i = 0; i < MAXN; ++i)
	{
		parent[i] = i; rank[i] = 0;
	}
}

void join(int x, int y)
{
	int a = find(x);
	int b = find(y);
	if(a == b) return;
	if(rank[a] < rank[b])
	{
		parent[a] = b;
		rank[a] += rank[b];
	}
	else
	{
		parent[b] = a;
		if(rank[a] == rank[b]) rank[b]++;
		else rank[b] += rank[a];
	}
}

int Egalitarianism::maxDifference( vector <string> _f, int amnt )
{
	f = _f;
	n = SZ(f);
	init_uf();
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			if(f[i][j] == 'Y') {d[i][j] = 1; join(i, j);}
			else if(i == j) d[i][j] = 0;
			else d[i][j] = (int)1e9;
		}
	}
	map < int , int > m;
	for(int i = 0; i < n; ++i)
	{
		parent[i] = find(parent[i]);
		if(m.find(parent[i]) == m.end())
		{
			m.insert(make_pair(parent[i], 1));
		}
		else
		{
			m[parent[i]] += 1;
		}
	}
	if(SZ(m) != 1) return -1;

	for(int k = 0; k < n; ++k)
	{
		for(int i = 0; i < n; ++i)
		{
			for(int j = 0; j < n; ++j)
			{
				d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
			}
		}
	}
	int ret = 0;
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			if(d[i][j] != (int)1e9) ret = max(ret, d[i][j]);
		}
	}
	if(ret == 0) return -1;

	return ret*amnt;
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
			string isFriend[]         = {"NYN",
 "YNY",
 "NYN"};
			int d                     = 10;
			int expected__            = 20;

			clock_t start__           = clock();
			int received__            = Egalitarianism().maxDifference(vector <string>(isFriend, isFriend + (sizeof isFriend / sizeof isFriend[0])), d);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string isFriend[]         = {"NN",
 "NN"};
			int d                     = 1;
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = Egalitarianism().maxDifference(vector <string>(isFriend, isFriend + (sizeof isFriend / sizeof isFriend[0])), d);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string isFriend[]         = {"NNYNNN",
 "NNYNNN",
 "YYNYNN",
 "NNYNYY",
 "NNNYNN",
 "NNNYNN"};
			int d                     = 1000;
			int expected__            = 3000;

			clock_t start__           = clock();
			int received__            = Egalitarianism().maxDifference(vector <string>(isFriend, isFriend + (sizeof isFriend / sizeof isFriend[0])), d);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string isFriend[]         = {"NNYN",
 "NNNY",
 "YNNN",
 "NYNN"};
			int d                     = 584;
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = Egalitarianism().maxDifference(vector <string>(isFriend, isFriend + (sizeof isFriend / sizeof isFriend[0])), d);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string isFriend[]         = {"NYNYYYN",
 "YNNYYYN",
 "NNNNYNN",
 "YYNNYYN",
 "YYYYNNN",
 "YYNYNNY",
 "NNNNNYN"};
			int d                     = 5;
			int expected__            = 20;

			clock_t start__           = clock();
			int received__            = Egalitarianism().maxDifference(vector <string>(isFriend, isFriend + (sizeof isFriend / sizeof isFriend[0])), d);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			string isFriend[]         = {"NYYNNNNYYYYNNNN",
 "YNNNYNNNNNNYYNN",
 "YNNYNYNNNNYNNNN",
 "NNYNNYNNNNNNNNN",
 "NYNNNNYNNYNNNNN",
 "NNYYNNYNNYNNNYN",
 "NNNNYYNNYNNNNNN",
 "YNNNNNNNNNYNNNN",
 "YNNNNNYNNNNNYNN",
 "YNNNYYNNNNNNNNY",
 "YNYNNNNYNNNNNNN",
 "NYNNNNNNNNNNNNY",
 "NYNNNNNNYNNNNYN",
 "NNNNNYNNNNNNYNN",
 "NNNNNNNNNYNYNNN"}
;
			int d                     = 747;
			int expected__            = 2988;

			clock_t start__           = clock();
			int received__            = Egalitarianism().maxDifference(vector <string>(isFriend, isFriend + (sizeof isFriend / sizeof isFriend[0])), d);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 6: {
			string isFriend[]         = {"NY",
 "YN"};
			int d                     = 0;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = Egalitarianism().maxDifference(vector <string>(isFriend, isFriend + (sizeof isFriend / sizeof isFriend[0])), d);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

      /*case 7: {
			string isFriend[]         = ;
			int d                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = Egalitarianism().maxDifference(vector <string>(isFriend, isFriend + (sizeof isFriend / sizeof isFriend[0])), d);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string isFriend[]         = ;
			int d                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = Egalitarianism().maxDifference(vector <string>(isFriend, isFriend + (sizeof isFriend / sizeof isFriend[0])), d);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 9: {
			string isFriend[]         = ;
			int d                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = Egalitarianism().maxDifference(vector <string>(isFriend, isFriend + (sizeof isFriend / sizeof isFriend[0])), d);
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
