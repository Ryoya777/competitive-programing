#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <bitset>
#include <queue>
#include <map>
#include <utility>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define MOD 10000000000　+　7    //10億　= 10^9になってる
#define juu 100000               //10万 10e5
#define hyaku 1000000            //100万　10e6
#define mINF -922337200085470000 //llのmax-1桁の小さい方
#define pINF 922337203600070000  //llのmax-1桁のデカい方
#define uINF 1844674407300000000 //ullのmax-1桁してる
#define pi 3.1415926535897932384
ll factor[300];
ll memory[300];
/*素朴法で計算
factorは必ずmemset(factor,0,sizeof(factor));
グローバルであるmemoryに個数を書き込む
memory配列の走査にはfactorの要素を使う*/
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
}
/*グローバルにあるfactorに素数書き込む.個数を返すので配列は-1しろforは<*/
int elast(ll number)
{
    ll tmp = 0;
    int flag = 0;
    *factor = 2;
    for (int i = 3; i <= number; i++)
    {
        flag = 0;
        for (int j = 0; j <= tmp; j++)
        {
            if (i % (*(factor + j)) == 0)
            {
                flag = 1;
                break;
            }
        }
        if (flag)
            continue;
        tmp += 1;
        *(factor + tmp) = i;
    }
    return tmp + 2;
}
/*整数をqsortする為だけのもの*/
long long compare(const long long *a, const long long *b)
{
    if (*a < *b)
        return -1;
    else if (*a > *b)
        return 1;
    return 0;
}
/*intで収まる範囲であってくれ*/
ll nCr(int n, int r)
{
    ll val = 1;
    int i;
    if (r == 0)
        return 1;
    for (i = 0; i < n - r; i++)
    {
        val *= (n - i);
        val /= (i + 1);
    }
    return val;
}
/*intで収まる範囲であってくれ*/
ll nPr(int n, int r)
{
    ll val = 1;
    int i;
    for (i = 0; i < r; i++)
    {
        val *= (n - i);
    }
    return val;
}

void chmin(ll &a, ll b)
{
    if (a > b)
        a = b;
}
void chmax(ll &a, ll b)
{
    if (a < b)
        a = b;
}

/*
qsort(array,length,sizeof(int),(int(*)(const int*, const int*))compare);
使う時これをコピペ
*/


int main()
{
    
    return 0;
}
