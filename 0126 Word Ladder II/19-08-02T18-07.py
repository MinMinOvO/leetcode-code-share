from collections import deque


class Solution:
    def findLadders(self, beginWord: str, endWord: str, wordList: list) -> list:
        if len(wordList) == 1:
            dif = False
            for chr_a, chr_b, in zip(beginWord, endWord):
                if chr_a == chr_b:
                    if dif:
                        return []
                    else:
                        dif = True
            return [beginWord, endWord] if dif else []
        try:
            idx_end = wordList.index(endWord)
        except ValueError:
            return []
        try:
            idx_begin = wordList.index(beginWord)
        except ValueError:
            wordList.append(beginWord)
            idx_begin = len(wordList) -1
        N, L = len(wordList), len(wordList[0])
        edges = [[] for _ in range(N)]
        vals = [ord(word[0]) - 97 for word in wordList]
        for l in range(1, L):
            for i in range(N):
                vals[i] = (vals[i] << 5) | (ord(wordList[i][l]) - 97)
        model = ~31
        my_dict = {}
        for _ in range(L):
            for i in range(N):
                key = vals[i] & model
                if key not in my_dict:
                    my_dict[key] = [i]
                else:
                    for val in my_dict[key]:
                        edges[val].append(i)
                    edges[i] += my_dict[key]
                    my_dict[key].append(i)
            my_dict.clear()
            model = (model << 5) | 31

        def return_result():
            my_dict = {idx_begin: [[wordList[idx_begin]]]}
            my_dict_aux = {}
            while len(my_dict) > 0:
                for idx, trace in my_dict.items():
                    if idx == idx_end:
                        return trace
                    nodes_next = nodes_reach[idx]
                    for i in range(len(nodes_next) - 1):
                        trace_copy = [footprint.copy() for footprint in trace]
                        for footprint in trace_copy:
                            footprint.append(wordList[nodes_next[i]])
                        if nodes_next[i] not in my_dict_aux:
                            my_dict_aux[nodes_next[i]] = trace_copy
                        else:
                            my_dict_aux[nodes_next[i]] += trace_copy
                    for footprint in trace:
                        footprint.append(wordList[nodes_next[-1]])
                    if nodes_next[-1] not in my_dict_aux:
                        my_dict_aux[nodes_next[-1]] = trace
                    else:
                        my_dict_aux[nodes_next[-1]] += trace
                my_dict = my_dict_aux
                my_dict_aux = {}
            return []

        que = deque([idx_end])
        nodes_reach = [[] for _ in range(N)]
        flag = [0 for _ in range(N)]
        flag[idx_end] = 2
        nodes_visited = deque()
        while len(que) > 0:
            for _ in range(len(que)):
                node = que.popleft()
                for node_o in edges[node]:
                    if flag[node_o] <= 1:
                        nodes_reach[node_o].append(node)
                        if flag[node_o] < 1:
                            que.append(node_o)
                            nodes_visited.append(node_o)
                            flag[node_o] = 1
                if node == idx_begin:
                    # gugugu
                    return return_result()
            while len(nodes_visited) > 0:
                flag[nodes_visited.popleft()] = 2

        return []