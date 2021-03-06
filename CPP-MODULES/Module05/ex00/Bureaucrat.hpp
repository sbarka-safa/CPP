#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

#include <string>
#include <iostream>


class Bureaucrat {
    private :
        /* it must have a constant name  */
        std::string const _name;
        /* it must have a grade that ranges from 1 (highest possible)  to 150 (lowest possible) */
        int _grade;
        Bureaucrat( void );                 /* canonical */

    public :
        Bureaucrat( Bureaucrat const & src); /* canonical */
        Bureaucrat( std::string const & name , int grade);
        Bureaucrat & operator = (Bureaucrat const & src); /* canonical */
        ~Bureaucrat( void );                               /* canonical */
    
        /* You will provide getters for both these attributes (getName and getGrade) */
        std::string const & getName() const;
        int  getGrade() const;
        /*
            and two functions to increment or decrement the grade
        */
        void increment( void );
        void decrement( void );

    
        /*
            Any attempt to create a Bureaucrat with an invalid grade must throw 
            an exception,
            which will be either a Bureaucrat::GradeTooHighException or
            a Bureaucrat::GradeTooLowException.
        */
        class GradeTooHightException : public std::exception{
           public :
               virtual const char *what() const throw();
        };

        class GradeTooLowException : public std::exception{
            public :
               virtual const char *what() const throw();
        };
   
};

std::ostream & operator << (std::ostream  & o , Bureaucrat const & bureaucrat);
#endif