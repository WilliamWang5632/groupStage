#pragma once
#include <iostream>

#include "Team.cpp"

using namespace std;

class Match{
public:
    // match constructor passes two teams by reference
    Match(Team* team1, int goals1, int goals2, Team* team2): 
        team1_(team1), 
        team2_(team2),
        goals1_(goals1),
        goals2_(goals2){
        
        team1_->updateGD(goals1, goals2);
        team2_->updateGD(goals2, goals1);
        
        if (goals1 > goals2){
            team1_->playGame('W');
            team2_->playGame('L');
        }
        else if(goals1 == goals2){
            team1_->playGame('D');
            team2_->playGame('D');
        }
        else if(goals1 < goals2){
            team1_->playGame('L');
            team2_->playGame('W');
        }
        else{
            cout << "Error" << endl;
        }      
    }
private:
    Team* team1_;
    int goals1_;
    int goals2_;
    Team* team2_;
};