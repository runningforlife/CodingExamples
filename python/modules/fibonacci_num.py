"""Fibonacci numbers module"""

def fibonacci_at_pos(n):
    """return fibonacci number for given position"""
    curr_pos = 0
    prev_num, curr_num = 0, 1

    while curr_pos < n:
        curr_pos += 1
        prev_num, curr_num = curr_num, prev_num + curr_num
    
    return prev_num

def fibonacci_small_than(n):
    """"get fibonacci number smaller than given number"""
    result = []
    prev, curr = 0, 1

    while prev < n:
        result.append(prev)
        prev, curr = curr, prev + curr

    return prev


if __name__ == "_main__":
    import sys
    print(fibonacci_small_than(sys.argv[1]))
