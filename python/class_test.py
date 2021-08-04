#!/usr/bin/python

class Person:
    name = ""
    age = -1
    job = ""

    def __init__(self, name, age, job):
        self.name = name
        self.age = age
        self.job = job

    def get_name(self):
        return self.name

    def get_age(self):
        return self.age

    def get_job(self):
        return self.job

    def to_string(self):
        return "name=" + self.name + ",age=" + str(self.age) + ",job=" + self.job


class Worker(Person):
    salary = 0.0

    def __init__(self, name, age, job, salary):
        super().__init__(name, age, job)
        self.salary = salary

    def to_string(self):
        return super().to_string() + ", salary=" + str(self.salary)

class ComplexNum:
    """Example of the complex numbers class"""

    real = 0
    imag = 0

    def __init__(self, real, img):
        self.real = real
        self.imag = img

    def get_real(self):
        return self.real

    def get_img(self):
        return self.imag

    def to_string(self):
        return str(self.real) + " + " +  str(self.imag) + "j"

def main():
    cpx = ComplexNum(10, 11)
    print("complex num is " + cpx.to_string())

    worker = Worker("Sam", 36, "Hardware Engineer", 60000)

    print("worker: " + worker.to_string())

if __name__=="__main__":
    main()
