#!/bin/python3

import random
import sys

if __name__ == '__main__':
    if len(sys.argv) == 4:
        try:
            list = random.sample(range(int(sys.argv[2]), int(sys.argv[3])), int(sys.argv[1]))
        except ValueError:
            print('Sample size exceeded population size.\n')
        for i in range(len(list)): 
            sys.stdout.write(str(list[i]) + " ")
    else:
        print("usage: gen_rand_seq x, y, z\n" +
        "[x]: general amout of numbers to generate;\n"
        "[y]: minimal number in a sequence of numbers;\n"
        "[z]: maximum number in a sequence of numbers).")
        sys.exit()
