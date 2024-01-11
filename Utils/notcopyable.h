#ifndef NOTCOPYABLE_H
#define NOTCOPYABLE_H

struct NotCopyable{
    NotCopyable() = default;
    ~NotCopyable() = default;

    NotCopyable (NotCopyable&) = delete;
    NotCopyable &operator=(NotCopyable&) = delete;

    NotCopyable (NotCopyable &&) = default;
    NotCopyable &operator=(NotCopyable&&) = default;
};

#endif // NOTCOPYABLE_H
