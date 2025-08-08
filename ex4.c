/******************
Assignment: ex4
*******************/
#include <stdio.h>
#include <string.h>

#define SIZE2 5
#define MAX_SIZE 10
#define MAX_SIZE2 30
#define MAX_SLOTS 100
#define MAX_WORDS 100
#define MAX_LENGTH 15

typedef struct
{
    int row;
    int col;
    int length;
    int direction;
} Slot;

int task1RobotPaths(int x, int y);
int task1RobotPathsHelper(int x, int y);
float task2HumanPyramid(float arr[SIZE2][SIZE2], int Size, int x, int y);
int matchingParenthesis(char c1, char c2);
int task3ParenthesisValidatorHelper();
int task3ParenthesisValidator(int depth, int lastOpen);
int isNearQueen(char result[MAX_SIZE][MAX_SIZE], int N, int col, int row);
int isTakenProvince(char board[MAX_SIZE][MAX_SIZE], char result[MAX_SIZE][MAX_SIZE], int N, int col, int row, char pr);
int isEmptyRow(char result[MAX_SIZE][MAX_SIZE], int N, int col, int row);
int SafeRow(char board[MAX_SIZE][MAX_SIZE], char result[MAX_SIZE][MAX_SIZE], int N, int col, int row);
int task4QueensBattle(char board[MAX_SIZE][MAX_SIZE], char result[MAX_SIZE][MAX_SIZE], int N, int col, int row);


int main()
{
    int task = -1;
    do
    {
        printf("Choose an option:\n"
               "1. Robot Paths\n"
               "2. The Human Pyramid\n"
               "3. Parenthesis Validation\n"
               "4. Queens Battle\n"
               "5. Crossword Generator\n"
               "6. Exit\n");

        if (scanf("%d", &task))
        {
            switch (task)
            {
            case 6:
                printf("Goodbye!\n");
                break;
            case 1:
            {
                int x, y;
                printf("Please enter the coordinates of the robot (column, row):\n");
                scanf("%d %d", &x, &y);
                int result = task1RobotPaths(x, y);
                printf("The total number of paths the robot can take to reach home is: %d\n", result);
                break;
            }
            case 2:
            {
                float arr[SIZE2][SIZE2];
                int isValid = 1;
                for(int i = 0; i < SIZE2; i++)
                {
                    for(int k = 0; k < SIZE2; k++)
                    {
                        arr[i][k] = -1;
                    }
                }
                printf("Please enter the weights of the cheerleaders:\n");
                for(int i = SIZE2 - 1; i >= 0 && isValid; i--)
                {
                    for(int k = 0; k < SIZE2 - i; k++)
                    {
                        scanf("%f", &arr[k][i]);
                        if(arr[k][i] < 0)
                        {
                            printf("Negative weights are not supported.\n");
                            isValid = 0;
                            break;
                        }
                    }
                }
                if(!isValid)
                    break;
                printf("The total weight on each cheerleader is:\n");
                for(int i = SIZE2 - 1; i >= 0; i--)
                {
                    for(int k = 0; k < SIZE2 - i; k++)
                    {
                        printf("%.2f ", task2HumanPyramid(arr, SIZE2, k , i));
                    }
                    printf("\n");
                }
                break;
            }
            case 3:
            {
                scanf("%*c");
                printf("Please enter a term for validation:\n");
                int result = task3ParenthesisValidatorHelper();
                if(result)
                    printf("The parentheses are balanced correctly.\n");
                else
                    printf("The parentheses are not balanced correctly.\n");
                break;
            }
            case 4:
            {
                char board[MAX_SIZE][MAX_SIZE] = {0}, result[MAX_SIZE][MAX_SIZE] = {0};
                int N;
                for(int i = 0; i < N; i++)
                {
                    for(int k = 0; k < N; k++)
                    {
                        result[i][k] = '*';
                    }
                }
                printf("Please enter the board dimensions:\n");
                scanf("%d", &N);
                printf("Please enter the %dx%d puzzle board:\n", N, N);
                for (int i = N - 1; i >= 0; i--) {
                    for (int k = 0; k < N; k++) {
                        scanf(" %c", &board[i][k]);
                    }
                }
                int possible = task4QueensBattle(board, result, N, 0, 0);
                if(possible)
                {
                    printf("Solution:\n");
                    for(int i = N - 1; i >= 0; i--)
                    {
                        for(int k = 0; k < N; k++)
                        {
                            printf("%c ", result[i][k]);
                        }
                        printf("\n");
                    }
                }
                else
                    printf("This puzzle cannot be solved.\n");
                break;
            }
            case 5:
            {
                /* For some reacon it doesn't work, I tried to debug it but I couldn't find the problem
                char grid[MAX_SIZE2][MAX_SIZE2] = {0}, words[MAX_SLOTS][MAX_LENGTH + 1] = {0};
                Slot slots[MAX_SLOTS];
                int numSlots, numWords, dim, inserted[MAX_WORDS] = {0}, owns[MAX_SIZE2][MAX_SIZE2] = {0};
                // Initialize grid to #
                for (int i = 0; i < MAX_SIZE2; i++) {
                    for (int k = 0; k < MAX_SIZE2; k++) {
                        grid[i][k] = '#';
                    }
                }
                // Get input from the user
                printf("Please enter the dimensions of the crossword grid:\n");
                scanf("%d", &dim);
                printf("Please enter the number of slots in the crossword:\n");
                scanf("%d", &numSlots);
                printf("Please enter the details for each slot (Row, Column, Length, Direction):\n");
                for (int i = 0; i < numSlots; i++) {
                    scanf("%d %d %d %c", &slots[i].row, &slots[i].col, &slots[i].length, &slots[i].direction);
                }
                printf("Please enter the number of words in the dictionary:\n");
                scanf("%d", &numWords);
                while (numWords < numSlots) {
                    printf("The dictionary must contain at least %d words. Please enter a valid dictionary size:\n", numSlots);
                    scanf("%d", &numWords);
                }
                printf("Please enter the words for the dictionary:\n");
                for (int i = 0; i < numWords; i++) {
                    scanf("%s", words[i]);
                }
                // Generate the crossword
                int possible = task5CrosswordGenerator(grid, slots, numSlots, inserted, words, numWords, 0, 0, owns);
                if (possible) {
                    // Print the crossword grid
                    for (int i = 0; i < dim; i++) {
                        for (int k = 0; k < dim; k++) {
                            printf("| %c ", grid[i][k]);
                        }
                        printf("|\n");
                    }
                } else {
                    printf("This crossword cannot be solved.\n");
                } */
                break;
            }
            default:
                printf("Please choose a task number from the list.\n");
                break;
            }
        }
        else
        {
            scanf("%*s");
        }

    } while (task != 6);
}

int task1RobotPaths(int x, int y)
{
    //checks whether the user entered negative coordinates
    if(x < 0 || y < 0)
        return 0;
    return task1RobotPathsHelper(x, y);
}

int task1RobotPathsHelper(int x, int y)
{
    // if one of the coordinates is 0, then there is exactly one way to the base from there
    if(x == 0 || y == 0)
        return 1;
    return task1RobotPathsHelper(x - 1, y) + task1RobotPathsHelper(x, y - 1);
}

float task2HumanPyramid(float arr[SIZE2][SIZE2], int size, int x, int y)
{
    if(x == size || y == size || x == -1 || arr[x][y] == -1)
        return 0;
    return task2HumanPyramid(arr, size, x, y + 1) / 2 + task2HumanPyramid(arr, size, x - 1, y + 1) / 2 + arr[x][y];
}

int matchingParenthesis(char c1, char c2)
{
    if(c1 == '(' && c2 == ')')
        return 1;
    if(c1 == '[' && c2 == ']')
        return 1;
    if(c1 == '{' && c2 == '}')
        return 1;
    if(c1 == '<' && c2 == '>')
        return 1;
    return 0;
}

// this function is used to start the recursion and to skip any whitespace characters
int task3ParenthesisValidatorHelper()
{
    char c;
    scanf("%c", &c);
    // if it is whitespace, we don't start yet
    if (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\f' || c == '\v')
        return task3ParenthesisValidatorHelper();
    else if (c == '(' || c == '[' || c == '{' || c == '<')
        return task3ParenthesisValidator(1, c) && task3ParenthesisValidator(0, c);
    else if (c == ')' || c == ']' || c == '}' || c == '>')
        return 0;
    return task3ParenthesisValidator(0, 0);
}

// it checks whether each parenthesis has a matching one in the same depth
int task3ParenthesisValidator(int depth, int lastOpen)
{
    char c;
    scanf("%c", &c);
    if(c == '\n')
    {
        if(depth == 0)
            return 1;
        return 0;
    }
    else if(c == '(' || c == '[' || c == '{' || c == '<')
    {
        /* checks if there is a matching parenthesis in the same depth (now one deeper) 
         but still needs to also check if we are done with the input */
        if(task3ParenthesisValidator(depth + 1, c) && task3ParenthesisValidator(depth, lastOpen))
            return 1;
        return 0;
    }
    else if(c == ')' || c == ']' || c == '}' || c == '>')
    {
        // whether it matches the last open parenthesis (and if there is one), if yes we found a match
        if(depth != 0 && matchingParenthesis(lastOpen, c))
            return 1;
        scanf("%*[^\n]");
        scanf("%*c");
        return 0;
    }
    return task3ParenthesisValidator(depth, lastOpen);
}

int isNearQueen(char result[MAX_SIZE][MAX_SIZE], int N, int col, int row)
{
    if(row > 0)
    {
        if(result[row - 1][col] == 'X')
            return 1;
        if(col > 0 && result[row - 1][col - 1] == 'X')
            return 1;
        if(col < N - 1 && result[row - 1][col + 1] == 'X')
            return 1;
    }
    if(row < N - 1)
    {
        if(result[row + 1][col] == 'X')
            return 1;
        if(col > 0 && result[row + 1][col - 1] == 'X')
            return 1;
        if(col < N - 1 && result[row + 1][col + 1] == 'X')
            return 1;
    }
    if(col > 0 && result[row][col - 1] == 'X')
        return 1;
    if(col < N - 1 && result[row][col + 1] == 'X')
        return 1;
    return 0;
}

// checks if the province is already taken by scanning the whole board
int isTakenProvince(char board[MAX_SIZE][MAX_SIZE], char result[MAX_SIZE][MAX_SIZE], int N, int col, int row, char pr)
{
    if(row >= N)
        return 0;
    if(col >= N)
        return isTakenProvince(board, result, N, 0, row + 1, pr);
    if(board[row][col] == pr && result[row][col] == 'X')
        return 1;
    return isTakenProvince(board, result, N, col + 1, row, pr);
}

int isEmptyRow(char result[MAX_SIZE][MAX_SIZE], int N, int col, int row)
{
    if(col >= N)
        return 1;
    if(result[row][col] == 'X')
        return 0;
    return isEmptyRow(result, N, col + 1, row);
}

// returns the first row from the given one that is safe to place a queen in the current column
int SafeRow(char board[MAX_SIZE][MAX_SIZE], char result[MAX_SIZE][MAX_SIZE], int N, int col, int row)
{
    //if there is no sucj row, we return -1
    if(row >= N)
        return -1;
    if(isEmptyRow(result, N, 0, row) && !isNearQueen(result, N, col, row) 
        && !isTakenProvince(board, result, N, 0, 0, board[row][col]))
        return row;
    return SafeRow(board, result, N, col, row + 1);
}

// we check column by column, if we can't place a queen in the current column, we return 0
int task4QueensBattle(char board[MAX_SIZE][MAX_SIZE], char result[MAX_SIZE][MAX_SIZE], int N, int col, int row)
{
    // queens in all columns have been placed
    if(col >= N)
        return 1;
    row = SafeRow(board, result, N, col, row);
    // if there is no safe place in the current column, we return 0
    if(row == -1)
        return 0;
    // trying to place the queen and countinue checking in next column
    result[row][col] = 'X';
    if(task4QueensBattle(board, result, N, col + 1, 0))
        return 1;
    // if we can't place the queen there, we unmark the cell and try the next available row in the current column
    result[row][col] = '*';
    return task4QueensBattle(board, result, N, col, row + 1);
}
/* 
int placeWordH(char grid[MAX_SIZE2][MAX_SIZE2], Slot slot, char word[MAX_LENGTH + 1], int owns[MAX_SIZE2][MAX_SIZE2], int pos) {
    if (pos == slot.length)
        return 1;
    if((grid[slot.row][slot.col + pos] == '#' || grid[slot.row][slot.col + pos] == word[pos])
        && placeWordH(grid, slot, word, owns, pos + 1))
    {
        grid[slot.row][slot.col + pos] = word[pos];
        owns[slot.row][slot.col + pos]++;
        return 1;
    }
    return 0;
}

int placeWordV(char grid[MAX_SIZE2][MAX_SIZE2], Slot slot, char word[MAX_LENGTH + 1], int owns[MAX_SIZE2][MAX_SIZE2], int pos) {
    if (pos == slot.length)
        return 1;
    if((grid[slot.row + pos][slot.col] == '#' || grid[slot.row + pos][slot.col] == word[pos])
        && placeWordV(grid, slot, word, owns, pos + 1))
    {
        grid[slot.row + pos][slot.col] = word[pos];
        owns[slot.row + pos][slot.col]++;
        return 1;
    }
    return 0;
}

void removeWordH(char grid[MAX_SIZE2][MAX_SIZE2], Slot slot, int owns[MAX_SIZE2][MAX_SIZE2], int pos) {
    if(pos == slot.length)
        return;
        
    owns[slot.row][slot.col + pos]--;
    if(owns[slot.row][slot.col + pos] == 0)
        grid[slot.row][slot.col + pos] = '#';
    removeWordH(grid, slot, owns, pos + 1);
}

void removeWordV(char grid[MAX_SIZE2][MAX_SIZE2], Slot slot, int owns[MAX_SIZE2][MAX_SIZE2], int pos) {
    if(pos == slot.length)
        return;
        
    owns[slot.row + pos][slot.col]--;
    if(owns[slot.row + pos][slot.col] == 0)
        grid[slot.row + pos][slot.col] = '#';
    removeWordV(grid, slot, owns, pos + 1);
}

int insertInGrid(char grid[MAX_SIZE2][MAX_SIZE2], Slot slot, char word[MAX_LENGTH + 1], int owns[MAX_SIZE2][MAX_SIZE2]) {
    if (strlen(word) != slot.length)
        return 0;
    
    // Place word
    if (slot.direction == 'H')
        return placeWordH(grid, slot, word, owns, 0);
    else
        return placeWordV(grid, slot, word, owns, 0);
}

void cancelInsertion(char grid[MAX_SIZE2][MAX_SIZE2], Slot slot, int owns[MAX_SIZE2][MAX_SIZE2]) {
    if (slot.direction == 'H')
        removeWordH(grid, slot, owns, 0);
    else
        removeWordV(grid, slot, owns, 0);
}

int task5CrosswordGenerator(char grid[MAX_SIZE2][MAX_SIZE2], Slot slots[MAX_SLOTS], int numSlots, int inserted[MAX_WORDS],
    char words[MAX_SLOTS][MAX_LENGTH + 1], int numWords, int iSlots, int iWords, int owns[MAX_SIZE2][MAX_SIZE2]) {
    
    if (iSlots == numSlots)
        return 1;
    
    if (iWords == numWords)
        return 0;
    
    if (!inserted[iWords] && insertInGrid(grid, slots[iSlots], words[iWords], owns)) {
        inserted[iWords] = 1;
        if (task5CrosswordGenerator(grid, slots, numSlots, inserted, words, numWords, iSlots + 1, 0, owns))
            return 1;
        inserted[iWords] = 0;
        cancelInsertion(grid, slots[iSlots], owns);
    }
    
    return task5CrosswordGenerator(grid, slots, numSlots, inserted, words, numWords, iSlots, iWords + 1, owns);
} */