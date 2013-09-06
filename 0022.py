def sort(lst):
    if lst == []:
        return []

    pivot = lst[0]
    left = []
    right = []

    for x in lst[1:]:
        if x > pivot:
            right.append(x)
        else:
            left.append(x)

    left = sort(left)
    left.append(pivot)

    right = sort(right)

    left.extend(right)
    return left

def name_score(name):
    score = 0
    for n in name:
        score += ord(n) - 96

    return score

name_list = file('0022.names.txt', 'r').read().replace('"', '').lower().split(',')

name_list = sort(name_list)

total_score = 0
pos = 1
for name in name_list:
    score = name_score(name)
    total_score += (pos * score)
    pos += 1

print total_score


