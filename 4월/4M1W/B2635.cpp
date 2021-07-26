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
	int i, N, t1, t2, t3, count, ans, ans_i;
	cin >> N;

	//A = N / 2;
	//B = N / 4 * 3;

	ans = 0;
	for (i = 1; i <= N; i++) {
		t1 = N;
		t2 = i;
		count = 2;
		while (t1 >= t2) {
			t3 = t1 - t2;
			t1 = t2;
			t2 = t3;
			count++;
		}
		if (count > ans) {
			ans = count;
			ans_i = i;
		}
	}
	cout << ans << endl;
	t1 = N;
	t2 = ans_i;
	while (t1 >= t2) {
		printf("%d ", t1);
		t3 = t1 - t2;
		t1 = t2;
		t2 = t3;
	}
	cout << t1 << " " << t2;
}
