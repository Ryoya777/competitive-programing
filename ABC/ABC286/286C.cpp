#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <bitset>
#include <set>
#include <numeric>
#include <unordered_map>
#include <climits>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using vi = vector<int>;
using vvi = vector<vi>;  // vvi g(N, vi(M, 0));  // vector<vector<int>>g(N, vector<int>(M, 0));
using vl = vector<ll>;
using vvl = vector<vl>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vd = vector<double>;
using vs = vector<string>;
using vvs = vector<vs>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;
using vpii = vector<pii>;
using vpll = vector<pll>;
using vpdd = vector<pdd>;
using Graph = vector<vector<int>>;    // グラフを明示的に宣言
const int inf = 1 << 30;
const ll INF = 1LL << 60;
const ll MOD = 998244353;
const ll MOD2 = 1000000007;
#define rep(i, n) for(int i=0; i<n; i++)
#define rep2(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)  // i..配列aの、a[i]が示す値。
#define err setprecision(12)  // 誤差問題では、 cout << err << ans << endl;
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define allvec(vec) vec.begin(), vec.end()
#define maxitr(vec) max_element(allvec(vec))
#define minitr(vec) min_element(allvec(vec))
#define sortAsc(vec) sort(vec.begin(), vec.end())
#define sortDesc(vec) sort(vec.begin(), vec.end(), greater<int>())
#define ceil(x, y) (x + y - 1) / y
template <class T> void chmin(T& a, T b){if(a > b) a = b;}
template <class T> void chmax(T& a, T b){if(a < b) a = b;}

// // 判定問題の最後
// if(ok) cout << "Yes" << endl;
// else cout << "No" << endl;

int main(){
    ll N, A, B; cin >> N >> A >> B;
    string S; cin >> S;
    string T = S + S;
    ll p = 0;  // どこから数えるか。Aするたびに１増える (0<=p<=N-1)
    ll ans = INF;
    for(int pi=0; pi<=N-1; pi++){
        ll ans2 = A * pi;
        int i = pi;
        int j = i + (N-1);
        if(N%2==0){
            while(i<((N/2)+pi)){
                if(T[i]!=T[j]){
                    ans2 += B;
                }
                i++;
                j--;
            }
        }
        else{
            while(i<((N/2)+pi)){
                if(T[i]!=T[j]){
                    ans2 += B;
                }
                i++;
                j--;
            }
        }
        chmin(ans, ans2);
    }
    cout << ans << endl;
}