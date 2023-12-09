#include <vector>
#include <utility>
#include <algorithm>

#include "Match.cpp"

using namespace std;

const int NUM_TEAMS_PER_GROUP = 4;
const string SPACE = "";
const string HEADER = "    TEAM         GP   W   D   L  GF  GA  GD  Pts";

//format an integer so that they are aligned 
string format(int number){
    string str = to_string(number);
    if (str.length() == 1){
        return "   " + str;
    }
    else if (str.length() == 2){
        return "  " + str;
    }
    else if (str.length() == 3){
        return " " + str;
    }
    else{
        return str;
    }
}

// print standings
void printTable(vector<Team*> allTeams){
    vector<pair<string, unordered_map<string, int>>> allPairs;
    
    // update teams and create pair<name string, data map> vector
    for (auto team : allTeams){
        team->updateAll();
        //team->printTeamData();
        string name = team->getName();
        unordered_map<string, int> teamData = team->getTeamData();
        
        pair<string, unordered_map<string, int>> teamPair(name, teamData);
        allPairs.push_back(teamPair);
    }
    
    // Custom comparator to sort in decreasing order based on "Pts" key in the unordered_map
    auto comparator = [](const auto& pair1, const auto& pair2) {
        return pair1.second.at("Pts") > pair2.second.at("Pts");
    };

    // Sort the teams by number of points
    sort(allPairs.begin(), allPairs.end(), comparator);
    
    
    cout << HEADER << endl;

    // print data on all teams
    for (auto&& pair : allPairs) {
        string name = pair.first;
        int nameSize = name.length();
        // align team name
        while (nameSize < 12){
            name += " ";
            nameSize++;
        }

        // print data
        const unordered_map<string, int>& teamData = pair.second;

        cout << name << " : "
            << format(teamData.at("GP")) << SPACE   // games played
            << format(teamData.at("W"))  << SPACE   // games won
            << format(teamData.at("D"))  << SPACE   // games drawn
            << format(teamData.at("L"))  << SPACE   // games lost
            << format(teamData.at("GF")) << SPACE   // goals for
            << format(teamData.at("GA")) << SPACE   // goals against
            << format(teamData.at("GD")) << SPACE   // goal differential
            << format(teamData.at("Pts")) << endl;  // total points
    }
}