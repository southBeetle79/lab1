#include "textwrapper.hpp"
#include <iostream>

TextWrapper::TextWrapper(const MyString& input, int width): text(input), maxWidth(width), currentPos(0){}

bool TextWrapper::is_end_of_text() const{
    return text.get(currentPos) == '\0';
}

int TextWrapper::find_word_end(int start) const{
    int i = start;
    while(text.get(i) != '\0' && text.get(i) != ' '){
        i++;
    }
    return i;
}

void TextWrapper::print_chunk(int start, int end) const{
    for(int i = start; i < end; i++){
        std::cout << text.get(i);
    }
}

void TextWrapper::print_wrapped(){
    int lineLength = 0;
    currentPos = 0;

    while(!is_end_of_text()){
        if(text.get(currentPos) == ' '){
            if(lineLength > 0){
                std::cout << " ";
                lineLength++;
            }
            currentPos++;
            continue;
        }
        int wordend = find_word_end(currentPos);
        int wordlen = wordend - currentPos;
        
        if(lineLength + wordlen > maxWidth){
            std::cout << "\n";
            lineLength = 0;
        }
        print_chunk(currentPos, wordend);
        lineLength += wordlen;
        currentPos = wordend;
    }
    std::cout << std::endl;
}

