#pragma once

#include "stack-creation-failed.hh"
#include "stack-empty.hh"
#include "stack-max-size.hh"
#include "stack.hh"

template <class T>
Stack<T>::Stack(size_t max_size)
    : vect_()
    , size_{ max_size }
{
    try
    {
        vect_.reserve(this->size_);
    }
    catch (std::length_error const& err)
    {
        throw StackCreationFailed("Max stack size is too big.");
    }
    catch (std::bad_alloc const& err)
    {
        throw StackCreationFailed("Allocation failed.");
    }
}

template <class T>
Stack<T>& Stack<T>::push(const T& item)
{
    if (this->vect_.size() > this->size_ - 1)
        throw StackMaxSize("Unable to push, stack max size reached.");

    this->vect_.push_back(item);

    return *this;
}

template <class T>
Stack<T>& Stack<T>::operator+=(const T& item)
{
    return (*this) << item;
}

template <class T>
Stack<T>& Stack<T>::operator<<(const T& item)
{
    return this->push(item);
}

template <class T>
T Stack<T>::pop()
{
    if (this->vect_.size() == 0)
        throw StackEmpty("Unable to pop, stack is empty.");

    T last = this->vect_.back();
    this->vect_.pop_back();

    return last;
}

template <class T>
T Stack<T>::operator--()
{
    return this->pop();
}

template <class T>
T& Stack<T>::operator[](size_t i)
{
    if (this->vect_.size() - 1 < i)
        throw std::out_of_range("Out of range.");

    size_t index = this->vect_.size() - i - 1;
    return this->vect_[index];
}

template <class T>
bool Stack<T>::operator==(const Stack<T>& s)
{
    if (s.vect_.size() == this->vect_.size())
        return false;

    for (size_t i = 0; i <= s.vect_.size() - 1; i++)
    {
        if (s.vect_[i] != this->vect_[i])
            return false;
    }

    return true;
}

template <class T>
typename Stack<T>::const_iterator Stack<T>::begin() const
{
    return this->vect_.rbegin();
}

template <class T>
typename Stack<T>::iterator Stack<T>::begin()
{
    return this->vect_.rbegin();
}

template <class T>
typename Stack<T>::const_iterator Stack<T>::end() const
{
    return this->vect_.rend();
}

template <class T>
typename Stack<T>::iterator Stack<T>::end()
{
    return this->vect_.rend();
}

template <class T>
void Stack<T>::resize(size_t t)
{
    try
    {
        if (t < this->size_ + 1)
        {
            std::vector<T> vect;
            vect.reserve(t);
            for (size_t i = 0; i < t; i++)
                vect.push_back(this->vect_[i]);

            this->vect_ = vect;
        }
        else
            this->vect_.reserve(t);

        this->size_ = t;
    }
    catch (std::length_error const& err)
    {
        throw StackCreationFailed("Max stack size is too big.");
    }
    catch (std::bad_alloc const& err)
    {
        throw StackCreationFailed("Allocation failed.");
    }
}

template <class T>
std::ostream& Stack<T>::print(std::ostream& s) const
{
    size_t size = this->vect_.size();

    for (size_t i = 0; i < size; i++)
    {
        s << this->vect_.at(i);
        if (i < size - 1)
            s << " ";
    }

    return s;
}

template <class T>
std::ostream& operator<<(std::ostream& ostr, const Stack<T>& p)
{
    p.print(ostr);
    return ostr;
}

template <class T>
size_t Stack<T>::max_size() const
{
    return this->size_;
}
