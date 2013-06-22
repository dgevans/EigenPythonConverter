#include <eigen3/Eigen/Dense>
#include <iostream>

#include <Python.h>
#include <numpy/arrayobject.h>

#include "NumpyConverter.hpp"
using namespace Eigen;
using namespace std;

typedef Matrix<double,Dynamic,Dynamic,RowMajor> rMatrixXd;


char const* greet()
{
    return "hello, world";
}

MatrixXd testRowMajor(const rMatrixXd &a)
{
    return a;
}

MatrixXd test(const MatrixXd &a)
{
    return a;
}

VectorXd estimate(const Map<rMatrixXd> &X, const Map<VectorXd> &y)
{
    return (X.transpose()*X).ldlt().solve(X.transpose()*y);
}

VectorXd estimate2(PyObject * pyX, PyObject *pyy)
{
    Map<rMatrixXd> X((double*)PyArray_DATA(pyX),10000,4);
    Map<VectorXd> y((double*)PyArray_DATA(pyy),10000);
    return (X.transpose()*X).ldlt().solve(X.transpose()*y);
}

BOOST_PYTHON_MODULE(test_cpp)
{
    Register<MatrixXd>();
    
    Register<rMatrixXd>();
    
    Register<VectorXd>();
    
    using namespace boost::python;
    def("greet", greet);
    def("test",test);
    def("testRowMajor",testRowMajor);
    def("estimate",estimate);
    def("estimate2",estimate2);
}