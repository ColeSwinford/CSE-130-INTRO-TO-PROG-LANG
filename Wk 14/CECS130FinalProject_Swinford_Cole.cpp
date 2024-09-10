/*
	Cole Swinford
	Lab 11, Sec. 1
	April 13, 2022
	Symptom Checker
*/

#include <stdlib.h>
#include <iostream>
#include <time.h>
using namespace std;

//Globals
int Fever;
int Cough;
int ShortnessOfBreath;
int RunnyNose;
int Headaches;
int Sneezing;
int Fatigue;

int numPatients;
int numCOVID;
int numCold;
int numFlu;
int otherIllness;
///////////////////

class COVID
{
    public:
        int SymptomCheck()
        {
            if(Fever == 1 && Cough == 1 && ShortnessOfBreath == 1 && Sneezing != 1)
            {
                numCOVID += 1;
            }

            return 0;
        }


};

class Cold: public COVID
{
    public:
        int SymptomCheck()
        {
            if(RunnyNose == 1 && Sneezing == 1 && ShortnessOfBreath != 1)
            {
                numCold += 1;
            }

            return 0;
        }
};

class Flu: public COVID
{
    public:
        int SymptomCheck()
        {
            if(Fever == 1 && Cough == 1 && Headaches == 1 && Fatigue == 1 && ShortnessOfBreath != 1 && Sneezing != 1)
            {
                numFlu += 1;
            }

            return 0;
        }
};

//Symptom Guide
int Guide()
{
    cout << "~`Symptom Checker`~" << endl;
    ///////////////////Adjustable Guide
    string Fever[3];
    string Cough[3];
    string ShortnessOfBreath[3];
    string RunnyNose[3];
    string Headaches[3];
    string Sneezing[3];
    string Fatigue[3];

    Fever[0] = "*";
    Fever[1] = "+";
    Fever[2] = "*";
    Cough[0] = "*";
    Cough[1] = "+";
    Cough[2] = "*";
    ShortnessOfBreath[0] = "*";
    ShortnessOfBreath[1] = "-";
    ShortnessOfBreath[2] = "-";
    RunnyNose[0] = "+";
    RunnyNose[1] = "*";
    RunnyNose[2] = "+";
    Headaches[0] = "+";
    Headaches[1] = "+";
    Headaches[2] = "*";
    Sneezing[0] = "-";
    Sneezing[1] = "*";
    Sneezing[2] = "-";
    Fatigue[0] = "+";
    Fatigue[1] = "+";
    Fatigue[2] = "*";
    ///////////////////

    //Guide
    cout << "\n| Guide: * Common | + Sometimes/Rarely | - No |" << endl;
    cout << " _______________________________________________________________________________" << endl;
    cout << "|\tSymptoms\t|\tCOVID-19\t|      Cold\t|      Flu\t|" << endl;
    cout << "|-----------------------|-----------------------|---------------|---------------|" << endl;
    cout << "|\t  Fever    \t|" << "\t    " << Fever[0] << "\t\t|" << "\t "<< Fever[1] << "\t|" << "\t" << Fever[2] << "\t|" << endl;
    cout << "|-----------------------|-----------------------|---------------|---------------|" << endl;
    cout << "|\t  Cough    \t|" << "\t    " << Cough[0] << "\t\t|" << "\t "<< Cough[1] << "\t|" << "\t" << Cough[2] << "\t|" << endl;
    cout << "|-----------------------|-----------------------|---------------|---------------|" << endl;
    cout << "|  Shortness of Breath  |" << "\t    " << ShortnessOfBreath[0] << "\t\t|" << "\t "<< ShortnessOfBreath[1] << "\t|" << "\t" << ShortnessOfBreath[2] << "\t|" << endl;
    cout << "|-----------------------|-----------------------|---------------|---------------|" << endl;
    cout << "|       Runny Nose      |" << "\t    " << RunnyNose[0] << "\t\t|" << "\t "<< RunnyNose[1] << "\t|" << "\t" << RunnyNose[2] << "\t|" << endl;
    cout << "|-----------------------|-----------------------|---------------|---------------|" << endl;
    cout << "|\t Headaches    \t|" << "\t    " << Headaches[0] << "\t\t|" << "\t "<< Headaches[1] << "\t|" << "\t" << Headaches[2] << "\t|" << endl;
    cout << "|-----------------------|-----------------------|---------------|---------------|" << endl;
    cout << "|\t Sneezing    \t|" << "\t    " << Sneezing[0] << "\t\t|" << "\t "<< Sneezing[1] << "\t|" << "\t" << Sneezing[2] << "\t|" << endl;
    cout << "|-----------------------|-----------------------|---------------|---------------|" << endl;
    cout << "|\t Fatigue    \t|" << "\t    " << Fatigue[0] << "\t\t|" << "\t "<< Fatigue[1] << "\t|" << "\t" << Fatigue[2] << "\t|" << endl;
    cout << "|-----------------------|-----------------------|---------------|---------------|\n" << endl;

    return 0;
}
//Prompt user for number of patients
int Prompt()
{
    cout << "Number of patients: ";
    cin >> numPatients;

    return 0;
}
//Calculate and display percentages of ilnesses
int IllnessResults()
{
    //Symtpom Results
    cout << "| Symptom Results |" << endl;
    cout << " Patients with COVID-19 symptoms: " << numCOVID << endl;
    cout << " Patients with Cold symptoms: " << numCold << endl;
    cout << " Patients with Flu symptoms: " << numFlu << endl;
    cout << " Patients with other illness symptoms: " << otherIllness << "\n" << endl;

    //Percentage of each illness
    cout << "| Percentage of each illness |" << endl;
    float percCOVID;
    percCOVID = ((float)numCOVID/(float)numPatients)*100;
    cout << " COVID-19:\t[" << (int)percCOVID << "%]";
    for(int c = 0; c < (int)percCOVID; c++)
    {
        cout << "+";
    }
    cout << endl;

    float percCold;
    percCold = ((float)numCold/(float)numPatients)*100;
    cout << " Cold:\t\t[" << (int)percCold << "%]";
    for(int co = 0; co < (int)percCold; co++)
    {
        cout << "+";
    }
    cout << endl;

    float percFlu;
    percFlu = ((float)numFlu/(float)numPatients)*100;
    cout << " Flu:\t\t[" << (int)percFlu << "%]";
    for(int f = 0; f < (int)percFlu; f++)
    {
        cout << "+";
    }
    cout << endl;

    float percOther;
    percOther = ((float)otherIllness/(float)numPatients)*100;
    cout << " Other:\t\t[" << (int)percOther << "%]";
    for(int o = 0; o < (int)percOther; o++)
    {
        cout << "+";
    }
    cout << endl;

    return 0;
}


int main()
{
    COVID covid;
    Cold cold;
    Flu flu;

    Guide();
    Prompt();
    cout << "Working on it ...\n" << endl;

    //Randomize symptoms
    srand(time(NULL));
    for(int i = 0; i < numPatients; i++)
    {
        int startingCOVID = numCOVID;
        int startingCold = numCold;
        int startingFlu = numFlu;

        //Random fever
        Fever = rand() % 2;
        //Random cough
        Cough = rand() % 2;
        //Random shortness of breath
        ShortnessOfBreath = rand() % 2;
        //Random runny nose
        RunnyNose = rand() % 2;
        //Random headaches
        Headaches = rand() % 2;
        //Random sneezing
        Sneezing = rand() % 2;
        //Random fatigue
        Fatigue = rand() % 2;

        //cout << "\nFever: " << Fever << "\nCough: " << Cough << "\nShortnessOfBreath: " << ShortnessOfBreath << "\nRunnyNose:" << RunnyNose << "\nHeadaches: " << Headaches << "\nSneezing: " << Sneezing <<"\nFatigue: " << Fatigue << "\n" << endl;

        covid.SymptomCheck();
        cold.SymptomCheck();
        flu.SymptomCheck();

        if(numCOVID == startingCOVID && numCold == startingCold && numFlu == startingFlu)
        {
            otherIllness += 1;
        }

    }

    IllnessResults();


    return 0;
}
