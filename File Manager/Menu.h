#pragma once
#include "File_Manager.h"

class Menu
{
private:
    FileManager& fileManager;
    string currentPath;

public:
    Menu(FileManager& fm) : fileManager(fm), currentPath("/") {}
    void display() const;
    void run();
};