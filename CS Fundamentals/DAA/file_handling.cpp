#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    fstream file;
    file.open("example.txt");

    // Writing to file
    int n = 100;
    for (int i = 0; i < n; i++)
    {
        file << rand() % 100 <<' ';
    }

    // Reading from file
    // for (int i = 0; i < n; i++)
    // {
    //     int x;
    //     file>>x;
    //     cout<<x<<' ';
    // }

    return 0;
}