
#include <iostream>
using namespace std;
class StudentDataBase;
class student{
    string name;
    int rollNumber;
    int marks;
    student*next;
friend StudentDataBase;
};
class StudentDataBase{
    student*head;
public:
  StudentDataBase(void){
      head=NULL;
  }
    void AddStudent(string name,int rollNumber,int marks){
        student* newStudent=new student;
        newStudent->name=name;
        newStudent->rollNumber=rollNumber;
        newStudent->marks=marks;
        newStudent->next=NULL;
        if (head==NULL){
            head=newStudent;
        }
        else{
            student*ptr=head;;
            while(ptr->next!=NULL){
                ptr=ptr->next;
            }
            ptr->next=newStudent;
        }
    }
    void UpdateStudent(int RollNumber) {
    student* ptr = head;
    while (ptr != nullptr && ptr->rollNumber != RollNumber) {
        ptr = ptr->next;
    }
    if (ptr == nullptr) {
        cout << "Student with roll number " << RollNumber << " not found." << endl;
        return;
    }

    short temp = 0;
    cout << "Press 1 to update name, 2 to update marks, 3 to update both name and marks: ";
    cin >> temp;
    if (temp==1){
         string newName;
        cout << "Enter the new name of the student: ";
        cin >> newName;
        ptr->name = newName;
    }
    else if(temp==2){
           int newMarks;
        cout << "Enter the new marks of the student: ";
        cin >> newMarks;
        ptr->marks = newMarks;
    }
    else if(temp==3){
          string newName;
        cout << "Enter the new name of the student: ";
        cin >> newName;
        ptr->name = newName;
        int newMarks;
        cout << "Enter the new marks of the student: ";
        cin >> newMarks;
        ptr->marks = newMarks;
    }
    else{
        cout<<"Invalid Input!!!!";
    }
}
    void DisplayStudent(void){
        student*ptr=head;
        cout<<"Name--RollNumber--Marks:"<<endl;
        while(ptr!=NULL){
            cout<<ptr->name<<" "<<ptr->rollNumber<< " "<<ptr->marks<<endl;
            ptr=ptr->next;
        }
    }
    void DeleteNode(int RollNumber) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    // Case 1: If the node to be deleted is the head node...
    if (head->rollNumber == RollNumber) {
        student* temp = head;
        head = head->next;
        delete temp;
        cout << "Node with roll number " << RollNumber << " deleted successfully." << endl;
        return;
    }

    // Case 2: If the node to be deleted is in the middle of the list..
    student* current = head;
    student* prev = nullptr;
    while (current != nullptr && current->rollNumber != RollNumber) {
        prev = current;
        current = current->next;
    }

    if (current == nullptr) {
        cout << "Node with roll number " << RollNumber << " not found." << endl;
        return;
    }

    prev->next = current->next;
    delete current;
    cout << "Node with roll number " << RollNumber << " deleted successfully." << endl;
}


};
int main() {
StudentDataBase*database=new StudentDataBase;
database->AddStudent("Ayush",81,100);
database->AddStudent("Aman",30,90);
database->AddStudent("tarun",364,89);
database->AddStudent("Avinash",78,95);
database->DeleteNode(364);
database->DisplayStudent();
    return 0;
}
