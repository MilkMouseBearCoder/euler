#! /usr/bin/python


DAY_OF_WEEK = ['Sun', 'Mon', 'Tue', 'Wed', 'Thu', 'Fri', 'Sat']
MONTH_DAYS = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]


def is_leap_year(year):
    if (year % 100 == 0 and year % 400 == 0) or year % 4 == 0:
        return True
    return False


def year_days(year, year_count=0):
    result = 0
    year_end = year + year_count

    while year <= year_end:
        if is_leap_year(year):
            result += 366
        else:
            result += 365
        year += 1

    return result


def month_days(month, year):
    leap_add = 0

    if month == 1 and is_leap_year(year):
        leap_add = 1

    return MONTH_DAYS[month] + leap_add


def day_of_week(day):
    return DAY_OF_WEEK[day % 7]


if __name__ == '__main__':
    sundays = 0

    day_1 = 1
    day_start = year_days(1901) + day_1
    day_end = year_days(1901, 100)

    month = 0
    year = 1901
    day = day_start
    while day < day_end:
        if day_of_week(day) == 'Sun':
            sundays += 1

        day += month_days(month, year)

        month += 1

        if month == 12:
            month = 0
            year += 1

    print sundays
