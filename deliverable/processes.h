#include <iostream>
#include <string>
#include <random>
#include <chrono>
#include <tuple> 
#include "classes.h" 
using namespace std;

void card_creation_process(CardObject &card_being_added, vector<CardObject> &all_card_values){
    card_being_added.cardCreator();
    all_card_values.push_back(card_being_added);
}

vector<CardObject> duplicate_checker(vector<CardObject> checking_card_values){
    vector<CardObject> new_vector{checking_card_values};


    std::cout << "Chcking started";
    bool all_clear{false};
    while (all_clear != true){
        for (int i{0}; i < new_vector.size(); ++ i){
            for (int j{i+1}; j < new_vector.size(); ++j){
                if (new_vector[i].indv_card_values == new_vector[j].indv_card_values){
                    std::cout << "Duplicate detected";
                    CardObject new_obj;
                    new_obj.cardCreator();
                    new_vector[j] = new_obj;
                    duplicate_checker(new_vector);
                }
            }
        }
        all_clear = true;
    }
    return new_vector;
}

void clear_screen(){
    
    cout << "" << flush;

    system("CLS");
}





string card_analysis_process(vector<tuple<string,string>> board_values, vector<tuple<string,string>> player_card){
    vector<tuple<string,string>> combined_vector;
    combined_vector.insert(combined_vector.end(), board_values.begin(), board_values.end());
    combined_vector.insert(combined_vector.end(), player_card.begin(), player_card.end());

    int matching_suits{1};
    //used to tell me which cards are matching
    vector<int> index_for_matching;
    vector<int> index_for_matching_two;
    
    //comparing all the cards together
    for (int i{0}; i < combined_vector.size(); ++ i){
            for (int j{i+1}; j < combined_vector.size(); ++j){

                if (get<0>(combined_vector[i]) == get<0>(combined_vector[j])){
                    if (index_for_matching.size() == 0){
                        index_for_matching.push_back(i);
                        index_for_matching.push_back(j);
                    }
                    else if (get<0>(combined_vector[j]) == get<0>(combined_vector[index_for_matching[0]])){
                        index_for_matching.push_back(j);
                    }
                    else if (index_for_matching_two.size() == 0){
                        index_for_matching_two.push_back(i);
                        index_for_matching_two.push_back(j);
                    }
                    else if (get<0>(combined_vector[j]) == get<0>(combined_vector[index_for_matching_two[0]])){
                        index_for_matching_two.push_back(j);
                    }
                }
            }
        }
    //being checking for hands
    int size_one{(int)index_for_matching.size()};
    int size_two{(int)index_for_matching_two.size()};

    if (size_one == 4 or size_two == 4){
        return "Four of a Kind.";
    }
    else if ((size_one == 3 and size_two == 2) or (size_one == 2 and size_two == 3)){
        return "Full house.";
    }
    else if (size_one == 3 or size_two == 3){
        return "Three of a kind.";
    }
    
    else if (size_one == 2 and size_two == 2){
        return "Two pair.";
    }
    
    else if (size_one == 2 or size_two == 2){
        return "Pair.";
    }

    else {
        int highest_index{0};
        string values[13] {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
        
        //going through each card and finsing the highest valued card
        for (int i{0}; i < combined_vector.size(); ++ i){
            string comp_value{get<0>(combined_vector[i])};
            //manually searching because the search algorithm is bad
            for (int j{0}; j < 13; ++ j){
                if (comp_value == values[j]){
                    if (j > highest_index){
                        highest_index = j;
                    }
                    
                }
                
            }

        }
        string highest_value{get<0>(combined_vector[highest_index])};
        string highest_suit{get<1>(combined_vector[highest_index])};
        return "a High card. ";
    }
    
    return "Something has gone wrong for this to appear";
}
