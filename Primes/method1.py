# code by savir singh
# A function to check if a given number is prime.
# (Method 1)

def check_prime(num):
  for i in range(2, int(num**0.5)):
    if num%i==0:
      return False
  return True

number = int(input())

print(check_prime(number))
