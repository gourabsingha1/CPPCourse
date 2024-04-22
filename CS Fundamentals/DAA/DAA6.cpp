#include <iostream>
using namespace std;

// **** String Matching ****

void naiveStringMatch(string text, string pattern) {
    int n = text.size(), m = pattern.size();
    for (int i = 0; i < n - m; i++)
    {
        bool found = 1;
        for (int j = 0; j < m; j++)
        {
            if(text[i + j] != pattern[j]) {
                found = 0;
                break;
            }
        }
        if(found) {
            cout<<"Pattern found at index "<<i<<endl;
        }
    }
    cout<<endl;
}

// **** GCD ****

int gcd(int a, int b) {
    if(b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    string text = "AABAACAADAABAAABAA", pattern = "AABA";
    naiveStringMatch(text, pattern);

    int a, b;
    cout<<"Enter two numbers: ";
    cin>>a>>b;
    cout<<"GCD of "<<a<<" and "<<b<<" is = "<<gcd(a, b)<<endl;
    return 0;
}