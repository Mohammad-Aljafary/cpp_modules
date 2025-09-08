# include "Contact.hpp"

void Contact::setFirstName(std::string str) {
	this->firstName = str;
}
void Contact::setLastName(std::string str) {
	this->lastName = str;
}
void Contact::setNickName(std::string str) {
	this->nickName = str;
}
void Contact::setPhoneNumber(std::string str) {
	this->phoneNumber = str;
}
void Contact::setDarkestSecret(std::string str) {
	this->darkestSecret = str;
}
std::string Contact::getFirstName() const {
	return this->firstName;
}
std::string Contact::getLastName() const {
	return this->lastName;
}

std::string Contact::getNickName() const {
	return this->nickName;
}
std::string Contact::getPhoneNumber() const {
	return this->phoneNumber;
}

std::string Contact::getDarkestSecret() const {
	return this->darkestSecret;
}
