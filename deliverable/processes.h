#include <iostream>
#include <string>
#include <random>
#include <chrono>
#include <tuple> 
#include "classes.h" 
using namespace std;

void duplicate_checker(vector<CardObject> checking_card_values){
    bool all_clear{false};
    while (all_clear != true){
        for (int i{0}; i < checking_card_values.size(); ++ i){
            for (int j{i+1}; j < checking_card_values.size(); ++j){
                if (checking_card_values[i].indv_card_values == checking_card_values[j].indv_card_values){
                    checking_card_values[j].cardCreator();
                    duplicate_checker(checking_card_values);
                }
                else{

                }
            }
        }
        all_clear = true;
    }

}

void clear_screen(){
    
    cout << "" << flush;

    system("CLS");
}

void card_creation_process(CardObject &card_being_added, vector<CardObject> &all_card_values){
    card_being_added.cardCreator();
    all_card_values.push_back(card_being_added);
}



void card_analysis_process(vector<tuple<string,string>> board_values, vector<tuple<string,string>> player_card){
    vector<tuple<string,string>> combined_vector;
    combined_vector.insert(combined_vector.end(), board_values.begin(), board_values.end());
    combined_vector.insert(combined_vector.end(), player_card.begin(), player_card.end());
    int matching_suits{0};
    int matching_values{0};
    for (int i{0}; i < combined_vector.size(); ++ i){
            for (int j{i+1}; j < combined_vector.size(); ++j){
                if (get<0>(combined_vector[i]) == get<0>(combined_vector[j])){
                    matching_suits = matching_suits + 1;
                }
                else if (get<0>(combined_vector[i]) == get<0>(combined_vector[j])){
                    matching_values = matching_suits + 1;
                }
            }
        }
}
