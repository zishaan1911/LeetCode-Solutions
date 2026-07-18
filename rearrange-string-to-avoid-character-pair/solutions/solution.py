class Solution:
    def rearrangeString(self, s: str, x: str, y: str) -> str:
        cnt_x = 0
        cnt_y = 0
        others = []

        for ch in s:
            if ch == x:
                cnt_x += 1
            elif ch == y:
                cnt_y += 1
            else:
                others.append(ch)
        return y * cnt_y + "".join(others) + x * cnt_x