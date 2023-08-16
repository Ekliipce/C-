#include "int-container.hh"

#include <iostream>
#include <memory>
#include <optional>

MyIntContainer::MyIntContainer(size_t size)
    : current_size_(0)
    , max_size_(size)
    , elems_(std::make_unique<int[]>(size))
{}

// Print the content of the container
void MyIntContainer::print() const
{
    for (size_t i = 0; i < this->current_size_; i++)
    {
        if (i != this->current_size_ - 1)
            std::cout << this->elems_[i] << " | ";
        else
            std::cout << this->elems_[i] << '\n';
    }
}

// Get the current number of elements inside the array
size_t MyIntContainer::get_len() const
{
    return this->current_size_;
}

// Add an element inside the array
bool MyIntContainer::add(int elem)
{
    if (this->current_size_ == this->max_size_)
        return false;

    this->elems_[current_size_] = elem;
    this->current_size_++;
    return true;
}

// Get the last element inside the array and remove it
std::optional<int> MyIntContainer::pop()
{
    if (this->current_size_ < 1)
        return std::nullopt;

    std::optional<int> last = this->elems_[current_size_ - 1];
    this->current_size_--;
    return last;
}

// Get the element at a given position
std::optional<int> MyIntContainer::get(size_t position) const
{
    if (position >= this->current_size_)
        return std::nullopt;

    return std::optional<int>{ this->elems_[position] };
}

// Get the index inside the array of a given element
std::optional<size_t> MyIntContainer::find(int elem) const
{
    for (size_t i = 0; i < this->current_size_; i++)
    {
        if (this->elems_[i] == elem)
            return std::optional<size_t>{ i };
    }

    return std::nullopt;
}

// Sort the array
/*
void MyIntContainer::sort2()
{
    for (size_t i = 1; i < this->current_size_; i++)
    {
        int key = this->elems_[i];
        size_t j = i - 1;

        for (; this->elems_[j] > key; j--)
            this->elems_[j + 1] = this->elems_[j];
        this->elems_[j + 1] = key;
    }
}
*/
// Checks if the array is sorted
bool MyIntContainer::is_sorted() const
{
    if (this->current_size_ < 1)
        return true;

    for (size_t i = 1; i < this->current_size_; i++)
    {
        if (this->elems_[i - 1] > this->elems_[i])
            return false;
    }

    return true;
}

void my_swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void MyIntContainer::sort()
{
    for (size_t i = 0; i < this->current_size_ - 1; i++)
        for (size_t j = 0; j < this->current_size_ - i - 1; j++)
            if (this->elems_[j] > this->elems_[j + 1])
                my_swap(&this->elems_[j], &this->elems_[j + 1]);
}
