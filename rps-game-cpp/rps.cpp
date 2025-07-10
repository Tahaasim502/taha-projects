#include<iostream>
#include<random>
using namespace std;
#define RED     "\033[31m"   //033 means escape character, 30-37 means foreground text color 
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define RESET   "\033[0m"
#define BLUE    "\033[34m"
#define PURPLE  "\033[35m"

string computerChoice()
{
    int num = rand() % 3 + 1;
    if(num == 1)
    {
        return "rock";
    }
    else if(num == 2)
    {
        return "paper"; 
    }
    else 
    {
        return "scissors";
    }
}

string playerChoice()
{
    string choice;
    cout << "Enter the choice you want to select: " << endl;
    cout << "rock | paper | scissors: " << endl;
    cin >> choice;
    while(choice != "rock" && choice != "paper" && choice != "scissors")
    {
        cout << RED << "Invalid choice: " << RESET << endl;
        cin >> choice;
    }
    return choice;
}

void display(string comp_choice, string player_choice)
{
    cout << "Computer Choose: " << comp_choice << endl;
    cout << "Player Choose: " << player_choice << endl;
}

void displaywinner()
{
    string ret1 = computerChoice();
    string ret2 = playerChoice();
    display(ret1, ret2);
    if(ret2 == "rock" && ret1 == "scissors")
    {
        cout << YELLOW << "You picked: " << ret2 << RESET << endl;
        cout << YELLOW << "Computer Picked: " << ret1 << RESET << endl;
        cout << GREEN << "Player wins the game" << RESET << endl;
    }
    else if (ret2 == "rock" && ret1 == "paper")
    {
        cout << YELLOW << "You picked: " << ret2 << RESET << endl;
        cout << YELLOW << "Computer Picked: " << ret1 << RESET << endl;
        cout << BLUE << "Computer wins the game" << RESET << endl;
    }
    else if(ret2 == "rock" && ret1 == "rock")
    {
        cout << YELLOW << "You picked: " << ret2 << RESET << endl;
        cout << YELLOW << "Computer Picked: " << ret1 << RESET << endl;
        cout << RED << "TIE" << RESET << endl;
    }

    else if(ret2 == "paper" && ret1 == "rock")
    {
        cout << YELLOW << "You picked: " << ret2 << RESET << endl;
        cout << YELLOW << "Computer Picked: " << ret1 << RESET << endl;
        cout << GREEN << "Player wins the game" << RESET << endl;
    }
    else if(ret2 == "paper" && ret1 == "scissors")
    {
        cout << YELLOW << "You picked: " << ret2 << RESET << endl;
        cout << YELLOW << "Computer Picked: " << ret1 << RESET << endl;
        cout << BLUE << "Computer wins the game" << RESET << endl;
    }
    else if(ret2 == "paper" && ret1 == "paper")
    {
        cout << YELLOW << "You picked: " << ret2 << RESET << endl;
        cout << YELLOW << "Computer Picked: " << ret1 << RESET << endl;
         cout << RED << "TIE" << RESET << endl; 
    }

    else if(ret2 == "scissors" && ret1 == "rock")
    {
        cout << YELLOW << "You picked: " << ret2 << RESET << endl;
        cout << YELLOW << "Computer Picked: " << ret1 << RESET << endl;
        cout << BLUE << "Computer wins the game" << RESET << endl;
    }
    else if(ret2 == "scissors" && ret1 == "paper")
    {
        cout << YELLOW << "You picked: " << ret2 << RESET << endl;
        cout << YELLOW << "Computer Picked: " << ret1 << RESET << endl;
        cout << GREEN << "Player wins the game" << RESET << endl;
    }
    else if(ret2 == "scissors" && ret1 == "scissors")
    {
        cout << YELLOW << "You picked: " << ret2 << RESET << endl;
        cout << YELLOW << "Computer Picked: " << ret1 << RESET << endl;
         cout << RED << "TIE" << RESET << endl;
    }

}

int main()
{
    char again;
    srand(time(0));
    do
    {
        displaywinner();
        cout << endl;
        cout << "Do you wish to play the game again(y|n): ";
        cin >> again; 
    } while (again == 'y' || again == 'Y');
    cout << PURPLE << "GAME OVER!" << RESET << endl;
    return 0;
}