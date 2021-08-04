#!/usr/bin/python

import random

def lottery():
    """generator function"""

    for i in range(3):
        yield random.randint(1, 10)


    yield random.randint(20, 30)


def test_generators():
    for idx, rand_num in enumerate(lottery()):
        if idx < 3:
            assert 0 <= rand_num <= 10
        else:
            assert 20 <= rand_num <= 30


if __name__ == "__main__":
    test_generators()
    print("generators test done")
