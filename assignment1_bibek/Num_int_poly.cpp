#include <vector>
#include <cmath>
#include <stdexcept>
#include <iostream>
#include <sstream>
#define pi_val 3.14159265358979323846 /* value of pi */
#include "int_rule.hpp"

class Polynomial : public ScalarFunction<double> { //class Polynomial derived from ScalarFunction
public:
    explicit Polynomial(std::vector<double> coeffs) : coeffs_(std::move(coeffs)) {} //constructor for the Polynomial class
    
    double operator()(double x) const override { //overriding the operator() function from the base class
        double result = 0.0;
        for (size_t i = 0; i < coeffs_.size(); ++i) {
            result += coeffs_[i] * std::pow(x, i); //f(x_i)=c0+c1*x+c2*x^2+c3*x^3+...+ci*x^i to evaluate the polynomial
                                                   // where ci is the coefficient of the polynomial
                                                   // and i is the degree of the polynomial 
        }
        return result;
    }
private:
    std::vector<double> coeffs_;
};

int main(int argc, char* argv[]) {
    try {
        std::vector<double> coeffs;
        double coeff;
        int degree;
        
        std::cout << "Enter the degree of the polynomial: ";
        std::cin >> degree;
        
        std::cout << "Enter polynomial coefficients: in order of c0 c1 c2 for a c0+c1*x+c2*x^2 polynomial type\n";
        for (int i=0; i<=degree; ++i) {
            std::cin >> coeff;
            coeffs.push_back(coeff); // storing the coefficients in the vector
        }
        
        double a, b;
        std::cout << "Enter integration limits (a b): ";
        std::cin >> a;
        std::cin >> b;

        unsigned int n;
        std::cout << "Enter the type of quadrature rule you want to use: \n 1. Gauss Legendre \n 2. Gauss Lobatto \n 3. Chebyshev case 1 \n 4. Chebyshev case 2 \n";
        std::cin >> n;

        unsigned int d;
        std::cout << "number of sampling points \n";
        std::cin >> d;
        if (n ==1) {
            auto rule = QuadratureType<double>::gauss_legendre(d);
            std::cout << "Gauss Legendre rule selected with " << d << " sampling points \n";
            Polynomial p(coeffs);
            double result = rule.integrate(p, a, b);
            std::cout << "Integral result: " << result << std::endl;
        }
        else if (n == 2) {
            auto rule = QuadratureType<double>::gauss_lobatto(d);
            std::cout << "Gauss Lobatto rule selected with " << d << " sampling points \n";
            Polynomial p(coeffs);
            double result = rule.integrate(p, a, b);
            std::cout << "Integral result: " << result << std::endl;
        }
        else if (n == 3) {
            auto rule = QuadratureType<double>::chebyshev1(d);
            std::cout << "Chebyshev case1 rule selected with " << d << " sampling points \n";
            Polynomial p(coeffs);
            double result = rule.integrate(p, a, b);
            std::cout << "Integral result: " << result << std::endl;
        }
        else if (n == 4) {
            auto rule = QuadratureType<double>::chebyshev2(d);
            std::cout << "Chebyshev case2 rule selected with " << d << " sampling points \n";
            std::cout << "Chebyshev case2 is still a work in process :-( \n";
            Polynomial p(coeffs);
            double result = rule.integrate(p, a, b);
            std::cout << "Integral result: " << result << std::endl;
        }
        else {
            throw std::invalid_argument("Invalid quadrature rule type selected \n");
        }
        return 0;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
}
