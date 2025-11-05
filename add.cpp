// Pour formater sous Windows : Shift + Alt + F

#include <iostream>
#include <cstdlib>

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        std::cerr << "error: not enough arguments" << std::endl;
        return -1;
    }
    int i = 1;
    int res = 0;
    while (i < argc)
    {
        int b = std::atoi(argv[i]);
        res = res + b;
        i = i + 1;
    }
    std::cout << res << std::endl;
    return 0;
}