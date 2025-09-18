# include "Weapon.hpp"

const std::string& Weapon::getType() const
{
	return this->type;
}

void Weapon::setType(const std:: string& type )
{
    this->type = type;
}

Weapon::Weapon(std:: string type){
    this->type = type;
}

Weapon::Weapon(){

}
