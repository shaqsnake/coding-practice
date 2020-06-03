#include <cstdio>
#include <utility>

class shared_count {
public:
    shared_count():  count_(1) {}
    void add_count() {
        ++count_;
    }
    long reduce_count() {
        return --count_;
    }
    long get_count() const {
        return count_;
    }

private:
    long count_;
};

template <typename T>
class smart_ptr {
public:
    template <typename U>
    friend class smart_ptr;

    explicit smart_ptr(T* ptr = nullptr): ptr_(ptr) {
        if (ptr) {
            shared_count_ = new shared_count();
        }
    }
    ~smart_ptr() {
        if (ptr_ && !shared_count_->reduce_count()) {
            delete ptr_;
            delete shared_count_;
        }
    }
    smart_ptr(const smart_ptr& other) {
        ptr_ = other.ptr_;
        if (ptr_) {
            other.shared_count_->add_count();
            shared_count_ = other.shared_count_;
        }
    }
    template <typename U>
    smart_ptr(const smart_ptr<U>& other) {
        ptr_ = other.ptr_;
        if (ptr_) {
            other.shared_count_->add_count();
            shared_count_ = other.shared_count_;
        }
    }
    template <typename U>
    smart_ptr(smart_ptr<U>&& other) {
        ptr_ = other.ptr_;
        if (ptr_) {
            shared_count_ = other.shared_count_;
            other.ptr_ = nullptr;
        }
    }
    smart_ptr& operator=(smart_ptr rhs) {
        rhs.swap(*this);
        return *this;
    }
    template <typename U>
    smart_ptr(const smart_ptr<U>& other, T* ptr) {
        ptr_ = ptr;
        if (ptr_) {
            other.shared_count_->add_count();
            shared_count_ = other.shared_count_;
        }
    }

    long use_count() const {
        if (ptr_) {
            return shared_count_->get_count();
        } else {
            return 0;
        }
    }

    void swap(smart_ptr& rhs) {
        using std::swap;
        swap(ptr_, rhs.ptr_);
        swap(shared_count_, rhs.shared_count_);
    }

    T* get() const { return ptr_; }
    T& operator*() const { return *ptr_; }
    T* operator->() const { return ptr_; }
    operator bool() const { return ptr_; }
private:
    T* ptr_;
    shared_count* shared_count_;
};

template <typename T, typename U>smart_ptr<T> static_pointer_cast(  const smart_ptr<U>& other) noexcept{  T* ptr = static_cast<T*>(other.get());  return smart_ptr<T>(other, ptr);}
template <typename T, typename U>smart_ptr<T> reinterpret_pointer_cast(  const smart_ptr<U>& other) noexcept{  T* ptr = reinterpret_cast<T*>(other.get());  return smart_ptr<T>(other, ptr);}
template <typename T, typename U>smart_ptr<T> const_pointer_cast(  const smart_ptr<U>& other) noexcept{  T* ptr = const_cast<T*>(other.get());  return smart_ptr<T>(other, ptr);}
template <typename T, typename U>smart_ptr<T> dynamic_pointer_cast(  const smart_ptr<U>& other) noexcept{  T* ptr = dynamic_cast<T*>(other.get());  return smart_ptr<T>(other, ptr);}

class shape {
public:
    virtual ~shape() {}
};

class circle: public shape {
public:
    ~circle() { puts("~circle()"); }
};

int main() {
    smart_ptr<shape> p1{new circle()};
    printf("use count of p1 is %ld\n", p1.use_count());
    smart_ptr<shape> p2;
    printf("use count of p2 was %ld\n", p2.use_count());
    p2 = p1;
    printf("use count of p2 is now %ld\n", p2.use_count());
    if (p1) {
        puts("p1 is not empty");
    }
    smart_ptr<circle> p3 = dynamic_pointer_cast<circle>(p2);
    printf("use count of p3 is %ld\n", p3.use_count());

    return 0;
}