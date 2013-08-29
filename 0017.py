#!bin/usr/python


class NumberConverter(object):
    def __init__(self):
        self.TRANSLATE = {
            1: 'one',
            2: 'two',
            3: 'three',
            4: 'four',
            5: 'five',
            6: 'six',
            7: 'seven',
            8: 'eight',
            9: 'nine',
            10: 'ten',
            11: 'eleven',
            12: 'twelve',
            13: 'thirteen',
            14: 'fourteen',
            15: 'fifteen',
            16: 'sixteen',
            17: 'seventeen',
            18: 'eighteen',
            19: 'nineteen',
            20: 'twenty',
            30: 'thirty',
            40: 'forty',
            50: 'fifty',
            60: 'sixty',
            70: 'seventy',
            80: 'eighty',
            90: 'ninety',
            100: 'hundred',
            1000: 'thousand'
        }

    def __and__(self, s):
        if s != '':
            s += ' and '
        return s

    def __space__(self, s):
        if s != '':
            s += ' '
        return s

    def to_words(self, n):
        result = ''

        ones = n % 10
        tens = (n % 100) - ones
        hundreds = (n % 1000) - tens - ones
        thousands = n - hundreds - tens - ones

        if thousands > 0:
            result += self.TRANSLATE[thousands / 1000] + ' ' \
                + self.TRANSLATE[1000]
        if hundreds > 0:
            result = self.__space__(result)
            result += self.TRANSLATE[hundreds / 100] + ' ' \
                + self.TRANSLATE[100]
        if tens == 10:
            result = self.__and__(result)
            result += self.TRANSLATE[tens + ones]
        elif tens > 10:
            result = self.__and__(result)
            result += self.TRANSLATE[tens]
        
        if tens != 10 and ones > 0:
            if tens == 0:
                result = self.__and__(result)
            else:
                result = self.__space__(result)
            result += self.TRANSLATE[ones]

        return result

if __name__ == '__main__':
    n = 1
    converter = NumberConverter()

    result = ''
    totalLength = 0

    while n < 1001:
        words = converter.to_words(n)
        print words
        words = words.replace(' ', '').replace('-', '')
        totalLength += len(words)
        n += 1

    result = result.replace(' ', '')
    print totalLength
