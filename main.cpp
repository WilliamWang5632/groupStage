#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <fstream>
#include <sstream>

#include "Match.cpp"

using namespace std;

const int NUM_TEAMS_PER_GROUP = 4;
const string SPACE = "   ";
const string HEADER = "    TEAM      GP   W   D   L  GF  GA   GD  Pts";


// print standings
void printTable(vector<Team*> allTeams){
    vector<pair<string, unordered_map<string, int>>> allPairs;
    
    for (auto team : allTeams){
        team->updateAll();
        team->printTeamData();
        string name = team->getName();
        unordered_map<string, int> teamData = team->getTeamData();
        
        
        pair<string, unordered_map<string, int>> teamPair(name, teamData);
        allPairs.push_back(teamPair);
    }
    
    // Custom comparator to sort in decreasing order based on "Pts" key in the unordered_map
    auto comparator = [](const auto& pair1, const auto& pair2) {
        return pair1.second.at("Pts") > pair2.second.at("Pts");
    };

    // Sort the vector of pairs
    sort(allPairs.begin(), allPairs.end(), comparator);
    
    
    cout << HEADER << endl;
    for (auto&& pair : allPairs) {
        string name = pair.first;
        int nameSize = name.length();
        while (nameSize < 12){
            name += " ";
            nameSize++;
        }

        const unordered_map<string, int>& teamData = pair.second;

        string buffer = "";
        if (teamData.at("GD") >= 0) {
            buffer = " ";
        }

        cout << name << " : "
            << teamData.at("GP") << SPACE
            << teamData.at("W") << SPACE
            << teamData.at("D") << SPACE
            << teamData.at("L") << SPACE
            << teamData.at("GF") << SPACE
            << teamData.at("GA") << SPACE
            << buffer
            << teamData.at("GD") << SPACE
            << teamData.at("Pts") << endl;
    }
}

int main(){


    Team team1("Argentina");
    Team team2("France");
    Team team3("Germany");
    Team team4("Spain");
    
    vector<Team*> allTeams = {&team1, &team2, &team3, &team4};

    ifstream inputFile("scores.txt");

    if (!inputFile){
        cerr << "error opening file!" << endl;
        return 1;
    }

    string line;

    while (getline(inputFile, line)){
        istringstream iss(line);
        string teamName1, s_score1, s_score2, teamName2;
        iss >> teamName1 >> s_score1 >> s_score2 >> teamName2;
        int i_score1 = stoi(s_score1);
        int i_score2 = stoi(s_score2);
        Team* firstTeam;
        Team* secondTeam;
        for (auto team : allTeams){
            if (teamName1 == team->getName()){
                firstTeam = team;
            }
            else if (teamName2 == team->getName()){
                secondTeam = team;
            }
            else{
                cout << "team not found" << endl;
            }
        }
        Match match(firstTeam, i_score1, i_score2, secondTeam);
    }
    
    printTable(allTeams);
}












// #include <iostream>
// #include <fstream>
// #include <vector>
// #include <sstream>

// struct Person {
//     std::string firstName;
//     std::string lastName;
//     int age;
// };

// int main() {
//     std::ifstream inputFile("data.txt");

//     if (!inputFile) {
//         std::cerr << "Error opening file!" << std::endl;
//         return 1;
//     }

//     std::vector<Person> people;
//     std::string line;

//     while (std::getline(inputFile, line)) {
//         std::istringstream iss(line);
//         Person person;

//         // Read data from the line separated by spaces
//         iss >> person.firstName >> person.lastName >> person.age;

//         // Add the person to the vector
//         people.push_back(person);
//     }

//     // Print the organized data
//     for (const auto& person : people) {
//         std::cout << "First Name: " << person.firstName << ", Last Name: " << person.lastName
//                   << ", Age: " << person.age << std::endl;
//     }

//     return 0;
// }







