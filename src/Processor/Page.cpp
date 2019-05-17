//
// Created by dzordzu on 5/16/19.
//

#include <OperatingSystems/Processor/Process.h>
#include "../../include/OperatingSystems/Processor/Page.h"
OperatingSystems::Processor::Page::Page(OperatingSystems::Processor::Process *process) : process(process) {
    process->weight+=Page::weight;
}
OperatingSystems::Processor::Process *OperatingSystems::Processor::Page::getProcess() const {
    return process;
}
OperatingSystems::Processor::Page::~Page() {
    process->weight-=Page::weight;
}
OperatingSystems::Processor::Page::Page(const OperatingSystems::Processor::Page &page) {
    this->process = page.process;
    process->weight += Page::weight;
}

