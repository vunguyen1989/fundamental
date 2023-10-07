# STRING TO LIST OF CHAR
>>> x = 'abc'
>>> list(x)
['a', 'b', 'c']

#LIST OF CHAR TO STRING
X = ''.join(prefix)

#CUT FROM STRING
>>> x = "Hello World!"
>>> x[2:]
'llo World!'
>>> x[:2]
'He'
>>> x[:-2]
'Hello Worl'
>>> x[-2:]
'd!'
>>> x[2:-2]
'llo Worl

#IN TRONG 1 LINE, PYTHON 3
print(int(A[i])//D, end =" ")
print (digit.count(1),digit.count(0)) => sẽ cách nhau dấu cách

#FIND IN STRING
Checking if substring is found
We can use in operator or find() function to check if substring is present in the string or not.
s = 'My Name is Pankaj'
if 'Name' in s:
    print('Substring found')
if s.find('Name') != -1:
    print('Substring found')
Note that find() function returns the index position of the substring if it’s found, otherwise it returns -1.
python string contains substring

#COUNT of Substring Occurrence
We can use count() function to find the number of occurrences of a substring in the string.
s = 'My Name is Pankaj'

print('Substring count =', s.count('a'))

s = 'This Is The Best Theorem'
print('Substring count =', s.count('Th'))

Output:
Substring count = 3
Substring count = 3

#DECIMAL TO BINARY
"{0:b}".format(int)
>> "{0:b}".format(int) => "{0:b}".format(5) => 101