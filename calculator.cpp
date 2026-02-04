#include <stdio.h>
#include <math.h>

void inputEvaluate();

int main() {
    inputEvaluate();
    return 0;
}

void inputEvaluate() {
    char input[256];
    scanf("%s", input);
    
    int index = 0;
    int startIntNumber = 0;
    int numberCount = 0;
    double *numArr = new double[100];

    while (input[index] != '\0') {
        if(input[index] != '+' && input[index] != '-' && input[index] != '*' && input[index] != '/' && input[index] != '%' && input[index] != '.') {
            index++;
            continue; 
        } 
        
        if(input[index] != '.') {
            double number = 0;
            int dotPos = -1;

            for(int i = startIntNumber; i < index; i++) {
                if(input[i] == '.') {
                    dotPos = i;
                    break;
                }
            }

            if(dotPos == -1) { // จำนวนเต็ม
                for(int i = startIntNumber; i < index; i++) {
                    number = number * 10 + (input[i] - '0');
                }
            } else { // ทศนิยม
                for(int i = startIntNumber; i < dotPos; i++) {
                    number = number * 10 + (input[i] - '0');
                }
                double expo = 1;
                for(int i = dotPos + 1; i < index; i++) {
                    number += (input[i] - '0') * pow(10, -expo);
                    expo++;
                }
            }

            numArr[numberCount++] = number;
            startIntNumber = index + 1;
        }
        index++;
    }

    if (startIntNumber < index) {
        double lastNumber = 0;
        int dotPos = -1;

        for (int i = startIntNumber; i < index; i++) {
            if (input[i] == '.') {
                dotPos = i;
                break;
            }
        }

        if (dotPos == -1) {
            for (int i = startIntNumber; i < index; i++) {
                lastNumber = lastNumber * 10 + (input[i] - '0');
            }
        } else {
            for (int i = startIntNumber; i < dotPos; i++) {
                lastNumber = lastNumber * 10 + (input[i] - '0');
            }
            double divisor = 10;
            for (int i = dotPos + 1; i < index; i++) {
                lastNumber += (input[i] - '0') / divisor;
                divisor *= 10;
            }
        }
        
        numArr[numberCount] = lastNumber;
        numberCount++; 
    }

    for(int i = 0 ; i < numberCount ; i++) {
        printf("Number %d : %.4f\n", i + 1, numArr[i]);
    }
    delete[] numArr; 
}