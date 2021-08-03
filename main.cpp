#include <iostream>
#include <ctime>

using namespace std;
typedef long long int ll;

ll iterative(ll n) {
    ll f[3] = {0, 1, 1};
    if (n < 2)
        return f[n];
    else
        for (int i = 2; i < n; i++) {
            f[0] = f[1];
            f[1] = f[2];
            f[2] = f[0] + f[1];
        }
    return f[2];
}

ll recursive(ll n) {
    if (n < 3)
        return 1;
    return recursive(n - 1) + recursive(n - 2);
}

int main() {

    ll n;
    cout << "Enter the number n:";
    cin >> n;

    // iterative solution
    auto t1 = clock();

    cout << iterative(n) << endl;
    auto t2 = clock();
    cout << "Time of iterative solution: " << t2 - t1 << " nanoseconds." << endl;

    //recursive solution
    t1 = clock();
    cout << recursive(n) << endl;
    t2 = clock();
    cout << "Time of recursive solution: " << t2 - t1 << " nanoseconds." << endl;
    return 0;
}
