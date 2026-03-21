#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main() {
    string s;cin >> s;
    int first = 0, last = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '1') {
            first = i;
            break;
        }
    }
    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] == '1') {
            last = i;
            break;
        }
    }

    long long val = 32;
    int cont = 1;
    long long ans = last - first + 1;
    while (ans > val) {
        val *= 2;
        cont++;
    }
	
	cout<<"long";
    for (int i = 1; i < cont; i++)
        cout<<" long";
	cout<<endl;
}