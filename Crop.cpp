// Garden Designer
// OOP244.143 - Assignment 3
// Mohamed Abbas Kassam
//Crop.cpp




#include <iostream>
#include <iomanip>
#include "Plant.h"
#include "Crop.h"
#include "Garden.h"
#include<new>
#include<fstream>




/* Safe empty state*/
Crop::Crop()
{
    length = 0;
    width = 0;
    x_c = 0;
    y_r = 0;
}

Crop::~Crop() {} //Destructor

/*The Plant object must not be empty
and the length and width both must be positive, but not so large as to push the crop beyond the bounds of the garden.*/



/*You do not need to validate length and width.
the Three-argument constructor becomes a five-argument constructor, receiving two
additional integers representing the x and y starting location of the crop.
If all parameters are valid, this function accepts the data.
Otherwise, this constructor leaves the object in a safe empty state.
assuming that the x and y coordinates are positive values, the crop will fit within the garden.
Added two more intergers below updated function*/
Crop::Crop(const Plant& pl, int l, int wi, int x , int y)
{

    if(l > 0 && wi > 0 && !pl.isEmpty() && x >= 0 && y >=0)
    {
        plant=pl;
        length = l;
        width = wi;
        x_c = x;
        y_r = y;
    }
    else
    {
        *this = Crop();
    }
}

bool Crop::isEmpty()const
{
    if(plant.isEmpty() && width == 0 && length == 0 )
    {
        return true;
    }
    else
    {
        return false;
    }
}


/*Update the display query to receive a reference to an ostream object
for use in displaying the current object.*/

void Crop::display(std::ostream& os) const
{

    char x = plant.symbol();
    if ( x!='\0' && width != 0 && length !=0)
    {
        int i , j ;
        for( i =0 ; i < length; i++)
        {
            for (j =0 ; j < width; j++)
                os<< plant.symbol();
            os<<std::endl;
        }
        plant.display(os);
    }


}
/*Returns true or false updated from assignment 1*/
bool Crop::read(const Plant& p)
{
    int len, wid, x,y;
    do
    {
        std::cout << "Enter crop length: ";
        std::cin >> len;
        length = len;
        if(len==0)
        {
            return false;
        }
        else if(len < 0 )
        {
            std::cout << "Enter a valid input" <<std::endl;
        }
        else
        {
            std::cout << "Enter crop width: ";
            std::cin >> wid;
            std::cin.ignore();
            std::cout <<"Enter x: ";
            std::cin>> x;
            std::cout <<"Enter y: ";
            std::cin>> y;
            width = wid;
            plant = p;
            x_c  = x;
            y_r = y;
        }
        if (wid ==0)
            return false;
        else if (wid < 0)
            std::cout << "Enter a valid input" << std::endl;
        else
        {
            return true;
        }
    }
    while (len < 0 && wid < 0);
}
 /*A non-friend overloaded operator that receives a reference to an ostream object and a
    reference to an unmodifiable Crop object.*/
std::ostream& operator<<(std::ostream& os, const Crop& cp)
{

    if(!cp.isEmpty())
    {
        cp.display(os);
        return os;
    }

}
/*If any of the following, the map is NOT updated, and the function returns false:
the function receives incorrect parameters Object is in a safe empty state
Crop will not fit on map using the provided col/row
Otherwise the map is updated and the function returns true*/
bool Crop::place(char * map,int l_row, int x_col)const
{
    int i;
    int j;
    if (map == nullptr || x_c + width > x_col || y_r + length > l_row || isEmpty() || l_row < 0 || x_col < 0)
    {

        return false;
    }
    else
    {
        for(i= y_r * x_col + x_c ; i < x_col*(y_r+length) ; i=i+x_col)
        {
            for(j=i; j<width+i ; j++)
            {
                map [j] = plant.symbol();
            }

        }
        return true;
    }


}

/*A query that recieves a reference to an ofstream representing an output file
This function outputs the current object to the file reference provided using the above format.
This function outputs the current Crops information and passes on to the Plant's function.*/
void Crop:: out(std::ofstream& of)const{
   if(of.is_open())
    {
        of << length << " " << width << " " << x_c << " "  <<y_r <<" ";
        plant.out(of);
    }
}



/*A non-friend helper insertion operator that recieves a reference to an ofstream object as a left hand operand
and a constant reference to a Crop as the right hand operand.
This function outputs the current object to the file reference provided in the same manners as outline for out(std::ostream&).
This operator allows for cascading.*/
std::ofstream& operator<<(std::ofstream& of, const Crop& c)
{
    c.out(of);
    return of;
}



/*A non-friend helper extraction operator that recieves a reference to an ifstream object as a left hand operand and a
reference to a Crop as the right hand operand.This function parses the the file and attempts to reconstructor the object as described in the file. Similar to the insertion operator, this function primarily focus on reading in the Crop information.
This function replaces the right hand operand with the result. This operator allows for cascading. */
std::ifstream& operator>>(std::ifstream& fi, Crop& c)
{

    int lgth;
    int wdth;
    int xx;
    int yy;
    Plant pn;

    if(fi.is_open())
{
    if(fi.good())
        {
        fi >> lgth>> wdth >> xx >> yy;
            fi >> pn;
            c = Crop(pn , lgth , wdth , xx , yy);
        }
    }
return fi;
}


