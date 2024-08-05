#pragma once

#include <cstdlib>
#include <sys/time.h>
#include <iostream>
#include <iomanip>
#include <exception>
#include <vector>
#include <deque>
#include <set>

class PmergeMe
{
public:
    /* Constructors */
    PmergeMe(char **sequence);
    PmergeMe(const PmergeMe &toCopy);
    ~PmergeMe();

    /* Operators */
    PmergeMe &operator=(const PmergeMe &rhs);

    /* Members */
    void execute();
	 void _checkArgs(char **sequence) const;
    void _checkDuplicates();
    void _parseSequence(char **sequence);
    double _getTime() const;

private:
    /* Attributes */
    int _size;
    std::vector<int> _vector;
    std::deque<int> _deque;

    /* Constructors */
    PmergeMe();

    /* Exceptions */
    class NotADigitException : public std::exception
    {
        const char *what() const throw();
    };

    class DuplicatesException : public std::exception
    {
        const char *what() const throw();
    };

    /* Methods */
    template <typename T>
    static void fordJohnsonSort(T &container);
};

std::ostream &operator<<(std::ostream &stream, std::vector<int> &vector);
std::ostream &operator<<(std::ostream &stream, std::deque<int> &deque);
