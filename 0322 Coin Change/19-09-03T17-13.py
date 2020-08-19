from math import ceil
class Solution:

    '''
    def coinChange(self, coins: list, amount: int) -> int:
        inf = 0x3f3f3f3f
        M = [inf for _ in range(amount+1)]
        M[0] = 0
        for i in range(len(coins)):
            for amount_use in range(amount, -1, -1):
                val_min = M[amount_use]
                for num in range(1, ceil(amount_use / coins[i])+1):
                    xxx = amount_use - num * coins[i]
                    if xxx >= 0 and M[xxx] + num < val_min:
                        val_min = M[xxx] + num
                M[amount_use] = val_min
        return -1 if M[amount] == inf else M[amount]
    '''

    def coinChange(self, coins: list, amount: int) -> int:
        INF = 0x3f3f3f3f
        opt = [INF if i != 0 else 0 for i in range(amount+1)]
        for cur, use in enumerate(opt):
            maybe = use + 1
            for coin in coins:
                new = cur + coin
                if new > amount:
                    continue
                if opt[new] > maybe:
                    opt[new] = maybe
        return opt[-1] if opt[-1] < INF else -1

if __name__ == '__main__':
    print(Solution().coinChange(coins=[1, 2, 5], amount=11))
