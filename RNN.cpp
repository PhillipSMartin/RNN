#include "RNN.h"    

std::vector<Matrix> RNN::forward( const std::vector<Matrix>& inputs, bool verbose /* = false*/ ) {
    std::vector<Matrix> _outputs;

    // WXH = [WX, WH]
    Matrix _weightsXH = weightsX_.append_columnwise( weightsH_ );
    if (verbose) {
        std::cout << "WeightsXH:" << std::endl;
        _weightsXH.print(std::cout);
        std::cout << "WeightsY:" << std::endl;
        weightsY_.print(std::cout);
    }

    int _step = 0;
    for (const Matrix& _input : inputs) {
        if (verbose) {
            std::cout << "Input to step " << _step++ << ":\n" << "X =" << std::endl;
            _input.print(std::cout);
            std::cout << "H =" << std::endl;
            hiddenState_.print(std::cout);
        }

        // XH = [X, H]
        // H = ReLU( WXH * XH )   
        Matrix _XH = _input.append_rowwise( hiddenState_ );
        hiddenState_ = Matrix::ReLU( _weightsXH * _XH );
        if (verbose) {
            std::cout << "New hidden state:" << std::endl;
            hiddenState_.print(std::cout);
        }

        // Y = WYH * H
        _outputs.push_back( weightsY_ * hiddenState_ );
        if (verbose) {
            std::cout << "Output:" << std::endl;
            _outputs.back().print(std::cout);
        }
    } 
    return _outputs;
}

