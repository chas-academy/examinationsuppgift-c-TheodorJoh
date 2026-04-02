#include <stdio.h>
#include <string.h>


//Function for finding the index of the heighest score
int get_winner_index(int scores[], int size) {
    int best_score_index = 0;
    for (int i = 0; i < size; i++) {
        if(scores[i] > scores[best_score_index]) {
            best_score_index = i; 
        } }
    return best_score_index;
}

int main() {
    char names_list[5][25];
    int points_list[5] = {0};
    float avg_total_score = 0;
    for (int i = 0; i < 5; i++)
    {
        //Names input
        //Only takes in the first 10 letters
        scanf("%10s", names_list[i]);
        for (int j = 0; j < 13; j++)
        {
            //Points input
            int temp;
            scanf("%d", &temp);
            points_list[i] += temp;
        }
        avg_total_score += points_list[i];
    }


    //Makes the first letter capitalized if it is not already
    for(int i = 0;i < 5; i++) {
        if(names_list[i][0] >= 97) 
        {
            names_list[i][0] -= 32;
        }
    }

    //Prints the the student with the heighest score
    printf("%s\n", names_list[get_winner_index(points_list, 5)]);

    //Average points for all student
    avg_total_score = avg_total_score / 5.0;

    //Check who is under the average and prints the ones that are not
    for (int i = 0; i < 5; i++)
    {
        if (points_list[i] < avg_total_score)
        {
            printf("%s\n", names_list[i]);
        }
        
    }
    return 0;
    
}

