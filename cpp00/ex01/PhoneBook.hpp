#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iomanip>
# define MAX_CONTACTS 8

class PhoneBook
{
private:
    Contact contacts[MAX_CONTACTS];
    int head;
    int count;

public:
    PhoneBook() : head(0), count(0) {}
    ~PhoneBook();
    void add_contact(Contact);
	void view_contacts();
	void view_single_contact(int);
	bool index_invalid(int);
    int get_count();

};

// static std::string trunc_if_long(std::string);

#endif