#ifndef EXCEPTION_H_
#define EXCEPTION_H_

#include <iostream>
#include <string>

using namespace std;

namespace _collection {

class Exception: public exception{
    public:
        Exception(){};
        Exception(string sentence){exp_str = sentence;}
        virtual const char* what() const throw(){return exp_str.c_str();} 

    private:
        string exp_str;
    };

} /* namespace _collection */
#endif /* EXCEPTION_H_ */

