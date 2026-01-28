#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    long double p1x, p1y, p2x, p2y, p3x, p3y, p4x, p4y;cin >> p1x >> p1y >> p2x >> p2y >> p3x >> p3y >> p4x >> p4y;
    
    tuple<long double, long double> A = make_tuple(p1x - p2x, p1y - p2y);
    long double magnitudA = sqrt(get<0>(A)*get<0>(A) + get<1>(A)*get<1>(A));

    tuple<long double, long double> B = make_tuple(p2x - p3x, p2y - p3y);
    long double magnitudB = sqrt(get<0>(B)*get<0>(B) + get<1>(B)*get<1>(B));

    tuple<long double, long double> C = make_tuple(p3x - p4x, p3y - p4y);
    long double magnitudC = sqrt(get<0>(C)*get<0>(C) + get<1>(C)*get<1>(C));

    tuple<long double, long double> D = make_tuple(p4x - p1x, p4y - p1y);
    long double magnitudD = sqrt(get<0>(D)*get<0>(D) + get<1>(D)*get<1>(D));

    tuple<long double, long double> E = make_tuple(p1x - p3x, p1y - p3y);
    long double magnitudE = sqrt(get<0>(E)*get<0>(E) + get<1>(E)*get<1>(E));

    tuple<long double, long double> F = make_tuple(p2x - p4x, p2y - p4y); 
    long double magnitudF = sqrt(get<0>(F)*get<0>(F) + get<1>(F)*get<1>(F));

    if(magnitudA == 0 || magnitudB == 0 || magnitudC == 0 || magnitudD == 0){
        cout << "none\n";
        return 0;
    }
    if(magnitudA == magnitudB && magnitudB == magnitudC && magnitudC == magnitudD){
        if(magnitudE == magnitudF){
            cout << "square\n";
            return 0;
        }
        cout << "rhombus\n";
        return 0;
    }
    if(magnitudA == magnitudC && magnitudB == magnitudD){
        if(magnitudE == magnitudF){
            cout << "rectangle\n";
            return 0;
        }
        cout << "parallelogram\n";
        return 0;
    }
    if((magnitudA == magnitudB && magnitudC == magnitudD) || (magnitudA == magnitudD && magnitudC == magnitudB)){
        cout << "kite\n";
        return 0;
    }
    if((get<0>(A)*get<1>(C) - get<1>(A)*get<0>(C) == 0) || (get<0>(B)*get<1>(D) - get<1>(B)*get<0>(D) == 0)){
        cout << "trapezium\n";
        return 0;
    }
    cout << "none\n";
    return 0;
}