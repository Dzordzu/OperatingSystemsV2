//
// Created by dzordzu on 5/16/19.
//

#include "../../include/OperatingSystems/Processor/Process.h"

const std::string &OperatingSystems::Processor::Process::getName() const {
    return name;
}



bool OperatingSystems::Processor::Process::resolvePage(OperatingSystems::Processor::Page &page) {

    if(this != page.getProcess()) throw std::logic_error("Algorithm has been bound to other process than given page");
    if(frames.empty()) {
        counter->add();
        return true;
    }

    enum Mode {
        LOADED,
        ADD_TO_EMPTY_FRAME,
        REPLACE
    };

    Mode mode = REPLACE;
    Frame * emptyFrame;

    for(Frame &frame : frames) {
        if(frame.getPage() == nullptr) {

            if(mode != LOADED) {
                emptyFrame = &frame;
                mode = ADD_TO_EMPTY_FRAME;
            }
        }
        else if(frame.getPage() == &page) mode = LOADED;
    }

    if(mode == ADD_TO_EMPTY_FRAME) {
        pageAlgorithm->addToFrame(page, *emptyFrame);
        return false;
    }
    else if(mode == REPLACE) {
        counter->add();
        pageAlgorithm->replacePage(page);
        return true;
    }
    else {
        pageAlgorithm->pageAlreadyLoaded(page);
        return false;
    }


}


OperatingSystems::Processor::Process::Process(const std::string &name, int framesAmount, PagesAlgorithm *pageAlgorithm)
        : name(name), pageAlgorithm(pageAlgorithm) {
    frames.resize(framesAmount);

    this->pageAlgorithm->process = this;
    this->pageAlgorithm->frames = &frames;
}
int OperatingSystems::Processor::Process::getFramesAmount() {
    return frames.size();
}
uint_fast32_t OperatingSystems::Processor::Process::getWeight() const {
    return weight;
}
void OperatingSystems::Processor::Process::setCounter(OperatingSystems::Processor::ErrorCounter *counter) {
    Process::counter = counter;
}
