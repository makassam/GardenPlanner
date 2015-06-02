/* OOP244 143 Assignment 3 Test Main
 * Garden Planning Application (GPA)
 * Detailed Garden Class and Files
 *
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <cstring>
#include "Plant.h"
#include "Crop.h"
#include "Garden.h"

#define DEBUG 1                    // Output verbosity flag
const int NOTESTS=117;
const int BLANK=0;

void StabilityTests();
bool PlantTests(int& testNumber,int* totalPassed, int* totalTested);
bool CropTests(int& testNumber, int* totalPassed, int* totalTested);
bool MapTests(int& testNumber, int* totalPassed, int* totalTested);
bool GardenTests(int& testNumber, int* totalPassed, int* totalTested);
bool DetailedGardenTests(int& testNumber, int* totalPassed, int* totalTested);
void passed(const char* message, int i, int* totalPassed, int* total);
void failed(const char* message, int i, bool* ok, int* total);
bool compare(const char *, const char *,int);
void displaySBS(const char*, const char*, int, int);



int main() {
    bool ok = true;
    struct Plant plant;
    int totalPassed = 0, totalTested = 0, testNumber = 0;

    // Stability Tests
	StabilityTests();

    // Plant Tests
    if (DEBUG)
        std::cout << "Plant Tests\n===============\n";
    if(PlantTests(testNumber, &totalPassed, &totalTested) != 0)
        if (DEBUG)
            std::cout << "\nPlant Tests passed!\n\n";
        else
            std::cout << "Plant Tests passed!\n";
    else {
        std::cout << "\n";
        if (DEBUG)
            std::cout << "Plant Tests had errors!\n\n";
        else
            std::cout << "Plant Tests had errors!\n";
    }

    // Crop Tests
    if (DEBUG)
        std::cout << "Crop Tests\n=========\n";
    if(CropTests(testNumber, &totalPassed, &totalTested) != 0)
        if (DEBUG)
            std::cout << "\nCrop Tests passed!\n\n";
        else
            std::cout << "Crop Tests passed!\n";
    else {
        std::cout << "\n";
        std::cout << "\nCrop Tests had errors!\n";
    }

   // Crop Map Tests
    if (DEBUG)
        std::cout << "Crop Place Tests\n====================\n";
    if(MapTests(testNumber, &totalPassed, &totalTested) != 0)
        if (DEBUG)
            std::cout << "\nCrop Place Tests passed!\n\n";
        else
            std::cout << "Place Tests passed!\n";
    else {
        std::cout << "\n";
        std::cout << "\nPlace Tests had errors!\n";
    }
   // Garden Tests
    if (DEBUG)
        std::cout << "Garden Tests\n====================\n";
    if(GardenTests(testNumber, &totalPassed, &totalTested) != 0)
        if (DEBUG)
            std::cout << "Garden Tests passed!\n\n";
        else
            std::cout << "Garden Tests passed!\n";
    else {
        std::cout << "\n";
        std::cout << "\nGarden Tests had errors!\n";
    }
   // Detailed Garden Tests
    if (DEBUG)
        std::cout << "Detailed Garden Tests\n====================\n";
    if(DetailedGardenTests(testNumber, &totalPassed, &totalTested) != 0)
        if (DEBUG)
            std::cout << "Detailed Garden Tests passed!\n\n";
        else
            std::cout << "Detailed Garden Tests passed!\n";
    else {
        std::cout << "\n";
        std::cout << "\nDetailed Garden Tests had errors!\n";
    }


    // Conclusion
    std::cout << "\nYour GPA modules have passed " << totalPassed << " of " << NOTESTS << " tests\n";
    if (totalPassed == totalTested)
        std::cout << "\nCongratulations!!!   "
        "Your GPA modules are ready for submission\n"
        "Assuming no segmentation faults ....\n";
    else
        std::cout << "Keep working on your code - good luck!\n";

    return 0;
}

/* DMTests performs tests on the objects to ensure that proper
*  dynamic memory is setup. It is tested first so that problems
*  are not intermixed with the other code
*  *totalPassed - total number of tests passed
*  *totalTested - total number of tests attempted
*/

void StabilityTests(){
	bool ok = true;

	std::cout<<"Stability Tests"<<std::endl
			 <<"--------------------------------------------------------------"<<std::endl
			 <<"A message will be printed before each of these test"<<std::endl
			 <<"When something goes wrong with dynamic memory the common"<<std::endl
			 <<"result is a segmentation fault. Use the messages to help trackdown"<<std::endl
			 <<"where the problem occured. Use debugging techniques outline on "<<std::endl
			 <<"moodle to figure out what the cause is"<<std::endl
			 <<"--------------------------------------------------------------"<<std::endl;
	std::cout<<"Plant Copies"<<std::endl<<std::endl;

	std::cout<<"construction/destruction of an empty object"<<std::endl
			 <<"constructing"<<std::endl;
	Plant * plant1=new Plant();
	std::cout<<"destroying"<<std::endl;
	delete plant1;

	std::cout<<"construction/destruction of a non-empty object"<<std::endl
			<<"constructing"<<std::endl;
	plant1=new Plant("A name", 'q');
	std::cout<<"destroying"<<std::endl;
	delete plant1;

	std::cout<<"Copy Constructor"<<std::endl;
	Plant plant2("A name", 'q');
	if(1){
		Plant plant3= plant2;
		std::cout<<"destroying"<<std::endl;
	}

	std::cout<<"Trigger SES in 2 arg ctor"<<std::endl;
	Plant plant4(nullptr,'q');

	std::cout<<"Assign into empty object"<<std::endl;
	plant4=plant2;

	std::cout<<"self assignment check"<<std::endl;
	plant1=new Plant("another name", 'f');
	*plant1=*plant1;
	delete plant1;

	std::cout<<"check deep copy"<<std::endl;
	plant1=new Plant();

	Plant * plant3=new Plant("once more", 'q');
	*plant1=*plant3;
	delete plant1;
	delete plant3;

	std::cout<<"--------------------------------------------------------------"<<std::endl
			  <<"Garden Copies"<<std::endl
			  <<"--------------------------------------------------------------"<<std::endl<<std::endl;

	std::cout<<"construction/destruction of an empty object"<<std::endl
			 <<"constructing"<<std::endl;
	Garden * garden1=new Garden();
	std::cout<<"destroying"<<std::endl;
	delete garden1;

	std::cout<<"construction/destruction of a non-empty object"<<std::endl
			<<"constructing"<<std::endl;
	garden1=new Garden(400, 300);
	std::cout<<"destroying"<<std::endl;
	delete garden1;

	std::cout<<"Copy Constructor"<<std::endl;
	Garden garden2(40, 40);
	if(1){
		Garden garden3 = garden2;
		std::cout<<"destroying"<<std::endl;
	}

	std::cout<<"Trigger SES in 2 arg ctor"<<std::endl;
	Garden garden4(-10,-30);

	std::cout<<"Assign into empty object"<<std::endl;
	garden4=garden2;

	std::cout<<"self assignment check"<<std::endl;
	garden1=new Garden(10,10);
	*garden1=*garden1;
	delete garden1;

	std::cout<<"check deep copy"<<std::endl;
	garden1=new Garden();
	Garden * garden3=new Garden(100,100);
	*garden1=*garden3;
	delete garden1;
	delete garden3;

	std::cout<<"--------------------------------------------------------------"<<std::endl
			  <<"Detailed Garden Copies"<<std::endl
			  <<"--------------------------------------------------------------"<<std::endl<<std::endl;

	std::cout<<"construction/destruction of an empty object"<<std::endl
			 <<"constructing"<<std::endl;
	DetailedGarden * dgarden1=new DetailedGarden();
	std::cout<<"destroying"<<std::endl;
	delete dgarden1;

	std::cout<<"construction/destruction of a non-empty object"<<std::endl
			<<"constructing"<<std::endl;
	dgarden1=new DetailedGarden("Sample",400, 300);
	std::cout<<"destroying"<<std::endl;
	delete dgarden1;

	std::cout<<"Copy Constructor"<<std::endl;
	DetailedGarden dgarden2("Sample",40, 40);
	if(1){
		DetailedGarden dgarden3 = dgarden2;
		std::cout<<"destroying"<<std::endl;
	}

	std::cout<<"Trigger SES in 3 arg ctor"<<std::endl;
	DetailedGarden dgarden4(nullptr,10,30);
	DetailedGarden dgarden5("sample",-10,-30);

	std::cout<<"Assign into empty object"<<std::endl;
	dgarden4=dgarden2;

	std::cout<<"self assignment check"<<std::endl;
	dgarden1=new DetailedGarden("sample",10,10);
	*dgarden1=*dgarden1;
	delete dgarden1;

	std::cout<<"check deep copy"<<std::endl;
	dgarden1=new DetailedGarden();
	DetailedGarden * dgarden3=new DetailedGarden("Sample Name",100,100);
	*dgarden1=*dgarden3;
	delete dgarden1;
	delete dgarden3;

	//empty tests.
	Plant plant;
	Crop crop;
	Garden garden;
	std::ofstream empty;
    std::ifstream null;
 	std::cout <<"--------------------------------------------------------------"<<std::endl
 			  <<"File Stability tests"<<std::endl
			  <<"--------------------------------------------------------------"<<std::endl
			  <<"Passing empty file objects to file functions and operators"<<std::endl;
	std::cout<<"Empty file object tests - output"<<std::endl;
	std::cout<<"Crop::out"<<std::endl;
    crop.out(empty);
    std::cout<<"crop - operator<<"<<std::endl;
    empty<<crop;
	std::cout<<"Plant::out"<<std::endl;
    plant.out(empty);
	std::cout<<"Plant - operator<<"<<std::endl;
    empty<<plant;
	std::cout<<"Garden::out"<<std::endl;
    garden.out(empty);
	std::cout<<"Garden - operator<<"<<std::endl;
    empty<<garden;

	std::cout<<"Empty file object tests - input"<<std::endl;
	std::cout<<"Plant - operator>>"<<std::endl;
    null>>plant;
	std::cout<<"Crop - operator>>"<<std::endl;
    null>>crop;
	std::cout<<"Garden - operator>>"<<std::endl;
    null>>garden;

	std::cout<<"---------------------------------------------------"<<std::endl<<
			   "Stability Tests Complete"<<std::endl<<std::endl;
}



/* PlantTests performs tests on the Plantclass and return false
*  for invalid results
*  *totalPassed - total number of tests passed
*  *totalTested - total number of tests attempted
*/
bool PlantTests(int& testNumber, int* totalPassed, int* totalTested) {
    bool ok = true;
	Plant blank;
	Plant plant1("Turnips", 'T');

	if(!blank.isEmpty())
        failed("SES Test: isEmpty did not return true",++testNumber, &ok, totalTested);
    else
    	passed("SES Test: isEmpty returned true", ++testNumber, totalPassed,
         totalTested);

	if(plant1.isEmpty())
        failed("Good Test: isEmpty did not return false",++testNumber, &ok, totalTested);
    else
    	passed("Good Test: isEmpty returned false", ++testNumber, totalPassed,
         totalTested);

	if(plant1.symbol()!='T')
        failed("Good Test: symbol did not return the correct character",++testNumber,
               &ok, totalTested);
    else
    	passed("Good Test: symbol returned the correct character", ++testNumber,
  	  	       totalPassed, totalTested);

  	std::cout<<"Null Name Test: Sending null pointer to Plant constructor..."<<std::endl;
    plant1=Plant(nullptr, 'W');
	if(!blank.isEmpty())
        failed("Null Name Test: isEmpty did not return true",++testNumber, &ok, totalTested);
    else
    	passed("Null Name Test: isEmpty returned true", ++testNumber, totalPassed,
         totalTested);

	if(plant1.symbol()!=blank.symbol())
        failed("Null Name Test: symbol did not return the correct character, object is not in a SES"
               ,++testNumber, &ok, totalTested);
    else
    	passed("Null Name Test: symbol returned the correct character", ++testNumber, totalPassed,
         totalTested);

    plant1=Plant("", 'F');
	if(!plant1.isEmpty())
        failed("Blank Name Test: isEmpty did not return true",++testNumber, &ok, totalTested);
    else
    	passed("Blank Name Test: isEmpty returned true", ++testNumber, totalPassed,
         totalTested);

	if(plant1.symbol()!=blank.symbol())
        failed("Blank Name Test: symbol did not return the correct character, object is not in a SES"
               ,++testNumber, &ok, totalTested);
    else
    	passed("Blank Name Test: symbol returned the correct character", ++testNumber, totalPassed,
         totalTested);

  	std::cout<<"Long Name Test: Sending an excessively long name to Plant constructor..."<<std::endl;
    plant1=Plant("An Excessively long name for a plant", 'L');
	if(!blank.isEmpty())
        failed("Long Name Test: isEmpty did not return true",++testNumber, &ok, totalTested);
    else
    	passed("Long Name Test: isEmpty returned true", ++testNumber, totalPassed,
         totalTested);

	if(plant1.symbol()!=blank.symbol())
        failed("Long Name Test: symbol did not return the correct character, object is not in a SES"
               ,++testNumber, &ok, totalTested);
    else
    	passed("Long Name Test: symbol returned the correct character", ++testNumber, totalPassed,
         totalTested);

	if(!(plant1==blank))
        failed("operator==: SES plant == Blank plant did not match"
               ,++testNumber, &ok, totalTested);
    else
    	passed("operator==: SES plant == Blank plant matched", ++testNumber, totalPassed,
         totalTested);

   Plant plant2("Carrots", 'C');
   Plant plant3("Carrots", 'C');
	if(!(plant2==plant3))
        failed("operator==: Two objects holding identical data did not match"
               ,++testNumber, &ok, totalTested);
    else
    	passed("operator==: Two objects holding identical data matched", ++testNumber, totalPassed,
         totalTested);

    plant3=Plant("Carrots", 'Q');
	if(plant2==plant3)
        failed("operator==: Different Symbols: Incorrected returned true"
               ,++testNumber, &ok, totalTested);
    else
    	passed("operator==: Different Symbols: Correctly returned false", ++testNumber, totalPassed,
         totalTested);

    plant3=Plant("Cucumber", 'C');
	if(plant2==plant3)
        failed("operator==: Different Name: Incorrected returned true"
               ,++testNumber, &ok, totalTested);
    else
    	passed("operator==: Different Name: Correctly returned false", ++testNumber, totalPassed,
         totalTested);

	std::stringstream result;

	result<<blank;
	if(result.str().length()!=0){
        failed("SES Test: display() attempted to modify the output stream",++testNumber, &ok, totalTested);
	}
    else
    	passed("SES Test: display() did not attempt to modify the output stream", ++testNumber, totalPassed,
         totalTested);
//Plant
	Plant plant;
	std::ofstream fout;
	std::ifstream fin;
	std::string mPlant="e Egg Plant\n";
	result.str(std::string());
  //output
	fout.open("plant.txt");
	Plant plantOut("Egg Plant",'e');
	fout<<plantOut;
	fout.close();
  //input
	fin.open("plant.txt");
	plant=Plant(); //Blank out
	result.str(std::string());
	result<<fin.rdbuf();

	fin.close();
	if(result.str()!=mPlant){
		failed("plant.txt: Contents of the file does not match with expected results",++testNumber, &ok, totalTested);
		std::cout<<std::endl<<"Your output:"<<std::endl<<result.str()<<std::endl<<std::endl
		         <<"Expected Output"<<std::endl<<mPlant<<std::endl;
		return false;
	}else
	   	passed("mplant.txt: matches with the expected result", ++testNumber, totalPassed,
         totalTested);

	fin.open("plant.txt");
	result.str(std::string());
	fin>>plant;
	if(plant.isEmpty())
		failed("fin>>plant: isEmpty did not return false",++testNumber, &ok, totalTested);
	else
		passed("fin>>plant: isEmpty returned false", ++testNumber, totalPassed,
	 totalTested);
	fin.close();
    return ok;
}

/* CropTests performs tests on all Crop function except place()
*  returns false for invalid results
*  *totalPassed - total number of tests passed
*  *totalTested - total number of tests attempted
*/
bool CropTests(int& testNumber, int* totalPassed, int* totalTested) {
    bool ok = true;
	Plant blankPlant;
	Plant plant1("Cabbage", 'c');
	Crop blank;
	Crop crop1(plant1,4,4,0,0);

	if(!blank.isEmpty())
        failed("SES Test: isEmpty did not return true",++testNumber, &ok, totalTested);
    else
    	passed("SES Test: isEmpty returned true", ++testNumber, totalPassed,
         totalTested);
   //Good Plant
   	std::cout<<"---Valid Plant Crop Test"<<std::endl;
	if(crop1.isEmpty())
        failed("Good Test: isEmpty did not return false",++testNumber, &ok, totalTested);
    else
    	passed("Good Test: isEmpty returned false", ++testNumber, totalPassed,
         totalTested);
    crop1=Crop(plant1, 1, 1,0,0);
	if(crop1.isEmpty())
        failed("Good Test Smallest: isEmpty did not return false",++testNumber, &ok, totalTested);
    else
    	passed("Good Test Smallest: isEmpty returned false", ++testNumber, totalPassed,
         totalTested);
	crop1=Crop(plant1, -10, 4,0,0);
	if(!blank.isEmpty())
        failed("Neg Len Test: isEmpty did not return true",++testNumber, &ok, totalTested);
    else
    	passed("Neg Len Test: isEmpty returned true", ++testNumber, totalPassed,
         totalTested);
	crop1=Crop(plant1, 4, -15,0,0);
	if(!blank.isEmpty())
        failed("Neg Wid Test: isEmpty did not return true",++testNumber, &ok, totalTested);
    else
    	passed("Neg Wid Test: isEmpty returned true", ++testNumber, totalPassed,
         totalTested);
	crop1=Crop(plant1, 4, 4,0,-1);
	if(!blank.isEmpty())
        failed("Neg X Test: isEmpty did not return true",++testNumber, &ok, totalTested);
    else
    	passed("Neg X Test: isEmpty returned true", ++testNumber, totalPassed,
         totalTested);
	crop1=Crop(plant1, 4, 4,-1,0);
	if(!blank.isEmpty())
        failed("Neg Y Test: isEmpty did not return true",++testNumber, &ok, totalTested);
    else
    	passed("Neg Y Test: isEmpty returned true", ++testNumber, totalPassed,
         totalTested);
	crop1=Crop(plant1, 4, 4,-1,-1);
	if(!blank.isEmpty())
        failed("Neg Both X/Y Test: isEmpty did not return true",++testNumber, &ok, totalTested);
    else
    	passed("Neg Both X/Y Test: isEmpty returned true", ++testNumber, totalPassed,
         totalTested);
	crop1=Crop(plant1, -135, -122,0,0);
	if(!blank.isEmpty())
        failed("Neg Both Test: isEmpty did not return true",++testNumber, &ok, totalTested);
    else
    	passed("Neg Both Test: isEmpty returned true", ++testNumber, totalPassed,
         totalTested);
	crop1=Crop(plant1, 0, 4,0,0);
	if(!blank.isEmpty())
        failed("0 Len Test: isEmpty did not return true",++testNumber, &ok, totalTested);
    else
    	passed("0 Len Test: isEmpty returned true", ++testNumber, totalPassed,
         totalTested);
	crop1=Crop(plant1, 4, 0,0,0);
	if(!blank.isEmpty())
        failed("0 Wid Test: isEmpty did not return true",++testNumber, &ok, totalTested);
    else
    	passed("0 Wid Test: isEmpty returned true", ++testNumber, totalPassed,
         totalTested);
	crop1=Crop(plant1, 0, 0,0,0);
	if(!blank.isEmpty())
        failed("0 Both Test: isEmpty did not return true",++testNumber, &ok, totalTested);
    else
    	passed("0 Both Test: isEmpty returned true", ++testNumber, totalPassed,
         totalTested);
    //Bad Plant
    std::cout<<"---Invalid Plant Crop Test"<<std::endl;
	Crop crop2(blankPlant, 5,5,0,0);
	if(!crop2.isEmpty())
        failed("Valid Len/Wid Test: isEmpty did not return true",++testNumber, &ok, totalTested);
    else
    	passed("Valid Len/Wid Test: isEmpty returned true", ++testNumber, totalPassed,
         totalTested);
    crop2=Crop(blankPlant, 1, 1,0,0);
	if(!crop2.isEmpty())
        failed("Valid Len/Wid Test Smallest: isEmpty did not return true",++testNumber, &ok, totalTested);
    else
    	passed("Valid Len/Wid Test Smallest: isEmpty returned true", ++testNumber, totalPassed,
         totalTested);
	crop2=Crop(blankPlant, -10, 4,0,0);
	if(!blank.isEmpty())
        failed("Neg Len Test: isEmpty did not return true",++testNumber, &ok, totalTested);
    else
    	passed("Neg Len Test: isEmpty returned true", ++testNumber, totalPassed,
         totalTested);
	crop2=Crop(blankPlant, 4, -15,0,0);
	if(!blank.isEmpty())
        failed("Neg Wid Test: isEmpty did not return true",++testNumber, &ok, totalTested);
    else
    	passed("Neg Wid Test: isEmpty returned true", ++testNumber, totalPassed,
         totalTested);
	crop2=Crop(blankPlant, -135, -122,0,0);
	if(!blank.isEmpty())
        failed("Neg Both Test: isEmpty did not return true",++testNumber, &ok, totalTested);
    else
    	passed("Neg Both Test: isEmpty returned true", ++testNumber, totalPassed,
         totalTested);
	crop2=Crop(blankPlant, 0, 4,0,0);
	if(!blank.isEmpty())
        failed("0 Len Test: isEmpty did not return true",++testNumber, &ok, totalTested);
    else
    	passed("0 Len Test: isEmpty returned true", ++testNumber, totalPassed,
         totalTested);
	crop2=Crop(blankPlant, 4, 0,0,0);
	if(!blank.isEmpty())
        failed("0 Wid Test: isEmpty did not return true",++testNumber, &ok, totalTested);
    else
    	passed("0 Wid Test: isEmpty returned true", ++testNumber, totalPassed,
         totalTested);
	crop2=Crop(blankPlant, 0, 0,0,0);
	if(!blank.isEmpty())
        failed("0 Both Test: isEmpty did not return true",++testNumber, &ok, totalTested);
    else
    	passed("0 Both Test: isEmpty returned true", ++testNumber, totalPassed,
         totalTested);

    //display tests
	std::stringstream result;

	result<<blank;
	if(result.str().length()!=0){
        failed("SES Test: display() attempted to modify the output stream",++testNumber, &ok, totalTested);
	}
    else
    	passed("SES Test: display() did not attempt to modify the output stream", ++testNumber, totalPassed,
         totalTested);



//Files
	std::ofstream fout;
	std::ifstream fin;
	Crop crop;
	std::string mPlant="e Egg Plant\n";
	std::string mCrop="8 8 2 2 e Egg Plant\n";
	result.str(std::string());
	Plant plantOut("Egg Plant",'e');

  //output
	fout.open("crop.txt");
	Crop cropOut(plantOut,8,8,2,2);
	fout<<cropOut;
	fout.close();
  //input
	fin.open("crop.txt");
	crop=Crop(); //Blank out
	result.str(std::string());
	result<<fin.rdbuf();

	fin.close();
	if(result.str()!=mCrop){
		failed("crop.txt: Contents of the file does not match with expected results",++testNumber, &ok, totalTested);
		std::cout<<std::endl<<"Your output:"<<std::endl<<result.str()<<std::endl<<std::endl
		         <<"Expected Output"<<std::endl<<mCrop<<std::endl;
		return false;
	}else
	   	passed("crop.txt: matches with the expected result", ++testNumber, totalPassed,
         totalTested);

	fin.open("crop.txt");
	result.str(std::string());
	fin>>crop;
	if(crop.isEmpty())
		failed("fin>>crop: isEmpty did not return false",++testNumber, &ok, totalTested);
	else
		passed("fin>>crop: isEmpty returned false", ++testNumber, totalPassed,
	 totalTested);
	fin.close();

    return ok;
}

/* RegisteredTests performs tests on the registered() function and returns
*  false for invalid results
*  *totalPassed - total number of tests passed
*  *totalTested - total number of tests attempted
*/
bool MapTests(int& testNumber, int* totalPassed, int* totalTested) {
    bool ok = true;

	char map[600];
	int wid = 30;

	char master[13][601]={
		{"                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        "},
		{"ll                            ll                            ll                            ll                            ll                            ll                            ll                            ll                            ll                            ll                            ll                            ll                            ll                            ll                            ll                            ll                            ll                            ll                            ll                            ll                            "},
		{"ll cc                         ll cc                         ll cc                         ll cc                         ll cc                         ll cc                         ll cc                         ll cc                         ll cc                         ll cc                         ll cc                         ll cc                         ll cc                         ll cc                         ll cc                         ll cc                         ll cc                         ll cc                         ll cc                         ll cc                         "},
		{"ll cc p                       ll cc p                       ll cc p                       ll cc p                       ll cc p                       ll cc p                       ll cc p                       ll cc p                       ll cc p                       ll cc p                       ll cc p                       ll cc p                       ll cc p                       ll cc p                       ll cc p                       ll cc p                       ll cc p                       ll cc p                       ll cc p                       ll cc p                       "},
		{"ll cc p ttt                   ll cc p ttt                   ll cc p ttt                   ll cc p ttt                   ll cc p ttt                   ll cc p ttt                   ll cc p ttt                   ll cc p ttt                   ll cc p ttt                   ll cc p ttt                   ll cc p ttt                   ll cc p ttt                   ll cc p ttt                   ll cc p ttt                   ll cc p ttt                   ll cc p ttt                   ll cc p ttt                   ll cc p ttt                   ll cc p ttt                   ll cc p ttt                   "},
		{"ll cc p ttt RRRRRRRRRR        ll cc p ttt RRRRRRRRRR        ll cc p ttt RRRRRRRRRR        ll cc p ttt RRRRRRRRRR        ll cc p ttt RRRRRRRRRR        ll cc p ttt RRRRRRRRRR        ll cc p ttt RRRRRRRRRR        ll cc p ttt RRRRRRRRRR        ll cc p ttt RRRRRRRRRR        ll cc p ttt RRRRRRRRRR        ll cc p ttt                   ll cc p ttt                   ll cc p ttt                   ll cc p ttt                   ll cc p ttt                   ll cc p ttt                   ll cc p ttt                   ll cc p ttt                   ll cc p ttt                   ll cc p ttt                   "},
		{"ll cc p ttt RRRRRRRRRR        ll cc p ttt RRRRRRRRRR        ll cc p ttt RRRRRRRRRR        ll cc p ttt RRRRRRRRRR        ll cc p ttt RRRRRRRRRR        ll cc p ttt RRRRRRRRRR        ll cc p ttt RRRRRRRRRR        ll cc p ttt RRRRRRRRRR        ll cc p ttt RRRRRRRRRR        ll cc p ttt RRRRRRRRRR        ll cc p ttt                   ll cc p ttt CCCCC             ll cc p ttt CCCCC             ll cc p ttt CCCCC             ll cc p ttt CCCCC             ll cc p ttt CCCCC             ll cc p ttt CCCCC             ll cc p ttt CCCCC             ll cc p ttt CCCCC             ll cc p ttt CCCCC             "},
		{"ll cc p ttt RRRRRRRRRR        ll cc p ttt RRRRRRRRRR        ll cc p ttt RRRRRRRRRR        ll cc p ttt RRRRRRRRRR        ll cc p ttt RRRRRRRRRR        ll cc p ttt RRRRRRRRRR        ll cc p ttt RRRRRRRRRR        ll cc p ttt RRRRRRRRRR        ll cc p ttt RRRRRRRRRR        ll cc p ttt RRRRRRRRRR        ll cc p ttt                   ll cc p ttt CCCCC  bbb        ll cc p ttt CCCCC  bbb        ll cc p ttt CCCCC  bbb        ll cc p ttt CCCCC  bbb        ll cc p ttt CCCCC  bbb        ll cc p ttt CCCCC  bbb        ll cc p ttt CCCCC  bbb        ll cc p ttt CCCCC  bbb        ll cc p ttt CCCCC  bbb        "},
		{"ll cc p ttt RRRRRRRRRR rrrrrrrll cc p ttt RRRRRRRRRR rrrrrrrll cc p ttt RRRRRRRRRR rrrrrrrll cc p ttt RRRRRRRRRR rrrrrrrll cc p ttt RRRRRRRRRR rrrrrrrll cc p ttt RRRRRRRRRR rrrrrrrll cc p ttt RRRRRRRRRR rrrrrrrll cc p ttt RRRRRRRRRR rrrrrrrll cc p ttt RRRRRRRRRR        ll cc p ttt RRRRRRRRRR        ll cc p ttt                   ll cc p ttt CCCCC  bbb        ll cc p ttt CCCCC  bbb        ll cc p ttt CCCCC  bbb        ll cc p ttt CCCCC  bbb        ll cc p ttt CCCCC  bbb        ll cc p ttt CCCCC  bbb        ll cc p ttt CCCCC  bbb        ll cc p ttt CCCCC  bbb        ll cc p ttt CCCCC  bbb        "},
		{"ll cc p ttt RRRRRRRRRR rrrrrrrll cc p ttt RRRRRRRRRR rrrrrrrll cc p ttt RRRRRRRRRR rrrrrrrll cc p ttt RRRRRRRRRR rrrrrrrll cc p ttt RRRRRRRRRR rrrrrrrll cc p ttt RRRRRRRRRR rrrrrrrll cc p ttt RRRRRRRRRR rrrrrrrll cc p ttt RRRRRRRRRR rrrrrrrll cc p ttt RRRRRRRRRR        ll cc p ttt RRRRRRRRRR TTTTTTTll cc p ttt            TTTTTTTll cc p ttt CCCCC  bbb TTTTTTTll cc p ttt CCCCC  bbb TTTTTTTll cc p ttt CCCCC  bbb TTTTTTTll cc p ttt CCCCC  bbb TTTTTTTll cc p ttt CCCCC  bbb        ll cc p ttt CCCCC  bbb        ll cc p ttt CCCCC  bbb        ll cc p ttt CCCCC  bbb        ll cc p ttt CCCCC  bbb        "},
		{"ll cc p ttt RRRRRRRRRR rrrrrrrll cc p ttt RRRRRRRRRR rrrrrrrll cc p ttt RRRRRRRRRR rrrrrrrll cc p ttt RRRRRRRRRR rrrrrrrll cc p ttt RRRRRRRRRR rrrrrrrll cc p ttt RRRRRRRRRR rrrrrrrll cc p ttt RRRRRRRRRR rrrrrrrll cc p ttt RRRRRRRRRR rrrrrrrll cc p ttt RRRRRRRRRR        ll cc p ttt RRRRRRRRRR TTTTTTTll cc p ttt            TTTTTTTll cc p ttt CCCCC  bbb TTTTTTTll cc p ttt CCCCC  bbb TTTTTTTll cc p ttt CCCCC  bbb TTTTTTTll cc p ttt CCCCC  bbb TTTTTTTll cc p ttt CCCCC  bbb        ll cc p ttt CCCCC  bbb sssssssll cc p ttt CCCCC  bbb sssssssll cc p ttt CCCCC  bbb sssssssll cc p ttt CCCCC  bbb sssssss"},
		{"BBBB                          BBBB                          BBBB                          BBBB                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          "},
		{"SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS"}
		};

	Plant plant1("Basil", 'B');
	Crop blankCrop;
	Crop crop1(plant1,4,4,0,0);
	for(int i=0; i< 600; i++)
		map[i]=' ';

	//invalid cases
	std::cout<<"---Invalid Input Map Tests"<<std::endl;
	std::cout<<"Null Name Test: Sending null pointer to Plant constructor..."<<std::endl;
	if(crop1.place( nullptr, 20,30))
		failed("Null Pointer: place did not return false",++testNumber, &ok, totalTested);
	else
	   	passed("Null Pointer: place returned false", ++testNumber, totalPassed,
         totalTested);
    if(!compare(map,master[BLANK],60)){
		failed("Null Pointer: your map does not match expected result",++testNumber, &ok, totalTested);
		std::cout<<std::endl;
		displaySBS(map,master[BLANK],20,30);
		return false;
	}else
		passed("Null Pointer: map matches with the expected result", ++testNumber, totalPassed,
         totalTested);
	if(blankCrop.place(map, 20,30))
		failed("Blank Crop: place did not return false",++testNumber, &ok, totalTested);
	else
	   	passed("Blank Crop: place returned false", ++testNumber, totalPassed,
         totalTested);
    if(!compare(map,master[BLANK],600)){
		failed("Blank Crop: your map does not match expected result",++testNumber, &ok, totalTested);
		std::cout<<std::endl;
		displaySBS(map,master[BLANK],20,30);
		return false;
	}else
		passed("Blank Crop: map matches with the expected result", ++testNumber, totalPassed,
         totalTested);
    	Crop big(Plant ("Sun flower", 'S'),20,30,0,0);

	//Valid tests
	std::cout<<"---Valid Map Tests"<<std::endl;
	if(!crop1.place(map, 20,30))
		failed("Simple Crop: place did not return true",++testNumber, &ok, totalTested);
	else
	   	passed("Simple Crop: place returned true", ++testNumber, totalPassed,
         totalTested);
    if(!compare(map,master[11],600)){
		failed("Simple Crop: your map does not match expected result",++testNumber, &ok, totalTested);
		std::cout<<std::endl;
		displaySBS(map,master[11],20,30);
		return false;
	}else
		passed("Simple Crop: map matches with the expected result", ++testNumber, totalPassed,
         totalTested);

	if(!big.place(map,20,30))
		failed("Full Crop: place did not return true",++testNumber, &ok, totalTested);
	else
	   	passed("Full Crop: place returned true", ++testNumber, totalPassed,
         totalTested);
    if(!compare(map,master[12],600)){
		failed("Full Crop: your map does not match expected result",++testNumber, &ok, totalTested);
		std::cout<<std::endl;
		displaySBS(map,master[12],20,30);
		return false;
	}else
		passed("Full Crop: map matches with the expected result", ++testNumber, totalPassed,
         totalTested);

    //various changes
	char map2[600];
	for(int i=0;i<600;i++)
		map2[i]=' ';
    Crop crops[10];
    crops[0]=Crop(Plant("Lettuce",'l'), 20,2,0,0);
    crops[1]=Crop(Plant("Carrots",'c'), 20,2,3,0);
    crops[2]=Crop(Plant("Peppers",'p'), 20,1,6,0);
    crops[3]=Crop(Plant("Tomatoes",'t'), 20,3,8,0);
    crops[4]=Crop(Plant("Rhubarb",'R'), 10,10,12,0);
    crops[5]=Crop(Plant("Cabbage",'C'), 9,5,12,11);
    crops[6]=Crop(Plant("Basil",'b'),9,3,19,11);
    crops[7]=Crop(Plant("Rosemary", 'r'),8,7,23,0);
    crops[8]=Crop(Plant("Thyme", 'T'),6,7,23,9);
    crops[9]=Crop(Plant("Squash", 's'),4,7,23,16);

	if(!crops[0].place(map2,20,30))
		failed("crop[0]: place did not return true",++testNumber, &ok, totalTested);
	else
	   	passed("crop[0]: place returned true", ++testNumber, totalPassed,
         totalTested);
    if(!compare(map2,master[1],600)){
		failed("crop[0]: your map does not match expected result",++testNumber, &ok, totalTested);
		std::cout<<std::endl;
		displaySBS(map2,master[1],20,30);
		return false;
	}else
		passed("crop[0]: map matches with the expected result", ++testNumber, totalPassed,
         totalTested);

	if(!crops[1].place(map2,20,30))
		failed("crop[1]: place did not return true",++testNumber, &ok, totalTested);
	else
	   	passed("crop[1]: place returned true", ++testNumber, totalPassed,
         totalTested);
    if(!compare(map2,master[2],600)){
		failed("crop[1]: your map does not match expected result",++testNumber, &ok, totalTested);
		std::cout<<std::endl;
		displaySBS(map2,master[2],20,30);
		return false;
	}else
		passed("crop[1]: map matches with the expected result", ++testNumber, totalPassed,
         totalTested);

	if(!crops[2].place(map2,20,30))
		failed("crop[2]: place did not return true",++testNumber, &ok, totalTested);
	else
	   	passed("crop[2]: place returned true", ++testNumber, totalPassed,
         totalTested);
    if(!compare(map2,master[3],600)){
		failed("crop[2]: your map does not match expected result",++testNumber, &ok, totalTested);
		std::cout<<std::endl;
		displaySBS(map2,master[3],20,30);
		return false;
	}else
		passed("crop[2]: map matches with the expected result", ++testNumber, totalPassed,
         totalTested);

	if(!crops[3].place(map2,20,30))
		failed("crop[3]: place did not return true",++testNumber, &ok, totalTested);
	else
	   	passed("crop[3]: place returned true", ++testNumber, totalPassed,
         totalTested);
    if(!compare(map2,master[4],600)){
		failed("crop[3]: your map does not match expected result",++testNumber, &ok, totalTested);
		std::cout<<std::endl;
		displaySBS(map2,master[4],20,30);
		return false;
	}else
		passed("crop[3]: map matches with the expected result", ++testNumber, totalPassed,
         totalTested);

	if(!crops[4].place(map2,20,30))
		failed("crop[4]: place did not return true",++testNumber, &ok, totalTested);
	else
	   	passed("crop[4]: place returned true", ++testNumber, totalPassed,
         totalTested);
    if(!compare(map2,master[5],600)){
		failed("crop[4]: your map does not match expected result",++testNumber, &ok, totalTested);
		std::cout<<std::endl;
		displaySBS(map2,master[5],20,30);
		return false;
	}else
		passed("crop[4]: map matches with the expected result", ++testNumber, totalPassed,
         totalTested);

	if(!crops[5].place(map2,20,30))
		failed("crop[5]: place did not return true",++testNumber, &ok, totalTested);
	else
	   	passed("crop[5]: place returned true", ++testNumber, totalPassed,
         totalTested);
    if(!compare(map2,master[6],600)){
		failed("crop[5]: your map does not match expected result",++testNumber, &ok, totalTested);
		std::cout<<std::endl;
		displaySBS(map2,master[6],20,30);
		return false;
	}else
		passed("crop[5]: map matches with the expected result", ++testNumber, totalPassed,
         totalTested);

	if(!crops[6].place(map2,20,30))
		failed("crop[6]: place did not return true",++testNumber, &ok, totalTested);
	else
	   	passed("crop[6]: place returned true", ++testNumber, totalPassed,
         totalTested);
    if(!compare(map2,master[7],600)){
		failed("crop[6]: your map does not match expected result",++testNumber, &ok, totalTested);
		std::cout<<std::endl;
		displaySBS(map2,master[7],20,30);
		return false;
	}else
		passed("crop[6]: map matches with the expected result", ++testNumber, totalPassed,
         totalTested);

	if(!crops[7].place(map2,20,30))
		failed("crop[7]: place did not return true",++testNumber, &ok, totalTested);
	else
	   	passed("crop[7]: place returned true", ++testNumber, totalPassed,
         totalTested);
    if(!compare(map2,master[8],600)){
		failed("crop[7]: your map does not match expected result",++testNumber, &ok, totalTested);
		std::cout<<std::endl;
		displaySBS(map2,master[8],20,30);
		return false;
	}else
		passed("crop[7]: map matches with the expected result", ++testNumber, totalPassed,
         totalTested);

	if(!crops[8].place(map2,20,30))
		failed("crop[8]: place did not return true",++testNumber, &ok, totalTested);
	else
	   	passed("crop[8]: place returned true", ++testNumber, totalPassed,
         totalTested);
    if(!compare(map2,master[9],600)){
		failed("crop[8]: your map does not match expected result",++testNumber, &ok, totalTested);
		std::cout<<std::endl;
		displaySBS(map2,master[9],20,30);
		return false;
	}else
		passed("crop[8]: map matches with the expected result", ++testNumber, totalPassed,
         totalTested);

	if(!crops[9].place(map2,20,30))
		failed("crop[9]: place did not return true",++testNumber, &ok, totalTested);
	else
	   	passed("crop[9]: place returned true", ++testNumber, totalPassed,
         totalTested);
    if(!compare(map2,master[10],600)){
		failed("crop[9]: your map does not match expected result",++testNumber, &ok, totalTested);
		std::cout<<std::endl;
		displaySBS(map2,master[10],20,30);
		return false;
	}else
		passed("crop[9]: map matches with the expected result", ++testNumber, totalPassed,
         totalTested);

    return ok;
}

bool GardenTests(int& testNumber, int* totalPassed, int* totalTested){
    bool ok = true;
	Plant blankPlant;
	Plant plant1("Cabbage", 'c');
	Crop blankCrop;
	Crop crop1(plant1,4,4,0,0);
	Garden blankGarden;
	Garden garden1(20,30);

	std::stringstream result;
	std::string master[13];
	master[0]= "+------------------------------+\n|                              |\n|                              |\n|                              |\n|                              |\n|                              |\n|                              |\n|                              |\n|                              |\n|                              |\n|                              |\n|                              |\n|                              |\n|                              |\n|                              |\n|                              |\n|                              |\n|                              |\n|                              |\n|                              |\n|                              |\n+------------------------------+\n";
	master[1]= "+------------------------------+\n|ll                            |\n|ll                            |\n|ll                            |\n|ll                            |\n|ll                            |\n|ll                            |\n|ll                            |\n|ll                            |\n|ll                            |\n|ll                            |\n|ll                            |\n|ll                            |\n|ll                            |\n|ll                            |\n|ll                            |\n|ll                            |\n|ll                            |\n|ll                            |\n|ll                            |\n|ll                            |\n+------------------------------+\n";
	master[2]= "+------------------------------+\n|ll cc                         |\n|ll cc                         |\n|ll cc                         |\n|ll cc                         |\n|ll cc                         |\n|ll cc                         |\n|ll cc                         |\n|ll cc                         |\n|ll cc                         |\n|ll cc                         |\n|ll cc                         |\n|ll cc                         |\n|ll cc                         |\n|ll cc                         |\n|ll cc                         |\n|ll cc                         |\n|ll cc                         |\n|ll cc                         |\n|ll cc                         |\n|ll cc                         |\n+------------------------------+\n";
	master[3]= "+------------------------------+\n|ll cc p                       |\n|ll cc p                       |\n|ll cc p                       |\n|ll cc p                       |\n|ll cc p                       |\n|ll cc p                       |\n|ll cc p                       |\n|ll cc p                       |\n|ll cc p                       |\n|ll cc p                       |\n|ll cc p                       |\n|ll cc p                       |\n|ll cc p                       |\n|ll cc p                       |\n|ll cc p                       |\n|ll cc p                       |\n|ll cc p                       |\n|ll cc p                       |\n|ll cc p                       |\n|ll cc p                       |\n+------------------------------+\n";
	master[4]= "+------------------------------+\n|ll cc p ttt                   |\n|ll cc p ttt                   |\n|ll cc p ttt                   |\n|ll cc p ttt                   |\n|ll cc p ttt                   |\n|ll cc p ttt                   |\n|ll cc p ttt                   |\n|ll cc p ttt                   |\n|ll cc p ttt                   |\n|ll cc p ttt                   |\n|ll cc p ttt                   |\n|ll cc p ttt                   |\n|ll cc p ttt                   |\n|ll cc p ttt                   |\n|ll cc p ttt                   |\n|ll cc p ttt                   |\n|ll cc p ttt                   |\n|ll cc p ttt                   |\n|ll cc p ttt                   |\n|ll cc p ttt                   |\n+------------------------------+\n";
	master[5]= "+------------------------------+\n|ll cc p ttt RRRRRRRRRR        |\n|ll cc p ttt RRRRRRRRRR        |\n|ll cc p ttt RRRRRRRRRR        |\n|ll cc p ttt RRRRRRRRRR        |\n|ll cc p ttt RRRRRRRRRR        |\n|ll cc p ttt RRRRRRRRRR        |\n|ll cc p ttt RRRRRRRRRR        |\n|ll cc p ttt RRRRRRRRRR        |\n|ll cc p ttt RRRRRRRRRR        |\n|ll cc p ttt RRRRRRRRRR        |\n|ll cc p ttt                   |\n|ll cc p ttt                   |\n|ll cc p ttt                   |\n|ll cc p ttt                   |\n|ll cc p ttt                   |\n|ll cc p ttt                   |\n|ll cc p ttt                   |\n|ll cc p ttt                   |\n|ll cc p ttt                   |\n|ll cc p ttt                   |\n+------------------------------+\n";
	master[6]= "+------------------------------+\n|ll cc p ttt RRRRRRRRRR        |\n|ll cc p ttt RRRRRRRRRR        |\n|ll cc p ttt RRRRRRRRRR        |\n|ll cc p ttt RRRRRRRRRR        |\n|ll cc p ttt RRRRRRRRRR        |\n|ll cc p ttt RRRRRRRRRR        |\n|ll cc p ttt RRRRRRRRRR        |\n|ll cc p ttt RRRRRRRRRR        |\n|ll cc p ttt RRRRRRRRRR        |\n|ll cc p ttt RRRRRRRRRR        |\n|ll cc p ttt                   |\n|ll cc p ttt CCCCC             |\n|ll cc p ttt CCCCC             |\n|ll cc p ttt CCCCC             |\n|ll cc p ttt CCCCC             |\n|ll cc p ttt CCCCC             |\n|ll cc p ttt CCCCC             |\n|ll cc p ttt CCCCC             |\n|ll cc p ttt CCCCC             |\n|ll cc p ttt CCCCC             |\n+------------------------------+\n";
	master[7]= "+------------------------------+\n|ll cc p ttt RRRRRRRRRR        |\n|ll cc p ttt RRRRRRRRRR        |\n|ll cc p ttt RRRRRRRRRR        |\n|ll cc p ttt RRRRRRRRRR        |\n|ll cc p ttt RRRRRRRRRR        |\n|ll cc p ttt RRRRRRRRRR        |\n|ll cc p ttt RRRRRRRRRR        |\n|ll cc p ttt RRRRRRRRRR        |\n|ll cc p ttt RRRRRRRRRR        |\n|ll cc p ttt RRRRRRRRRR        |\n|ll cc p ttt                   |\n|ll cc p ttt CCCCC  bbb        |\n|ll cc p ttt CCCCC  bbb        |\n|ll cc p ttt CCCCC  bbb        |\n|ll cc p ttt CCCCC  bbb        |\n|ll cc p ttt CCCCC  bbb        |\n|ll cc p ttt CCCCC  bbb        |\n|ll cc p ttt CCCCC  bbb        |\n|ll cc p ttt CCCCC  bbb        |\n|ll cc p ttt CCCCC  bbb        |\n+------------------------------+\n";
	master[8]= "+------------------------------+\n|ll cc p ttt RRRRRRRRRR rrrrrrr|\n|ll cc p ttt RRRRRRRRRR rrrrrrr|\n|ll cc p ttt RRRRRRRRRR rrrrrrr|\n|ll cc p ttt RRRRRRRRRR rrrrrrr|\n|ll cc p ttt RRRRRRRRRR rrrrrrr|\n|ll cc p ttt RRRRRRRRRR rrrrrrr|\n|ll cc p ttt RRRRRRRRRR rrrrrrr|\n|ll cc p ttt RRRRRRRRRR rrrrrrr|\n|ll cc p ttt RRRRRRRRRR        |\n|ll cc p ttt RRRRRRRRRR        |\n|ll cc p ttt                   |\n|ll cc p ttt CCCCC  bbb        |\n|ll cc p ttt CCCCC  bbb        |\n|ll cc p ttt CCCCC  bbb        |\n|ll cc p ttt CCCCC  bbb        |\n|ll cc p ttt CCCCC  bbb        |\n|ll cc p ttt CCCCC  bbb        |\n|ll cc p ttt CCCCC  bbb        |\n|ll cc p ttt CCCCC  bbb        |\n|ll cc p ttt CCCCC  bbb        |\n+------------------------------+\n";
	master[9]= "+------------------------------+\n|ll cc p ttt RRRRRRRRRR rrrrrrr|\n|ll cc p ttt RRRRRRRRRR rrrrrrr|\n|ll cc p ttt RRRRRRRRRR rrrrrrr|\n|ll cc p ttt RRRRRRRRRR rrrrrrr|\n|ll cc p ttt RRRRRRRRRR rrrrrrr|\n|ll cc p ttt RRRRRRRRRR rrrrrrr|\n|ll cc p ttt RRRRRRRRRR rrrrrrr|\n|ll cc p ttt RRRRRRRRRR rrrrrrr|\n|ll cc p ttt RRRRRRRRRR        |\n|ll cc p ttt RRRRRRRRRR TTTTTTT|\n|ll cc p ttt            TTTTTTT|\n|ll cc p ttt CCCCC  bbb TTTTTTT|\n|ll cc p ttt CCCCC  bbb TTTTTTT|\n|ll cc p ttt CCCCC  bbb TTTTTTT|\n|ll cc p ttt CCCCC  bbb TTTTTTT|\n|ll cc p ttt CCCCC  bbb        |\n|ll cc p ttt CCCCC  bbb        |\n|ll cc p ttt CCCCC  bbb        |\n|ll cc p ttt CCCCC  bbb        |\n|ll cc p ttt CCCCC  bbb        |\n+------------------------------+\n";
	master[10]="+------------------------------+\n|ll cc p ttt RRRRRRRRRR rrrrrrr|\n|ll cc p ttt RRRRRRRRRR rrrrrrr|\n|ll cc p ttt RRRRRRRRRR rrrrrrr|\n|ll cc p ttt RRRRRRRRRR rrrrrrr|\n|ll cc p ttt RRRRRRRRRR rrrrrrr|\n|ll cc p ttt RRRRRRRRRR rrrrrrr|\n|ll cc p ttt RRRRRRRRRR rrrrrrr|\n|ll cc p ttt RRRRRRRRRR rrrrrrr|\n|ll cc p ttt RRRRRRRRRR        |\n|ll cc p ttt RRRRRRRRRR TTTTTTT|\n|ll cc p ttt            TTTTTTT|\n|ll cc p ttt CCCCC  bbb TTTTTTT|\n|ll cc p ttt CCCCC  bbb TTTTTTT|\n|ll cc p ttt CCCCC  bbb TTTTTTT|\n|ll cc p ttt CCCCC  bbb TTTTTTT|\n|ll cc p ttt CCCCC  bbb        |\n|ll cc p ttt CCCCC  bbb sssssss|\n|ll cc p ttt CCCCC  bbb sssssss|\n|ll cc p ttt CCCCC  bbb sssssss|\n|ll cc p ttt CCCCC  bbb sssssss|\n+------------------------------+\n";
	master[11]="+------------------------------+\n|BBBB                          |\n|BBBB                          |\n|BBBB                          |\n|BBBB                          |\n|                              |\n|                              |\n|                              |\n|                              |\n|                              |\n|                              |\n|                              |\n|                              |\n|                              |\n|                              |\n|                              |\n|                              |\n|                              |\n|                              |\n|                              |\n|                              |\n+------------------------------+\n";
	master[12]="+------------------------------+\n|SSSSSSSSSSSSSSSSSSSSSSSSSSSSSS|\n|SSSSSSSSSSSSSSSSSSSSSSSSSSSSSS|\n|SSSSSSSSSSSSSSSSSSSSSSSSSSSSSS|\n|SSSSSSSSSSSSSSSSSSSSSSSSSSSSSS|\n|SSSSSSSSSSSSSSSSSSSSSSSSSSSSSS|\n|SSSSSSSSSSSSSSSSSSSSSSSSSSSSSS|\n|SSSSSSSSSSSSSSSSSSSSSSSSSSSSSS|\n|SSSSSSSSSSSSSSSSSSSSSSSSSSSSSS|\n|SSSSSSSSSSSSSSSSSSSSSSSSSSSSSS|\n|SSSSSSSSSSSSSSSSSSSSSSSSSSSSSS|\n|SSSSSSSSSSSSSSSSSSSSSSSSSSSSSS|\n|SSSSSSSSSSSSSSSSSSSSSSSSSSSSSS|\n|SSSSSSSSSSSSSSSSSSSSSSSSSSSSSS|\n|SSSSSSSSSSSSSSSSSSSSSSSSSSSSSS|\n|SSSSSSSSSSSSSSSSSSSSSSSSSSSSSS|\n|SSSSSSSSSSSSSSSSSSSSSSSSSSSSSS|\n|SSSSSSSSSSSSSSSSSSSSSSSSSSSSSS|\n|SSSSSSSSSSSSSSSSSSSSSSSSSSSSSS|\n|SSSSSSSSSSSSSSSSSSSSSSSSSSSSSS|\n|SSSSSSSSSSSSSSSSSSSSSSSSSSSSSS|\n+------------------------------+\n";

	if(!blankGarden.isEmpty())
        failed("SES Test: isEmpty did not return true",++testNumber, &ok, totalTested);
    else
    	passed("SES Test: isEmpty returned true", ++testNumber, totalPassed,
         totalTested);

	result<<blankGarden;
	if(result.str().length()!=0){
        failed("SES Test: Display attempted to modify the output stream",++testNumber, &ok, totalTested);
	}
    else
    	passed("SES Test: Display did not attempt to modify the output stream", ++testNumber, totalPassed,
         totalTested);

	result.str(std::string());
	if(!blankGarden.isEmpty())
        failed("20/30: isEmpty did not return true",++testNumber, &ok, totalTested);
    else
    	passed("20/30: isEmpty returned true", ++testNumber, totalPassed,
         totalTested);

    result<<garden1;
    if(result.str()!=master[0]){
		failed("20/30: display() did not output the expected result",++testNumber, &ok, totalTested);
	    std::cout<<"--Expected result --"<<std::endl<<master[0]<<"--your result--"<<std::endl<<result.str()<<"--------"<<std::endl;;
	}
	else
	    passed("20/30: display() did not attempt to modify the output stream", ++testNumber, totalPassed,
        	    totalTested);
	garden1=Garden(1,100);
	if(garden1.isEmpty())
        failed("Wide and short: isEmpty did not return false",++testNumber, &ok, totalTested);
    else
    	passed("Wide and short: isEmpty returned false", ++testNumber, totalPassed,
         totalTested);
	result.str(std::string());
	result<<garden1;
	if(result.str().length()==0){
        failed("Wide and short:: display did not attempted to modify the output stream",++testNumber, &ok, totalTested);
	}
    else
    	passed("Wide and short:: display() modify the output stream", ++testNumber, totalPassed,
         totalTested);
	garden1=Garden(100,1);
	if(garden1.isEmpty())
        failed("Thin and Long: isEmpty did not return false",++testNumber, &ok, totalTested);
    else
    	passed("Thin and Long: isEmpty returned false", ++testNumber, totalPassed,
         totalTested);
	result.str(std::string());
	result<<garden1;
	if(result.str().length()==0){
        failed("Thin and Long: display did not attempted to modify the output stream",++testNumber, &ok, totalTested);
	}
    else
    	passed("Thin and Long: display() modify the output stream", ++testNumber, totalPassed,
         totalTested);
    Garden garden2(5,5);
    std::string t1="+-----+\n|cccc |\n|cccc |\n|cccc |\n|cccc |\n|     |\n+-----+\n";
    garden2+=crop1;

	result.str(std::string());
   	garden2.display(result);
	if(result.str()!=t1){
        failed("Simple Crop add: display() did not output the expected result",++testNumber, &ok, totalTested);
        std::cout<<"--Expected result --"<<std::endl<<t1<<"--your result--"<<std::endl<<result.str()<<"--------"<<std::endl;;
	}
    else
    	passed("Simple Crop add: display() did not attempt to modify the output stream", ++testNumber, totalPassed,
         totalTested);
	result.str(std::string());
    garden2.display(result);
	if(result.str()!=t1){
        failed("Simple Crop add: display() did not output the expected result",++testNumber, &ok, totalTested);
        std::cout<<"--Expected result --"<<std::endl<<t1<<"--your result--"<<std::endl<<result.str()<<"--------"<<std::endl;;
	}
    else
    	passed("Simple Crop add: display() did not attempt to modify the output stream", ++testNumber, totalPassed,
         totalTested);
	result.str(std::string());
    result<<garden2;
	if(result.str()!=t1){
        failed("Simple Crop add: operator<< did not output the expected result",++testNumber, &ok, totalTested);
        std::cout<<"--Expected result --"<<std::endl<<t1<<"--your result--"<<std::endl<<result.str()<<"--------"<<std::endl;;
	}
    else
    	passed("Simple Crop add: operator<< did not attempt to modify the output stream", ++testNumber, totalPassed,
         totalTested);

	Garden garden3(20,30);
    Crop crops[10];
    crops[0]=Crop(Plant("Lettuce",'l'), 20,2,0,0);
    crops[1]=Crop(Plant("Carrots",'c'), 20,2,3,0);
    crops[2]=Crop(Plant("Peppers",'p'), 20,1,6,0);
    crops[3]=Crop(Plant("Tomatoes",'t'), 20,3,8,0);
    crops[4]=Crop(Plant("Rhubarb",'R'), 10,10,12,0);
    crops[5]=Crop(Plant("Cabbage",'C'), 9,5,12,11);
    crops[6]=Crop(Plant("Basil",'b'),9,3,19,11);
    crops[7]=Crop(Plant("Rosemary", 'r'),8,7,23,0);
    crops[8]=Crop(Plant("Thyme", 'T'),6,7,23,9);
    crops[9]=Crop(Plant("Squash", 's'),4,7,23,16);

	garden3+=crops[0];
	result.str(std::string());
	result<<garden3;
	if(result.str()!=master[1]){
		failed("crops[0]: your map does not match expected result",++testNumber, &ok, totalTested);
		std::cout<<std::endl<<"Your output:"<<std::endl<<result.str()<<std::endl<<std::endl
		         <<"Expected Output"<<std::endl<<master[1]<<std::endl;
		return false;
	}else
	   	passed("crops[0]: map matches with the expected result", ++testNumber, totalPassed,
         totalTested);

	garden3+=crops[1];
	result.str(std::string());
	result<<garden3;
	if(result.str()!=master[2]){
		failed("crops[1]: your map does not match expected result",++testNumber, &ok, totalTested);
		std::cout<<std::endl<<"Your output:"<<std::endl<<result.str()<<std::endl<<std::endl
		         <<"Expected Output"<<std::endl<<master[1]<<std::endl;
		return false;
	}else
	   	passed("crops[1]: map matches with the expected result", ++testNumber, totalPassed,
         totalTested);

	garden3+=crops[2];
	result.str(std::string());
	result<<garden3;
	if(result.str()!=master[3]){
		failed("crops[2]: your map does not match expected result",++testNumber, &ok, totalTested);
		std::cout<<std::endl<<"Your output:"<<std::endl<<result.str()<<std::endl<<std::endl
		         <<"Expected Output"<<std::endl<<master[3]<<std::endl;
		return false;
	}else
	   	passed("crops[2]: map matches with the expected result", ++testNumber, totalPassed,
         totalTested);

	garden3+=crops[3];
	result.str(std::string());
	result<<garden3;
	if(result.str()!=master[4]){
		failed("crops[3]: your map does not match expected result",++testNumber, &ok, totalTested);
		std::cout<<std::endl<<"Your output:"<<std::endl<<result.str()<<std::endl<<std::endl
		         <<"Expected Output"<<std::endl<<master[4]<<std::endl;
		return false;
	}else
	   	passed("crops[3]: map matches with the expected result", ++testNumber, totalPassed,
         totalTested);

	garden3+=crops[4];
	result.str(std::string());
	result<<garden3;
	if(result.str()!=master[5]){
		failed("crops[4]: your map does not match expected result",++testNumber, &ok, totalTested);
		std::cout<<std::endl<<"Your output:"<<std::endl<<result.str()<<std::endl<<std::endl
		         <<"Expected Output"<<std::endl<<master[5]<<std::endl;
		return false;
	}else
	   	passed("crops[4]: map matches with the expected result", ++testNumber, totalPassed,
         totalTested);

	garden3+=crops[5];
	result.str(std::string());
	result<<garden3;
	if(result.str()!=master[6]){
		failed("crops[5]: your map does not match expected result",++testNumber, &ok, totalTested);
		std::cout<<std::endl<<"Your output:"<<std::endl<<result.str()<<std::endl<<std::endl
		         <<"Expected Output"<<std::endl<<master[6]<<std::endl;
		return false;
	}else
	   	passed("crops[5]: map matches with the expected result", ++testNumber, totalPassed,
         totalTested);

	garden3+=crops[6];
	result.str(std::string());
	result<<garden3;
	if(result.str()!=master[7]){
		failed("crops[6]: your map does not match expected result",++testNumber, &ok, totalTested);
		std::cout<<std::endl<<"Your output:"<<std::endl<<result.str()<<std::endl<<std::endl
		         <<"Expected Output"<<std::endl<<master[7]<<std::endl;
		return false;
	}else
	   	passed("crops[6]: map matches with the expected result", ++testNumber, totalPassed,
         totalTested);

	garden3+=crops[7];
	result.str(std::string());
	result<<garden3;
	if(result.str()!=master[8]){
		failed("crops[7]: your map does not match expected result",++testNumber, &ok, totalTested);
		std::cout<<std::endl<<"Your output:"<<std::endl<<result.str()<<std::endl<<std::endl
		         <<"Expected Output"<<std::endl<<master[8]<<std::endl;
		return false;
	}else
	   	passed("crops[7]: map matches with the expected result", ++testNumber, totalPassed,
         totalTested);

	garden3+=crops[8];
	result.str(std::string());
	result<<garden3;
	if(result.str()!=master[9]){
		failed("crops[8]: your map does not match expected result",++testNumber, &ok, totalTested);
		std::cout<<std::endl<<"Your output:"<<std::endl<<result.str()<<std::endl<<std::endl
		         <<"Expected Output"<<std::endl<<master[9]<<std::endl;
		return false;
	}else
	   	passed("crops[8]: map matches with the expected result", ++testNumber, totalPassed,
         totalTested);

	garden3+=crops[9];
	result.str(std::string());
	result<<garden3;
	if(result.str()!=master[10]){
		failed("crops[9]: your map does not match expected result",++testNumber, &ok, totalTested);
		std::cout<<std::endl<<"Your output:"<<std::endl<<result.str()<<std::endl<<std::endl
		         <<"Expected Output"<<std::endl<<master[10]<<std::endl;
		return false;
	}else
	   	passed("crops[9]: map matches with the expected result", ++testNumber, totalPassed,
         totalTested);

	//creating output file for file portion
	std::cout<<"Outputting garden to a file"<<std::endl;
	std::ofstream of("SampleGarden.txt");
	of<<garden3;
	std::ifstream fin;
	//Garden
	Garden garden;
	std::string PrevGarFile="10 20 30\n20 2 0 0 l Lettuce\n20 2 3 0 c Carrots\n20 1 6 0 p Peppers\n20 3 8 0 t Tomatoes\n10 10 12 0 R Rhubarb\n9 5 12 11 C Cabbage\n9 3 19 11 b Basil\n8 7 23 0 r Rosemary\n6 7 23 9 T Thyme\n4 7 23 16 s Squash\n";
	std::string PrevGard="+------------------------------+\n|ll cc p ttt RRRRRRRRRR rrrrrrr|\n|ll cc p ttt RRRRRRRRRR rrrrrrr|\n|ll cc p ttt RRRRRRRRRR rrrrrrr|\n|ll cc p ttt RRRRRRRRRR rrrrrrr|\n|ll cc p ttt RRRRRRRRRR rrrrrrr|\n|ll cc p ttt RRRRRRRRRR rrrrrrr|\n|ll cc p ttt RRRRRRRRRR rrrrrrr|\n|ll cc p ttt RRRRRRRRRR rrrrrrr|\n|ll cc p ttt RRRRRRRRRR        |\n|ll cc p ttt RRRRRRRRRR TTTTTTT|\n|ll cc p ttt            TTTTTTT|\n|ll cc p ttt CCCCC  bbb TTTTTTT|\n|ll cc p ttt CCCCC  bbb TTTTTTT|\n|ll cc p ttt CCCCC  bbb TTTTTTT|\n|ll cc p ttt CCCCC  bbb TTTTTTT|\n|ll cc p ttt CCCCC  bbb        |\n|ll cc p ttt CCCCC  bbb sssssss|\n|ll cc p ttt CCCCC  bbb sssssss|\n|ll cc p ttt CCCCC  bbb sssssss|\n|ll cc p ttt CCCCC  bbb sssssss|\n+------------------------------+\n";
	  //input
		fin.open("SampleGarden.txt");
		result.str(std::string());
		garden=Garden();//Blank out
		result<<fin.rdbuf();
		fin.close();
		if(result.str()!=PrevGarFile){
			failed("SampleGarden.txt: Contents of the file does not match with expected results",++testNumber, &ok, totalTested);
			std::cout<<std::endl<<"Your output:"<<std::endl<<result.str()<<std::endl<<std::endl
			         <<"Expected Output"<<std::endl<<PrevGarFile<<std::endl;
			return false;
		}else
		   	passed("SampleGarden.txt:matches with the expected result", ++testNumber, totalPassed,
	         totalTested);

	    garden=Garden();//Blank out
	    fin.open("SampleGarden.txt");
	    fin>>garden;
		if(garden.isEmpty())
			failed("fin>>garden: isEmpty did not return false",++testNumber, &ok, totalTested);
		else
			passed("fin>>garden: isEmpty returned false", ++testNumber, totalPassed,
		 totalTested);
		result.str(std::string());
	    result<<garden;
		if(result.str()!=PrevGard){
	        failed("fin>>garden: operator<< did not output the expected result",++testNumber, &ok, totalTested);
	        std::cout<<"--Expected result --"<<std::endl<<PrevGard<<"--your result--"<<std::endl<<result.str()<<"--------"<<std::endl;;
		}
	    else
	    	passed("fin>>garden: operator<< matches with expected result", ++testNumber, totalPassed,
	         totalTested);
	    fin.close();

	//Garden ctor
	std::cout<<"Passing nullptr to Graden(const char*)"<<std::endl;
	Garden blank(nullptr);
	if(!blank.isEmpty())
        failed("SES Test: isEmpty did not return true",++testNumber, &ok, totalTested);
    else
    	passed("SES Test: isEmpty returned true", ++testNumber, totalPassed,
         totalTested);
	std::cout<<"File Stability tests complete"<<std::endl<<std::endl;

	    garden=Garden();//Blank out
	    garden=Garden("SampleGarden.txt");
		if(garden.isEmpty())
			failed("Garden(\"SampleGarden.txt\"): isEmpty did not return false",++testNumber, &ok, totalTested);
		else
			passed("Garden(\"SampleGarden.txt\"): isEmpty returned false", ++testNumber, totalPassed,
		 totalTested);
		result.str(std::string());
	    result<<garden;
		if(result.str()!=PrevGard){
	        failed("Garden(\"SampleGarden.txt\"): operator<< did not output the expected result",++testNumber, &ok, totalTested);
	        std::cout<<"--Expected result --"<<std::endl<<PrevGard<<"--your result--"<<std::endl<<result.str()<<"--------"<<std::endl;;
		}
	    else
	    	passed("Garden(\"SampleGarden.txt\"): operator<< matches with expected result", ++testNumber, totalPassed,
	         totalTested);
    return ok;
}

bool DetailedGardenTests(int& testNumber, int* totalPassed, int* totalTested){
    bool ok = true;
	Plant blankPlant;
	Plant plant1("Cabbage", 'c');
	Crop blankCrop;
	Crop crop1(plant1,4,4,0,0);
	DetailedGarden blankDetailedGarden;
	DetailedGarden garden1("First Garden", 20,30);

	std::stringstream result;
	std::string master[13];
	master[0]= "+------------------------------+\n|                              |\n|                              |\n|                              |\n|                              |\n|                              |\n|                              |\n|                              |\n|                              |\n|                              |\n|                              |\n|                              |\n|                              |\n|                              |\n|                              |\n|                              |\n|                              |\n|                              |\n|                              |\n|                              |\n|                              |\n+------------------------------+\nFirst Garden\n";
	master[1]= "+------------------------------+\n|ll                            |\n|ll                            |\n|ll                            |\n|ll                            |\n|ll                            |\n|ll                            |\n|ll                            |\n|ll                            |\n|ll                            |\n|ll                            |\n|ll                            |\n|ll                            |\n|ll                            |\n|ll                            |\n|ll                            |\n|ll                            |\n|ll                            |\n|ll                            |\n|ll                            |\n|ll                            |\n+------------------------------+\nMy first Garden\n";
	master[2]= "+------------------------------+\n|ll cc                         |\n|ll cc                         |\n|ll cc                         |\n|ll cc                         |\n|ll cc                         |\n|ll cc                         |\n|ll cc                         |\n|ll cc                         |\n|ll cc                         |\n|ll cc                         |\n|ll cc                         |\n|ll cc                         |\n|ll cc                         |\n|ll cc                         |\n|ll cc                         |\n|ll cc                         |\n|ll cc                         |\n|ll cc                         |\n|ll cc                         |\n|ll cc                         |\n+------------------------------+\nMy first Garden\n";
	master[3]= "+------------------------------+\n|ll cc p                       |\n|ll cc p                       |\n|ll cc p                       |\n|ll cc p                       |\n|ll cc p                       |\n|ll cc p                       |\n|ll cc p                       |\n|ll cc p                       |\n|ll cc p                       |\n|ll cc p                       |\n|ll cc p                       |\n|ll cc p                       |\n|ll cc p                       |\n|ll cc p                       |\n|ll cc p                       |\n|ll cc p                       |\n|ll cc p                       |\n|ll cc p                       |\n|ll cc p                       |\n|ll cc p                       |\n+------------------------------+\nMy first Garden\n";
	master[4]= "+------------------------------+\n|ll cc p ttt                   |\n|ll cc p ttt                   |\n|ll cc p ttt                   |\n|ll cc p ttt                   |\n|ll cc p ttt                   |\n|ll cc p ttt                   |\n|ll cc p ttt                   |\n|ll cc p ttt                   |\n|ll cc p ttt                   |\n|ll cc p ttt                   |\n|ll cc p ttt                   |\n|ll cc p ttt                   |\n|ll cc p ttt                   |\n|ll cc p ttt                   |\n|ll cc p ttt                   |\n|ll cc p ttt                   |\n|ll cc p ttt                   |\n|ll cc p ttt                   |\n|ll cc p ttt                   |\n|ll cc p ttt                   |\n+------------------------------+\nMy first Garden\n";
	master[5]= "+------------------------------+\n|ll cc p ttt RRRRRRRRRR        |\n|ll cc p ttt RRRRRRRRRR        |\n|ll cc p ttt RRRRRRRRRR        |\n|ll cc p ttt RRRRRRRRRR        |\n|ll cc p ttt RRRRRRRRRR        |\n|ll cc p ttt RRRRRRRRRR        |\n|ll cc p ttt RRRRRRRRRR        |\n|ll cc p ttt RRRRRRRRRR        |\n|ll cc p ttt RRRRRRRRRR        |\n|ll cc p ttt RRRRRRRRRR        |\n|ll cc p ttt                   |\n|ll cc p ttt                   |\n|ll cc p ttt                   |\n|ll cc p ttt                   |\n|ll cc p ttt                   |\n|ll cc p ttt                   |\n|ll cc p ttt                   |\n|ll cc p ttt                   |\n|ll cc p ttt                   |\n|ll cc p ttt                   |\n+------------------------------+\nMy first Garden\n";
	master[6]= "+------------------------------+\n|ll cc p ttt RRRRRRRRRR        |\n|ll cc p ttt RRRRRRRRRR        |\n|ll cc p ttt RRRRRRRRRR        |\n|ll cc p ttt RRRRRRRRRR        |\n|ll cc p ttt RRRRRRRRRR        |\n|ll cc p ttt RRRRRRRRRR        |\n|ll cc p ttt RRRRRRRRRR        |\n|ll cc p ttt RRRRRRRRRR        |\n|ll cc p ttt RRRRRRRRRR        |\n|ll cc p ttt RRRRRRRRRR        |\n|ll cc p ttt                   |\n|ll cc p ttt CCCCC             |\n|ll cc p ttt CCCCC             |\n|ll cc p ttt CCCCC             |\n|ll cc p ttt CCCCC             |\n|ll cc p ttt CCCCC             |\n|ll cc p ttt CCCCC             |\n|ll cc p ttt CCCCC             |\n|ll cc p ttt CCCCC             |\n|ll cc p ttt CCCCC             |\n+------------------------------+\nMy first Garden\n";
	master[7]= "+------------------------------+\n|ll cc p ttt RRRRRRRRRR        |\n|ll cc p ttt RRRRRRRRRR        |\n|ll cc p ttt RRRRRRRRRR        |\n|ll cc p ttt RRRRRRRRRR        |\n|ll cc p ttt RRRRRRRRRR        |\n|ll cc p ttt RRRRRRRRRR        |\n|ll cc p ttt RRRRRRRRRR        |\n|ll cc p ttt RRRRRRRRRR        |\n|ll cc p ttt RRRRRRRRRR        |\n|ll cc p ttt RRRRRRRRRR        |\n|ll cc p ttt                   |\n|ll cc p ttt CCCCC  bbb        |\n|ll cc p ttt CCCCC  bbb        |\n|ll cc p ttt CCCCC  bbb        |\n|ll cc p ttt CCCCC  bbb        |\n|ll cc p ttt CCCCC  bbb        |\n|ll cc p ttt CCCCC  bbb        |\n|ll cc p ttt CCCCC  bbb        |\n|ll cc p ttt CCCCC  bbb        |\n|ll cc p ttt CCCCC  bbb        |\n+------------------------------+\nMy first Garden\n";
	master[8]= "+------------------------------+\n|ll cc p ttt RRRRRRRRRR rrrrrrr|\n|ll cc p ttt RRRRRRRRRR rrrrrrr|\n|ll cc p ttt RRRRRRRRRR rrrrrrr|\n|ll cc p ttt RRRRRRRRRR rrrrrrr|\n|ll cc p ttt RRRRRRRRRR rrrrrrr|\n|ll cc p ttt RRRRRRRRRR rrrrrrr|\n|ll cc p ttt RRRRRRRRRR rrrrrrr|\n|ll cc p ttt RRRRRRRRRR rrrrrrr|\n|ll cc p ttt RRRRRRRRRR        |\n|ll cc p ttt RRRRRRRRRR        |\n|ll cc p ttt                   |\n|ll cc p ttt CCCCC  bbb        |\n|ll cc p ttt CCCCC  bbb        |\n|ll cc p ttt CCCCC  bbb        |\n|ll cc p ttt CCCCC  bbb        |\n|ll cc p ttt CCCCC  bbb        |\n|ll cc p ttt CCCCC  bbb        |\n|ll cc p ttt CCCCC  bbb        |\n|ll cc p ttt CCCCC  bbb        |\n|ll cc p ttt CCCCC  bbb        |\n+------------------------------+\nMy first Garden\n";
	master[9]= "+------------------------------+\n|ll cc p ttt RRRRRRRRRR rrrrrrr|\n|ll cc p ttt RRRRRRRRRR rrrrrrr|\n|ll cc p ttt RRRRRRRRRR rrrrrrr|\n|ll cc p ttt RRRRRRRRRR rrrrrrr|\n|ll cc p ttt RRRRRRRRRR rrrrrrr|\n|ll cc p ttt RRRRRRRRRR rrrrrrr|\n|ll cc p ttt RRRRRRRRRR rrrrrrr|\n|ll cc p ttt RRRRRRRRRR rrrrrrr|\n|ll cc p ttt RRRRRRRRRR        |\n|ll cc p ttt RRRRRRRRRR TTTTTTT|\n|ll cc p ttt            TTTTTTT|\n|ll cc p ttt CCCCC  bbb TTTTTTT|\n|ll cc p ttt CCCCC  bbb TTTTTTT|\n|ll cc p ttt CCCCC  bbb TTTTTTT|\n|ll cc p ttt CCCCC  bbb TTTTTTT|\n|ll cc p ttt CCCCC  bbb        |\n|ll cc p ttt CCCCC  bbb        |\n|ll cc p ttt CCCCC  bbb        |\n|ll cc p ttt CCCCC  bbb        |\n|ll cc p ttt CCCCC  bbb        |\n+------------------------------+\nMy first Garden\n";
	master[10]="+------------------------------+\n|ll cc p ttt RRRRRRRRRR rrrrrrr|\n|ll cc p ttt RRRRRRRRRR rrrrrrr|\n|ll cc p ttt RRRRRRRRRR rrrrrrr|\n|ll cc p ttt RRRRRRRRRR rrrrrrr|\n|ll cc p ttt RRRRRRRRRR rrrrrrr|\n|ll cc p ttt RRRRRRRRRR rrrrrrr|\n|ll cc p ttt RRRRRRRRRR rrrrrrr|\n|ll cc p ttt RRRRRRRRRR rrrrrrr|\n|ll cc p ttt RRRRRRRRRR        |\n|ll cc p ttt RRRRRRRRRR TTTTTTT|\n|ll cc p ttt            TTTTTTT|\n|ll cc p ttt CCCCC  bbb TTTTTTT|\n|ll cc p ttt CCCCC  bbb TTTTTTT|\n|ll cc p ttt CCCCC  bbb TTTTTTT|\n|ll cc p ttt CCCCC  bbb TTTTTTT|\n|ll cc p ttt CCCCC  bbb        |\n|ll cc p ttt CCCCC  bbb sssssss|\n|ll cc p ttt CCCCC  bbb sssssss|\n|ll cc p ttt CCCCC  bbb sssssss|\n|ll cc p ttt CCCCC  bbb sssssss|\n+------------------------------+\nMy first Garden\n";
	master[11]="+------------------------------+\n|BBBB                          |\n|BBBB                          |\n|BBBB                          |\n|BBBB                          |\n|                              |\n|                              |\n|                              |\n|                              |\n|                              |\n|                              |\n|                              |\n|                              |\n|                              |\n|                              |\n|                              |\n|                              |\n|                              |\n|                              |\n|                              |\n|                              |\n+------------------------------+\n";
	master[12]="+------------------------------+\n|SSSSSSSSSSSSSSSSSSSSSSSSSSSSSS|\n|SSSSSSSSSSSSSSSSSSSSSSSSSSSSSS|\n|SSSSSSSSSSSSSSSSSSSSSSSSSSSSSS|\n|SSSSSSSSSSSSSSSSSSSSSSSSSSSSSS|\n|SSSSSSSSSSSSSSSSSSSSSSSSSSSSSS|\n|SSSSSSSSSSSSSSSSSSSSSSSSSSSSSS|\n|SSSSSSSSSSSSSSSSSSSSSSSSSSSSSS|\n|SSSSSSSSSSSSSSSSSSSSSSSSSSSSSS|\n|SSSSSSSSSSSSSSSSSSSSSSSSSSSSSS|\n|SSSSSSSSSSSSSSSSSSSSSSSSSSSSSS|\n|SSSSSSSSSSSSSSSSSSSSSSSSSSSSSS|\n|SSSSSSSSSSSSSSSSSSSSSSSSSSSSSS|\n|SSSSSSSSSSSSSSSSSSSSSSSSSSSSSS|\n|SSSSSSSSSSSSSSSSSSSSSSSSSSSSSS|\n|SSSSSSSSSSSSSSSSSSSSSSSSSSSSSS|\n|SSSSSSSSSSSSSSSSSSSSSSSSSSSSSS|\n|SSSSSSSSSSSSSSSSSSSSSSSSSSSSSS|\n|SSSSSSSSSSSSSSSSSSSSSSSSSSSSSS|\n|SSSSSSSSSSSSSSSSSSSSSSSSSSSSSS|\n|SSSSSSSSSSSSSSSSSSSSSSSSSSSSSS|\n+------------------------------+\n";

	if(!blankDetailedGarden.isEmpty())
        failed("SES Test: isEmpty did not return true",++testNumber, &ok, totalTested);
    else
    	passed("SES Test: isEmpty returned true", ++testNumber, totalPassed,
         totalTested);

	result<<blankDetailedGarden;
	if(result.str().length()!=0){
        failed("SES Test: Display attempted to modify the output stream",++testNumber, &ok, totalTested);
	}
    else
    	passed("SES Test: Display did not attempt to modify the output stream", ++testNumber, totalPassed,
         totalTested);

	result.str(std::string());
	if(!blankDetailedGarden.isEmpty())
        failed("20/30: isEmpty did not return true",++testNumber, &ok, totalTested);
    else
    	passed("20/30: isEmpty returned true", ++testNumber, totalPassed,
         totalTested);

    result<<garden1;
    if(result.str()!=master[0]){
		failed("20/30: display() did not output the expected result",++testNumber, &ok, totalTested);
	    std::cout<<"--Expected result --"<<std::endl<<master[0]<<"--your result--"<<std::endl<<result.str()<<"--------"<<std::endl;;
	}
	else
	    passed("20/30: display() did not attempt to modify the output stream", ++testNumber, totalPassed,
        	    totalTested);
	garden1=DetailedGarden("Thin and Wide",1,100);
	if(garden1.isEmpty())
        failed("Wide and short: isEmpty did not return false",++testNumber, &ok, totalTested);
    else
    	passed("Wide and short: isEmpty returned false", ++testNumber, totalPassed,
         totalTested);
	result.str(std::string());
	result<<garden1;
	if(result.str().length()==0){
        failed("Wide and short:: display did not attempted to modify the output stream",++testNumber, &ok, totalTested);
	}
    else
    	passed("Wide and short:: display() modify the output stream", ++testNumber, totalPassed,
         totalTested);
	garden1=DetailedGarden("Long and narrow",100,1);
	if(garden1.isEmpty())
        failed("Thin and Long: isEmpty did not return false",++testNumber, &ok, totalTested);
    else
    	passed("Thin and Long: isEmpty returned false", ++testNumber, totalPassed,
         totalTested);
	result.str(std::string());
	result<<garden1;
	if(result.str().length()==0){
        failed("Thin and Long: display did not attempted to modify the output stream",++testNumber, &ok, totalTested);
	}
    else
    	passed("Thin and Long: display() modify the output stream", ++testNumber, totalPassed,
         totalTested);
    DetailedGarden garden2("A small Garden", 5,5);
    std::string t1="+-----+\n|cccc |\n|cccc |\n|cccc |\n|cccc |\n|     |\n+-----+\nA small Garden\n";
    garden2+=crop1;

	result.str(std::string());
   	garden2.display(result);
	if(result.str()!=t1){
        failed("Simple Crop add: display() did not output the expected result",++testNumber, &ok, totalTested);
        std::cout<<"--Expected result --"<<std::endl<<t1<<"--your result--"<<std::endl<<result.str()<<"--------"<<std::endl;;
	}
    else
    	passed("Simple Crop add: display() did not attempt to modify the output stream", ++testNumber, totalPassed,
         totalTested);
	result.str(std::string());
    garden2.display(result);
	if(result.str()!=t1){
        failed("Simple Crop add: display() did not output the expected result",++testNumber, &ok, totalTested);
        std::cout<<"--Expected result --"<<std::endl<<t1<<"--your result--"<<std::endl<<result.str()<<"--------"<<std::endl;;
	}
    else
    	passed("Simple Crop add: display() did not attempt to modify the output stream", ++testNumber, totalPassed,
         totalTested);
	result.str(std::string());
    result<<garden2;
	if(result.str()!=t1){
        failed("Simple Crop add: operator<< did not output the expected result",++testNumber, &ok, totalTested);
        std::cout<<"--Expected result --"<<std::endl<<t1<<"--your result--"<<std::endl<<result.str()<<"--------"<<std::endl;;
	}
    else
    	passed("Simple Crop add: operator<< did not attempt to modify the output stream", ++testNumber, totalPassed,
         totalTested);

	DetailedGarden garden3("My first Garden",20,30);
    Crop crops[10];
    crops[0]=Crop(Plant("Lettuce",'l'), 20,2,0,0);
    crops[1]=Crop(Plant("Carrots",'c'), 20,2,3,0);
    crops[2]=Crop(Plant("Peppers",'p'), 20,1,6,0);
    crops[3]=Crop(Plant("Tomatoes",'t'), 20,3,8,0);
    crops[4]=Crop(Plant("Rhubarb",'R'), 10,10,12,0);
    crops[5]=Crop(Plant("Cabbage",'C'), 9,5,12,11);
    crops[6]=Crop(Plant("Basil",'b'),9,3,19,11);
    crops[7]=Crop(Plant("Rosemary", 'r'),8,7,23,0);
    crops[8]=Crop(Plant("Thyme", 'T'),6,7,23,9);
    crops[9]=Crop(Plant("Squash", 's'),4,7,23,16);

	garden3+=crops[0];
	result.str(std::string());
	result<<garden3;
	if(result.str()!=master[1]){
		failed("crops[0]: your map does not match expected result",++testNumber, &ok, totalTested);
		std::cout<<std::endl<<"Your output:"<<std::endl<<result.str()<<std::endl<<std::endl
		         <<"Expected Output"<<std::endl<<master[1]<<std::endl;
		return false;
	}else
	   	passed("crops[0]: map matches with the expected result", ++testNumber, totalPassed,
         totalTested);

	garden3+=crops[1];
	result.str(std::string());
	result<<garden3;
	if(result.str()!=master[2]){
		failed("crops[1]: your map does not match expected result",++testNumber, &ok, totalTested);
		std::cout<<std::endl<<"Your output:"<<std::endl<<result.str()<<std::endl<<std::endl
		         <<"Expected Output"<<std::endl<<master[1]<<std::endl;
		return false;
	}else
	   	passed("crops[1]: map matches with the expected result", ++testNumber, totalPassed,
         totalTested);

	garden3+=crops[2];
	result.str(std::string());
	result<<garden3;
	if(result.str()!=master[3]){
		failed("crops[2]: your map does not match expected result",++testNumber, &ok, totalTested);
		std::cout<<std::endl<<"Your output:"<<std::endl<<result.str()<<std::endl<<std::endl
		         <<"Expected Output"<<std::endl<<master[3]<<std::endl;
		return false;
	}else
	   	passed("crops[2]: map matches with the expected result", ++testNumber, totalPassed,
         totalTested);

	garden3+=crops[3];
	result.str(std::string());
	result<<garden3;
	if(result.str()!=master[4]){
		failed("crops[3]: your map does not match expected result",++testNumber, &ok, totalTested);
		std::cout<<std::endl<<"Your output:"<<std::endl<<result.str()<<std::endl<<std::endl
		         <<"Expected Output"<<std::endl<<master[4]<<std::endl;
		return false;
	}else
	   	passed("crops[3]: map matches with the expected result", ++testNumber, totalPassed,
         totalTested);

	garden3+=crops[4];
	result.str(std::string());
	result<<garden3;
	if(result.str()!=master[5]){
		failed("crops[4]: your map does not match expected result",++testNumber, &ok, totalTested);
		std::cout<<std::endl<<"Your output:"<<std::endl<<result.str()<<std::endl<<std::endl
		         <<"Expected Output"<<std::endl<<master[5]<<std::endl;
		return false;
	}else
	   	passed("crops[4]: map matches with the expected result", ++testNumber, totalPassed,
         totalTested);

	garden3+=crops[5];
	result.str(std::string());
	result<<garden3;
	if(result.str()!=master[6]){
		failed("crops[5]: your map does not match expected result",++testNumber, &ok, totalTested);
		std::cout<<std::endl<<"Your output:"<<std::endl<<result.str()<<std::endl<<std::endl
		         <<"Expected Output"<<std::endl<<master[6]<<std::endl;
		return false;
	}else
	   	passed("crops[5]: map matches with the expected result", ++testNumber, totalPassed,
         totalTested);

	garden3+=crops[6];
	result.str(std::string());
	result<<garden3;
	if(result.str()!=master[7]){
		failed("crops[6]: your map does not match expected result",++testNumber, &ok, totalTested);
		std::cout<<std::endl<<"Your output:"<<std::endl<<result.str()<<std::endl<<std::endl
		         <<"Expected Output"<<std::endl<<master[7]<<std::endl;
		return false;
	}else
	   	passed("crops[6]: map matches with the expected result", ++testNumber, totalPassed,
         totalTested);

	garden3+=crops[7];
	result.str(std::string());
	result<<garden3;
	if(result.str()!=master[8]){
		failed("crops[7]: your map does not match expected result",++testNumber, &ok, totalTested);
		std::cout<<std::endl<<"Your output:"<<std::endl<<result.str()<<std::endl<<std::endl
		         <<"Expected Output"<<std::endl<<master[8]<<std::endl;
		return false;
	}else
	   	passed("crops[7]: map matches with the expected result", ++testNumber, totalPassed,
         totalTested);

	garden3+=crops[8];
	result.str(std::string());
	result<<garden3;
	if(result.str()!=master[9]){
		failed("crops[8]: your map does not match expected result",++testNumber, &ok, totalTested);
		std::cout<<std::endl<<"Your output:"<<std::endl<<result.str()<<std::endl<<std::endl
		         <<"Expected Output"<<std::endl<<master[9]<<std::endl;
		return false;
	}else
	   	passed("crops[8]: map matches with the expected result", ++testNumber, totalPassed,
         totalTested);

	garden3+=crops[9];
	result.str(std::string());
	result<<garden3;
	if(result.str()!=master[10]){
		failed("crops[9]: your map does not match expected result",++testNumber, &ok, totalTested);
		std::cout<<std::endl<<"Your output:"<<std::endl<<result.str()<<std::endl<<std::endl
		         <<"Expected Output"<<std::endl<<master[10]<<std::endl;
		return false;
	}else
	   	passed("crops[9]: map matches with the expected result", ++testNumber, totalPassed,
         totalTested);

	//Copy consistency check
	DetailedGarden garden6;
	garden6=garden3;
	result.str(std::string());
	result<<garden6;
	if(result.str()!=master[10]){
		failed("Copy Check: your map does not match expected result",++testNumber, &ok, totalTested);
		std::cout<<std::endl<<"Your output:"<<std::endl<<result.str()<<std::endl<<std::endl
		         <<"Expected Output"<<std::endl<<master[10]<<std::endl;
		return false;
	}else
	   	passed("self assignment: map matches with the expected result", ++testNumber, totalPassed,
         totalTested);


    //self assignment check
    garden3=garden3;
	result.str(std::string());
	result<<garden3;
	if(result.str()!=master[10]){
		failed("self assignment: changed the object",++testNumber, &ok, totalTested);
		std::cout<<std::endl<<"Your output:"<<std::endl<<result.str()<<std::endl<<std::endl
		         <<"Expected Output"<<std::endl<<master[10]<<std::endl;
		return false;
	}else
	   	passed("self assignment: map matches with the expected result", ++testNumber, totalPassed,
         totalTested);
    return ok;
}


/* passed displays passing message, increments *totalPassed and *total
*  i holds test number
*/
void passed(const char* message, int i, int* totalPassed, int* total) {
    if (DEBUG && message[0] != '\0')
        std::cout << "Passed test " << std::setw(4) << i << " (" << message << ")\n";
    ++*totalPassed;
    ++*total;
}

/* failed displays failure message, resets *ok to false, increments *total
*  i holds test number
*/
void failed(const char* message, int i, bool* ok, int* total) {
    std::cout << "Failed test " << std::setw(4) << i << " (" << message << ")\n";
    *ok = false;
    ++*total;
}

bool compare(const char *map, const char *master, int size){
	bool same=true;
	int i;
	for( i=0; i<size && same;i++)
		same= map[i]==master[i];
	return same;
}

void displayHeader(int wid){
	std::cout<<std::endl<<"   " ;
	for (int i=1; i<=wid;i++){
		if(i/10==0)
			std::cout<<' ';
		else
			std::cout<<i/10;
	}
	std::cout<<"      ";
	for (int i=1; i<=wid;i++){
		if(i/10==0)
			std::cout<<' ';
		else
			std::cout<<i/10;
	}
	std::cout<<std::endl<<"   ";
	for (int i=1; i<=wid;i++)
		std::cout<<i%10;
	std::cout<<"      ";
	for (int i=1; i<=wid;i++)
		std::cout<<i%10;

	std::cout<<std::endl;
	std::cout<<"  +";
	for(int i=0; i<wid; i++)
		std::cout<<'-';
	std::cout<<'+';
	std::cout<<"    ";
	std::cout<<"+";
	for(int i=0; i<wid; i++)
		std::cout<<'-';
	std::cout<<'+'<<std::endl;
}

//Displays map footer based on the width (wid) provided
void displayFooter(int wid){
	std::cout<<"  +";
	for(int i=0; i<wid; i++)
		std::cout<<'-';
	std::cout<<"+    ";
	std::cout<<"+";
	for(int i=0; i<wid; i++)
		std::cout<<'-';
	std::cout<<"+    "<<std::endl;
}

void displaySBS(const char *map, const char *master, int len, int wid){
	displayHeader(wid);
	for(int i=0; i<len; i++){
		std::cout.width(2);
		std::cout<<i+1<<'|';
		for(int j=0; j<wid;j++)
			std::cout<<map[i*wid+j];
		std::cout<<"|  ";
		std::cout.width(2);
		std::cout<<i+1<<'|';
		for(int j=0; j<wid;j++)
			std::cout<<master[i*wid+j];
		std::cout<<'|'<<std::endl;
	}
	displayFooter(wid);
	std::cout<<"   "<<"Your Map"<<std::setw(wid+6)<<
		      "Should be"<<std::endl<<std::endl;
}
