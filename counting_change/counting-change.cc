constexpr long count(long long C[], int i, long n)
{
    if (n < 0)
        return 0;
    else if (n == 0)
        return 1;
    else if (i <= 0 && n >= 1)
        return 0;
    else
        return count(C, i - 1, n) + count(C, i, n - C[i - 1]);
}

constexpr long long count_change(const long long amount)
{
    long long C[] = { 1, 2, 5, 10, 20, 50, 100, 200 };

    int i = sizeof(C) / sizeof(C[0]);
    return count(C, i, amount);
}
