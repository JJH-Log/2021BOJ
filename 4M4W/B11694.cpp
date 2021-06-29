#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <utility>  //pair 사용
#include <algorithm> //reverse 사용
#include <math.h> // sqrt 사용
#include <set>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, temp, N, result; //state1, state2
	int FLAG;
	cin >> N;
	result = 0;
	FLAG = 1;
	for (i = 0; i < N; i++) {
		cin >> temp;
		if (temp > 1) FLAG = 0;
		result = result ^ temp;
	}
	if (FLAG) {
		if (result) cout << "cubelover";
		else cout << "koosaga";
	}
	else {
		if (result) cout << "koosaga";
		else cout << "cubelover";
	}


	return 0;
}
