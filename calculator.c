#include <stdio.h>

void inputEvaluate();

int main() {
    inputEvaluate();
    return 0;
}



void inputEvaluate() {
    char input[256];
    scanf("%s", input);
    printf("You entered: %s\n", input);
    int index = 0;
    int startNumber = index;
    int endNumber;
    int *num;
    int numberCount = 0;

    while (input[index] != '\0') {
        if(input[index] != '+' && input[index] != '-' && input[index] != '*' && input[index] != '/' && input[index] != '%') {
            index++;
            continue;
        } else {
            endNumber = index - 1;
            printf("start number: %d\nend number: %d\n", startNumber, endNumber); // start number end number
            int numberLength = endNumber - startNumber + 1;
            printf("number length: %d\n", numberLength);
            int number = 0;
            printf("char number = ");
            for(int i = startNumber ; i <= endNumber ; i++) {
                printf("%c", input[i]);
                number = number * 10 + (input[i] - '0');
            }
            printf("\n");
            printf("int number: %d\n", number);
            num[numberCount] = number;
            numberCount++;
            printf("start number: %d\nend number: %d\n", startNumber, endNumber); // start number end number
            startNumber = endNumber;
        }
        index++;
    }
    for(int i = 0 ; i <= numberCount ; i++) {
        printf("number %d : %d\n", i, num[i]);
    }
}