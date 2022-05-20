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