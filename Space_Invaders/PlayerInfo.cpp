#include <iostream>
#include <algorithm>
#include "MergeSort.h"
#include "PlayerInfo.h"

using namespace std;

PlayerInfo::PlayerInfo():name(""), current_score(0), saved_score(0)
{
	//...
}

void PlayerInfo::SetCurrentScore(int curr_score)
{
	current_score = curr_score;
}

int PlayerInfo::GetSavedScore() const
{
	return saved_score;
}

std::string PlayerInfo::GetName() const
{
	return name;
}

void PlayerInfo::LoadInfoToGame(std::string &p_name, int p_score)
{
	saved_score = p_score;
	name = p_name;
}

void PlayerInfo::CompareScores()
{
	if (current_score > saved_score)
	{
		saved_score = current_score;
	}
}

bool PlayerInfo::CreateNewProfile()
{
	cout << "Enter your name\n";
	cin >> name;
	return true;
}

void PlayerInfo::SaveCurrPlayerToFile()
{
	player_data_in.open("PlayerData.txt", ios_base::app);
	player_data_in << "\n" << GetName() << " " << GetSavedScore();
	player_data_in.close();
}

void PlayerInfo::InsertProfilesToVector()
{
	//Open text file to use it again
	player_data_out.open("PlayerData.txt");
	//Find player profiles
	while (player_data_out >> name >> saved_score)
	{
		player_info_pointer = new PlayerInfo;
		player_info_pointer->LoadInfoToGame(name, saved_score);
		player_vector_pair.push_back(std::pair<int, PlayerInfo*>(player_info_pointer->GetSavedScore(), player_info_pointer));

	}
	player_data_out.close();
}

void PlayerInfo::SortProfiles()
{
	player_data_in.open("PlayerData.txt");
	//Merge Sort the scores
	mrgsrt(player_vector_pair);
	cout << "The scoreboard is: \n";
	for (int i = 0; i < player_vector_pair.size(); i++)
	{
		cout << player_vector_pair[i].second->GetName() << " " << player_vector_pair[i].second->GetSavedScore() << endl;
		player_data_in << player_vector_pair[i].second->GetName() << " " << player_vector_pair[i].second->GetSavedScore() << endl;
	}
	player_data_in.close();
}
