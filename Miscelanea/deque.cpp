#include<bits/stdc++.h>
using namespace std;

/* Metodos deque */

int main(){
    deque<int> dq;
    dq.push_front(1);
    dq.push_back(10);
    deque<int>::iterator it = dq.begin();
    it++;
    dq.insert(it, 5); // O(n)
    it = dq.end();

    int n = dq.front(); //1
    int m = dq.back(); //10
    int x = dq.at(1); //5

    dq.pop_front();
    dq.pop_back();
    it = dq.begin();
    dq.erase(it); // O(n)

    int len = dq.size();

    dq.clear();

    return 0;
}