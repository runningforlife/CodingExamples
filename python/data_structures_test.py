#!/usr/bin/python

def test_list():
    nums = [1, 4, 99, 23, 55]

    assert isinstance(nums, list)

    assert nums[0] == 1
    assert nums[2:3] == [99]

    print("list test done")

def test_set():
    family = {"dad", "mom", "daughter", "son", "gradma", "gradpa"}

    chars_set_1 = {'a', 'b', 'c', 'f', 'g', 'h', 'z'}
    chars_set_2 = {'d', 'b', 'c', 'g', 'h'}

    assert len(family) == 6
    assert chars_set_1 - chars_set_2 == {'a', 'f', 'z'}
    assert chars_set_1 & chars_set_2 == {'b', 'c', 'g', 'h'}

    print("set test done")


def test_dict():
    fruits_color = {
        'apple': 'red',
        'orange': 'orange',
        'banana': 'yellow',
    }

    assert fruits_color['apple'] == 'red'
    
    for item in fruits_color.keys():
        print(item)

def main():
    test_list()
    test_set()
    test_dict()

if __name__ == "__main__":
    main()
