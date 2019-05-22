//
// Created by dzordzu on 5/17/19.
//

#include "OperatingSystems/Algorithms/FrameAllocation/WorkingSet.h"
#include <iostream>

void OperatingSystems::Algorithms::FrameAllocation::WorkingSet::allocateFrames() {

    std::map<Process *, int> usages;

    for(Process & process : getProcesses()) {
        usages.insert({&process, 0});
    }

    for(Page & p: recentPages) {
        usages.at(p.getProcess())++;
    }

    int usagesSize = usages.size();

    for(Process p : this->getProcesses()) {
        setFramesAmount(p, 0);
    }

    for(auto usage : usages) {
        setFramesAmount(*usage.first, ((double)usage.second/(double)usagesSize)*this->processor->getFramesAmount());
    }

    this->recentPages.clear();
}
void OperatingSystems::Algorithms::FrameAllocation::WorkingSet::alwaysRun(OperatingSystems::Processor::Page &page) {

    bool add = true;
    for(Page & p: recentPages) {
        if(&p == &page) add = false;
    }

    if(add) recentPages.emplace_back(page);
}
