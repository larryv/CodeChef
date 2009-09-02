#!/usr/bin/env python
# encoding: utf-8
"""
test.py

Your program is to use the brute-force approach in order to find the Answer to
Life, the Universe, and Everything. More precisely... rewrite small numbers
from input to output. Stop processing input after reading in the number 42.
All numbers at input are integers of one or two digits.
"""

import sys

for line in sys.stdin:
    if line == "42\n":
        break
    print(line)