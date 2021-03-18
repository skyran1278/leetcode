# Given a string only containing a/e/i/o/u, e.g. aeiaaioooaauuaeiu.
# Design an algorithm to find out the longest char orders in the order of a/e/i/o/u.
# E.g. the example input should output aeiiooouuu
def solution(s):
    dp = [['' for _ in range(5)] for _ in range(len(s))]
    vowels = {0: 'a', 1: 'e', 2: 'i', 3: 'o', 4: 'u'}
    if s[0] == 'a':
        dp[0][0] = 'a'

    for i in range(1, len(s)):
        for j in range(5):
            if s[i] == vowels[j]:
                if j != 0 and (dp[i - 1][j] or dp[i][j - 1]):
                    l1 = len(dp[i - 1][j])
                    l2 = len(dp[i][j - 1])
                    if l1 > l2:
                        dp[i][j] = dp[i - 1][j] + s[i]
                    else:
                        dp[i][j] = dp[i][j - 1] + s[i]
                elif j == 0:
                    dp[i][j] = dp[i - 1][j] + s[i]
            else:
                dp[i][j] = dp[i - 1][j]
    return dp[len(s) - 1][4]


print(solution('aeiouaaaiaaaa') == 'aaaaaaaa')
