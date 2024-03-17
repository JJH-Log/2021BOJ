#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int,int>> v;

int main() {
    int i, N, temp;
    cin >> N;

    v.resize(N, make_pair(0,0));
    for (i = 0; i < N; i++) {
        scanf("%d", &temp);
        v[i] = make_pair(temp, i + 1);
    }
    sort(v.begin(), v.end());
    for (i = 0; i < N; i++) {
        printf("%d\n", (v[i].first - v[i].second));
    }
    return 0;
}

