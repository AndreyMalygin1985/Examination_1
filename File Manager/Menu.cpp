#include "Menu.h"


void Menu::display() const
{
	cout << endl;
	cout << "������� ����: " << currentPath << endl;
	cout << " [0] ������� ����" << endl;
	cout << " [1] �������� ����������" << endl;
	cout << " [2] ������� �����" << endl;
	cout << " [3] ������� ����" << endl;
	cout << " [4] ������� �����" << endl;
	cout << " [5] ������� ����" << endl;
	cout << " [6] ������������� �����" << endl;
	cout << " [7] ������������� ����" << endl;
	cout << " [8] ����������� �����" << endl;
	cout << " [9] ����������� ����" << endl;
	cout << "[10] ����������� �����" << endl;
	cout << "[11] ����������� ����" << endl;
	cout << "[12] �������� ������" << endl;
	cout << "[13] ����� �� �����" << endl;
	cout << "[666] �����" << endl;
	cout << endl;
}

void Menu::run()
{
	while (true)
	{
		display();
		int choice;
		cout << "�������� ��������: ";
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case 0:
			fileManager.selectDisk();
			break;
		case 1:
			//fileManager.showCurrentDirectoryContent();
			fileManager.showContent(currentPath);
			break;
		case 2:
		{
			string folderName;
			cout << "������� ��� �����: ";
			cin >> folderName;
			//fileManager.createNewFolder();
			fileManager.createFolder(currentPath, folderName);
			break;
		}
		case 3:
		{
			string fileName;
			cout << "������� ��� �����: ";
			cin >> fileName;
			fileManager.createFile(currentPath, fileName);
			break;
		}
		case 4:
		{
			string folderName;
			cout << "������� ��� �����: ";
			cin >> folderName;
			fileManager.deleteFolder(currentPath + folderName);
			break;
		}
		case 5:
		{
			string fileName;
			cout << "������� ��� �����: ";
			cin >> fileName;
			fileManager.deleteFile(currentPath + fileName);
			break;
		}
		case 6:
		{
			string folderName, newFolderName;
			cout << "������� ��� �����: ";
			cin >> folderName;
			cout << "������� ����� ��� �����: ";
			cin >> newFolderName;
			fileManager.renameFolder(currentPath + folderName, newFolderName);
			break;
		}
		case 7:
		{
			string fileName, newFileName;
			cout << "������� ��� �����: ";
			cin >> fileName;
			cout << "������� ����� ��� �����: ";
			cin >> newFileName;
			fileManager.renameFile(currentPath + fileName, newFileName);
			break;
		}
		case 8:
		{
			string source, destination;
			cout << "������� � �������� �����: ";
			cin >> source;
			cout << "������� ����� ����������: ";
			cin >> destination;
			fileManager.copyFolder(currentPath + source, currentPath + destination);
			break;
		}
		case 9:
		{
			string source, destination;
			cout << "������� �������� ����: ";
			cin >> source;
			cout << "������� �������� ����: ";
			cin >> destination;
			fileManager.copyFile(currentPath + source, currentPath + destination);
			break;
		}
		case 10:
		{
			string source, destination;
			cout << "������� � �������� �����: ";
			cin >> source;
			cout << "������� ����� ����������: ";
			cin >> destination;
			fileManager.moveFolder(currentPath + source, currentPath + destination);
			break;
		}
		case 11:
		{
			string source, destination;
			cout << "������� �������� ����: ";
			cin >> source;
			cout << "������� �������� ����: ";
			cin >> destination;
			fileManager.moveFile(currentPath + source, currentPath + destination);
			break;
		}
		case 12:
		{
			string path;
			cout << "������� ���� � ����� ��� �����: ";
			cin >> path;
			fileManager.calculateSize(currentPath + path);
			break;
		}
		case 13:
		{
			string mask;
			cout << "������� �����: ";
			cin >> mask;
			vector<string> results = fileManager.searchByMask(currentPath, mask);
			cout << "���������� ������:" << endl;
			for (const auto& result : results)
			{
				cout << result << endl;
			}
			break;
		}
		case 666:
			return;
		default:
			cout << "�������� �����. ����������, ���������� �����." << endl;
		}

		cout << endl;
	}
}