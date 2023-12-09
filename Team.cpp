#include <iostream>
#include <unordered_map>

using namespace std;


class Team{
public:
    // default constructor
    Team(){
        name_ = "None";
        data_["W"] = 0;
        data_["D"] = 0;
        data_["L"] = 0;
        data_["GF"] = 0;
        data_["GA"] = 0;
    }
    
    // constructor with name and initialise data to 0
    Team(string name){
        name_ = name;
        data_["W"] = 0;
        data_["D"] = 0;
        data_["L"] = 0;
        data_["GF"] = 0;
        data_["GA"] = 0;
    }
    
    // add to wins, draws or loss depending on result
    void playGame(char result){
        switch (result){
            case 'W':
                data_["W"] += 1;
                break;
            case 'D':
                data_["D"] += 1;
                break;
            case 'L':
                data_["L"] += 1;
                break;
            default:
                cout << "Error" << endl;
        }
    }
    
    // update goal differential
    void updateGD(int scored, int conceded){
        data_["GF"] += scored;
        data_["GA"] += conceded;
    }
    
    // update all data
    void updateAll(){
        data_["GP"] = data_["W"] + data_["D"] + data_["L"];
        data_["Pts"] = data_["W"] * 3 + data_["D"];
        data_["GD"] = data_["GF"] - data_["GA"];
    }
    
    // print all information on a team
    void printTeamData(){
        cout << "Team: " << name_ << endl;
        cout << "Games played : " << data_["GP"] << endl; 
        cout << "Games won : " << data_["W"] << endl; 
        cout << "Games drawn : " << data_["D"] << endl; 
        cout << "Games lost : " << data_["L"] << endl; 
        cout << "Goals for : " << data_["GF"] << endl; 
        cout << "Goals against : " << data_["GA"] << endl; 
        cout << "Goal differential : " << data_["GD"] << endl; 
        cout << "Total points : " << data_["Pts"] << endl; 
    }
    
    // get data unordered_map
    unordered_map<string, int> getTeamData(){
        return data_;
    }
    // get name
    string getName(){
        return name_;
    }
    
private:
    string name_;
    unordered_map<string, int> data_;
};
