#include <iostream>
#include <unistd.h>
#include<sys/stat.h>
using namespace std;

void disMenu(){
    cout<<"1. Navigate directories"<<endl;
    cout<<"2. View files"<<endl;
    cout<<"3. Create directories"<<endl;
    cout<<"4. Copy or move files"<<endl;
    cout<<"5. Delete files"<<endl;
    cout<<"6. Exit"<<endl;
}

void navDir(){
    string dir;
    cout<<"Enter the directory you want to navigate to: ";
    cin>>dir;
    if (chdir(dir.c_str()) == 0){
        cout<<"Directory changed successfully!"<<endl;
    } else {
        cout<<"Directory change failed!"<<endl;
    }
}

void viewFiles(){
#ifdef _WIN32
    system("dir");
#else
    system("ls");
#endif
}

void createDir(){
    string dir;
    cout<<"Enter the name of the directory you want to create: ";
    cin>>dir;
#ifdef _WIN32
    if (mkdir(dir.c_str()) == 0) {
#else
        if (mkdir(dir.c_str(), 0777) == 0) {
#endif
        cout<<"Directory created successfully!"<<endl;
    } else {
        cout<<"Directory creation failed!"<<endl;
    }
}

void copyMoveFiles() {
    string src, dest;
    cout<<"Enter the source file path: ";
    cin>>src;
    cout<<"Enter the destination file path: ";
    cin>>dest;
    if (rename(src.c_str(), dest.c_str())==0) {
        cout<<"File copied/moved successfully!"<<endl;
    } else {
        cout << "File copy/move failed!" << endl;
    }
}

void deleteFile() {
    string file;
    cout<<"Enter the file path you want to delete: ";
    cin>>file;
    if (remove(file.c_str())==0) {
        cout<<"File deleted successfully!"<<endl;
    } else {
        cout<<"File deletion failed!"<< endl;
    }
}

void exit() {
    cout<<"Exiting..."<<endl;
}

int main() {
    int choice;
    cout<<"Welcome to the Basic File Manager!"<<endl;
    while (true) {
        cout<<"Please select an option from the menu below:"<<endl<<endl;
        disMenu();
        cin >> choice;
        switch (choice) {
            case 1:
                navDir();
                break;
            case 2:
                viewFiles();
                break;
            case 3:
                createDir();
                break;
            case 4:
                copyMoveFiles();
                break;
            case 5:
                deleteFile();
                break;
            case 6:
                exit();
                return 0;
            default:
                cout << "Invalid choice!" << endl;
                break;
        }
    }
}
