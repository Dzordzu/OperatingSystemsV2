//
// Created by dzordzu on 5/16/19.
//

#ifndef OPERATINGSYSTEMS_PROCESSOR_CALL_H
#define OPERATINGSYSTEMS_PROCESSOR_CALL_H

#include "Page.h"

namespace OperatingSystems {
    namespace Processor {


        class Call {
            Page * page;
        public:
            explicit Call(Page * page) : page(page) {}
            Page *getPage() const {
                return page;
            }
        };


    }
}



#endif //OPERATINGSYSTEMS_PROCESSOR_CALL_H
