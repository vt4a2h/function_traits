/*****************************************************************************
**
** Copyright (C) 2019 Fanaskov Vitaly (vt4a2h@gmail.com)
**
** Created 24/5/2019.
**
** Permission is hereby granted, free of charge, to any person obtaining a copy
** of this software and associated documentation files (the "Software"), to deal
** in the Software without restriction, including without limitation the rights
** to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
** copies of the Software, and to permit persons to whom the Software is
** furnished to do so, subject to the following conditions:
**
** The above copyright notice and this permission notice shall be included in all
** copies or substantial portions of the Software.
**
** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
** FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
** AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
** LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
** OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
** SOFTWARE.
**
*****************************************************************************/

#include <utility>
#include <tuple>

namespace ft {

    template<class T>
    struct function_traits;

    template<class T>
    struct function_traits : public function_traits<decltype(&T::operator())> {};

    template<class R, class ...Args>
    struct function_traits<R (*)(Args...)>
    {
        static constexpr std::size_t args_count = sizeof...(Args);

        using result_type = R;

        template <std::size_t index>
        struct arg
        {
            using type = typename std::tuple_element<index, std::tuple<Args...>>::type;
        };
    };

    template<class R, class C, class ...Args>
    struct function_traits<R (C::*)(Args...) const> : public function_traits<R (*)(Args...)>
    {
        using class_type = C;
    };

} // namespace ft
