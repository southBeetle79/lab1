#include "mystring.hpp"

class TextWrapper{
private:
    MyString text;
    int maxWidth;
    int currentPos;

    bool is_end_of_text() const;
    int find_word_end(int start) const;
    void print_chunk(int start, int end) const;
public:
    TextWrapper(const MyString& input, int width);
    void print_wrapped();
};