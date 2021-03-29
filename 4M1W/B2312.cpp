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

//vector<pair<int, int>> v;
vector<int> ar;


void getPrime(int x, int N) {
	int i, count;
	bool flag = true;
	for (i = x; i <= sqrt(N); i++) {
		if (N % i == 0) {
			count = 0;
			while (N % i == 0) {
				N = N / i;
				count++;
			}
			cout << i << " " << count << endl;
			getPrime(i, N);
			flag = false;
			i = N;
		}
	}
	if (flag && (N != 1)) {
		cout << N << " " << 1 << endl;
	}
}

int main() {
	int c, T, N;
	cin >> T;
	for (c = 0; c < T; c++) {
		cin >> N;
		getPrime(2, N);
	}
}