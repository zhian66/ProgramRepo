#include<vector>
#include<string>
#include<sstream>
#include<fstream>
#include<iostream>

//std::string openFile();
bool checkLoad(std::string fn);
void loadGame();

int main() {
	//std::ifstream fp("test.txt");
	std::string fn = "test.txt";
	if (checkLoad(fn))	loadGame();
}

bool checkLoad(std::string fn) {

	std::string filename, line, tmp;
	//std::ifstream fp(openFile());
	std::ifstream fp;// fp.open(fn);
	std::vector<std::string> tokens;

	std::vector<int> player;
	std::vector<int> chessId;
	std::vector<std::pair<int, int>> prepos, pos;
	
	while (getline(fp, line)) {
		int i = 0;
		std::istringstream check(line);
		std::cout << 0;
		while (check >> tmp) {
			std::cout << 1;
			if (i > 9)	return false;
			tokens.push_back(tmp);
			i++;
		}

		for (const std::string& s : tokens) {
			std::cout << s << std::endl;
		}

		for (int i = 0; i < tokens.size(); i++)
			std::cout << tokens[i] << '\n';
		if (i < 8)	return false;

		//1 player,; 3 Soldier; 4 (6,; 5 6); 5 ->;7 (6,; 8 5) 

		//player
		int temp = tokens[1][0] - '0';
		if (temp != 1 && temp != 2) return false;
		else player.push_back(temp);
		//chess
		// 1:king(將), 2:Guard(士), 3:Minister(相), 4:Horse(馬), 5:Rook(車), 6:Cannon(炮), 7:Pawn(兵)
		std::vector<char> chessTmp;
		for (int i = 0; i < tokens[3].size(); i++) {
			char temp = tokens[3][i];
			if (!isalpha(temp))	return false;
			chessTmp.push_back(tolower(temp));
		}
		std::string s(chessTmp.begin(), chessTmp.end());
		if (s == "king")			chessId.push_back(1);
		else if (s == "guard")		chessId.push_back(2);
		else if (s == "minister")	chessId.push_back(3);
		else if (s == "horse")		chessId.push_back(4);
		else if (s == "rook")		chessId.push_back(5);
		else if (s == "cannon")		chessId.push_back(6);
		else if (s == "pawn")		chessId.push_back(7);
		else						return false;
		//prepos
		int x = tokens[4][1] - '0';
		int y = tokens[5][0] - '0';
		if (x > 8 || x < 0 ||
			y > 9 || y < 0)			return false;
		else prepos.push_back(std::make_pair(x, y));
		//pos
		x = tokens[7][1] - '0';
		y = tokens[8][0] - '0';
		if (x > 8 || x < 0 ||
			y > 9 || y < 0)			return false;
		else pos.push_back(std::make_pair(x, y));
	}
	if (player.size() != chessId.size() ||
		chessId.size() != prepos.size() ||
		prepos.size() != pos.size()) return false;
	return true;
}

void loadGame() {

}
