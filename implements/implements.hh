#pragma once

template <typename T, typename N = T>
concept impl_basic_op = requires(T elm1, N elm2)
{
    elm1 + elm2;
    elm1 - elm2;
    -elm1;
    +elm1;
    elm1 / elm2;
    elm1* elm2;
};

template <typename T, typename N = T>
concept impl_modulo = requires(T elm1, N elm2)
{
    elm1 % elm2;
};

template <typename T, typename N = T>
concept impl_bitwise_op = requires(T elm1, N elm2)
{
    elm1 << elm2;
    elm1 >> elm2;
    elm1 | elm2;
    elm1& elm2;
    ~elm1;
};

template <typename T, typename N = T>
concept impl_arith_op =
    impl_basic_op<T, N> && impl_modulo<T, N> && impl_bitwise_op<T, N>;
