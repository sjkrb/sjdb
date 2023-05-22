#ifndef DATABASE_H
#define DATABASE_H

struct NotCopyable{
    NotCopyable() = default;
    ~NotCopyable() = default;

    NotCopyable (NotCopyable&) = delete;
    NotCopyable &operator=(NotCopyable&) = delete;

    NotCopyable (NotCopyable &&) = default;
    NotCopyable &operator=(NotCopyable&&) = default;
};

class DataBase : public NotCopyable
{
  public:
    DataBase();
};

#endif // DATABASE_H
