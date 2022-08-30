#include<iostream>
using namespace std;

class Team{
	int player_score;
	static int team_score;   // by default static value is 0
	public:
	void getScores(){
		cout<<"Enter score of player: ";
		cin>>player_score;
		team_score+=player_score;
		cout<<player_score<<" "<<team_score<<endl;
	}
	
};

int Team::team_score;

int main(){
	Team t1,t2,t3,t4,t5;
	t1.getScores();
	t2.getScores();
	t3.getScores();
	t4.getScores();
	t5.getScores();

}
