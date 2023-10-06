#include <algorithm>
#include <iostream>
#include <string>

int main(void)
{
    std::cout << "\n";
    std::cout << "________________________________________" << std::endl;

    double x, y; // windows: usually initialized with 0; Linux: you might actually get some rubbish initialization

    // std::cout << "x: " << x << "; y: " << y << std::endl;

    std::cout << "x = ";
    // std::cin >> x;
    std::cout << "y = ";
    // std::cin >> y;

    x = 80; y = 40;

    std::cout << "x: " << x << "; y: " << y << std::endl;

    double sum = x + y; //float type, double means double precision for float

    std::cout << "Sizes: " << sizeof(float) << " " << sizeof(double) << std::endl;

    // non-integer values accuracy can be preserved using string
    std::string str = "Here is the sum of the two numbers: " + std::to_string(sum);

    std::cout << "Type: " << typeid(str[0]).name() << std::endl; //char

    bool is_big = sum > 100;

    std::cout << "Is that equivalent? " << ((is_big == (x + y > 100)) ? "Yes" : "No") << std::endl; //play with parenthesis
    
    is_big ? std::cout << "Result is big" << std::endl : std::cout << "Result is small" << std::endl;

    if (is_big)
    {
        // for (size_t i = 0; i < str.size(); i++)
        // {
        //     str[i] = std::toupper(str[i]);
        // }
        for (auto &symbol : str) //play with & : it is needed to actually reference the contents of str
        {
            symbol = std::toupper(symbol);
            std::cout << symbol << "|";
        }
        std::cout << std::endl;
        // std::transform(str.begin(), str.end(), str.begin(), toupper);
    }
    else
    {
        std::transform(str.begin(), str.end(), str.begin(), tolower);
    }

    std::cout << str << std::endl;

    for (int i = 0; i < int(sum); i++)
    {
        std::cout << "_";
    }

    std::cout << std::endl << std::endl;

    return 0;
}