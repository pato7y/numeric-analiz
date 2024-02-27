#include <stdexcept>
#include <cmath> 
#include <iostream> // Added to use cout

using namespace std;

,
double bisectionFunction(double (*f)(double), double a, double b, double tol = 1e-6, int maxIteration = 10) {
    
    if (f(a) * f(b) >= 0) {
        throw invalid_argument("Root must be within the interval.");
    }

    int counter=0;
    
    while ((abs(b-a)/2 > tol)   && (counter < maxIteration)) {
        double c=(a+b)/2;
       
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

// sample funtion 
double func(double x) {
    return x * x * x - x * x + 2;
}


int main() {
    try {
        double root = bisectionFunction(func, -2, 2); 
        cout << " root: " << root << endl; 
    } catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << endl; 
    }

    return 0;
}
