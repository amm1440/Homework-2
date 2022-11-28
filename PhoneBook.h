// header file for Phonebook class
#ifndef PHONEBOOK_H
#define PHONE_BOOK_H
#include <string>
#include <string.h>




class PhoneBook
{

    public:
        void run();

    private:
        bool fileCheck(std::string);
        bool searching(std::string, std::string, int);


};

#endif
