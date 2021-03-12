#include "iostream"
#include "stack"
using namespace std;
string a[11] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
stack<int> s;
int main()
{
    char c;
    int sum = 0;
    while (cin >> c)
        sum += c - '0';
    if (sum)
    {
        while (sum)
        {
            s.push(sum % 10);
            sum /= 10;
        }
        cout << a[s.top()];
        s.pop();
        while (!s.empty())
        {
            cout << " " << a[s.top()];
            s.pop();
        }
    }
    else
        cout << "zero";
}
