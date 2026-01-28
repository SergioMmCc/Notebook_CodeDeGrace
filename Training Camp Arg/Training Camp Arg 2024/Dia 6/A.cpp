#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

typedef pair<string, int> psi;
vector<psi> language(1);

int binarySearch(vector<psi>& A, int i, int j, string r) {
    while(i <= j) {
        int m = (i + j) / 2;
        if(A[m].first == r)
            return m;
        else if(A[m].first < r) 
            i = m+1;
        else
            j = m-1;
    }
    
    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    string search;
    int n, k, m; cin >> n >> k >> m;
    for(int i = 1; i <= n; i++) {
        cin >> search;
        language.push_back({search, 0});
    }
    for(int i = 1; i <= n; i++) 
        cin >> language[i].second;

    int number, same, minimum;
    for(int i = 0; i < k; i++) {
        cin >> number;
        vector<int> change;
        minimum = 2e9;
        for(int j = 0; j < number; j++) {
            cin >> same;
            if(language[same].second < minimum)
                minimum = language[same].second;
            change.push_back(same);
        }
        for(int i : change) 
            language[i].second = minimum;
    }
    sort(language.begin()+1, language.end());
    long long result = 0;

    for(int i = 1; i <= m; i++) {
        cin >> search;
        int where = binarySearch(language, 1, n, search);
        result += language[where].second;
    }

    cout << result << endl;

    return 0;
}

typedef pair<string, int> psi;
vector<psi> language(1);

int binarySearch(vector<psi>& A, int i, int j, string r) {
    while(i <= j) {
        int m = (i + j) / 2;
        if(A[m].first == r)
            return m;
        else if(A[m].first < r) 
            i = m+1;
        else
            j = m-1;
    }
    
    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    string search;
    int n, k, m; cin >> n >> k >> m;
    for(int i = 1; i <= n; i++) {
        cin >> search;
        language.push_back({search, 0});
    }
    for(int i = 1; i <= n; i++) 
        cin >> language[i].second;

    int number, same, minimum;
    for(int i = 0; i < k; i++) {
        cin >> number;
        vector<int> change;
        minimum = 2e9;
        for(int j = 0; j < number; j++) {
            cin >> same;
            if(language[same].second < minimum)
                minimum = language[same].second;
            change.push_back(same);
        }
        for(int i : change) 
            language[i].second = minimum;
    }
    sort(language.begin()+1, language.end());
    long long result = 0;

    for(int i = 1; i <= m; i++) {
        cin >> search;
        int where = binarySearch(language, 1, n, search);
        result += language[where].second;
    }

    cout << result << endl;

    return 0;
}