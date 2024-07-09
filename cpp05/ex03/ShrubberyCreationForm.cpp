/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnie <mnie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 16:21:58 by mnie              #+#    #+#             */
/*   Updated: 2024/07/07 18:28:13 by mnie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

// constructors and destructor
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
	AForm("ShrubberyCreationForm", 145, 137), _target(target){}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : 
	AForm(copy) {}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

// Overloaded operation
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	AForm::operator=(src);
	return (*this);
}

// member function
void ShrubberyCreationForm::action() const{
    std::string outfile_name = this->_target+"_shrubberry";
	std::ofstream outfile(outfile_name.c_str());
	if (!outfile.is_open())
	{
		std::cerr << RED << "Error to open outfile" << RESET << std::endl;
		exit(1);
	}
	const std::string tree =
		"	                                     #######,*                               \n"
		"                          /#############%%%####% ###                            \n"
		"                        ########%%%%%%%#######%%%####%########/#                \n"
		"          .*            ###%%%%%%%%####%%####%%%%%%#######%%%##.##(             \n"
		"         /######** #%## (######%%%%%%##%%%%%%%%%%%####%#%%%%%##%%#######        \n"
		"       /####%#%%%%################%%%##%%%%%##%#%%%###%%%%%%%%%%%%%%%##         \n"
		"      ,,##%%#%%%#####%%%%%%%%%%%%#########%###%############%%%#%%%##%%%         \n"
		"    *###%#%%%#%%######%%%%%%%%%%###%%%%%%%%%%%%%%%%%%%%%###%%%%%%%%######       \n"
		"      ####%%#%%%%%#####%%%%%%%%%&#%%%%%%####%%%%%%%%#######%%%%%%%%%#######     \n"
		"   (############%%%####%%%%#####%##%%#%##%%%###%%%%%%%########%###%###%%%%###   \n"
		" #######%%%%%%%%%%%%#########%%%%#####%%%%%%%#%#%%%%###%%%%%%%%######%%%####.   \n"
		" #####%%&%%%%%%%####%%%%%#####%%%%#%%%%%%%%%%%%%%%%%###%%%%%%%%%%%####%#%##     \n"
		" #.####&&&&%&%%%#%#%%%%%%%##%%%%%%%%%%%%%%%%%%%%%#&##%%#%%%%%%%%%%%&%%%%%%%##   \n"
		"  ,#####%&&&%%&%%###%%%#%%#%###%##%%%%%%%%%&%%%%%%%&%&&&%%%%%%%%%%%%%%%######## \n"
		"     #######&%%&&%&#####%%%%%%%%%%%%%%%%%%%%%%%%%%&&&&&&&&&%%%%%%%%%%&%#%%%%### \n"
		"      ###&&&&&&&&&&&&&&%###&#&%%%%%&&&&&&&&&&%%%%&%&%%%%%%&&&&&&&&&&&%%%%%%#####\n"
		"      / # ##&&&&&&&%&&&&&&%%#&&&&&&&%&&&&&&&##&&&&&&&&&&&&&&&%##%%%#%%%%######/ \n"
		"           (((###%%%%%%%%%&&%%%&&&&&&%&&&&&&&&##%%%&&&&&&&&&&%%%%%###(#         \n"
		"                ##%%%##%%#%%&&&&%&&&%&%&&&&&&%%&%%&&&&&&&%%%%#######            \n"
		"                           /%%%&%&&%%&&&%&&%&&&&&&@%,#   ..#,   .               \n"
		"                              /&%&&%%%&%&&&%%&&&                                \n"
		"                                &#&% #%%%%&%&&&                                 \n"
		"                                 %&%&&%%%&&&&&                                  \n"
		"                                    &%%%&&&&%&,                                 \n"
		"                                     %&%&%%%&&&                                 \n"
		"                                     &%#%%%&&%&                                 \n"
		"                                     &%#%%&&&&&                                 \n"
		"                                     %%%&%%&&&&                                 \n"
		"                                    %%%&%%&%&&&&%                               \n"
		"                                   %%%%%&%&%&&&&&&                              \n"
		"                                  #%%&%%%%%&&&&&&&&                             \n"
		"                                %%&%%%&#&&&%&&&&&&&&&%                          \n"
		"                           %%%%%&%%&&&%&&&&&&&&&/*,,,,....                      \n";
	outfile << tree;
	outfile.close();
	std::cout << "Tree planted in " << this->_target << RESET << std::endl;
}