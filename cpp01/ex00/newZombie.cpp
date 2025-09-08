# include "Zombie.hpp"


Zombie* newZombie( std::string name )
{ 
    Zombie *temp = new (std::nothrow) Zombie(name);
    if (!temp) {
        std::cerr << "Memory allocation failed" << std::endl;
        return NULL;
    }
    return temp;
}
