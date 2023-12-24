#include "File_Manager.h"

void FileManager::selectDisk() {
	cout << "Доступные диски:\n";

	// Получаем список доступных дисков
	vector<fs::path> disks;
	for (char letter = 'A'; letter <= 'F'; ++letter) {
		fs::path rootPath = fs::path(string(1, letter) + ":\\");
		if (fs::exists(rootPath)) {
			disks.push_back(rootPath);
			wcout << "Disk " << rootPath.root_name().wstring() << "\n";
		}
	}

	if (disks.empty()) {
		cout << "Диски не найдены.\n";
		return;
	}

	cout << "Введите букву диска, который хотите выбрать: ";
	wstring selectedDisk;
	getline(wcin >> ws, selectedDisk);

	// Проверяем, есть ли выбранный диск в списке
	bool diskFound = false;
	for (const fs::path& disk : disks) {
		if (disk.root_name().wstring() == selectedDisk) {
			currentDirectory = disk;  // Обновляем текущий путь на выбранный диск
			diskFound = true;
			break;
		}
	}

	if (diskFound) {
		wcout << "Выбранный диск: " << selectedDisk << "\n";
	}
	else {
		cout << "Неверный выбор диска.\n";
	}
}

void FileManager::showContent(const string& path) {
	if (!fs::exists(path)) {
		cout << "Неверный путь.\n";
		return;
	}

	try {
		fs::directory_iterator dirIt(path);
		fs::directory_iterator endIt;

		for (; dirIt != endIt; ++dirIt) {
			const fs::path& entryPath = dirIt->path();

			if (fs::is_directory(entryPath)) {
				cout << "(папка) " << entryPath.filename() <<endl;
			}
			else {
				cout << "(файл)  "<< entryPath.filename() <<endl;
			}
		}
	}
	catch (const fs::filesystem_error& e) {
		cout << "Ошибка: " << e.what() << "\n";
	}
}


bool FileManager::createFolder(const string& path, const string& folderName)
{
	fs::path folderPath = fs::path(path) / folderName;

	try
	{
		fs::create_directories(folderPath);
		cout << "Папка создана успешно." << endl;
		return true;
	}
	catch (const fs::filesystem_error& err)
	{
		cout << "Не удалось создать папку: " << err.what() << endl;
		return false;
	}
}

bool FileManager::createFile(const string& path, const string& fileName)
{
	fs::path filePath = fs::path(path) / fileName;

	try
	{
		ofstream file(filePath);
		if (file)
		{
			cout << "Файл успешно создан." << endl;
			return true;
		}
		else
		{
			cout << "Не удалось создать файл." << endl;
			return false;
		}
	}
	catch (const fs::filesystem_error& err)
	{
		cout << "Не удалось создать файл: " << err.what() << endl;
		return false;
	}
}

bool FileManager::deleteFolder(const string& path)
{
	try
	{
		fs::remove_all(path);
		cout << "Папка успешно удалена." << endl;
		return true;
	}
	catch (const fs::filesystem_error& err)
	{
		cout << "Не удалось удалить папку: " << err.what() << endl;
		return false;
	}
}

bool FileManager::deleteFile(const string& path)
{
	try
	{
		fs::remove(path);
		cout << "Файл успешно удален." << endl;
		return true;
	}
	catch (const fs::filesystem_error& err)
	{
		cout << "Не удалось удалить файл: " << err.what() << endl;
		return false;
	}
}

bool FileManager::renameFolder(const string& path, const string& newFolderName)
{
	try
	{
		fs::path newPath = fs::path(path).parent_path() / newFolderName;
		fs::rename(path, newPath);
		cout << "Папка успешно переименована." << endl;
		return true;
	}
	catch (const fs::filesystem_error& err)
	{
		cout << "Не удалось переименовать папку: " << err.what() << endl;
		return false;
	}
}

bool FileManager::renameFile(const string& path, const string& newFileName)
{
	try
	{
		fs::path newPath = fs::path(path).parent_path() / newFileName;
		fs::rename(path, newPath);
		cout << "Файл успешно переименован." << endl;
		return true;
	}
	catch (const fs::filesystem_error& err)
	{
		cout << "Не удалось переименовать файл: " << err.what() << endl;
		return false;
	}
}

bool FileManager::copyFolder(const string& source, const string& destination)
{
	try
	{
		fs::copy(source, destination, fs::copy_options::recursive);
		cout << "Папка успешно скопирована." << endl;
		return true;
	}
	catch (const fs::filesystem_error& err)
	{
		cout << "Не удалось скопировать папку: " << err.what() << endl;
		return false;
	}
}

bool FileManager::copyFile(const string& source, const string& destination)
{
	try
	{
		fs::copy(source, destination);
		cout << "Файл успешно скопирован." << endl;
		return true;
	}
	catch (const fs::filesystem_error& err)
	{
		cout << "Не удалось скопировать файл: " << err.what() << endl;
		return false;
	}
}


bool FileManager::moveFolder(const string& source, const string& destination)
{
	try
	{
		fs::rename(source, destination);
		cout << "Папка успешно перемещена." << endl;
		return true;
	}
	catch (const fs::filesystem_error& err)
	{
		cout << "Не удалось переместить папку: " << err.what() << endl;
		return false;
	}
}

bool FileManager::moveFile(const string& source, const string& destination)
{
	try
	{
		fs::rename(source, destination);
		cout << "Файл успешно перемещен." << endl;
		return true;
	}
	catch (const fs::filesystem_error& err)
	{
		cout << "Не удалось переместить файл: " << err.what() << endl;
		return false;
	}
}

uintmax_t FileManager::calculateSize(const string& path)
{
	try
	{
		uintmax_t size = fs::file_size(path);
		cout << "Размер: " << size << " байт" << endl;
		return size;
	}
	catch (const fs::filesystem_error& err)
	{
		cout << "Не удалось рассчитать размер: " << err.what() << endl;
		return 0;
	}
}

vector<string> FileManager::searchByMask(const string& path, const string& mask)
{
	vector<string> results;

	try
	{
		for (const auto& entry : fs::recursive_directory_iterator(path))
		{
			if (entry.is_regular_file() && entry.path().filename().string().find(mask) != string::npos)
			{
				results.push_back(entry.path().string());
			}
		}
	}
	catch (const fs::filesystem_error& err)
	{
		cout << "Поиск не удался: " << err.what() << endl;
		return results;
	}

	return results;
}