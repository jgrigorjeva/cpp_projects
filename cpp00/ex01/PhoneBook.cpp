#include "Contact.hpp"
#include "PhoneBook.hpp"

PhoneBook::~PhoneBook()
{
}

void PhoneBook::add_contact(Contact c)
{
    if (c.info_not_filled())
    {
        std::cout << "Not all contact details have been filled, contact not added\n";
        return ;
    }
    int pos = (head + count)% MAX_CONTACTS;
    contacts[pos] = c;
    if (count < MAX_CONTACTS)
        count++;
    else
        head = (head + 1) % MAX_CONTACTS;
    std::cout << "Contact added" << std::endl;
}

static std::string trunc_if_long(std::string);

void PhoneBook::view_contacts()
{
    int pos;
    for (int i = 0; i < count; i++)
    {
        pos = (head + i) % MAX_CONTACTS;
        std::cout << std::right << std::setw(10) << i << "|" 
        << std::setw(10) << trunc_if_long(contacts[pos].get_fn()) << "|"
		<< std::setw(10) << trunc_if_long(contacts[pos].get_ln()) << "|" 
		<< std::setw(10) << trunc_if_long(contacts[pos].get_nick())
		<< std::endl;
    }
    
}

void PhoneBook::view_single_contact(int contact_ID)
{
	int pos = (head + contact_ID) % MAX_CONTACTS;
	std::cout << std::left << std::setw(16) << "First name: " << contacts[pos].get_fn() << std::endl;
	std::cout << std::left << std::setw(16) << "Last name: " << contacts[pos].get_ln() << std::endl;
	std::cout << std::left << std::setw(16) << "Nick name: " << contacts[pos].get_nick() << std::endl;
	std::cout << std::left << std::setw(16) << "Phone number: " << contacts[pos].get_phone() << std::endl;
	std::cout << std::left << std::setw(16) << "Darkest secret: " << contacts[pos].get_secret() << std::endl;
	std::cout << std::endl;
}

bool PhoneBook::index_invalid(int contact_ID)
{
	return (contact_ID < 0 || contact_ID > count - 1);
}

static std::string trunc_if_long(std::string str)
{
    if (str.length() <= 10)
        return (str);
    else
    {
        return (str.substr(0, 9) + ".");
    }
}

int PhoneBook::get_count()
{
    return (count);
}