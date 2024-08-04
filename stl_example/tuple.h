#pragma once

template <typename... Types>
class Tuple;

template <typename T, typename... Rest>
class Tuple<T, Rest...> : public Tuple<Rest...>
{
private:
    T _value;

public:
    // 使用构造函数初始化当前值和剩余元组
    Tuple(T value, Rest... rest) : Tuple<Rest...>(rest...), _value(value) {}

    // 获取当前元组元素
    T &getValue()
    {
        return _value;
    }

    // 重载括号运算符以便访问特定类型的元素
    template <std::size_t Index>
    auto &get()
    {
        if constexpr (Index == 0)
        {
            return _value;
        }
        else
        {
            return Tuple<Rest...>::template get<Index - 1>();
        }
    }
};

// 递归终止条件
template <>
class Tuple<>
{
};

// std::get
template <std::size_t Index, typename... Types>
auto &get(Tuple<Types...> &tuple)
{
    return tuple.template get<Index>();
}
