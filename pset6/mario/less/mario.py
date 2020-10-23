# declare cs50 library


from cs50 import get_int

# user input


def main():
    pyramid_height = get_height("Height: ")
    draw_half_pyramid(pyramid_height)

# input condition


def get_height(prompt):
    while True:
        m = get_int(prompt)
        if m >= 1 and m <= 8:
            break
    return m

# Draw a pyramid of hashes


def draw_half_pyramid(rows):

    for row in range(1, rows + 1):
        print(" " * (rows - row) + "#" * row)


if __name__ == "__main__":
    main()
