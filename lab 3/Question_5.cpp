#include <bits/stdc++.h>

using namespace std;

long long fast_modular_exponentiaion(long long base, long long exp, long long mod)
{
    long long bit = ceil(log2(exp)), res = 1, power = base % mod;
    for(long long i = 0; i <= bit; i++)
    {
        //bit exists
        if((long long)pow(2, i) & exp) res = res * power % mod;
        power = power * power % mod;
    }
    return res;
}

bool single_test(int m, int n)
{
    int a = 2 + rand() % (n - 4);
    int res = fast_modular_exponentiaion(a, m, n);
    if(res == 1 || res == n - 1) return true;
    while(m != n - 1)
    {
        res = res * res % n;
        m *= 2;
        if(res == 1) return false;
        else if(res == n - 1) return true;
    }
    return false;
}

bool millerTest(int n, int k)
{
    if(n == 1 || n == 4) return false;
    else if(n == 2 || n == 3) return true;
    int m = n - 1;
    while(m % 2 == 0) m /= 2;
    for(int i = 0; i < k; i++) if(single_test(m, n)) return false;
    return true;
}

int main()
{
    cout << "Enter n & k with space separated: ";
    int n, k;
    cin >> n >> k;
    if(!millerTest(n, k)) cout << "Probably prime" << endl;
    else cout << "Not prime" << endl;
}
