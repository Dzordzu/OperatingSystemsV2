//
// Created by dzordzu on 5/16/19.
//

#ifndef OPERATINGSYSTEMS_PROCESSOR_PAGE_H
#define OPERATINGSYSTEMS_PROCESSOR_PAGE_H


#include <cstdint>

namespace OperatingSystems{
    namespace Processor {

        class Process;

        class Page {
            Process * process;
        public:
            static const uint_fast64_t weight = 1;
            Page(OperatingSystems::Processor::Process *process);
            Page(Page const &page);
            Process *getProcess() const;
            ~Page();
        };
    }
}



#endif //OPERATINGSYSTEMS_PROCESSOR_PAGE_H
