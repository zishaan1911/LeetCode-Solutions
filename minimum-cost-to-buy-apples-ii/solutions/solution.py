class Solution:
    def minCost(self, n: int, prices: List[int], roads: List[List[int]]) -> List[int]:
        adj_empty = [[] for _ in range(n)]
        adj_taxed = [[] for _ in range(n)]

        for u, v, cost, tax in roads:
            adj_empty[u].append((v, cost))
            adj_empty[v].append((u, cost))
            adj_taxed[u].append((v, cost*tax))
            adj_taxed[v].append((u, cost*tax))

        def dijkstra(start_node, adj):
            dist = [float('inf')] * n
            dist[start_node] = 0
            pq = [(0, start_node)]
            while pq:
                d, u = heapq.heappop(pq)
                if d > dist[u]: continue
                for v, w in adj[u]:
                    if dist[u] + w < dist[v]:
                        dist[v] = dist[u] + w
                        heapq.heappush(pq, (dist[v], v))
            return dist

        d_empty = [dijkstra(i, adj_empty) for i in range(n)]
        d_taxed = [dijkstra(i, adj_taxed) for i in range(n)]

        ans = []

        for i in range(n):
            res = prices[i]
            for j in range(n):
                current_total = d_empty[i][j] + prices[j] + d_taxed[j][i]
                if current_total < res:
                    res = current_total
            ans.append(res)

        return ans