//
// Created by dzordzu on 5/18/19.
//

#ifndef OPERATINGSYSTEMS_SIMULATOR_PAGESGENERATOR_H
#define OPERATINGSYSTEMS_SIMULATOR_PAGESGENERATOR_H

#include <string>
#include <OperatingSystems/Processor/Processor.h>
#include "ProcessWrapper.h"
#include <random>

namespace OperatingSystems {
    namespace Simulator {


        class PagesGenerator {
        protected:
            ProcessWrapper & process;
            static std::random_device device;
        public:
            explicit PagesGenerator(const std::vector<ProcessWrapper> &processes);
            std::vector<Processor::Page> generate(uint_fast64_t min, uint_fast64_t max);
        };

    }
}


#endif //OPERATINGSYSTEMS_SIMULATOR_PAGESGENERATOR_H
