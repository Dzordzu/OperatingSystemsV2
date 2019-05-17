//
// Created by dzordzu on 5/17/19.
//

#ifndef OPERATINGSYSTEMS_ALGORITHMS_FRAMEALLOCATION_ERRORSCONTROLLING_H
#define OPERATINGSYSTEMS_ALGORITHMS_FRAMEALLOCATION_ERRORSCONTROLLING_H

#include "Algorithm.h"
#include <OperatingSystems/Processor/Processor.h>
#include <map>

namespace OperatingSystems {
    namespace Algorithms {
        namespace FrameAllocation {
            class ErrorsControlling : public Algorithm {
                std::map<Process *, int> errors;
                double min = 0.2;
                double max = 0.8;
            public:
                void pageError(Page &page) override;
                void allocateFrames() override;
                void setMin(double min);
                void setMax(double max);
            };
        }
    }
}


#endif //OPERATINGSYSTEMS_ALGORITHMS_FRAMEALLOCATION_ERRORSCONTROLLING_H
