template <typename T1, typename T2>
void Bimap<T1, T2>::insert(const T1& v1, const T2& v2)
{
    lhs.insert({ v1, v2 });
    rhs.insert({ v2, v1 });
}

template <typename T1, typename T2>
void Bimap<T1, T2>::insert(const T2& v1, const T1& v2)
{
    lhs.insert({ v2, v1 });
    rhs.insert({ v1, v2 });
}

template <typename T1, typename T2>
void Bimap<T1, T2>::erase(const T1& v)
{
    lhs.erase(v);
    for (iteratorT2 curr = rhs.begin(); curr != rhs.end(); curr++)
    {
        if (curr->second == v)
        {
            curr = rhs.erase(curr);
            break;
        }
    }
}

template <typename T1, typename T2>
void Bimap<T1, T2>::erase(const T2& v)
{
    rhs.erase(v);
    for (iteratorT1 curr = lhs.begin(); curr != lhs.end(); curr++)
    {
        if (curr->second == v)
        {
            curr = lhs.erase(curr);
            break;
        }
    }
}

template <typename T1, typename T2>
Bimap<T1, T2>::iteratorT1 Bimap<T1, T2>::find(const T1& v)
{
    return lhs.find(v);
}

template <typename T1, typename T2>
Bimap<T1, T2>::iteratorT2 Bimap<T1, T2>::find(const T2& v)
{
    return rhs.find(v);
}

template <typename T1, typename T2>
std::size_t Bimap<T1, T2>::size() const
{
    return lhs.size();
}

template <typename T1, typename T2>
void Bimap<T1, T2>::clear()
{
    lhs.clear();
    rhs.clear();
}
