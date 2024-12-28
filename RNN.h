#pragma once

#include "matrix.h"
#include <vector>

class RNN {
    private:
        unsigned int inputDimension_;
        unsigned int hiddenDimension_;
        unsigned int outputDimension_;

        Matrix weightsX_;
        Matrix weightsH_;
        Matrix weightsY_;  
        Matrix hiddenState_;

    public:
        RNN(unsigned int inputDimension, 
                unsigned int hiddenDimension, 
                unsigned int outputDimension) : 
                inputDimension_{inputDimension},
                hiddenDimension_{hiddenDimension},
                outputDimension_{outputDimension} {
            weightsX_ = Matrix{hiddenDimension, inputDimension};
            weightsH_ = Matrix{hiddenDimension, hiddenDimension};
            weightsY_ = Matrix{outputDimension, hiddenDimension};
            hiddenState_ = Matrix{hiddenDimension, 1};
        }

        void set_weights( const std::vector<double>& weightsX, const std::vector<double>& weightsH, const std::vector<double>& weightsY ) {
            weightsX_.set_all( weightsX );
            weightsH_.set_all( weightsH );
            weightsY_.set_all( weightsY );
        }

        std::vector<Matrix> forward( const std::vector<Matrix>& inputs, bool verbose = false );
};