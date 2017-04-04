#pragma once
#ifndef __PLAYERINFO_H_INCLUDED__
#define __PLAYERINFO_H_INCLUDED__
#include <string>
#include <fstream>
#include <vector>

class PlayerInfo
{
public:
	PlayerInfo();

	void SetCurrentScore(int curr_score);
	int GetSavedScore() const;
	std::string GetName() const;
	void LoadInfoToGame(std::string &p_name, int p_score);
	void CompareScores();
	bool CreateNewProfile();
	void SaveCurrPlayerToFile();
	void InsertProfilesToVector();
	void SortProfiles();

protected:
	short unsigned int current_score;
	short unsigned int saved_score;
	std::string name;
	std::ifstream player_data_out;//Player data output on screen
	std::ofstream player_data_in;//Player data input to file
	std::string full_answer;
	char y_n_answer;
	PlayerInfo* player_info_pointer = NULL;
	std::vector<std::pair<int, PlayerInfo*>> player_vector_pair;
};

#endif // !__PLAYERINFO_H_INCLUDED__
