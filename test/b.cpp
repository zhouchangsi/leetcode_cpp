#include <bits/stdc++.h>
using namespace std;  

int main(){
    int k = 42, n = 2, m = 4;

    int count = 0;
    while(k > 0) {
        if(k % m == n) count++;
        k /= m;
    }

    cout << count << endl;
}

// 42 = 2*4^2 + 2*4 + 2
// 42变成4进制是222
