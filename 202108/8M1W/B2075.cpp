#include <iostream>
#include <vector>
#include <string> //substr
#include <map>
#include <queue>
#include <stack>
#include <utility>  //pair
#include <algorithm> //sort, reverse
#include <math.h> // sqrt
#include <set>
#include <cassert>
#define MOD 1000000007
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;

vector<int> ptr;
vector<vector<int>> v;
int N;


int getMaxCol() {
    int key = -2e9;
    int result = -1;
    for (int j = 0; j < N; j++) {
        if (v[ptr[j]][j] > key) {
            key = v[ptr[j]][j];
            result = j;
        }
    }
    return result;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int i, j, ans;
    cin >> N;
    v.resize(N, vector<int>(N, 0));
    ptr.resize(N, N - 1);
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) cin >> v[i][j];
    }

    for (i = 1; i < N; i++) {
        ans = getMaxCol();
        ptr[ans]--;
    }
    ans = getMaxCol();
    cout << v[ptr[ans]][ans];

    return 0;
}