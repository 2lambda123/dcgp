#include <random>
#include <vector>
#define BOOST_TEST_MODULE dcgp_compute_test
#include <boost/test/unit_test.hpp>

#include <dcgp/expression.hpp>
#include <dcgp/kernel_set.hpp>


#include "helpers.hpp"

using namespace dcgp;

BOOST_AUTO_TEST_CASE(compute)
{
    // Random seed
    std::random_device rd;

    kernel_set<double> basic_set({"sum", "diff", "mul", "div"});

    /// Testing over Miller's test case from the PPSN 2014 tutorial
    expression<double> ex1(2, 4, 2, 3, 4, 2, basic_set(), rd());
    ex1.set({0, 0, 1, 1, 0, 0, 1, 3, 1, 2, 0, 1, 0, 4, 4, 2, 5, 4, 2, 5, 7, 3});

    CHECK_EQUAL_V(ex1({1., -1.}), std::vector<double>({0, -1, -1, 0}));
    CHECK_CLOSE_V(ex1({-.123, 2.345}), std::vector<double>({2.222, -0.288435, 0.676380075, 0}), 1e-8);

    ex1.set({0, 0, 1, 1, 0, 0, 1, 3, 1, 2, 0, 1, 0, 4, 4, 2, 5, 4, 6, 5, 7, 3});
    CHECK_EQUAL_V(ex1({2., -3.}), std::vector<double>({6, -6, -18, 0}));
    CHECK_EQUAL_V(ex1({1., -1.}), std::vector<double>({2, -1, -1, 0}));
    CHECK_CLOSE_V(ex1({-.123, 2.345}), std::vector<double>({-4.69, -0.288435, 0.676380075, 0}), 1e-8);

    /// Testing over a single row program
    dcgp::expression<double> ex2(4, 1, 1, 10, 10, 2, basic_set(), rd());
    ex2.set({2, 3, 0, 0, 2, 2, 3, 0, 1, 1, 5,  4, 2, 6, 1, 0,
             7, 7, 3, 6, 7, 1, 7, 6, 2, 4, 10, 2, 3, 2, 10}); ///(x/y)/(2z-(t*x))
    CHECK_CLOSE_V(ex2({2., 3., 4., -2.}), std::vector<double>({0.055555555555555552}), 1e-8);
    CHECK_EQUAL_V(ex2({-1., 1., -1., 1.}), std::vector<double>({1}));
}

BOOST_AUTO_TEST_CASE(check_bounds)
{
    // Random seed
    std::random_device rd;

    kernel_set<double> basic_set({"sum", "diff", "mul", "div"});

    // Testing an expression with arity 3, levels-back 2
    expression<double> ex(3, 1, 2, 3, 2, 3, basic_set(), rd());

    CHECK_EQUAL_V(ex.get_lb(), std::vector<unsigned int>(
                                   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 0, 3, 3, 3, 5}));
    CHECK_EQUAL_V(ex.get_ub(), std::vector<unsigned int>(
                                   {3, 2, 2, 2, 3, 2, 2, 2, 3, 4, 4, 4, 3, 4, 4, 4, 3, 6, 6, 6, 3, 6, 6, 6, 8}));
}
