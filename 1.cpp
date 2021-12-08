#include <bits/stdc++.h>
using namespace std;
struct Student
{
    int roll_no;
    string name;
    double SGPA;
};
class Student_Data
{
public:
    int n;
    Student v[20];
    Student temp;
    void get_data();
    void display();
    void roll_call();
    void alpha_name();
    int partition(int low, int high);
    void quickSort(int low, int high);
    void linearSearch();
    void binarySearch();
};
void Student_Data ::get_data()
{
    cout << "-------------------------------------------" << endl;
    cout << "Enter number of students : ";
    cin >> n;
    cout << "-------------------------------------------" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "::"
             << "Data Entry for Student " << i + 1 << "::" << endl;
        cout << "Enter Roll Number : ";
        cin >> v[i].roll_no;

        cout << "Enter name of Student : ";
        cin >> v[i].name;

        cout << "Enter SGPA of Student : ";
        cin >> v[i].SGPA;
        while (v[i].SGPA > 10)
        {
            cout << "Please enter less than 10 again" << endl;
            cout << "Enter the SGPA of Student: ";
            cin >> v[i].SGPA;
        }
        cout << "-------------------------------------------" << endl;
    }
}
void Student_Data ::display()
{
    cout << "ROLL NO"
         << "\t\t\t\t\t\t"
         << "NAME"
         << "\t\t\t\t\t\t"
         << "SGPA" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << v[i].roll_no << "\t\t\t\t\t\t" << v[i].name << "\t\t\t\t\t\t" << v[i].SGPA << endl;
    }
    cout << "-------------------------------------------" << endl;
}
void Student_Data ::roll_call()
{
    bool flag;
    for (int i = 0; i < n - 1; i++)
    {
        flag = false;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (v[j].roll_no > v[j + 1].roll_no)
            {
                swap(v[j], v[j + 1]);
                flag = true;
            }
        }

        if (flag == false)
        {
            break;
        }
    }
    cout << "Data according to roll call : " << endl;
    display();
}
void Student_Data ::alpha_name()
{
    for (int i = 1; i < n; i++)
    {
        temp = v[i];
        string key = v[i].name;
        int j = i - 1;
        while (j >= 0 && v[j].name > key)
        {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = temp;
    }
    cout << "Data according to name : " << endl;
    display();
}
int Student_Data ::partition(int low, int high)
{
    int pivot = v[low].SGPA;
    int i = low;
    int j = high;
    while (i < j)
    {
        while (v[i].SGPA >= pivot)
        {
            i++;
        }
        while (v[j].SGPA < pivot)
        {
            j--;
        }
        if (i < j)
        {
            swap(v[i], v[j]);
        }
    }
    swap(v[low], v[j]);
    return j;
}
void Student_Data ::quickSort(int low, int high)
{
    if (low < high)
    {
        int pivot = partition(low, high);
        quickSort(low, pivot - 1);
        quickSort(pivot + 1, high);
    }
}
void Student_Data ::linearSearch()
{
    string str;
    cout << "Enter the name of the student : ";
    cin >> str;
    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        if (str == v[i].name)
        {
            flag = true;
            cout << "-------------------------------------------" << endl;
            cout << "DataSet of " << str << endl;
            cout << "ROLL NO"
                 << "\t\t\t\t\t\t"
                 << "NAME"
                 << "\t\t\t\t\t\t"
                 << "SGPA" << endl;
            cout << v[i].roll_no << "\t\t\t\t\t\t" << v[i].name << "\t\t\t\t\t\t" << v[i].SGPA << endl;
            cout << "-------------------------------------------" << endl;
        }
    }
    if (flag == false)
    {
        cout << "Element not found" << endl;
    }
}
void Student_Data ::binarySearch()
{
    cin.ignore();
    double key;
    cout << "Enter the SGPA : ";
    cin >> key;
    

    while (key > 10)
    {
        cout << "Please enter less than 10 again" << endl;
        cout << "Enter the SGPA : ";
        cin >> key;
    }
    int low = 0;
    int high = n - 1;
    bool flag = false;
    cout << "-------------------------------------------" << endl;
    
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (v[mid].SGPA == key)
        {
            flag = true;
            cout << "ROLL NO :   " << v[mid].roll_no << "\t\t\t\t\t\t NAME :   " << v[mid].name << "\t\t\t\t\t\t  SGPA :   " << v[mid].SGPA << endl;
            break;
        }
        else if (key > v[mid].SGPA)
        {
            low = mid + 1;
        }
        else if (key < v[mid].SGPA)
        {
            high = mid - 1;
        }
    }

    cout << "-------------------------------------------" << endl;
}
int main()
{
    Student_Data obj;
    obj.get_data();
    int x = 1;
    while (x)
    {
        int choice;
        cout << "-----------------------------------------" << endl;
        cout << "1. Sort data by Roll Call" << endl;
        cout << "2. Sort data by Alphabetical order" << endl;
        cout << "3. Sort data by SGPA" << endl;
        cout << "4. Access data by name" << endl;
        cout << "5. Access data by SGPA" << endl;
        cout << "0. To exit" << endl;
        cout << "-----------------------------------------" << endl
             << endl;
        cout << "Choice : ";
        cin >> choice;
        switch (choice)
        {
        case 0:
            x = 0;
            cout << "Exit..." << endl;
            break;
        case 1:
            obj.roll_call();
            break;
        case 2:
            obj.alpha_name();
            break;
        case 3:
            obj.quickSort(0, obj.n - 1);
            obj.display();
            break;
        case 4:
            obj.linearSearch();
            break;
        case 5:
            obj.binarySearch();
            break;
        default:
            cout << "Wrong choice" << endl;
            break;
        }
    }

    return 0;
}


/*

-------------------------------------------
Enter number of students : 5
-------------------------------------------
::Data Entry for Student 1::
Enter Roll Number : 1
Enter name of Student : ria
Enter SGPA of Student : 6.7
-------------------------------------------
::Data Entry for Student 2::
Enter Roll Number : 2
Enter name of Student : ram
Enter SGPA of Student : 7.7
-------------------------------------------
::Data Entry for Student 3::
Enter Roll Number : 3
Enter name of Student : shayam
Enter SGPA of Student : 7.9
-------------------------------------------
::Data Entry for Student 4::
Enter Roll Number : 4
Enter name of Student : raj
Enter SGPA of Student : 8.9
-------------------------------------------
::Data Entry for Student 5::
Enter Roll Number : 5 
Enter name of Student : shivang
Enter SGPA of Student : 10 
-------------------------------------------
-----------------------------------------
1. Sort data by Roll Call
2. Sort data by Alphabetical order
3. Sort data by SGPA
4. Access data by name
5. Access data by SGPA
0. To exit
-----------------------------------------

Choice : 5
Enter the SGPA : 10
-------------------------------------------
ROLL NO :   5                                            NAME :   shivang                                                 SGPA :   10       
-------------------------------------------
-----------------------------------------
1. Sort data by Roll Call
2. Sort data by Alphabetical order
3. Sort data by SGPA
4. Access data by name
5. Access data by SGPA
0. To exit
-----------------------------------------

Choice : 4
Enter the name of the student : ram
-------------------------------------------
DataSet of ram
ROLL NO                                         NAME                                            SGPA
2                                               ram                                             7.7
-------------------------------------------
-----------------------------------------
1. Sort data by Roll Call
2. Sort data by Alphabetical order
3. Sort data by SGPA
4. Access data by name
5. Access data by SGPA
0. To exit
-----------------------------------------

Choice : 1
Data according to roll call : 
ROLL NO                                         NAME                                            SGPA
1                                               ria                                             6.7
2                                               ram                                             7.7
3                                               shayam                                          7.9
4                                               raj                                             8.9
5                                               shivang                                         10
-------------------------------------------
-----------------------------------------
1. Sort data by Roll Call
2. Sort data by Alphabetical order
3. Sort data by SGPA
4. Access data by name
5. Access data by SGPA
0. To exit
-----------------------------------------

Choice : 2
Data according to name : 
ROLL NO                                         NAME                                            SGPA
4                                               raj                                             8.9
2                                               ram                                             7.7
1                                               ria                                             6.7
3                                               shayam                                          7.9
5                                               shivang                                         10
-------------------------------------------
-----------------------------------------
1. Sort data by Roll Call
2. Sort data by Alphabetical order
3. Sort data by SGPA
4. Access data by name
5. Access data by SGPA
0. To exit
-----------------------------------------

Choice : 3
ROLL NO                                         NAME                                            SGPA
5                                               shivang                                         10
4                                               raj                                             8.9
3                                               shayam                                          7.9
2                                               ram                                             7.7
1                                               ria                                             6.7
-------------------------------------------
-----------------------------------------
1. Sort data by Roll Call
2. Sort data by Alphabetical order
3. Sort data by SGPA
4. Access data by name
5. Access data by SGPA
0. To exit
-----------------------------------------

Choice : 0
Exit...


*/
