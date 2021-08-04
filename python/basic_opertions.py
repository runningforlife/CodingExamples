#!/usr/bin/python

"""how to user basic math operations in python """

def math_operations():
    a = 5 + 3
    assert a == 8

    b = 5 - 3
    assert b == 2

    c = 5 * 3
    assert c == 15
    assert isinstance(c, int)

    assert 5 / 3 == 1.666666666666666666666667
    assert 8 / 2 == 4

    assert 5 % 3 == 2

    assert 5 ** 3 == 125
    assert 2 ** 3 == 8

    assert 5 // 3 == 1
    assert 8 // 4 == 2

    print("math operation done")


def do_bitwise_operations():
    """bitwise operations"""

    assert 5 & 3 == 1
    assert ~4 == -5

    assert 5 ^ 3 == 6

    assert 5 >> 1 == 2
    assert 5 << 2 == 20

    print("bitwise operations done")

if __name__ == "__main__":
    math_operations()
    do_bitwise_operations()
