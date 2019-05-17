//
// Created by dzordzu on 5/17/19.
//

#include "OperatingSystems/Algorithms/FrameAllocation/ErrorsControlling.h"

void OperatingSystems::Algorithms::FrameAllocation::ErrorsControlling::allocateFrames() {

}
void OperatingSystems::Algorithms::FrameAllocation::ErrorsControlling::setMin(double min) {
    ErrorsControlling::min = min;
}
void OperatingSystems::Algorithms::FrameAllocation::ErrorsControlling::setMax(double max) {
    ErrorsControlling::max = max;
}
void
OperatingSystems::Algorithms::FrameAllocation::ErrorsControlling::pageError(OperatingSystems::Processor::Page &page) {
    if(errors.find(page.getProcess()) == errors.end()) {
        errors.insert({page.getProcess(), 1});
    }
}
