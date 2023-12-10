class Solution:
    def getGoodIndices(self, variables: List[List[int]], target: int) -> List[int]:
        l = len(variables)
        li = []
        for i in range(l):
            a = variables[i][0]
            b = variables[i][1]
            c = variables[i][2]
            m = variables[i][3]
            if(((a**b)%10)**c) % m == target:
                li.append(i)
        return li