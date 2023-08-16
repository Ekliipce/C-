#include "list.hh"

List::List()
{
    nb_elts_ = 0;
    this->first_ = nullptr;
    this->last_ = nullptr;
}

void List::push_front(int i)
{
    std::shared_ptr<Node> ptr = std::make_shared<Node>(i);

    ptr->next_set(this->first_);
    ptr->prev_set(nullptr);

    if (this->nb_elts_ != 0)
        this->first_->prev_set(ptr);
    else
        this->last_ = ptr;

    this->first_ = ptr;

    this->nb_elts_++;
}

void List::push_back(int i)
{
    std::shared_ptr<Node> ptr = std::make_shared<Node>(i);

    ptr->next_set(nullptr);
    ptr->prev_set(this->last_);

    if (this->nb_elts_ != 0)
        this->last_->next_set(ptr);
    else
        this->first_ = ptr;

    this->last_ = ptr;

    this->nb_elts_++;
}

std::optional<int> List::pop_front()
{
    if (this->nb_elts_ == 0)
        return std::nullopt;

    std::shared_ptr<Node> first = this->first_;

    if (this->nb_elts_ == 1)
    {
        this->first_ = nullptr;
        this->last_ = nullptr;
    }
    else
    {
        std::shared_ptr<Node> prev = this->first_->next_get();
        this->first_ = prev;
        this->first_->prev_set(nullptr);
    }

    this->nb_elts_--;
    return first->val_get();
}

std::optional<int> List::pop_back()
{
    if (this->nb_elts_ == 0)
        return std::nullopt;

    std::shared_ptr<Node> last = this->last_;

    if (this->nb_elts_ == 1)
    {
        this->first_ = nullptr;
        this->last_ = nullptr;
    }
    else
    {
        std::shared_ptr<Node> prev = this->last_->prev_get();
        this->last_ = prev;
        this->last_->next_set(nullptr);
    }

    this->nb_elts_--;
    return last->val_get();
}

void List::print(std::ostream& os) const
{
    auto curr = this->first_;
    for (int i = 0; i < this->nb_elts_; i++)
    {
        os << curr->val_get();

        if (curr->next_get() != nullptr)
            os << " ";
        curr = curr->next_get();
    }
}

int List::length() const
{
    return this->nb_elts_;
}
