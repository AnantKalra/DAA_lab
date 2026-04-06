#include <iostream>
using namespace std;

void coinchange(int amount) {
    int coins[] = {2000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
    int n = sizeof(coins) / sizeof(coins[0]);

    cout << "Coins used:\n";

    for (int i = 0; i < n; i++) {
        if (amount >= coins[i]) {
            int count = amount / coins[i];
            amount = amount % coins[i];

            cout << coins[i] << " x " << count << endl;
        }
    }
}

int main() {
    int amount;
    cout << "Enter amount: ";
    cin >> amount;

    coinchange(amount);  // function call
    
    return 0;
}