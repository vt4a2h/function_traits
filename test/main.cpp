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

#include "ft.hpp"

void freeFunction(int, double, float) {}

int main()
{
    {
        using FF = ft::function_traits<decltype(&freeFunction)>;

        static_assert(FF::args_count == 3);

        static_assert(std::is_same<FF::arg<0>::type, int   >::value);
        static_assert(std::is_same<FF::arg<1>::type, double>::value);
        static_assert(std::is_same<FF::arg<2>::type, float >::value);
    }

    {
        auto l = [](int, float){};
        using L = ft::function_traits<decltype(l)>;

        static_assert(L::args_count == 2);
        static_assert(std::is_same<L::arg<0>::type, int  >::value);
        static_assert(std::is_same<L::arg<1>::type, float>::value);
    }

    return 0;
}
