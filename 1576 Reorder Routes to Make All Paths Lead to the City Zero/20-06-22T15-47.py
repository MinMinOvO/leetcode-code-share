class Solution:
    def minReorder(self, n: int, connections: List[List[int]]) -> int:
        _forward = [[] for _ in range(n)]
        _reverse = [[] for _ in range(n)]
        for a, b in connections:
            _forward[a].append(b)
            _reverse[b].append(a)
        reorder = 0
        visited = [False for _ in range(n)]
        que = deque([0])
        visited[0] = True
        while que:
            c = que.popleft()
            for r in _reverse[c]:
                if visited[r]:
                    continue
                que.append(r)
                visited[r] = True
            for f in _forward[c]:
                if visited[f]:
                    continue
                que.append(f)
                visited[f] = True
                reorder += 1
        return reorder