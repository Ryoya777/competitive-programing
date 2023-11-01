#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cstdint>
#include <cassert>
#include <numeric>
#include <string>
#include <complex>
#include <algorithm>
#include <iostream>
#include <vector>
#include <bitset>
#include <deque>
#include <queue>
#include <map>
#include <utility>
#include <functional>
#include <iomanip>
#include <chrono>
#include <unordered_map>
#include <set>
using namespace std;
using ull = uint64_t;
using ll = int_fast64_t;
using prll = pair<ll, ll>;
constexpr ll MOD = 1000000007; //10億　= 10^9になってる
constexpr ll mINF = -(1LL << 60);
constexpr ll pINF = 1LL << 60;
constexpr ull uINF = 1844674407399900000; //ullのmax-1桁してる
constexpr long double pi = 3.1415926535897932384;
constexpr ll juu = 100000;    //10万 10e5
constexpr ll hyaku = 1000000; //100万　10e6
constexpr int dx[4] = {0, 0, 1, -1};
constexpr int dy[4] = {1, -1, 0, 0};
constexpr int ddx[8] = {0, 0, 1, -1, 1, 1, -1, -1};
constexpr int ddy[8] = {1, -1, 0, 0, -1, 1, 1, -1};
#define all(v) v.begin(), v.end()
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define repN(i, first, end) for (ll i = first; i < (ll)(end); ++i)
#define Debug(xx) cerr << " DEBUG:" << xx << endl;
#define Debug2(xx, yy) cerr << " DEBUG:" << xx << ":" << yy << endl;
vector<int> factor;
/*
ll factor[300];
ll memory[300];
素朴法で計算
factorは必ずmemset(factor,0,sizeof(factor));
グローバルであるmemoryに個数を書き込む
memory配列の走査にはfactorの要素を使う
void primefac(ll num)
{
    int i = 0, kosuu = 0;
    while (*(factor + i) != 0)
    {
        while (num % *(factor + i) == 0)
        {
            num /= *(factor + i);
            memory[*(factor + i)] += 1;
        }
        if (num == 1)
            break;
        i++;
    }
}*/

/*どこまで篩を使いたいか、と初期化のみしたvectorを与える,個数が帰ってくる*/
int elast(int maximum)
{
    ll cnt = 1;
    int size_of_vector = maximum / 3 + 100;
    factor.reserve(size_of_vector);
    bool flag = false;
    factor.emplace_back(2);
    for (ll i = 3; i <= maximum; i += 2)
    {
        flag = false;
        for (auto &fac : factor)
        {
            //if (i % (*factor_itr) == 0)
            if (i % fac == 0)
            {
                flag = true;
                break;
            }
        }
        if (flag)
            continue;
        ++cnt;
        factor.emplace_back(i);
    }
    return cnt;
}

//繰り返し二乗。掛けられる数、回数、mod
ll powpow(ll n, ll p)
{
    if (p == 0)
    {
        return 1;
    }
    if (p == 1)
        return n % MOD;
    if (p % 2 == 1)
    {
        return (n * powpow(n, p - 1)) % MOD;
    }
    ll dob = powpow(n, p / 2);
    return (dob * dob) % MOD;
}

//MODとn、rが互いに素である事が確定していないとこれは出来ない。小定理、またchild,parentでおかしくなる。 mod取った後にそれら同士で割り算するとおかしくなるから逆元使う。（合同式の性質考えろ）
ll nCrMod(ll n, ll r)
{
    ll child = 1;
    ll parent = 1;
    if (r == 0)
        return 1;
    for (ll i = 0; i < r; ++i)
    {
        child = child * (n - i) % MOD;
        parent = parent * (r - i) % MOD;
    }
    ll ans = child * powpow(parent, MOD - 2);
    return ans % MOD;
}
ll to_digit(ll num)
{
    return (ll)(to_string(num).size());
}
ll nCr(ll n, ll r)
{
    ll val = 1, val2 = 1;
    if (r == 0)
        return 1;
    if (n < r)
        return 0;
    for (ll i = 0; i < r; ++i)
    {
        val *= (n - i);
        val2 *= (r - i);
    }
    return val / val2;
}
ll nPr(ll n, ll r)
{
    ll val = 1;
    for (ll i = 0; i < r; ++i)
    {
        val *= (n - i);
    }
    return val;
}
template <typename T>
bool chmin(T &a, const T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}
template <typename T>
bool chmax(T &a, const T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}

/*ソートして被りを無くす*/
template <typename T>
void eraseSame(T &a)
{
    sort(all(a));
    a.erase(unique(all(a)), a.end());
}

/*aとbで大きい方を後ろにする。変更なしならtrue、ありならfalse */
template <typename T>
bool swapmax(T &a, T &b)
{
    T temp;
    temp = a;
    if (a > b)
    {
        swap(a, b);
        return false;
    }
    return true;
}
ll GCD(ll x, ll y) { return (x % y) ? GCD(y, x % y) : y; }
ll LCD(ll x, ll y) { return x / GCD(x, y) * y; }

/*一行に入力が何個あるかを1,ぶち込むvectorを2*/
template <typename T>
void splitIn(ll N, vector<T> &array)
{
    T temp;
    int i = 0;
    if (N == 0)
    {
        return;
    }
    array.resize(N);
    while (cin >> temp)
    {
        array[i] = temp;
        ++i;
        if (i >= N)
        {
            break;
        }
    }
    return;
}
ll facmod(ll num)
{
    ll ans = 1;
    if (num == 0)
        return 1;
    for (ll i = num; i >= 1; --i)
    {
        ans = (ans * i) % MOD;
    }
    return ans;
}

ll inv_num(ll num)
{
    return powpow(num, MOD - 2);
}
/*時間計測
chrono::system_clock::time_point  start, end;
start = chrono::system_clock::now();

end = std::chrono::system_clock::now();
double elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();
*/
signed main()
{
    // int32_t max = 2,147,483,648 (10桁)
    // int64_t max = 9,223,372,036,854,775,808 (19桁)
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //cout << fixed << setprecision(20);
    ll n = 0,ans = 0,sum = 0;
    string s;
    vector<ll> v;
    cin >> n;

    cout << ans << "\n";
    return 0;
}