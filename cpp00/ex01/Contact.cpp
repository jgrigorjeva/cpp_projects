#include "Contact.hpp"

Contact::Contact(std::string first_name, std::string last_name, std::string nick, 
			std::string phone_number, std::string secret)
{
    this->first_name = first_name;
    this->last_name = last_name;
    this->nick = nick;
    this->phone_number = phone_number;
    this->secret = secret;
    // contact_count++;
}

Contact::~Contact()
{
    // contact_count--;
}

std::string Contact::get_fn()
{
    return (first_name);
}

std::string Contact::get_ln()
{
    return (last_name);
}
std::string Contact::get_nick()
{
    return (nick);
}
std::string Contact::get_phone()
{
    return (phone_number);
}
std::string Contact::get_secret()
{
    return (secret);
}