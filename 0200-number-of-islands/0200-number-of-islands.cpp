class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int islands = 0;

        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};
        vector<pair<int, int>> st;

        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (grid[r][c] != '1')
                    continue;
                
                ++islands;
                grid[r][c] = '0';
                st.push_back({r, c});

                while (!st.empty()) {
                    auto [x, y] = st.back();
                    st.pop_back();

                    for (int d = 0; d < 4; ++d) {
                        int nx = x + dr[d];
                        int ny = y + dc[d];

                        if (nx < 0 || nx >= rows || ny < 0 || ny >= cols || grid[nx][ny] != '1')
                            continue;

                        grid[nx][ny] = '0';
                        st.push_back({nx, ny});
                    }
                }
            }
        }

        return islands;
    }
};