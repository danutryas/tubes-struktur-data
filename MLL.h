#ifndef MLL_H_INCLUDED
#define MLL_H_INCLUDED
#include <iostream>
#include "file.h"
#include "folder.h"

#define next(P) (P)->next
#define info(P) (P)->info
#define folder(P) (P)->folder
#define first(L) (L).first
#define nil NULL

using namespace std;

// 1)Menambahkan folder baru (5 poin)
void insertFolder(folderList &L, adrFolder P);
// 2)Menampilkan data folder X (5 poin)
void showDataFolder(folderList L, string folderName);
// 3)Menghapus folder tertentu (10 poin)
void deleteFolder(fileList &pL,folderList &cL,string folderName);
// 4)Mencari folder X (5 poin)
adrFolder findFolder(folderList L, string folderName);
// 5)Menambahkan file dari folder X (5 poin)
void insertFileFromFolderX(fileList &L,adrFile pFile,adrFolder pFolder);
// 6)Menghapus file dari folder X (10 poin)
void deleteFileFromFolderX(fileList &pL,folderList cL, string folderName);
// 7)Menampilkan seluruh file dari folder X (5 poin)
void showAllFileFromFolderX(fileList L,folderList folderL,string folderName);
// 8)Mencari file Y dari folder X (5 poin)
adrFile findFileFromFolderX(fileList &L, string fileName, string folderName);
// 9)Membuat relasi antara folder X dan file Y (15 poin)
void connectFolderFile(folderList cL,fileList &pL,string fileName, string folderName);                     //
// 10)Menghapus relasi antara folder X dan file Y (15 poin)
void disconnectFolderFile(folderList cL,fileList &pL,string fileName,string folderName);       //
// 11)Menampilkan folder yang memiliki jumlah file yang paling banyak dan menampilkan file tersebut(10 poin)
void showMostFileInFolder(fileList pL,folderList cL);                                          //
// 12)Mencari nama folder dari file Y (10 poin)
void findFolderNameFromFileY(fileList L,string fileName);                       //

//aditional function
void showConnection(folderList cL,fileList pL);
// program function
void showMenu();
int getMenu();
bool backMenu();
void runProgram(int programNumber);
void clearConsole();

#endif // MLL_H_INCLUDED
