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
    for(int i = 1; i <= n; i++) primes[i] = true;
    for(int i = 2; i <= sqrt(n); i++) 
    {
        //if prime then set entries of multiples of i starting form i*i to false
        if(primes[i]) 
        {
            for(int j = i * i; j <= n; j += i) 
            {
                primes[j] = false;
            }
        }
    }
}

/*
    parameter:
    n: int
    primes[]: bool
    factors: vector<int>
    void function forms vector containing prime factors of number n
*/
void trialDivisionFactorization(int n, bool primes[], vector<int>& factors)
{
    //form all numbers less than or equals to n
    sieve(n, primes);
    for(int i = 2; i <= n; i++)
    {
        //tests if i is prime and is a factor of n
        if(primes[i] && n % i == 0)
        {
            n /= i;
            factors.push_back(i--);
        }
    }
}

int main()
{
    int n;
    cout << "Enter number: ";
    cin >> n;
    bool primes[n + 1];
    vector<int> factors;
    trialDivisionFactorization(n, primes, factors);
    for(int i = 0; i < factors.size(); i++) cout << factors[i] << ' ';
}
