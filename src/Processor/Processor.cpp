//
// Created by dzordzu on 5/16/19.
//

#include "OperatingSystems/Processor/Processor.h"
#include <iostream>

void OperatingSystems::Processor::Processor::resolveCall(Call call) {

    framesAlgorithm->alwaysRun(*call.getPage());

    if(call.getPage()->getProcess()->resolvePage(*call.getPage())) {
        framesAlgorithm->pageError(*call.getPage());
    }

    if(allocationsCounter >= 0) allocationsCounter++;

    if(allocationsCounter == framesAllocationFrequency) {
        allocationsCounter = 0;
        framesAlgorithm->allocateFrames();
        std::cout<<"Frames allocated "<<std::endl;
    }
}
void OperatingSystems::Processor::Processor::allocateFrames() {
    framesAlgorithm->allocateFrames();
}


void OperatingSystems::Processor::Processor::addProcess(const std::string name, int pagesAmount) {
    pagesAlgorithms.emplace_back(std::make_unique<LRU>());
    this->processesVal.emplace_back(Process(name, 0, &(**pagesAlgorithms.rbegin())));
    this->processes.emplace_back(*processesVal.rbegin());

    for(int i=0; i<pagesAmount; i++) {
        pages.emplace_back(Page(&*processesVal.rbegin()));
    }
    framesAlgorithmOnAdd->allocateFrames();
}



OperatingSystems::Processor::Processor::Processor(int framesAmount, FramesAlgorithm *framesAlgorithm,
                                                  FramesAlgorithm *framesAlgorithmOnAdd)
        : freeFrames(framesAmount), framesAlgorithm(framesAlgorithm), framesAmount(framesAmount), framesAlgorithmOnAdd(framesAlgorithmOnAdd) {
    if(framesAmount == 0) throw std::logic_error("No frames");
    if(framesAlgorithm == nullptr) throw std::logic_error("Couldn't find frames allocation algorithm");
    framesAlgorithm->processor = this;
    framesAlgorithmOnAdd->processor = this;
}
int OperatingSystems::Processor::Processor::getFramesAmount() const {
    return framesAmount;
}
int OperatingSystems::Processor::Processor::getFreeFramesAmount() const {
    return freeFrames;
}
void OperatingSystems::Processor::Processor::addProcess(OperatingSystems::Processor::Process &process) {
    this->processes.emplace_back(process);
}
void OperatingSystems::Processor::Processor::setFramesAllocationFrequency(int framesAllocationFrequency) {
    Processor::framesAllocationFrequency = framesAllocationFrequency;
}
void OperatingSystems::Processor::Processor::allocateFramesAfterAdd() {
    framesAlgorithmOnAdd->allocateFrames();
}
int OperatingSystems::Processor::Processor::getFramesAllocationFrequency() const {
    return framesAllocationFrequency;
}
