from cs50 import get_int


def main():
    n = get_height()
    for i in range(n):
        # Print blank spaces before
        for b in range(n - i - 1):
            print(" ", end="")
        # Print first block column
        for j in range(i + 1):
            print("#", end="")
        # Print blank space between
        print("  ", end="")
        # Print second block column
        for l in range(i + 1):
            print("#", end="")
        print()
    

# Check if number prompted is positive
def get_height():
    while True:
        n = get_int("Height: ")
        if n > 0 and n < 9:
            break
    return n


if __name__ == "__main__":
    main()