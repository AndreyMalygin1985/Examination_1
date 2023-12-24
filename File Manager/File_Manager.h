#pragma once
#include "Libraries.h"

using namespace std;
namespace fs = filesystem;

class FileManager
{
private:
	filesystem::path currentDisk;
	wstring selectedDisk;
	wstring currentDirectory;
public:
	void selectDisk();
	void showContent(const string& path);
	bool createFolder(const string& path, const string& folderName);
	bool createFile(const string& path, const string& fileName);
	bool deleteFolder(const string& path);
	bool deleteFile(const string& path);
	bool renameFolder(const string& path, const string& newFolderName);
	bool renameFile(const string& path, const string& newFileName);
	bool copyFolder(const string& source, const string& destination);
	bool copyFile(const string& source, const string& destination);
	bool moveFolder(const string& source, const string& destination);
	bool moveFile(const string& source, const string& destination);
	uintmax_t calculateSize(const string& path);
	vector<string> searchByMask(const string& path, const string& mask);
};