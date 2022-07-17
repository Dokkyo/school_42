#include "easyfind.tpp"

int main()
{
    std::vector<int>  a;
    int ret;

    for (int i = 0; i < 10; ++i)
    {
       a.push_back(i * 10);
    }

    for (int i = 0; i < 100; ++i)
    {
       ret = easyfind(a, i);
       if (ret == 1)
            std::cout << "No occurence." << std::endl;
    }

    return 0;
}