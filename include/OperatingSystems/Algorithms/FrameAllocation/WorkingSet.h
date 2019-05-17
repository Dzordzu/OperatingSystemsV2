//
// Created by dzordzu on 5/17/19.
//

#ifndef OPERATINGSYSTEMS_ALGORITHMS_FRAMEALLOCATION_WORKINGSET_H
#define OPERATINGSYSTEMS_ALGORITHMS_FRAMEALLOCATION_WORKINGSET_H

#include <vector>
#include <functional>
#include "Algorithm.h"
#include <OperatingSystems/Processor/Processor.h>

namespace OperatingSystems {
    namespace Algorithms {
        namespace FrameAllocation {
            class WorkingSet : public Algorithm {
                std::vector<std::reference_wrapper<Page>> recentPages;
            public:
                void alwaysRun(Page &page) override;
                void allocateFrames() override;
            };
        }
    }
}


#endif //OPERATINGSYSTEMS_ALGORITHMS_FRAMEALLOCATION_WORKINGSET_H
