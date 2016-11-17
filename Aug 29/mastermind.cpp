//the game of mastermind is
//cmpt has 4 slots
//each slot has ball (r,g,b,y) (colors)
//ex: cmpt may have (r,g,g,b)
// usr wants to guess sol'n may guess (y,r,g,b)
// usr gets hit if they get correct slot & color
// usr gets pseudohit if they guess correct color (color exists) but not direct hit
// write method that given guess and sol'n returns the number of htis and ppseudohits
//(y,r,g,b) sol'n (r,g,g,b)
//string = "yrgb" ?
//return 2 hits and pseudohit
//strings are well formed
//best concievably O(1)
// best space == O(1)'


#include <string>
#include <iostream>

void guessCorrectness(std::string guess, std::string solution)
{
    bool * bitMap = new bool[4];
    int hits = 0;
    int pseudoHits = 0;

    for(int i = 0; i < 4; i++)
    {
        if(guess[i] == solution[i])
        {
            bitMap[i] = true;
            hits++;
        }
        else
        {
            bitMap[i] = false;
        }
    }

    for(int i = 0; i < 4; i++)
    {
        if(!bitMap[i])
        {
            int guessValue = guess[i];
            for(int j = 0; j < 4; j++)
            {
                if(!bitMap[j] && guessValue == solution[j])
                {
                    pseudoHits++;
                    bitMap[j] = true;
                }
            }
        }
    }
    std::cout << "PseudoHits are: " << pseudoHits << " & the hits are " << hits << std::endl;
    return;
}

int main()
{
    std::string guess = "yrgb";
    std::string solution = "rggb";

    guessCorrectness(guess,solution); // Should print 1 psuedohit, two hits.

    return 0;
}
