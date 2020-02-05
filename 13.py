class Solution:
    def romanToInt(self, s: str) -> int:
        if s == '' : return 0
        hashmap = {
            'I' : 1,
            'II' : 2,
            'III' : 3,
            'IV' : 4,
            'V' : 5,
            'IX' : 9,
            'X' : 10,
            'XL' : 40,
            'L' : 50,
            'XC' : 90,
            'C' : 100,
            'CD' : 400,
            'D' : 500,
            'CM' : 900,
            'M' : 1000
        }
        # 最大正向匹配
        ret = 0
        max_len = 3
        index = 0
        while index < len(s):
            temp_skip = max_len
            while temp_skip > 0:
                if s[index : index + temp_skip] in hashmap:
                    ret += hashmap[s[index : index + temp_skip]]
                    index += temp_skip
                    break
                else:
                    temp_skip -= 1
        return ret

def main():
    s = 'MCMXCIV'
    print(Solution().romanToInt(s))

if __name__ == '__main__':
    main()