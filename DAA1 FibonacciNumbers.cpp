#include <iostream>
using namespace std;

int fib(int n) {
    int count = 2;
    int first = 0, second = 1, next = 0;

    cout << "Fibonacci Series: ";
    cout << first << " " << second << " ";

    while (next <= n) {
        next = first + second;
        if (next > n) break;
        cout << next << " ";
        first = second;
        second = next;
        count++;
    }
    cout << endl;

    return count - 1;
}

int main() {
    int n;
    cout << "Enter the number: ";
    cin >> n;
    cout << "Count: " << fib(n) << endl;
    return 0;
}
