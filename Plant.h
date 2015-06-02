// Garden Designer
// OOP244.143 - Assignment 3
// Mohamed Abbas Kassam
// Plant.h

class Plant
{
    char pname[21];
    char symb;

public:
    Plant(); //put this in plan.cpp
    ~Plant();
    Plant(const char* p, char s); //put this in plant.cpp using *this plant()
    bool isEmpty()const;  // Returns true if the object is in a safe empty state, false otherwise
    char symbol()const; // A simple query that returns the symbol of that represents the Plant held by the current object.

    bool read();
    const char* plantName()const; //A simple query that returns the name of the Plant held by the current object.

    //void display()const; //A display query that displays name and symbol of the Plant held by the current object.
    //If the object is in a safe-empty state, nothing is displayed.
    void display(std::ostream&)const;//Update the display query to receive a reference to an ostream object
    //for use in displaying the current object


/*A query that recieves a reference to an ofstream representing an output file
This function outputs the current object to the file reference provided using the above format.
This function outputs the current Plants information*/
void out(std::ofstream&)const;

};
std::ostream& operator<<(std::ostream& , const Plant&); //A non-friend overloaded operator that receives a reference to an ostream object and a reference to
//an unmodifiable Plant object.
//This function displays the object in the same manner as display(ostream).
//This operator allows for cascading

bool operator==(const Plant&, const Plant&);//A non-friend overloaded operator that receives two references
//to a unmodifiable Plant objects.
//This function returns true if both plants are holding the
//same information, false otherwise


/*A non-friend helper insertion operator that recieves a reference to an ofstream object as a left hand operand and a
constant reference to a Plant as the right hand operand. This function outputs the current object to the file reference provided
in the same manners as outline for out(std::ostream&). This operator allows for cascading.*/
std::ofstream& operator<<(std::ofstream&, const Plant&);



/*A non-friend helper extraction operator that recieves a reference to an ifstream object as a left hand operand and a
reference to a Plant as the right hand operand. This function parses the the file and attempts to reconstructor the object
as described in the file.This function replaces the right hand operand with the result. This operator allows for cascading. */
std::ifstream& operator>>(std::ifstream&, Plant&);


