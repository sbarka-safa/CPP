#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void ) : _energy_points(50) , _hit_points(100) , _attack_damage(20){
    //default constructor
    std::cout << BOLDGREEN << "Default constructor called from ClapTrap" << "\033[0m"  << std::endl;
}

//ClapTrap::ClapTrap(int energy_points, int hit_points, int attack_damage)
ClapTrap::ClapTrap(std::string name) : _name(name) , _energy_points(50) , _hit_points(100) , _attack_damage(20) {
    std::cout << BOLDGREEN << "Parametric constructor called from ClapTrap" << "\033[0m" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & src)
{
    std::cout << BOLDGREEN <<  "Copy constructor called from ClapTrap" << "\033[0m" << std::endl;
    *this = src;
}

ClapTrap::~ClapTrap( void )
{
    std::cout << BOLDRED << "Destructor called from ClapTrap" << "\033[0m" << std::endl;
}

ClapTrap & ClapTrap::operator = (ClapTrap const &cpy ){
    std::cout << BOLDYELLOW << "operator overload (=) " <<  "\033[0m" << std::endl;
    if(this != &cpy)
    {
        this->_name = cpy.getName();
        this->_hit_points = cpy.getHitPoints();
        this->_attack_damage = cpy.getAttackDamage();
        this->_energy_points = cpy.getEnergyPoints();
    }
    return *this;
}
std::ostream &operator << (std::ostream & o , ClapTrap &clapTrap){
    std::cout << BOLDYELLOW << "operator overload (<<) " <<  "\033[0m" << std::endl;
    std::cout << "-------------------" << std::endl;
    o << "Name                  : " << clapTrap.getName() << std::endl;
    o << "Energy points         : " << clapTrap.getEnergyPoints() << std::endl;
    o << "Hit points            : " << clapTrap.getHitPoints() << std::endl;
    o << "Attack damage         : " << clapTrap.getAttackDamage() << std::endl; 
    std::cout << "--------------------" << std::endl;
    return o;
}

std::string ClapTrap::getName( void ) const
{
    return this->_name;
}

int         ClapTrap::getHitPoints( void ) const
{
    return this->_hit_points;
}

int          ClapTrap::getEnergyPoints( void ) const
{
    return this->_energy_points;
}

int        ClapTrap::getAttackDamage( void ) const
{
    return this->_attack_damage;
}

void        ClapTrap::attack( std::string const & target ){
    std::cout << "FR4G-TP " << "<" << this->getName() << "> " ;
    std::cout << "attacks " << "<" << target << "> , ";
    std::cout << "causing " << "<" << this->getAttackDamage() << "> ";
    std::cout << "points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    //this->_attack_damage+=amount;
    std::cout << "FR4G-TP " << "<" <<  this->getName() << "> " ;
   // std::cout << "causing " << "<" << this->getAttackDamage() << "> ";
   std::cout << "causing " << "<" << amount << "> ";
    std::cout << "points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    this->_attack_damage-=amount;
    std::cout << "FR4G-TP " << "<" <<  this->getName() << "> " ;
    std::cout << "repairing " << "<" << amount << "> ";
    std::cout << "points of damage!" << std::endl;
}