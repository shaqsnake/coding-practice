#include <iostream>

using namespace std;

class istream_line_reader {
public:
    class iterator {
    public:
        typedef ptrdiff_t difference_type;
        typedef string value_type;
        typedef const value_type* pointer;
        typedef const value_type& reference;
        typedef input_iterator_tag iterator_category;

        iterator() noexcept
            : stream_(nullptr) {}

        explicit iterator(istream& is) noexcept
            : stream_(&is) {
                // ++*this;
            }

        reference operator*() const noexcept {
            return line_;
        }

        iterator& operator++() {
            getline(*stream_, line_);
            if (!*stream_) {
                stream_ = nullptr;
            }
            return *this;
        }

        bool operator==(const iterator& rhs) const noexcept {
            return stream_ == rhs.stream_;
        }

        bool operator!=(const iterator& rhs) const noexcept {
            return !operator==(rhs);
        }

    private:
        istream* stream_;
        string line_;
    };

    istream_line_reader() noexcept
        : stream_(nullptr) {}
    explicit istream_line_reader(istream& is) noexcept
        : stream_(&is) {}

    iterator begin() {
        return iterator(*stream_);
    }

    iterator end() const noexcept {
        return iterator();
    }

private:
    istream* stream_;
};

int main() {
    for (const string& line: istream_line_reader(cin)) {
        cout << line << endl;
    }

    // string line;
    // for (;;) {
    //     getline(cin, line);
    //     if (!cin) {
    //         break;
    //     }
    //     cout << line << endl;
    // }
    return 0;
}