#include <array>
#include <iostream>
#include "include/constexpr_vmult_inverse.h"
#include "include/constexpr_quadrature.h"
#include "include/polynomialbasis/constexpr_lagrange.h"

template <typename Number, size_t size>
constexpr_array<Number, size> create_vector()
{
    constexpr_array<Number, size> arr{1.};
    for (unsigned int i = 0; i < size; ++i)
        arr[i] = i;
    return arr;
}

template <typename Number, size_t size>
constexpr_array<constexpr_array<Number, size>, size> create_array()
{
    constexpr_array<constexpr_array<Number, size>, size> arr;
    for (unsigned int i = 0; i < size; ++i)
        for (unsigned int j = 0; j < size; ++j)
            arr[i][j] = 10^i;
    return arr;
}


int main() {
	// Initialize VMULT
	constexpr size_t order = 3;
	constexpr size_t q_order = 3;
	VMULT_INVERSE<long double, order, q_order, Quadrature , Lagrange > vmult;

	// Compute VMULT Mass Matrix
	constexpr_array < constexpr_array < long double, order + 1 >, order + 1 > u_1 = create_array < long double, order + 1 > ();
	constexpr_array < constexpr_array < long double, order + 1 >, order + 1 > y_mass = create_array < long double, order + 1 > ();
	vmult.mass(y_mass, u_1);

	for (unsigned int i = 0; i < order + 1; i++) {
		for (unsigned int j = 0; j < order + 1; j++) {
			std::cout << y_mass[i][j] << std::endl;
		}
	}

	return 0;
}