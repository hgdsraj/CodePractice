#include <exception>
#include <iostream>
#include <string>


namespace LOL
{
    typedef int Foo;
    class foo : public std::exception
    {
    public:
        virtual const char * what() const throw()
        {
            return static_cast<const char*>((char *)&"LOL"[0]);
        }
    };

    struct result_type
    {
    public:
        result_type(int x);
        const int res = 0;
    };
};
LOL::result_type::result_type(int x) : res(x) {}

int bar(LOL::Foo baz, LOL::Foo foobar)
{
    if (foobar == 0)
    {
        throw(LOL::foo());
    }

    while (foobar != 0)
    {
        LOL::Foo lmao = baz & foobar;
        baz = baz ^ foobar;
        foobar = lmao << 1;
    }
    return baz;
}



int main()
{
    LOL::Foo ten = 10;
    LOL::Foo twelve = 12;
    try
    {
       LOL::result_type result(bar(ten,twelve));
       std::cout << result.res << std::endl;
    }
    catch(std::exception& e)
    {
      std::cout << e.what() << std::endl;
    }

    return 0;
}
