#include "TacticalMarine.hpp"


TacticalMarine:: TacticalMarine( void ){
    std::cout << "Tactical Marine ready for battle!" << std::endl;
}

 TacticalMarine::~ TacticalMarine( void ){
    std::cout << "Aaargh..." << std::endl;
}

 TacticalMarine::TacticalMarine( TacticalMarine const & src){
    *this = src;
}

 TacticalMarine const &  TacticalMarine::operator = ( TacticalMarine const & src){
     std::cout << "overload AssaultTerminator" << std::endl;
    return src;
}

ISpaceMarine *  TacticalMarine::clone() const {
    return new TacticalMarine(*this);
}

void  TacticalMarine::battleCry() const {
    std::cout << "For the holy PLOT!" << std::endl;
}

void  TacticalMarine::rangedAttack() const {
    std::cout << "* attacks with a bolter *" << std::endl;
}

void  TacticalMarine::meleeAttack() const {
    std::cout << "* attacks with a chainsword *" << std::endl;
}