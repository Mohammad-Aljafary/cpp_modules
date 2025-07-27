#include "Harl.hpp"

void Harl::debug(void) {
    std::cout << "[DEBUG]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info(void) {
    std::cout << "[INFO]" << std::endl;
    std::cout << "  I cannot believe adding extra bacon costs more money. You didn’t put "
              << "enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void) {
    std::cout << "[WARNING]" << std::endl;
    std::cout << "  I think I deserve to have some extra bacon for free. I’ve been coming for "
              << "years, whereas you started working here just last month." << std::endl;
}

void Harl::error(void) {
    std::cout << "[ERROR]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}


void Harl::complain(std::string level) {

    int index = 0;
    std::string numLevels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harl::*fun[])(void) = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };

    for (int i = 0; i <= 4; i++) {
        if (i != 4 && level == numLevels[i]) {
            index = i;
            break;
        }
        index = i;
    }

    switch (index)
    {
        case DEBUG:
            (this->*fun[DEBUG])();
            // fallthrough
        case INFO:
            (this->*fun[INFO])();
            // fallthrough
        case WARNING:
            (this->*fun[WARNING])();
            // fallthrough
        case ERROR:
            (this->*fun[ERROR])();
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
            break;
    }
    
}
