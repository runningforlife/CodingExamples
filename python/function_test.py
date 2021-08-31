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

def cheese_shop(kind, *args, **keywords):
    """a function which pass tuples & dicts"""
    print('Do you have any ' , kind, '?')
    
    for arg in args:
        print(arg)

    print('-' * 40)

    for kw in keywords:
        print(kw, ':', keywords[kw])

def main():
    fib_test()
    func_test()
    lamda_test()
    func_decorators()

    cheese_shop("Limburger", "It's very funny, sir!", "It's really really, really funny, sir.",
            shopkeeper="Michael Palin",
            client="John Cleese",
            sketch="Cheese Shop Sketch")

    word_tuple = ("hah, it's funny", "hahaha, it's really funny funny day", "ok, we got a cheese")
    person_dict = {"shopKeeper": "Michael",
                   "client":"John",
                   "sketch": "cheese Shop sketch"}

    # unpacking parameters
    cheese_shop("Limburger", *word_tuple, **person_dict)


if __name__ == "__main__":
    main()

