#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

int main() {
    // Create a MateriaSource and learn some Materias
    MateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    // Create a Character
    ICharacter* me = new Character("me");

    // Create Materias and equip them
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    // Create another Character and use Materias
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);

    // Clean up
    delete bob;
    delete me;
    delete src;

    return 0;
}