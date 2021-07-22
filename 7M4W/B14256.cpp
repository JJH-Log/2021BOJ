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
#define MOD 1000000007
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;

lld result = 0;
vector<bool> v; //visited

int cntSqr(int key, int A, int B) {
    if (v[key]) return 0;
    int acnt = 1;
    int bcnt = 1;
    while (key * bcnt * bcnt <= B) {
        v[key * bcnt * bcnt] = true;
        if (key * bcnt * bcnt <= A) acnt++;
        bcnt++;
    }
    //cout << "KEY : " << key << ' ' << (acnt - 1) * (bcnt - 1) << endl;
    return (acnt - 1) * (bcnt - 1);
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int i, A, B;
    cin >> A >> B;
    if (A > B) swap(A, B);
    v.resize(B + 1, false);
    result = 0;
    for (i = 1; i <= A; i++) {
        result += cntSqr(i, A, B);
    }
    cout << result;
    return 0;
}