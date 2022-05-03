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
        string chosen_suit {""};
        string chosen_value {""};
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
            
        }

};


class Hand : public CardObject {

};

vector<string> card_printer(vector<string> board_state, string card_output[7][7]){
    
    vector<string> new_board_state{};
    string temp_str_concat = "";

    for (int line{0}; line <7; ++line){
        temp_str_concat = temp_str_concat +  board_state[line];

        temp_str_concat = temp_str_concat + "    ";

        for(int i{0}; i<7; ++i){
            temp_str_concat = temp_str_concat + card_output[line][i];
        }
            
        temp_str_concat = temp_str_concat;
        cout << temp_str_concat << "\n";
        new_board_state.push_back(temp_str_concat);
        temp_str_concat = "";
        
        }

    return new_board_state;
}
    

void game_sequence(int prev_total,  vector<string> board){
    if (prev_total < 21){
        cout << "Hit or stand? ";
        string order{};
        cin >> order;
        if (order == "hit" or order== "Hit"){
            CardObject newCard;
            newCard.cardCreator();
            
            vector<string> newboard{card_printer(board, newCard.card_structure)};


            //game_sequence(new_total, newboard);
        }
        else{
            cout << "Your current total is: " << prev_total;
        }
        
    }
    else if (prev_total == 21){
        cout << "Blackjack!";
    }
    else{
        cout << "Bust!";
    }
    
}



vector<string> start_sequence(string card1[7][7], string card2[7][7]){
    
    vector<string> board_state{};
    string temp_str_concat = "";
    
    for (int i {0}; i< 7; ++i) {
        for (int j{0}; j<7; ++j) {
            temp_str_concat = temp_str_concat +  card1[i][j];
            cout << card1[i][j];
        }
        
        cout << "    ";
        temp_str_concat = temp_str_concat + "    ";
        for (int k{0}; k<7; ++k) {
            temp_str_concat = temp_str_concat +card2[i][k];
            cout << card2[i][k];
        }
        cout << "\n";
        
        board_state.push_back(temp_str_concat);
        temp_str_concat = "";
    }
    

    return board_state;
}


bool duplicate_checker(string fcard_suit, string scard_suit, string fcard_value, string scard_value){
    if (fcard_suit == scard_suit and fcard_value == scard_value){
            return false;
        }
    
    else {
            return true;
        }

    }
