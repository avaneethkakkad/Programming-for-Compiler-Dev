class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp = triangle[n-1];
        vector<vector<int>> pathIdx(n-1, vector<int>(n-1, 0)); // To store choices

        // Fill dp and record choices
        for (int i = n - 2; i >= 0; --i) {
            for (int j = 0; j < triangle[i].size(); ++j) {
                if (dp[j] < dp[j+1]) {
                    dp[j] = triangle[i][j] + dp[j];
                    pathIdx[i][j] = j; // Go straight down
                } else {
                    dp[j] = triangle[i][j] + dp[j+1];
                    pathIdx[i][j] = j+1; // Go down-right
                }
            }
        }

        // Reconstruct the path
        vector<int> path;
        int idx = 0;
        path.push_back(triangle[0][0]);
        for (int i = 0; i < n-1; ++i) {
            idx = pathIdx[i][idx];
            path.push_back(triangle[i+1][idx]);
        }

        // Print the path (optional)
        // for (int num : path) cout << num << " ";
        // cout << endl;

        return dp[0]; // Minimum path sum
    }
};
