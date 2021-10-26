/*
 * hungtran: 
 * self-learning c++
 */
// Constructing vectors

/* default:
 * (1) vector();
 *     explicit vector (const allocator_type& alloc);
 * fill:
 * (2) explicit vector (size_type n, const allocator_type& alloc = allocator_type());
 *              vector (size_type n, const value_type& val,
 *              const allocator_type& alloc = allocator_type());
 * range:
 * (3) template <class InputIterator>
 *        vector (InputIterator first, InputIterator last,
 *                const allocator_type& alloc = allocator_type());
 * copy:
 * (4) vector (const vector& x);
 *     vector (const vector& x, const allocator_type& alloc);
 * move:
 * (5) vector (vector&& x);
 *     vector (vector&& x, const allocator_type& alloc);
 * initializer list
 * (6) vector (initializer_list<value_type> il,
 *             const allocator_type& alloc = allocator_type())
 */

#include <iostream>
#include <vector>

int main() {
  std::vector<int> v1; // an empty vector of ints
  std::vector<int> v2(4,100); //four elements vector with value 100
  std::vector<int> v3(v2.begin(), v2.end()); //iterating through v2
  std::vector<int> v4(v3); // a copy of v3
  
  int a[] = {16,2,77,29};
  std::vector<int> v5(a, a + sizeof(a)/sizeof(int));

  for (std::vector::iterator it = v5.begin(); it != v5.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
  return 0;
}
