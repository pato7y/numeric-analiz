#include <stdexcept>
#include <cmath> 
#include <iostream> 

using namespace std;

//this is the decleration of function that will solve problem with bisection method
double bisectionFunction(double (*f)(double), double a, double b, double tol = 1e-6, int maxIteration = 10) {
    
    if (f(a) * f(b) >= 0) {
        throw invalid_argument("Root must be within the interval.");
    }

    int counter=0; // counter to count the iteration
    
    while ((abs(b-a)/2 > tol)   && (counter < maxIteration)) {
        double c=(a+b)/2;
       //finding new root and updating the boundaries of the roots and checking new root
        if (f(c)==0) {
            return c; 
        } else if (f(a) * f(c) < 0) {
            b=c; 
        } else {
            a=c; 
        }
        counter++; 
    }
    return (a+b)/2; 
}

// sample funtion that is given by me by default  also this part may be updated later 
double func(double x) {
    return x * x * x - x * x -4-x;
}


int main() {
    // also this part may be updated later 

        double root = bisectionFunction(func, -2, 2); 
        cout << " root: " << root << endl; 
   
       

    return 0;
}
