#include "Harl.hpp"

int main()
{
    Harl harl;

    std::cout << "Checking different harl levels:\n";
    harl.complain("DEBUG");
    harl.complain("INFO");
    harl.complain("WARNING");
    harl.complain("ERROR");
    harl.complain("INVALID");
    return (0);
}
