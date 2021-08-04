#!/usr/bin/python
import fibonacci_num

from fibonacci_num import fibonacci_at_pos, fibonacci_small_than
from fibonacci_num import fibonacci_at_pos as fib_at_pos

def test_modules():

    print(fibonacci_num.fibonacci_at_pos(7))
    print(fib_at_pos(7))

    print(dir(fibonacci_num))
    print("modules test done")


if __name__ == "__main__":
    test_modules()
