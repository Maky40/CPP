#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    if (ac < 2)
    {
        std::cerr << "Error: Need at least one argument.\n"
                  << "Usage example: ./PmergeMe [nb1] [nb2] [nb3] [nb4]" << std::endl;
        return (EXIT_FAILURE);
    }
    try
    {
        PmergeMe sequence(av);
        sequence.execute();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return (EXIT_FAILURE);
    }

    return (EXIT_SUCCESS);
}
