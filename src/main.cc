#include<iostream>
#include<memory>

#include "gamBackground.h"

int main(int argc, char *argv[]) {
    std::shared_ptr<bgm::gamBackground> ptr = std::make_shared<bgm::gamBackground>();
    ptr->createBackground(argc, argv);

    return 0;
}