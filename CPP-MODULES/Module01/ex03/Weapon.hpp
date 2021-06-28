#ifndef WEAPON_H
# define WEAPON_H
#include <string>
#include <iostream>

class Weapon {

    public :
        Weapon( std::string  type );
        ~Weapon( void );
        Weapon( void );
        std::string const &  getType( void ) const;
        void setType( std::string const  & type);
        
    private:
        std::string  _type;
        
};

#endif