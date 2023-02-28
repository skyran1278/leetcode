class Solution:
    def findJudge(self, N: int, trusts: List[List[int]]) -> int:
        # 相信誰
        trust_dict = defaultdict(list)

        # 被幾個人相信
        be_trust_dict = defaultdict(int)

        for (me, other) in trusts:
            # 相信誰
            trust_dict[me].append(other)

            # 被幾個人相信
            be_trust_dict[other] += 1

        for i in range(1, N + 1):
            # 不相信任何人 and 被除了自己之外所有人相信
            if not trust_dict[i] and be_trust_dict[i] == N -1:
                return i

        return -1

class Solution:
    def findJudge(self, N: int, trust: List[List[int]]) -> int:
        # 相信誰
        trusts = [0] * (N + 1)

        for (me, other) in trust:
            # 相信誰
            trusts[me] -= 1
            trusts[other] += 1

        for i in range(1, N + 1):
            # 不相信任何人 and 被除了自己之外所有人相信
            if trusts[i] == N -1:
                return i

        return -1

class Solution:
    def findJudge(self, N: int, trust: List[List[int]]) -> int:
        trusts = dict.fromkeys(range(1, N + 1), 0)

        for (me, other) in trust:
            # 有相信人的就刪掉
            if me in trusts:
                del trusts[me]

            # 被相信的 + 1
            if other in trusts:
                trusts[other] += 1

        for i in trusts:
            # 被除了自己之外所有人相信
            if trusts[i] == N -1:
                return i

        return -1
