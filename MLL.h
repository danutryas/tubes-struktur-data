#ifndef MLL_H_INCLUDED
#define MLL_H_INCLUDED
#include <iostream>

#define next(P) (P)->next
#define info(P) (P)->info
#define folder(P) (P)->folder
#define first(L) (L).first
#define nil NULL

using namespace std;

// parent
struct file {
    string name;
    string type;
    double size;
};
// child
struct folder {
    string name;
    int totalFile;
    double size;
};

// address define
typedef struct elmFile *adrFile;
typedef struct elmFolder *adrFolder;

// element
struct elmFile {
    file info;
    adrFile next;
    adrFolder folder;
};
struct elmFolder {
    folder info;
    adrFolder next;
};

// List
typedef struct fileList {
    adrFile first;
};
typedef struct folderList {
    adrFolder first;
};



// 1)Menambahkan folder baru (5 poin)
void insertFolder(folderList &L, adrFolder P);
// 2)Menampilkan data folder X (5 poin)
void showDataFolder(folderList L, string folderName);
// 3)Menghapus folder tertentu (10 poin)
void deleteFolder(fileList &pL,folderList &cL,string folderName);
// 4)Mencari folder X (5 poin)
adrFolder findFolder(folderList L, string folderName);
// 5)Menambahkan file dari folder X (5 poin)
// void insertFileFromFolderX(fileList &L,string folderName);                      //
void insertFile(fileList &L, adrFile P);
// 6)Menghapus file dari folder X (10 poin)
void deleteFileFromFolderX(fileList &pL,folderList cL, adrFile P, string folderName);                                                   //
// 7)Menampilkan seluruh file dari folder X (5 poin)
void showAllFileFromFolderX(fileList L,string folderName);
// 8)Mencari file Y dari folder X (5 poin)
adrFile findFileFromFolderX(fileList &L, string fileName, string folderName);   //
// 9)Membuat relasi antara folder X dan file Y (15 poin)
void connectFolderFile(folderList cL,fileList &pL,string fileName, string folderName);                     //
// 10)Menghapus relasi antara folder X dan file Y (15 poin)
void disconnectFolderFile(folderList cL,fileList &pL,string fileName,string folderName);       //
// 11)Menampilkan folder yang memiliki jumlah file yang paling banyak dan menampilkan file tersebut(10 poin)
void showMostFileInFolder(fileList pL,folderList cL);                                          //
// 12)Mencari nama folder dari file Y (10 poin)
string findFolderNameFromFileY(fileList L,string fileName);                       //

//aditional function
void createFileList(fileList &pL);
void createFolderList(folderList &cL);
adrFile newFile(file info);
adrFolder newFolder(folder info);
void showMenu();
int getMenu();
bool backMenu();
void runProgram(int programNumber);
int inDegreeFolder(fileList L, string folderName);
adrFile findFile(fileList L, string fileName);
void clearConsole();
void showFolderList(folderList L);
void showFileList(fileList L);
void showConnection(folderList cL,fileList pL);
#endif // MLL_H_INCLUDED
