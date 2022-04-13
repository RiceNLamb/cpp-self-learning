#include <iostream>
#include <string>
#include <random>
#include <chrono>
using namespace std;

class CardObject {
    private:
        string suits[4] {
            "C", "S", "H", "D" 
            };
        string values[13] {
            "1", "2", "3", "4","5", "6", "7", "8", "9", "10", "J","Q","K" 
        };
    public:
        string card_structure[7][7] {
            {"-","-","-","-","-","-","-"},
            {"|"," "," "," "," "," ","|"},
            {"|"," "," "," "," "," ","|"},
            {"|"," "," ",""," "," ","|"},
            {"|"," "," "," "," "," ","|"},
            {"|"," "," "," "," "," ","|"},
            {"-","-","-","-","-","-","-"},
            };
        void cardCreator(){
            mt19937 mt{ random_device{}()};
           //establishing 
            uniform_int_distribution<> suit_selector{0,3};
            uniform_int_distribution<> value_selector{0,12};
           
            string chosen_suit = suits[suit_selector(mt)];
            string chosen_value = values[value_selector(mt)];
            if (chosen_value == "10")
                card_structure[3][5] = "";
            card_structure[1][1] = chosen_suit;
            card_structure[5][5] = chosen_suit;
            card_structure[3][3] = chosen_value;
            
        }

};


