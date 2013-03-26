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

class Arrows {
public:
int ret;
int n;
string y;
vector < int > posl;
vector < int > posr;
	
int trackl(int x, char t)
{
	int l=1;
	for(int i=x-1; i>=0; --i)
	{
		if(y[i]==t) l++;
		else break;
	}
	return l;
}

int trackr(int x, char t)
{
	int l=1;
	for(int i=x+1; i<n; ++i)
	{
		if(y[i]==t) l++;
		else break;
	}
	return l;
}

int longestArrow( string s )
{
	y=s;
	n=SZ(s);
	ret=0;
	for(int i=0; i<n; ++i)
	{
		if(s[i]=='<') posl.push_back(i);
		if(s[i]=='>') posr.push_back(i);
	}
	if(SZ(posl)==0 && SZ(posr)==0) return -1;
	ret=1;
	for(int i=0; i<SZ(posl); ++i)
	{
		if(posl[i]<(n-1) && s[posl[i]+1]!='>' && s[posl[i]+1]!='<') ret=max(ret,trackr(posl[i], s[posl[i]+1]));
	}
	for(int i=0; i<SZ(posr); ++i)
	{
		if(posr[i]>0 && s[posr[i]-1]!='>' && s[posr[i]-1]!='<') ret=max(ret,trackl(posr[i], s[posr[i]-1]));
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
			string s                  = "<--->--==>";
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = Arrows().longestArrow(s);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string s                  = "<<<<<<<<<<";
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = Arrows().longestArrow(s);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string s                  = "----==-";
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = Arrows().longestArrow(s);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string s                  = "<----=====>";
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = Arrows().longestArrow(s);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			string s                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = Arrows().longestArrow(s);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			string s                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = Arrows().longestArrow(s);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string s                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = Arrows().longestArrow(s);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string s                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = Arrows().longestArrow(s);
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
    while(1);
}
// END CUT HERE
