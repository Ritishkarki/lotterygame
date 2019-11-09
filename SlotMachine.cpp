// slotmachine implementation
#include "Reel.h"
#include "iostream"
#include "string"
using namespace std;
class SlotMachine{
    private:
        ReelList<char> *Reel[3];
        char Reel1Result;
        char Reel2Result;
        char Reel3Result;
        std::string result;

    public:
        // SlotMachine constructor
        SlotMachine(){}

        // spin method to generate random numbers
        std::string spin(){
            //make three reel list
            Reel[0] = new ReelList<char>();
            Reel[1] = new ReelList<char>();
            Reel[2] = new ReelList<char>();

            // reset the result in every spin to make it empty and add 3 results
            result ="";

            // spin the three reels and store the results
            Reel1Result = Reel[0] -> spin();
            Reel2Result = Reel[1] -> spin();
            Reel3Result = Reel[2] -> spin();
            result += Reel1Result;
            result += Reel2Result;
            result += Reel3Result;

            // display the spin result 
            cout << endl << " ------------------------ " << endl;
            cout << "| Spin result |  " << Reel1Result << " " << Reel2Result << " " << Reel3Result << "   |" << endl;
            cout << " ------------------------ " << endl << endl;
            
            delete(Reel[0]);
            delete(Reel[1]);
            delete(Reel[2]);

            // return the result for cash prize calculation
            return result;
        }

        // destructor
        ~SlotMachine(){}
};
