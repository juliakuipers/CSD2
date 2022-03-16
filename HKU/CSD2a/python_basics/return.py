# Python program to
# demonstrate return statement
 
def add(a, b):
 
    # returning sum of a and b
    return a + b
 
def is_true(a):
 
    # returning boolean of a
    return bool(a)
 
# calling function
res = add(2, 3)
print("Result of add function is {}".format(res))
 
res = is_true(2<5)
print("\nResult of is_true function is {}".format(res))