// Game : Simple betting game
// "Jack Queen King" - Computer shuffles these cards
// Player has to guess the position of the queen 
// If he wins, he takes 3 * bet amount
// If he looses, he loosed bet amount
// Player has $100 initially 

# include<iostream>
# include<time.h>
using namespace std;
int cash = 100;

void play(int bet){
    // char c[3] = {'J', 'Q', 'K'};
    char *c = new char[10]; // Memory allocating at run time 
    c[0] = 'J';
    c[1] = 'Q';
    c[2] = 'K';
    cout<< "Shuffling....." << endl;
    srand(time(NULL)); // Seeding random number generator
    for (int i = 0; i < 5; i++) // Swaps positions 5 times 
    {
        int x = rand() % 3;
        int y = rand() % 3;
        int temp = c[x];
        c[x] = c[y];
        c[y] = temp; // Swaps characters at position x and y
    }
    int PlayersGuess;
    cout<< "What's the position of the queen => 1, 2 & 3 = ";
    cin>> PlayersGuess;
    if(c[PlayersGuess - 1] == 'Q'){
        cash += 3*bet;
        cout<< "You win!! Result = /" << c[0] << " " << c[1] << " "<<  c[2] << "/ Total cash = $" << cash << endl;
    }
    else{
        cash -= bet;
        cout<< "You loose!! Result = /" << c[0] << " " << c[1] << " "<<  c[2] << "/ Total cash = $" << cash  << endl;
    }
    free(c); // Freeing the allocated memory
}

int main(){
    int bet;
    cout<< "***Welcome to the virtual casino***" << endl;
    cout<< endl << "Total cash = $" << cash << endl;
    while (cash > 0)
    {
        cout<< "What's your bet? = $";
        cin>> bet;
        if(bet == 0 || bet > cash)
        {
            cout<< "Your bet amout exceeded, Please enter bet amount less than your total cash" << endl;
            break;
        }
        play(bet);
    }
    
    return 0;
}