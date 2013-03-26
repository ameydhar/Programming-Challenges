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

class RailroadSeatNumeration {
template<class T> string toString(T n){ostringstream ost;ost<<n;ost.flush();return ost.str();}

bool isvaldom(int n)
{
	if(n>=1 && n<=9) return true;
	return false;
}

bool isvalint(int n)
{
	if(n==1 || n==3 || n==4 || n==6) return true;
	return false;
}

bool inran(int n)
{
	if(n>=1 && n<=36) return true;
	return false;
}

public:
string getInternational( vector <int> t )
{
	int n=SZ(t), grp;
	string ret = "";
	bool international = true, domestic = true;
	for(int i=0; i<n; ++i)
	{
		international = international & isvaldom(t[i]/10) & isvalint(t[i]%10);
		domestic = domestic & inran(t[i]);
	}	
		if(international & domestic) return "AMBIGUOUS";
		if(international)
		{
			for(int i=0; i<n; ++i)
			{
				if(i!=n-1) ret+=toString(t[i])+" ";
				else ret+=toString(t[i]);
			}
			return ret;
		}
		if(domestic)
		{
			for(int i=0; i<n; ++i)
			{
				grp = (t[i]/4)+((t[i]%4)==0?0:1);
				ret+=toString(grp);
				if(t[i]%4==1) ret+="1";
				else if(t[i]%4==2) ret+="3";
				else if(t[i]%4==3) ret+="4";
				else if(t[i]%4==0) ret+="6";
				if(i!=n-1) ret+=" ";
			}
			return ret;
		}
		return "BAD DATA";

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
			int tickets[]             = {1};
			string expected__         = "11";

			clock_t start__           = clock();
			string received__         = RailroadSeatNumeration().getInternational(vector <int>(tickets, tickets + (sizeof tickets / sizeof tickets[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			int tickets[]             = {11};
			string expected__         = "AMBIGUOUS";

			clock_t start__           = clock();
			string received__         = RailroadSeatNumeration().getInternational(vector <int>(tickets, tickets + (sizeof tickets / sizeof tickets[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			int tickets[]             = {45};
			string expected__         = "BAD DATA";

			clock_t start__           = clock();
			string received__         = RailroadSeatNumeration().getInternational(vector <int>(tickets, tickets + (sizeof tickets / sizeof tickets[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			int tickets[]             = {5, 7, 6};
			string expected__         = "21 24 23";

			clock_t start__           = clock();
			string received__         = RailroadSeatNumeration().getInternational(vector <int>(tickets, tickets + (sizeof tickets / sizeof tickets[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			int tickets[]             = {21, 24, 23};
			string expected__         = "AMBIGUOUS";

			clock_t start__           = clock();
			string received__         = RailroadSeatNumeration().getInternational(vector <int>(tickets, tickets + (sizeof tickets / sizeof tickets[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 5: {
			int tickets[]             = {8, 28};
			string expected__         = "26 76";

			clock_t start__           = clock();
			string received__         = RailroadSeatNumeration().getInternational(vector <int>(tickets, tickets + (sizeof tickets / sizeof tickets[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int tickets[]             = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = RailroadSeatNumeration().getInternational(vector <int>(tickets, tickets + (sizeof tickets / sizeof tickets[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int tickets[]             = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = RailroadSeatNumeration().getInternational(vector <int>(tickets, tickets + (sizeof tickets / sizeof tickets[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int tickets[]             = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = RailroadSeatNumeration().getInternational(vector <int>(tickets, tickets + (sizeof tickets / sizeof tickets[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 9: {
			int tickets[]             = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = RailroadSeatNumeration().getInternational(vector <int>(tickets, tickets + (sizeof tickets / sizeof tickets[0])));
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
