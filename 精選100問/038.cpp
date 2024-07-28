#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int q;
    cin >> q;
    vector<pair<string, string>> queries;
    vector<int> results;

    // 入力を読み取る
    for (int i = 0; i < q; ++i) {
        string X, Y;
        cin >> X >> Y;
        queries.push_back(make_pair(X, Y));
    }

    // 各クエリに対してLCSを計算
    for (const auto& query : queries) {
        string X = query.first;
        string Y = query.second;
        int lenX = X.length();
        int lenY = Y.length();
        vector<vector<int>> dp(lenY + 1, vector<int>(lenX + 1, 0));

        for (int i = 1; i <= lenY; ++i) {
            for (int j = 1; j <= lenX; ++j) {
                if (Y[i - 1] == X[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        results.push_back(dp[lenY][lenX]);
    }

    // 結果を出力
    for (const int result : results) {
        cout << result << endl;
    }

    return 0;
}
