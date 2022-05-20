#include <iostream>
#include "processes.h"
#include<unistd.h>

using namespace std;



int main(){
    vector<CardObject> card_values; 
    CardObject pfirst_card;
    CardObject psecond_card;
    pfirst_card.cardCreator();
    card_values.push_back(pfirst_card);
    psecond_card.cardCreator();
    card_values.push_back(psecond_card);

    duplicate_checker(card_values);
    
    Hand player_hand;
    player_hand.hand_maker(pfirst_card);
    player_hand.hand_maker(psecond_card);

    

    
    // vector<string> initial_cards{start_sequence(first_card.card_structure,second_card.card_structure)};

    //game_sequence(starting_total, initial_cards);
    usleep(3000000);
}