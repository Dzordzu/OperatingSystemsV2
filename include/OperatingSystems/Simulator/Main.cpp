//
// Created by dzordzu on 5/16/19.
//

#include <iostream>
#include <OperatingSystems/OperatingSystems.h>
#include <OperatingSystems/Algorithms/PageReplacement/LRU.h>
#include <OperatingSystems/Algorithms/FrameAllocation/Equal.h>
#include <OperatingSystems/Algorithms/FrameAllocation/Proportional.h>
#include <OperatingSystems/Algorithms/FrameAllocation/WorkingSet.h>

int main() {

    using OperatingSystems::Processor::Process;
    using OperatingSystems::Processor::Processor;
    using OperatingSystems::Processor::Page;
    using OperatingSystems::Processor::Call;
    using OperatingSystems::Algorithms::PageReplacement::LRU;
    using OperatingSystems::Algorithms::FrameAllocation::Equal;
    using OperatingSystems::Algorithms::FrameAllocation::Proportional;
    using OperatingSystems::Algorithms::FrameAllocation::WorkingSet;

    LRU lru;
    Process process("Own", 0, &lru);

    std::vector<Page> pages;
    pages.reserve(2000);
    pages.resize(10, {&process});

    WorkingSet algo;
    Proportional addAlgo;


    Processor processor(5, &algo, &addAlgo);
    processor.setFramesAllocationFrequency(5);
    std::cout<<"Processor name: "<<algo.getProcessorName()<<"; refresh after "<<processor.getFramesAllocationFrequency()<<std::endl;

    processor.addProcess("Test", 10);
    processor.addProcess("Test2", 20);
    processor.addProcess("Test3", 50);
    processor.addProcess(process);
    processor.allocateFramesAfterAdd();


    processor.resolveCall(Call(&pages[0]));
    processor.resolveCall(Call(&pages[1]));
    processor.resolveCall(Call(&pages[0]));
    processor.resolveCall(Call(&pages[2]));
//    processor.resolveCall(Call(&pages[8]));





//    Page page(&*processor.processesVal.begin());
//    processor.allocateFramesAfterAdd();

    for(Process &p : processor.processes) {
        std::cout<<p.getName()<<" "<<p.getFramesAmount()<<std::endl;
    }

//    Call call(&page);
//    processor.resolveCall(call);




}
