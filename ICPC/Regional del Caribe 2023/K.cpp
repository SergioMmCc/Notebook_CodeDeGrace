#include <bits/stdc++.h>
using namespace std;

int main()
{
    unsigned long long min, max, a, b, root, sum, i;
    int flag1 = 0, flag2 = 0;
    cin >> a >> b;
    
    min = a;
    while (min <= b) {
        sum = 0;
        
        root = sqrt(min);
        if (root * root == min)
            sum += root;
        else
            root++;
            
        for (i = 2; i < root; i++) {
            if (min % i == 0) 
                sum += i + min/i;
            if (sum > min) {
                flag1 = 1;
                break;
            }
        }
        if (flag1 == 1)
            break;
        
        min++;
    }
    
    max = b;
    while (max >= a) {
        sum = 0;
        root = sqrt(max);
        if (root * root == max)
            sum += root;
        else 
            root++;
        
        for (i = 2; i < root; i++) {
            if (max % i == 0)
                sum += i + max/i;
            if (sum > max) {
                flag2 = 1;
                break;
            }
        }
        if (flag2 == 1)
            break;
        max--;
    }
    if (flag1 == 0 && flag2 == 0)
        cout << "-1 -1\n";
    else
        cout << min << " " << max << "\n";

    return 0;
}
