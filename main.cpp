#include <iostream>
#include "matrix.h"
#include "RNN.h"
#include <vector>

int main() {
    const unsigned int _inputDimension{1};
    const unsigned int _hiddenDimension{2};
    const unsigned int _outputDimension{1};

    RNN  _rnn{_inputDimension, _hiddenDimension, _outputDimension};
    _rnn.set_weights( { 1, 2 }, { 1, -1, 1, 1 }, { -1, 1 });

    std::vector<Matrix> _input;
    _input.push_back(Matrix(_inputDimension, 1, { 3 }));
    _input.push_back(Matrix(_inputDimension, 1, { 4 })); 
    _input.push_back(Matrix(_inputDimension, 1, { 5 }));
    _input.push_back(Matrix(_inputDimension, 1, { 6 })); 

    std::vector _output = _rnn.forward( _input, true );

    std::cout << "Outputs:" << std::endl;
    for (unsigned int _i = 0; _i < _output.size(); _i++) {
        _output[_i].print(std::cout);
    }

    return 0;
}
