//
// Created by dzordzu on 5/16/19.
//

#include <iostream>
#include <OperatingSystems/OperatingSystems.h>
#include <OperatingSystems/Algorithms/PageReplacement/LRU.h>
#include <OperatingSystems/Algorithms/FrameAllocation/Equal.h>
#include <OperatingSystems/Algorithms/FrameAllocation/Proportional.h>
#include <OperatingSystems/Algorithms/FrameAllocation/WorkingSet.h>
#include <OperatingSystems/Algorithms/FrameAllocation/ErrorsControlling.h>
#include <OperatingSystems/Processor/ErrorCounter.h>
#include "ProcessorInfo.h"
#include "ProcessWrapper.h"

int main() {

    using OperatingSystems::Processor::Process;
    using OperatingSystems::Processor::Processor;
    using OperatingSystems::Processor::Page;
    using OperatingSystems::Processor::Call;
    using OperatingSystems::Processor::ErrorCounter;
    using OperatingSystems::Algorithms::PageReplacement::LRU;
    using OperatingSystems::Simulator::ProcessWrapper;

    using namespace OperatingSystems::Algorithms::FrameAllocation;

    std::vector<std::string> names {
            "Docker", "MyApp", "OperatingSystems", "Test", "KDE", "NonWindowsApp", "Git", "Inkscape", "Gimp", "Firefox"
    };

    /*
     * Declare processor
     */
    ErrorsControlling algo;
    Proportional addAlgo;
    Processor processor(50, &algo, &addAlgo);
    processor.setFramesAllocationFrequency(10);

    /*
     * Declare processes
     */

    std::vector<ProcessWrapper> processes;
    processes.reserve(10);
    for(const std::string & name : names) {
        processes.emplace_back(ProcessWrapper(name));
    }

    /*
     * Declare counters
     */
    std::vector<ErrorCounter> errorCounters;
    errorCounters.reserve(12);
    for(const std::string & name : names) {
        errorCounters.emplace_back(ErrorCounter(name + " Counter"));
    }
    errorCounters.emplace_back(ErrorCounter("General Counter"));

    /*
     * Connect counters with processes
     */
    for(int i=0; i<processes.size(); i++) {
        processes[i]->setCounter(&errorCounters[i]);
    }

    /*
     * Add processes to processor
     */
    for(ProcessWrapper & pw : processes) {
        processor.addProcess(*pw);
    }

    /*
     * Show info
     */
    OperatingSystems::Simulator::ProcessorInfo processorInfo(processor);

    ProcessWrapper process("Own");

//    LRU lru;
//    Process process("Own", 0, &lru);

    std::vector<Page> pages;
    pages.reserve(2000);
    pages.resize(65, {&process});





    processor.addProcess(*process);
    processor.allocateFramesAfterAdd();

    std::cout<<processorInfo.fullInfo();


    for(Page & page : pages) {
        processor.resolveCall(Call(&page));
    }






//    Page page(&*processor.processesVal.begin());
//    processor.allocateFramesAfterAdd();

    for(Process &p : processor.processes) {
        std::cout<<p.getName()<<" "<<p.getFramesAmount()<<std::endl;
    }

//    Call call(&page);
//    processor.resolveCall(call);




}
