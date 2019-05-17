//
// Created by dzordzu on 5/17/19.
//

#include "OperatingSystems/Algorithms/FrameAllocation/WorkingSet.h"

void OperatingSystems::Algorithms::FrameAllocation::WorkingSet::allocateFrames() {

}
void OperatingSystems::Algorithms::FrameAllocation::WorkingSet::alwaysRun(OperatingSystems::Processor::Page &page) {

    bool add = true;
    for(Page & p: recentPages) {
        if(&p == &page) add = false;
    }

    if(add) recentPages.emplace_back(page);
}
