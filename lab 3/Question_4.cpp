#include <bits/stdc++.h>
using namespace std;

/*
    parameter:
    a: int
    b: int
    s: *int
    t: *int
    recursive functions, on the last return, s and t point to bezout coefficients
*/
void eGCD(int a, int b, int *s, int *t)
{
    //the s and t used in each step in the backward substitution
    int si, ti;
    //the base case
    if(a % b == 0) {
        *s = 0;
        *t = 1;
        return;
    }
    //passing pointers to the current s and t
    eGCD(b, a % b, &si, &ti);
    //back substitution step after modifying values of s and t from previous steps
    *s = ti;
    *t = si - a / b * ti;
}

void solveCongrunce(int n, int m[], int M[], int a[])
{
    int Mtotal = 1, ans = 0;
    //calculating M total
    for(int i = 0; i < n; i++) Mtotal *= m[i];
    for(int i = 0; i < n; i++) M[i] = Mtotal / m[i];
    for(int i = 0; i < n; i++)
    {
        int s, t; 
        //using extended GCD to calculate the inverses
        eGCD(M[i], m[i], &s, &t);
        //adding on the final answer after each calculation of inverse
        ans += a[i] * M[i] * s;
    }
    cout << endl;
    cout << "the solution is: " << ans % Mtotal << " mod " << Mtotal << endl;
}

int main()
{
    int n;
    cout << "Enter the number of equations: ";
    cin >> n;
    //initializing arrays used in equations
    int m[n], M[n], a[n];
    cout << "Enter the the a's with space separated: ";
    for(int i = 0; i < n; i++) cin >> a[i];
    cout << "Enter the the m's with space separated: ";
    for(int i = 0; i < n; i++) cin >> m[i];
    solveCongrunce(n, m, M, a);
}
