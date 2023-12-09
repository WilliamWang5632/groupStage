#include <fstream>
#include <sstream>

#include "printTable.cpp"

using namespace std;


int main(){
    // instanciate teams (must do manually)
    Team team1("Costa-Rica");
    Team team2("Spain");
    Team team3("Germany");
    Team team4("Japan");
    
    vector<Team*> allTeamsPtr = {&team1, &team2, &team3, &team4};

    // open file
    ifstream inputFile("scores.txt");

    if (!inputFile){
        cerr << "error opening file!" << endl;
        return 1;
    }

    string line;

    // loop through every line in text file
    while (getline(inputFile, line)){

        // skip line if its empty
        if (line.length() == 0) {
            continue;
        }

        // first team    --   goals scored by first team   --   goals scored by second team   --   second team
        istringstream iss(line);
        string teamName1, s_score1, s_score2, teamName2;
        iss >> teamName1 >> s_score1 >> s_score2 >> teamName2;
        int i_score1 = stoi(s_score1);
        int i_score2 = stoi(s_score2);
        Team* firstTeam;
        Team* secondTeam;

        // find Team object in allTeamsPtr by matching name
        for (auto team : allTeamsPtr){
            if (teamName1 == team->getName()){
                firstTeam = team;
            }
            else if (teamName2 == team->getName()){
                secondTeam = team;
            }
        }

        // play the match avec update results for each team
        Match match(firstTeam, i_score1, i_score2, secondTeam);
    }

    // print the group table
    printTable(allTeamsPtr);
}


