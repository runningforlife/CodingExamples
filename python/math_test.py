#!/usr/bin/python3
# -*- coding:UTF-8 -*-

a = 3 ** 9

print("3^9 is " + str(a))

PI = 3.1416
radius = float(input('please input radius of the circle\n'))
perimeter = 2 * PI * radius
area = PI * radius * radius

print('周长: %2.f' % perimeter)
print('面积: %2.f' % area)
