#include <iostream>
#include "processes.h"
#include<unistd.h>

using namespace std;



int main(){
    vector<CardObject> card_values; 
    CardObject first_card;
    CardObject second_card;
    first_card.cardCreator();
    card_values.push_back(first_card);
    second_card.cardCreator();
    card_values.push_back(second_card);

    duplicate_checker(card_values);
    

    
    // vector<string> initial_cards{start_sequence(first_card.card_structure,second_card.card_structure)};

    //game_sequence(starting_total, initial_cards);
    usleep(3000000);
}