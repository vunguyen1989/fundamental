#include <iostream>
#include <forward_list>

int main(){
	std::forward_list<int> list1 = {1, 2, 3, 4, 0, 2};
	std::forward_list<int> list2 = {8, 19, 6, 7, 8, 12};

//	list1.sort();
//	list2.sort();
//
//	list1.merge(list2);
	
	for (auto i : list1)
		std::cout << i << " ";
	std::cout << std::endl;

//	list1.remove_if([](int e){return e > 2;});
	list1.insert_after(list1.begin(), 5);

	std::cout << "After insert_after begin: " ;
	for (auto i : list1)
		std::cout << i << " ";
	std::cout << std::endl;







}
