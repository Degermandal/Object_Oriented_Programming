#ifndef EXCEPTION_H
#define EXCEPTION_H
using namespace std;

namespace _shape{

    class Exception : public exception{
    public:
        Exception(){};
        Exception(string str){exc_str = str;}
        virtual const char* what() const throw(){return exc_str.c_str();}

    private:
        string exc_str;
    };
}
#endif
