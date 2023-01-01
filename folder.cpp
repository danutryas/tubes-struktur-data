void createFolderList(folderList &cL){
    first(cL) = nil;
};
adrFolder newFolder(folder info){
    adrFolder C = new elmFolder;
    info(C) = info;
    next(C) = nil;
    return C;
}
