#include <bits/stdc++.h>
using namespace std;

int binarySearch (const vector<int>& A, int i, int j, int k) {
    int m;
    while(i <= j) {
        m = i+j >> 1;
        if(A[m] == k)
            return m;
        if(A[m] > k)
            j = m - 1;
        else
            i = m + 1;   
    }
    return -i -1;
}

int solver(const vector<int>& a, const vector<int>& b) {
    int ans = 0, aux, boxes = 0;
    set<int> coincidences;
    for(int i = 1, j = 1; i < a.size() && j < b.size();) {
        if(a[i] == b[j]) {
            coincidences.insert(a[i]);
            i++;
            j++;
        }
        else if(a[i] > b[j])
            j++;
        else
            i++;
    }

    for(int i = 1, j = 1; j < b.size(); j++) {
        set<int>::iterator it = coincidences.find(b[j]);
        if(it != coincidences.end())
            coincidences.erase(it);
        
        while(i < a.size() && a[i] <= b[j]) {
            boxes++;
            i++;
        }
        if(boxes == 0) {
            aux = coincidences.size();
            ans = max(ans, aux);   
        }
        else {
            int cubren = binarySearch(b, 1, b.size()-1, b[j]-boxes+1);
            if(cubren < 0) 
                cubren = -cubren -1;
            
            aux = j - cubren + coincidences.size() + 1;
            ans = max(ans, aux);
        }
    }

    return ans;
}

int main () {
    int t; cin >> t;
    int n, m, save, result;
    while(t--) {
        vector<int> ar(1,0), al(1,0), br(1,0), bl(1,0);
        cin >> n >> m;
        for(int i = 0; i < n; i++) {
            cin >> save;
            if(save < 0)al.push_back(-save);
            else ar.push_back(save);
        }
        for(int i = 0; i < m; i++) {
            cin >> save;
            if(save < 0)bl.push_back(-save);
            else br.push_back(save);
        }
        sort(al.begin(), al.end());
        sort(bl.begin(), bl.end());
        
        result = solver(al, bl) + solver(ar, br);
    
        cout << result << "\n";
    }

    return 0;
}