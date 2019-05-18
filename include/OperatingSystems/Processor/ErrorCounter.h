//
// Created by dzordzu on 5/18/19.
//

#ifndef OPERATINGSYSTEMSS_PROCESSOR_ERRORSCOUNTER_H
#define OPERATINGSYSTEMSS_PROCESSOR_ERRORSCOUNTER_H

#include <cstdint>
#include <string>

namespace OperatingSystems {
    namespace Processor {
        class ErrorCounter {
            std::string counterName;
            uint_fast64_t errors = 0;
        public:
            explicit ErrorCounter(const std::string &counterName) : counterName(counterName) {}
            void add(int amount = 1) { errors+=amount; }
            uint_fast64_t getErrors() const {return errors;}
            void reset() {errors = 0;}
            const std::string &getCounterName() const {
                return counterName;
            }
        };
    }
}

#endif //OPERATINGSYSTEMSS_PROCESSOR_ERRORSCOUNTER_H
