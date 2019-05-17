//
// Created by dzordzu on 5/17/19.
//

#ifndef OPERATINGSYSTEMS_LRU_H
#define OPERATINGSYSTEMS_LRU_H

#include "Algorithm.h"
#include <list>
#include <functional>

namespace OperatingSystems {

    namespace Algorithms {
        namespace PageReplacement {


            class LRU : public  Algorithm {
                std::list<Page *> usedPages;
                void addUsedPage(Page &page);
            public:
                void addToFrame(Page &page, Frame &frame) override;
                void replacePage(Page &page) override;
                void pageAlreadyLoaded(Page &page) override;
            };


        }
    }
}



#endif //OPERATINGSYSTEMS_LRU_H
