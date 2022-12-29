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
        if (programNumber == 1){
            cout << "=================================================" << endl;
            cout << "Program 1 : Menambahkan folder baru" << endl;
            cout << "=================================================" << endl;
        }else if (programNumber == 2){
            cout << "=================================================" << endl;
            cout << "Program 2 : Menampilkan data folder X" << endl;
            cout << "=================================================" << endl;
        }else if (programNumber == 3){
            cout << "=================================================" << endl;
            cout << "Program 3 : Menghapus folder tertentu" << endl;
            cout << "=================================================" << endl;
        }else if (programNumber == 4){
            cout << "=================================================" << endl;
            cout << "Program 4 : Mencari folder X" << endl;
            cout << "=================================================" << endl;
        }else if (programNumber == 5){
            cout << "=================================================" << endl;
            cout << "Program 5 : Menambahkan file dari folder X" << endl;
            cout << "=================================================" << endl;
        }else if (programNumber == 6){
            cout << "=================================================" << endl;
            cout << "Program 6 : Menghapus file dari folder X" << endl;
            cout << "=================================================" << endl;
        }else if (programNumber == 7){
            cout << "=================================================" << endl;
            cout << "Program 7 : Menampilkan seluruh file dari folder X" << endl;
            cout << "=================================================" << endl;
        }else if (programNumber == 8){
            cout << "=================================================" << endl;
            cout << "Program 8 : Mencari file Y dari folder X" << endl;
            cout << "=================================================" << endl;
        }else if (programNumber == 9){
            cout << "=================================================" << endl;
            cout << "Program 9 : Membuat relasi antara folder X" << endl;
            cout << "=================================================" << endl;
        }else if (programNumber == 10){
            cout << "=================================================" << endl;
            cout << "Program 10 : Menghapus relasi antara folder X dan file Y" << endl;
            cout << "=================================================" << endl;
        }else if (programNumber == 11){
            cout << "=================================================" << endl;
            cout << "Program 11 : Menampilkan folder yang memiliki jumlah file yang paling banyak dan menampilkan file tersebut" << endl;
            cout << "=================================================" << endl;
        }else if (programNumber == 12){
            cout << "=================================================" << endl;
            cout << "Program 12 : Mencari nama folder dari file Y" << endl;
            cout << "=================================================" << endl;
        }else if (programNumber == 0){
            break;
        }else {
            continue;
        }
        printMenu = backMenu();
    }
    */
    return 0;
}
