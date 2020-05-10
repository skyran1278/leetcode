class Solution:
    def findJudge(self, N: int, trusts: List[List[int]]) -> int:
        trust_dict = defaultdict(list)
        be_trust_dict = defaultdict(int)
        for trust in trusts:
            trust_dict[trust[0]].append(trust[1])
            be_trust_dict[trust[1]] += 1

        for i in range(1, N + 1):
            if be_trust_dict[i] == N -1 and not trust_dict[i]:
                return i

        return -1
