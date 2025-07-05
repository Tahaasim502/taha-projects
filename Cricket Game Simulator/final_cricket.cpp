#include<iostream>
#include<fstream>
#include<ctime>
using namespace std;
//sohaib
struct teams
{
    string teamname;
    string players[11];
    string outstatus[11];
    int *scores;
    int matchWins = 0;
    int **allMatchscores;
};

struct match
{
    int matchnum;
    int tosswinner;
    int team1winner;
    int team2winner;
    string winnerteam;
};

void inputTeamDetails(teams &t1, teams &t2)
{
    cout << "Enter the name of team 1: ";
    cin >> t1.teamname;
    cout << "Enter the name of team 2: ";
    cin >> t2.teamname;
    cout << endl;
    cout << "Enter players for team " << t1.teamname << ":\n";
    for (int i = 0; i < 11; i++) {
        cout << "Player " << i + 1 << ": ";
        cin >> t1.players[i];
    }
    cout << endl;
    cout << "Enter players for team " << t2.teamname << ":\n";
    for (int i = 0; i < 11; i++) {
        cout << "Player " << i + 1 << ": ";
        cin >> t2.players[i];
    }
}


void resetforMatch(teams &t1, teams &t2)
{
    for (int i = 0; i < 11; i++)
	{
        t1.scores[i] = 0;
        t1.outstatus[i] = "0";
        t2.scores[i] = 0;
        t2.outstatus[i] = "0";
    }
}

int simulateInnings(teams &team, int overs) {
    int totalBalls = overs * 6;
    int playerIndex = 0;
    int totalScore = 0;
    int outs = 0;

    for (int i = 0; i < totalBalls && outs < 10; i++)
	{
        int score = rand() % 7;
        if (score == 5)
		{
            team.outstatus[playerIndex] = "OUT";
            outs++;
            playerIndex++;
        }
		else
		{
            team.scores[playerIndex] += score;
            totalScore += score;
        }
        if(outs == 10)
        {
        	break;
		}

    }
    return totalScore;
}
//sohaib
void storePlayerScores(teams &team, int matchIndex) {
    for (int i = 0; i < 11; i++) {
        team.allMatchscores[i][matchIndex] = team.scores[i];
    }
}

int toss(teams &team1, teams &team2)
{
    int choice;
    int toss = rand() % 2;
    if(toss == 0)
    {
       cout<<"Team "<< team1.teamname <<" has won the toss\n";
        cout<<"Enter 1 for batting || 2 for balling: ";
        cin>>choice;
        while(choice != 1 && choice != 2)
        {
            cout << "Error, please make sure the choice is either 1 or 2: ";
            cin >> choice;
        }
        return choice;
	}
	else
    {
       cout<<"Team "<< team2.teamname <<" has won the toss\n";
       cout<<"Enter 1 for batting || 2 for balling: ";
       cin>>choice;
       while(choice != 1 && choice != 2)
       {
            cout << "Error, please make sure the choice is either 1 or 2: ";
            cin >> choice;
       }
       return choice;
	}
}

void simulateMatch(teams &team1, teams &team2,int match, int overs)
{
    for (int i = 0; i < match; i++)
	{
	    cout << "\n=== Match " << i + 1 << " ===\n";
        resetforMatch(team1, team2);
	    int tossresult = toss(team1, team2);
	    int score1 = 0, score2 = 0;
	    if(tossresult == 1)
        {
            score1 = simulateInnings(team1, overs);
            storePlayerScores(team1, i);
            score2 = simulateInnings(team2, overs);
            storePlayerScores(team2, i);
        }
        else
        {
            score1 = simulateInnings(team1, overs);
            storePlayerScores(team1, i);
            score2 = simulateInnings(team2, overs);
            storePlayerScores(team2, i);
        }

        cout << team1.teamname << " scored: " << score1 << endl;
        cout << team2.teamname << " scored: " << score2 << endl;

        if (score1 > score2)
		{
            cout << "Winner: " << team1.teamname << endl;
            team1.matchWins++;
        }
		else if (score2 > score1)
		{
            cout << "Winner: " << team2.teamname << endl;
            team2.matchWins++;
        }

		else
		{
            cout << "Match Drawn!\n";
        }
    }

    cout << "\n=== Series Result ===\n";
    cout << team1.teamname << " won " << team1.matchWins << " matches.\n";
    cout << team2.teamname << " won " << team2.matchWins << " matches.\n";
}

void displayMatchSummary(teams &team1, teams &team2, int no_matches, int no_overs)
{
    simulateMatch(team1, team2, no_matches, no_overs);
}

void writeSeriesSummaryToFile(teams &team1, teams &team2, int no_matches)
{
    ofstream file("series_summary.txt");
    if (!file.is_open()) {
        cout << "Failed to open summary file.\n";
        return;
    }

    for (int i = 0; i < no_matches; i++) {
        file << "Match " << i + 1 << ":\n";
        file << team1.teamname << " 's team player scores:\n";
        for (int j = 0; j < 11; j++)
            file << team1.players[j] << ": " << team1.allMatchscores[j][i] << "\n";

        file << team2.teamname << " 's team player scores:\n";
        for (int j = 0; j < 11; j++)
            file << team2.players[j] << ": " << team2.allMatchscores[j][i] << "\n";
        file << "\n";
    }

    file << "Final Results:\n";
    file << team1.teamname << " won " << team1.matchWins << " matches.\n";
    file << team2.teamname << " won " << team2.matchWins << " matches.\n";
    file.close();
}

void deallocateTeamMemory(teams &team, int matches)
{
    delete[] team.scores;
    for(int i = 0; i < 11; i++)
    {
        delete[] team.allMatchscores[i];
    }
    delete[] team.allMatchscores;
}
int main()
{
    srand(time(0));
    teams t1, t2;
    int no_overs, no_matches;
    cout << "Project made by Taha Asim, M.Sohaib and Tayyab Ahmed" << endl;
    cout << "Enter number of overs: ";
    cin >> no_overs;
    cout << "Enter number of matches: ";
    cin >> no_matches;
    cout << endl;
    inputTeamDetails(t1, t2);
    t1.scores = new int [11];
    t2.scores = new int [11];
    t1.allMatchscores = new int * [11];
    t2.allMatchscores = new int *[11];
    for(int i = 0; i < 11; i++)
    {
        t1.allMatchscores[i] = new int [no_matches];
        t2.allMatchscores[i] = new int [no_matches];
    }
    displayMatchSummary(t1, t2, no_matches, no_overs);
    writeSeriesSummaryToFile(t1, t2, no_matches);
    deallocateTeamMemory(t1, no_matches);
    deallocateTeamMemory(t2, no_matches);
    return 0;
}
