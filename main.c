#include <stdio.h>
#include <stdlib.h>     // for srand()
#include <time.h>       // for time()

/* This function creates a random number between 0 and given num */
int generate_rand_num(int num)
{
    srand(time(NULL));         // srand takes seed as an input and is defined inside stdlib.h
    return rand() % num;
}

int main()
{
    printf("\n\t************ Welcome to Rock-Paper-Scissors Game ************\n\n");
    // Creating array of characters for options to choosen by computer
    char computer[] = {'r', 'p', 's'};

    char username[20], user_input;
    int user_score = 0, computer_score = 0;
    printf("Please enter your name to start the game: ");
    scanf("%s", &username);
    getchar();
    int a = 0;

    // Implementing a while loop to run the game continuously untill the user choose to quit the game
    while (1)
    {
        printf("\nChoose one of the Rock(r), Paper(p), Scissors(s) or Quit(q)\n");
        printf("Computer: Computer has choosen something, it's your turn now: \n%s: ", username);
        scanf("%c", &user_input);
        if (user_input == 'q')
        {
            break;
        }
        else if (user_input == computer[generate_rand_num(3)])
        {
            printf("It's a tie!");
        }
        else
        {
            if (computer[generate_rand_num(3)] == 'r')
            {
                if (user_input == 'p')
                {
                    printf("%s wins!", username);
                    user_score++;
                }
                else if (user_input == 's')
                {
                    printf("Computer wins!");
                    computer_score++;
                }
            }
            else if (computer[generate_rand_num(3)] == 'p')
            {
                if (user_input == 's')
                {
                    printf("%s wins!", username);
                    user_score++;
                }
                else if (user_input == 'r')
                {
                    printf("Computer wins!");
                    computer_score++;
                }
            }
            else if (computer[generate_rand_num(3)] == 's')
            {
                if (user_input == 'r')
                {
                    printf("%s wins!", username);
                    user_score++;
                }
                else if (user_input == 'p')
                {
                    printf("Computer wins!");
                    computer_score++;
                }
            }
        }
        getchar();
        a++;         // Counting how many times game is played between computer and user
    }

    printf("\n\n\t**************** GAME OVER ****************\n");
    printf("\nComputer's score: %d/%d", computer_score, a);
    printf("\n%s's score: %d/%d\n\n", username, user_score, a);

    if (computer_score == user_score)
    {
        printf("This game is a tie! Congratulations to both.\n");
    }
    else if (computer_score < user_score)
    {
        printf("Congratulations! %s, you wins the game.\n", username);
    }
    else if (computer_score > user_score)
    {
        printf("Opps! %s lost the game. Come again to try.\n", username);
    }

    return 0;
}
