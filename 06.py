class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if s == '': return ''
        if numRows == 1: return s
        slst = list(s)
        if numRows == 2:
            ret = []
            i = 0
            while i < len(slst):
                ret.append(slst[i])
                i += 2
            i = 1
            while i < len(slst):
                ret.append(slst[i])
                i += 2
            return ''.join(ret)
        ret = []
        # 第1行
        idx = 0
        while idx < len(slst):
            ret.append(slst[idx])
            idx += (2 * numRows - 2)
        
        for idx in range(1, numRows - 1):
            longInterval = 2 * (numRows - idx - 1)
            shortInterval = 2 * idx
            
            temp = idx
            inter = longInterval
            while temp < len(slst):
                ret.append(slst[temp])
                temp += inter
                inter = shortInterval if inter == longInterval else longInterval
        
        idx = numRows - 1
        while idx < len(slst):
            ret.append(slst[idx])
            idx += (2 * numRows - 2)
        
        # assert len(ret) == len(slst)
        return ''.join(ret)
            
def main():
    s = "PAYPALISHIRING"
    numRows = 4
    print(Solution().convert(s, numRows))

if __name__ == "__main__":
    main()