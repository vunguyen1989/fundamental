
# set of mixed datatypes
my_set = {1.0, "Hello", (1, 2, 3)}
print(my_set)
# set phải được init khi khởi tạo

#MIN VALUE OF DICT
>>> d = {320:1, 321:0, 322:3}
>>> d.items()
[(320, 1), (321, 0), (322, 3)]
>>> # find the minimum by comparing the second element of each tuple
>>> min(d.items(), key=lambda x: x[1]) 
(321, 0)
min(d.items(), key=lambda x: x[1])[0]


# set from string python
Xstr = input()
Xset = set(list(Xstr))

