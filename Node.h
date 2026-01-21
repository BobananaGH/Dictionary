#pragma once

#include "Word.h"

struct Node {
    Word data; //chưa đối tượng word
    Node* next; // con trỏ liên kết đến Node tiếp theo

    Node(Word w) : data(w), next(NULL) {}
};