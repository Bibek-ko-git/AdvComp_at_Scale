#ifndef MM_MV_PRODUCT_H
#define MM_MV_PRODUCT_H

#include <vector>

std::vector<std::vector<double>> M_M_Product(const std::vector<std::vector<double>>& matrixA, const std::vector<std::vector<double>>& matrixB);
std::vector<double> M_V_Product(const std::vector<std::vector<double>>& matrixA, const std::vector<double>& vectorC);

#endif
