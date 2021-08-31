#!/usr/bin/python

import subprocess
from subprocess import PIPE

def test_subprocess():
    cmd = 'adb devices'
    #print(subprocess.call(cmd, shell=True))
    #print(subprocess.check_output(["adb", "devices"]))


    std_out, std_err = subprocess.Popen(cmd, shell=True, stdout=PIPE, stderr=PIPE).communicate()

    print(std_out.decode('utf-8'))
    #print(type(std_out))
    print(str(std_out, 'UTF-8'))

    print(type(str(std_out, 'utf-8')))

    p = subprocess.run('adb devices', shell=True, stdout=PIPE)
    if p.returncode != 0:
       print("no device found")
    else:
        print("device " + str(p.stdout, 'utf-8') + " is found")

    print(str(p.stdout, 'utf-8').split())
    print(len(str(p.stdout, 'utf-8').split('\n')))

if __name__ == "__main__":
    test_subprocess()
