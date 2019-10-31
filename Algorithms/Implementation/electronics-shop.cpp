// Problem : Algorithms/Implementation - Electronics Shop 
// Author - Pranav Shridhar

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int b, n, m, i, j;
    int price;
    int tot;
    int maxBuy = INT32_MIN;

    std::vector<int> keyboards;
    std::vector<int> usbs;

    cin >> b >> n >> m;

    for (i = 0; i < n; i++) {
        cin >> price;
        keyboards.push_back(price);
    }
    for (i = 0; i < m; i++) {
        cin >> price;
        usbs.push_back(price);
    }

    sort(keyboards.begin(), keyboards.end(), greater<int>());
    sort(usbs.begin(), usbs.end());

    if (*min_element(keyboards.begin(), keyboards.end()) + 
        *min_element(usbs.begin(), usbs.end()) > b) {
        cout << -1;
        return 0;
    }

    for (i = 0, j = 0; i < n; i++) {
        if (keyboards[i] > b) 
            continue;
        for (; j < m; j++) {
            tot = keyboards[i] + usbs[j];
            if (tot <= b) {
                if (tot > maxBuy)
                    maxBuy = tot;
            }
            else 
                break;
        }
    }

    cout << maxBuy;

    return 0;
}
