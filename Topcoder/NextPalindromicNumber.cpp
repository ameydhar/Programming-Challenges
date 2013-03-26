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

class NextPalindromicNumber {
public:
bool ispalin(string s)
{
	int n=SZ(s);
	for(int i=0; i<n/2; ++i)
	{
		if(s[i]!=s[n-1-i]) return false;
	}
	return true;
}

string getNext( string n )
{
	string s=n;
	int len=SZ(s);
	if(!ispalin(n))
	{
		for(int i=0; i<len/2; ++i)
		{
			s[len-1-i]=s[i];
		}
		if(n>s) getNext(s);
		else return s;
	}
	if(len%2)
	{
		int start=len/2;
		int i=0;
		bool end=false;
		do
		{
			s[start-i]++;
			if(i) s[start+i]++;
			if(s[start-i]>'9')
			{
				s[start-i]='0';
				s[start+i]='0';
			}
			else end=true;
			i++;
		}while(!end && start-i>=0);
		if(!end)
		{
			s="1"+s;
			s[SZ(s)-1]='1';
		}
	}
	else
	{
		int start=len/2;
		int i=1;
		bool end=false;
		do
		{
			s[start-i]++;
			s[start+i-1]++;
			if(s[start-i]>'9')
			{
				s[start-i]='0';
				s[start+i-1]='0';
			}
			else end=true;
			i++;
		}while(!end && start-i>=0);
		if(!end)
		{
			s="1"+s;
			s[SZ(s)-1]='1';
		}
	}
	return s;
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
	
	int verify_case(int casenum, const string &expected, const string &received, clock_t elapsed) { 
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
			cerr << "    Expected: \"" << expected << "\"" << endl; 
			cerr << "    Received: \"" << received << "\"" << endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum) {
		switch (casenum) {
		case 0: {
			string n                  = "12345";
			string expected__         = "12421";

			clock_t start__           = clock();
			string received__         = NextPalindromicNumber().getNext(n);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string n                  = "858";
			string expected__         = "868";

			clock_t start__           = clock();
			string received__         = NextPalindromicNumber().getNext(n);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string n                  = "1999";
			string expected__         = "2002";

			clock_t start__           = clock();
			string received__         = NextPalindromicNumber().getNext(n);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string n                  = "1";
			string expected__         = "2";

			clock_t start__           = clock();
			string received__         = NextPalindromicNumber().getNext(n);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			string n                  = "9999";
			string expected__         = "10001";

			clock_t start__           = clock();
			string received__         = NextPalindromicNumber().getNext(n);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string n                  = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = NextPalindromicNumber().getNext(n);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string n                  = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = NextPalindromicNumber().getNext(n);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string n                  = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = NextPalindromicNumber().getNext(n);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string n                  = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = NextPalindromicNumber().getNext(n);
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
