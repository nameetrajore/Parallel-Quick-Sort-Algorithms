import random
import sys

args = sys.argv
n = int(args[1])
f = open('input.txt','w') 
randomlist = random.sample(range(-2147483647, 2147483646), n)
for item in randomlist:
    f.write(str(item)+' ')
f.close()