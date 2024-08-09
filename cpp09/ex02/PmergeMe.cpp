#include "PmergeMe.hpp"

/******************************** Constructors ********************************/
PmergeMe::PmergeMe() : _size(0) {}

PmergeMe::PmergeMe(char **sequence)
{
    _checkArgs(sequence);
    _parseSequence(sequence);
    _checkDuplicates();
}

PmergeMe::PmergeMe(const PmergeMe &toCopy)
{
    if (this != &toCopy)
    {
        this->_size = toCopy._size;
        this->_vector = toCopy._vector;
        this->_deque = toCopy._deque;
    }
}

PmergeMe::~PmergeMe() {}

/********************************* Operators **********************************/
PmergeMe &PmergeMe::operator=(const PmergeMe &rhs)
{
    if (this != &rhs)
    {
        this->_size = rhs._size;
        this->_vector = rhs._vector;
        this->_deque = rhs._deque;
    }
    return (*this);
}

/********************************* Exceptions *********************************/
const char *PmergeMe::NotADigitException::what() const throw()
{
    return ("Error: Sequence must be composed by positive integers only.");
}

const char *PmergeMe::DuplicatesException::what() const throw()
{
    return ("Error: Duplicates.");
}

/********************************* Members **********************************/
void PmergeMe::_checkArgs(char **sequence) const
{
    std::string arg;

    for (unsigned int i = 1; sequence[i]; i++)
    {
        arg = sequence[i];
        for (std::string::const_iterator it = arg.begin(); it != arg.end(); ++it)
        {
            if (!std::isdigit(*it))
                throw (PmergeMe::NotADigitException());
        }
    }
}
void PmergeMe::execute()
{
    std::cout << "Before:\t" << this->_vector << '\n';

    double start = _getTime();
    fordJohnsonSort(this->_vector);
    double vectorTime = _getTime() - start;

    start = _getTime();
    fordJohnsonSort(this->_deque);
    double dequeTime = _getTime() - start;

    std::cout << "After:\t" << this->_vector << '\n'
              << "Time to process a range of " << this->_size
              << " elements with std::vector<int>:\t" << std::setprecision(6) << vectorTime * 1000 << " us\n"
              << "Time to process a range of " << this->_size
              << " elements with std::deque<int>:\t" << (float)dequeTime * 1000 << " us" << std::endl;
}
void PmergeMe::_checkDuplicates()
{
    std::set<int> n;

    for (std::vector<int>::iterator it = this->_vector.begin(); it != this->_vector.end(); ++it)
    {
        if (!n.insert(*it).second)
            throw (PmergeMe::DuplicatesException());
    }
}

void PmergeMe::_parseSequence(char **sequence)
{
    int n;

    for (unsigned int i = 1; sequence[i]; i++)
    {
        n = std::atoi(sequence[i]);
        this->_vector.push_back(n);
        this->_deque.push_back(n);
    }
    this->_size = this->_vector.size();
}

double PmergeMe::_getTime() const
{
    struct timeval t;

    gettimeofday(&t, NULL);
    return (t.tv_sec * 1000 + t.tv_usec * 0.001);
}

template <typename U>
void moveElement(U &container, std::size_t from, std::size_t to) {
    // Extraire l'élément à déplacer
    int element = container[from];

    // Supprimer l'élément de la position initiale
    container.erase(container.begin() + from);

    // Insérer l'élément à la nouvelle position
    if (to > from) {
        container.insert(container.begin() + to - 1, element);
    } else {
        container.insert(container.begin() + to, element);
    }
}

template <typename T>
void PmergeMe::fordJohnsonSort(T &container)
{
	typename T::iterator it = container.begin();
	int x = 0;
	for (size_t i = 0; i < container.size() / 2; i++)
	{
		if (*(it + x) > *(it + x + 1))
			std::swap(*(it + x), *(it + x + 1));
		x += 2;
	}
	if (container.size() > 2)
	{
		int y;
		for (size_t i = 2; i < container.size(); i++)
		{
			y = i - 1;
			if (*(it + i) < *(it + y))
			{
				while (y != -1 && *(it + i) < *(it + y))
					y--;
				moveElement(container, i, y + 1);
			}
		}
	}
}

/************************* Stream operator overloads **************************/
std::ostream &operator<<(std::ostream &stream, std::vector<int> &vector)
{
	if (vector.size() < 10)
	{
		for (std::vector<int>::iterator it = vector.begin(); it != vector.end(); ++it)
        	stream << *it << ' ';
	}
	else {
    	std::vector<int>::iterator it = vector.begin();
		for (int i = 0; i < 4 && it != vector.end(); i++, ++it)
			std::cout << *it << " ";
		std::cout << "[...]";}
    return (stream);
}

std::ostream &operator<<(std::ostream &stream, std::deque<int> &deque)
{
    for (std::deque<int>::iterator it = deque.begin(); it != deque.end(); ++it)
        stream << *it << ' ';
    return (stream);
}
