# code by savir singh
# Calculating the maximum subarray sum of a given array.

def maximum_subarray_sum(array, n):
    maximum = 0
    current = 0
    for i in range(n):
        current = max(array[i], current+array[i])
        maximum = max(maximum, current)
    return maximum

example_array = [1, -2, 3, -4, 5, 6, 7, -6, -4, -2]

print(maximum_subarray_sum(example_array, len(example_array)))
