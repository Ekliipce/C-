#include "unordered-multimap.hh"

template <typename KeyType, typename ValueType>
bool UnorderedMultimap<KeyType, ValueType>::empty() const
{
    return this->vect_.empty();
}

template <typename KeyType, typename ValueType>
unsigned UnorderedMultimap<KeyType, ValueType>::size() const
{
    return this->vect_.size();
}

template <typename KeyType, typename ValueType>
std::pair<typename UnorderedMultimap<KeyType, ValueType>::iterator,
          typename UnorderedMultimap<KeyType, ValueType>::iterator>
UnorderedMultimap<KeyType, ValueType>::equal_range(const KeyType& key)
{
    std::pair<typename UnorderedMultimap<KeyType, ValueType>::iterator,
              typename UnorderedMultimap<KeyType, ValueType>::iterator>
        equal_pair;
    bool is_end = false;

    for (auto it = vect_.begin(); it != this->vect_.end(); it++)
    {
        auto pair = it;
        if ((*pair).first == key)
        {
            equal_pair.first = pair;
            for (auto it2 = ++pair; it2 != this->vect_.end(); it2++)
            {
                auto pair2 = it2;
                if ((*pair2).first != key)
                {
                    equal_pair.second = pair2;
                    break;
                }
            }

            is_end = true;
            return equal_pair;
        }
    }

    if (!is_end)
    {
        equal_pair.first = this->vect_.end();
        equal_pair.second = this->vect_.end();
    }

    return equal_pair;
}

template <typename KeyType, typename ValueType>
void UnorderedMultimap<KeyType, ValueType>::add(const KeyType& key,
                                                const ValueType& value)
{
    this->vect_.push_back(std::pair(key, value));
}

template <typename KeyType, typename ValueType>
unsigned UnorderedMultimap<KeyType, ValueType>::count(const KeyType& key) const
{
    unsigned count = 0;
    for (auto pair : this->vect_)
    {
        if (pair.first == key)
            count++;
    }

    return count;
}

template <typename KeyType, typename ValueType>
void UnorderedMultimap<KeyType, ValueType>::clear()
{
    this->vect_.clear();
}
