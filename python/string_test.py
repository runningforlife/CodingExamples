#!/usr/bin/python

def do_str_test():
    hi = 'hello''world'

    print("the len of '" + hi + "' is " + str(len(hi)))

    assert hi.count('l') == 3

    print("do str test done")

if __name__ == "__main__":
    print("the name variable is " + __name__);
    do_str_test()
