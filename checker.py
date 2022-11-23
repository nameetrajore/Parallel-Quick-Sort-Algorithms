import sys
args = sys.argv
output = args[1]

f = open(output, "r")
f2 = open('input.txt', "r")

read_input = f2.read()
input = read_input.split(' ')
data = f.read()
sorted = data.split(' ')
f.close()

input.sort()
if(input==sorted):
    print('Array is not sorted.')
else:
    print('Array is sorted.')