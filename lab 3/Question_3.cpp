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
    if(a % b == 0)
    {
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

int main()
{
    //s, t are the bezouts coefficients
    int a, b, s, t;
    cout << "Enter a & b with space separated: ";
    cin >> a >> b;
    eGCD(a, b, &s, &t);   //passing pointer to the s and t to change their value
    cout << s << " " << t << endl;
}
