#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// Function to find the x-intercept (root) of a line passing through two points (x1, y1) and (x2, y2)
double findRootLine(double x1, double x2, double y1, double y2) {
    // Prevent division by zero when x1 == x2
    if (x1 == x2) {
        printf("Error: Division by zero detected. x1 and x2 must be different.\n");
        exit(EXIT_FAILURE);
    }
    
    // Calculate the slope of the line
    double slope = (y2 - y1) / (x2 - x1);
    // Calculate the y-intercept of the line
    double fixedNumber = y1 - slope * x1;
    // Compute and return the x-value where y = 0 (root)
    return -fixedNumber / slope;
}

// Function to evaluate the polynomial equation at a given x value
double findPointsOnFunc(double x, double equation[], int size) {
    double y = 0;  // Initialize y (function output)

    // Loop through polynomial terms and calculate y = f(x)
    for (int i = 0; i < size; i++) {
        y += pow(x, size - i - 1) * equation[i];  // Multiply coefficient by x^(degree-i)
    }

    return y;  // Return function value at x
}

int main() {
    system("cls");  // Clear the console screen (Windows-specific, optional)

    int numberOfTerms;  // Number of terms in the polynomial equation
    printf("Enter the number of terms (Based on max degree): ");
    scanf("%d", &numberOfTerms);

    // Allocate memory dynamically for equation coefficients
    double *equation = (double *)malloc(numberOfTerms * sizeof(double));
    if (equation == NULL) {
        printf("Error: Memory allocation failed.\n");
        return EXIT_FAILURE;
    }

    // Get polynomial coefficients from the user
    for (int i = 0; i < numberOfTerms; i++) {
        printf("Enter coefficient for x^%d: ", numberOfTerms - i - 1);
        scanf("%lf", &equation[i]);
    }
    
    double bottomLimit, topLimit;  // Define the interval for root finding
    printf("Enter first point: ");
    scanf("%lf", &bottomLimit);
    printf("Enter second point: ");
    scanf("%lf", &topLimit);

    double myErrorRatio;  // Error tolerance
    printf("Enter error ratio: ");
    scanf("%lf", &myErrorRatio);

    double errorRatio = 1.0;  // Initialize error ratio
    double candidateRoot;  // Variable to store the computed root

    // Start the Regula Falsi (False Position) Method loop
    do {
        // Evaluate function values at given points
        double y1 = findPointsOnFunc(bottomLimit, equation, numberOfTerms); 
        double y2 = findPointsOnFunc(topLimit, equation, numberOfTerms); 

        // Check if the function values have opposite signs (ensuring a root exists)
        if (y1 * y2 >= 0) { 
            printf("Error: No sign change detected. Root finding may not be reliable.\n");
            free(equation);
            return EXIT_FAILURE;
        }

        // Compute the candidate root using the false position method
        candidateRoot = findRootLine(bottomLimit, topLimit, y1, y2);

        // Check which half of the interval to keep based on function signs
        if (findPointsOnFunc(candidateRoot, equation, numberOfTerms) * y1 < 0) {
            // Root is between bottomLimit and candidateRoot
            topLimit = candidateRoot;
        } else {
            // Root is between candidateRoot and topLimit
            bottomLimit = candidateRoot;
        }

        // Compute error margin
        double error1 = fabs(candidateRoot - bottomLimit);
        double error2 = fabs(topLimit - candidateRoot);
        errorRatio = fmax(error1, error2);  // Select the maximum error

    } while (errorRatio > myErrorRatio);  // Continue iteration until error is small enough
    
    // Display the final computed root
    printf("Root of the equation: %lf\n", candidateRoot);

    // Free allocated memory to avoid memory leaks
    free(equation);
    return 0;
}
