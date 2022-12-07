#include <bits/stdc++.h>

using namespace std;

/*
    patameters:
    base: int
    exp: int
    mod: int
    returns result of base^exp%mod using fast modular exponentiation algorithm
*/
int fastModularExponentiaion(int base, int exp, int mod)
{
    int bit = ceil(log2(exp)), res = 1, power = base % mod;
    for(int i = 0; i <= bit; i++)
    {
        //bit exists
        if((int)pow(2, i) & exp) res = res * power % mod;
        power = power * power % mod;
    }
    return res;
}

/*
    parametes:
    m: int
    n: int
    returns true if n is probably prime and false if composite for single base created randonly
*/
bool singleTest(int m, int n)
{
    //creates random base a where 2 <= a <= n - 1
    int a = 2 + rand() % (n - 4);
    //computes a ^ m % n with fast modular exponentiation
    int res = fastModularExponentiaion(a, m, n);
    //prime if the result is 1 or n - 1
    if(res == 1 || res == n - 1) return true;
    //loop stops when m truns back to its original value n - 1
    while(m != n - 1)
    {
        //try make res reaches n - 1 or 1 to decide whether true or false by multiplying res by itself with mod n
        res = res * res % n;
        m *= 2;
        if(res == 1) return false;
        else if(res == n - 1) return true;
    }
    return false;
}

/*
    parameters:
    n: int
    k: int
    test number n k of times, if passes all tests, returns true indicating probably prime 
    and false if fails one test al least indicating composite
*/
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
