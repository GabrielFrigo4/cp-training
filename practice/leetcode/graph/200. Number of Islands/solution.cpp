class Solution {
public:
    array<int, 4> dx = {1, 0, -1, 0};
    array<int, 4> dy = {0, -1, 0, 1};

    void dfs(vector<vector<char>>& grid, int x, int y) {
        if (x < 0 || y < 0 || x >= grid[0].size() || y >= grid.size()) {
            return;
        }
        if (grid[y][x] == '0') {
            return;
        }

        grid[y][x] = '0';
        for (int i = 0; i < 4; i++) {
            dfs(grid, x + dx[i], y + dy[i]);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for (int y = 0; y < grid.size(); y++) {
            for (int x = 0; x < grid[0].size(); x++) {
                if (grid[y][x] == '0') {
                    continue;
                }
                count++;
                dfs(grid, x, y);
            }
        }
        return count;
    }
};
