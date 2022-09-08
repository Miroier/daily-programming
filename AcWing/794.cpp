#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// A / b，商C，余数r
vector<int> div(vector<int> &A, int b, int &r)
{
    vector<int> C;
    r = 0;
    for (int i = A.size() - 1; i >= 0; i--)
    {
        r = r * 10 + A[i];
        C.push_back(r / b);
        r %= b;
    }

    //现在C[0]存的是最高位，需要逆序一下
    reverse(C.begin(), C.end());

    while (C.size() > 1 && C.back() == 0)
        C.pop_back();

    return C;
}

int main()
{
#ifdef ONLINE_JUDGE
#else
    freopen("input.txt", "r", stdin);
#endif
    string a;
    int b;

    cin >> a >> b;

    vector<int> A;
    for (int i = a.size() - 1; i >= 0; i--)
        A.push_back(a[i] - '0');

    int r; // 余数
    auto C = div(A, b, r);

    for (int i = C.size() - 1; i >= 0; i--)
        cout << C[i];
    cout << endl
         << r;
}
