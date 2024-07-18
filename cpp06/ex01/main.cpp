#include "Serializer.hpp"

int main()
{
	// Serializer serial;
	Data data = {0, 42.0f};
	Data* data_ptr = &data;


	std::cout << GREEN << "data_ptr->int_nb = " << RESET << data_ptr->int_nb << std::endl;
	std::cout << GREEN << "data_ptr->fl_nb = " << RESET << data_ptr->fl_nb << std::endl;
	std::cout << std::endl;
	std::cout << BLUE << "Data* data_ptr = " << RESET << data_ptr << std::endl;
	uintptr_t int_ptr = Serializer::serialize(data_ptr);
	std::cout << BLUE << "uintptr_t int_ptr = " << RESET << int_ptr << std::endl;
	Data* reinit = Serializer::deserialize(int_ptr);
	std::cout << BLUE << "Data* reinit = " << RESET << reinit << std::endl;
	std::cout << std::endl;
	std::cout << GREEN << "reinit->int_nb = " << RESET << reinit->int_nb << std::endl;
	std::cout << GREEN << "reinit->fl_nb = " << RESET << reinit->fl_nb << std::endl;

	return 0;
}