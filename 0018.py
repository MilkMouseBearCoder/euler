
def max_triiangle_path():
    triangle_raw = open('0018_input.txt', 'r').read()

    triangle = triangle_raw.split('\n')

    for x in range(len(triangle)):
        triangle[x] = triangle[x].split(' ')

    print triangle


if __name__ == "__main__":
    max_triiangle_path() 
