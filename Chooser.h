
#ifndef CHOOSER_H
#define CHOOSER_H

#include "Computer.h"
#include <iostream>
#include <string>

using namespace std;
enum choice{which};

class Chooser
{
    public:
    virtual int get_choice() = 0; 
    void setChoice (int c)
    {
        choice = c;
    }
    
    protected:
    int choice;   
};

class RandomChooser: public Chooser
{
    public:
        int get_choice()
        {
            return choice; 
        }
};

class MachineLearningChooser: public Chooser
{
    public:
        int get_choice()
        {
            return choice;
        }
};  

#endif /* CHOOSER_H */

