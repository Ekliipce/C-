#include <iostream>
#include <string>
#include <vector>

#include "soldier.hh"

class Regiment
{
public:
    Regiment();
    Regiment(std::vector<Soldier*> soldiers);

    void join_by(Regiment& r);
    size_t count() const;
    void add_soldier(Soldier* s);
    void print_state() const;
    void scream() const;

    std::vector<Soldier*>& get_soldiers();

private:
    std::vector<Soldier*> soldiers_;
};
