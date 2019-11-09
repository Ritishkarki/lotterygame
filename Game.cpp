#include <iostream>
#include "SlotMachine.cpp"
#include "PayoutTable.cpp"
#include "string"
using namespace std;
class Game {
    private:
        int InitialCash;
    public:
        Game(){
            InitialCash = 100;
        }

        string SpinSlotMachine(){
            // make a instance of slot machine
            SlotMachine *machine = new SlotMachine();
            string result = "";
            result = machine -> spin();
            delete(machine);
            // deduct one dollar after every spin
            InitialCash -= 1;
            return result;
        }

        void Play(){
            // make a new istance of payout table
            PayoutTable *paytable = new PayoutTable();
            string yes_no ="";
            int payment = 0;

            cout << endl << "===================================" << endl;
            string result = SpinSlotMachine();
            payment = paytable -> getPayment(result);
            if(payment > 0){
                cout << (result == "777" ? "JACKPOT" : "Congratulations") << "!!! You won $" << payment << endl;
                InitialCash += payment;
            }else{
                cout << "Sorry!!! Not a winning combination. " << endl;
            }
            cout << "Your Current balance is $" << InitialCash << endl;
            cout << endl << "===================================" << endl << endl;


            if(InitialCash > 0){
                cout << "Do you want to spin again ? (yes/no) :";
                getline (cin, yes_no);

                if(yes_no == "yes" || yes_no == "YES" || yes_no == "Yes"){
                    // recursively call the same play function when user wants to play
                    Play();
                }else{
                    cout <<"Bye Bye!!! Your final balance is $" << InitialCash << "." << endl;
                }
            }else{
                cout << "You ran out of balance :( . Better luck next time !!!";
                exit(0);
            }
        }
};