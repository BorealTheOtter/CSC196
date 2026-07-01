/*
    C++ Review Assignment
    ---------------------

    Instructions:
    Complete each task in this file.

    Requirements:
    - Your program must compile and run.
    - Complete each TODO section.
    - Answer each question using comments in the code.
    - Print enough output to show that each task works.

    Suggested workflow:
    - Complete one task at a time.
    - Build and run after each task.
    - Read compiler errors carefully.
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// ============================================================
// Task 4 - Function Declarations
// ============================================================


// This function should take an int by value and increment it.
void IncrementValue(int value);


// This function should take an int by reference and increment it.
void IncrementReference(int& value);

// ============================================================
// Task 7 - Struct
// ============================================================


// - firstName: std::string
// - lastName: std::string
// - id: int
// - gpa: double
struct Student
{
    string firstName;
    string lastName;
    int id;
    double gpa;
};

// ============================================================
// Task 8 - Class
// ============================================================


// Requirements:
// - private firstName, lastName, id, and gpa fields
// - a constructor that initializes all fields
// - getter functions for each field
// - setter functions for each field
class StudentClass
{
public:

    StudentClass(string first, string last, int id, double gpa) : firstName(first), lastName(last), id(id), gpa(gpa) {

    }

    string getFirstName() const {
        return firstName;
    }
    string getLastName() const {
        return lastName;
    }
    int getId() const {
        return id;
    }
    double getGpa() const {
        return gpa;
    }

    void setFirstName(const string firstName) {
        this->firstName = firstName;
    }
    void setLastName(const string lastName) {
        this->lastName = lastName;
    }
    void setId(const int id) {
        this->id = id;
    }
    void setGpa(const double gpa) {
        this->gpa = gpa;
    }
private:

    string firstName;
    string lastName;
    int id;
    double gpa;
};

// ============================================================
// Task 10 - Const Correctness
// ============================================================


// This function should print a StudentClass object.
// It should take the student as a const reference.
void PrintStudent(const StudentClass& student);

// ============================================================
// Task 11 - Enums
// ============================================================


// Include the days of the week.
// Example: Monday, Tuesday, etc.
enum class Day
{
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY
};

int main()
{
    cout << "C++ Review Assignment" << endl;
    cout << "=====================" << endl << endl;

    // ========================================================
    // Task 1 - Built-in Data Types
    // ========================================================

    cout << "Task 1 - Built-in Data Types" << endl;

    bool currStudent = true;
    char lastInitial = 'R';
    int creditsEarned = 43;
    float gpa = 3.82f;
    double tuition = 8670.00; //kinda a bad double example but whatever



    cout << "currStudent (bool): " << currStudent << endl;
    cout << "lastInitial (char): " << lastInitial << endl;
    cout << "creditsEarned (int): " << creditsEarned << endl;
    cout << "gpa (float): " << gpa << endl;
    cout << "tuition (double): " << tuition << endl;

    cout << endl;

    // ========================================================
    // Task 2 - References
    // ========================================================

    cout << "Task 2 - References" << endl;


    int refInt1 = 42;

    int& refInt2 = refInt1;

    refInt2 = 69;

    cout << refInt1 << endl;

    cout << refInt2 << endl;
    // Question:
    // What is the value of the original int after changing the reference?
    // Why is it different from its initial value?
    // Answer in comments below:

    // the original int (refInt1) is 69 after changing the reference
    // this is due to refInt2 (the actual reference) only being a reference to refInt1 instead of having its own value

    cout << endl;

    // ========================================================
    // Task 3 - Pointers
    // ========================================================

    cout << "Task 3 - Pointers" << endl;


    int pointInt1 = 2763;

    int* pointInt2 = &pointInt1;

    cout << pointInt1 << endl;
    cout << addressof(pointInt1) << endl;
    cout << pointInt2 << endl;
    cout << *pointInt2 << endl;
    *pointInt2 = 191;
    cout << pointInt1 << endl;
    // Question:
    // Why did modifying the dereferenced pointer change the original variable?
    // Answer in comments below:

    //dereferencing basically just says "hey, modify the memory at this address i'm pointing at" instead of "modify me"

    cout << endl;

    // ========================================================
    // Task 4 - Value vs Reference Parameters
    // ========================================================

    cout << "Task 4 - Value vs Reference Parameters" << endl;

    int imRunningOutOfNames = 11111;
    cout << imRunningOutOfNames << endl;
    IncrementValue(imRunningOutOfNames);
    cout << imRunningOutOfNames << endl;
    cout << imRunningOutOfNames << endl;
    IncrementReference(imRunningOutOfNames);
    cout << imRunningOutOfNames << endl;
    // Question:
    // Why does IncrementValue not change the original variable,
    // but IncrementReference does?
    // Answer in comments below:

    //because in the first one you're giving it a copy of the number, while in the second one you're giving it the variables address

    cout << endl;

    // ========================================================
    // Task 5 - Arrays and Vectors
    // ========================================================

    cout << "Task 5 - Arrays and Vectors" << endl;

    int intArray[5] = { 1, 2, 3, 4, 5 };
    vector<int> intVector = { 1, 2, 3, 4, 5 };
    cout << intArray << endl;
    for (int num : intVector) {
        cout << num << " ";
    }
    cout << endl;
    intVector.push_back(6);
    for (int num : intVector) {
        cout << num << " ";
    }
    cout << endl;
    // Question:
    // Why can the vector grow, but the array cannot?
    // Answer in comments below:

    //due to how arrays are allocated & how vectors have extra functions inside of it

    cout << endl;

    // ========================================================
    // Task 6 - Loops
    // ========================================================

    cout << "Task 6 - Loops" << endl;

    for (int i = 0; i < 5; ++i) {
        cout << intVector[i] << " ";
    }
    cout << endl;
    for (int num : intVector) {
        cout << num << " ";
    }
    cout << endl;

    // ========================================================
    // Task 7 - Structs
    // ========================================================

    cout << "Task 7 - Structs" << endl;

    Student studentA;
    Student studentB;

    studentA.firstName = "John";
    studentA.lastName = "Deere";
    studentA.id = 10;
    studentA.gpa = 3.82f;

    studentB.firstName = "Toby";
    studentB.lastName = "Fox";
    studentB.id = 2341;
    studentB.gpa = 1.84f;

    cout << studentA.firstName << " " << studentA.lastName << " " << studentA.id << " " << studentA.gpa << endl;
    cout << studentB.firstName << " " << studentB.lastName << " " << studentB.id << " " << studentB.gpa << endl;
    cout << endl;

    // ========================================================
    // Task 8 - Classes
    // ========================================================

    cout << "Task 8 - Classes" << endl;

    StudentClass studentC("Joey", "Valence", 16803, 3.95);
    StudentClass studentD("Will", "Wood", 579, 2.7);

    cout << studentC.getFirstName() << " ";
    cout << studentC.getLastName() << " ";
    cout << studentC.getId() << " ";
    cout << studentC.getGpa() << endl;

    cout << studentD.getFirstName() << " ";
    cout << studentD.getLastName() << " ";
    cout << studentD.getId() << " ";
    cout << studentD.getGpa() << endl;

    studentC.setId(8);

    cout << studentC.getFirstName() << " ";
    cout << studentC.getLastName() << " ";
    cout << studentC.getId() << " ";
    cout << studentC.getGpa() << endl;
    // Question:
    // Why might a class with private data be preferable to a struct with public data?
    // Answer in comments below:

    //business rules, no one can access the address in memory without going through the getter first (usually the setters would also be private / have business rules but that's me personally)

    cout << endl;

    // ========================================================
    // Task 9 - Dynamic Memory
    // ========================================================

    cout << "Task 9 - Dynamic Memory" << endl;


    int* taskNine = new int;
    *taskNine = 92;
    cout << *taskNine << endl;
    delete taskNine;
    taskNine = nullptr;
    // Question:
    // Why should a pointer be set to nullptr after deleting it?
    // Answer in comments below:

    //to stop a potential issue if you end up calling the pointer later

    cout << endl;

    // ========================================================
    // Task 10 - Const Correctness
    // ========================================================

    cout << "Task 10 - Const Correctness" << endl;

    PrintStudent(studentC);
    // Then comment out that line so the program compiles.

    // Question:
    // Why does the compiler prevent modification of a const reference parameter?
    // Answer in comments below:

    //IDK? that's just how its designed.

    cout << endl;

    // ========================================================
    // Task 11 - Enums
    // ========================================================

    cout << "Task 11 - Enums" << endl;

    Day dayofWeek = Day::MONDAY;
    switch (dayofWeek) {
    case Day::MONDAY: cout << "Monday"; break;
    case Day::TUESDAY: cout << "Tuesday"; break;
    case Day::WEDNESDAY: cout << "Wednesday"; break;
    case Day::THURSDAY: cout << "Thursday"; break;
    case Day::FRIDAY: cout << "Friday"; break;
    case Day::SATURDAY: cout << "Saturday"; break;
    case Day::SUNDAY: cout << "Sunday"; break;
    default: cout << "?"; break;
    }
    cout << endl;

    return 0;
}

// ============================================================
// Function Definitions
// ============================================================

void IncrementValue(int value)
{
    value++;
}

void IncrementReference(int& value)
{
    value++;
}

void PrintStudent(const StudentClass& student)
{
    cout << "Name: " << student.getFirstName() << " " << student.getLastName() << endl;
    cout << "ID: " << student.getId() << endl;
    cout << "GPA: " << student.getGpa() << endl;

    //student.setGpa(2.543);

    // What happens?

    //      An error (Cannot convert this argument from type const StudentClass to type StudentClass: function is missing const qualifier) due to the setter method not being const

    // After observing the compiler error, comment out the modification.
}

