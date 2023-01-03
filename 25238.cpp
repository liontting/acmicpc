#include <iostream>
using namespace std;
float a, b, answer;

int main() {
    cin >> a >> b;
    answer = a - a * b / 100;
    if (answer >= 100)
        cout << "0";
    else
        cout << "1";
    return 0;
}
