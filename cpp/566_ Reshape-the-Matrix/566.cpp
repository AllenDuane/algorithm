class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int row = nums.size(), col = nums[0].size();
        if (row * col != r * c)
            return nums;
        vector<vector<int>> res(r, vector<int>(c));
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                int to1dim = i * col + j,
                    newI = to1dim / c,
                    newJ = to1dim % c;
                res[newI][newJ] = nums[i][j];
            }
        }
        return res;
    }

    void printMatrix(vector<vector<int>> nums) {
        for (auto p : nums) {
            for (auto q : p)
                cout << q << " ";
            cout << endl;
        }
    }
};
