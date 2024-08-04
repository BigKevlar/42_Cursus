#include "Contact.hpp"

Contact::Contact()
{}

Contact::Contact(std::string fname, std::string lname, std::string nick, std::string phone, std::string secret)
{
    _first_name = fname;
    _last_name = lname;
    _nick_name = nick;
    _phone_number = phone;
    _darkest_secret = secret;
}

Contact::~Contact()
{}

std::string Contact::get_first_name() const {
    return (_first_name);
}

void Contact::set_first_name(const std::string fname) {
    _first_name = fname;
}
