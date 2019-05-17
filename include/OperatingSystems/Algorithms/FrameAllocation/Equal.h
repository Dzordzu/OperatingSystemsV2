//
// Created by dzordzu on 5/17/19.
//

#ifndef OPERATINGSYSTEMS_ALGORITHMS_FRAMEALLOCATION_EQUAL_H
#define OPERATINGSYSTEMS_ALGORITHMS_FRAMEALLOCATION_EQUAL_H

#include "Algorithm.h"
#include <OperatingSystems/Processor/Processor.h>

namespace OperatingSystems {
    namespace Algorithms {
        namespace FrameAllocation {

            class Equal : public Algorithm {
            public:
                void allocateFrames() override;
            };


        }
    }
}


#endif //OPERATINGSYSTEMS_ALGORITHMS_FRAMEALLOCATION_EQUAL_H
