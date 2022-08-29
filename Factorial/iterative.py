# code by savir singh
# A function to find the factorial of a given number.
# (Using iteration)

in1 = int(input())
final = 1

while True:
    if in1==1:
        print(final)
        break
    final*=in1
    in1-=1
