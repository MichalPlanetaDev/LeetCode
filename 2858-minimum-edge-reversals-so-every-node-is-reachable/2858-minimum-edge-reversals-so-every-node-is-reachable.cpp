class Solution {
public:
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> graph(n);

        for (const auto& e : edges) {
            graph[e[0]].push_back({e[1], 0});
            graph[e[1]].push_back({e[0], 1});
        }

        vector<int> parent(n, -1), change(n), ans(n);
        vector<int> order = {0};
        parent[0] = 0;

        for (int i = 0; i < order.size(); ++i) {
            int u = order[i];

            for (auto [v, reversed] : graph[u]) {
                if (v == parent[u])
                    continue;

                parent[v] = u;
                change[v] = reversed ? -1 : 1;
                ans[0] += reversed;
                order.push_back(v);
            }
        }

        for (int i = 1; i < n; ++i) {
            int u = order[i];
            ans[u] = ans[parent[u]] + change[u];
        }

        return ans;
    }
};