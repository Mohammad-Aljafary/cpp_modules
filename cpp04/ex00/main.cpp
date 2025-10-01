#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main (){
    const Animal *meta = new Animal();
    const Animal *dog = new Dog();
    const Animal *cat = new Cat();
    const WrongAnimal *wrong_cat = new WrongCat();
    const WrongCat *wrong_cat2 = new WrongCat();
    

    std::cout << dog->getType() << " " << std::endl;
    std::cout << cat->getType() << " " << std::endl;
    std::cout << wrong_cat->getType() << " " << std::endl;
    dog->makeSound();
    cat->makeSound();
    meta->makeSound();
    wrong_cat->makeSound();
    wrong_cat2->makeSound();

    delete meta;
    delete dog;
    delete cat;
    delete wrong_cat;
    delete wrong_cat2;
    return 0;
}
