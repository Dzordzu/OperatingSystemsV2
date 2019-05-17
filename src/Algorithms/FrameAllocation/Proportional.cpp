//
// Created by dzordzu on 5/17/19.
//

#include "OperatingSystems/Algorithms/FrameAllocation/Proportional.h"

void OperatingSystems::Algorithms::FrameAllocation::Proportional::allocateFrames() {

    int weightTotal = 0;
    for(Process &p : processor->processes) {
        weightTotal += p.getWeight();
    }


    for(Process &p : processor->processes) {
        double percentage = (double)p.getWeight()/(double)weightTotal;
        setFramesAmount(p, (int)std::ceil(processor->getFramesAmount() * percentage));
    }
}
