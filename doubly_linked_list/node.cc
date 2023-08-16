#include "node.hh"

Node::Node(int i)
    : val_(i)
{}

int Node::val_get() const
{
    return this->val_;
}

void Node::val_set(int val)
{
    this->val_ = val;
}

std::shared_ptr<Node> Node::next_get() const
{
    return this->next_;
}

void Node::next_set(std::shared_ptr<Node> next)
{
    this->next_ = next;
}

std::shared_ptr<Node> Node::prev_get() const
{
    return this->prev_.lock();
}

void Node::prev_set(std::shared_ptr<Node> prev)
{
    this->prev_ = prev;
}
