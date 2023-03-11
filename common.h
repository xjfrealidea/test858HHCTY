#ifndef COMMON_H
#define COMMON_H

#define SINGLETON(Class) \
public: \
    Class(const Class &) = delete; \
    Class &operator=(const Class &) = delete; \
    static Class& instance() \
    { \
        static Class instance; \
        return instance; \
    } \
    virtual ~Class(); \
protected: \
    Class(); \

#endif // COMMON_H
