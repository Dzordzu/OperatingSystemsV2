//
// Created by dzordzu on 5/17/19.
//

#ifndef OPERATINGSYSTEMS_ALGORITHMS_FRAMEALLOCATION_ERRORSCONTROLLING_H
#define OPERATINGSYSTEMS_ALGORITHMS_FRAMEALLOCATION_ERRORSCONTROLLING_H

#include "Algorithm.h"
#include <OperatingSystems/Processor/Processor.h>
#include <map>
#include <algorithm>

namespace OperatingSystems {
    namespace Algorithms {
        namespace FrameAllocation {
            class ErrorsControlling : public Algorithm {
                double min = 0.2;
                double max = 0.9;
                double stepReduction = 0.2; //relative to process->frames
                int guaranteedStepAddition = 50;
                double stepAddition = 0.1; // relative to (process->frames) [after guaranteed step]
            public:
                void pageError(Page &page) override;
                void allocateFrames() override;

                void setMin(double min);
                void setMax(double max);

                void setStepReduction(double stepReduction);
                void setGuaranteedStepAddition(int guaranteedStepAddition);
                void setStepAddition(double stepAddition);
            };
        }
    }
}


#endif //OPERATINGSYSTEMS_ALGORITHMS_FRAMEALLOCATION_ERRORSCONTROLLING_H
