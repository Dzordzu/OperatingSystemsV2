//
// Created by dzordzu on 5/16/19.
//

#ifndef OPERATINGSYSTEMS_PROCESSOR_FRAME_H
#define OPERATINGSYSTEMS_PROCESSOR_FRAME_H


#include "Page.h"

namespace OperatingSystems {
    namespace Processor {


        class Frame {
            Page * page = nullptr;
        public:
            Frame() = default;
            Frame(Page *page);
            Page *getPage() const;
            void setPage(Page *page);
        };

        

    }
}

#endif //OPERATINGSYSTEMS_PROCESSOR_FRAME_H
