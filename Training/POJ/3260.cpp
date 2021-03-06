// written at 14:50 on 1 Mar 2017 
#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <complex>
#include <deque>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector> 
#include <utility>
#include <bitset>
#include <numeric>

#define IOS std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
// #define __DEBUG__
#ifdef __DEBUG__
    #define DEBUG(...) printf(__VA_ARGS__)
#else
    #define DEBUG(...)
#endif
#define filename ""
#define setfile() freopen(filename".in", "r", stdin); freopen(filename".ans", "w", stdout);
#define resetfile() freopen("/dev/tty", "r", stdin); freopen("/dev/tty", "w", stdout); system("more " filename".ans");
#define rep(i, j, k) for (int i = j; i < k; ++i)
#define irep(i, j, k) for (int i = j - 1; i >= k; --i)

using namespace std;

template <typename T>
inline T sqr(T a) { return a * a;};

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int > Pii;

const double pi = acos(-1.0);
const int INF = INT_MAX;
const ll LLINF = LLONG_MAX;
const int MAX_T = 1e4 + 10;
const int MAX_V = 120 + 10;
const int MAX_W = MAX_T + MAX_V * MAX_V + 10;
const int MAX_N = 100 + 10;

int t, n, mv, w, V[MAX_N], C[MAX_N], dp1[MAX_W], dp2[MAX_V * MAX_V];

int main(int argc, char const *argv[])
{
    scanf("%d%d", &n, &t);
    rep(i, 0, n) scanf("%d", V + i), mv = max(mv, V[i]);
    rep(i, 0, n) scanf("%d", C + i);
    w = t + mv * mv + 1;
    rep(i, 1, w) dp1[i] = INF / 3;
    rep(i, 1, mv * mv + 1) dp2[i] = INF / 3;
    rep(i, 0, n) {
        int num = C[i];
        for (int k = 1; num > 0; k <<= 1) {
            int mul = min(k, num);
            for (int j = w; j >= V[i] * mul; --j)
                dp1[j] = min(dp1[j], dp1[j - V[i] * mul] + mul);
            num -= mul;
        }
    }
    rep(i, 0, n) rep(j, V[i], mv * mv + 1) 
        dp2[j] = min(dp2[j] , dp2[j - V[i]] + 1);
    int ans = INF / 3;
    rep(i, t, w) ans = min(dp1[i] + dp2[i - t], ans);
    printf("%d\n", ans == INF / 3? -1 : ans);
    return 0;
}