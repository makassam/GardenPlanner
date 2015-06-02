// Garden Designer
// OOP244.143 - Assignment 3
// Mohamed Abbas Kassam
//Crop.h




class Crop
{
    Plant plant;
    int length;
    int width;
    int x_c;
    int y_r;
public:
    Crop();
    ~Crop();

    bool isEmpty()const;

    //void display()const;
    void display(std::ostream&)const;
    //Update the display query to receive a reference to an ostream object
    //for use in displaying the current object.
    bool read(const Plant& plant); //In addition to the input from assignment 1,
    //this function also prompts the user to enter in x and y coordinates for the crop.
    //Note: you do not need to validate against a maximum length and width anymore.
    bool place(char * map,int ,int )const;
    /*
    The Plant object must not be empty, and the length and width both must be positive,
    but not so large as to push the crop beyond the bounds of the garden.
    Update the query that adds the crop held by the object to the map. Note: the map is no longer a static two dimensional array.
    The function now receives a pointer to a c-style string as well as two integer representing the length and width of the map
    If any of the following, the map is NOT updated, and the function returns false:the function receives incorrect parameters
    Object is in a safe empty state
    Crop will not fit on map using the provided col/row*/

    /* Crop(const Plant& pl, int l, int wi)*/
    Crop(const Plant&, int, int, int, int);
    // You do not need to validate length and width.
    //the Three-argument constructor becomes a five-argument constructor, receiving two
    //additional integers representing the x and y starting location of the crop.
    //If all parameters are valid, this function accepts the data.
    //Otherwise, this constructor leaves the object in a safe empty state.
    //assuming that the x and y coordinates are positive values, the crop will fit within the garden.


    /*A query that recieves a reference to an ofstream representing an output file
    This function outputs the current object to the file reference provided using the above format.
    This function outputs the current Crops information and passes on to the Plant's function.*/
    void out(std::ofstream&)const;


};
//A non-friend overloaded operator that receives a reference to an ostream object and a reference to an unmodifiable Crop object.
std::ostream& operator<<(std::ostream& , const Crop&);



/*A non-friend helper insertion operator that recieves a reference to an ofstream object as a left hand operand
and a constant reference to a Crop as the right hand operand.
This function outputs the current object to the file reference provided in the same manners as outline for out(std::ostream&).
This operator allows for cascading.*/
std::ofstream& operator<<(std::ofstream&, const Crop&);



/*A non-friend helper extraction operator that recieves a reference to an ifstream object as a left hand operand and a
reference to a Crop as the right hand operand.This function parses the the file and attempts to reconstructor the object as described in the file. Similar to the insertion operator, this function primarily focus on reading in the Crop information.
This function replaces the right hand operand with the result. This operator allows for cascading. */
std::ifstream& operator>>(std::ifstream&, Crop&);






