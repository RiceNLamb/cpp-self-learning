#include <iostream>
#include "processes.h"
#include<unistd.h>

using namespace std;


int main(){

    CardObject first_card;
    CardObject second_card;
    first_card.cardCreator();
    second_card.cardCreator();

    bool dupe_checker {duplicate_checker(first_card.chosen_value , second_card.chosen_value, first_card.chosen_suit, second_card.chosen_suit)};

    while(dupe_checker != true){
        second_card.cardCreator();
        dupe_checker = duplicate_checker(first_card.chosen_value , second_card.chosen_value, first_card.chosen_suit, second_card.chosen_suit);
    }
    
    int fcard_value{first_card.output_value};
    int scard_value{second_card.output_value};

    
    int starting_total {fcard_value + scard_value};
    vector<string> initial_cards{start_sequence(first_card.card_structure,second_card.card_structure)};

    game_sequence(starting_total, initial_cards);

    usleep(3000000);
}