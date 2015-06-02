


// Garden Designer
// OOP244.143 - Assignment 3
// Mohamed Abbas Kassam

const int MAX_CROPS=20;
class Garden
{

    Crop crps[20];
    int cur_crop;
    char * map;
    int l_row;
    int w_col;

public:

    /*A no argument constructor that sets the object in a safe-empty state.*/
    Garden();


    /*Two argument constructor that receives two integers represents the length and width of the Garden.
    If either number is invalid (negative) the object adopts a safe empty state, otherwise the map is
    dynamically allocated based on the dimensions provided and initialized so that every index is holding ' '.*/
    Garden(int, int);


    /*A copy constructor that copies an existing object into a newly created object.
    This function performs both a shallow and deep copy*/
    Garden(const Garden&);

    /*An assignment operator that copies an existing objecting into another existing object.
    This function performs both a shallow and deep copy while preventing memory leaks*/
    Garden& operator=(const Garden&);


    /*A destructor that returns any dynamically allocated memory to the operatings system when the object goes out of scope.*/
    ~Garden();


    /*A simple query that returns the state of the current object.
    Returns true if the object is in a safe empty state, false otherwise */
    bool isEmpty()const;


    /*An append operator that adds a single crop to the Garden.
    This member operator receives a reference to a crop. If the crop is valid, and there is room in the list for another crop, the
    crop is added to the garden and the map is updated. If there is already another crop located at the same postion on the map,
    the new crop takes precidence.(overwrites)*/
    Garden& operator+=(const Crop&);


    /*A display query to receive a reference to an ostream object for use in displaying the current object.*/
    virtual void display(std::ostream&)const;

    /*A query that recieves a reference to an ofstream representing an output file.
    This function outputs the current object to the file reference provided using the above format.
    This function primarily focuses on the first line and controlling how many additional line are written.
    For the 2nd line on, it calls the appropriate Crop function.*/
    void out(std::ofstream&)const;


    /*A one argument constructor that receives a c-style string representing the name of a file.
    This function opens the file provided and constructs the object must in the same manner as described in the
    extraction operator described above. If, for whatever reason, the file name is invalid, or
    the file cannot be opened, the object adopts a safe empty state. */
    Garden(const char*);



};

/*A non-friend overloaded operator that receives a reference to an ostream object and a reference to an unmodifiable Garden object.
This function displays the object in the same manner as display(ostream). This operator allows for cascading*/
std::ostream& operator<<(std::ostream& , const Garden&);


/*A non-friend helper insertion operator that recieves a reference to an ofstream object as a
left hand operand and a constant reference to a Garden as the right hand operand.
This function outputs the current object to the file reference provided in the same manners as outline for out(std::ostream&).
This operator allows for cascading.*/
std::ofstream& operator<<(std::ofstream&, const Garden&);


/*A non-friend helper extraction operator that recieves a reference to an ifstream object as a left hand operand and a
reference to a Garden as the right hand operand.This function parses the the file and attempts to reconstructor the object
as described in the file. Similar to the insertion operator, this function primarily focus on reading the
first line and controlling how many additional lines are read. This function replaces the right hand operand with the result.
This operator allows for cascading. */
std::ifstream& operator>>(std::ifstream&, Garden&);



/* Detailed Garden*/

class DetailedGarden : public Garden{

char* desc;

public:
/*A no argument constructor that sets the object in a safe-empty state.*/
DetailedGarden();

/* Destructor */
~DetailedGarden();

/*Three argument constructor that receives a
c-style null terminated string, as well as two integers represents the length and width of the Garden.
If the base is set to a safe empty state, or description is missing (null), the object will adopt a safe empty state.*/
DetailedGarden(const char*,int, int);


/*A simple query that returns the state of the current object.Returns true if the object is in a safe empty state,
false otherwise */
bool isEmpty()const;



/*A display query to receive a reference to an ostream object for use in displaying the current object.
This function displays the map of the garden through the ostream object provided in the following format followed by the detailed description
*/
void display(std::ostream&)const;

/*assignment perator*/
DetailedGarden& operator=(const DetailedGarden&);

/*Constructor*/
DetailedGarden(const DetailedGarden&);






};
