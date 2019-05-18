//
// Created by dzordzu on 5/18/19.
//

#ifndef OPERATINGSYSTEMS_CALLSGENERATOR_H
#define OPERATINGSYSTEMS_CALLSGENERATOR_H

#include <OperatingSystems/Processor/Processor.h>
#include <vector>
#include <random>

namespace OperatingSystems {
    namespace Simulator {


        class CallsGenerator {
            using Page = Processor::Page;
            using Call = Processor::Call;

            std::random_device device;
            std::vector<Page> sources;
            uint_fast32_t center;
            uint_fast32_t deviation;
            uint_fast32_t population;

        public:
            void setPagesSource(const std::vector<Processor::Page> &sources);
            void randomCenter();
            void setDeviation(uint_fast32_t deviation);
            void setPopulation(uint_fast32_t population);
            std::vector<Call> generate();
        };


    }
}


#endif //OPERATINGSYSTEMS_CALLSGENERATOR_H
