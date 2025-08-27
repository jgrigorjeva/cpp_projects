#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class Contact
{
    private:
        std::string first_name;
		std::string last_name;
		std::string nick;
		std::string phone_number;
		std::string secret;
		// static int contact_count;
	public:
		Contact(){};
		Contact(std::string first_name, std::string last_name, std::string nick, 
			std::string phone_number, std::string secret);
		~Contact();
		std::string get_fn();
		std::string get_ln();
		std::string get_nick();
		std::string get_phone();
		std::string get_secret();

};

#endif