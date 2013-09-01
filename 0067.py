def max_triangle_path():
    # Read the values from files into an array for each level
    triangle = open('0067_input.txt', 'r').read().split('\n')

    # split the string into the integer values and reverse the triangle
    triangle = [list(map(int, t.split(' ')))
                for t in reversed(triangle) if len(t) > 0]

    #triangle = [list(map(int, x)) for x in triangle]

    print triangle

    for x_idx, x_val in enumerate(triangle):
        if x_idx == len(triangle):
            break
        y_pos = 0
        for y1, y2 in zip(x_val[:-1], x_val[1:]):
            if y1 > y2:
                triangle[x_idx + 1][y_pos] += y1
            else:
                triangle[x_idx + 1][y_pos] += y2
            y_pos += 1

    print triangle


if __name__ == "__main__":
    max_triangle_path() 
