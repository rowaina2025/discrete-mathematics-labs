#include <bits/stdc++.h>
using namespace std;

/*
    parameters:
    n: int
    primes[]: bool
    void function sets index j to false if j is composite and to true if j is prime
*/
void sieve(int n, bool primes[])
{
    for(int i = 2; i <= n; i++) primes[i] = true;
    for(int i = 2; i <= sqrt(n); i++)
    {
        //if prime then set entries of multiples of i stating form i*i to false
        if(primes[i])
        {
            for(int j = i * i; j <= n; j += i)
            {
                primes[j] = false;
            }
        }
    }
}

int main()
{
    int n;
    cout << "Enter number: ";
    cin >> n;
    bool primes[n + 1];
    sieve(n, primes);
    for(int i = 2; i <= n; i++) if(primes[i]) cout << i << ' ';
}
