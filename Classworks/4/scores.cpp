// ABC academy is conducting cricket matches for different teams. In each team, there are 11 players and there are 11 teams in the league. The first match
// is being conducted and every player score will be printed with the total team score. Create a class team with data members as player score and team score.
// Create appropriate member function to achieve the task. access levels, data types and the functions will be defined accordingly.


#include<iostream>
using namespace std;

class Team{
	int player_score[11];
	int team_score=0;
	public:
	void getScores(){
		for (int i=0; i<11; i++){
			cout<<"Enter score of player "<<i+1<<": ";
			cin>>player_score[i];
			team_score+=player_score[i];
			cout<<player_score[i]<<" "<<team_score<<endl;
		}
	}
	
};

int main(){
	Team t1;
	t1.getScores();

}
