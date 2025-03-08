# Linear Interpolation in C

This repository contains an implementation of the **Linear Interpolation Method** in C for approximating function values between two known data points.

## 📌 Features
- Allows user to input polynomial equations dynamically.
- Implements **Linear Interpolation** for estimating function values.
- Customizable **error ratio** for precise approximations.
- Efficient and easy-to-use approach for interpolation problems.

## 📥 Installation & Usage
1. Clone this repository:
   ```sh
   git clone https://github.com/1230505039/Linear-Interpolation.git
   cd Linear-Interpolation
   ```
2. Compile the program:
   ```sh
   gcc -o lineerInterpolation lineerInterpolation.c -lm
   ```
3. Run the program:
   ```sh
   ./lineerInterpolation
   ```
4. Follow the prompts to enter:
   - The number of terms (based on polynomial degree)
   - Coefficients of the polynomial
   - Two data points for interpolation
   - Error ratio (optional)

## 🧮 How It Works
### Linear Interpolation Method
1. Given two points **(x1, y1)** and **(x2, y2)**, it finds the equation of the line passing through these points.
2. Uses the formula:
   
   	\[ y = y1 + \frac{(x - x1) (y2 - y1)}{(x2 - x1)} \]
   
   to compute the estimated value at any given x.
3. Iterates until the approximation is within the given error margin.
4. Returns the estimated value of the function.

## 📝 Example Input/Output
```
Enter the number of terms (Based on max degree): 3
Enter coefficient for x^2: 1
Enter coefficient for x^1: -3
Enter coefficient for x^0: 2
Enter first point (x1): 1
Enter second point (x2): 3

Estimated function value at x=2: 1.500000
```

## 💡 Why Use This?
- Ideal for **numerical methods** learners & students.
- Helps understand **interpolation techniques**.
- Demonstrates **function evaluation and error handling** in C.
- Useful for estimating missing data values in datasets.

## 🤝 Contributing
Feel free to fork this repo and submit pull requests! Suggestions and improvements are welcome. 🚀

## 📜 License
This project is **open-source** under the MIT License.

---
**Author:** Umutcan Oğuz  
**GitHub Repository:** [Linear-Interpolation](https://github.com/1230505039/Linear-Interpolation)

