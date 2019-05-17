//
// Created by dzordzu on 5/16/19.
//

#include "../../include/OperatingSystems/Processor/Frame.h"

OperatingSystems::Processor::Frame::Frame(Page *page) : page(page) {}

OperatingSystems::Processor::Page *OperatingSystems::Processor::Frame::getPage() const {
    return page;
}

void OperatingSystems::Processor::Frame::setPage(Page *page) {
    Frame::page = page;
}
