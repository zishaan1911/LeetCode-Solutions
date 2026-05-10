class Solution:
    def countWordOccurrences(self, chunks: list[str], queries: list[str]) -> list[int]:
        s = "".join(chunks)

        pattern = r'[a-z]+(?:-[a-z]+)*'

        filtered = "".join(c if 'a'<=c<='z' or c=='-' else " " for c in s)

        words = []
        for segment in filtered.split():
            words.extend(re.findall(pattern, segment))

        from collections import Counter
        counts = Counter(words)

        return [counts[q] for q in queries]
        