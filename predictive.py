a=('Red','Blue','Green','Black','White','Yellow','Red') #Tuple of colors
for i in a:
    print(i) #Accessing elements using indexing
#a[3]='Orange'#Tuple object doesn't supports mutability
b=0
element='Red'
count=a.count(element)
print(f"The element '{element}' occurs {count} times in the tuple")
#Create and manipulate Dictionaries
D={'Name':'Riya','Age':20,'City':'Karnal'}
print(D['Name'])
print(D['Age'])
print(D['City'])
D['Email']='riyag9034@gmail.com'
print(D['Email'])
D['Age']=31# Modifying an existing Key value
print(D)
if 'City' in D:
    print("City exists in the Dictionary")
else:
    print("City doesn't exists in the Dictionary")
#Getting a list of keys and value pairs
Keys=list(D.keys())
values=list(D.values())
print("Keys: ",Keys)
print("values: ",values)
#Difference between List and Tuple
List=[1,2,3,4,5,6]
Tuple=(1,2,3,4,5,6)
print(List)
print(Tuple)
List[3]=78
#Tuple[5]=99 #Tuple object doesn't supports item assignment
print(List)
print(Tuple)
List.append(45)
print(List)
#We cannot use the append method in tuple as they are immutable
#Program to print the multiplication table of a number
a=int(input("Enter a number: "))
print(f"Multiplication table of {a} is: ")
for i in range(1,11):
    print(f"{a} x {i} = {a*i}")
#Create a program to find factorial of a number
e=int(input("Enter a number: "))
fact=1
if e==0:
    print("Factorial is 1")
else:
    for i in range(1,e+1):
        fact*=i
print(f"Factorial of a {e} is {fact}")
#Write a program to check if a given number is prime
def is_prime(n):
    if n<=1:
        return False
    for i in range(2,int(n**0.5)+1):
        if n%i==0:
            return False
    return True
number=int(input("Enter a number: "))
if is_prime(number):
    print(f"{number} is a prime number")
else:
    print(f"{number} is not a prime number")
#Program to find sum of all even numbers between 1 and 100
sum=0
for i in range(1,101):
    if i%2==0:
        sum+=i
print(f"Sum of all even numbers from 1 to 100 is {sum} ")
#Implement a simple calculator using conditional statements and loops
def add(x, y):
    return x + y

def subtract(x, y):
    return x - y

def multiply(x, y):
    return x * y

def divide(x, y):
    if y != 0:
        return x / y
    else:
        return "Error! Division by zero."

def calculator():
    while True:
        print("\nSimple Calculator")
        print("1. Add")
        print("2. Subtract")
        print("3. Multiply")
        print("4. Divide")
        print("5. Exit")

        choice = input("Enter choice (1/2/3/4/5): ")

        if choice == '5':
            print("Exiting the calculator. Goodbye!")
            break

        if choice in ['1', '2', '3', '4']:
            num1 = float(input("Enter first number: "))
            num2 = float(input("Enter second number: "))

            if choice == '1':
                print(f"Result: {num1} + {num2} = {add(num1, num2)}")
            elif choice == '2':
                print(f"Result: {num1} - {num2} = {subtract(num1, num2)}")
            elif choice == '3':
                print(f"Result: {num1} * {num2} = {multiply(num1, num2)}")
            elif choice == '4':
                result = divide(num1, num2)
                print(f"Result: {num1} / {num2} = {result}")
        else:
            print("Invalid input! Please enter a valid choice.")

calculator()
