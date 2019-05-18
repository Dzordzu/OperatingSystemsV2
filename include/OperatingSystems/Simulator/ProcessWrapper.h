//
// Created by dzordzu on 5/18/19.
//

#ifndef OPERATINGSYSTEMS_ALGORITHMS_FRAMEALLOCATION_PROCESSWRAPPER_H
#define OPERATINGSYSTEMS_ALGORITHMS_FRAMEALLOCATION_PROCESSWRAPPER_H

#include <memory>
#include <OperatingSystems/Processor/Processor.h>

namespace OperatingSystems {
    namespace Simulator {


        class ProcessWrapper {
            using Algorithm = OperatingSystems::Algorithms::PageReplacement::LRU;
            using Process = OperatingSystems::Processor::Process;

            std::unique_ptr<Algorithm> algorithm;
            std::unique_ptr<Process> process;

        public:
            explicit ProcessWrapper(const std::string name);

            Process& operator*();
            Process* operator&();
            Process* operator->();

        };

        
    }
}


#endif //OPERATINGSYSTEMS_ALGORITHMS_FRAMEALLOCATION_PROCESSWRAPPER_H
