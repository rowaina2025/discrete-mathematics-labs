#include <bits/stdc++.h>
using namespace std;

int getBit(int number, int position) {
    int comp = pow(2, position);
    int res = number & comp;
    return res == 0 ? 0 : 1;
}

int setBit(int number, int position) {
    int comp = pow(2, position);
    int res = number | comp;
    return res;
}

int clearBit(int number, int position) {
    int comp = pow(2, position);
    comp = ~comp;
    int res = number & comp;
    return res;
}

int updateBit(int number, int position, bool value) {
    int res;
    if(value) res = setBit(number, position);
    else res = clearBit(number, position);
    return res;
}

void part1() {
    int op;
    cout << "--Enter the number of operation below\n\n";
    cout << "1. Get bit\n";
    cout << "2. Set bit\n";
    cout << "3. Clear bit\n";
    cout << "4. Update bit\n";
    cout << "\nYour choice: ";
    cin >> op;
    cout << "\n";
    switch(op) {
        case 1 : {
            int num, pos;
            cout << "Enter the number: ";
            cin >> num;
            cout << "Enter the position: ";
            cin >> pos;
            int bit = getBit(num, pos);
            cout << "\nThe value of the bit at the position is: " << bit;
            break;
        }
        case 2 : {
            int num, pos;
            cout << "Enter the number: ";
            cin >> num;
            cout << "Enter the position: ";
            cin >> pos;
            int res = setBit(num, pos);
            cout << "\nThe number after modification is: " << res;
            break;
        }
        case 3 : {
            int num, pos;
            cout << "Enter the number: ";
            cin >> num;
            cout << "Enter the position: ";
            cin >> pos;
            int res = clearBit(num, pos);
            cout << "\nThe number after modification is: " << res;
            break;
        }
        case 4 : {
            int num, pos, newBit;
            cout << "Enter the number: ";
            cin >> num;
            cout << "Enter the position: ";
            cin >> pos;
            cout << "Enter the value of the new bit: ";
            cin >> newBit;
            int res = updateBit(num, pos, newBit);
            cout << "\nThe number after modification is: " << res;
            break;
        }
        default : {
            cout << "Invalid Input!";
            break;
        }
    }
}

void part2() {
    cout << "--Enter the number of universe set elements: ";
    int num, sz;
    cin >> num;
    cout << "--Enter the universe set: ";
    string str;
    map<string, int> mp;
    vector<string> uni;
    for(int i = 0; i < num; i++) {
        cin >> str;
        uni.push_back(str);
        mp[str] = i;
    }
    cout << "\n--Enter the number of subsets: ";
    cin >> num;
    int sub[num] = {0};
    for(int i = 1; i <= num; i++) {
        cout << "\nSet #" << i << " size: ";
        cin >> sz;
        cout << "Enter the set: ";
        for(int j = 0; j < sz; j++) {
            cin >> str;
            sub[i - 1] = setBit(sub[i - 1], mp[str]);
        }
    }
    cout << "\n--Choose an operation..\n";
    cout << "--U: union      I: intersection      C: complement      Q: quit\n";
    cout << "--Enter operation type in one line followed by the number of the operand/s\n";
    while(true) {
        cin >> str;
        if(str == "U") {
            int st1, st2;
            cin >> st1 >> st2;
            int sub1 = sub[st1 - 1], sub2 = sub[st2 - 1];
            int comp = sub1 | sub2;
            for(int i = 0; i < uni.size(); i++) if(getBit(comp, i) == 1) cout << uni[i] << ' ';
            cout << "\n";
        }
        else if(str == "I") {
            int st1, st2;
            cin >> st1 >> st2;
            int sub1 = sub[st1 - 1], sub2 = sub[st2 - 1];
            int comp = sub1 & sub2;
            for(int i = 0; i < uni.size(); i++) if(getBit(comp, i) == 1) cout << uni[i] << ' ';
            cout << "\n";
        }
        else if(str =="C") {
            int st;
            cin >> st;
            int sub1 = sub[st - 1];
            int comp = ~sub1;
            for(int i = 0; i < uni.size(); i++) if(getBit(comp, i) == 1) cout << uni[i] << ' ';
            cout << "\n";
        }
        else if(str == "Q") {
            break;
        }
        else {
            cout << "Invalid Input!";
            break;
        }
    }
}

void part3() {
    cout << "Choose part to be executed\n\n";
    cout << "1. Enter 1 for Part a.\n";
    cout << "2. Enter 2 for part b.\n";
    cout << "\nYour choice: ";
    int op;
    cin >> op;
    cout << "\n";
    if(op == 1) {
        int n, x, res = 0;
        cout << "Enter number of array elements: ";
        cin >> n;
        cout << "Enter elements of array separated by space: ";
        for(int i = 0; i < n; i++) {
            cin >> x;
            res ^= x;
        }
        cout << "\nThe element occurring odd number of times is: " << res;
    }
    else if(op == 2) {
        unsigned int num, counter = 0;
        cout << "Enter the number: ";
        cin >> num;
        while(num > 0) {
            if(getBit(num, 0) == 1) counter++;
            num /= 2;
        }
        cout << "\nThe number of '1' bits is: " << counter;
    }
}

int main() {
    int op;
    cout << "Please choose one part\n\n";
    cout << "1. Part one\n";
    cout << "2. Part two\n";
    cout << "3. Part three\n";
    cout << "\nYour choice: ";
    cin >> op;
    cout << "\n\n";
    if(op == 1) part1();
    else if(op == 2) part2();
    else if(op == 3) part3();
    cout << "\n\n";
}
