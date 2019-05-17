//
// Created by dzordzu on 5/17/19.
//

#ifndef OPERATINGSYSTEMS_ALGORITHMS_FRAMEALLOCATION_PROPORTIONAL_H
#define OPERATINGSYSTEMS_ALGORITHMS_FRAMEALLOCATION_PROPORTIONAL_H

#include <cmath>
#include "Algorithm.h"
#include <OperatingSystems/Processor/Processor.h>

namespace OperatingSystems {
    namespace Algorithms {
        namespace FrameAllocation {

            class Proportional : public Algorithm {
            public:
                void allocateFrames() override;
            };


        }
    }
}


#endif //OPERATINGSYSTEMS_ALGORITHMS_FRAMEALLOCATION_PROPORTIONAL_H
