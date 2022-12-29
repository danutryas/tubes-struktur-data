#include "MLL.h"
#include <iostream>
using namespace std;

int main()
{
    fileList ListFile;folderList ListFolder;
    createFileList(ListFile);createFolderList(ListFolder);

    adrFolder cP;adrFile pP;
    folder folder;file file;

    folder.name = "folderA";folder.size = 1.0;folder.totalFile = 1;
    file.name = "fileA";file.size = 1.0;file.type = "jpg";

    pP = newFile(file);cP = newFolder(folder);
    insertFolder(ListFolder,cP);
    showDataFolder(ListFolder,"folderA");

    adrFolder folder2 = findFolder(ListFolder, "folderA");
    deleteFolder(ListFile,ListFolder,"folderA");
    showDataFolder(ListFolder,"folderB");

    /*
    bool printMenu = true;
    int choosenMenu;

    while (printMenu){
        choosenMenu = getMenu();
        runProgram(choosenMenu);
        printMenu = backMenu();
    }
    */
    return 0;
}
