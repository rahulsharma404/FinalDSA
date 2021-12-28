#include <bits/stdc++.h>
#define N 100
using namespace std;
class Student_Database
{
    char name[N];
    int rollno;
    int division;
    char address[N];

public:
    Student_Database();
    void input_data();
    void display();
    void get_data(int);
    int return_rollno()
    {
        return rollno;
    }
};
class Sequence_File
{
    char filename[N];

public:
    Sequence_File();
    Sequence_File(char F[]);
    void displayrecords();
    void insert();
    bool deleterecord(int);
    void modify(int);
    void search(int);
};

Student_Database::Student_Database()
{
    rollno = -1;
    strcpy(name, "NULL");
    strcpy(address, "NULL");
    division = -1;
}

void Student_Database::input_data()
{
    cout << "\n-------------Student Data Entry--------------" << endl;
    cout << "Roll Number of Student :  ";
    cin >> rollno;
    cout << "Name of Student        :  ";
    cin >> name;
    cout << "Division of student    :  ";
    cin >> division;
    cout << "Address of Student     :  ";
    cin >> address;
    cout << "---------------------------------------------" << endl;
}
void Student_Database::get_data(int r)
{
    rollno = r;
    cout << "Roll Number : ";
    cin >> rollno;
    cout << "Name        : ";
    cin >> name;
    cout << "Division    : ";
    cin >> division;
    cout << "Address     : ";
    cin >> address;
}
void Student_Database::display()
{
    cout << endl << rollno << "\t" << name << "\t\t" << division << "\t\t" << address;
}

Sequence_File::Sequence_File()
{
    ofstream FileA("file.txt");
    strcpy(filename, "file.txt");
    if (FileA)
    {
        cout << "file.txt created Successfully" << endl;
        FileA.close();
    }
    else
        cout << "File is not created";
}
void Sequence_File::displayrecords()
{
    ifstream FileA;
    Student_Database S;
    FileA.open(filename);
    FileA.read((char *)&S, sizeof(S));
    if (!FileA.eof())
    {

        cout << "\n-------------Student Data Display--------------" << endl;

        cout << "\nRollNo \tStudent Name \tDivision \tAddress";
        while (!FileA.eof())
        {
            S.display();
            FileA.read((char *)&S, sizeof(S));
        }
        cout << "\n-----------------------------------------------" << endl;
    }
    else
        cout << "No Records here" << endl;
    FileA.close();
}
void Sequence_File::insert()
{
    ofstream FileA;
    Student_Database S;
    FileA.open(filename, ios::app);
    S.input_data();
    FileA.write((char *)&S, sizeof(S));
    FileA.close();
}

bool Sequence_File::deleterecord(int roll)
{
    cout << "\nRollNo \tStudent Name \tDivision \tAddress";
    ifstream FileA;
    ofstream tempfile;
    Student_Database S;
    int flag = 0;
    FileA.open(filename);
    tempfile.open("temp.txt");
    FileA.read((char *)&S, sizeof(S));
    while (!FileA.eof())
    {
        if (roll == S.return_rollno())
        {
            S.display();
            flag = 1;
        }
        else
            tempfile.write((char *)&S, sizeof(S));
        FileA.read((char *)&S, sizeof(S));
    }
    FileA.close();
    tempfile.close();
    remove(filename);
    rename("Temp.txt", filename);
    if (flag == 0)
    {
        cout << "Record for Roll No. " << roll << " not found here" << endl;
        return 0;
    }
    else
    {
        cout << "\nAbove Record Deleted Successfully from file" << endl;
        return 1;
    }
}

void Sequence_File::modify(int roll)
{
    ifstream FileA;
    ofstream tempfile;
    Student_Database S;
    int flag = 0;
    FileA.open(filename);
    tempfile.open("Temp.txt");
    FileA.read((char *)&S, sizeof(S));
    while (!FileA.eof())
    {
        if (roll == S.return_rollno())
        {
            S.display();

            cout << "\n-------------Modify the details----------------" << endl;
            S.get_data(roll);
            flag = 1;
        }
        tempfile.write((char *)&S, sizeof(S));
        FileA.read((char *)&S, sizeof(S));
    }
    if (flag == 0)
        cout << "Record for Roll No. " << roll << " not found here" << endl;
    else
        cout << "Record Modified Successfully" << endl;
    FileA.close();
    tempfile.close();
    remove(filename);
    rename("Temp.txt", filename);
}
void Sequence_File::search(int roll)
{
    ifstream FileA;
    Student_Database S;
    int flag = 0;
    FileA.open(filename);
    FileA.read((char *)&S, sizeof(S));
    while (!FileA.eof())
    {
        if (roll == S.return_rollno())
        {
            cout << "\nRollNo \tStudent Name \tDivision \tAddress";
            S.display();
            flag = 1;
        }
        FileA.read((char *)&S, sizeof(S));
    }
    if (flag == 0)
        cout << "Record for Roll No. " << roll << " not found here" << endl;
}
int main()
{
    char fname[N];
    int roll;
    Sequence_File sfile;
    int cnt = 0;
    bool dele = 0;

    bool flag = true;
    int ch;
    while (flag)
    {
        cout << "\n--------------------File Handling Menu Bar------------------- " << endl;
        cout << "1] Add" << endl;
        cout << "2] Display" << endl;
        cout << "3] Delete" << endl;
        cout << "4] Search" << endl;
        cout << "5] Modify" << endl;
        cout << "6] Exit" << endl;
        cout << "--------------------------------------------------------------- " << endl;
        cout << "Enter your choice : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            sfile.insert();
            cnt++;
            break;
        case 2:
            sfile.displayrecords();
            break;
        case 3:
            if (cnt != 0)
            {
                cout << "\nEnter Roll No to delete : ";
                cin >> roll;
                dele = sfile.deleterecord(roll);
                if (dele)
                {
                    cnt--;
                }
            }
            else
                cout << "No Records here" << endl;
            break;
        case 4:
            if (cnt != 0)
            {
                cout << "\nEnter Roll No of the student you want to search : ";
                cin >> roll;
                sfile.search(roll);
            }
            else
                cout << "No Records here" << endl;
            break;

        case 5:
            if (cnt != 0)
            {
                cout << "\nEnter Roll No of the student you want to Modify : ";
                cin >> roll;
                sfile.modify(roll);
            }
            else
                cout << "No Records here" << endl;
            break;
        case 6:
            cout << "\nExiting..." << endl;
            flag = false;
        }
    }
    return 0;
}
