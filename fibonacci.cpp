#include <iostream>
using namespace std;

int main() 
{
    int term1 = 0, term2 = 1, nextTerm = 0, n;

    cout << "Enter a positive number: ";
    cin >> n;

    cout << "Fibonacci Series: " << term1 << ", " << term2 << ", ";

    nextTerm = term1 + term2;

    while(nextTerm <= n) {
        cout << nextTerm << ", ";
        term1 = term2;
        term2 = nextTerm;
        nextTerm = term1 + term2;
    }
    return 0;
}