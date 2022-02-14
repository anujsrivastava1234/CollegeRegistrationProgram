#include <iostream>
#include <fstream>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

char stdsRec[] = "stdtRecord.txt";
char modulesRecord[] = "modRecord.txt";
char tempFile[] = "tempFile.txt";

class Std
{

public:
  // add one std's record to DB
  int addStdRecord(char *stdsRec)
  {
    int StdNo;
    char name[50];

    ofstream out(stdsRec, ios_base::app);

    cout << "\nEnter Std No : ";
    cin >> StdNo;
    out << endl
        << StdNo << " | ";

    cout << "\nEnter Name (50 char):";
    cin >> name;
    out << name << " | ";

    int flag = -1;
    cout << "\n0 - Under Grad.,1 - PostGrad";
    cout << "\nEnter :";
    cin >> flag;

    int moduleCount = -1;

    if (flag == 0)
      moduleCount = 6;
    else if (flag == 1)
      moduleCount = 4;
    else
    {
      cout << "\nErr: Pl. enter either 0or1 ";
      return -1;
    }

    for (int i = 0; i < moduleCount; i++)
    {
      int module;
      cout << "\nEnter Module  No" << i << " : ";
      cin >> module;
      out << module << " | ";
    }

    char choice;
    cout << "\nadd Marks against each module? y/n :";
    cin >> choice;

    // separator to find start of marks
    out << " = ";

    if (choice == 'y')
    {
      for (int i = 0; i < moduleCount; i++)
      {
        double marks;
        cout << "\nEnter Marks of Module  No" << i << " : ";
        cin >> marks;
        out << marks << " | ";
      }
    }

    out.close();
  }

  // update any std's recrod to DB
  int updateStdRecord()
  {
    int StdNo;
    cout << "\nEnter Std Number :";
    cin >> StdNo;
    // modify if it exist e
  }

  // display record of any Std by his Stdno
  int displayStdRecord()
  {
    int StdNo;

    // display if Std record exist
    cout << "\n# Find Any Module Details #\n";

    cout << "\nEnter Std No to be searched: ";
    cin >> StdNo;

    int flag = -1;
    ifstream file(stdsRec);
    string str;

    while (getline(file, str))
    {
      if (str.length() > 0)
      {

        char temp[1000];
        memset(temp, 1000, sizeof(temp));
        strcpy(temp, str.c_str());

        char *ptr;
        ptr = strtok(temp, "|");

        int tempno = atoi(ptr);

        if (StdNo == tempno)
        {
          cout << "\n"
               << str;
          flag = 1;
          break;
        }
      }
    }

    if (flag == -1)
      cout << "\nNo Std found with No :" << StdNo;

    file.close();
    getchar();
    getchar();
  }

  // display record of all Stds
  int displayAllStdRecord()
  {
    ifstream file(stdsRec);
    string str;

    cout << "\n# List of All Std #";

    if (!file)
    {
      cout << "\nNo Record found !!";
      return -1;
    }

    while (getline(file, str))
    {
      if (str.length() > 0)
        cout << "\n\t" << str;
    }
    file.close();
    getchar();
  }
  int findStdMarks()
  {
    cout << "\n# find Marks of any std #\n ";
    int StdNo;

    cout << "\nEnter Std No: ";
    cin >> StdNo;

    int flag = -1;
    ifstream file(stdsRec);
    string str;

    while (getline(file, str))
    {
      if (str.length() > 0)
      {
        char temp[1000];
        memset(temp, 1000, sizeof(temp));
        strcpy(temp, str.c_str());

        char *ptr;
        ptr = strtok(temp, "|");

        int tempno = atoi(ptr);

        if (StdNo == tempno)
        {
          memset(temp, 1000, sizeof(temp));
          strcpy(temp, str.c_str());
          char *ptr1 = strtok(temp, "=");
          ptr1 = strtok(NULL, "=");
          ptr1 = strtok(ptr1, "|");
          // double sum = atof(ptr1, "|");
          double sum = atof(ptr1);
          double minNo = sum;
          int countSub = 0;
          while (ptr1 = strtok(NULL, "|"))
          {
            if (atof(ptr1) < minNo)
              minNo = atof(ptr1);

            sum += atof(ptr1);
            countSub++;
          }

          if (countSub == 6)
          {
            sum -= minNo;
            cout << "\nsum is : " << sum;
            sum = sum / 5;
            cout << "\nAvg Sum is top 5 sub: " << sum;

            if (sum > 70)
              cout << "\nGrade : A";
            else if (sum >= 60 && sum <= 69)
              cout << "\nGrade is : B+";
            else if (sum >= 50 && sum <= 59)
              cout << "\nGrade is : B";
            else if (sum >= 41 && sum <= 49)
              cout << "\nGrade is : C";
            else if (sum >= 40)
              cout << "\nGrade is : D";
            else if (sum < 40)
              cout << "\nGrade is : F";
          }
          else
          {
            sum = sum / 4;
            cout << "\nAvg Sum of 4 Sub: " << sum;
            if (sum >= 76)
              cout << "\nDistinction";
            else if (sum >= 61 && sum <= 75)
              cout << "\nMerit";
            else if (sum >= 50 && sum <= 60)
              cout << "\nPass";
            else if (sum < 50)
              cout << "\nFail";
          }

          flag = 1;
          break;
        }
      }
    }

    if (flag == 1)
      cout << "\nNo Std Found with No : " << StdNo;

    file.close();
    getchar();
    getchar();
  }

  int updateStd()
  {
    cout << "\n# Update Std Record  #\n";
    int StdNo;

    cout << "\nEnter Std No: ";
    cin >> StdNo;

    cout << "\nEnter Std No : ";
    cin >> StdNo;

    int flag = -1;
    ifstream file(stdsRec);
    string str;

    int StdFound = 0;
    while (getline(file, str))
    {
      if (str.length() > 0)
      {

        char temp[1000];
        memset(temp, 1000, sizeof(temp));
        strcpy(temp, str.c_str());

        char *ptr;
        ptr = strtok(temp, "|");

        int tempno = atoi(ptr);

        if (StdNo == tempno)
        {
          addStdRecord(tempFile);
          StdFound = 1;
        }
        else
        {
          ofstream file(tempFile, ios_base::app);
          file << endl
               << str;
          file.close();
        }
      }
    }

    file.close();

    if (StdFound)
    {
      remove(stdsRec);
      rename(tempFile, stdsRec);
    }
  }
};

class Module
{

public:
  int dispalyAnyModuleInfo()
  {
    int moduleno;
    cout << "\n 3 Find Module Details  #\n";

    cout << "\nEnter Module No : ";
    cin >> moduleno;
    int flag = -1;
    ifstream file(modulesRecord);
    string str;

    while (getline(file, str))
    {
      if (str.length() > 0)
      {
        char temp[1000];
        memset(temp, 1000, sizeof(temp));
        strcpy(temp, str.c_str());

        char *ptr;
        ptr = strtok(temp, "|");

        int tempNo = atoi(ptr);
        cout << "\nModule no is : " << temp;

        if (moduleno == tempNo)
        {
          cout << "\n"
               << str;
          flag = 1;
          break;
        }
      }
    }

    if (!flag)
      cout << "\nModule found : " << moduleno;

    file.close();
    getchar();
    getchar();
  }

  int displayAllModuleInfo()
  {
    cout << "\n# List of All Modulkes  #\n";

    // reads all modules from record

    ifstream file(modulesRecord);
    string str;
    cout << "\nModule No | Title | level";
    while (getline(file, str))
    {
      if (str.length() > 0)
        cout << "\n"
             << str;
    }
    file.close();
    getchar();
    getchar();
  }

  int updateModulesInfo()
  {
    cout << "\n3 Update Modules Infop  #\n";
    int moduleNo;
    cout << "\nEnter Module No to be modified: ";
    cin >> moduleNo;
  }

  // add new module to Db
  int addModule(char *modulerecord)
  {
    int moduleNo;
    char title[50];
    char level[50];

    ofstream out(modulerecord, ios_base::app);

    cout << "\n# Add new Module #";
    cin >> moduleNo;
    cout << endl
         << moduleNo << " | ";
    cout << "\nEnter Title of Module ( 50 char) : ";
    cin >> level;
    cout << level << " | ";

    cout << "\nModule Added !!";
    getchar();

    out.close();
  }

  int updateModule()
  {
    cout << "\n#Update Module Record #\n";
    int moduleNo;

    cout << "\nEnter Module No : ";
    cin >> moduleNo;

    int flag = -1;
    ifstream file(modulesRecord);
    string str;

    int moduleFound = 0;
    while (getline(file, str))
    {
      if (str.length() > 0)
      {
        char temp[1000];
        memset(temp, 1000, sizeof(temp));
        strcpy(temp, str.c_str());

        char *ptr;
        ptr = strtok(temp, "|");

        int tempno = atoi(ptr);
        if (moduleNo == tempno)
        {
          addModule(tempFile);
          moduleNo = 1;
        }
        else
        {
          ofstream file(tempFile, ios_base::app);
          file << endl
               << str;
          file.close();
        }
      }
    }

    file.close();

    if (moduleFound)
    {
      remove(modulesRecord);
      rename(tempFile, modulesRecord);
    }
  }
};

int main(int argc, char **argv)
{
  Std stdobj;
  Module modObject;

  int choice = -1;
  while (choice != 0)
  {
    system("cls");

    cout << "\n\t\t\t\t# College Registration System #";
    cout << "\n\t\t\t\t1> Add Record";
    cout << "\n\t\t\t\t2> Update Record";
    cout << "\n\t\t\t\t3> Get Any Record";
    cout << "\n\t\t\t\t4> Get all Record";
    cout << "\n\t\t\t\t5> Add Module";
    cout << "\n\t\t\t\t6> Get any Module details";
    cout << "\n\t\t\t\t7> Get All Modules Details";
    cout << "\n\t\t\t\t8> Update Modules";
    cout << "\n\t\t\t\t9> find Std Marks";
    cout << "\n\t\t\t\t0> Exit..";

    cout << "\nEnter Your choice : ";
    cin >> choice;

    switch (choice)
    {
    case 1:
      stdobj.addStdRecord(stdsRec);
      break;
    case 2:
      stdobj.updateStd();
      break;
    case 3:
      stdobj.displayStdRecord();
      break;
    case 4:
      stdobj.displayAllStdRecord();
      break;
    case 5:
      modObject.addModule(modulesRecord);
      break;
    case 6:
      modObject.dispalyAnyModuleInfo();
      break;
    case 7:
      modObject.displayAllModuleInfo();
      break;
    case 8:
      modObject.updateModule();
      break;
    case 9:
      stdobj.findStdMarks();
      break;
    case 0:
      cout << "\nThank You !1 Good Bye\n";
      break;
    default:
      cout << "\nInvalid choice...";
      getchar();
    }
    /* code */
  }

  return 0;
}