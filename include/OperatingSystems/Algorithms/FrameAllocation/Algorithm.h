//
// Created by dzordzu on 5/17/19.
//

#ifndef OPERATINGSYSTEMS_ALGORITHMS_FRAMEALLOCATION_ALGORITHM_H
#define OPERATINGSYSTEMS_ALGORITHMS_FRAMEALLOCATION_ALGORITHM_H

#include <OperatingSystems/Processor/Page.h>
#include <OperatingSystems/Processor/Frame.h>
#include <vector>
#include <functional>

namespace OperatingSystems {

    namespace Processor { class Process; class Processor;}

    namespace Algorithms {
        namespace FrameAllocation {

            using OperatingSystems::Processor::Processor;
            using OperatingSystems::Processor::Process;
            using OperatingSystems::Processor::Page;
            using OperatingSystems::Processor::Frame;

            class Algorithm {
            protected:
                friend Processor;
                Processor * processor;
                void setFramesAmount(Process &process, int amount);
                std::vector<std::reference_wrapper<Process>> & getProcesses();
            public:
                Algorithm() = default;
                virtual void allocateFrames() = 0;
                virtual void pageError(Page & page) {};
            };


        }
    }
}



#endif //OPERATINGSYSTEMS_ALGORITHMS_FRAMEALLOCATION__ALGORITHM_H
