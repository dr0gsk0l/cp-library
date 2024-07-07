#include "library/algebra/monoid/Concepts.cpp"

#pragma once
template <monoid M> class SWAG {
    using X = typename M::value_type;

    std::stack<X> back_stack,
        front_stack; // back は後ろの各要素 front は前の累積和
    X back_value;

    inline X front_value() const {
        return front_stack.size() ? front_stack.top() : M::unit();
    }

  public:
    SWAG() : back_value(M::unit()) {}
    void push_back(X x) {
        back_stack.push(x);
        M::Rchop(back_value, x);
    }
    void push_front(X x) { front_stack.push(M::op(x, front_value())); }
    void pop_front() {
        if (front_stack.empty()) {
            if (back_stack.empty())
                return;
            while (back_stack.size()) {
                push_front(back_stack.top());
                back_stack.pop();
            }
            back_value = M::unit();
        }
        front_stack.pop();
    }
    X prod() { return M::op(front_value(), back_value); }
    int size() { return back_stack.size() + front_stack.size(); }
};