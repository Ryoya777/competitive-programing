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
using ld = long double;
using vi = vector<int>;
using vvi = vector<vi>;  // vvi g(N, vi(M, 0));  // vector<vector<int>>g(N, vector<int>(M, 0));
using vl = vector<ll>;
using vvl = vector<vl>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vd = vector<double>;
using vs = vector<string>;
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
#define maxitr(vec) max_element(vec.begin(), vec.end())
#define minitr(vec) min_element(vec.begin(), vec.end())
#define sortAsc(vec) sort(vec.begin(), vec.end())
#define sortDesc(vec) sort(vec.begin(), vec.end(), greater<int>())
#define ceil(x, y) (x + y - 1) / y
template <class T> void chmin(T& a, T b){if(a > b) a = b;}
template <class T> void chmax(T& a, T b){if(a < b) a = b;}

// // 判定問題の最後
// if(ok) cout << "Yes" << endl;
// else cout << "No" << endl;

int main(){
    int n; cin >> n;
    string s; cin >> s;
    int i=0;
    string t = "";
    while(i<n){
        if(s[i]=='n'){
            if(i<n-1 && s[i+1]=='a'){
                t += "nya";
                i += 2;
            }
          	else{
              t += s[i];
              i++;
            }
        }
        else{
            t += s[i];
            i++;
        }
    }
    cout << t << endl;
}

/*
別解
int main() {
    int n; cin >> n;
    string s; cin >> s;

    // "na" を "nya" に置換
    for (int ind = 0; ind < n - 1; ind++) {
        if (s[ind] == 'n' && s[ind + 1] == 'a') {
            s.insert(ind + 1, "y");
            ind++; // 'y' を挿入した後、'y' の次の文字に移動
            n++;   // 文字列 `s` の長さが増えたので、n をインクリメント(+1)
        }
    }

    cout << s << endl;
    return 0;
}
*/

/*
文字列の処理．
挿入するならinsertメソッドもあるが，それだと，文字列の長さが変わるのでnを増やす必要がある．
文字列の長さが増えた時に，nを増やすことに注意．
*/