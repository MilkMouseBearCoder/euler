#!bin/usr/python


class NumberConverter(object):
    def __init__(self):
        self.ONES = ['one', 'two', 'three', 'four', 'five',
                     'six', 'seven', 'eight', 'nine']
        self.TENS = ['ten', 'twenty', 'thirty', 'forty', 'fifty',
                     'sixty', 'seventy', 'eighty', 'ninety']
        self.HUNDREDS = '{} hundred'
        self.THOUSANDS = '{} thousand'

    def __convert_ones_to_words__(self, n):
        return self.ONES[n -1]

    def __convert_tens_to_words__(self, n):
        return self.TENS[n - 1]

    def __convert_teens_to_words__(self, n):
        teens = {
            10: 'ten',
            11: 'eleven',
            12: 'twelve',
            13: 'thirteen',
            14: 'fourteen',
            15: 'fifteen',
            16: 'sixteen',
            17: 'seventeen',
            18: 'eighteen',
            19: 'nineteen'
        }

        return teens[n]
        

    def __convert_hundreds_to_words__(self, n):
        return self.HUNDREDS.format(self.__convert_ones_to_words__(n))

    def __convert_thousands_to_words__(self, n):
        return self.THOUSANDS.format(self.__convert_ones_to_words__(n))

    def __and__(self, s):
        if s != '':
            s+= ' and '
        return s

    def __space__(self, s):
        if s != '':
            s+= ' '
        return s


    def to_words(self, n):
        result = ''

        ones = n % 10
        tens = (n % 100)  - ones
        hundreds = (n % 1000) - tens - ones
        thousands = n - hundreds - tens - ones

        if thousands > 0:
            result+=self.__convert_thousands_to_words__(thousands / 1000)

        if hundreds > 0:
            result = self.__space__(result)
            word = self.__convert_hundreds_to_words__(hundreds / 100)
#            if thousands == 0:
#                word = word.replace('one', 'a')
            result+=word

        if tens == 10:
            result = self.__and__(result)
            result+=self.__convert_teens_to_words__(tens + ones)
        elif tens > 10:
            result = self.__and__(result)
            result+=self.__convert_tens_to_words__(tens / 10)

        if tens != 10 and ones > 0:
            if tens == 0:
                result = self.__and__(result)
            else:
                result = self.__space__(result)
            result+=self.__convert_ones_to_words__(ones)

        return result

if __name__ == '__main__':
    n = 1
    converter = NumberConverter()

    result = ''
    totalLength = 0;

    while n < 1001:
        words = converter.to_words(n);
        print words
        words = words.replace(' ', '').replace('-', '')
        totalLength+=len(words)
        n+=1

    result = result.replace(' ', '')
    print totalLength
