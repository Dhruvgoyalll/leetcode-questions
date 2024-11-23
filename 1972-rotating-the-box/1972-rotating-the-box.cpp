class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n = box.size();
        int m = box[0].size();
        // Resulting vector after rotation
        vector<vector<char>> nums(m, vector<char>(n, '.'));
        for (int i = 0; i < n; i++) {
            int empty = m - 1; // Start from the end of the row
            for (int j = m - 1; j >= 0; j--) {
                if (box[i][j] == '*') {
                    empty = j - 1; // Update empty to just before the obstacle
                } else if (box[i][j] == '#') {
                    // Swap the stone to the 'empty' position
                    swap(box[i][j], box[i][empty]);
                    empty--; // Move the empty position backward
                }
            }
            // Insert the processed row into the rotated matrix
            for (int j = 0; j < m; j++) {
                nums[j][n - i - 1] = box[i][j];
            }
        }
        return nums;
    }
};