#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <stack>
#include <queue>
#include <utility>  //pair 사용
#include <algorithm> //reverse 사용
#include <math.h> // sqrt 사용
#include <set>
//for (const auto& i : v) cout << i << ' ';
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string S, T;
	string result;
	cin >> S >> T;
	int i, j, FLAG;
	result = "";
	for (i = 0; i < S.size(); i++) {
		result += S[i];
		if (S[i] == T[T.size() - 1]) {
			if (result.size() >= T.size()) {
				FLAG = 1;
				for (j = 0; j < T.size(); j++) {
					if (result[result.size() - 1 - j] != T[T.size() - 1 - j]) FLAG = 0;
				}
				if (FLAG) result.erase(result.size() - T.size(), T.size());
			}
		}
	}
	if (result == "") cout << "FRULA";
	else cout << result;
	return 0;
}