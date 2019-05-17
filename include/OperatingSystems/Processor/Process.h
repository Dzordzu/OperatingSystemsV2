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

#include <stdexcept>



namespace OperatingSystems {

    namespace Processor {


        class Process {
            using PagesAlgorithm = OperatingSystems::Algorithms::PageReplacement::Algorithm;
            using FramesAlgorithm = OperatingSystems::Algorithms::FrameAllocation::Algorithm;
            friend Page;
            friend FramesAlgorithm;

            PagesAlgorithm * pageAlgorithm;
            std::string name;
            std::vector<Frame> frames;
            uint_fast32_t weight = 0;


        public:
            explicit Process(const std::string &name, int framesAmount, PagesAlgorithm *pageAlgorithm);
            const std::string &getName() const;
            bool resolvePage(Page &page);
            int getFramesAmount();
            uint_fast32_t getWeight() const;

            bool operator<(Process const &process);
        };
    }

}


#endif //OPERATINGSYSTEMS_PROCESSOR_PROCESS_H
