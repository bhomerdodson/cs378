/*
CS378: Quiz #14 (9 pts)
*/

/* -----------------------------------------------------------------------
1. Assuming that push_back() and push_front() are defined for
   std::vector<T>, std::deque<T>, and std::list<T>, what are their
   complexities for each?
   (6 pts)

push_back()  on vector is amortized constant
push_front() on vector is           linear

push_back()  on deque  is amortized constant
push_front() on deque  is amortized constant

push_back()  on list   is           constant
push_front() on list   is           constant
*/

/* -----------------------------------------------------------------------
2. What is the complexity of std::vector<T>::swap()?
   Be precise. There are two cases.
   (3 pts)

constant if the allocators are equivalent, linear if not
*/
