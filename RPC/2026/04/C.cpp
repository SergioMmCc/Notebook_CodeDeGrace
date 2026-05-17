#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define sz(a) ((int)a.size())
#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define pqueue priority_queue
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<pii> vii;
// #include<ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// using indexed_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

void solver(){
    string a, b; 
    string c, d;
    cin >> a >> c;
    cin >> b >> d;
    a += ' ';
    a += c;
    b += ' ';
    b += d;
    if(a == b){
        cout << "7 days" << endl;
        return;
    } 
    int mod = 10080;
    int day = 1440;
    int hour = 60;
    int am = 0;
    int bm = mod;
    map<string, int> mp = {{"Mon", 0}, {"Tue", 1}, {"Wed", 2}, {"Thu", 3}, {"Fri", 4}, {"Sat", 5}, {"Sun", 6}};
    string daya = "";
    daya += a[0];
    daya += a[1];
    daya += a[2];
    string dayb = "";
    dayb += b[0];
    dayb += b[1];
    dayb += b[2];
    am += day * mp[daya];
    bm += day * mp[dayb];
    string houra = "";
    houra += a[4];
    houra += a[5];
    string hourb = "";
    hourb += b[4];
    hourb += b[5];
    am += stoi(houra) * 60;
    bm += stoi(hourb) * 60;
    string mina = "";
    mina += a[7];
    mina += a[8];
    string minb = "";
    minb += b[7];
    minb += b[8];
    am += stoi(mina);
    bm += stoi(minb);
    int totm = (bm - am) % mod;
    int days = 0, hours = 0, minutes = 0;
    days = totm / day;
    totm %= day;
    hours = totm / 60;
    totm %= 60;
    minutes = totm;
    if(days > 0){
        if(days == 1){
            cout << "1 day";
        }else{
            cout << days << " days";
        }
        if(hours > 0 && minutes > 0){
            cout << ", " << hours << " hour";
            if(hours > 1){
                cout << "s";
            }
            cout << ", " << minutes << " minute";
            if(minutes > 1){
                cout << "s";
            }
            cout << endl;
        }else{
            if(minutes > 0){
                cout << " and ";
                cout << minutes << " minute";
                if(minutes > 1){
                    cout << "s";
                }
                cout << endl;
            }else if(hours > 0){
                cout << " and ";
                cout << hours << " hour";
                if(hours > 1){
                    cout << "s";
                }
                cout << endl;
            }else{
                cout << endl;
            }
        }
    }else{

        if(hours > 0 && minutes > 0){
            cout << hours << " hour";
            if(hours > 1){
                cout << "s";
            }
            cout << " and " << minutes << " minute";
            if(minutes > 1){
                cout << "s";
            }
            cout << endl;
        }else{
            if(minutes > 0){
                cout << minutes << " minute";
                if(minutes > 1){
                    cout << "s";
                }
                cout << endl;
            }else if(hours > 0){
                cout << hours << " hour";
                if(hours > 1){
                    cout << "s";
                }
                cout << endl;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("name.in", "r", stdin);
	// freopen("name.out", "w", stdout);
    int t = 1;
    // cin>>t;
    while(t--){
        solver();
    }

    return 0;
}