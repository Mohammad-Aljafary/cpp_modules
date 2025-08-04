#include "ClapTrap.hpp"

int main()
{
    ClapTrap enemy("Jack");
    ClapTrap enemy2("Tom");
    enemy2 = enemy; 
    ClapTrap enemy3(enemy);

    enemy.attack("Here");
    enemy2.attack("LOL");
    enemy3.attack("FOOL");

    enemy.beRepaired(5);
    enemy2.beRepaired(7);
    enemy3.beRepaired(9);

    enemy.takeDamage(5);
    enemy2.takeDamage(7);
    enemy3.takeDamage(9);

    return (0);
}