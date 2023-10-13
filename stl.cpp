#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <unordered_map>

// C++'s iterators are a generalisation of pointers-into-arrays. So you can write this:

// void sort_array() {
//     int arr[10] = {4, 5, 1, 7, 6, 3, 9, 2, 8, 0};
//     std::sort(arr, arr + 10); // std::sort<int*>
// }
// just as you can write

// void sort_vector() {
//     std::vector<int> v = {4, 5, 1, 7, 6, 3, 9, 2, 8, 0};
//     std::sort(v.begin(), v.end()); // std::sort<std::vector<int>::iterator>
// }
// And in general you can write

// template <Container C, Integral T> // not-yet-legal concepts syntax
// sort_container() {
//     C<T> c = {4, 5, 1, 7, 8, 3, 9, 2, 8, 0};
//     std::sort(std::begin(c), std::end(c));
// }
// Note: template <Container C, Integral T> means template <typename C, typename T> requires Container<C> && Integral<T>, which roughly means template <typename C, typename T, std::enable_if_t<std::is_integral_v<T> && std::is_container_v<C>>, if std::is_container existed

// std::sort, because it is a function template, works for both T* (the sort of iterator you use into a T[N]) and std::vector<T>::iterator (the sort of iterator you use for a std::vector<T>, obviously). This only works because iterators are designed to mimic how pointers work.

// And you can write these:

// for (auto x : A) {
//     std::cout << x << std::endl;
// }
// which are transformed into this (basically):

// auto __end = std::end(A);    
// for (auto __it = std::begin(A); __it != __end; ++__it) {
//     std::cout << (*__it) << std::endl;
// }
// Which works whether A is arr or v.

// Note: While in C you use T * everywhere, in modern C++ you use unique_ptr<T> for a owning-pointer-to-T, T * for a non-owning-nullable-pointer-toT, T& for a non-owning-non-nullable-pointer-to-T, std::array<T,N>::iterator for a pointer-into-std::array<T,N> (the replacement for T[N]) and std::vector<T>::iterator for a pointer-into-std::vector<T> (the replacement for T[]).

// But iterators don't have to have the semantics of pointers, otherwise we'd just use pointers.

int main(void)
{
    // Create a vector of integers.
    std::vector<int> my_vector;

    // Add some elements to the vector.
    my_vector.push_back(1);
    my_vector.push_back(2);
    my_vector.push_back(3);
    my_vector.push_back(4);
    my_vector.push_back(5);

    // Iterate over the vector using a range-based for loop.
    // for (int element : my_vector) {
    //     std::cout << element << std::endl;
    // }

    int a = 10;
    int *b = new int[10];
    // std::cout << a << std::endl;
    // b -> |17|19| | | | | | | | | |
    // b -> 17
    // b + 1 -> 19
    // b + 2 -> | |
    // ...
    *b = 17;
    *(b + 1) = 19;
    *(b + 2) = 21;
    // std::cout << b << " stores " << *b << std::endl;
    // std::cout << b + 1 << " stores " << *(b + 1) << std::endl;
    // std::cout << b + 2 << " stores " << *(b + 2) << std::endl;
    // std::cout << *b << std::endl;
    // std::cout << *(b + 1) << std::endl;
    // std::cout << *(b + 2) << std::endl;

    std::vector<int>::iterator iter = my_vector.begin();
    // std::cout << *iter << std::endl;
    // std::cout << *(my_vector.begin()) << std::endl;
    // std::cout << *(my_vector.begin() + 1) << std::endl;

    my_vector.erase(iter + 3);

    // for (size_t i = 0; i < my_vector.size(); i++)
    // {
    //     std::cout << my_vector[i] << std::endl;
    // }

    // for (std::vector<int>::iterator it = my_vector.begin(); it < my_vector.end(); it++)
    // {
    //     std::cout << *it << std::endl;
    // }

    // for (int element : my_vector) {
    //     std::cout << element << std::endl;
    // }

    std::unordered_map<std::string, int> my_map;

    // Add some elements to the map.
    my_map["one"] = 1;
    // my_map["two"] = 2;
    my_map["three"] = 3;

    // Iterate over the map using a range-based for loop.
    // for (const auto& [key, value] : my_map) {
    //     std::cout << key << " -> " << value << std::endl;
    // }

    // for (const auto& it : my_map) {
    //     std::cout << it.first << " -> " << it.second << std::endl;
    // }

    // std::cout << my_map["two"] << std::endl; 

    //     // Iterate over the map using a range-based for loop.
    // for (const auto& [key, value] : my_map) {
    //     std::cout << key << " -> " << value << std::endl;
    // }

    if (my_map.find("something") != my_map.end())
        std::cout << my_map.find("something")->second << std::endl;
    else {
        std::cout << "did not find something" << std::endl;
    }
    std::cout << my_map["something"] << std::endl ;
    std::cout << my_map.find("something")->second << std::endl;

      // Create a vector of integers.
  std::vector<int> my_vector_to_sort = {3, 1, 2};

  // Sort the vector in ascending order.
  // <algorithms>
  std::sort(my_vector_to_sort.begin(), my_vector_to_sort.end());

  // Iterate over the vector and print the elements.
  for (int element : my_vector_to_sort) {
    std::cout << element << std::endl;
  }

    delete b;

    // for a, b in enumerate(my_list):
    //    print(a, b)

    return 0;
}