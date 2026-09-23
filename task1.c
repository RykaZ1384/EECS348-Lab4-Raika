#include <stdio.h> // access to printf() and scanf()

int main() { // main function where the program starts

    int score; // store the score entered by the user

    // keep asking until the user enters 1
    while (1) {

        printf("Enter the NFL score (Enter 1 to stop): "); // ask for the score

        // check if the input is a valid number
        if (scanf("%d", &score) != 1) {
            printf("Invalid input. Please enter a number.\n"); // show error message

            while (getchar() != '\n'); // clear the invalid input
            continue; // ask again
        }

        // stop the program if score is 1
        if (score == 1) {
            break;
        }

        // check for negative scores
        if (score < 0) {
            printf("Invalid score. Please enter a positive score.\n");
            continue;
        }

        // show the combinations for the entered score
        printf("Possible combinations of scoring plays if a team's score is %d:\n", score);

        // go through possible 8 point touchdowns
        for (int td2 = 0; td2 * 8 <= score; td2++) {

            // go through possible 7 point touchdowns
            for (int td1 = 0; td2 * 8 + td1 * 7 <= score; td1++) {

                // go through possible regular touchdowns
                for (int td = 0; td2 * 8 + td1 * 7 + td * 6 <= score; td++) {

                    // go through possible field goals
                    for (int fg = 0;
                         td2 * 8 + td1 * 7 + td * 6 + fg * 3 <= score;
                         fg++) {

                        // go through possible safeties
                        for (int safety = 0;
                             td2 * 8 + td1 * 7 + td * 6 +
                             fg * 3 + safety * 2 <= score;
                             safety++) {

                            // calculate the score for this combination
                            int total = td2 * 8 + td1 * 7 + td * 6
                                      + fg * 3 + safety * 2;

                            // print it if the combination matches the score
                            if (total == score) {
                                printf("%d TD + 2pt, %d TD + FG, %d TD, "
                                       "%d 3pt FG, %d Safety\n",
                                       td2, td1, td, fg, safety);
                            }
                        }
                    }
                }
            }
        }
    }

    return 0; // end program
}
