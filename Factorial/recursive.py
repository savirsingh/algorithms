# code by savir singh
# A function to find the factorial of a given number.
# (Using recursion)

def factorial(num):
    global list1
    global final
    if num == 1:
        for i in range(len(list1)):
            final*=list1[i]
        print(final)
        return False
    list1.append(num-1)
    num-=1
    factorial(num)

final = 1
list1 = []
in1 = int(input())
list1.append(in1)
factorial(in1)
