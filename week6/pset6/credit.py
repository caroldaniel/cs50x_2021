import cs50
import sys


def main():
    # Get input from user
    cc_number = getnumber()
    # Check Luhn's Algorithm
    sumdigits = luhn(cc_number)
    if sumdigits % 10 == 0:
        # Check if AMEX
        if len(cc_number) == 15:
            if cc_number[0] == "3":
                if cc_number[1] == "4" or cc_number[1] == "7":
                    print("AMEX")
                    sys.exit(0)
        # Check if MasterCard
        if len(cc_number) == 16:
            if cc_number[0] == "5":
                if cc_number[1] in ["1", "2", "3", "4", "5"]:
                    print("MASTERCARD")
                    sys.exit(0)
        # Check if Visa
        if len(cc_number) in [13, 14, 15, 16]:
            if cc_number[0] == "4":
                print("VISA")
                sys.exit(0)
    print("INVALID")
    sys.exit(1)


# Check is user prompted a number
def getnumber():
    while True:
        cc_number = cs50.get_string("Number: ")
        if cc_number.isdigit():
            break
    return cc_number


# Check for Luhn's Algorithm
def luhn(cc_number):
    sumdigits = 0
    for i in range(len(cc_number)):
        if len(cc_number) % 2 == 0:
            if i % 2 == 0:
                product = (int(cc_number[i]) * 2)
                sumdigits += int(product / 10) + product % 10
            else:
                sumdigits += int(cc_number[i])
        else:
            if i % 2 == 1:
                product = (int(cc_number[i]) * 2)
                sumdigits += int(product / 10) + product % 10
            else:
                sumdigits += int(cc_number[i])
    return sumdigits


if __name__ == "__main__":
    main()

