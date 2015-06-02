// Garden Designer
// OOP244.143 - Assignment 3
// Mohamed Abbas Kassam
//Garden.cpp



#include <iostream>
#include <iomanip>
#include "Plant.h"
#include "Crop.h"
#include "Garden.h"
#include <cstring>
#include <new>
#include<fstream>


/*A no argument constructor that sets the object in a safe-empty state.*/
Garden::Garden()
{
    cur_crop = 0;
    map = nullptr;
    l_row = 0;
    w_col = 0;
}


/*Two argument constructor that receives two integers represents the length and width of the Garden.
If either number is invalid (negative) the object adopts a safe empty state, otherwise the map is
dynamically allocated based on the dimensions provided and initialized so that every index is holding ' '.*/
Garden::Garden(int gl, int gw)
{
    if(gl>0 && gw >0)
    {
        l_row= gl;
        w_col = gw;
        cur_crop = 0;
        map = new char[l_row*w_col];
        for (int i=0 ; i < l_row*w_col; i++)
            map[i] = ' ';

    }
    else
    {
        map = nullptr;
        *this = Garden();
    }
}


/*A copy constructor that copies an existing object into a newly created object.
This function performs both a shallow and deep copy*/
Garden::Garden(const Garden& gr)
{
    if(gr.map!=nullptr)
    {
        cur_crop = gr.cur_crop;
        l_row = gr.l_row;
        w_col = gr.w_col;

// allocate dynamic memory
        map = new char[l_row * w_col];
        for(int i=0; i<(l_row * w_col); i++)
        {
            map[i] = gr.map[i];
        }

    }
}

/*An assignment operator that copies an existing objecting into another existing object.
This function performs both a shallow and deep copy while preventing memory leaks*/
Garden& Garden:: operator=(const Garden& gr)
{
    if(this != &gr)
    {

        cur_crop = gr.cur_crop;
        l_row = gr.l_row;
        w_col = gr.w_col;

        for(int i =0; i <cur_crop;i++){

            crps[i] = gr.crps[i];
        }

   // delete [] map;
   if (gr.map != nullptr)
    {

       map = new char[strlen(gr.map) + 1];
       strcpy(map,gr.map);
    }
      else
      {
          map = nullptr;
      }
    }
    return *this;
}

/*A destructor that returns any dynamically allocated memory to the operatings system when the object goes out of scope.*/
Garden::~Garden()
{
    delete [] map ;
}


/*A simple query that returns the state of the current object.
Returns true if the object is in a safe empty state, false otherwise */
bool Garden:: isEmpty()const
{
    if( map == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}


/*An append operator that adds a single crop to the Garden.
This member operator receives a reference to a crop. If the crop is valid, and there is room in the list for another crop, the
crop is added to the garden and the map is updated. If there is already another crop located at the same postion on the map,
the new crop takes precidence.(overwrites)*/
Garden& Garden:: operator+=(const Crop& cp)
{
    if (!cp.isEmpty() && cur_crop < MAX_CROPS)
    {
        if(cp.place(map, l_row,w_col)){

           crps[cur_crop] = cp;
           cur_crop++;

           }
    }
    return *this;
}


/*A display query to receive a reference to an ostream object for use in displaying the current object.*/
void Garden::display(std::ostream& os) const
{
    int i , j , k;
    os << "+";
    for(i=0; i<w_col; i++)
        os << "-";
    os << "+" << std::endl;
    for(j =0 ; j <l_row*w_col ; j=j+w_col)
    {
        os << "|";
        for (k =j ; k< j + w_col ; k++)
        {
            os << map[k];
        }
        os << "|"<<std::endl;
    }
    os << "+";
    for(i=0; i<w_col; i++)
        os << "-";
    os << "+"<<std::endl;
}




/*A non-friend overloaded operator that receives a reference to an ostream object and a reference to an unmodifiable Garden object.
This function displays the object in the same manner as display(ostream). This operator allows for cascading*/
std::ostream& operator<<(std::ostream& os , const Garden& gr)
{
    if(!gr.isEmpty())
        gr.display(os);
    return os;
}

/*A query that recieves a reference to an ofstream representing an output file.
    This function outputs the current object to the file reference provided using the above format.
    This function primarily focuses on the first line and controlling how many additional line are written.
    For the 2nd line on, it calls the appropriate Crop function.*/
    void Garden:: out(std::ofstream& of)const{
    if (of.is_open())
    {
        of << cur_crop << " " << l_row << " " << w_col << std:: endl;
        for (int i =0 ; i < cur_crop; i++)
        {
            crps[i].out(of);

        }
    }
    }

    /*A one argument constructor that receives a c-style string representing the name of a file.
      This function opens the file provided and constructs the object must in the same manner as described in the
      extraction operator described above. If, for whatever reason, the file name is invalid, or
      the file cannot be opened, the object adopts a safe empty state. */
Garden::Garden(const char* file)
    {

        if(file != nullptr && strlen(file)>0 )
        {
            std::ifstream fi (file);
            if(fi.is_open())
            {
                map = nullptr;
                fi >> *this;
            }
            else
            {
                map = nullptr;
                *this = Garden();
            }

        }

        else
        {
            map = nullptr;
            *this = Garden();
        }

    }


/*A non-friend helper insertion operator that recieves a reference to an ofstream object as a
left hand operand and a constant reference to a Garden as the right hand operand.
This function outputs the current object to the file reference provided in the same manners as outline for out(std::ostream&).
This operator allows for cascading.*/
std::ofstream& operator<<(std::ofstream& of, const Garden& gr)
{
/*
    if (of.is_open())
    {
        of << gr.cur_crop << "" << gr.l_row << "" << gr.w_col << std:: endl;
        for (i =0 ; i < cur_crop; i++)
        {
            gr.crps[i].out(of);

        }
*/
        gr.out(of);
        return of;

    }


/*A non-friend helper extraction operator that recieves a reference to an ifstream object as a left hand operand and a
reference to a Garden as the right hand operand.This function parses the the file and attempts to reconstructor the object
as described in the file. Similar to the insertion operator, this function primarily focus on reading the
first line and controlling how many additional lines are read. This function replaces the right hand operand with the result.
This operator allows for cascading. */
std::ifstream& operator>>(std::ifstream& fi, Garden& gr){

int c_crp;
int g_length;
int g_width;

    if(fi.is_open()){
       if(fi.good()){
        fi >> c_crp >> g_length >> g_width;
            Garden temp(g_length , g_width);
            gr = temp;
            for(int i = 0; i < c_crp ; i++){
                Crop cp;
                fi >> cp;
                gr+= cp;
            }
       }

       }

return fi;
}


/*A no argument constructor that sets the object in a safe-empty state.*/
DetailedGarden::DetailedGarden(){

    desc = nullptr;

}


/* Destructor */
DetailedGarden::~DetailedGarden(){
    desc = nullptr;
    delete [] desc;


}

/* Assignment Operator */
DetailedGarden& DetailedGarden::operator=(const DetailedGarden& src)
{

    if(this != &src)
    {

        Garden&  gdr = *this;
        gdr = src;
        delete [] desc;

        if(src.desc !=nullptr)
        {
            desc = new char[strlen(src.desc)+1];
            strcpy(desc,src.desc);
        }
        else
        {

            desc =nullptr;
        }
    }
    return *this;

}

DetailedGarden :: DetailedGarden(const DetailedGarden& src){

    desc = nullptr;
    *this = src;

}
/*Three argument constructor that receives a
c-style null terminated string, as well as two integers represents the length and width of the Garden.
If the base is set to a safe empty state, or description is missing (null), the object will adopt a safe empty state.*/
DetailedGarden::DetailedGarden(const char* gr_desc,int len, int wid) : Garden(len , wid)
{
    if(gr_desc != nullptr && strlen(gr_desc)>0)
    {

        desc = new char[strlen(gr_desc) + 1];
        strcpy(desc , gr_desc);

    }
    else {
        desc = nullptr;
        *this = DetailedGarden();
    }
}


/*A simple query that returns the state of the current object.Returns true if the object is in a safe empty state,
false otherwise */
bool DetailedGarden:: isEmpty()const
{
if ( desc == nullptr && Garden::isEmpty()){
    return true;
}
else {
      return false;
}


}



/*A display query to receive a reference to an ostream object for use in displaying the current object.
This function displays the map of the garden through the ostream object provided in the following format followed by the detailed description
*/
void DetailedGarden::display(std::ostream& os)const
{
    Garden::display(os);
    os << desc << std::endl;

}
