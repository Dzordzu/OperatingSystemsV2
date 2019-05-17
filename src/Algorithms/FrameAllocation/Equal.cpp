//
// Created by dzordzu on 5/17/19.
//

#include "OperatingSystems/Algorithms/FrameAllocation/Equal.h"

void OperatingSystems::Algorithms::FrameAllocation::Equal::allocateFrames() {
    int amount = processor->getFramesAmount() / getProcesses().size();

    for(Process &p : processor->processes) {
        if(amount > processor->getFreeFramesAmount()) {
            setFramesAmount(p, amount);
        }
        else {
            setFramesAmount(p, processor->getFreeFramesAmount());
        }
    }
}
