#include <vector>
#include <cmath>
#include <stdexcept>
#include <iostream>
#define pi_val 3.14159265358979323846 /* value of pi */
#include "int_rule.hpp"

class Polynomial : public ScalarFunction<double> { //class Polynomial derived from ScalarFunction
public:
    explicit Polynomial(std::vector<double> coeffs) : coeffs_(std::move(coeffs)) {} //constructor for the Polynomial class
    
    double operator()(double x) const override {
        double function_x = 0.0;
        for (size_t i = 0; i < coeffs_.size(); ++i) {
            function_x += coeffs_[i] * std::pow(x, i); //f(x_i)=c0+c1*x+c2*x^2+c3*x^3+...+ci*x^i to evaluate the polynomial
                                                   // where ci is the coefficient of the polynomial
                                                   // and i is the degree of the polynomial 
        }
        return function_x;
    }
private:
    std::vector<double> coeffs_; // stores the coefficients of the polynomial [c0,c1,c2,...]
};

int test_constant_function1() {
    auto rule = QuadratureType<double>::gauss_legendre(2); // 2 point gauss legendre rule for a constant function
    Polynomial f({1.0}); // f(x) = 1 is the given function
    double result = rule.integrate(f, 0.0, 1.0); //integral of f(x) from 0 to 1 should give us 1
    return std::abs(result - 1.0) < 1e-6 ? 0 : 1; // error calculation: 0 for passing and 1 for failing
}

int test_constant_function2() { 
    auto rule = QuadratureType<double>::gauss_lobatto(3); // 3 point gauss lobatto rule for a constant function
    Polynomial f({1.0}); // f(x) = 1
    double result = rule.integrate(f, 0.0, 1.0);
    return std::abs(result - 1.0) < 1e-6 ? 0 : 1;
}

int test_constant_function3() {
    auto rule = QuadratureType<double>::chebyshev1(4); // 4 point chebyshev1 rule for a constant function
    Polynomial f({1.0}); // f(x) = 1/sqrt(1-x^2)
    double result = rule.integrate(f, -1.0, 1.0);
    return std::abs(result - pi_val) < 1e-6 ? 0 : 1;
}
int test_constant_function4() {
    auto rule = QuadratureType<double>::chebyshev2(4); // 4 point chebyshev1 rule for a constant function
    Polynomial f({1.0}); // f(x) = 1*sqrt(1-x^2)
    double result = rule.integrate(f, -1.0, 1.0);
    return std::abs(result - pi_val/2.0) < 1e-4 ? 0 : 1; // is not passing
}

int test_linear_function1() {
    auto rule = QuadratureType<double>::gauss_legendre(3); // 3 point gauss legendre rule for a linear function
    Polynomial f({1.0, 1.0}); // f(x) = 1 + x
    double result = rule.integrate(f, 0.0, 1.0);
    return std::abs(result - 3.0/2.0) < 1e-6 ? 0 : 1;
}

int test_linear_function2() { 
    auto rule = QuadratureType<double>::gauss_lobatto(3); // 3 point gauss lobatto rule for a linear function
    Polynomial f({1.0, 1.0}); // f(x) = 1
    double result = rule.integrate(f, 0.0, 1.0);
    return std::abs(result - 3.0/2.0) < 1e-6 ? 0 : 1;
}

int test_linear_function3() {
    auto rule = QuadratureType<double>::chebyshev1(6); // 4 point chebyshev1 rule for a linear function
    Polynomial f({0.0, 1.0}); // f(x) = x/sqrt(1-x^2)
    double result = rule.integrate(f, -1.0, 1.0);
    return std::abs(result - 0.0) < 1e-4 ? 0 : 1; // is not passing
}
int test_linear_function4() {
    auto rule = QuadratureType<double>::chebyshev2(8); // 6 point chebyshev1 rule for a linear function
    Polynomial f({0.0, 1.0}); // f(x) = x*sqrt(1-x^2)
    double result = rule.integrate(f, -1.0, 1.0);
    return std::abs(result - 0.0) < 1e-4 ? 0 : 1; // is not passing
}


int test_quadratic_function1() {
    auto rule = QuadratureType<double>::gauss_legendre(6); // finally 6 point gauss legendre rule for a quadratic function
    Polynomial f({0.0, 0.0, 1.0}); // f(x) = x^2
    double result = rule.integrate(f, 0.0, 1.0);
    return std::abs(result - 1.0/3.0) < 1e-6 ? 0 : 1;
}

int test_quadratic_function2() {
    auto rule = QuadratureType<double>::gauss_lobatto(4); // 4 point gauss lobatto rule for a quadratic function
    Polynomial f({0.0, 0.0, 1.0}); // f(x) = x^2
    double result = rule.integrate(f, 0.0, 1.0);
    return std::abs(result - 1.0/3.0) < 1e-6 ? 0 : 1;
}

int test_quadratic_function3() {
    auto rule = QuadratureType<double>::chebyshev1(8); // 8 point chebyshev1 rule for a quadratic function
    Polynomial f({0.0, 0.0, 1.0}); // f(x) = x^2/sqrt(1-x^2)
    double result = rule.integrate(f, -1.0, 1.0);
    return std::abs(result - pi_val/2.0) < 1e-4 ? 0 : 1; //is not passing
}

int test_quadratic_function4() {
    auto rule = QuadratureType<double>::chebyshev2(8); // 8 point chebyshev2 rule for a quadratic function
    Polynomial f({0.0, 0.0, 1.0}); // f(x) = x^2*sqrt(1-x^2)
    double result = rule.integrate(f, -1.0, 1.0);
    return std::abs(result - pi_val/8.0) < 1e-6 ? 0 : 1; // is not passing
}

int main() {
    double failed = 0.0;
    
    std::cout << "Testing constant function using gauss legendre: ";
    failed = test_constant_function1();
    std::cout << (failed == 0.0 ? "PASSED" : "FAILED") << std::endl;

    std::cout << "Testing constant function using gauss lobato: ";
    failed = test_constant_function2();
    std::cout << (failed == 0.0 ? "PASSED" : "FAILED") << std::endl;

    std::cout << "Testing constant function using chebyshev case 1: ";
    failed = test_constant_function3();
    std::cout << (failed == 0.0 ? "PASSED" : "FAILED") << std::endl;

    std::cout << "Testing constant function using chebyshev case 2: ";
    failed = test_constant_function4();
    std::cout << (failed == 0.0 ? "PASSED" : "FAILED") << std::endl;

    std::cout << "Testing linear function using gauss legendre: ";
    failed = test_linear_function1();
    std::cout << (failed == 0.0 ? "PASSED" : "FAILED") << std::endl;

    std::cout << "Testing linear function using gauss lobato: ";
    failed = test_linear_function2();
    std::cout << (failed == 0.0 ? "PASSED" : "FAILED") << std::endl;

    std::cout << "Testing linear function using chebyshev case 1: ";
    failed = test_linear_function3();
    std::cout << (failed == 0.0 ? "PASSED" : "FAILED") << std::endl;

    std::cout << "Testing linear function using chebyshev case 2: ";
    failed = test_linear_function4();
    std::cout << (failed == 0.0 ? "PASSED" : "FAILED") << std::endl;
    
    std::cout << "Testing quadratic function using the legendre rule: ";
    failed = test_quadratic_function1();
    std::cout << (failed == 0.0 ? "PASSED" : "FAILED") << std::endl;

    std::cout << "Testing quadratic function using the lobatto rule: ";
    failed = test_quadratic_function2();
    std::cout << (failed == 0.0 ? "PASSED" : "FAILED") << std::endl;

    std::cout << "Testing quadratic function using the chebyshev case 1: ";
    failed = test_quadratic_function3();
    std::cout << (failed == 0.0 ? "PASSED" : "FAILED") << std::endl;

    std::cout << "Testing quadratic function using the chebyshev case 2 ";
    failed = test_quadratic_function4();
    std::cout << (failed == 0.0 ? "PASSED" : "FAILED") << std::endl;
    
    return failed;
}
