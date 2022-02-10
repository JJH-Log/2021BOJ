#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <utility>  //pair 사용
#include <algorithm> //reverse 사용
#include <math.h> // sqrt 사용
#include <set>
#define MOD 1000000007
//for (const auto& i : v) cout << i << ' ';
using namespace std;
using lld = long long;

vector<string> v;
set<string> st;

string parse(string s, int i, int j) {
	int k;
	string result = "";
	for (k = i; k < j; k++) result += s[k];
	return result;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t, T, i, j, k;
	string s;
	string t1, t2, t3;
	cin >> T;
	cin.ignore();
	for (t = 0; t < T; t++) {
		getline(cin, s);
		i = 0;
		for (j = 0; j < s.size(); j++) {
			if (s[j] == ' ') {
				v.push_back(parse(s, i, j));
				i = j + 1;
			}
		}
		v.push_back(parse(s, i, j));
		while (true) {
			cin >> t1 >> t2 >> t3;
			if (t2[0] == 'd') break;
			st.insert(t3);
		}
		cin >> t1 >> t2;
		for (i = 0; i < v.size(); i++) {
			if (st.count(v[i])) v[i] = "";
		}
		for (i = 0; i < v.size(); i++) {
			if (v[i] != "") cout << v[i] << ' ';
		}
		cin.ignore();
		v.clear();
		st.clear();
	}

	return 0;
}