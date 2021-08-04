#!/usr/bin/python

def fib_num(num):
    if num <= 1:
        return num
    else:
        return fib_num(num - 2) + fib_num(num - 1)

def func_test():
    pass

def lamda_test():
    x = lambda a, b : a ** b
    print("3^5 is " + str(x(3, 5)))
    print("2^10 is " + str(x(2, 10)))
    print("lamda test done")

def fib_test():
    res = fib_num(10)
    print("fibinacci 10th number is " + str(res))

def func_decorators():
    def greeting(name):
        return "Hello, {0}!".format(name)

    def decorate_with_div(func):
        def func_wrapper(name):
            return "<div>{0}</div>".format(func(name))

        return func_wrapper

    my_get_text = decorate_with_div(greeting)

    assert my_get_text("John") == '<div>Hello, John!</div>'
    print("func decorators done")

def main():
    fib_test()
    func_test()
    lamda_test()
    func_decorators()

if __name__ == "__main__":
    main()

