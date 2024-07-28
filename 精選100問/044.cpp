#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

int main() {
    vector<int> dp_all(1000001, INF);
    vector<int> dp_odd(1000001, INF);
    
    // init_dp
    dp_all[0] = 0;
    dp_odd[0] = 0;

    // init_num2sq
    // all
    vector<int> num2sq_all;
    for (int n = 1; n <= 200; ++n) {
        num2sq_all.push_back((n * (n + 1) * (n + 2)) / 6);
    }
    // odd
    vector<int> num2sq_odd;
    for (int n = 1; n <= 200; ++n) {
        int tmp_squ = (n * (n + 1) * (n + 2)) / 6;
        if (tmp_squ % 2 == 1) {
            num2sq_odd.push_back(tmp_squ);
        }
    }

    // execute dp
    // all
    for (int num : num2sq_all) {
        for (int tmp_sum = num; tmp_sum < 1000001; tmp_sum++) {
            dp_all[tmp_sum] = min(dp_all[tmp_sum], dp_all[tmp_sum - num] + 1);
        }
    }
    // odd
    for (int num : num2sq_odd) {
        for (int tmp_sum = num; tmp_sum < 1000001; tmp_sum++) {
            dp_odd[tmp_sum] = min(dp_odd[tmp_sum], dp_odd[tmp_sum - num] + 1);
        }
    }

    vector<pair<int, int>> reses;
    while (true) {
        int N;
        cin >> N;
        if (N == 0) break;

        int tmp_res_all = dp_all[N];
        int tmp_res_odd = dp_odd[N];

        reses.push_back({tmp_res_all, tmp_res_odd});
    }

    for (const auto& res : reses) {
        cout << res.first << " " << res.second << endl;
    }

    return 0;
}
