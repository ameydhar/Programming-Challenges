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

class VowelEncryptor {
	bool isvowel(char x)
	{
		if(x=='a' || x=='e' || x=='i' || x=='o' || x=='u') return true;
		return false;
	}
public:
   vector <string> encrypt( vector <string> text ) {
	   int n=SZ(text),i,j;
	   vector < string > ans;
	   for(i=0; i<n; ++i)
	   {
		   int x = SZ(text[i]);
		   string ret="";
		   for(j=0; j<x; ++j)
		   {
			   if(!isvowel(text[i][j])) ret+=text[i][j];
		   }
		   if(ret=="") ret=text[i];
		   ans.push_back(ret);
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
			string text[]             = {"hello", "world"};
			string expected__[]       = {"hll", "wrld" };

			clock_t start__           = clock();
			vector <string> received__ = VowelEncryptor().encrypt(vector <string>(text, text + (sizeof text / sizeof text[0])));
			return verify_case(casenum, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			string text[]             = {"a", "b", "c"};
			string expected__[]       = {"a", "b", "c" };

			clock_t start__           = clock();
			vector <string> received__ = VowelEncryptor().encrypt(vector <string>(text, text + (sizeof text / sizeof text[0])));
			return verify_case(casenum, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			string text[]             = {"he", "who", "is", "greedy", "is", "disgraced"};
			string expected__[]       = {"h", "wh", "s", "grdy", "s", "dsgrcd" };

			clock_t start__           = clock();
			vector <string> received__ = VowelEncryptor().encrypt(vector <string>(text, text + (sizeof text / sizeof text[0])));
			return verify_case(casenum, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

/*      case 3: {
			string text[]             = ;
			string expected__[]       = ;

			clock_t start__           = clock();
			vector <string> received__ = VowelEncryptor().encrypt(vector <string>(text, text + (sizeof text / sizeof text[0])));
			return verify_case(casenum, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 4: {
			string text[]             = ;
			string expected__[]       = ;

			clock_t start__           = clock();
			vector <string> received__ = VowelEncryptor().encrypt(vector <string>(text, text + (sizeof text / sizeof text[0])));
			return verify_case(casenum, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 5: {
			string text[]             = ;
			string expected__[]       = ;

			clock_t start__           = clock();
			vector <string> received__ = VowelEncryptor().encrypt(vector <string>(text, text + (sizeof text / sizeof text[0])));
			return verify_case(casenum, vector <string>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 6: {
			string text[]             = ;
			string expected__[]       = ;

			clock_t start__           = clock();
			vector <string> received__ = VowelEncryptor().encrypt(vector <string>(text, text + (sizeof text / sizeof text[0])));
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
