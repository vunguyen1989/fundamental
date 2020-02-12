#SORTING
nums.sort()

#SUB LIST FROM LIST
mids = nums[l+1:r - len(nums)]

#GÁN HAI LIST VỚI NHAU => SẼ LÀM VIỆC NHƯ CON TRỎ
>>> x = [1,2]
>>> x
[1, 2]
>>> y = x
>>> y
[1, 2]
>>> x.append(5)
>>> x
[1, 2, 5]
>>> y
[1, 2, 5]
>>> y.clear()
>>> x
[]

#SWAP HAI LIST
x,y = y,x
