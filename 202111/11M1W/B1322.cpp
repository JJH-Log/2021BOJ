#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <utility>
#include <algorithm>
#include <cstring>
#include <math.h>
#include <set>
#include <cassert>
#include <sstream>
#define MOD 10007
#define BOUND 1000000000
#define MININT -2147483647
#define MAXINT 2147483647
using namespace std;
using lld = long long;

string encode(lld X) {
    string result = "";
    while (X) {
        if (X % 2) result += "1";
        else result += "0";
        X /= 2;
    }
    return result;
}

lld decode(string X) {
    lld result = 0;
    for (int i = 0; i < X.size(); i++) {        
        result *= 2;
        if (X[i] == '1') result += 1;
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int X, K, i, j;
    string x, k, result;
    lld Y;
    result = "";

    cin >> X >> K;
    x = encode(X), k = encode(K);
    i = j = 0;
    while(j < k.size()){
        if (i < x.size() && x[i] == '1') result += '0', i++;
        else result += k[j], i++, j++;
    }
    reverse(result.begin(), result.end());
    cout << decode(result);

    return 0;
}
