class Solution {
public:
    int minimumThreshold(int n, vector<vector<int>>& edges,
                         int source, int target, int k) {

        // store the input midway in the function
        auto tarnicuvo = edges;

        vector<vector<pair<int,int>>> graph(n);

        int maxW = 0;

        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];

            graph[u].push_back({v, w});
            graph[v].push_back({u, w});

            maxW = max(maxW, w);
        }

        auto can = [&](int threshold) -> bool {

            vector<int> dist(n, INT_MAX);
            deque<int> dq;

            dist[source] = 0;
            dq.push_front(source);

            while (!dq.empty()) {
                int u = dq.front();
                dq.pop_front();

                for (auto &[v, w] : graph[u]) {

                    int cost = (w > threshold) ? 1 : 0;

                    if (dist[u] + cost < dist[v]) {
                        dist[v] = dist[u] + cost;

                        if (cost == 0)
                            dq.push_front(v);
                        else
                            dq.push_back(v);
                    }
                }
            }

            return dist[target] <= k;
        };

        // impossible even if all edges are light
        if (!can(maxW)) return -1;

        int lo = 0, hi = maxW;
        int ans = maxW;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if (can(mid)) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        return ans;
    }
};