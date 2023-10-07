#include <iostream> 
#include <vector> 

using namespace std; 

/*
    ADVANTAGE?
    - Cung cấp cùng một cách sử dụng đối với từng đối tượng riêng lẻ hoặc nhóm các đối tượng với nhau.
    
    WHEN TO USE?
    - Composite Pattern chỉ nên được áp dụng khi nhóm đối tượng phải hoạt động 
    như một đối tượng duy nhất (theo cùng một cách).
    - Composite Pattern có thể được sử dụng để tạo ra một cấu trúc giống như cấu trúc cây.
*/


class File { 
    public:
        virtual int TotalSize(){}
        virtual int ShowProperty(){}
}; 

class Directory : public File { 
    string name;
    vector<File> files;
    public:
        Directory(string name){
            this->name = name;
        }
        void AddFile(File file){
            files.push_back(file);
        }

        int TotalSize(){
            return files.size();
        }

        int ShowProperty(){
            cout<<"Dir name: "<< name << endl;
            cout<<"Dir's files: "<< files.size() << endl;
        }
}; 

class FileLeaf : public File {
    int size;
    string name;
    public:
        FileLeaf(int size, string name){
            this->size = size;
            this->name = name;
        }
        int TotalSize() {
            return size;
        }
        int ShowProperty(){
            cout<<"File name: "<< name << endl;
        }

}; 

int main() 
{ 
    FileLeaf file1 = FileLeaf(5, "file1");
    FileLeaf file2 = FileLeaf(8, "file2");
    file1.ShowProperty();

    Directory dir = Directory("root");
    dir.AddFile(file1);
    dir.AddFile(file2);

    // dir.TotalSize()
    dir.ShowProperty();

	return 0; 
} 
