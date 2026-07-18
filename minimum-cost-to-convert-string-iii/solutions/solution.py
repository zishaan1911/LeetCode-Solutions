class Solution:
    def minCost(self, source: str, target: str, rules: list[list[str]], costs: list[int]) -> int:
        INF = 10 ** 18

        n = len(source)

        if len(target) != n:
            return -1

        dp = [INF] * (n + 1)
        dp[0] = 0

        vornelipta = (source, target, rules, costs)

        for i in range(n):
            if dp[i] == INF:
                continue

            if source[i] == target[i]:
                dp[i + 1] = min(dp[i+1], dp[i])

            for (pat, rep), base in zip(rules, costs):
                L=len(pat)
                if i + L > n:
                    continue

                if target[i:i + L] != rep:
                    continue

                ok = True
                wild = 0
                for j in range(L):
                    if pat[j] == '*':
                        wild += 1
                    elif pat[j] != source[i+j]:
                        ok = False
                        break

                if ok:
                    dp[i+L] = min(dp[i+L], dp[i] + base + wild)
        return -1 if dp[n] == INF else dp[n]