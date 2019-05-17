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

    Page pageOwn(&process);

    WorkingSet algo;
    Proportional addAlgo;
    Processor processor(100, &algo, &addAlgo);
    processor.addProcess("Test", 2);
    processor.addProcess("Test2", 2);
    processor.addProcess("Test3", 5);
    processor.addProcess(process);

    for(int i=0; i<3*pages.size(); i++) {
        processor.resolveCall(Call(&pages[i%pages.size()]));
    }

    Page page(&*processor.processesVal.begin());
    processor.allocateFramesAfterAdd();

    for(Process &p : processor.processes) {
        std::cout<<p.getName()<<" "<<p.getFramesAmount()<<std::endl;
    }

    Call call(&page);
    processor.resolveCall(call);




}
