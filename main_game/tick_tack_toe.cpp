#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;


class SmallGame
{
public:
	SmallGame(string board_now[][4])// board(board_now)
	{
		//board = board_now;
		for (int i = 0; i < 3; i++)
		{
			for (int b = 0; b < 3; b++)
			{
				board[i][b] = board_now[i][b];
			}
		}
	}
	vector<vector<int> >get_possible_squares()
	{

		vector<vector<int> >final_vector;

		for (int i = 0; i < 3; i++)
		{

			for (int b = 0; b < 3; b++)
			{
				vector<int>on_iteration;
				if (board[i][b] == "-")
				{
					on_iteration.push_back(i);
					on_iteration.push_back(b);
					final_vector.push_back(on_iteration);
				}
			}
		}
		return final_vector;
	}
	void make_move()
	{
		vector<vector<int> >the_possible_moves = get_possible_squares();
		int random_index = rand()%the_possible_moves.size()+0;
		vector<int>new_vector = the_possible_moves[random_index];
		int first_square = new_vector[0];
		int second_square = new_vector[1];
		board[first_square][second_square] = "o";

		the_possible_moves = get_possible_squares();
		random_index = rand()%the_possible_moves.size()+0;
		new_vector = the_possible_moves[random_index];
		first_square = new_vector[0];
		second_square = new_vector[1];
		board[first_square][second_square] = "x";

	}
	bool is_winner()
	{
		bool top = true, middle = true, bottom = true, side = true, side1 = true, side2 = true, diagonal1 = true, diagonal2 = true;

		for (int i = 0; i < 3; i++)
		{
			if (board[0][i] != "o")
			{
				top = false;
				break;
			}
		}
		for (int i = 0; i < 3; i++)
		{
			if (board[1][i] != "o")
			{
				middle = false;
				break;
			}
		}
		for (int i = 0; i < 3; i++)
		{
			if (board[2][i] != "o")
			{
				bottom = false;
				break;
			}
		}

		for (int i = 0; i < 3; i++)
		{
			if (board[i][0] != "o")
			{
				side = false;
				break;
			}
		}

		for (int i = 0; i < 3; i++)
		{
			if (board[i][1] != "o")
			{
				side1 = false;
				break;
			}
		}
		for (int i = 0; i < 3; i++)
		{
			if (board[i][2] != "o")
			{
				side2 = false;
				break;
			}
		}
		for (int i = 0; i < 3; i++)
		{
			if (board[i][i] != "o")
			{
				diagonal1 = false;
				break;
			}
		}
		for (int i = 0; i < 3; i++)
		{
			if (board[2-i][i] != "o")
			{
				diagonal2 = false;
				break;
			}
		}
		bool top1 = true, middle1 = true, bottom1 = true, side10 = true, side11 = true, side21 = true, diagonal11 = true, diagonal21 = true;
		for (int i = 0; i < 3; i++)
		{
			if (board[0][i] != "o")
			{
				top1 = false;
				break;
			}
		}
		for (int i = 0; i < 3; i++)
		{
			if (board[1][i] != "o")
			{
				middle1 = false;
				break;
			}
		}
		for (int i = 0; i < 3; i++)
		{
			if (board[2][i] != "o")
			{
				bottom1 = false;
				break;
			}
		}

		for (int i = 0; i < 3; i++)
		{
			if (board[i][0] != "o")
			{
				side10 = false;
				break;
			}
		}

		for (int i = 0; i < 3; i++)
		{
			if (board[i][1] != "o")
			{
				side11 = false;
				break;
			}
		}
		for (int i = 0; i < 3; i++)
		{
			if (board[i][2] != "o")
			{
				side21 = false;
				break;
			}
		}
		for (int i = 0; i < 3; i++)
		{
			if (board[i][i] != "o")
			{
				diagonal11 = false;
				break;
			}
		}
		for (int i = 0; i < 3; i++)
		{
			if (board[2-i][i] != "o")
			{
				diagonal21 = false;
				break;
			}
		}
		vector<bool>o_moves = {top, middle, bottom, side, side1, side2, diagonal1, diagonal2};
		vector<bool>x_moves = {top1, middle1, bottom1, side1, side11, side21, diagonal11, diagonal21};
		if (any_of(o_moves.begin(), o_moves.end(), [](bool i){return !i;}))
		{
			//cout << "o won"<< endl; //will have to return here
			return true;
		}
		else
		{
			if (any_of(x_moves.begin(), x_moves.end(), [](bool i){return !i;}))
			{
				return true;


			}
			else
			{
				return false;
			}
		}


	}
	string thewinner()
	{
		bool top = true, middle = true, bottom = true, side = true, side1 = true, side2 = true, diagonal1 = true, diagonal2 = true;

		for (int i = 0; i < 3; i++)
		{
			if (board[0][i] != "o")
			{
				top = false;
				break;
			}
		}
		for (int i = 0; i < 3; i++)
		{
			if (board[1][i] != "o")
			{
				middle = false;
				break;
			}
		}
		for (int i = 0; i < 3; i++)
		{
			if (board[2][i] != "o")
			{
				bottom = false;
				break;
			}
		}

		for (int i = 0; i < 3; i++)
		{
			if (board[i][0] != "o")
			{
				side = false;
				break;
			}
		}

		for (int i = 0; i < 3; i++)
		{
			if (board[i][1] != "o")
			{
				side1 = false;
				break;
			}
		}
		for (int i = 0; i < 3; i++)
		{
			if (board[i][2] != "o")
			{
				side2 = false;
				break;
			}
		}
		for (int i = 0; i < 3; i++)
		{
			if (board[i][i] != "o")
			{
				diagonal1 = false;
				break;
			}
		}
		for (int i = 0; i < 3; i++)
		{
			if (board[2-i][i] != "o")
			{
				diagonal2 = false;
				break;
			}
		}
		bool top1 = true, middle1 = true, bottom1 = true, side10 = true, side11 = true, side21 = true, diagonal11 = true, diagonal21 = true;
		for (int i = 0; i < 3; i++)
		{
			if (board[0][i] != "o")
			{
				top1 = false;
				break;
			}
		}
		for (int i = 0; i < 3; i++)
		{
			if (board[1][i] != "o")
			{
				middle1 = false;
				break;
			}
		}
		for (int i = 0; i < 3; i++)
		{
			if (board[2][i] != "o")
			{
				bottom1 = false;
				break;
			}
		}

		for (int i = 0; i < 3; i++)
		{
			if (board[i][0] != "o")
			{
				side10 = false;
				break;
			}
		}

		for (int i = 0; i < 3; i++)
		{
			if (board[i][1] != "o")
			{
				side11 = false;
				break;
			}
		}
		for (int i = 0; i < 3; i++)
		{
			if (board[i][2] != "o")
			{
				side21 = false;
				break;
			}
		}
		for (int i = 0; i < 3; i++)
		{
			if (board[i][i] != "o")
			{
				diagonal11 = false;
				break;
			}
		}
		for (int i = 0; i < 3; i++)
		{
			if (board[2-i][i] != "o")
			{
				diagonal21 = false;
				break;
			}
		}
		vector<bool>o_moves = {top, middle, bottom, side, side1, side2, diagonal1, diagonal2};
		vector<bool>x_moves = {top1, middle1, bottom1, side10, side11, side21, diagonal11, diagonal21};
		if (any_of(o_moves.begin(), o_moves.end(), [](bool i){return !i;}))
		{
			//cout << "o won"<< endl; //will have to return here
			return "o won";
		}
		else
		{
			if (any_of(x_moves.begin(), x_moves.end(), [](bool i){return !i;}))
			{
				return "x won";


			}
			else
			{
				return "tie";
			}
		}


	}
	string board[4][4];
};


class TackToe
{
public:
	//TackToe();
	void can_you_see_this()
	{
		cout << "Hello, how are you"<< endl;
	}
	void print_board()
	{
		for (int i = 0; i < 3; i++)
		{
			//string top_row = "";
			for (int b = 0; b < 3; b++)
			{
				if (b < 2)
				cout << board[i][b] << " | ";
				else
				cout << board[i][b] << endl;
			}
			if (i != 2)
			{
				cout << "----------"<< endl;
			}

		}
	}
	vector<vector<int> >get_possible_squares()
	{
		cout << "Here possible squares"<< endl;
		vector<vector<int> >final_vector;

		for (int i = 0; i < 3; i++)
		{

			for (int b = 0; b < 3; b++)
			{
				vector<int>on_iteration;
				if (board[i][b] == "-")
				{
					on_iteration.push_back(i);
					on_iteration.push_back(b);
					final_vector.push_back(on_iteration);
				}
			}
		}
		return final_vector;
	}
	void play()
	{
		//cout << "Here"<< endl;
		for (auto pair: get_possible_squares())
		{
			for (auto b: pair)
			{
				cout << b << " ";
			}
			cout << endl;
			cout << "here play"<< endl;
			determine_outcome(pair);
		}
	}
	string thewinner()
	{
		bool top = true, middle = true, bottom = true, side = true, side1 = true, side2 = true, diagonal1 = true, diagonal2 = true;

		for (int i = 0; i < 3; i++)
		{
			if (board[0][i] != "o")
			{
				top = false;
				break;
			}
		}
		for (int i = 0; i < 3; i++)
		{
			if (board[1][i] != "o")
			{
				middle = false;
				break;
			}
		}
		for (int i = 0; i < 3; i++)
		{
			if (board[2][i] != "o")
			{
				bottom = false;
				break;
			}
		}

		for (int i = 0; i < 3; i++)
		{
			if (board[i][0] != "o")
			{
				side = false;
				break;
			}
		}

		for (int i = 0; i < 3; i++)
		{
			if (board[i][1] != "o")
			{
				side1 = false;
				break;
			}
		}
		for (int i = 0; i < 3; i++)
		{
			if (board[i][2] != "o")
			{
				side2 = false;
				break;
			}
		}
		for (int i = 0; i < 3; i++)
		{
			if (board[i][i] != "o")
			{
				diagonal1 = false;
				break;
			}
		}
		for (int i = 0; i < 3; i++)
		{
			if (board[2-i][i] != "o")
			{
				diagonal2 = false;
				break;
			}
		}
		bool top1 = true, middle1 = true, bottom1 = true, side10 = true, side11 = true, side21 = true, diagonal11 = true, diagonal21 = true;
		for (int i = 0; i < 3; i++)
		{
			if (board[0][i] != "o")
			{
				top1 = false;
				break;
			}
		}
		for (int i = 0; i < 3; i++)
		{
			if (board[1][i] != "o")
			{
				middle1 = false;
				break;
			}
		}
		for (int i = 0; i < 3; i++)
		{
			if (board[2][i] != "o")
			{
				bottom1 = false;
				break;
			}
		}

		for (int i = 0; i < 3; i++)
		{
			if (board[i][0] != "o")
			{
				side10 = false;
				break;
			}
		}

		for (int i = 0; i < 3; i++)
		{
			if (board[i][1] != "o")
			{
				side11 = false;
				break;
			}
		}
		for (int i = 0; i < 3; i++)
		{
			if (board[i][2] != "o")
			{
				side21 = false;
				break;
			}
		}
		for (int i = 0; i < 3; i++)
		{
			if (board[i][i] != "o")
			{
				diagonal11 = false;
				break;
			}
		}
		for (int i = 0; i < 3; i++)
		{
			if (board[2-i][i] != "o")
			{
				diagonal21 = false;
				break;
			}
		}
		vector<bool>o_moves = {top, middle, bottom, side, side1, side2, diagonal1, diagonal2};
		vector<bool>x_moves = {top1, middle1, bottom1, side10, side11, side21, diagonal11, diagonal21};
		if (any_of(o_moves.begin(), o_moves.end(), [](bool i){return !i;}))
		{
			//cout << "o won"<< endl; //will have to return here
			return "o won";
		}
		else
		{
			if (any_of(x_moves.begin(), x_moves.end(), [](bool i){return !i;}))
			{
				return "x won";


			}
			else
			{
				return "tie";
			}
		}


	}

	bool is_winner()
	{
		bool top = true, middle = true, bottom = true, side = true, side1 = true, side2 = true, diagonal1 = true, diagonal2 = true;

		for (int i = 0; i < 3; i++)
		{
			if (board[0][i] != "o")
			{
				top = false;
				break;
			}
		}
		for (int i = 0; i < 3; i++)
		{
			if (board[1][i] != "o")
			{
				middle = false;
				break;
			}
		}
		for (int i = 0; i < 3; i++)
		{
			if (board[2][i] != "o")
			{
				bottom = false;
				break;
			}
		}

		for (int i = 0; i < 3; i++)
		{
			if (board[i][0] != "o")
			{
				side = false;
				break;
			}
		}

		for (int i = 0; i < 3; i++)
		{
			if (board[i][1] != "o")
			{
				side1 = false;
				break;
			}
		}
		for (int i = 0; i < 3; i++)
		{
			if (board[i][2] != "o")
			{
				side2 = false;
				break;
			}
		}
		for (int i = 0; i < 3; i++)
		{
			if (board[i][i] != "o")
			{
				diagonal1 = false;
				break;
			}
		}
		for (int i = 0; i < 3; i++)
		{
			if (board[2-i][i] != "o")
			{
				diagonal2 = false;
				break;
			}
		}
		bool top1 = true, middle1 = true, bottom1 = true, side10 = true, side11 = true, side21 = true, diagonal11 = true, diagonal21 = true;
		for (int i = 0; i < 3; i++)
		{
			if (board[0][i] != "o")
			{
				top1 = false;
				break;
			}
		}
		for (int i = 0; i < 3; i++)
		{
			if (board[1][i] != "o")
			{
				middle1 = false;
				break;
			}
		}
		for (int i = 0; i < 3; i++)
		{
			if (board[2][i] != "o")
			{
				bottom1 = false;
				break;
			}
		}

		for (int i = 0; i < 3; i++)
		{
			if (board[i][0] != "o")
			{
				side10 = false;
				break;
			}
		}

		for (int i = 0; i < 3; i++)
		{
			if (board[i][1] != "o")
			{
				side11 = false;
				break;
			}
		}
		for (int i = 0; i < 3; i++)
		{
			if (board[i][2] != "o")
			{
				side21 = false;
				break;
			}
		}
		for (int i = 0; i < 3; i++)
		{
			if (board[i][i] != "o")
			{
				diagonal11 = false;
				break;
			}
		}
		for (int i = 0; i < 3; i++)
		{
			if (board[2-i][i] != "o")
			{
				diagonal21 = false;
				break;
			}
		}
		vector<bool>o_moves = {top, middle, bottom, side, side1, side2, diagonal1, diagonal2};
		vector<bool>x_moves = {top1, middle1, bottom1, side1, side11, side21, diagonal11, diagonal21};
		if (any_of(o_moves.begin(), o_moves.end(), [](bool i){return !i;}))
		{
			//cout << "o won"<< endl; //will have to return here
			return true;
		}
		else
		{
			if (any_of(x_moves.begin(), x_moves.end(), [](bool i){return !i;}))
			{
				return true;


			}
			else
			{
				return false;
			}
		}


	}

	void determine_outcome(vector<int>coords)
	{
		cout << "arrived here"<< endl;
		SmallGame smallgame(board);
		int a = coords[0];
		int b = coords[1];
		cout << "a "<< a << endl;
		cout << "b "<< b << endl;
		smallgame.board[a][b] = "o";
		for (int i = 0; i < 3; i++)
		{
			for (int b = 0; b < 3; b++)
			{
				cout << smallgame.board[i][b]<< " ";
			}
			cout << endl;
		}
		cout << "so far, here"<< endl;
		while (smallgame.is_winner())
		{
			cout << "running loop"<< endl;

			smallgame.make_move();
		}

		string game_winner = smallgame.thewinner();
		if (game_winner == "o won")
		{
			possible_squares.push_back(coords);
			results.push_back(1);

		}
		else
		{
			if (game_winner == "x won")
			{
				possible_squares.push_back(coords);
				results.push_back(0);

			}
			else
			{
				possible_squares.push_back(coords);
				results.push_back(0.5);
			}
		}


	}
	void decide_move()
	{
		vector<vector<int> >first_choice;
		vector<vector<int> >second_choice;

		for (int i = 0; i < results.size(); i++)
		{
			if (results[i] == 1)
			{
				first_choice.push_back(possible_squares[i]);
			}
			else if (results[i] == 0.5)
			{
				second_choice.push_back(possible_squares[i]);
			}

		}
		vector<int>the_square;
		if (first_choice.size() > 0)
		{
			int rand_index = rand()%first_choice.size()+0;
			the_square = first_choice[rand_index];

		}
		else if (second_choice.size() > 0)
		{
			int rand_index = rand()%second_choice.size()+0;
			the_square = second_choice[rand_index];

		}
		else
		{
			int rand_index = rand()%possible_squares.size()+0;
			the_square = possible_squares[rand_index];
		}
		int place1 = the_square[0];
		int place2 = the_square[1];
		board[place1][place2] = "o";
		possible_squares.clear();
	}
	friend ostream& operator <<(ostream& out, TackToe& who_winner) //still needed friend
	{

		out << who_winner.winner;
		return out;
	}

	void user_move()
	{
		int x, y;
		cout << "Enter the x-coordinate: ";
		cin >> x;
		cout << "Enter the y-corrdnate: ";
		cin >> y;
		board[x][y] = "x";
	}



	string winner = "none_yet";



private:
	string board[4][4] = {
		{"-", "-", "-"},
		{"-", "-", "-"},
		{"-", "-", "-"}};

	vector<vector<int> >possible_squares;
	vector<double>results;
	//string winner = "none_yet";

};
/*
ostream& operator <<(ostream& out, MainGame::TackToe& who_winner)
{
out << who_winner.winner;
return out;
}
*/


int main()
{

	TackToe the_game;
	while (true)
		//the_game.print_board();
		//the_game.can_you_see_this();

		the_game.play();
		the_game.decide_move();
		the_game.user_move();
		the_game.print_board();

	cout << the_game << endl;






}
