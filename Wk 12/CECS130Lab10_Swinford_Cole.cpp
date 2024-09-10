/*
	Cole Swinford
	Lab 10, Sec. 1
	March 31, 2022
	3D Tic-Tac-Toe
*/

#include <iostream>
#include <ctype.h>
#include <cstdlib>
#include <time.h>
using namespace std;


int UserStart;
int BoardStart;
string UserChoice;
string BoardChoice;
bool MoveOn;
int RandPCM;
string PM;
string PCM;
string Default = " ";

int RandStart()
// Randomly select starting player
{
	srand(time(0));
	UserStart = rand() % 2;
	//cout << "UserStart: " << UserStart << endl;

	if(UserStart == 0)
	{
		cout << "\nI go first" << endl;

		// X, O selection
		srand(time(0));
		RandPCM = rand() % 10;
		cout << RandPCM;

		if(RandPCM < 5)
		{
			PCM = "x";
		}
		if(RandPCM >= 5)
		{
			PCM = "o";
		}

		if(PCM == "x")
		{
			PM = "o";
		}

		if(PCM == "o")
		{
			PM = "x";
		}
	}

	if(UserStart == 1)
	{
		// X, O selection
		cout << "\nChoose your fighter 'x' or 'o'" << endl;
		cin >> PM;
		UserChoice = PM;
	}

	return UserStart;
}

// Dimension 1
class TTT
{
    public:
        string Row3[4];
        string Row2[4];
        string Row1[4];

		// Default board
        int DefaultBoard()
        {
            Row3[1] = Default;
            Row3[2] = Default;
            Row3[3] = Default;

            Row2[1] = Default;
            Row2[2] = Default;
            Row2[3] = Default;

            Row1[1] = Default;
            Row1[2] = Default;
            Row1[3] = Default;

			cout << "\n[1]" << endl;
            cout << "#################" << endl;
            cout << "|| " << Row3[1] << " || " << Row3[2] << " || " << Row3[3] << " ||" << endl;
            cout << "#################" << endl;
            cout << "|| " << Row2[1] << " || " << Row2[2] << " || " << Row2[3] << " ||" << endl;
            cout << "#################" << endl;
            cout << "|| " << Row1[1] << " || " << Row1[2] << " || " << Row1[3] << " ||" << endl;
            cout << "#################" << endl;

            return 0;
        }

		// Player move
        int PlayerMove()
        {
			bool prompt = true;
			int PMx;
			int PMy;

			if(prompt == true)
			{
				// x-coordinate selection
				cout << "\nx coordinate: ";
				cin >> PMx;

				// y-coordinate selection
				cout << "\ny coordinate: ";
				cin >> PMy;

				prompt = false;
			}

			if(PMy == 1)
			{
				if(Row1[PMx] == " ")
				{
					Row1[PMx] = PM;
					MoveOn = true;
				}

				else
				{
					cout << "Illegal move, try again." << endl;
					prompt = true;
				}
			}

			if(PMy == 2)
			{
				if(Row2[PMx] == " ")
				{
					Row2[PMx] = PM;
					MoveOn = true;
				}

				else
				{
					cout << "Illegal move, try again." << endl;
					prompt = true;
				}
			}

			if(PMy == 3)
			{
				if(Row3[PMx] == " ")
				{
					Row3[PMx] = PM;
					MoveOn = true;
				}

				else
				{
					cout << "Illegal move, try again." << endl;
					prompt = true;
				}
			}

			return 0;
        }

		// Update the board
		int UpdateBoard()
		{
            cout << "#################" << endl;
            cout << "|| " << Row3[1] << " || " << Row3[2] << " || " << Row3[3] << " ||" << endl;
            cout << "#################" << endl;
            cout << "|| " << Row2[1] << " || " << Row2[2] << " || " << Row2[3] << " ||" << endl;
            cout << "#################" << endl;
            cout << "|| " << Row1[1] << " || " << Row1[2] << " || " << Row1[3] << " ||" << endl;
            cout << "#################" << endl;

            return 0;
		}

		// Computer move
		int PCMove()
        {
			bool PC = true;
			while(PC == true)
			{
				bool Roll = true;
				int PCx;
				int PCy;

				if(Roll == true)
				{
					if(Row1[1] == Default || Row1[2] == Default || Row1[3] == Default)
					{
						// x-coordinate selection
						srand(time(0));
						PCx = rand() % 3 + 1;
						//cout << "PCx: " << PCx << endl;

						// y-coordinate selection
						PCy = 1;
						//cout << "PCy: " << PCy << endl;

						Roll = false;
					}

					if(Row2[1] == Default || Row2[2] == Default || Row2[3] == Default)
					{
						// x-coordinate selection
						srand(time(0));
						PCx = rand() % 3 + 1;
						//cout << "PCx: " << PCx << endl;

						// y-coordinate selection
						PCy = 2;
						//cout << "PCy: " << PCy << endl;

						Roll = false;
					}

					if(Row3[1] == Default || Row3[2] == Default || Row3[3] == Default)
					{
						// x-coordinate selection
						srand(time(0));
						PCx = rand() % 3 + 1;
						//cout << "PCx: " << PCx << endl;

						// y-coordinate selection
						PCy = 3;
						//cout << "PCy: " << PCy << endl;

						Roll = false;
					}
				}

				if(UserStart == 1)
				{
					if(UserChoice == "x")
					{
						PCM = "o";
					}

					if(UserChoice == "o")
					{
						PCM = "x";
					}
				}

				if(PCy == 1)
				{
					if(Row1[PCx] == Default)
					{
						Row1[PCx] = PCM;
						PC = false;
					}

					else
					{
						Roll = true;
					}
				}

				if(PCy == 2)
				{
					if(Row2[PCx] == Default)
					{
						Row2[PCx] = PCM;
						PC = false;
					}

					else
					{
						Roll = true;
					}
				}

				if(PCy == 3)
				{
					if(Row3[PCx] == Default)
					{
						Row3[PCx] = PCM;
						PC = false;
					}

					else
					{
						Roll = true;
					}
				}
			}

			return 0;
        }

		// Check for win condition
		int End()
		{
			// Player Win (horizontal)
			if(Row1[1] == PM && Row1[1] == Row1[2] && Row1[2] == Row1[3])
			{
				cout << "\n// You win!" << endl;

				Reset();
				return 0;
			}
			if(Row2[1] == PM && Row2[1] == Row2[2] && Row2[2] == Row2[3])
			{
				cout << "\n// You win!" << endl;

				Reset();
				return 0;
			}
			if(Row3[1] == PM && Row3[1] == Row3[2] && Row3[2] == Row3[3])
			{
				cout << "\n// You win!" << endl;

				Reset();
				return 0;
			}

			// Player Win (vertical)
			if(Row1[1] == PM && Row1[1] == Row2[1] && Row2[1] == Row3[1])
			{
				cout << "\n// You win!" << endl;

				Reset();
				return 0;
			}
			if(Row1[2] == PM && Row1[2] == Row2[2] && Row2[2] == Row3[2])
			{
				cout << "\n// You win!" << endl;

				Reset();
				return 0;
			}
			if(Row1[3] == PM && Row1[3] == Row2[3] && Row2[3] == Row3[3])
			{
				cout << "\n// You win!" << endl;

				Reset();
				return 0;
			}

			// Player Win (diagonal)
			if(Row1[1] == PM && Row1[1] == Row2[2] && Row3[3] == Row2[2])
			{
				cout << "\n// You win!" << endl;

				Reset();
				return 0;
			}
			if(Row3[1] == PM && Row3[1] == Row2[2] && Row1[3] == Row2[2])
			{
				cout << "\n// You win!" << endl;

				Reset();
				return 0;
			}

/*--------------------------------------------------------------------------------------------------------------------------------------------------*/

			// Computer Win (horizontal)
			if(Row1[1] == PCM && Row1[1] == Row1[2] && Row1[2] == Row1[3])
			{
				cout << "\n// I win!" << endl;

				Reset();
				return 0;
			}
			if(Row2[1] == PCM && Row2[1] == Row2[2] && Row2[2] == Row2[3])
			{
				cout << "\n// I win!" << endl;

				Reset();
				return 0;
			}
			if(Row3[1] == PCM && Row3[1] == Row3[2] && Row3[2] == Row3[3])
			{
				cout << "\n// I win!" << endl;

				Reset();
				return 0;
			}

			// Computer Win (vertical)
			if(Row1[1] == PCM && Row1[1] == Row2[1] && Row2[1] == Row3[1])
			{
				cout << "\n// I win!" << endl;

				Reset();
				return 0;
			}
			if(Row1[2] == PCM && Row1[2] == Row2[2] && Row2[2] == Row3[2])
			{
				cout << "\n// I win!" << endl;

				Reset();
				return 0;
			}
			if(Row1[3] == PCM && Row1[3] == Row2[3] && Row2[3] == Row3[3])
			{
				cout << "\n// I win!" << endl;

				Reset();
				return 0;
			}

			// Computer Win (diagonal)
			if(Row1[1] == PCM && Row1[1] == Row2[2] && Row3[3] == Row2[2])
			{
				cout << "\n// I win!" << endl;

				Reset();
				return 0;
			}
			if(Row3[1] == PCM && Row3[1] == Row2[2] && Row1[3] == Row2[2])
			{
				cout << "\n// I win!" << endl;

				Reset();
				return 0;
			}

/*--------------------------------------------------------------------------------------------------------------------------------------------------*/

			// Continue
			else
			{
				// Draw
				if(Row1[1] != Default && Row1[2] != Default && Row1[3] != Default && Row2[1] != Default && Row2[2] != Default && Row2[3] != Default && Row3[1] != Default && Row3[2] != Default && Row3[3] != Default)
				{
					cout << "\n// Draw!" << endl;

					Reset();
					return 0;
				}

				else
				{
					MoveOn = true;
					return 0;
				}

			}
		}

		// Reset Board
		int Reset()
		{
            Row3[1] = Default;
            Row3[2] = Default;
            Row3[3] = Default;

            Row2[1] = Default;
            Row2[2] = Default;
            Row2[3] = Default;

            Row1[1] = Default;
            Row1[2] = Default;
            Row1[3] = Default;

			cout << "\n----------------------------------" << endl;
			cout << "Default Board" << endl;
			UpdateBoard();

			// Board 2
			cout << "\n\t[2]" << endl;
            cout << "\t#################" << endl;
            cout << "\t|| " << Row3[1] << " || " << Row3[2] << " || " << Row3[3] << " ||" << endl;
            cout << "\t#################" << endl;
            cout << "\t|| " << Row2[1] << " || " << Row2[2] << " || " << Row2[3] << " ||" << endl;
            cout << "\t#################" << endl;
            cout << "\t|| " << Row1[1] << " || " << Row1[2] << " || " << Row1[3] << " ||" << endl;
            cout << "\t#################" << endl;

			// Board 3
			cout << "\n\t\t[3]" << endl;
            cout << "\t\t#################" << endl;
            cout << "\t\t|| " << Row3[1] << " || " << Row3[2] << " || " << Row3[3] << " ||" << endl;
            cout << "\t\t#################" << endl;
            cout << "\t\t|| " << Row2[1] << " || " << Row2[2] << " || " << Row2[3] << " ||" << endl;
            cout << "\t\t#################" << endl;
            cout << "\t\t|| " << Row1[1] << " || " << Row1[2] << " || " << Row1[3] << " ||" << endl;
            cout << "\t\t#################" << endl;

			cout << "\n----------------------------------" << endl;

			RandStart();
		}

};

// Dimension 2
class Board2: public TTT
{
	public:

		// Default board
        int DefaultBoard()
        {
            Row3[1] = Default;
            Row3[2] = Default;
            Row3[3] = Default;

            Row2[1] = Default;
            Row2[2] = Default;
            Row2[3] = Default;

            Row1[1] = Default;
            Row1[2] = Default;
            Row1[3] = Default;

			cout << "\n\t[2]" << endl;
            cout << "\t#################" << endl;
            cout << "\t|| " << Row3[1] << " || " << Row3[2] << " || " << Row3[3] << " ||" << endl;
            cout << "\t#################" << endl;
            cout << "\t|| " << Row2[1] << " || " << Row2[2] << " || " << Row2[3] << " ||" << endl;
            cout << "\t#################" << endl;
            cout << "\t|| " << Row1[1] << " || " << Row1[2] << " || " << Row1[3] << " ||" << endl;
            cout << "\t#################" << endl;

            return 0;
        }

		// Update the board
		int UpdateBoard()
		{
			cout << "\n\t[2]" << endl;
            cout << "\t#################" << endl;
            cout << "\t|| " << Row3[1] << " || " << Row3[2] << " || " << Row3[3] << " ||" << endl;
            cout << "\t#################" << endl;
            cout << "\t|| " << Row2[1] << " || " << Row2[2] << " || " << Row2[3] << " ||" << endl;
            cout << "\t#################" << endl;
            cout << "\t|| " << Row1[1] << " || " << Row1[2] << " || " << Row1[3] << " ||" << endl;
            cout << "\t#################" << endl;

            return 0;
		}

		// Reset Board
		int Reset()
		{
            Row3[1] = Default;
            Row3[2] = Default;
            Row3[3] = Default;

            Row2[1] = Default;
            Row2[2] = Default;
            Row2[3] = Default;

            Row1[1] = Default;
            Row1[2] = Default;
            Row1[3] = Default;

			cout << "\n----------------------------------" << endl;
			cout << "Default Board" << endl;

			// Board 1
			cout << "[2]" << endl;
            cout << "#################" << endl;
            cout << "|| " << Row3[1] << " || " << Row3[2] << " || " << Row3[3] << " ||" << endl;
            cout << "#################" << endl;
            cout << "|| " << Row2[1] << " || " << Row2[2] << " || " << Row2[3] << " ||" << endl;
            cout << "#################" << endl;
            cout << "|| " << Row1[1] << " || " << Row1[2] << " || " << Row1[3] << " ||" << endl;
            cout << "#################" << endl;

			UpdateBoard();

			// Board 3
			cout << "\n\t\t[3]" << endl;
            cout << "\t\t#################" << endl;
            cout << "\t\t|| " << Row3[1] << " || " << Row3[2] << " || " << Row3[3] << " ||" << endl;
            cout << "\t\t#################" << endl;
            cout << "\t\t|| " << Row2[1] << " || " << Row2[2] << " || " << Row2[3] << " ||" << endl;
            cout << "\t\t#################" << endl;
            cout << "\t\t|| " << Row1[1] << " || " << Row1[2] << " || " << Row1[3] << " ||" << endl;
            cout << "\t\t#################" << endl;

			cout << "\n----------------------------------" << endl;

			RandStart();
		}

};

// Dimension 3
class Board3: public TTT
{
	public:
		
		// Default board
        int DefaultBoard()
        {
            Row3[1] = Default;
            Row3[2] = Default;
            Row3[3] = Default;

            Row2[1] = Default;
            Row2[2] = Default;
            Row2[3] = Default;

            Row1[1] = Default;
            Row1[2] = Default;
            Row1[3] = Default;

			cout << "\n\t\t[3]" << endl;
            cout << "\t\t#################" << endl;
            cout << "\t\t|| " << Row3[1] << " || " << Row3[2] << " || " << Row3[3] << " ||" << endl;
            cout << "\t\t#################" << endl;
            cout << "\t\t|| " << Row2[1] << " || " << Row2[2] << " || " << Row2[3] << " ||" << endl;
            cout << "\t\t#################" << endl;
            cout << "\t\t|| " << Row1[1] << " || " << Row1[2] << " || " << Row1[3] << " ||" << endl;
            cout << "\t\t#################" << endl;

            return 0;
        }

		// Update the board
		int UpdateBoard()
		{
			cout << "\n\t\t[2]" << endl;
            cout << "\t\t#################" << endl;
            cout << "\t\t|| " << Row3[1] << " || " << Row3[2] << " || " << Row3[3] << " ||" << endl;
            cout << "\t\t#################" << endl;
            cout << "\t\t|| " << Row2[1] << " || " << Row2[2] << " || " << Row2[3] << " ||" << endl;
            cout << "\t\t#################" << endl;
            cout << "\t\t|| " << Row1[1] << " || " << Row1[2] << " || " << Row1[3] << " ||" << endl;
            cout << "\t\t#################" << endl;

            return 0;
		}

		// Reset Board
		int Reset()
		{
            Row3[1] = Default;
            Row3[2] = Default;
            Row3[3] = Default;

            Row2[1] = Default;
            Row2[2] = Default;
            Row2[3] = Default;

            Row1[1] = Default;
            Row1[2] = Default;
            Row1[3] = Default;

			cout << "\n----------------------------------" << endl;
			cout << "Default Board" << endl;

			// Board 1
			cout << "[2]" << endl;
            cout << "#################" << endl;
            cout << "|| " << Row3[1] << " || " << Row3[2] << " || " << Row3[3] << " ||" << endl;
            cout << "#################" << endl;
            cout << "|| " << Row2[1] << " || " << Row2[2] << " || " << Row2[3] << " ||" << endl;
            cout << "#################" << endl;
            cout << "|| " << Row1[1] << " || " << Row1[2] << " || " << Row1[3] << " ||" << endl;
            cout << "#################" << endl;

			// Board 2
			cout << "\n\t[2]" << endl;
            cout << "\t#################" << endl;
            cout << "\t|| " << Row3[1] << " || " << Row3[2] << " || " << Row3[3] << " ||" << endl;
            cout << "\t#################" << endl;
            cout << "\t|| " << Row2[1] << " || " << Row2[2] << " || " << Row2[3] << " ||" << endl;
            cout << "\t#################" << endl;
            cout << "\t|| " << Row1[1] << " || " << Row1[2] << " || " << Row1[3] << " ||" << endl;
            cout << "\t#################" << endl;

			UpdateBoard();

			cout << "\n----------------------------------" << endl;

			RandStart();
		}

};

int main()
{
	TTT t;
	Board2 t2;
	Board3 t3;
	cout << "\n----------------------------------" << endl;
	cout << "Default Board" << endl;
	t.DefaultBoard();
	t2.DefaultBoard();
	t3.DefaultBoard();
	cout << "----------------------------------" << endl;
	RandStart();

	// If User starts
	if(UserStart == 1)
	{
		while(1)
		{
			// Board Selection
			cout << "Select a board [1, 2, 3]" << endl;
			cin >> BoardChoice;

			if(BoardChoice == "1")
			{
				t.PlayerMove();
				cout << "\nYour move" << endl;
				t.UpdateBoard();
				t2.UpdateBoard();
				t3.UpdateBoard();
				t.End();
				// Player Win (row 1)
				if(t.Row1[1] == PM && t.Row1[1] == t2.Row1[1] && t2.Row1[1] == t3.Row1[1])
				{
					cout << "\n// You win!" << endl;

					t.Reset();
					t2.Reset();
					t3.Reset();
				}
				if(t.Row1[2] == PM && t.Row1[2] == t2.Row1[2] && t2.Row1[2] == t3.Row1[2])
				{
					cout << "\n// You win!" << endl;

					t.Reset();
					t2.Reset();
					t3.Reset();
				}
				if(t.Row1[3] == PM && t.Row1[3] == t2.Row1[3] && t2.Row1[3] == t3.Row1[3])
				{
					cout << "\n// You win!" << endl;

					t.Reset();
					t2.Reset();
					t3.Reset();
				}
				// Player Win (row 2)
				if(t.Row2[1] == PM && t.Row2[1] == t2.Row2[1] && t2.Row2[1] == t3.Row2[1])
				{
					cout << "\n// You win!" << endl;

					t.Reset();
					t2.Reset();
					t3.Reset();
				}
				if(t.Row2[2] == PM && t.Row2[2] == t2.Row2[2] && t2.Row2[2] == t3.Row2[2])
				{
					cout << "\n// You win!" << endl;

					t.Reset();
					t2.Reset();
					t3.Reset();
				}
				if(t.Row2[3] == PM && t.Row2[3] == t2.Row2[3] && t2.Row2[3] == t3.Row2[3])
				{
					cout << "\n// You win!" << endl;

					t.Reset();
					t2.Reset();
					t3.Reset();
				}
				// Player Win (row 3)
				if(t.Row3[1] == PM && t.Row3[1] == t2.Row3[1] && t2.Row3[1] == t3.Row3[1])
				{
					cout << "\n// You win!" << endl;

					t.Reset();
					t2.Reset();
					t3.Reset();
				}
				if(t.Row3[2] == PM && t.Row3[2] == t2.Row3[2] && t2.Row3[2] == t3.Row3[2])
				{
					cout << "\n// You win!" << endl;

					t.Reset();
					t2.Reset();
					t3.Reset();
				}
				if(t.Row3[3] == PM && t.Row3[3] == t2.Row3[3] && t2.Row3[3] == t3.Row3[3])
				{
					cout << "\n// You win!" << endl;

					t.Reset();
					t2.Reset();
					t3.Reset();
				}

			/*--------------------------------------------------------------------------------------------------------------------------------------------------*/

				// Computer Win (row 1)
				if(t.Row1[1] == PCM && t.Row1[1] == t2.Row1[1] && t2.Row1[1] == t3.Row1[1])
				{
					cout << "\n// I win!" << endl;

					t.Reset();
					t2.Reset();
					t3.Reset();
				}
				if(t.Row1[2] == PCM && t.Row1[2] == t2.Row1[2] && t2.Row1[2] == t3.Row1[2])
				{
					cout << "\n// I win!" << endl;

					t.Reset();
					t2.Reset();
					t3.Reset();
				}
				if(t.Row1[3] == PCM && t.Row1[3] == t2.Row1[3] && t2.Row1[3] == t3.Row1[3])
				{
					cout << "\n// I win!" << endl;

					t.Reset();
					t2.Reset();
					t3.Reset();
				}
				// Computer Win (row 2)
				if(t.Row2[1] == PCM && t.Row2[1] == t2.Row2[1] && t2.Row2[1] == t3.Row2[1])
				{
					cout << "\n// I win!" << endl;

					t.Reset();
					t2.Reset();
					t3.Reset();
				}
				if(t.Row2[2] == PCM && t.Row2[2] == t2.Row2[2] && t2.Row2[2] == t3.Row2[2])
				{
					cout << "\n// I win!" << endl;

					t.Reset();
					t2.Reset();
					t3.Reset();
				}
				if(t.Row2[3] == PCM && t.Row2[3] == t2.Row2[3] && t2.Row2[3] == t3.Row2[3])
				{
					cout << "\n// I win!" << endl;

					t.Reset();
					t2.Reset();
					t3.Reset();
				}
				// Computer Win (row 3)
				if(t.Row3[1] == PCM && t.Row3[1] == t2.Row3[1] && t2.Row3[1] == t3.Row3[1])
				{
					cout << "\n// I win!" << endl;

					t.Reset();
					t2.Reset();
					t3.Reset();
				}
				if(t.Row3[2] == PCM && t.Row3[2] == t2.Row3[2] && t2.Row3[2] == t3.Row3[2])
				{
					cout << "\n// I win!" << endl;

					t.Reset();
					t2.Reset();
					t3.Reset();
				}
				if(t.Row3[3] == PCM && t.Row3[3] == t2.Row3[3] && t2.Row3[3] == t3.Row3[3])
				{
					cout << "\n// I win!" << endl;

					t.Reset();
					t2.Reset();
					t3.Reset();
				}

			/*--------------------------------------------------------------------------------------------------------------------------------------------------*/

				// Continue
				else
				{
					// Draw
					if(t.Row1[1] != Default && t.Row1[2] != Default && t.Row1[3] != Default && t.Row2[1] != Default && t.Row2[2] != Default && t.Row2[3] != Default && t.Row3[1] != Default && t.Row3[2] != Default && t.Row3[3] != Default && t2.Row1[1] != Default && t2.Row1[2] != Default && t2.Row1[3] != Default && t2.Row2[1] != Default && t2.Row2[2] != Default && t2.Row2[3] != Default && t2.Row3[1] != Default && t2.Row3[2] != Default && t2.Row3[3] != Default && t3.Row1[1] != Default && t3.Row1[2] != Default && t3.Row1[3] != Default && t3.Row2[1] != Default && t3.Row2[2] != Default && t3.Row2[3] != Default && t3.Row3[1] != Default && t3.Row3[2] != Default && t3.Row3[3] != Default)
					{
						cout << "\n// Draw!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}

					else
					{
						MoveOn = true;
					}

				}
			}

			if(BoardChoice == "2")
			{
				t2.PlayerMove();
				cout << "\nYour move" << endl;
				t.UpdateBoard();
				t2.UpdateBoard();
				t3.UpdateBoard();
				t2.End();
				// Player Win (row 1)
				if(t.Row1[1] == PM && t.Row1[1] == t2.Row1[1] && t2.Row1[1] == t3.Row1[1])
				{
					cout << "\n// You win!" << endl;

					t.Reset();
					t2.Reset();
					t3.Reset();
				}
				if(t.Row1[2] == PM && t.Row1[2] == t2.Row1[2] && t2.Row1[2] == t3.Row1[2])
				{
					cout << "\n// You win!" << endl;

					t.Reset();
					t2.Reset();
					t3.Reset();
				}
				if(t.Row1[3] == PM && t.Row1[3] == t2.Row1[3] && t2.Row1[3] == t3.Row1[3])
				{
					cout << "\n// You win!" << endl;

					t.Reset();
					t2.Reset();
					t3.Reset();
				}
				// Player Win (row 2)
				if(t.Row2[1] == PM && t.Row2[1] == t2.Row2[1] && t2.Row2[1] == t3.Row2[1])
				{
					cout << "\n// You win!" << endl;

					t.Reset();
					t2.Reset();
					t3.Reset();
				}
				if(t.Row2[2] == PM && t.Row2[2] == t2.Row2[2] && t2.Row2[2] == t3.Row2[2])
				{
					cout << "\n// You win!" << endl;

					t.Reset();
					t2.Reset();
					t3.Reset();
				}
				if(t.Row2[3] == PM && t.Row2[3] == t2.Row2[3] && t2.Row2[3] == t3.Row2[3])
				{
					cout << "\n// You win!" << endl;

					t.Reset();
					t2.Reset();
					t3.Reset();
				}
				// Player Win (row 3)
				if(t.Row3[1] == PM && t.Row3[1] == t2.Row3[1] && t2.Row3[1] == t3.Row3[1])
				{
					cout << "\n// You win!" << endl;

					t.Reset();
					t2.Reset();
					t3.Reset();
				}
				if(t.Row3[2] == PM && t.Row3[2] == t2.Row3[2] && t2.Row3[2] == t3.Row3[2])
				{
					cout << "\n// You win!" << endl;

					t.Reset();
					t2.Reset();
					t3.Reset();
				}
				if(t.Row3[3] == PM && t.Row3[3] == t2.Row3[3] && t2.Row3[3] == t3.Row3[3])
				{
					cout << "\n// You win!" << endl;

					t.Reset();
					t2.Reset();
					t3.Reset();
				}

			/*--------------------------------------------------------------------------------------------------------------------------------------------------*/

				// Computer Win (row 1)
				if(t.Row1[1] == PCM && t.Row1[1] == t2.Row1[1] && t2.Row1[1] == t3.Row1[1])
				{
					cout << "\n// I win!" << endl;

					t.Reset();
					t2.Reset();
					t3.Reset();
				}
				if(t.Row1[2] == PCM && t.Row1[2] == t2.Row1[2] && t2.Row1[2] == t3.Row1[2])
				{
					cout << "\n// I win!" << endl;

					t.Reset();
					t2.Reset();
					t3.Reset();
				}
				if(t.Row1[3] == PCM && t.Row1[3] == t2.Row1[3] && t2.Row1[3] == t3.Row1[3])
				{
					cout << "\n// I win!" << endl;

					t.Reset();
					t2.Reset();
					t3.Reset();
				}
				// Computer Win (row 2)
				if(t.Row2[1] == PCM && t.Row2[1] == t2.Row2[1] && t2.Row2[1] == t3.Row2[1])
				{
					cout << "\n// I win!" << endl;

					t.Reset();
					t2.Reset();
					t3.Reset();
				}
				if(t.Row2[2] == PCM && t.Row2[2] == t2.Row2[2] && t2.Row2[2] == t3.Row2[2])
				{
					cout << "\n// I win!" << endl;

					t.Reset();
					t2.Reset();
					t3.Reset();
				}
				if(t.Row2[3] == PCM && t.Row2[3] == t2.Row2[3] && t2.Row2[3] == t3.Row2[3])
				{
					cout << "\n// I win!" << endl;

					t.Reset();
					t2.Reset();
					t3.Reset();
				}
				// Computer Win (row 3)
				if(t.Row3[1] == PCM && t.Row3[1] == t2.Row3[1] && t2.Row3[1] == t3.Row3[1])
				{
					cout << "\n// I win!" << endl;

					t.Reset();
					t2.Reset();
					t3.Reset();
				}
				if(t.Row3[2] == PCM && t.Row3[2] == t2.Row3[2] && t2.Row3[2] == t3.Row3[2])
				{
					cout << "\n// I win!" << endl;

					t.Reset();
					t2.Reset();
					t3.Reset();
				}
				if(t.Row3[3] == PCM && t.Row3[3] == t2.Row3[3] && t2.Row3[3] == t3.Row3[3])
				{
					cout << "\n// I win!" << endl;

					t.Reset();
					t2.Reset();
					t3.Reset();
				}

			/*--------------------------------------------------------------------------------------------------------------------------------------------------*/

				// Continue
				else
				{
					// Draw
					if(t.Row1[1] != Default && t.Row1[2] != Default && t.Row1[3] != Default && t.Row2[1] != Default && t.Row2[2] != Default && t.Row2[3] != Default && t.Row3[1] != Default && t.Row3[2] != Default && t.Row3[3] != Default && t2.Row1[1] != Default && t2.Row1[2] != Default && t2.Row1[3] != Default && t2.Row2[1] != Default && t2.Row2[2] != Default && t2.Row2[3] != Default && t2.Row3[1] != Default && t2.Row3[2] != Default && t2.Row3[3] != Default && t3.Row1[1] != Default && t3.Row1[2] != Default && t3.Row1[3] != Default && t3.Row2[1] != Default && t3.Row2[2] != Default && t3.Row2[3] != Default && t3.Row3[1] != Default && t3.Row3[2] != Default && t3.Row3[3] != Default)
					{
						cout << "\n// Draw!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}

					else
					{
						MoveOn = true;
					}

				}
			}

			if(BoardChoice == "3")
			{
				t3.PlayerMove();
				cout << "\nYour move" << endl;
				t.UpdateBoard();
				t2.UpdateBoard();
				t3.UpdateBoard();
				t3.End();
				// Player Win (row 1)
				if(t.Row1[1] == PM && t.Row1[1] == t2.Row1[1] && t2.Row1[1] == t3.Row1[1])
				{
					cout << "\n// You win!" << endl;

					t.Reset();
					t2.Reset();
					t3.Reset();
				}
				if(t.Row1[2] == PM && t.Row1[2] == t2.Row1[2] && t2.Row1[2] == t3.Row1[2])
				{
					cout << "\n// You win!" << endl;

					t.Reset();
					t2.Reset();
					t3.Reset();
				}
				if(t.Row1[3] == PM && t.Row1[3] == t2.Row1[3] && t2.Row1[3] == t3.Row1[3])
				{
					cout << "\n// You win!" << endl;

					t.Reset();
					t2.Reset();
					t3.Reset();
				}
				// Player Win (row 2)
				if(t.Row2[1] == PM && t.Row2[1] == t2.Row2[1] && t2.Row2[1] == t3.Row2[1])
				{
					cout << "\n// You win!" << endl;

					t.Reset();
					t2.Reset();
					t3.Reset();
				}
				if(t.Row2[2] == PM && t.Row2[2] == t2.Row2[2] && t2.Row2[2] == t3.Row2[2])
				{
					cout << "\n// You win!" << endl;

					t.Reset();
					t2.Reset();
					t3.Reset();
				}
				if(t.Row2[3] == PM && t.Row2[3] == t2.Row2[3] && t2.Row2[3] == t3.Row2[3])
				{
					cout << "\n// You win!" << endl;

					t.Reset();
					t2.Reset();
					t3.Reset();
				}
				// Player Win (row 3)
				if(t.Row3[1] == PM && t.Row3[1] == t2.Row3[1] && t2.Row3[1] == t3.Row3[1])
				{
					cout << "\n// You win!" << endl;

					t.Reset();
					t2.Reset();
					t3.Reset();
				}
				if(t.Row3[2] == PM && t.Row3[2] == t2.Row3[2] && t2.Row3[2] == t3.Row3[2])
				{
					cout << "\n// You win!" << endl;

					t.Reset();
					t2.Reset();
					t3.Reset();
				}
				if(t.Row3[3] == PM && t.Row3[3] == t2.Row3[3] && t2.Row3[3] == t3.Row3[3])
				{
					cout << "\n// You win!" << endl;

					t.Reset();
					t2.Reset();
					t3.Reset();
				}

			/*--------------------------------------------------------------------------------------------------------------------------------------------------*/

				// Computer Win (row 1)
				if(t.Row1[1] == PCM && t.Row1[1] == t2.Row1[1] && t2.Row1[1] == t3.Row1[1])
				{
					cout << "\n// I win!" << endl;

					t.Reset();
					t2.Reset();
					t3.Reset();
				}
				if(t.Row1[2] == PCM && t.Row1[2] == t2.Row1[2] && t2.Row1[2] == t3.Row1[2])
				{
					cout << "\n// I win!" << endl;

					t.Reset();
					t2.Reset();
					t3.Reset();
				}
				if(t.Row1[3] == PCM && t.Row1[3] == t2.Row1[3] && t2.Row1[3] == t3.Row1[3])
				{
					cout << "\n// I win!" << endl;

					t.Reset();
					t2.Reset();
					t3.Reset();
				}
				// Computer Win (row 2)
				if(t.Row2[1] == PCM && t.Row2[1] == t2.Row2[1] && t2.Row2[1] == t3.Row2[1])
				{
					cout << "\n// I win!" << endl;

					t.Reset();
					t2.Reset();
					t3.Reset();
				}
				if(t.Row2[2] == PCM && t.Row2[2] == t2.Row2[2] && t2.Row2[2] == t3.Row2[2])
				{
					cout << "\n// I win!" << endl;

					t.Reset();
					t2.Reset();
					t3.Reset();
				}
				if(t.Row2[3] == PCM && t.Row2[3] == t2.Row2[3] && t2.Row2[3] == t3.Row2[3])
				{
					cout << "\n// I win!" << endl;

					t.Reset();
					t2.Reset();
					t3.Reset();
				}
				// Computer Win (row 3)
				if(t.Row3[1] == PCM && t.Row3[1] == t2.Row3[1] && t2.Row3[1] == t3.Row3[1])
				{
					cout << "\n// I win!" << endl;

					t.Reset();
					t2.Reset();
					t3.Reset();
				}
				if(t.Row3[2] == PCM && t.Row3[2] == t2.Row3[2] && t2.Row3[2] == t3.Row3[2])
				{
					cout << "\n// I win!" << endl;

					t.Reset();
					t2.Reset();
					t3.Reset();
				}
				if(t.Row3[3] == PCM && t.Row3[3] == t2.Row3[3] && t2.Row3[3] == t3.Row3[3])
				{
					cout << "\n// I win!" << endl;

					t.Reset();
					t2.Reset();
					t3.Reset();
				}

			/*--------------------------------------------------------------------------------------------------------------------------------------------------*/

				// Continue
				else
				{
					// Draw
					if(t.Row1[1] != Default && t.Row1[2] != Default && t.Row1[3] != Default && t.Row2[1] != Default && t.Row2[2] != Default && t.Row2[3] != Default && t.Row3[1] != Default && t.Row3[2] != Default && t.Row3[3] != Default && t2.Row1[1] != Default && t2.Row1[2] != Default && t2.Row1[3] != Default && t2.Row2[1] != Default && t2.Row2[2] != Default && t2.Row2[3] != Default && t2.Row3[1] != Default && t2.Row3[2] != Default && t2.Row3[3] != Default && t3.Row1[1] != Default && t3.Row1[2] != Default && t3.Row1[3] != Default && t3.Row2[1] != Default && t3.Row2[2] != Default && t3.Row2[3] != Default && t3.Row3[1] != Default && t3.Row3[2] != Default && t3.Row3[3] != Default)
					{
						cout << "\n// Draw!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}

					else
					{
						MoveOn = true;
					}

				}
			}

			// Continue after Player Move
			if(MoveOn == true)
			{
				cout << "\nComputer moving..." << endl;

				srand(time(0));
				BoardStart = rand() % 3;

				if(BoardStart == 0)
				{
					t.PCMove();
					t.UpdateBoard();
					t2.UpdateBoard();
					t3.UpdateBoard();
					t.End();
					// Player Win (row 1)
					if(t.Row1[1] == PM && t.Row1[1] == t2.Row1[1] && t2.Row1[1] == t3.Row1[1])
					{
						cout << "\n// You win!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}
					if(t.Row1[2] == PM && t.Row1[2] == t2.Row1[2] && t2.Row1[2] == t3.Row1[2])
					{
						cout << "\n// You win!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}
					if(t.Row1[3] == PM && t.Row1[3] == t2.Row1[3] && t2.Row1[3] == t3.Row1[3])
					{
						cout << "\n// You win!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}
					// Player Win (row 2)
					if(t.Row2[1] == PM && t.Row2[1] == t2.Row2[1] && t2.Row2[1] == t3.Row2[1])
					{
						cout << "\n// You win!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}
					if(t.Row2[2] == PM && t.Row2[2] == t2.Row2[2] && t2.Row2[2] == t3.Row2[2])
					{
						cout << "\n// You win!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}
					if(t.Row2[3] == PM && t.Row2[3] == t2.Row2[3] && t2.Row2[3] == t3.Row2[3])
					{
						cout << "\n// You win!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}
					// Player Win (row 3)
					if(t.Row3[1] == PM && t.Row3[1] == t2.Row3[1] && t2.Row3[1] == t3.Row3[1])
					{
						cout << "\n// You win!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}
					if(t.Row3[2] == PM && t.Row3[2] == t2.Row3[2] && t2.Row3[2] == t3.Row3[2])
					{
						cout << "\n// You win!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}
					if(t.Row3[3] == PM && t.Row3[3] == t2.Row3[3] && t2.Row3[3] == t3.Row3[3])
					{
						cout << "\n// You win!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}

				/*--------------------------------------------------------------------------------------------------------------------------------------------------*/

					// Computer Win (row 1)
					if(t.Row1[1] == PCM && t.Row1[1] == t2.Row1[1] && t2.Row1[1] == t3.Row1[1])
					{
						cout << "\n// I win!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}
					if(t.Row1[2] == PCM && t.Row1[2] == t2.Row1[2] && t2.Row1[2] == t3.Row1[2])
					{
						cout << "\n// I win!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}
					if(t.Row1[3] == PCM && t.Row1[3] == t2.Row1[3] && t2.Row1[3] == t3.Row1[3])
					{
						cout << "\n// I win!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}
					// Computer Win (row 2)
					if(t.Row2[1] == PCM && t.Row2[1] == t2.Row2[1] && t2.Row2[1] == t3.Row2[1])
					{
						cout << "\n// I win!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}
					if(t.Row2[2] == PCM && t.Row2[2] == t2.Row2[2] && t2.Row2[2] == t3.Row2[2])
					{
						cout << "\n// I win!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}
					if(t.Row2[3] == PCM && t.Row2[3] == t2.Row2[3] && t2.Row2[3] == t3.Row2[3])
					{
						cout << "\n// I win!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}
					// Computer Win (row 3)
					if(t.Row3[1] == PCM && t.Row3[1] == t2.Row3[1] && t2.Row3[1] == t3.Row3[1])
					{
						cout << "\n// I win!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}
					if(t.Row3[2] == PCM && t.Row3[2] == t2.Row3[2] && t2.Row3[2] == t3.Row3[2])
					{
						cout << "\n// I win!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}
					if(t.Row3[3] == PCM && t.Row3[3] == t2.Row3[3] && t2.Row3[3] == t3.Row3[3])
					{
						cout << "\n// I win!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}

				/*--------------------------------------------------------------------------------------------------------------------------------------------------*/

					// Continue
					else
					{
						// Draw
						if(t.Row1[1] != Default && t.Row1[2] != Default && t.Row1[3] != Default && t.Row2[1] != Default && t.Row2[2] != Default && t.Row2[3] != Default && t.Row3[1] != Default && t.Row3[2] != Default && t.Row3[3] != Default && t2.Row1[1] != Default && t2.Row1[2] != Default && t2.Row1[3] != Default && t2.Row2[1] != Default && t2.Row2[2] != Default && t2.Row2[3] != Default && t2.Row3[1] != Default && t2.Row3[2] != Default && t2.Row3[3] != Default && t3.Row1[1] != Default && t3.Row1[2] != Default && t3.Row1[3] != Default && t3.Row2[1] != Default && t3.Row2[2] != Default && t3.Row2[3] != Default && t3.Row3[1] != Default && t3.Row3[2] != Default && t3.Row3[3] != Default)
						{
							cout << "\n// Draw!" << endl;

							t.Reset();
							t2.Reset();
							t3.Reset();
						}

						else
						{
							MoveOn = true;
						}

					}
				}

				if(BoardStart == 1)
				{
					t2.PCMove();
					t.UpdateBoard();
					t2.UpdateBoard();
					t3.UpdateBoard();
					t2.End();
					// Player Win (row 1)
					if(t.Row1[1] == PM && t.Row1[1] == t2.Row1[1] && t2.Row1[1] == t3.Row1[1])
					{
						cout << "\n// You win!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}
					if(t.Row1[2] == PM && t.Row1[2] == t2.Row1[2] && t2.Row1[2] == t3.Row1[2])
					{
						cout << "\n// You win!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}
					if(t.Row1[3] == PM && t.Row1[3] == t2.Row1[3] && t2.Row1[3] == t3.Row1[3])
					{
						cout << "\n// You win!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}
					// Player Win (row 2)
					if(t.Row2[1] == PM && t.Row2[1] == t2.Row2[1] && t2.Row2[1] == t3.Row2[1])
					{
						cout << "\n// You win!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}
					if(t.Row2[2] == PM && t.Row2[2] == t2.Row2[2] && t2.Row2[2] == t3.Row2[2])
					{
						cout << "\n// You win!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}
					if(t.Row2[3] == PM && t.Row2[3] == t2.Row2[3] && t2.Row2[3] == t3.Row2[3])
					{
						cout << "\n// You win!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}
					// Player Win (row 3)
					if(t.Row3[1] == PM && t.Row3[1] == t2.Row3[1] && t2.Row3[1] == t3.Row3[1])
					{
						cout << "\n// You win!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}
					if(t.Row3[2] == PM && t.Row3[2] == t2.Row3[2] && t2.Row3[2] == t3.Row3[2])
					{
						cout << "\n// You win!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}
					if(t.Row3[3] == PM && t.Row3[3] == t2.Row3[3] && t2.Row3[3] == t3.Row3[3])
					{
						cout << "\n// You win!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}

				/*--------------------------------------------------------------------------------------------------------------------------------------------------*/

					// Computer Win (row 1)
					if(t.Row1[1] == PCM && t.Row1[1] == t2.Row1[1] && t2.Row1[1] == t3.Row1[1])
					{
						cout << "\n// I win!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}
					if(t.Row1[2] == PCM && t.Row1[2] == t2.Row1[2] && t2.Row1[2] == t3.Row1[2])
					{
						cout << "\n// I win!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}
					if(t.Row1[3] == PCM && t.Row1[3] == t2.Row1[3] && t2.Row1[3] == t3.Row1[3])
					{
						cout << "\n// I win!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}
					// Computer Win (row 2)
					if(t.Row2[1] == PCM && t.Row2[1] == t2.Row2[1] && t2.Row2[1] == t3.Row2[1])
					{
						cout << "\n// I win!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}
					if(t.Row2[2] == PCM && t.Row2[2] == t2.Row2[2] && t2.Row2[2] == t3.Row2[2])
					{
						cout << "\n// I win!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}
					if(t.Row2[3] == PCM && t.Row2[3] == t2.Row2[3] && t2.Row2[3] == t3.Row2[3])
					{
						cout << "\n// I win!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}
					// Computer Win (row 3)
					if(t.Row3[1] == PCM && t.Row3[1] == t2.Row3[1] && t2.Row3[1] == t3.Row3[1])
					{
						cout << "\n// I win!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}
					if(t.Row3[2] == PCM && t.Row3[2] == t2.Row3[2] && t2.Row3[2] == t3.Row3[2])
					{
						cout << "\n// I win!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}
					if(t.Row3[3] == PCM && t.Row3[3] == t2.Row3[3] && t2.Row3[3] == t3.Row3[3])
					{
						cout << "\n// I win!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}

				/*--------------------------------------------------------------------------------------------------------------------------------------------------*/

					// Continue
					else
					{
						// Draw
						if(t.Row1[1] != Default && t.Row1[2] != Default && t.Row1[3] != Default && t.Row2[1] != Default && t.Row2[2] != Default && t.Row2[3] != Default && t.Row3[1] != Default && t.Row3[2] != Default && t.Row3[3] != Default && t2.Row1[1] != Default && t2.Row1[2] != Default && t2.Row1[3] != Default && t2.Row2[1] != Default && t2.Row2[2] != Default && t2.Row2[3] != Default && t2.Row3[1] != Default && t2.Row3[2] != Default && t2.Row3[3] != Default && t3.Row1[1] != Default && t3.Row1[2] != Default && t3.Row1[3] != Default && t3.Row2[1] != Default && t3.Row2[2] != Default && t3.Row2[3] != Default && t3.Row3[1] != Default && t3.Row3[2] != Default && t3.Row3[3] != Default)
						{
							cout << "\n// Draw!" << endl;

							t.Reset();
							t2.Reset();
							t3.Reset();
						}

						else
						{
							MoveOn = true;
						}

					}
				}

				if(BoardStart == 2)
				{
					t3.PCMove();
					t.UpdateBoard();
					t2.UpdateBoard();
					t3.UpdateBoard();
					t3.End();
					// Player Win (row 1)
					if(t.Row1[1] == PM && t.Row1[1] == t2.Row1[1] && t2.Row1[1] == t3.Row1[1])
					{
						cout << "\n// You win!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}
					if(t.Row1[2] == PM && t.Row1[2] == t2.Row1[2] && t2.Row1[2] == t3.Row1[2])
					{
						cout << "\n// You win!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}
					if(t.Row1[3] == PM && t.Row1[3] == t2.Row1[3] && t2.Row1[3] == t3.Row1[3])
					{
						cout << "\n// You win!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}
					// Player Win (row 2)
					if(t.Row2[1] == PM && t.Row2[1] == t2.Row2[1] && t2.Row2[1] == t3.Row2[1])
					{
						cout << "\n// You win!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}
					if(t.Row2[2] == PM && t.Row2[2] == t2.Row2[2] && t2.Row2[2] == t3.Row2[2])
					{
						cout << "\n// You win!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}
					if(t.Row2[3] == PM && t.Row2[3] == t2.Row2[3] && t2.Row2[3] == t3.Row2[3])
					{
						cout << "\n// You win!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}
					// Player Win (row 3)
					if(t.Row3[1] == PM && t.Row3[1] == t2.Row3[1] && t2.Row3[1] == t3.Row3[1])
					{
						cout << "\n// You win!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}
					if(t.Row3[2] == PM && t.Row3[2] == t2.Row3[2] && t2.Row3[2] == t3.Row3[2])
					{
						cout << "\n// You win!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}
					if(t.Row3[3] == PM && t.Row3[3] == t2.Row3[3] && t2.Row3[3] == t3.Row3[3])
					{
						cout << "\n// You win!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}

				/*--------------------------------------------------------------------------------------------------------------------------------------------------*/

					// Computer Win (row 1)
					if(t.Row1[1] == PCM && t.Row1[1] == t2.Row1[1] && t2.Row1[1] == t3.Row1[1])
					{
						cout << "\n// I win!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}
					if(t.Row1[2] == PCM && t.Row1[2] == t2.Row1[2] && t2.Row1[2] == t3.Row1[2])
					{
						cout << "\n// I win!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}
					if(t.Row1[3] == PCM && t.Row1[3] == t2.Row1[3] && t2.Row1[3] == t3.Row1[3])
					{
						cout << "\n// I win!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}
					// Computer Win (row 2)
					if(t.Row2[1] == PCM && t.Row2[1] == t2.Row2[1] && t2.Row2[1] == t3.Row2[1])
					{
						cout << "\n// I win!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}
					if(t.Row2[2] == PCM && t.Row2[2] == t2.Row2[2] && t2.Row2[2] == t3.Row2[2])
					{
						cout << "\n// I win!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}
					if(t.Row2[3] == PCM && t.Row2[3] == t2.Row2[3] && t2.Row2[3] == t3.Row2[3])
					{
						cout << "\n// I win!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}
					// Computer Win (row 3)
					if(t.Row3[1] == PCM && t.Row3[1] == t2.Row3[1] && t2.Row3[1] == t3.Row3[1])
					{
						cout << "\n// I win!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}
					if(t.Row3[2] == PCM && t.Row3[2] == t2.Row3[2] && t2.Row3[2] == t3.Row3[2])
					{
						cout << "\n// I win!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}
					if(t.Row3[3] == PCM && t.Row3[3] == t2.Row3[3] && t2.Row3[3] == t3.Row3[3])
					{
						cout << "\n// I win!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}

				/*--------------------------------------------------------------------------------------------------------------------------------------------------*/

					// Continue
					else
					{
						// Draw
						if(t.Row1[1] != Default && t.Row1[2] != Default && t.Row1[3] != Default && t.Row2[1] != Default && t.Row2[2] != Default && t.Row2[3] != Default && t.Row3[1] != Default && t.Row3[2] != Default && t.Row3[3] != Default && t2.Row1[1] != Default && t2.Row1[2] != Default && t2.Row1[3] != Default && t2.Row2[1] != Default && t2.Row2[2] != Default && t2.Row2[3] != Default && t2.Row3[1] != Default && t2.Row3[2] != Default && t2.Row3[3] != Default && t3.Row1[1] != Default && t3.Row1[2] != Default && t3.Row1[3] != Default && t3.Row2[1] != Default && t3.Row2[2] != Default && t3.Row2[3] != Default && t3.Row3[1] != Default && t3.Row3[2] != Default && t3.Row3[3] != Default)
						{
							cout << "\n// Draw!" << endl;

							t.Reset();
							t2.Reset();
							t3.Reset();
						}

						else
						{
							MoveOn = true;
						}

					}
				}

			}

		}
	}

	// If Computer starts
	if(UserStart == 0)
	{
		while(1)
		{
			cout << "\nComputer moving..." << endl;

			srand(time(0));
			BoardStart = rand() % 3;

			if(BoardStart == 0)
			{
				t.PCMove();
				t.UpdateBoard();
				t2.UpdateBoard();
				t3.UpdateBoard();
				t.End();
				// Player Win (row 1)
				if(t.Row1[1] == PM && t.Row1[1] == t2.Row1[1] && t2.Row1[1] == t3.Row1[1])
				{
					cout << "\n// You win!" << endl;

					t.Reset();
					t2.Reset();
					t3.Reset();
				}
				if(t.Row1[2] == PM && t.Row1[2] == t2.Row1[2] && t2.Row1[2] == t3.Row1[2])
				{
					cout << "\n// You win!" << endl;

					t.Reset();
					t2.Reset();
					t3.Reset();
				}
				if(t.Row1[3] == PM && t.Row1[3] == t2.Row1[3] && t2.Row1[3] == t3.Row1[3])
				{
					cout << "\n// You win!" << endl;

					t.Reset();
					t2.Reset();
					t3.Reset();
				}
				// Player Win (row 2)
				if(t.Row2[1] == PM && t.Row2[1] == t2.Row2[1] && t2.Row2[1] == t3.Row2[1])
				{
					cout << "\n// You win!" << endl;

					t.Reset();
					t2.Reset();
					t3.Reset();
				}
				if(t.Row2[2] == PM && t.Row2[2] == t2.Row2[2] && t2.Row2[2] == t3.Row2[2])
				{
					cout << "\n// You win!" << endl;

					t.Reset();
					t2.Reset();
					t3.Reset();
				}
				if(t.Row2[3] == PM && t.Row2[3] == t2.Row2[3] && t2.Row2[3] == t3.Row2[3])
				{
					cout << "\n// You win!" << endl;

					t.Reset();
					t2.Reset();
					t3.Reset();
				}
				// Player Win (row 3)
				if(t.Row3[1] == PM && t.Row3[1] == t2.Row3[1] && t2.Row3[1] == t3.Row3[1])
				{
					cout << "\n// You win!" << endl;

					t.Reset();
					t2.Reset();
					t3.Reset();
				}
				if(t.Row3[2] == PM && t.Row3[2] == t2.Row3[2] && t2.Row3[2] == t3.Row3[2])
				{
					cout << "\n// You win!" << endl;

					t.Reset();
					t2.Reset();
					t3.Reset();
				}
				if(t.Row3[3] == PM && t.Row3[3] == t2.Row3[3] && t2.Row3[3] == t3.Row3[3])
				{
					cout << "\n// You win!" << endl;

					t.Reset();
					t2.Reset();
					t3.Reset();
				}

			/*--------------------------------------------------------------------------------------------------------------------------------------------------*/

				// Computer Win (row 1)
				if(t.Row1[1] == PCM && t.Row1[1] == t2.Row1[1] && t2.Row1[1] == t3.Row1[1])
				{
					cout << "\n// I win!" << endl;

					t.Reset();
					t2.Reset();
					t3.Reset();
				}
				if(t.Row1[2] == PCM && t.Row1[2] == t2.Row1[2] && t2.Row1[2] == t3.Row1[2])
				{
					cout << "\n// I win!" << endl;

					t.Reset();
					t2.Reset();
					t3.Reset();
				}
				if(t.Row1[3] == PCM && t.Row1[3] == t2.Row1[3] && t2.Row1[3] == t3.Row1[3])
				{
					cout << "\n// I win!" << endl;

					t.Reset();
					t2.Reset();
					t3.Reset();
				}
				// Computer Win (row 2)
				if(t.Row2[1] == PCM && t.Row2[1] == t2.Row2[1] && t2.Row2[1] == t3.Row2[1])
				{
					cout << "\n// I win!" << endl;

					t.Reset();
					t2.Reset();
					t3.Reset();
				}
				if(t.Row2[2] == PCM && t.Row2[2] == t2.Row2[2] && t2.Row2[2] == t3.Row2[2])
				{
					cout << "\n// I win!" << endl;

					t.Reset();
					t2.Reset();
					t3.Reset();
				}
				if(t.Row2[3] == PCM && t.Row2[3] == t2.Row2[3] && t2.Row2[3] == t3.Row2[3])
				{
					cout << "\n// I win!" << endl;

					t.Reset();
					t2.Reset();
					t3.Reset();
				}
				// Computer Win (row 3)
				if(t.Row3[1] == PCM && t.Row3[1] == t2.Row3[1] && t2.Row3[1] == t3.Row3[1])
				{
					cout << "\n// I win!" << endl;

					t.Reset();
					t2.Reset();
					t3.Reset();
				}
				if(t.Row3[2] == PCM && t.Row3[2] == t2.Row3[2] && t2.Row3[2] == t3.Row3[2])
				{
					cout << "\n// I win!" << endl;

					t.Reset();
					t2.Reset();
					t3.Reset();
				}
				if(t.Row3[3] == PCM && t.Row3[3] == t2.Row3[3] && t2.Row3[3] == t3.Row3[3])
				{
					cout << "\n// I win!" << endl;

					t.Reset();
					t2.Reset();
					t3.Reset();
				}

			/*--------------------------------------------------------------------------------------------------------------------------------------------------*/

				// Continue
				else
				{
					// Draw
					if(t.Row1[1] != Default && t.Row1[2] != Default && t.Row1[3] != Default && t.Row2[1] != Default && t.Row2[2] != Default && t.Row2[3] != Default && t.Row3[1] != Default && t.Row3[2] != Default && t.Row3[3] != Default && t2.Row1[1] != Default && t2.Row1[2] != Default && t2.Row1[3] != Default && t2.Row2[1] != Default && t2.Row2[2] != Default && t2.Row2[3] != Default && t2.Row3[1] != Default && t2.Row3[2] != Default && t2.Row3[3] != Default && t3.Row1[1] != Default && t3.Row1[2] != Default && t3.Row1[3] != Default && t3.Row2[1] != Default && t3.Row2[2] != Default && t3.Row2[3] != Default && t3.Row3[1] != Default && t3.Row3[2] != Default && t3.Row3[3] != Default)
					{
						cout << "\n// Draw!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}

					else
					{
						MoveOn = true;
					}

				}
			}

			if(BoardStart == 1)
			{
				t2.PCMove();
				t.UpdateBoard();
				t2.UpdateBoard();
				t3.UpdateBoard();
				t2.End();
				// Player Win (row 1)
				if(t.Row1[1] == PM && t.Row1[1] == t2.Row1[1] && t2.Row1[1] == t3.Row1[1])
				{
					cout << "\n// You win!" << endl;

					t.Reset();
					t2.Reset();
					t3.Reset();
				}
				if(t.Row1[2] == PM && t.Row1[2] == t2.Row1[2] && t2.Row1[2] == t3.Row1[2])
				{
					cout << "\n// You win!" << endl;

					t.Reset();
					t2.Reset();
					t3.Reset();
				}
				if(t.Row1[3] == PM && t.Row1[3] == t2.Row1[3] && t2.Row1[3] == t3.Row1[3])
				{
					cout << "\n// You win!" << endl;

					t.Reset();
					t2.Reset();
					t3.Reset();
				}
				// Player Win (row 2)
				if(t.Row2[1] == PM && t.Row2[1] == t2.Row2[1] && t2.Row2[1] == t3.Row2[1])
				{
					cout << "\n// You win!" << endl;

					t.Reset();
					t2.Reset();
					t3.Reset();
				}
				if(t.Row2[2] == PM && t.Row2[2] == t2.Row2[2] && t2.Row2[2] == t3.Row2[2])
				{
					cout << "\n// You win!" << endl;

					t.Reset();
					t2.Reset();
					t3.Reset();
				}
				if(t.Row2[3] == PM && t.Row2[3] == t2.Row2[3] && t2.Row2[3] == t3.Row2[3])
				{
					cout << "\n// You win!" << endl;

					t.Reset();
					t2.Reset();
					t3.Reset();
				}
				// Player Win (row 3)
				if(t.Row3[1] == PM && t.Row3[1] == t2.Row3[1] && t2.Row3[1] == t3.Row3[1])
				{
					cout << "\n// You win!" << endl;

					t.Reset();
					t2.Reset();
					t3.Reset();
				}
				if(t.Row3[2] == PM && t.Row3[2] == t2.Row3[2] && t2.Row3[2] == t3.Row3[2])
				{
					cout << "\n// You win!" << endl;

					t.Reset();
					t2.Reset();
					t3.Reset();
				}
				if(t.Row3[3] == PM && t.Row3[3] == t2.Row3[3] && t2.Row3[3] == t3.Row3[3])
				{
					cout << "\n// You win!" << endl;

					t.Reset();
					t2.Reset();
					t3.Reset();
				}

			/*--------------------------------------------------------------------------------------------------------------------------------------------------*/

				// Computer Win (row 1)
				if(t.Row1[1] == PCM && t.Row1[1] == t2.Row1[1] && t2.Row1[1] == t3.Row1[1])
				{
					cout << "\n// I win!" << endl;

					t.Reset();
					t2.Reset();
					t3.Reset();
				}
				if(t.Row1[2] == PCM && t.Row1[2] == t2.Row1[2] && t2.Row1[2] == t3.Row1[2])
				{
					cout << "\n// I win!" << endl;

					t.Reset();
					t2.Reset();
					t3.Reset();
				}
				if(t.Row1[3] == PCM && t.Row1[3] == t2.Row1[3] && t2.Row1[3] == t3.Row1[3])
				{
					cout << "\n// I win!" << endl;

					t.Reset();
					t2.Reset();
					t3.Reset();
				}
				// Computer Win (row 2)
				if(t.Row2[1] == PCM && t.Row2[1] == t2.Row2[1] && t2.Row2[1] == t3.Row2[1])
				{
					cout << "\n// I win!" << endl;

					t.Reset();
					t2.Reset();
					t3.Reset();
				}
				if(t.Row2[2] == PCM && t.Row2[2] == t2.Row2[2] && t2.Row2[2] == t3.Row2[2])
				{
					cout << "\n// I win!" << endl;

					t.Reset();
					t2.Reset();
					t3.Reset();
				}
				if(t.Row2[3] == PCM && t.Row2[3] == t2.Row2[3] && t2.Row2[3] == t3.Row2[3])
				{
					cout << "\n// I win!" << endl;

					t.Reset();
					t2.Reset();
					t3.Reset();
				}
				// Computer Win (row 3)
				if(t.Row3[1] == PCM && t.Row3[1] == t2.Row3[1] && t2.Row3[1] == t3.Row3[1])
				{
					cout << "\n// I win!" << endl;

					t.Reset();
					t2.Reset();
					t3.Reset();
				}
				if(t.Row3[2] == PCM && t.Row3[2] == t2.Row3[2] && t2.Row3[2] == t3.Row3[2])
				{
					cout << "\n// I win!" << endl;

					t.Reset();
					t2.Reset();
					t3.Reset();
				}
				if(t.Row3[3] == PCM && t.Row3[3] == t2.Row3[3] && t2.Row3[3] == t3.Row3[3])
				{
					cout << "\n// I win!" << endl;

					t.Reset();
					t2.Reset();
					t3.Reset();
				}

			/*--------------------------------------------------------------------------------------------------------------------------------------------------*/

				// Continue
				else
				{
					// Draw
					if(t.Row1[1] != Default && t.Row1[2] != Default && t.Row1[3] != Default && t.Row2[1] != Default && t.Row2[2] != Default && t.Row2[3] != Default && t.Row3[1] != Default && t.Row3[2] != Default && t.Row3[3] != Default && t2.Row1[1] != Default && t2.Row1[2] != Default && t2.Row1[3] != Default && t2.Row2[1] != Default && t2.Row2[2] != Default && t2.Row2[3] != Default && t2.Row3[1] != Default && t2.Row3[2] != Default && t2.Row3[3] != Default && t3.Row1[1] != Default && t3.Row1[2] != Default && t3.Row1[3] != Default && t3.Row2[1] != Default && t3.Row2[2] != Default && t3.Row2[3] != Default && t3.Row3[1] != Default && t3.Row3[2] != Default && t3.Row3[3] != Default)
					{
						cout << "\n// Draw!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}

					else
					{
						MoveOn = true;
					}

				}
			}

			if(BoardStart == 2)
			{
				t3.PCMove();
				t.UpdateBoard();
				t2.UpdateBoard();
				t3.UpdateBoard();
				t3.End();
				// Player Win (row 1)
				if(t.Row1[1] == PM && t.Row1[1] == t2.Row1[1] && t2.Row1[1] == t3.Row1[1])
				{
					cout << "\n// You win!" << endl;

					t.Reset();
					t2.Reset();
					t3.Reset();
				}
				if(t.Row1[2] == PM && t.Row1[2] == t2.Row1[2] && t2.Row1[2] == t3.Row1[2])
				{
					cout << "\n// You win!" << endl;

					t.Reset();
					t2.Reset();
					t3.Reset();
				}
				if(t.Row1[3] == PM && t.Row1[3] == t2.Row1[3] && t2.Row1[3] == t3.Row1[3])
				{
					cout << "\n// You win!" << endl;

					t.Reset();
					t2.Reset();
					t3.Reset();
				}
				// Player Win (row 2)
				if(t.Row2[1] == PM && t.Row2[1] == t2.Row2[1] && t2.Row2[1] == t3.Row2[1])
				{
					cout << "\n// You win!" << endl;

					t.Reset();
					t2.Reset();
					t3.Reset();
				}
				if(t.Row2[2] == PM && t.Row2[2] == t2.Row2[2] && t2.Row2[2] == t3.Row2[2])
				{
					cout << "\n// You win!" << endl;

					t.Reset();
					t2.Reset();
					t3.Reset();
				}
				if(t.Row2[3] == PM && t.Row2[3] == t2.Row2[3] && t2.Row2[3] == t3.Row2[3])
				{
					cout << "\n// You win!" << endl;

					t.Reset();
					t2.Reset();
					t3.Reset();
				}
				// Player Win (row 3)
				if(t.Row3[1] == PM && t.Row3[1] == t2.Row3[1] && t2.Row3[1] == t3.Row3[1])
				{
					cout << "\n// You win!" << endl;

					t.Reset();
					t2.Reset();
					t3.Reset();
				}
				if(t.Row3[2] == PM && t.Row3[2] == t2.Row3[2] && t2.Row3[2] == t3.Row3[2])
				{
					cout << "\n// You win!" << endl;

					t.Reset();
					t2.Reset();
					t3.Reset();
				}
				if(t.Row3[3] == PM && t.Row3[3] == t2.Row3[3] && t2.Row3[3] == t3.Row3[3])
				{
					cout << "\n// You win!" << endl;

					t.Reset();
					t2.Reset();
					t3.Reset();
				}

			/*--------------------------------------------------------------------------------------------------------------------------------------------------*/

				// Computer Win (row 1)
				if(t.Row1[1] == PCM && t.Row1[1] == t2.Row1[1] && t2.Row1[1] == t3.Row1[1])
				{
					cout << "\n// I win!" << endl;

					t.Reset();
					t2.Reset();
					t3.Reset();
				}
				if(t.Row1[2] == PCM && t.Row1[2] == t2.Row1[2] && t2.Row1[2] == t3.Row1[2])
				{
					cout << "\n// I win!" << endl;

					t.Reset();
					t2.Reset();
					t3.Reset();
				}
				if(t.Row1[3] == PCM && t.Row1[3] == t2.Row1[3] && t2.Row1[3] == t3.Row1[3])
				{
					cout << "\n// I win!" << endl;

					t.Reset();
					t2.Reset();
					t3.Reset();
				}
				// Computer Win (row 2)
				if(t.Row2[1] == PCM && t.Row2[1] == t2.Row2[1] && t2.Row2[1] == t3.Row2[1])
				{
					cout << "\n// I win!" << endl;

					t.Reset();
					t2.Reset();
					t3.Reset();
				}
				if(t.Row2[2] == PCM && t.Row2[2] == t2.Row2[2] && t2.Row2[2] == t3.Row2[2])
				{
					cout << "\n// I win!" << endl;

					t.Reset();
					t2.Reset();
					t3.Reset();
				}
				if(t.Row2[3] == PCM && t.Row2[3] == t2.Row2[3] && t2.Row2[3] == t3.Row2[3])
				{
					cout << "\n// I win!" << endl;

					t.Reset();
					t2.Reset();
					t3.Reset();
				}
				// Computer Win (row 3)
				if(t.Row3[1] == PCM && t.Row3[1] == t2.Row3[1] && t2.Row3[1] == t3.Row3[1])
				{
					cout << "\n// I win!" << endl;

					t.Reset();
					t2.Reset();
					t3.Reset();
				}
				if(t.Row3[2] == PCM && t.Row3[2] == t2.Row3[2] && t2.Row3[2] == t3.Row3[2])
				{
					cout << "\n// I win!" << endl;

					t.Reset();
					t2.Reset();
					t3.Reset();
				}
				if(t.Row3[3] == PCM && t.Row3[3] == t2.Row3[3] && t2.Row3[3] == t3.Row3[3])
				{
					cout << "\n// I win!" << endl;

					t.Reset();
					t2.Reset();
					t3.Reset();
				}

			/*--------------------------------------------------------------------------------------------------------------------------------------------------*/

				// Continue
				else
				{
					// Draw
					if(t.Row1[1] != Default && t.Row1[2] != Default && t.Row1[3] != Default && t.Row2[1] != Default && t.Row2[2] != Default && t.Row2[3] != Default && t.Row3[1] != Default && t.Row3[2] != Default && t.Row3[3] != Default && t2.Row1[1] != Default && t2.Row1[2] != Default && t2.Row1[3] != Default && t2.Row2[1] != Default && t2.Row2[2] != Default && t2.Row2[3] != Default && t2.Row3[1] != Default && t2.Row3[2] != Default && t2.Row3[3] != Default && t3.Row1[1] != Default && t3.Row1[2] != Default && t3.Row1[3] != Default && t3.Row2[1] != Default && t3.Row2[2] != Default && t3.Row2[3] != Default && t3.Row3[1] != Default && t3.Row3[2] != Default && t3.Row3[3] != Default)
					{
						cout << "\n// Draw!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}

					else
					{
						MoveOn = true;
					}

				}
			}

			if(MoveOn == true)
			{
				cout << "\nYour move" << endl;

				// Board Selection
				cout << "Select a board [1, 2, 3]" << endl;
				cin >> BoardChoice;

				if(BoardChoice == "1")
				{
					t.PlayerMove();
					t.UpdateBoard();
					t2.UpdateBoard();
					t3.UpdateBoard();
					t.End();
					// Player Win (row 1)
					if(t.Row1[1] == PM && t.Row1[1] == t2.Row1[1] && t2.Row1[1] == t3.Row1[1])
					{
						cout << "\n// You win!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}
					if(t.Row1[2] == PM && t.Row1[2] == t2.Row1[2] && t2.Row1[2] == t3.Row1[2])
					{
						cout << "\n// You win!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}
					if(t.Row1[3] == PM && t.Row1[3] == t2.Row1[3] && t2.Row1[3] == t3.Row1[3])
					{
						cout << "\n// You win!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}
					// Player Win (row 2)
					if(t.Row2[1] == PM && t.Row2[1] == t2.Row2[1] && t2.Row2[1] == t3.Row2[1])
					{
						cout << "\n// You win!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}
					if(t.Row2[2] == PM && t.Row2[2] == t2.Row2[2] && t2.Row2[2] == t3.Row2[2])
					{
						cout << "\n// You win!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}
					if(t.Row2[3] == PM && t.Row2[3] == t2.Row2[3] && t2.Row2[3] == t3.Row2[3])
					{
						cout << "\n// You win!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}
					// Player Win (row 3)
					if(t.Row3[1] == PM && t.Row3[1] == t2.Row3[1] && t2.Row3[1] == t3.Row3[1])
					{
						cout << "\n// You win!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}
					if(t.Row3[2] == PM && t.Row3[2] == t2.Row3[2] && t2.Row3[2] == t3.Row3[2])
					{
						cout << "\n// You win!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}
					if(t.Row3[3] == PM && t.Row3[3] == t2.Row3[3] && t2.Row3[3] == t3.Row3[3])
					{
						cout << "\n// You win!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}

				/*--------------------------------------------------------------------------------------------------------------------------------------------------*/

					// Computer Win (row 1)
					if(t.Row1[1] == PCM && t.Row1[1] == t2.Row1[1] && t2.Row1[1] == t3.Row1[1])
					{
						cout << "\n// I win!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}
					if(t.Row1[2] == PCM && t.Row1[2] == t2.Row1[2] && t2.Row1[2] == t3.Row1[2])
					{
						cout << "\n// I win!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}
					if(t.Row1[3] == PCM && t.Row1[3] == t2.Row1[3] && t2.Row1[3] == t3.Row1[3])
					{
						cout << "\n// I win!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}
					// Computer Win (row 2)
					if(t.Row2[1] == PCM && t.Row2[1] == t2.Row2[1] && t2.Row2[1] == t3.Row2[1])
					{
						cout << "\n// I win!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}
					if(t.Row2[2] == PCM && t.Row2[2] == t2.Row2[2] && t2.Row2[2] == t3.Row2[2])
					{
						cout << "\n// I win!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}
					if(t.Row2[3] == PCM && t.Row2[3] == t2.Row2[3] && t2.Row2[3] == t3.Row2[3])
					{
						cout << "\n// I win!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}
					// Computer Win (row 3)
					if(t.Row3[1] == PCM && t.Row3[1] == t2.Row3[1] && t2.Row3[1] == t3.Row3[1])
					{
						cout << "\n// I win!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}
					if(t.Row3[2] == PCM && t.Row3[2] == t2.Row3[2] && t2.Row3[2] == t3.Row3[2])
					{
						cout << "\n// I win!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}
					if(t.Row3[3] == PCM && t.Row3[3] == t2.Row3[3] && t2.Row3[3] == t3.Row3[3])
					{
						cout << "\n// I win!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}

				/*--------------------------------------------------------------------------------------------------------------------------------------------------*/

					// Continue
					else
					{
						// Draw
						if(t.Row1[1] != Default && t.Row1[2] != Default && t.Row1[3] != Default && t.Row2[1] != Default && t.Row2[2] != Default && t.Row2[3] != Default && t.Row3[1] != Default && t.Row3[2] != Default && t.Row3[3] != Default && t2.Row1[1] != Default && t2.Row1[2] != Default && t2.Row1[3] != Default && t2.Row2[1] != Default && t2.Row2[2] != Default && t2.Row2[3] != Default && t2.Row3[1] != Default && t2.Row3[2] != Default && t2.Row3[3] != Default && t3.Row1[1] != Default && t3.Row1[2] != Default && t3.Row1[3] != Default && t3.Row2[1] != Default && t3.Row2[2] != Default && t3.Row2[3] != Default && t3.Row3[1] != Default && t3.Row3[2] != Default && t3.Row3[3] != Default)
						{
							cout << "\n// Draw!" << endl;

							t.Reset();
							t2.Reset();
							t3.Reset();
						}

						else
						{
							MoveOn = true;
						}

					}
				}

				if(BoardChoice == "2")
				{
					t2.PlayerMove();
					t.UpdateBoard();
					t2.UpdateBoard();
					t3.UpdateBoard();
					t2.End();
					// Player Win (row 1)
					if(t.Row1[1] == PM && t.Row1[1] == t2.Row1[1] && t2.Row1[1] == t3.Row1[1])
					{
						cout << "\n// You win!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}
					if(t.Row1[2] == PM && t.Row1[2] == t2.Row1[2] && t2.Row1[2] == t3.Row1[2])
					{
						cout << "\n// You win!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}
					if(t.Row1[3] == PM && t.Row1[3] == t2.Row1[3] && t2.Row1[3] == t3.Row1[3])
					{
						cout << "\n// You win!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}
					// Player Win (row 2)
					if(t.Row2[1] == PM && t.Row2[1] == t2.Row2[1] && t2.Row2[1] == t3.Row2[1])
					{
						cout << "\n// You win!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}
					if(t.Row2[2] == PM && t.Row2[2] == t2.Row2[2] && t2.Row2[2] == t3.Row2[2])
					{
						cout << "\n// You win!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}
					if(t.Row2[3] == PM && t.Row2[3] == t2.Row2[3] && t2.Row2[3] == t3.Row2[3])
					{
						cout << "\n// You win!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}
					// Player Win (row 3)
					if(t.Row3[1] == PM && t.Row3[1] == t2.Row3[1] && t2.Row3[1] == t3.Row3[1])
					{
						cout << "\n// You win!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}
					if(t.Row3[2] == PM && t.Row3[2] == t2.Row3[2] && t2.Row3[2] == t3.Row3[2])
					{
						cout << "\n// You win!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}
					if(t.Row3[3] == PM && t.Row3[3] == t2.Row3[3] && t2.Row3[3] == t3.Row3[3])
					{
						cout << "\n// You win!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}

				/*--------------------------------------------------------------------------------------------------------------------------------------------------*/

					// Computer Win (row 1)
					if(t.Row1[1] == PCM && t.Row1[1] == t2.Row1[1] && t2.Row1[1] == t3.Row1[1])
					{
						cout << "\n// I win!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}
					if(t.Row1[2] == PCM && t.Row1[2] == t2.Row1[2] && t2.Row1[2] == t3.Row1[2])
					{
						cout << "\n// I win!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}
					if(t.Row1[3] == PCM && t.Row1[3] == t2.Row1[3] && t2.Row1[3] == t3.Row1[3])
					{
						cout << "\n// I win!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}
					// Computer Win (row 2)
					if(t.Row2[1] == PCM && t.Row2[1] == t2.Row2[1] && t2.Row2[1] == t3.Row2[1])
					{
						cout << "\n// I win!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}
					if(t.Row2[2] == PCM && t.Row2[2] == t2.Row2[2] && t2.Row2[2] == t3.Row2[2])
					{
						cout << "\n// I win!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}
					if(t.Row2[3] == PCM && t.Row2[3] == t2.Row2[3] && t2.Row2[3] == t3.Row2[3])
					{
						cout << "\n// I win!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}
					// Computer Win (row 3)
					if(t.Row3[1] == PCM && t.Row3[1] == t2.Row3[1] && t2.Row3[1] == t3.Row3[1])
					{
						cout << "\n// I win!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}
					if(t.Row3[2] == PCM && t.Row3[2] == t2.Row3[2] && t2.Row3[2] == t3.Row3[2])
					{
						cout << "\n// I win!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}
					if(t.Row3[3] == PCM && t.Row3[3] == t2.Row3[3] && t2.Row3[3] == t3.Row3[3])
					{
						cout << "\n// I win!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}

				/*--------------------------------------------------------------------------------------------------------------------------------------------------*/

					// Continue
					else
					{
						// Draw
						if(t.Row1[1] != Default && t.Row1[2] != Default && t.Row1[3] != Default && t.Row2[1] != Default && t.Row2[2] != Default && t.Row2[3] != Default && t.Row3[1] != Default && t.Row3[2] != Default && t.Row3[3] != Default && t2.Row1[1] != Default && t2.Row1[2] != Default && t2.Row1[3] != Default && t2.Row2[1] != Default && t2.Row2[2] != Default && t2.Row2[3] != Default && t2.Row3[1] != Default && t2.Row3[2] != Default && t2.Row3[3] != Default && t3.Row1[1] != Default && t3.Row1[2] != Default && t3.Row1[3] != Default && t3.Row2[1] != Default && t3.Row2[2] != Default && t3.Row2[3] != Default && t3.Row3[1] != Default && t3.Row3[2] != Default && t3.Row3[3] != Default)
						{
							cout << "\n// Draw!" << endl;

							t.Reset();
							t2.Reset();
							t3.Reset();
						}

						else
						{
							MoveOn = true;
						}

					}
				}

				if(BoardChoice == "3")
				{
					t3.PlayerMove();
					t.UpdateBoard();
					t2.UpdateBoard();
					t3.UpdateBoard();
					t3.End();
					// Player Win (row 1)
					if(t.Row1[1] == PM && t.Row1[1] == t2.Row1[1] && t2.Row1[1] == t3.Row1[1])
					{
						cout << "\n// You win!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}
					if(t.Row1[2] == PM && t.Row1[2] == t2.Row1[2] && t2.Row1[2] == t3.Row1[2])
					{
						cout << "\n// You win!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}
					if(t.Row1[3] == PM && t.Row1[3] == t2.Row1[3] && t2.Row1[3] == t3.Row1[3])
					{
						cout << "\n// You win!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}
					// Player Win (row 2)
					if(t.Row2[1] == PM && t.Row2[1] == t2.Row2[1] && t2.Row2[1] == t3.Row2[1])
					{
						cout << "\n// You win!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}
					if(t.Row2[2] == PM && t.Row2[2] == t2.Row2[2] && t2.Row2[2] == t3.Row2[2])
					{
						cout << "\n// You win!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}
					if(t.Row2[3] == PM && t.Row2[3] == t2.Row2[3] && t2.Row2[3] == t3.Row2[3])
					{
						cout << "\n// You win!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}
					// Player Win (row 3)
					if(t.Row3[1] == PM && t.Row3[1] == t2.Row3[1] && t2.Row3[1] == t3.Row3[1])
					{
						cout << "\n// You win!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}
					if(t.Row3[2] == PM && t.Row3[2] == t2.Row3[2] && t2.Row3[2] == t3.Row3[2])
					{
						cout << "\n// You win!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}
					if(t.Row3[3] == PM && t.Row3[3] == t2.Row3[3] && t2.Row3[3] == t3.Row3[3])
					{
						cout << "\n// You win!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}

				/*--------------------------------------------------------------------------------------------------------------------------------------------------*/

					// Computer Win (row 1)
					if(t.Row1[1] == PCM && t.Row1[1] == t2.Row1[1] && t2.Row1[1] == t3.Row1[1])
					{
						cout << "\n// I win!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}
					if(t.Row1[2] == PCM && t.Row1[2] == t2.Row1[2] && t2.Row1[2] == t3.Row1[2])
					{
						cout << "\n// I win!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}
					if(t.Row1[3] == PCM && t.Row1[3] == t2.Row1[3] && t2.Row1[3] == t3.Row1[3])
					{
						cout << "\n// I win!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}
					// Computer Win (row 2)
					if(t.Row2[1] == PCM && t.Row2[1] == t2.Row2[1] && t2.Row2[1] == t3.Row2[1])
					{
						cout << "\n// I win!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}
					if(t.Row2[2] == PCM && t.Row2[2] == t2.Row2[2] && t2.Row2[2] == t3.Row2[2])
					{
						cout << "\n// I win!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}
					if(t.Row2[3] == PCM && t.Row2[3] == t2.Row2[3] && t2.Row2[3] == t3.Row2[3])
					{
						cout << "\n// I win!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}
					// Computer Win (row 3)
					if(t.Row3[1] == PCM && t.Row3[1] == t2.Row3[1] && t2.Row3[1] == t3.Row3[1])
					{
						cout << "\n// I win!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}
					if(t.Row3[2] == PCM && t.Row3[2] == t2.Row3[2] && t2.Row3[2] == t3.Row3[2])
					{
						cout << "\n// I win!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}
					if(t.Row3[3] == PCM && t.Row3[3] == t2.Row3[3] && t2.Row3[3] == t3.Row3[3])
					{
						cout << "\n// I win!" << endl;

						t.Reset();
						t2.Reset();
						t3.Reset();
					}

				/*--------------------------------------------------------------------------------------------------------------------------------------------------*/

					// Continue
					else
					{
						// Draw
						if(t.Row1[1] != Default && t.Row1[2] != Default && t.Row1[3] != Default && t.Row2[1] != Default && t.Row2[2] != Default && t.Row2[3] != Default && t.Row3[1] != Default && t.Row3[2] != Default && t.Row3[3] != Default && t2.Row1[1] != Default && t2.Row1[2] != Default && t2.Row1[3] != Default && t2.Row2[1] != Default && t2.Row2[2] != Default && t2.Row2[3] != Default && t2.Row3[1] != Default && t2.Row3[2] != Default && t2.Row3[3] != Default && t3.Row1[1] != Default && t3.Row1[2] != Default && t3.Row1[3] != Default && t3.Row2[1] != Default && t3.Row2[2] != Default && t3.Row2[3] != Default && t3.Row3[1] != Default && t3.Row3[2] != Default && t3.Row3[3] != Default)
						{
							cout << "\n// Draw!" << endl;

							t.Reset();
							t2.Reset();
							t3.Reset();
						}

						else
						{
							MoveOn = true;
						}

					}
				}

			}

		}
	}


	return 0;
}
