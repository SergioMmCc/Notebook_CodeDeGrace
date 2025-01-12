#include<bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
vector<int> adj(maxn);

// Source: https://usaco.guide/CPH.pdf#page=166

int floyd(int x){
    int a = adj[x];
    int b = adj[adj[x]];

    // At this point, the pointer a has walked k steps and the pointer b has walked
    // 2k steps, so the length of the cycle divides k
    while(a != b){
        a = adj[a];
        b = adj[adj[b]];
    }

    // the first node that belongs to the cycle can be found by 
    // moving the pointer a to node x and advancing the pointers 
    // step by step until they meet again
    a = x;
    while(a != b){
        a = adj[a];
        b = adj[b];
    }
    int firstCycleNode = a;

    // After this, the length of the cycle can be calculated as follows:
    b = adj[b];
    int length = 1;
    while(a != b){
        b = adj[b];
        length++;
    }

    return length;
}