#include "sorted_list.hpp"
#include <stdexcept>

template <typename T>
SortedList<T>::SortedList() : List<T>()
{
} // Constructor, completed

template <typename T>
SortedList<T>::SortedList(List<T> unsorted_list)
{
  // iterate through unsorted list and insert each item in sorted order
  for (int i = 1; i <= unsorted_list.getLength(); i++) {
    insert(unsorted_list.getEntry(i)); // insert will handle the actual sorting of list
  }
}

template <typename T>
SortedList<T>::SortedList(const SortedList<T> &x) : List<T>(x)
{
} // Copy constructor, completed

template <typename T>
SortedList<T> &SortedList<T>::operator=(SortedList<T> x)
{
  List<T>::operator=(x);
  return *this;
} // Copy assignment operator, completed

template <typename T>
SortedList<T>::~SortedList()
{
} // Destructor, completed

template <typename T>
bool SortedList<T>::isEmpty() const noexcept
{
  return List<T>::isEmpty();
} // Base Class function called, completed

template <typename T>
int SortedList<T>::getLength() const noexcept
{
  return List<T>::getLength();
} // Base Class function called, completed

template <typename T>
void SortedList<T>::insert(const T &item)
{
  int position = 1;
  while (position <= List<T>::getLength() && List<T>::getEntry(position) < item) {
    position++; // move forward to see where item belongs
  }
  List<T>::insert(position, item); // insert at the found position
}

template <typename T>
void SortedList<T>::remove(const T &item)
{
  int position = getPosition(item); // throws std::invalid_argument if not found
  List<T>::remove(position);
}

template <typename T>
void SortedList<T>::removeAt(int position)
{
  List<T>::remove(position);
}

template <typename T>
void SortedList<T>::clear()
{
  List<T>::clear();
} // Base Class function called, completed

template <typename T>
T SortedList<T>::getEntry(int position) const
{
  return List<T>::getEntry(position);
} // Base Class function called, completed

template <typename T>
int SortedList<T>::getPosition(const T &item)
{
  // linear search
  int position = 1;
  while (position <= List<T>::getLength() && List<T>::getEntry(position) < item) {
    position++;
  }

  // throw std::invalid_argument if item not found
  if (position > List<T>::getLength() || List<T>::getEntry(position) != item) {
    throw std::invalid_argument("Item not in sorted list");
  }

  return position;
}