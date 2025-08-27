#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <limits>
#include "Color.hpp"

void	get_contact_info(std::string contact_info[]);
bool handle_cin_errors(std::string &try_again, int contact_ID, PhoneBook book);

int main()
{
	std::string action;
	std::string contact_info[5];
	int contact_ID;
	Contact 	contact;
	PhoneBook	book;

    while (1)
    {
        std::cout << Color::bblue << "Type command: ADD | SEARCH | EXIT" << std::endl << "> " << Color::reset;
		std::getline(std::cin, action);
		std::cout << std::endl;
		if (action == "EXIT")
			return (0);
		if (action == "ADD")
		{
			get_contact_info(contact_info);	
			contact = Contact(contact_info[0], contact_info[1], contact_info[2], contact_info[3], contact_info[4]);
			book.add_contact(contact);
		}
		if (action == "SEARCH")
		{
			book.view_contacts();
			std::string try_again = "yes";
			while (try_again == "yes")
			{
				try_again = "no";
				std::cout << Color::bgreen << "Enter contact ID to view details:" << std::endl << "> " << Color::reset;
				std::cin >> contact_ID;
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //remove leftover newline
				if (handle_cin_errors(try_again, contact_ID, book))
					continue;
				else					
					book.view_single_contact(contact_ID);
			}
		}	
    }
}

void	get_contact_info(std::string contact_info[])
{
	std::string prompt_part[] = {"first name", "last name", "nick name", "phone number", "darkest secret"};

	for (int i = 0; i < 5; i++)
	{
		std::cout << Color::bgreen << "Insert contact " << prompt_part[i] << std::endl << "> " << Color::reset;
		std::getline(std::cin, contact_info[i]);
	}
	std::cout << std::endl;
}

bool handle_cin_errors(std::string &try_again, int contact_ID, PhoneBook book)
{
	if (std::cin.fail())
	{
		std::cin.clear(); // clear fail state
		std::cin.ignore(1000, '\n'); // discard bad input
		std::cout << Color::bred << "Contact ID is invalid, try again? yes/no" << std::endl << "> " << Color::reset;
		std::cin >> try_again;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //remove leftover newlines
		return (1);
	}
	else if (book.index_invalid(contact_ID))
	{
		std::cout << Color::bred <<"Contact ID is invalid, try again? yes/no" << std::endl << "> " << Color::reset;
		std::cin >> try_again;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //remove leftover newlines
		return (1);
	}
	return (0);
}