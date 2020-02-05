class Solution:
    def intToRoman(self, num: int) -> str:
        if num == 0: return ''
        hashmap = {
            1 : 'I',
            2 : 'II',
            3 : 'III',
            4 : 'IV',
            5 : 'V',
            9 : 'IX',
            10 : 'X',
            40 : 'XL',
            50 : 'L',
            90 : 'XC',
            100 : 'C',
            400 : 'CD',
            500 : 'D',
            900 : 'CM',
            1000 : 'M'
        }
        nums = sorted(hashmap.keys(), reverse=True)
        # print(nums)
        ret = ''
        while num != 0:
            for temp in nums:
                if num - temp >= 0:
                    break
            num -= temp
            ret += hashmap[temp]
        return ret

def main():
    x = 1994
    print(Solution().intToRoman(x))

if __name__ == "__main__":
    main()