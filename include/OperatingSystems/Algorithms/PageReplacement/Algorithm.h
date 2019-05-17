//
// Created by dzordzu on 5/17/19.
//

#ifndef OPERATINGSYSTEMS_ALGORITHMS_PAGEREPLACEMENT__ALGORITHM_H
#define OPERATINGSYSTEMS_ALGORITHMS_PAGEREPLACEMENT__ALGORITHM_H

#include <OperatingSystems/Processor/Page.h>
#include <OperatingSystems/Processor/Frame.h>
#include <vector>

namespace OperatingSystems {

    namespace Processor { class Process; }

    namespace Algorithms {
        namespace PageReplacement {

            using OperatingSystems::Processor::Page;
            using OperatingSystems::Processor::Frame;
            using OperatingSystems::Processor::Process;

            class Algorithm {
            protected:
                friend Process;
                Process * process;
                std::vector<Frame> * frames;

            public:
                Algorithm() = default;
                virtual void addToFrame(Page &page, Frame &frame) { frame.setPage(&page);}
                virtual void pageAlreadyLoaded(Page &page) {};
                virtual void replacePage(Page &page) = 0;
            };

        }
    }
}



#endif //OPERATINGSYSTEMS_ALGORITHMS_PAGEREPLACEMENT_ALGORITHM_H
