import unittest
from file_count import count_file

class FileCountTest(unittest.TestCase):
     """Tests for file_count.py"""

     def test_python_file_count(self):
         """test python file count"""
         cnt = count_file('.', 'py')
         self.assertNotEqual(cnt, 0)

     def test_c_file_count(self):
         """test c file count"""
         cnt = count_file('.', 'c')
         self.assertEqual(cnt, 0)


unittest.main()
