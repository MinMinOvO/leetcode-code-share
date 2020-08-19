from collections import deque

class Solution:
    def gardenNoAdj(self, N: int, paths: List[List[int]]) -> List[int]:
        edges = [deque() for _ in range(N)]
        for [a, b] in paths:
            a, b = a - 1, b - 1
            edges[a].append(b)
            edges[b].append(a)
        result = [0 for _ in range(N)]
        change = [False for _ in range(N)]
        for head in range(N):
            if result[head]:
                continue
            result[head] = 1
            que_node = deque([head])
            while que_node:
                node = que_node.popleft()
                node_val = result[node]
                edge_val = 1 + (node_val & 1)
                other_val = node_val + 2 if node_val <= 2 else node_val - 2
                equal, other, need_change = False, False, False
                for edge in edges[node]:
                    r_edge = result[edge]
                    if r_edge:
                        if r_edge == node_val:
                            equal = True
                            if change[edge]:
                                need_change = True
                        elif r_edge == other_val:
                            other = True
                            if change[edge]:
                                need_change = True
                    else:
                        result[edge] = edge_val
                        que_node.append(edge)
                if equal:
                    if other:
                        if need_change:
                            if node_val & 1:
                                for edge in edges[node]:
                                    if not (result[edge] & 1):
                                        change_val = 2 if result[edge] == 4 else 4
                                        break
                            else:
                                for edge in edges[node]:
                                    if result[edge] & 1:
                                        change_val = 1 if result[edge] == 3 else 3
                                        break
                            result[node] = change_val
                        else:
                            change[node] = True
                    else:
                        result[node] = other_val
        return result