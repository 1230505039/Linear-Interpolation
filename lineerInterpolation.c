#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double findRootLine(double x1, double x2, double y1, double y2) {
    double slope = (y2 - y1) / (x2 - x1);
    double fixedNumber = y1 - slope * x1;
    
    double root = (0 - fixedNumber) / slope;

    return root;
}

double findPointsOnFunc(double x, double equation[], int size) {
    double y = 0;
    
    for (int i = 0; i < size; i++)
    {
        y += pow(x, size - i - 1) * equation[i];
    }
    

    return y;
}

int main(){
    system("cls");

    int numberOfTerms;

    printf("Enter the number of terms (Based on max degree): ");
    scanf("%d", &numberOfTerms);

    double equation[numberOfTerms]; 

    for (int i = 0; i < numberOfTerms; i++)
    {
        printf("Enter %d. term: ", i + 1);
        scanf("%lf", &equation[i]);
    }
    
    double bottomLimit;
    double topLimit;

    printf("Enter first point: ");
    scanf("%lf", &bottomLimit);
    printf("Enter second point: ");
    scanf("%lf", &topLimit);

    double myErrorRatio;

    printf("Enter error ratio: ");
    scanf("%lf", &myErrorRatio);

    double errorRatio;

    double candidateRoot;

    do
    {
        double y1 = findPointsOnFunc(bottomLimit, equation, numberOfTerms); 
        double y2 = findPointsOnFunc(topLimit, equation, numberOfTerms); 

        candidateRoot = findRootLine(bottomLimit, topLimit, y1, y2);

        if(findPointsOnFunc(candidateRoot, equation, numberOfTerms) < 0){
            bottomLimit = candidateRoot;
        }
        else{
            topLimit = candidateRoot;
        }

        double error1 = candidateRoot - bottomLimit;
        double error2 = topLimit - candidateRoot ;

        errorRatio = error1 > error2 ? error1 : error2;
    } while (errorRatio > myErrorRatio);
    
    printf("%lf is root of equation", candidateRoot);

    return 0;
}