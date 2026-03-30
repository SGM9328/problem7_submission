#include "priority_queue.hpp"

template <typename T>
bool PriorityQueue<T>::isEmpty() const
{
    // TODO
    return sorted_list.isEmpty();
}

template <typename T>
void PriorityQueue<T>::add(const T &item)
{
    // TODO
    sorted_list.insert(item);
}

template <typename T>
void PriorityQueue<T>::remove()
/*
In remove() and peek(), ***throw std::out_of_range if the queue is empty, but delegate the 
exception to the underlying SortedList — do not handle it directly in the priority queue
*/
{
    // TODO, but exception handling should be delegated
    sorted_list.removeAt(sorted_list.getLength());
}

template <typename T>
T PriorityQueue<T>::peek()
{
    // TODO, but exception handling should be delegated
    return sorted_list.getEntry(sorted_list.getLength());
}