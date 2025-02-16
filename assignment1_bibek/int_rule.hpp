#ifndef INT_RULE_H
#define INT_RULE_H

#include <vector>
#include <cmath>
#include <stdexcept>
#include <iostream>
// #define pi_val 3.14159265358979323846 /* value of pi */

template<typename T>
class ScalarFunction {
    public:
    /**
     * @brief Pure virtual function to evaluate the scalar function at a given point
     * 
     * Assumptions:
     * - The function is defined for all numbers of type T
     * - The function is continuous and differentiable on the interval [a, b]
     * - The function takes-in position x and returns operator()
     */
    virtual T operator()(T x) const = 0;    // pure virtual function for the base class
    virtual ~ScalarFunction() = default;    // destructor for proper memory clean up
};

template<typename T>
class IntegrationRule {
    public:
    /**
     * @brief Construction of a new integration rule
     * @param weights The weights of the integration rule
     * @param points The points of the sampling locations
     */
    IntegrationRule(const std::vector<T>& weights, const std::vector<T>& points) 
    : weights_(weights), points_(points) {
        if (weights.size() != points.size()) {
            throw std::invalid_argument("The number of weights and points must be the same");
        }
    }

    /**
     * @brief Evaluate the integral of a scalar function
     * @param f The scalar function to integrate
     * @param a The lower bound of the integral
     * @param b The upper bound of the integral
     * @return The integral of the function
     */
    T integrate(const ScalarFunction<T>& f, T a, T b) const {
        // To transform the integral from [-1,1] to [a,b] using linear mapping
        T half_length = (b - a) / 2;
        T mid_point = (b + a) / 2;
        T integral = T{0};
        for (size_t i = 0; i < weights_.size(); i++) {
            integral += weights_[i] * f(half_length * points_[i] + mid_point);
        }
        return half_length * integral;
    }
    private:
    std::vector<T> weights_;
    std::vector<T> points_;
};

template<typename T>
class QuadratureType{
    public:
    // Calling the type of quadrature weights and the number of points
    static IntegrationRule<T> gauss_legendre(unsigned int n){
        switch(n) {
            case 1: 
                return IntegrationRule<T>{ {T{2}}, {T{0}} };
            case 2:
                return IntegrationRule<T>{ {T{1}, T{1}}, {T{-1/std::sqrt(T{3})}, T{1/std::sqrt(T{3})}} };
            case 3:
                return IntegrationRule<T>{ {T{5}/T{9}, T{8}/T{9}, T{5}/T{9}}, {T{-std::sqrt(T{3})/T{5}},
                T{0}, T{std::sqrt(T{3})/T{5}}} };
            case 4:
                return IntegrationRule<T>{ {T{(18+std::sqrt(T{30}))/T{36}}, T{(18+std::sqrt(T{30}))/T{36}}, 
                T{(18-std::sqrt(T{30}))/T{36}}, T{(18-std::sqrt(T{30}))/T{36}}}, {T{-std::sqrt(T{3})/T{7-std::sqrt(T{3})/T{7}}},
                 T{std::sqrt(T{3})/T{7-std::sqrt(T{3})/T{7}}}, T{-std::sqrt(T{3})/T{7+std::sqrt(T{3})/T{7}}}, T{std::sqrt(T{3})/T{7+std::sqrt(T{3})/T{7}}}} };
            case 5:
                return IntegrationRule<T>{ {T{128}/T{225}, T{(322+13*std::sqrt(T{70}))/T{900}}, T{512}/T{225}, 
                T{(322-13*std::sqrt(T{70}))/T{900}}, T{128}/T{225}}, {T{0}, T{-std::sqrt(T{5-2*std::sqrt(T{10})/T{15}})}, 
                T{-std::sqrt(T{5+2*std::sqrt(T{10})/T{15}})}, T{std::sqrt(T{5+2*std::sqrt(T{10})/T{15}})}, 
                T{std::sqrt(T{5-2*std::sqrt(T{10})/T{15}})}} };
            case 6: 
                return IntegrationRule<T>{ {T{0.4679139346}, T{0.3607615730}, T{0.1713244924}, T{0.1713244924}, T{0.3607615730}, T{0.4679139346}}, 
                {T{-0.2386191861}, T{-0.6612093865}, T{-0.9324695142}, T{0.9324695142}, T{0.6612093865}, T{0.2386191861}} };
            default:
                throw std::invalid_argument("Unsupported number of points");
        }
    }

    static IntegrationRule<T> gauss_lobatto(unsigned int n){
        switch(n) {
            case 3:
                return IntegrationRule<T>{ {T{1}/T{3}, T{4}/T{3}, T{1}/T{3}}, {T{-1}, T{0}, T{1}} }; 
            case 4:
                return IntegrationRule<T>{ {T{1}/T{6}, T{5}/T{6}, T{5}/T{6}, T{1}/T{6}}, {T{-1}, 
                T{-T{1}/std::sqrt(T{5})}, T{T{1}/std::sqrt(T{5})}, T{1}} };
            case 5:
                return IntegrationRule<T>{ {T{1}/T{10}, T{49}/T{90}, T{32}/T{45}, T{49}/T{90}, T{1}/T{10}}, {T{-1}, 
                T{-T{1}/std::sqrt(T{21})}, T{0}, T{T{1}/std::sqrt(T{21})}, T{1}} };
            default:
                throw std::invalid_argument("Unsupported number of points");
        }
    }

    static IntegrationRule<T> chebyshev1(double n){
        std::vector<T> weights(n, T{0});
        std::vector<T> points(n, T{0});
        for (size_t i = 0; i < n; i++) {
            weights[i] = M_PI/ n;
            points[i] = std::cos((2*i-1.0 * M_PI) / (2*n));
        } // Taking the first case for the chebyshev-gauss quadrature rule
        return IntegrationRule<T>{weights, points};
    }

    static IntegrationRule<T> chebyshev2(double n){
        std::vector<T> weights(n, T{0});
        std::vector<T> points(n, T{0});
        for (size_t i = 0; i < n; i++) {
            weights[i] = (M_PI/(n+1.0))*std::sin((i*M_PI)/(n+1.0))*std::sin((i*M_PI)/(n+1.0));
            points[i] = std::cos((i * M_PI) / (n+1.0));
        } // Taking the second case for the chebyshev-gauss quadrature rule
        return IntegrationRule<T>{weights, points};
    }
};

#endif
