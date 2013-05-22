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
#define FOREACH(i,a)    for(typeof((a).begin()) i=(a).begin();i!=(a).end();i++)
#define REP(i,n)		for(int i=0;i<n;i++)
#define SZ(a)			(int)(a.size())
#define SORT(CONTAINER)	sort((CONTAINER).begin(),(CONTAINER).end()); 
#define pb				push_back
#define INF				1000000000000000LL
#define fill(x,a)		memset(x, a, sizeof(x))


class PositiveID 
{
public:
int maximumFacts( vector <string> suspects ) ;
};


vector < string > split(string s, string del = ",")
{
	s += del[0];
	string w;
	vector < string > res;
	FOREACH(it,s)
	{
		if(find(del.begin(),del.end(),*it) == del.end()) w += *it;
		else if(w != "") {res.push_back(w); w = "";}
	}
	return res;
}

vector < string > strtovs(string s, string del=",")
{
	vector < string > v = split(s,del);  /* When we call this function string 'del in split should be blank */
	vector < string > res; 
	FOREACH(it,v) res.push_back(*it);
	return res;
}

int PositiveID::maximumFacts( vector <string> suspects )
{
	int ret = 0;
	int n = SZ(suspects);
	vector < string > chars;
	vector < string > traits[55];
	if(n==1) return 0;
	for(int i = 0; i < n; ++i)
	{
		chars = strtovs(suspects[i]);
		for(int j = 0; j < SZ(chars); ++j)
		{
			traits[i].pb(chars[j]);
		}
	}
	int best = 0;
	for(int i = 0; i < n; ++i)
	{
		for(int j = i+1; j < n; ++j)
		{
			int cnt = 0;
			for(int k = 0; k < SZ(traits[i]); ++k)
			{
				for(int l = 0; l < SZ(traits[j]); ++l)
				{
					if(traits[i][k] == traits[j][l]) {cnt++; break;}
				}
			}
			best = max(best, cnt);
		}
	}
	return best;


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
			string suspects[]         = {"blond,tall,skinny",
"short,skinny,blond,tattooed",
"scarred,bald"};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = PositiveID().maximumFacts(vector <string>(suspects, suspects + (sizeof suspects / sizeof suspects[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string suspects[]         = {"gigantic,fluorescent,loud,male"};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = PositiveID().maximumFacts(vector <string>(suspects, suspects + (sizeof suspects / sizeof suspects[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string suspects[]         = {"medium,average,nondescript",
"medium,average,nondescript"};
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = PositiveID().maximumFacts(vector <string>(suspects, suspects + (sizeof suspects / sizeof suspects[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string suspects[]         = {"big,tall,loud,happy,male,scarred,tattooed,dirty",
"short,male,beard,quiet,happy,tanned,handsome",
"female,pretty,blond,quiet",
"somnambulistic",
"happy,tiny,stout,male,tanned,beard,blond"};
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = PositiveID().maximumFacts(vector <string>(suspects, suspects + (sizeof suspects / sizeof suspects[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			string suspects[]         = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = PositiveID().maximumFacts(vector <string>(suspects, suspects + (sizeof suspects / sizeof suspects[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			string suspects[]         = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = PositiveID().maximumFacts(vector <string>(suspects, suspects + (sizeof suspects / sizeof suspects[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string suspects[]         = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = PositiveID().maximumFacts(vector <string>(suspects, suspects + (sizeof suspects / sizeof suspects[0])));
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
