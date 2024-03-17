#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <utility>  //pair 사용
#include <algorithm> //reverse 사용
#include <math.h> // sqrt 사용
#include <set>
#include <stack>
//for (const auto& i : v) cout << i << ' ';
using namespace std;

stack<char> st;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, N, K, cnt;
	string s; 
	string result;
	cin >> N >> K;
	cin >> s;
	cnt = 0;
	for (i = 0; i < N; i++) {
		while (true) {
			if (st.empty() || (st.top() >= s[i]) || (cnt == K)) break;
			st.pop();
			cnt++;
		}
		st.push(s[i]);
	}
	while (!st.empty()) {
		while (cnt != K) {
			st.pop();
			cnt++;
		}
		if (!result.size()) result = st.top();
		else result += st.top();
		st.pop();
	}
	reverse(result.begin(), result.end());
	cout << result;
	return 0;
}