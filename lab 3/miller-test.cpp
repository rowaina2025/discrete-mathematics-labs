#include <bits/stdc++.h>
using namespace std;

void sieve(int n, bool primes[]) {
    for(int i = 1; i <= n; i++) primes[i] = true;
    for(int i = 2; i <= sqrt(n); i++) {
        if(primes[i]) {
            for(int j = i * i; j <= n; j += i) {
                primes[j] = false;
            }
        }
    }
}

void trialDivisionFactorization(int n, bool primes[], vector<int>& factors)
{
    sieve(n, primes);
    for(int i = 2; i <= n; i++) {
        if(primes[i] && n % i == 0) {
            n /= i;
            factors.push_back(i--);
        }
    }
}

int main() {
    int n;
    cout << "Enter number: ";
    cin >> n;
    bool primes[n + 1];
    vector<int> factors;
    trialDivisionFactorization(n, primes, factors);
    for(int i = 0; i < factors.size(); i++) cout << factors[i] << ' ';
}
