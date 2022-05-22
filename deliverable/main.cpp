#include <iostream>
#include "processes.h"
#include <unistd.h>
#include <stdlib.h>

using namespace std;



int main(){
    vector<CardObject> card_values; 
    CardObject pfirst_card;
    CardObject psecond_card;

    card_creation_process(pfirst_card, card_values);
    card_creation_process(psecond_card, card_values);

    card_values = duplicate_checker(card_values);
    

    Hand player_hand;
    player_hand.hand_maker(pfirst_card);
    player_hand.hand_maker(psecond_card);

    
    Hand board_cards;

    CardObject first_flop;
    CardObject second_flop;
    CardObject third_flop;

    card_creation_process(first_flop, card_values);
    card_creation_process(second_flop, card_values);
    card_creation_process(third_flop, card_values);

    card_values = duplicate_checker(card_values);

    board_cards.hand_maker(first_flop); 
    board_cards.hand_maker(second_flop);
    board_cards.hand_maker(third_flop); 
    
    cout << "Press any key to play";
    cin.ignore(); 

    clear_screen();

    cout << "Board: \n";
    board_cards.hand_printer();
    cout << "\nYour cards \n";
    player_hand.hand_printer();
    
    cout << "Next card... \n" ;
    cin.ignore();  
    
    clear_screen();

    CardObject turn;
    card_creation_process(turn, card_values);

    card_values = duplicate_checker(card_values);
    board_cards.hand_maker(turn);

    cout << "Board: \n";
    board_cards.hand_printer();
    cout << "\nYour cards \n";
    player_hand.hand_printer();

    cout << "Next card...  \n";
    cin.ignore(); 


    clear_screen();

    CardObject river;
    card_creation_process(river, card_values);

    card_values = duplicate_checker(card_values);
    board_cards.hand_maker(river);
    cout << "Board: \n";
    board_cards.hand_printer();
    cout << "\nYour cards \n";
    player_hand.hand_printer();

    cout << "\nResults...";
    cin.ignore();  

    string result{card_analysis_process(board_cards.current_hand_values, player_hand.current_hand_values)};

    cout << "\nThe best hand is: " << result;
    
    cin.ignore(); 
}