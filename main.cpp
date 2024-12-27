#include <iostream>
#include "matrix.h"
#include <vector>

int main() {
    unsigned int _inputDimension = 1;
    unsigned int _outputDimension = 1;
    unsigned int _hiddenDimension = 2;
    unsigned int _numInputs  = 4;

    std::vector<Matrix> _input;
    _input.push_back(Matrix(_inputDimension, 1, new double[] { 3 }));
    _input.push_back(Matrix(_inputDimension, 1, new double[] { 4 })); 
    _input.push_back(Matrix(_inputDimension, 1, new double[] { 5 }));
    _input.push_back(Matrix(_inputDimension, 1, new double[] { 6 })); 

    Matrix _hiddenState(_hiddenDimension, 1, new double[] { 0, 0 });

    std::vector<Matrix> _output;

    Matrix _weightsX(_hiddenDimension, _inputDimension, new double[] { 1, 2 });
    Matrix _weightsH(_hiddenDimension, _hiddenDimension, new double[] { 1, -1, 1, 1 });
    Matrix _weightsY(_outputDimension, _hiddenDimension, new double[] { -1, 1 });

    Matrix _weightsXH = _weightsX.append_columnwise( _weightsH );

    std::cout << "Inputs:" << std::endl;
    for (unsigned int _i = 0; _i < _input.size(); _i++) {
        _input[_i].print(std::cout);
    }
    std::cout << "WeightsXH:" << std::endl;
    _weightsXH.print(std::cout);
    std::cout << "WeightsY:" << std::endl;
    _weightsY.print(std::cout);

    for (unsigned int _i = 0; _i < _numInputs; _i++) {
        std::cout << "Input to step " << _i << ":" << std::endl;
        Matrix _XH = _input[_i].append_rowwise( _hiddenState );
        _XH.print(std::cout);
 
        _hiddenState = Matrix::ReLU( _weightsXH * _XH );
        std::cout << "New hidden state:" << std::endl;
        _hiddenState.print(std::cout);

        _output.push_back( _weightsY * _hiddenState );
    }

    std::cout << "Output:" << std::endl;
    for (unsigned int _i = 0; _i < _output.size(); _i++) {
        _output[_i].print(std::cout);
    }

    return 0;
}
