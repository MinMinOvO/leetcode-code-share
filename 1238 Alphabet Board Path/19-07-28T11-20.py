class Solution:
    def alphabetBoardPath(self, target: str) -> str:
        queue = [((0, 0), [])]
        board = ["abcde", "fghij", "klmno", "pqrst", "uvwxy", "z"]
        flag = [[False for _ in range(5)] for _ in range(6)]
        flag[0][0] = True
        idx_cur = 0
        mmm = []
        while True:
            position, chars = queue.pop(0)
            if board[position[0]][position[1]] == target[idx_cur]:
                chars.append('!')
                mmm = mmm + chars
                flag = [[False for _ in range(5)] for _ in range(6)]
                flag[position[0]][position[1]] = True
                queue = [(position, [])]
                idx_cur += 1
                if idx_cur == len(target):
                    break
                else:
                    continue
            if (position[0] <= 3 or (position[1] <= 0 and position[0] == 4)) and not flag[position[0]+1][position[1]]:
                flag[position[0]+1][position[1]] = True
                chars_copy = chars.copy()
                chars_copy.append("D")
                queue.append(((position[0]+1, position[1]), chars_copy))
            if position[0] >= 1 and not flag[position[0]-1][position[1]]:
                flag[position[0]-1][position[1]] = True
                chars_copy = chars.copy()
                chars_copy.append("U")
                queue.append(((position[0]-1, position[1]), chars_copy))
            if (position[1] <= 3 and position[0] <= 4) and not flag[position[0]][position[1]+1]:
                flag[position[0]][position[1]] = True
                chars_copy = chars.copy()
                chars_copy.append("R")
                queue.append(((position[0], position[1]+1), chars_copy))
            if position[1] >= 1 and not flag[position[0]][position[1]-1]:
                flag[position[0]][position[1]-1] = True
                chars_copy = chars.copy()
                chars_copy.append("L")
                queue.append(((position[0], position[1]-1), chars_copy))
        return ''.join(mmm)
        
            