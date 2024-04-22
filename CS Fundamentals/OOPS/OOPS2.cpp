#include <iostream>
using namespace std;

int countVowels() {
    int res = 0;
    char s[1000];
    gets(s);
    char *ptr = s;
    for (int i = 0; s[i] != '\0'; i++)
    {
        char c = *(ptr + i);
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'){
            res++;
        }
    }
    return res;
}

int noOfChars(string s) {
    int res = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        res++;
    }
    return res;
}

int countSum() {
    int res = 0, n;
    cout<<"Enter n\n";
    cin>>n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    int *ptr = a; cout<<"Sum: ";
    for (int i = 0; i < n; i++)
    {
        res += (*ptr + i);
    }
    return res;
}

int main() {
    cout<<countSum()<<endl;
    cout<<noOfChars("gojsiog");
}