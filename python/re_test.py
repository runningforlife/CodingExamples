#!/usr/bin/python
"""
validate whether user input name/passwd 

satifies given format
"""
import re

def validate_user_info(name, pwd):
    """
    1. user name should be 6~20 chars including alphas or digits
    2. password length should be larger than 6 chars
    """

    name_re = re.match(r'^[0-9a-zA-Z_]{5,20}$', name)
    if not name_re:
        print('given name is not valid')
        return False

    pwd_re = re.match(r'^[A-Z]{1}[0-9a-zA-Z!@$]{5,30}', pwd)
    if not pwd_re:
        print('given password is not valid')
        return False


    return True

def main():
    user_name = input('please input your name:')
    user_pwd = input('please input your password:')

    if validate_user_info(user_name, user_pwd) == True:
        print('congratinations! given user info is valid')
    else:
        print('user info is not valid')


if __name__ == '__main__':
    main()
