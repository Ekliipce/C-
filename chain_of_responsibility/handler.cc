#include "handler.hh"

#include <iostream>

Handler::Handler(Handler* next)
    : next_(next)
{}

void Handler::set_successor(Handler* h)
{
    this->next_ = h;
}

void Handler::forward_request(int level)
{
    if (!this->next_)
        std::cout << "Nobody can handle this request\n";
    else
        this->next_->handle_request(level);
}
