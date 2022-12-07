#include<bits/stdc++.h>

using namespace std;

string elements[10000000];
int n;

int getBit(int number, int position) {
    int comp = pow(2, position);
    int res = number & comp;
    return res == 0 ? 0 : 1;
}

void formPowerSet() {
    cout << '\n';
    for(int i = 1; i < pow(2, n); i++) {
        for(int j = log2(i); j >= 0; j--) {
            if(getBit(i, j) == 1 )
                cout << elements[j] << ' ';
        }
        cout << '\n';
    }
}

int main() {
    cout << "Enter number of elements in set: ";
    cin >> n;
    cout << "Enter set elements: ";
    for(int i = 0; i < n; i++) {
        cin >> elements[i];
    }
    formPowerSet();
}
////////////////////////////////////////////////////////////////////////////
#include <bits/stdc++.h>
using namespace std;

vector<string> res;

void subset(string s[], int n, int cnt) {
    if(cnt == n) {
        for(int i = 0; i < res.size(); i++) cout << res[i] << " ";
        cout << "\n";
        return;
    }
    res.push_back(s[cnt]);
    subset(s, n, cnt + 1);
    res.pop_back();
    subset(s, n, cnt + 1);
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    string s[n];
    cout << "Insert the elements with space separated: ";
    for(int i = 0; i < n; i++) cin >> s[i];
    subset(s, n, 0);
}
