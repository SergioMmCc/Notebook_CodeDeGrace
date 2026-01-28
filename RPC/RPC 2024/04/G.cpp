#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int n, q;cin >> n >> q;
    string name; long long salary;

    map<string, long long> empleados;
    map<long long, set<string>> rep;

    int op;
    long long add;

    while (n--) {
        cin >> name >> salary;
        empleados[name] = salary;
        rep[salary].insert(name);
    }

    while (q--) {
        cin >> op;
        if (op == 2) {
            map<long long, set<string>>:: iterator i = rep.end();
            i--;
            salary = i->first;
            set<string>& punt = i->second;
            set<string>::iterator j = punt.begin();
            string change = *j;
            punt.erase(j);
            if(punt.empty())rep.erase(i);
            
            cout << change << " " << salary << "\n";
        }

        else {
            cin >> name >> add;

            salary = empleados[name];
            rep[salary].erase(name);
            if (rep[salary].empty())rep.erase(salary);

            empleados[name] += add;
            rep[salary + add].insert(name);
        }
    }

    return 0;
}