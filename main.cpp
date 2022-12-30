#include "MLL.h"
#include <iostream>
using namespace std;

int main()
{

    //cout << "ass" <<endl;
    //reRunProgram("as fuck");
    //cout << "fuc" <<endl;

    fileList ListFile;folderList ListFolder;
    createFileList(ListFile);createFolderList(ListFolder);
    adrFolder cP;adrFile pP;
    folder folder;file file;
    string folderName;string fileName;

    bool printMenu = true;
    int choosenMenu;

    while (printMenu){
        choosenMenu= getMenu();
        if (choosenMenu == 1){
            clearConsole();
            cout << "=================================================" << endl;
            cout << " Program 1 : Menambahkan folder baru" << endl;
            cout << "=================================================" << endl;
            int totalInput = 1;
            cout << "Jumlah folder yang ingin ditambahkan: ";cin >> totalInput;
            for (int i= 0;i < totalInput;i++) {
                cout << "Folder Name: ";cin >> folder.name;
                folder.size = 0;folder.totalFile = 0;
                cP = newFolder(folder);
                insertFolder(ListFolder,cP);
            }
            cout << "==> Folder berhasil ditambahkan" << endl;
        }else if (choosenMenu == 2){
            clearConsole();
            cout << "=================================================" << endl;
            cout << "Program 2 : Menampilkan data folder X" << endl;
            cout << "=================================================" << endl<<endl;
            showFolderList(ListFolder);
            if (first(ListFolder)==nil){
                cout << "List folder Kosong. Harap tambahkan folder terlebih dahulu" << endl;
            }else {
                cout << "Masukkan nama folder yang dicari: ";cin >> folderName;
                showDataFolder(ListFolder,folderName);
            }
        }else if (choosenMenu == 3){
            clearConsole();
            cout << "=================================================" << endl;
            cout << "Program 3 : Menghapus folder tertentu" << endl;
            cout << "=================================================" << endl;
            showFolderList(ListFolder);
            if (first(ListFolder) == nil){
                cout << "Harap tambahkan folder terlebih dahulu" << endl;
            }else {
                cout << "Masukkan nama folder yang ingin dihapus: ";cin >> folderName;
                deleteFolder(ListFile,ListFolder,folderName);
            }
        }
        // unfinished
        else if (choosenMenu == 4){
            clearConsole();
            cout << "=================================================" << endl;
            cout << "Program 4 : Mencari folder X" << endl;
            cout << "=================================================" << endl;
        }
        else if (choosenMenu == 5){
            clearConsole();
            cout << "=================================================" << endl;
            cout << "Program 5 : Menambahkan file dari folder X" << endl;
            cout << "=================================================" << endl;
            int totalInputFile = 1;
            cout << "Jumlah file yang ingin ditambahkan: ";cin >> totalInputFile;
            for (int i= 0;i < totalInputFile;i++) {
                cout << "=========================="<<endl;
                cout << "File Name      : ";cin >> file.name;
                cout << "File Type      : ";cin >> file.type;
                cout << "File Size(kB)  : ";cin >> file.size;
                cout << "=========================="<<endl;
                pP = newFile(file);
                insertFile(ListFile,pP);
            }
            cout << "==> File berhasil ditambahkan" << endl;
        }
        // unfinished
        else if (choosenMenu == 6){
            clearConsole();
            cout << "=================================================" << endl;
            cout << "Program 6 : Menghapus file dari folder X" << endl;
            cout << "=================================================" << endl;
        }
        else if (choosenMenu == 7){
            clearConsole();
            cout << "=================================================" << endl;
            cout << "Program 7 : Menampilkan seluruh file dari folder X" << endl;
            cout << "=================================================" << endl;
            cout << "Masukkan nama folder yang ingin ditampilkan: ";cin >> folderName;
            showAllFileFromFolderX(ListFile,folderName);
        }
        // unfinished
        else if (choosenMenu == 8){
            clearConsole();
            cout << "=================================================" << endl;
            cout << "Program 8 : Mencari file Y dari folder X" << endl;
            cout << "=================================================" << endl;
        }
        else if (choosenMenu == 9){
            clearConsole();
            cout << "=================================================" << endl;
            cout << "Program 9 : Membuat relasi antara folder X" << endl;
            cout << "=================================================" << endl;
            showFolderList(ListFolder);
            showFileList(ListFile);
            cout << "Masukkan nama folder dan file yang ingin dihubungkan:"<<endl;
            cout << "Nama Folder: ";cin >> folderName;
            cout << "Nama File: ";cin >> fileName;
            connectFolderFile(ListFolder,ListFile,fileName,folderName);
        }
        // error
        else if (choosenMenu == 10){
            clearConsole();
            cout << "=================================================" << endl;
            cout << "Program 10 : Menghapus relasi antara folder X dan file Y" << endl;
            cout << "=================================================" << endl;
            showConnection(ListFolder,ListFile);
            cout << "Masukkan nama folder dan file yang ingin dihapus Hubungannya:"<<endl;
            cout << "Nama Folder: ";cin >> folderName;
            cout << "Nama File: ";cin >> fileName;
            disconnectFolderFile(ListFolder,ListFile,fileName,folderName);
        }
        else if (choosenMenu == 11){
            clearConsole();
            cout << "=================================================" << endl;
            cout << "Program 11 : Menampilkan folder yang memiliki jumlah file yang paling banyak dan menampilkan file tersebut" << endl;
            cout << "=================================================" << endl;
            showMostFileInFolder(ListFile,ListFolder);
        }
        else if (choosenMenu == 12){
            clearConsole();
            cout << "=================================================" << endl;
            cout << "Program 12 : Mencari nama folder dari file Y" << endl;
            cout << "=================================================" << endl;
            showFileList(ListFile);
            cout << "Masukkan file yang ingin dicari nama foldernya: ";cin >> fileName;
            folderName = findFolderNameFromFileY(ListFile,fileName);
            cout << "Nama folder dari file "<< fileName << ": "<< folderName << endl;
        }else if (choosenMenu == 0){
            break;
        }else {
            continue;
        }
        printMenu = backMenu();
    }

    return 0;
}
