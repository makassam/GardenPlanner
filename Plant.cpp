// Garden Designer
// OOP244.143 - Assignment 3
// Mohamed Abbas Kassam
// Plant.cpp

#include <iostream>
#include <iomanip>
#include "Plant.h"
#include "Crop.h"
#include "Garden.h"
#include <cstring>
#include <new>
#include<fstream>


Plant::Plant()
{
    pname[0] = '\0';
    symb = ' ';
}
Plant::~Plant() {}

Plant::Plant(const char* name, char sbol)
{
    if ( name != nullptr && strlen (name) <=21 && name[0] != '\0' && ((sbol >= 'A' && sbol) <= 'Z' || (sbol >= 'a' && sbol >= 'z')))
    {
        strcpy(pname , name);
        symb = sbol;
    }
    else
    {
        *this = Plant();
    }
}
bool Plant::isEmpty()const         // Returns true if the object is in a safe empty state, false otherwise
{
    if(pname[0] == '\0' && symb==' ')
    {
        return true;
    }
    else
    {
        return false;
    }
}
// A simple query that returns the symbol of that represents the Plant held by the current object.
char Plant::symbol()const
{

    if (symb != ' ')
        return symb;
}

//void Plant::display()const{
//A display query that displays name and symbol of the Plant held by the current object.
//If the object is in a safe-empty state, nothing is displayed.

//cout << symb << " = " << pname << " ";
//}




/*Update the display query to receive a reference to an ostream object
for use in displaying the current object*/
void Plant:: display(std::ostream& os) const
{
    if(symb !=' ' && pname !='\0')
        os <<symb << " = " << pname << " ";

}

bool Plant::read()
{
    //This function prompts for and accepts a character as well as a string up to 20 characters in length.
    // If the input is unacceptable for any reason, this function clears the stream and asks for input once more.
    //The user must enter valid input or enter "0" as a name to quit.
    //If the user enters "0" as a name, this function does not change the current object and returns false.
    //If input is successfully read in, this function returns true.
    //Neither the name, nor the symbol can be blank.

    //char symb_;
    //char pname_[21];

    std::cout<< "Enter plant symbol: " ;
    std::cin>> symb;

    std::cout<<"Enter plant name: ";
    std::cin >> pname;
    std::cin.ignore();

    return true;
}

const char* Plant::plantName()const //A simple query that returns the name of the Plant held by the current object.
{
    if (pname != '\0')
    {
        return pname;
    }
}

/*A non-friend overloaded operator that receives a reference to an ostream object and a reference to
an unmodifiable Plant object.This function displays the object in the same manner as display(ostream).
This operator allows for cascading*/
std::ostream& operator<<(std::ostream& os , const Plant& p)
{
    p.display(os);
    return os;
}


/* A non-friend overloaded operator that receives two references
to a unmodifiable Plant objects.
This function returns true if both plants are holding the
same information, false otherwise*/


bool operator==(const Plant& p, const Plant& pl)
{
    return p.symbol()== pl.symbol() && strcmp(p.plantName(),pl.plantName())==0 ;


}

/*A query that recieves a reference to an ofstream representing an output file
This function outputs the current object to the file reference provided using the above format.
This function outputs the current Plants information*/
void Plant:: out(std::ofstream& of)const{

    if(of.is_open()){

            of << symb << " " << pname << std:: endl;
    }
}

/*A non-friend helper insertion operator that recieves a reference to an ofstream object as a left hand operand and a
constant reference to a Plant as the right hand operand. This function outputs the current object to the file reference provided
in the same manners as outline for out(std::ostream&). This operator allows for cascading.*/
std::ofstream& operator<<(std::ofstream& of , const Plant& pnt)
{

    pnt.out(of);
    return of;


}



/*A non-friend helper extraction operator that recieves a reference to an ifstream object as a left hand operand and a
reference to a Plant as the right hand operand. This function parses the the file and attempts to reconstructor the object
as described in the file.This function replaces the right hand operand with the result. This operator allows for cascading. */
std::ifstream& operator>>(std::ifstream& fi, Plant& pnt)
{


    char name[21];
    char sm;

    if(fi.is_open()){
        if(fi.good()){
            fi >> sm;
            fi.getline(name , 21);
            pnt = Plant(name , sm);
        }
    }

    return fi;

}


