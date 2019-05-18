//
// Created by dzordzu on 5/18/19.
//

#ifndef OPERATINGSYSTEMS_SIMULATOR_PROCESSORINFO_H
#define OPERATINGSYSTEMS_SIMULATOR_PROCESSORINFO_H

#include <string>
#include <OperatingSystems/Processor/Processor.h>

namespace OperatingSystems {
    namespace Simulator {


        class ProcessorInfo {
        protected:
            Processor::Processor & processor;
        public:
            ProcessorInfo(Processor::Processor &processor);
            const std::string name() const;
            const std::string frames() const;
            const std::string freeFrames() const;
            const std::string allocationFrequency() const;
            const std::string fullInfo() const;
        };


    }
}




#endif //OPERATINGSYSTEMS_SIMULATOR_PROCESSORINFO_H
