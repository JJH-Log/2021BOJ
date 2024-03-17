//B11502

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

#include <string.h>

#include <math.h>

#include <set>

#include <cassert>

#include <bitset>

#include <sstream>

#include <cmath>

#include <random>

#include <numeric>

#define MOD 1000000007

#define BOUND 200000

#define MININT -2147483647

#define MAXINT 2147483647

#define MAXN 1000001

using namespace std;

using lld = long long;

using pii = pair<int, int>;

using pll = pair<lld, lld>;

int T;

vector<int> pr;

bool isPrime(int X) {

   for (int i = 0; pr[i] <= sqrt(X); i++) {

      if (X % pr[i] == 0) return false;

   }

   return true;

}

void solve(int tar) {

   for (int i = 0; pr[i] <= tar; i++) {

      for (int j = i; pr[i] + pr[j] <= tar; j++) {

         for (int k = j; pr[i] + pr[j] + pr[k] <= tar; k++) {

            if (pr[i] + pr[j] + pr[k] == tar) {

               cout << pr[i] << ' ' << pr[j] << ' ' << pr[k] << '\n';

               return;

            }

         }

      }

   }

   cout << 0 << '\n';

}

int main() {

   ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

   pr.push_back(2);

   for (int i = 3; i <= 1000; i += 2) if (isPrime(i)) pr.push_back(i);

   cin >> T;

   while (T--) {

      int N;

      cin >> N;

      solve(N);

   }

   return 0;

}