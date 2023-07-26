class Solution {
public:
    int solve(vector<int>& nums, int n, vector<int>& dp) {
        if (n == 0) return 0;

        if (dp[n+1] != -1) return dp[n+1];

        int i = n;
        int sum = 0;
        int nottake = solve(nums, n - 1, dp);
        while (i - 1 >= 0 && nums[i - 1] == nums[n - 1]) {
            sum += nums[i - 1];
            i--;
        }
        while (i - 1 >= 0 && nums[i - 1] == nums[n - 1] - 1) {
            i--;
        }
        int take = sum + solve(nums, i, dp);

        return dp[n+1] = max(take, nottake);
    }

    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> dp(n + 2, -1);
        return solve(nums, n, dp);
    }
};