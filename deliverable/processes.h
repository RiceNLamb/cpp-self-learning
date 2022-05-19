#include <iostream>
#include <string>
#include <random>
#include <chrono>
#include <tuple> 
using namespace std;



class CardObject {
    private:
        string suits[4] {
            "C", "S", "H", "D" 
            };
        string values[13] {
            "A", "2", "3", "4","5", "6", "7", "8", "9", "10", "J","Q","K" 
        };
        int suits_converter(string value){
            if (value == "J")
                return 10;
            else if (value == "Q")
                return 10;
            else if (value == "K")
                return 10;
            else if (value == "A")
                return 11;
            else{
                int calculated_value {stoi(value)};
                return calculated_value;

            }
            return 0;
}
    public:
        string values[13] {
            "A", "2", "3", "4","5", "6", "7", "8", "9", "10", "J","Q","K" 
        };
        string chosen_suit {""};
        string chosen_value {""};
        tuple<string,string> indv_card_values; 
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
           
            chosen_suit = suits[suit_selector(mt)];
            chosen_value = values[value_selector(mt)];

            if (chosen_value == "10")
                card_structure[3][5] = "";

            card_structure[1][1] = chosen_suit;
            card_structure[5][5] = chosen_suit;
            card_structure[3][3] = chosen_value;

            indv_card_values = make_tuple(chosen_value, chosen_suit);

            

        }

};


class Hand{
    private:
        vector<string> current_hand{"","","","","","",""};
        vector<tuple<string,string>> current_hand_values; 
    public:
        //takes in the current boardstate, and then the generated card, then returns the new board state 
        // boards state will now be the hand
        void hand_maker(CardObject individual_card){
    
            string temp_str_concat = "";

            for (int line{0}; line <7; ++line){
                temp_str_concat = temp_str_concat + current_hand[line];

                temp_str_concat = temp_str_concat + "    ";

                // adds each space in each line 
                for(int i{0}; i<7; ++i){
                    temp_str_concat = temp_str_concat + individual_card.card_structure[line][i];
                }

                //adds in the line    
                current_hand[line] = temp_str_concat;
                temp_str_concat = "";
                
                }
            current_hand_values.push_back(individual_card.indv_card_values);

        }

        void hand_printer(){
            for (int i{0}; i < 7; ++i){
                std::cout << current_hand[i] << "\n";

            }
        }
};

    

// void game_sequence(int prev_total,  vector<string> board){
//     if (prev_total < 21){
//         cout << "Hit or stand? ";
//         string order{};
//         cin >> order;
//         if (order == "hit" or order== "Hit"){
//             CardObject newCard;
//             newCard.cardCreator();
            
//             vector<string> newboard{card_printer(board, newCard.card_structure)};


//             //game_sequence(new_total, newboard);
//         }
//         else{
//             cout << "Your current total is: " << prev_total;
//         }
        
//     }
//     else if (prev_total == 21){
//         cout << "Blackjack!";
//     }
//     else{
//         cout << "Bust!";
//     }
    
// }




void duplicate_checker(vector<CardObject> checking_card_values){
    bool all_clear{false};
    while (all_clear != true){
        for (int i{0}; i < checking_card_values.size(); ++ i){
            for (int j{i+1}; i < checking_card_values.size(); ++j){
                if (checking_card_values[i].indv_card_values == checking_card_values[j].indv_card_values){
                    checking_card_values[j].cardCreator();
                    i = 0;
                    continue;
                }
            }
        }
        all_clear = true;
    }

}