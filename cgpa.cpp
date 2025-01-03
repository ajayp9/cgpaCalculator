#include<iostream>
#include<vector>
#include <string>
using namespace std;

class Subject{
  public:
  string subjectname;
  int credit;
  float gradepoint;

  // constructor
  Subject(string name, int cr, float gp){
    subjectname = name;
    credit = cr;
    gradepoint = gp;
  }
};

class Student{
  public:
  string name;
  vector<Subject>subjects;

  //constructer
  Student(string studentName){
    name = studentName;
  }
  void addSubject(string subjectName, int credit, float gradepoint){
    Subject newSubject(subjectName, credit,gradepoint);
    subjects.push_back(newSubject);
  }

  float calculatecgpa(){
    int totalcredit = 0;
    float weightgradepoint = 0;
    for(const Subject & subject:subjects){
      totalcredit+=subject.credit;
      weightgradepoint+=subject.credit*subject.gradepoint;
    }
    return (totalcredit>0)?(weightgradepoint/totalcredit):0;
  }
  void displaycgpa(){
    cout<<"Student Name: "<<name<<endl;
    float cgpa = calculatecgpa();
    cout<<"CGPA: "<<cgpa<<endl;
  }
};

int main(){
  string studentname;
  int numsub;

  cout<<"Enter Student name: ";
  getline(cin, studentname);

  cout<<"Enter the number of subjects: ";
  cin>>numsub;

  Student student(studentname);

  for(int i=0;i<numsub;i++){
    string subjectname;
    int credit;
    float gradepoint;

    cout<<"Enter the subject name: ";

    cin.ignore();
    getline(cin, subjectname);

    cout<<"Enter the credit: ";
    cin>>credit;

    cout<<"Enter the gradepoint: ";
    cin>>gradepoint;
    student.addSubject(subjectname, credit, gradepoint);
  }

  student.displaycgpa();

  return 0;
}
