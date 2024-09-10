/*
	Cole Swinford
	Lab 9, Sec. 1
	March 25, 2022
	Tic-Tac-Toe
*/

#include <iostream>
#include <ctype.h>
#include <cstdlib>
#include <time.h>
using namespace std;


int UserStart;
string UserChoice;
bool MoveOn;

class TTT
{
    public:

        int RandPCM;
        string Row3[4];
        string Row2[4];
        string Row1[4];
		string Default = " ";
		string PM;
        string PCM;

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

            cout << "#################" << endl;
            cout << "|| " << Row3[1] << " || " << Row3[2] << " || " << Row3[3] << " ||" << endl;
            cout << "#################" << endl;
            cout << "|| " << Row2[1] << " || " << Row2[2] << " || " << Row2[3] << " ||" << endl;
            cout << "#################" << endl;
            cout << "|| " << Row1[1] << " || " << Row1[2] << " || " << Row1[3] << " ||" << endl;
            cout << "#################" << endl;

            return 0;
        }
 
		// Randomly select starting player
        int RandStart()
        { 
            srand(time(0));
            UserStart = rand() % 2;
            cout << "UserStart: " << UserStart << endl;

            if (UserStart == 0)
            {
                cout << "\nI go first" << endl;

                // X, O selection
				srand(time(0));
				RandPCM = rand() % 2;
				RandPCM += + 1;

				if (RandPCM == 1)
				{
					PCM = "x";
				}
				if (RandPCM == 0)
				{
					PCM = "o";
				}

				if (PCM == "x")
				{
					PM = "o";
				}

				if (PCM == "o")
				{
					PM = "x";
				}
            }

            if (UserStart == 1)
            {
				// X, O selection
                cout << "\nChoose your fighter 'x' or 'o'" << endl;
				cin >> PM;
				UserChoice = PM;
            }

            return 0;
        }

		// Player move
        int PlayerMove()
        {
			bool prompt = true;
			int PMx;
			int PMy;

			if (prompt == true)
			{
				cout << Row1[1];
				// x-coordinate selection
				cout << "\nx coordinate: ";
				cin >> PMx;

				// y-coordinate selection
				cout << "\ny coordinate: ";
				cin >> PMy;

				prompt = false;
			}

			if (PMy == 1)
			{
				if (Row1[PMx] == " ")
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

			if (PMy == 2)
			{
				if (Row2[PMx] == " ")
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

			if (PMy == 3)
			{
				if (Row3[PMx] == " ")
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
			while (PC == true)
			{
				bool Roll = true;
				int PCx;
				int PCy;

				if (Roll == true)
				{
					if (Row1[1] == Default || Row1[2] == Default || Row1[3] == Default)
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

					if (Row2[1] == Default || Row2[2] == Default || Row2[3] == Default)
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

					if (Row3[1] == Default || Row3[2] == Default || Row3[3] == Default)
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

				if (UserStart == 1)
				{
					if (UserChoice == "x")
					{
						PCM = "o";
					}

					if (UserChoice == "o")
					{
						PCM = "x";
					}
				}

				if (PCy == 1)
				{
					if (Row1[PCx] == Default)
					{
						Row1[PCx] = PCM;
						PC = false;
					}

					else
					{
						Roll = true;
					}
				}

				if (PCy == 2)
				{
					if (Row2[PCx] == Default)
					{
						Row2[PCx] = PCM;
						PC = false;
					}

					else
					{
						Roll = true;
					}
				}

				if (PCy == 3)
				{
					if (Row3[PCx] == Default)
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
			if (Row1[1] == PM && Row1[1] == Row1[2] && Row1[2] == Row1[3])
			{
				cout << "\n// You win!" << endl;

				// Game Reset
				MoveOn = true;
				cout << "\n----------------------------------" << endl;
				cout << "Default Board" << endl;
				DefaultBoard();
				RandStart();
				return 0;
			}
			if (Row2[1] == PM && Row2[1] == Row2[2] && Row2[2] == Row2[3])
			{
				cout << "\n// You win!" << endl;

				// Game Reset
				MoveOn = true;
				cout << "\n----------------------------------" << endl;
				cout << "Default Board" << endl;
				DefaultBoard();
				RandStart();
				return 0;
			}
			if (Row3[1] == PM && Row3[1] == Row3[2] && Row3[2] == Row3[3])
			{
				cout << "\n// You win!" << endl;

				// Game Reset
				MoveOn = true;
				cout << "\n----------------------------------" << endl;
				cout << "Default Board" << endl;
				DefaultBoard();
				RandStart();
				return 0;
			}

			// Player Win (vertical)
			if (Row1[1] == PM && Row1[1] == Row2[1] && Row2[1] == Row3[1])
			{
				cout << "\n// You win!" << endl;

				// Game Reset
				MoveOn = true;
				cout << "\n----------------------------------" << endl;
				cout << "Default Board" << endl;
				DefaultBoard();
				RandStart();
				return 0;
			}
			if (Row1[2] == PM && Row1[2] == Row2[2] && Row2[2] == Row3[2])
			{
				cout << "\n// You win!" << endl;

				// Game Reset
				MoveOn = true;
				cout << "\n----------------------------------" << endl;
				cout << "Default Board" << endl;
				DefaultBoard();
				RandStart();
				return 0;
			}
			if (Row1[3] == PM && Row1[3] == Row2[3] && Row2[3] == Row3[3])
			{
				cout << "\n// You win!" << endl;

				// Game Reset
				MoveOn = true;
				cout << "\n----------------------------------" << endl;
				cout << "Default Board" << endl;
				DefaultBoard();
				RandStart();
				return 0;
			}

			// Player Win (diagonal)
			if (Row1[1] == PM && Row1[1] == Row2[2] && Row3[3] == Row2[2])
			{
				cout << "\n// You win!" << endl;

				// Game Reset
				MoveOn = true;
				cout << "\n----------------------------------" << endl;
				cout << "Default Board" << endl;
				DefaultBoard();
				RandStart();
				return 0;
			}
			if (Row3[1] == PM && Row3[1] == Row2[2] && Row1[3] == Row2[2])
			{
				cout << "\n// You win!" << endl;

				// Game Reset
				MoveOn = true;
				cout << "\n----------------------------------" << endl;
				cout << "Default Board" << endl;
				DefaultBoard();
				RandStart();
				return 0;
			}

/*--------------------------------------------------------------------------------------------------------------------------------------------------*/

			// Computer Win (horizontal)
			if (Row1[1] == PCM && Row1[1] == Row1[2] && Row1[2] == Row1[3])
			{
				cout << "\n// I win!" << endl;

				// Game Reset
				MoveOn = true;
				cout << "\n----------------------------------" << endl;
				cout << "Default Board" << endl;
				DefaultBoard();
				RandStart();
				return 0;
			}
			if (Row2[1] == PCM && Row2[1] == Row2[2] && Row2[2] == Row2[3])
			{
				cout << "\n// I win!" << endl;

				// Game Reset
				MoveOn = true;
				cout << "\n----------------------------------" << endl;
				cout << "Default Board" << endl;
				DefaultBoard();
				RandStart();
				return 0;
			}
			if (Row3[1] == PCM && Row3[1] == Row3[2] && Row3[2] == Row3[3])
			{
				cout << "\n// I win!" << endl;

				// Game Reset
				MoveOn = true;
				cout << "\n----------------------------------" << endl;
				cout << "Default Board" << endl;
				DefaultBoard();
				RandStart();
				return 0;
			}

			// Computer Win (vertical)
			if (Row1[1] == PCM && Row1[1] == Row2[1] && Row2[1] == Row3[1])
			{
				cout << "\n// I win!" << endl;

				// Game Reset
				MoveOn = true;
				cout << "\n----------------------------------" << endl;
				cout << "Default Board" << endl;
				DefaultBoard();
				RandStart();
				return 0;
			}
			if (Row1[2] == PCM && Row1[2] == Row2[2] && Row2[2] == Row3[2])
			{
				cout << "\n// I win!" << endl;

				// Game Reset
				MoveOn = true;
				cout << "\n----------------------------------" << endl;
				cout << "Default Board" << endl;
				DefaultBoard();
				RandStart();
				return 0;
			}
			if (Row1[3] == PCM && Row1[3] == Row2[3] && Row2[3] == Row3[3])
			{
				cout << "\n// I win!" << endl;

				// Game Reset
				MoveOn = true;
				cout << "\n----------------------------------" << endl;
				cout << "Default Board" << endl;
				DefaultBoard();
				RandStart();
				return 0;
			}

			// Computer Win (diagonal)
			if (Row1[1] == PCM && Row1[1] == Row2[2] && Row3[3] == Row2[2])
			{
				cout << "\n// I win!" << endl;

				// Game Reset
				MoveOn = true;
				cout << "\n----------------------------------" << endl;
				cout << "Default Board" << endl;
				DefaultBoard();
				RandStart();
				return 0;
			}
			if (Row3[1] == PCM && Row3[1] == Row2[2] && Row1[3] == Row2[2])
			{
				cout << "\n// I win!" << endl;

				// Game Reset
				MoveOn = true;
				cout << "\n----------------------------------" << endl;
				cout << "Default Board" << endl;
				DefaultBoard();
				RandStart();
				return 0;
			}

/*--------------------------------------------------------------------------------------------------------------------------------------------------*/

			// Continue
			else
			{
				// Draw
				if (Row1[1] != Default && Row1[2] != Default && Row1[3] != Default && Row2[1] != Default && Row2[2] != Default && Row2[3] != Default && Row3[1] != Default && Row3[2] != Default && Row3[3] != Default)
				{
					cout << "\n// Draw!" << endl;

					// Game Reset
					MoveOn = true;
					cout << "\n----------------------------------" << endl;
					cout << "Default Board" << endl;
					DefaultBoard();
					RandStart();
					return 0;
				}

				else
				{
					return 0;
				}

			}
		}

};


int main()
{
	TTT t;
	MoveOn = true;
	cout << "\n----------------------------------" << endl;
	cout << "Default Board" << endl;
	t.DefaultBoard();
	t.RandStart();

	// If User starts
	if (UserStart == 1)
	{
		while (1)
		{
			MoveOn = false;
			t.PlayerMove();
			cout << "\nYour move" << endl;
			t.UpdateBoard();
			t.End();
			if (MoveOn == true)
			{
				cout << "\nComputer moving..." << endl;
				t.PCMove();
				t.UpdateBoard();
				t.End();
			}
		}
	}

	// If Computer starts
	if (UserStart == 0)
	{
		while (1)
		{
			cout << "\nComputer moving..." << endl;
			t.PCMove();
			t.UpdateBoard();
			t.End();
			cout << "\nYour move" << endl;
			t.PlayerMove();
			t.UpdateBoard();
			t.End();
		}
	}

	return 0;
}