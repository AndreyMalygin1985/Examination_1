#include "File_Manager.h"
#include "Menu.h"

using namespace std;
namespace fs = filesystem;

int main()
{
    SetConsoleOutputCP(1251);

    FileManager fileManager;
    Menu menu(fileManager);
    menu.run();
}