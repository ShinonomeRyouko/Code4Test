#ifndef __wrapper_h__
#define __wrapper_h__

#include <vector>
using namespace std;
// RAII
template <class T>
class wrapper {
private:
    // Track all the T class generated through wrapper.
    vector<T*> elements;

public:
    wrapper() = default;

    void* operator new(size_t) = delete;
    void* operator new[](size_t) = delete;
    void operator delete(void*) = delete;
    void operator delete[](void*) = delete;
    wrapper(const wrapper& other) = delete;
    wrapper(wrapper&& other) = delete;
    wrapper& operator=(const wrapper& other) = delete;
    wrapper& operator=(wrapper&& other) = delete;

    ~wrapper() {
        for (auto ele : elements) {
            delete ele;
        }
    }

    template <typename Source>
    T* gen_from_source(Source&& source) {
        return T::gen_from_source(std::forward<Source>(source), elements);
    }
};

#endif