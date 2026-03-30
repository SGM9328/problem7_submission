#include "list.hpp"

#include "list.hpp"
#include <stdexcept>
#include <algorithm>

template <typename T>
List<T>::List()
{
  head = nullptr; // head node starts as nullptr
  size = 0;
}

template <typename T>
List<T>::~List()
{
  clear();
}

template <typename T>
List<T>::List(const List<T> &x)
{
  head = nullptr; // head node starts as nullptr
  size = 0; // size starts at 0
  Node<T>* current = x.head; // pointer to current node in x list

  for (int i = 1; i <= x.size; i++) { // cycle through x list, insert each item into this list
    insert(i, current->getItem()); // insert item at position i, position starts at 1
    current = current->getNext(); // traverse to next node in x list
  }
}

template <typename T>
List<T> &List<T>::operator=(List<T> x)
{
  swap(x); // copy swap idiom
  return *this;
}

template <typename T>
void List<T>::swap(List &x)
{
  std::swap(head, x.head); // swap head pointers
  std::swap(size, x.size); // swap size of original list and x list
}

template <typename T>
bool List<T>::isEmpty() const noexcept
{
  if (size == 0) // if size is 0, list empty
  {
    return true;
  }
  return false; // otherwise, not empty
}

template <typename T>
int List<T>::getLength() const noexcept
{
  return size;
}

template <typename T>
void List<T>::insert(int position, const T &item)
{
  // TODO, implement the insert function using 1-based indexing
  // Note the void return type and throw std::out_of_range if the position is invalid
  if (position < 1 || position > size + 1) { // between 1 and size + 1
    throw std::out_of_range("Position is out of range");
  }

  Node<T>* newNode = new Node<T>(item); // new node to insert, initialized with item

  if (position == 1) { // inserted at front(head) of list
    newNode->setNext(head);
    head = newNode; // updating head pointer
  } else { // if insert is at position > 1
    Node<T>* current = head; // cycle to node just before position to insert
    for (int i = 1; i < position - 1; i++) { // actual cycling of pointer, again just only before position, hence (position - 1)
      current = current->getNext(); // traverse to node before position
    }
    // insert new node at position by linking it into list
    newNode->setNext(current->getNext()); // newNode points to node that current is pointing to
    current->setNext(newNode); // link new node into list
  }

  size++;
}

template <typename T>
void List<T>::remove(int position)
{
  // TODO, implement the remove function using 1-based indexing
  // Note the void return type and throw std::out_of_range if the position is invalid
  if (position < 1 || position > size) { // position between 1 and size
    throw std::out_of_range("Position is out of range");
  }

  Node<T>* toDelete; // dummy node

  if (position == 1) { // remove head
    toDelete = head;
    head = head->getNext(); // updating head node to next node
  } else { // remove at position > 1
    Node<T>* current = head; // remove node just before current position
    for (int i = 1; i < position - 1; i++) {
      current = current->getNext(); // traverse to node just before current position
    }
    toDelete = current->getNext(); // store current node in dummy node
    current->setNext(toDelete->getNext()); // bypass the node to delete
  }

  delete toDelete; // delete "current" node, that is stored in dummy node, to free memory (yay)
  size--; // size decreased by 1
}

template <typename T>
void List<T>::clear()
{
  // clear removes all items in list
  size = 0; // reset size to 0
  Node<T>* current = head; // pointer to current node
  while (current != nullptr) { // nullptr to go to end of list
    Node<T>* toDelete = current; // node to delete, same as in remove method
    current = current->getNext(); // shift to next node BEFORE deleting current node
    delete toDelete;
  }
  head = nullptr; // reseting front(head) to nullptr
}

// throw std::out_of_range if position < 1 or position > getLength()
template <typename T>
T List<T>::getEntry(int position) const
{
  // TODO
  // Throws std::out_of_range if the position is invalid
  if (position < 1 || position > size) { // position between 1 and size
    throw std::out_of_range("Position is out of range");
  }

  Node<T>* current = head;
  for (int i = 1; i < position; i++) {
    current = current->getNext(); // traverse list to pos
  }
  return current->getItem(); // return item at position
}

// throw std::out_of_range if position < 1 or position > getLength()
template <typename T>
void List<T>::setEntry(int position, const T &newValue)
{
  // TODO
  // Throws std::out_of_range if the position is invalid
  if (position < 1 || position > size) { // position between 1 and size
    throw std::out_of_range("Position is out of range");
  }

  Node<T>* current = head; // head node
  for (int i = 1; i < position; i++) {
    current = current->getNext(); // traverse list to pos
  }
  current->setItem(newValue); // set the new value at the position
}