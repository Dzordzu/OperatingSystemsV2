//
// Created by dzordzu on 5/16/19.
//

#ifndef OPERATINGSYSTEMS_PROCESSOR_PROCESS_H
#define OPERATINGSYSTEMS_PROCESSOR_PROCESS_H


#include <OperatingSystems/Algorithms/FrameAllocation/Algorithm.h>
#include <OperatingSystems/Algorithms/PageReplacement/Algorithm.h>
#include <OperatingSystems/Algorithms/PageReplacement/LRU.h>
#include <string>
#include <vector>

#include "Frame.h"
#include "ErrorCounter.h"

#include <stdexcept>



namespace OperatingSystems {

    namespace Algorithms {
        namespace FrameAllocation {
            class ErrorsControlling;
        }
    }

    namespace Processor {


        class Process {
            using PagesAlgorithm = OperatingSystems::Algorithms::PageReplacement::Algorithm;
            using FramesAlgorithm = OperatingSystems::Algorithms::FrameAllocation::Algorithm;
            using ErrorsControlling = OperatingSystems::Algorithms::FrameAllocation::ErrorsControlling;
            friend Page;
            friend FramesAlgorithm;

            PagesAlgorithm * pageAlgorithm;
            std::string name;
            std::vector<Frame> frames;
            uint_fast32_t weight = 0;

            ErrorCounter * errorCounter = nullptr;

            /*
             * @XXX Dangerous zone: to fix conceptually
             */
            friend ErrorsControlling;
            int errors = 0;


        public:
            explicit Process(const std::string &name, int framesAmount, PagesAlgorithm *pageAlgorithm);
            const std::string &getName() const;
            bool resolvePage(Page &page);
            int getFramesAmount() const;
            uint_fast32_t getWeight() const;
            void setCounter(ErrorCounter *counter);
        };
    }

}


#endif //OPERATINGSYSTEMS_PROCESSOR_PROCESS_H
