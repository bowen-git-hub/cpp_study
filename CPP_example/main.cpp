/**
 * ============================================================================
 * C++ PROGRAMMING DEMO - Chapters 1-8 Comprehensive Learning Code
 * ============================================================================
 * 
 * This demo covers all major topics from the first 400 pages of 
 * "C++ Programming: An Object-Oriented Approach" by Forouzan & Gilberg
 * 
 * Topics Covered:
 * Chapter 1: Computer Systems, Languages, Paradigms, Program Design
 * Chapter 2: C++ Basics, Variables, Data Types, Constants, cin/cout
 * Chapter 3: Expressions, Statements, Type Conversion, Overflow, Formatting
 * Chapter 4: Selection (if, if-else, switch, conditional expressions)
 * Chapter 5: Repetition (while, for, do-while, nested loops)
 * Chapter 6: Functions (library, user-defined, parameters, overloading)
 * Chapter 7: Classes (OOP, constructors, destructors, members)
 * Chapter 8: Arrays (1D, 2D, array operations)
 * 
 * Author: Learning Demo
 * ============================================================================
 */

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <string>
#include <cassert>
#include <limits>
#include <typeinfo>

using namespace std;

// ============================================================================
// SECTION 1: CHAPTER 1 - INTRODUCTION TO COMPUTERS AND PROGRAMMING
// ============================================================================
//知识点1.1: Computer System Components
// - CPU, Primary Memory, Secondary Storage, Input/Output, Communication
//知识点1.2: Computer Languages (Machine, Assembly, High-Level)
//知识点1.3: Language Paradigms (Procedural, Object-Oriented, Functional, Logic)
//知识点1.4: Program Design (Understanding problem, developing solution)
//知识点1.5: Program Development (Write, Compile, Link, Execute)
//知识点1.6: Testing (Design test data, specification/code/logic errors)

/**
 * 知识点1.3.1: Procedural Paradigm Example
 * A program is a set of commands that change memory state
 * This function demonstrates the procedural approach
 */
void proceduralExample() {
    cout << "\n=== 知识点1.3.1: Procedural Paradigm ===" << endl;
    // Procedural paradigm: commands change memory state
    int a, b, sum;
    
    cout << "Enter first number: ";
    cin >> a;
    cout << "Enter second number: ";
    cin >> b;
    
    sum = a + b;  // Command changes memory state
    cout << "Sum: " << sum << endl;
}

/**
 * 知识点1.4.2: Algorithm - Find largest number in a list
 * Algorithm is a set of logical steps independent of computer system
 */
int findLargest(int arr[], int size) {
    if (size <= 0) return -1;
    
    int largest = arr[0];  // Initialize with first element
    for (int i = 1; i < size; i++) {
        if (arr[i] > largest) {
            largest = arr[i];  // Update if current is larger
        }
    }
    return largest;
}

// ============================================================================
// SECTION 2: CHAPTER 2 - BASICS OF C++ PROGRAMMING
// ============================================================================
//知识点2.1: C++ Programs (Structure, main function, cout, endl)
//知识点2.2: Variables, Values, and Constants
//知识点2.3: Components (Tokens, Identifiers, Keywords, Literals, Comments)
//知识点2.4: Data Types (Integer, Character, Boolean, Floating-point, Void)

/**
 * 知识点2.1.1: First C++ Program Structure
 * - #include <iostream> is a preprocessor directive
 * - int main() is the required function
 * - cout is the output object
 * - endl inserts newline and flushes buffer
 */
void firstProgramDemo() {
    cout << "\n=== 知识点2.1.1: First C++ Program ===" << endl;
    cout << "This is a simple program in C++";
    cout << " to show the main structure." << endl;
    cout << "We learn more about the language";
    cout << " in this chapter." << endl;
}

/**
 * 知识点2.2.1: Variables - memory locations with name and type
 * 知识点2.2.2: Values - contents of variables
 * 知识点2.2.3: Constants - storage whose value cannot be changed
 */
void variablesAndConstantsDemo() {
    cout << "\n=== 知识点2.2: Variables, Values, and Constants ===" << endl;
    
    // Variable declarations (知识点2.3.1: Identifiers)
    int num1;           // Integer variable
    int num2;           // Integer variable
    int sum;            // Integer variable
    
    // Getting inputs (知识点2.1: cin object)
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;
    
    // Calculation and assignment
    sum = num1 + num2;
    
    // Output
    cout << "The sum is: " << sum << endl;
    
    // Constants (知识点2.2.3)
    const double PI = 3.14159;      // const modifier makes it constant
    const int DAYS_IN_WEEK = 7;     // Cannot be changed after initialization
    // DAYS_IN_WEEK = 8;            // ERROR: Cannot modify constant
    
    cout << "PI constant value: " << PI << endl;
    cout << "Days in week constant: " << DAYS_IN_WEEK << endl;
}

/**
 * 知识点2.3.1: Identifiers (keywords, predefined, user-defined)
 * 知识点2.3.2: Comments (single-line and multi-line)
 * 知识点2.4: Data Types (Integer, Character, Boolean, Floating-point, Void)
 */
void dataTypesDemo() {
    cout << "\n=== 知识点2.4: Data Types ===" << endl;
    
    // Integer types (知识点2.4.1)
    short shortInt = 32767;           // Usually 2 bytes
    int regularInt = 2147483647;      // Usually 4 bytes
    long longInt = 2147483647L;       // Usually 4 or 8 bytes
    unsigned int unsignedInt = 4294967295U;  // Only positive
    
    cout << "Short int: " << shortInt << " (size: " << sizeof(short) << " bytes)" << endl;
    cout << "Regular int: " << regularInt << " (size: " << sizeof(int) << " bytes)" << endl;
    cout << "Long int: " << longInt << " (size: " << sizeof(long) << " bytes)" << endl;
    cout << "Unsigned int: " << unsignedInt << endl;
    
    // Character types (知识点2.4.2)
    char letter = 'A';
    char asciiValue = 65;              // Same as 'A' in ASCII
    cout << "Character: " << letter << " (ASCII: " << (int)letter << ")" << endl;
    
    // Special characters (escape sequences)
    cout << "New line\\n, Tab\\t, Backslash\\\\, Single quote\\', Double quote\\\"" << endl;
    
    // Boolean type (知识点2.4.3)
    bool isTrue = true;
    bool isFalse = false;
    cout << "Boolean true: " << isTrue << " (any non-zero is true)" << endl;
    cout << "Boolean false: " << isFalse << " (zero is false)" << endl;
    
    // Floating-point types (知识点2.4.4)
    float floatNum = 3.14159F;        // Usually 4 bytes
    double doubleNum = 3.14159265359; // Usually 8 bytes
    long double longDouble = 3.14159265358979L; // Usually 8-16 bytes
    
    cout << "Float: " << floatNum << " (size: " << sizeof(float) << " bytes)" << endl;
    cout << "Double: " << doubleNum << " (size: " << sizeof(double) << " bytes)" << endl;
    cout << "Long double: " << longDouble << " (size: " << sizeof(long double) << " bytes)" << endl;
    
    // Void type (知识点2.4.5) - used for functions that return nothing
    // String class (知识点2.4.6)
    string firstName = "John";
    string lastName = "Doe";
    string fullName = firstName + " " + lastName;  // Concatenation
    cout << "C++ String: " << fullName << endl;
}

// ============================================================================
// SECTION 3: CHAPTER 3 - EXPRESSIONS AND STATEMENTS
// ============================================================================
//知识点3.1: Expressions (Primary, Unary, Multiplicative, Additive, Assignment)
//知识点3.2: Type Conversion (Implicit and Explicit)
//知识点3.3: Order of Evaluation (Precedence and Associativity)
//知识点3.4: Overflow and Underflow
//知识点3.5: Formatting Data (Manipulators)
//知识点3.6: Statements (Declaration, Expression, Null, Compound, Return)

/**
 * 知识点3.1.1: Primary Expressions - literals, names, parenthetical
 * 知识点3.1.2: Unary Expressions - plus, minus, sizeof
 * 知识点3.1.3: Multiplicative Expressions - *, /, %
 * 知识点3.1.4: Additive Expressions - +, -
 * 知识点3.1.5: Assignment Expressions - =, +=, -=, *=, /=, %=
 */
void expressionsDemo() {
    cout << "\n=== 知识点3.1: Expressions ===" << endl;
    
    // Primary expressions (literals, names)
    int x = 10;      // 'x' is a name (primary expression)
    int y = 20;
    
    // Unary expressions (知识点3.1.2)
    cout << "Unary plus: " << +x << endl;
    cout << "Unary minus: " << -x << endl;
    cout << "Size of int: " << sizeof(int) << " bytes" << endl;
    
    // Multiplicative expressions (知识点3.1.3)
    cout << "Multiplication (5 * 3): " << 5 * 3 << endl;
    cout << "Division (15 / 4): " << 15 / 4 << " (integer division truncates)" << endl;
    cout << "Division (15.0 / 4.0): " << 15.0 / 4.0 << endl;
    cout << "Remainder (17 % 5): " << 17 % 5 << endl;
    
    // Additive expressions (知识点3.1.4)
    cout << "Addition (10 + 20): " << 10 + 20 << endl;
    cout << "Subtraction (30 - 15): " << 30 - 15 << endl;
    
    // Assignment expressions (知识点3.1.5)
    int a = 5;           // Simple assignment
    int b = 10;
    cout << "Before compound: a=" << a << ", b=" << b << endl;
    a += 3;              // Compound assignment: a = a + 3
    b *= 2;              // Compound assignment: b = b * 2
    cout << "After a+=3: a=" << a << ", After b*=2: b=" << b << endl;
    
    // lvalue and rvalue (知识点3.1.6)
    // lvalue: can be on left side of assignment (destination)
    // rvalue: can be on right side of assignment (source)
    int num = 42;        // 'num' is lvalue, '42' is rvalue
    int another = num;   // 'another' is lvalue, 'num' is rvalue (value is copied)
}

/**
 * 知识点3.2: Type Conversion
 * - Implicit conversion: automatic by compiler
 * - Explicit conversion (casting): forced by programmer
 */
void typeConversionDemo() {
    cout << "\n=== 知识点3.2: Type Conversion ===" << endl;
    
    // Implicit type promotion (知识点3.2.1)
    bool flag = true;
    char ch = 'A';
    short small = 100;
    
    // bool and char are promoted to int for arithmetic
    int result1 = flag + 5;      // true (1) + 5 = 6
    int result2 = ch + 5;        // 'A' (65) + 5 = 70
    cout << "bool + int: " << result1 << endl;
    cout << "char + int: " << result2 << " (ASCII value of 'A' is 65)" << endl;
    
    // Implicit type change in mixed expressions (知识点3.2.1)
    int intVal = 10;
    double doubleVal = 3.14;
    double mixedResult = intVal + doubleVal;  // int promoted to double
    cout << "Mixed type result: " << mixedResult << endl;
    
    // Implicit type change with side effects (assignment)
    double pi = 3.14159;
    int intPi = pi;              // Truncation: 3.14159 -> 3
    cout << "Double to int (truncation): " << intPi << endl;
    
    // Explicit type conversion (知识点3.2.2)
    double value = 7.8;
    int truncated = static_cast<int>(value);   // C++ style casting
    int rounded = static_cast<int>(value + 0.5); // Rounding
    
    cout << "Original: " << value << endl;
    cout << "Static_cast to int (truncation): " << truncated << endl;
    cout << "Rounding: " << rounded << endl;
    
    // Using typeid to check types (requires <typeinfo>)
    cout << "Type of (intVal + doubleVal): " << typeid(intVal + doubleVal).name() << endl;
}

/**
 * 知识点3.3: Order of Evaluation
 * - Precedence: which operator is evaluated first
 * - Associativity: order when same precedence
 */
void precedenceAndAssociativityDemo() {
    cout << "\n=== 知识点3.3: Order of Evaluation ===" << endl;
    
    // Precedence example: multiplication has higher precedence than addition
    int result1 = 5 + 7 * 4;      // 5 + (7*4) = 5 + 28 = 33
    int result2 = (5 + 7) * 4;    // (5+7)*4 = 12*4 = 48
    
    cout << "5 + 7 * 4 = " << result1 << " (multiplication first)" << endl;
    cout << "(5 + 7) * 4 = " << result2 << " (parentheses override precedence)" << endl;
    
    // Complex expression with precedence
    int result3 = 5 - 30 / 4 * 8 + 10;
    // Steps: 30/4=7, 7*8=56, 5-56=-51, -51+10=-41
    cout << "5 - 30 / 4 * 8 + 10 = " << result3 << endl;
    
    // Associativity: left-to-right for most operators
    int result4 = 10 - 5 - 2;     // (10-5)-2 = 3 (left associative)
    cout << "10 - 5 - 2 = " << result4 << " (left associative)" << endl;
    
    // Assignment is right-to-left associative
    int a, b, c;
    a = b = c = 5;                // (a = (b = (c = 5)))
    cout << "a=b=c=5: a=" << a << ", b=" << b << ", c=" << c << endl;
}

/**
 * 知识点3.4: Overflow and Underflow
 * When value exceeds type's range
 */
void overflowUnderflowDemo() {
    cout << "\n=== 知识点3.4: Overflow and Underflow ===" << endl;
    
    // Unsigned integer overflow wraps around
    unsigned short maxUShort = 65535;
    cout << "Max unsigned short: " << maxUShort << endl;
    unsigned short overflowUShort = maxUShort + 1;
    cout << "max + 1 (overflow): " << overflowUShort << " (wraps to 0)" << endl;
    
    // Unsigned integer underflow wraps around
    unsigned short minUShort = 0;
    cout << "Min unsigned short: " << minUShort << endl;
    unsigned short underflowUShort = minUShort - 1;
    cout << "min - 1 (underflow): " << underflowUShort << " (wraps to 65535)" << endl;
    
    // Signed integer overflow (implementation defined, but often wraps)
    int maxInt = 2147483647;
    cout << "Max int: " << maxInt << endl;
    // int overflowInt = maxInt + 1;  // Would overflow (uncomment at your own risk)
    
    // Floating-point overflow gives INF (infinity)
    double maxDouble = 1.79769e+308;
    cout << "Max double: " << maxDouble << endl;
    // double overflowDouble = maxDouble * 1000;  // Would be INF
    
    // Detecting potential overflow before it happens
    int a = 2000000000;
    int b = 1500000000;
    if (a > numeric_limits<int>::max() - b) {
        cout << "Warning: Addition would overflow!" << endl;
    }
}

/**
 * 知识点3.5: Formatting Data with Manipulators
 * Requires <iomanip> header
 */
void formattingDemo() {
    cout << "\n=== 知识点3.5: Formatting Data ===" << endl;
    
    // Boolean manipulators
    bool boolValue = true;
    cout << "Default bool: " << boolValue << endl;
    cout << "boolalpha: " << boolalpha << boolValue << endl;
    cout << "noboolalpha: " << noboolalpha << boolValue << endl;
    
    // Integer base manipulators
    int number = 255;
    cout << "Decimal: " << dec << number << endl;
    cout << "Hexadecimal: " << hex << number << endl;
    cout << "Octal: " << oct << number << endl;
    cout << "Back to decimal: " << dec << number << endl;
    
    // showbase to display base prefix
    cout << "Hex with showbase: " << showbase << hex << number << endl;
    cout << "Octal with showbase: " << oct << number << endl;
    cout << noshowbase << dec;  // Reset
    
    // Floating-point formatting
    double pi = 3.14159265359;
    cout << "Default: " << pi << endl;
    cout << "Fixed: " << fixed << pi << endl;
    cout << "Scientific: " << scientific << pi << endl;
    cout << "Back to default: " << defaultfloat << pi << endl;
    
    // Precision (number of digits after decimal)
    cout << fixed << setprecision(2) << "Pi with 2 decimals: " << pi << endl;
    cout << setprecision(4) << "Pi with 4 decimals: " << pi << endl;
    
    // Field width and fill characters
    cout << "setw(10) with right alignment:" << endl;
    cout << setw(10) << "Hello" << endl;
    cout << "setw(10) with left alignment:" << endl;
    cout << left << setw(10) << "Hello" << right << endl;
    cout << "setfill('*') with setw(10):" << endl;
    cout << setfill('*') << setw(10) << 123 << endl;
    cout << setfill(' ');  // Reset fill
    
    // showpoint to show decimal point
    double integerValue = 100;
    cout << "Without showpoint: " << integerValue << endl;
    cout << "With showpoint: " << showpoint << integerValue << noshowpoint << endl;
    
    // showpos to show positive sign
    cout << "Without showpos: " << 100 << endl;
    cout << "With showpos: " << showpos << 100 << noshowpos << endl;
    
    // uppercase for hex and scientific
    cout << uppercase << hex << 255 << nouppercase << dec << endl;
}

/**
 * 知识点3.6: Statements
 * - Declaration statement
 * - Expression statement
 * - Null statement
 * - Compound statement
 * - Return statement
 */
void statementsDemo() {
    cout << "\n=== 知识点3.6: Statements ===" << endl;
    
    // Declaration statement (知识点3.6.1)
    int score;           // Declaration (and definition)
    double average;
    char grade;
    
    // Multiple declaration
    int first, second, third;
    
    // Declaration with initialization
    int x = 10;
    double pi = 3.14159;
    char letter = 'A';
    
    // Expression statement (知识点3.6.2) - expression followed by semicolon
    x = 5;               // Assignment expression statement
    x++;                 // Increment expression statement
    cout << "x = " << x << endl;  // Output expression statement
    
    // Null statement (知识点3.6.3) - just a semicolon
    ;                    // Does nothing, sometimes used in loops
    
    // Compound statement (知识点3.6.4) - block of statements in braces
    {
        int localVar = 100;      // Local to this block
        cout << "Inside compound statement: localVar = " << localVar << endl;
    }
    // localVar not accessible here
    
    // Return statement (知识点3.6.5) - returns from function
    // Demonstrated in main function return 0;
}

// ============================================================================
// SECTION 4: CHAPTER 4 - SELECTION
// ============================================================================
//知识点4.1: Simple Selection (if, if-else)
//知识点4.2: Complex Decisions (Logical operators: &&, ||, !)
//知识点4.3: Decisions on Specific Values (switch)
//知识点4.4: Conditional Expressions (?: ternary operator)

/**
 * 知识点4.1.1: Relational and Equality Expressions
 * Relational: <, <=, >, >=
 * Equality: ==, !=
 */
void relationalEqualityDemo() {
    cout << "\n=== 知识点4.1.1: Relational and Equality Expressions ===" << endl;
    
    int a = 10, b = 20;
    
    // Relational expressions
    cout << "a < b: " << (a < b) << endl;
    cout << "a > b: " << (a > b) << endl;
    cout << "a <= b: " << (a <= b) << endl;
    cout << "a >= b: " << (a >= b) << endl;
    
    // Equality expressions
    cout << "a == b: " << (a == b) << endl;
    cout << "a != b: " << (a != b) << endl;
    
    // WARNING: Don't compare floating-point numbers directly
    double x = 0.1 + 0.2;
    double y = 0.3;
    cout << "0.1 + 0.2 = " << x << endl;
    cout << "x == y? " << (x == y) << " (may be false due to precision)" << endl;
    
    // Better way: check if difference is very small
    const double EPSILON = 1e-9;
    if (abs(x - y) < EPSILON) {
        cout << "x and y are approximately equal" << endl;
    }
}

/**
 * 知识点4.1.2: One-Way Selection - if statement
 * Executes statement(s) only if condition is true
 */
void ifStatementDemo() {
    cout << "\n=== 知识点4.1.2: if Statement (One-Way Selection) ===" << endl;
    
    int number;
    cout << "Enter an integer: ";
    cin >> number;
    
    // Find absolute value using if statement
    int absolute = number;
    if (number < 0) {
        absolute = -number;    // Executed only if condition is true
    }
    cout << "Absolute value: " << absolute << endl;
    
    // Example: Overtime pay calculation
    double hoursWorked, payRate;
    cout << "Enter hours worked: ";
    cin >> hoursWorked;
    cout << "Enter pay rate: ";
    cin >> payRate;
    
    double regularPay = hoursWorked * payRate;
    double overtimePay = 0.0;
    
    if (hoursWorked > 40) {
        overtimePay = (hoursWorked - 40) * payRate * 1.5;
        regularPay = 40 * payRate;
    }
    
    double totalPay = regularPay + overtimePay;
    cout << "Regular pay: $" << regularPay << endl;
    cout << "Overtime pay: $" << overtimePay << endl;
    cout << "Total pay: $" << totalPay << endl;
}

/**
 * 知识点4.1.3: Two-Way Selection - if-else statement
 * Executes one branch if condition true, other if false
 */
void ifElseStatementDemo() {
    cout << "\n=== 知识点4.1.3: if-else Statement (Two-Way Selection) ===" << endl;
    
    int score;
    cout << "Enter test score (0-100): ";
    cin >> score;
    
    // Simple if-else for pass/fail
    if (score >= 70) {
        cout << "Grade: PASS" << endl;
    } else {
        cout << "Grade: FAIL" << endl;
    }
    
    // Finding larger of two numbers
    int num1, num2;
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;
    
    int larger;
    if (num1 >= num2) {
        larger = num1;
    } else {
        larger = num2;
    }
    cout << "The larger number is: " << larger << endl;
    
    // Nested if-else (知识点4.1.3 - multiway)
    cout << "\nNested if-else for grade determination:" << endl;
    char grade;
    if (score >= 90) {
        grade = 'A';
    } else if (score >= 80) {
        grade = 'B';
    } else if (score >= 70) {
        grade = 'C';
    } else if (score >= 60) {
        grade = 'D';
    } else {
        grade = 'F';
    }
    cout << "Letter grade: " << grade << endl;
}

/**
 * 知识点4.2: Complex Decisions - Logical Operators
 * && (AND), || (OR), ! (NOT)
 */
void logicalOperatorsDemo() {
    cout << "\n=== 知识点4.2: Complex Decisions (Logical Operators) ===" << endl;
    
    // Truth table demonstration
    bool p = true, q = false;
    cout << "p && q (AND): " << (p && q) << " (true only if both true)" << endl;
    cout << "p || q (OR): " << (p || q) << " (true if at least one true)" << endl;
    cout << "!p (NOT): " << (!p) << " (flips value)" << endl;
    
    // Range checking using AND
    int age;
    cout << "Enter age: ";
    cin >> age;
    
    // Check if age is between 18 and 65 (inclusive)
    if (age >= 18 && age <= 65) {
        cout << "You are in the working age range." << endl;
    } else {
        cout << "You are outside the working age range." << endl;
    }
    
    // Disjoint range using OR
    double temperature;
    cout << "Enter temperature: ";
    cin >> temperature;
    
    if (temperature < 32 || temperature > 100) {
        cout << "Extreme temperature warning!" << endl;
    } else {
        cout << "Temperature is moderate." << endl;
    }
    
    // Leap year calculation using logical operators
    int year;
    cout << "Enter year: ";
    cin >> year;
    
    bool isLeapYear = (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
    if (isLeapYear) {
        cout << year << " is a leap year." << endl;
    } else {
        cout << year << " is not a leap year." << endl;
    }
    
    // De Morgan's Law: !(x && y) is same as (!x || !y)
    //                !(x || y) is same as (!x && !y)
    bool x = true, y = false;
    cout << "\nDe Morgan's Law demonstration:" << endl;
    cout << "!(x && y) = " << !(x && y) << endl;
    cout << "(!x || !y) = " << (!x || !y) << endl;
    
    // Short-circuit evaluation
    int a = 10, b = 0;
    // The second condition is NOT evaluated if first is false
    if (b != 0 && a / b > 5) {  // Safe because b!=0 is false, division not attempted
        cout << "This won't execute" << endl;
    }
    cout << "Short-circuit prevents division by zero!" << endl;
}

/**
 * 知识点4.3: Decisions on Specific Values - switch statement
 */
void switchStatementDemo() {
    cout << "\n=== 知识点4.3: switch Statement ===" << endl;
    
    // Days of week using switch (fall-through)
    int day;
    cout << "Enter day number (1-7): ";
    cin >> day;
    
    cout << "Using fall-through (prints from selected day to end):" << endl;
    switch (day) {
        case 1: cout << "Monday ";
        case 2: cout << "Tuesday ";
        case 3: cout << "Wednesday ";
        case 4: cout << "Thursday ";
        case 5: cout << "Friday ";
        case 6: cout << "Saturday ";
        case 7: cout << "Sunday";
    }
    cout << endl;
    
    // Switch with break (selection)
    cout << "\nUsing break (prints only selected day):" << endl;
    switch (day) {
        case 1: cout << "Monday"; break;
        case 2: cout << "Tuesday"; break;
        case 3: cout << "Wednesday"; break;
        case 4: cout << "Thursday"; break;
        case 5: cout << "Friday"; break;
        case 6: cout << "Saturday"; break;
        case 7: cout << "Sunday"; break;
        default: cout << "Invalid day"; break;
    }
    cout << endl;
    
    // Grade conversion using switch
    int score;
    cout << "\nEnter score (0-100): ";
    cin >> score;
    
    char grade;
    switch (score / 10) {  // Convert range to single value
        case 10:
        case 9:  grade = 'A'; break;
        case 8:  grade = 'B'; break;
        case 7:  grade = 'C'; break;
        case 6:  grade = 'D'; break;
        default: grade = 'F'; break;
    }
    cout << "Grade: " << grade << endl;
    
    // Combining cases
    char letterGrade;
    cout << "\nEnter letter grade (A, B, C, D, F): ";
    cin >> letterGrade;
    
    switch (letterGrade) {
        case 'A':
        case 'B':
        case 'C':
            cout << "Passing grade" << endl;
            break;
        case 'D':
        case 'F':
            cout << "Failing grade" << endl;
            break;
        default:
            cout << "Invalid grade" << endl;
    }
}

/**
 * 知识点4.4: Conditional Expressions (Ternary Operator)
 * condition ? expression1 : expression2
 */
void conditionalExpressionDemo() {
    cout << "\n=== 知识点4.4: Conditional Expressions (Ternary Operator) ===" << endl;
    
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;
    
    // Find maximum using ternary operator
    int max = (a > b) ? a : b;
    cout << "Maximum (using ternary): " << max << endl;
    
    // Find absolute value using ternary
    int num;
    cout << "Enter a number: ";
    cin >> num;
    int absValue = (num < 0) ? -num : num;
    cout << "Absolute value: " << absValue << endl;
    
    // Comparison of if-else and ternary
    // if-else version
    int result1;
    if (a > b) {
        result1 = a;
    } else {
        result1 = b;
    }
    
    // Ternary version (more concise)
    int result2 = (a > b) ? a : b;
    
    cout << "if-else result: " << result1 << ", ternary result: " << result2 << endl;
    
    // Nested ternary (use sparingly - can be hard to read)
    int x = 5, y = 10, z = 7;
    int max3 = (x > y) ? ((x > z) ? x : z) : ((y > z) ? y : z);
    cout << "Maximum of three: " << max3 << endl;
}

// ============================================================================
// SECTION 5: CHAPTER 5 - REPETITION
// ============================================================================
//知识点5.1: Introduction (prefix/postfix increment/decrement)
//知识点5.2: while Statement
//知识点5.3: for Statement
//知识点5.4: do-while Statement
//知识点5.5: More About Loops (nested loops)
//知识点5.6: Other Related Statements (break, continue)

/**
 * 知识点5.1.1: Prefix and Postfix Increment/Decrement
 */
void incrementDecrementDemo() {
    cout << "\n=== 知识点5.1: Prefix and Postfix Increment/Decrement ===" << endl;
    
    // Postfix increment: returns original value, then increments
    int x = 5;
    int y = x++;  // y gets 5, then x becomes 6
    cout << "Postfix increment: x=" << x << ", y=" << y << endl;
    
    // Prefix increment: increments first, then returns new value
    int a = 5;
    int b = ++a;  // a becomes 6, then b gets 6
    cout << "Prefix increment: a=" << a << ", b=" << b << endl;
    
    // Postfix decrement
    int m = 10;
    int n = m--;  // n gets 10, then m becomes 9
    cout << "Postfix decrement: m=" << m << ", n=" << n << endl;
    
    // Prefix decrement
    int p = 10;
    int q = --p;  // p becomes 9, then q gets 9
    cout << "Prefix decrement: p=" << p << ", q=" << q << endl;
    
    // Used in loops (postfix is common)
    for (int i = 0; i < 5; i++) {  // i++ is postfix
        cout << i << " ";
    }
    cout << endl;
}

/**
 * 知识点5.2: while Statement
 * Pre-test loop - checks condition before executing body
 */
void whileLoopDemo() {
    cout << "\n=== 知识点5.2: while Statement ===" << endl;
    
    // Counter-controlled while loop
    cout << "Counter-controlled loop (print 1-5): ";
    int counter = 1;
    while (counter <= 5) {
        cout << counter << " ";
        counter++;
    }
    cout << endl;
    
    // Sum of numbers using while loop
    int n;
    cout << "Enter a number to sum from 1 to n: ";
    cin >> n;
    
    int sum = 0;
    int i = 1;
    while (i <= n) {
        sum += i;
        i++;
    }
    cout << "Sum of 1 to " << n << " = " << sum << endl;
    
    // Sentinel-controlled while loop
    cout << "\nEnter numbers to sum (enter -1 to stop):" << endl;
    int num;
    int total = 0;
    cout << "Enter first number: ";
    cin >> num;
    
    while (num != -1) {
        total += num;
        cout << "Enter next number (-1 to stop): ";
        cin >> num;
    }
    cout << "Sum of entered numbers: " << total << endl;
    
    // EOF-controlled while loop (using Ctrl+Z on Windows, Ctrl+D on Unix)
    cout << "\nEnter numbers (Ctrl+Z to end): ";
    int value;
    int count = 0;
    while (cin >> value) {
        count++;
    }
    cin.clear();  // Clear error flags
    cout << "You entered " << count << " numbers" << endl;
    
    // Finding average of test scores
    const int NUM_TESTS = 4;
    int testScore;
    int scoreSum = 0;
    int testCount = 0;
    
    while (testCount < NUM_TESTS) {
        cout << "Enter test score " << (testCount + 1) << ": ";
        cin >> testScore;
        scoreSum += testScore;
        testCount++;
    }
    double average = static_cast<double>(scoreSum) / NUM_TESTS;
    cout << "Average score: " << fixed << setprecision(2) << average << endl;
}

/**
 * 知识点5.3: for Statement
 * Combines initialization, condition, and update in one line
 */
void forLoopDemo() {
    cout << "\n=== 知识点5.3: for Statement ===" << endl;
    
    // Basic for loop
    cout << "Basic for loop (print 0-4): ";
    for (int i = 0; i < 5; i++) {
        cout << i << " ";
    }
    cout << endl;
    
    // For loop with different increment
    cout << "Even numbers from 2 to 10: ";
    for (int i = 2; i <= 10; i += 2) {
        cout << i << " ";
    }
    cout << endl;
    
    // For loop counting backwards
    cout << "Countdown from 5 to 1: ";
    for (int i = 5; i >= 1; i--) {
        cout << i << " ";
    }
    cout << endl;
    
    // Calculate factorial using for loop
    int factNum;
    cout << "Enter number for factorial: ";
    cin >> factNum;
    
    long long factorial = 1;
    for (int i = 1; i <= factNum; i++) {
        factorial *= i;
    }
    cout << factNum << "! = " << factorial << endl;
    
    // Multiple variables in for loop
    cout << "Multiple loop variables: ";
    for (int i = 0, j = 10; i < 5; i++, j--) {
        cout << "(" << i << "," << j << ") ";
    }
    cout << endl;
    
    // Range checking (numbers divisible by 7)
    cout << "Numbers divisible by 7 between 1 and 100:" << endl;
    int col = 0;
    for (int i = 1; i <= 100; i++) {
        if (i % 7 == 0) {
            cout << setw(4) << i;
            col++;
            if (col % 10 == 0) {
                cout << endl;
            }
        }
    }
    cout << endl;
}

/**
 * 知识点5.4: do-while Statement
 * Post-test loop - executes body at least once
 */
void doWhileLoopDemo() {
    cout << "\n=== 知识点5.4: do-while Statement ===" << endl;
    
    // Extract leftmost digit of a number (at least one iteration needed)
    int number;
    cout << "Enter a positive integer: ";
    cin >> number;
    
    int leftDigit;
    int temp = number;
    do {
        leftDigit = temp % 10;
        temp = temp / 10;
    } while (temp > 0);
    cout << "Leftmost digit of " << number << " is: " << leftDigit << endl;
    
    // Data validation - ensures valid input
    int score;
    do {
        cout << "Enter a score between 0 and 100: ";
        cin >> score;
        if (score < 0 || score > 100) {
            cout << "Invalid! Score must be between 0 and 100." << endl;
        }
    } while (score < 0 || score > 100);
    cout << "Valid score: " << score << endl;
    
    // Menu-driven program
    int choice;
    do {
        cout << "\n===== MENU =====" << endl;
        cout << "1. Say Hello" << endl;
        cout << "2. Say Goodbye" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1: cout << "Hello!" << endl; break;
            case 2: cout << "Goodbye!" << endl; break;
            case 3: cout << "Exiting..." << endl; break;
            default: cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 3);
}

/**
 * 知识点5.5: More About Loops (Nested loops)
 */
void nestedLoopsDemo() {
    cout << "\n=== 知识点5.5: Nested Loops ===" << endl;
    
    // Rectangle of asterisks
    int rows, cols;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;
    
    cout << "Rectangle of " << rows << "x" << cols << ":" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "*";
        }
        cout << endl;
    }
    
    // Triangle patterns
    cout << "\nRight triangle pattern:" << endl;
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= i; j++) {
            cout << "*";
        }
        cout << endl;
    }
    
    // Number pattern
    cout << "\nNumber pattern:" << endl;
    for (int i = 1; i <= 5; i++) {
        for (int j = i; j <= i + 4; j++) {
            cout << j << " ";
        }
        cout << endl;
    }
    
    // Multiplication table
    cout << "\nMultiplication table (1-10):" << endl;
    cout << "    ";
    for (int i = 1; i <= 10; i++) {
        cout << setw(4) << i;
    }
    cout << endl;
    cout << "    " << string(40, '-') << endl;
    
    for (int i = 1; i <= 10; i++) {
        cout << setw(2) << i << " |";
        for (int j = 1; j <= 10; j++) {
            cout << setw(4) << i * j;
        }
        cout << endl;
    }
}

/**
 * 知识点5.6: Other Related Statements (break, continue, return)
 */
void loopControlStatementsDemo() {
    cout << "\n=== 知识点5.6: break, continue, return ===" << endl;
    
    // break statement - exits loop immediately
    cout << "break statement (stop at 5): ";
    for (int i = 1; i <= 10; i++) {
        if (i == 5) {
            break;  // Exit loop when i reaches 5
        }
        cout << i << " ";
    }
    cout << endl;
    
    // continue statement - skips rest of iteration
    cout << "continue statement (skip even numbers): ";
    for (int i = 1; i <= 10; i++) {
        if (i % 2 == 0) {
            continue;  // Skip even numbers
        }
        cout << i << " ";
    }
    cout << endl;
    
    // Finding prime number with break
    int num;
    cout << "Enter a number to check if prime: ";
    cin >> num;
    
    if (num <= 1) {
        cout << num << " is not prime." << endl;
    } else {
        bool isPrime = true;
        for (int i = 2; i <= sqrt(num); i++) {
            if (num % i == 0) {
                isPrime = false;
                break;  // Found a divisor, no need to continue
            }
        }
        cout << num << (isPrime ? " is prime." : " is not prime.") << endl;
    }
}

// ============================================================================
// SECTION 6: CHAPTER 6 - FUNCTIONS
// ============================================================================
//知识点6.1: Introduction to Functions
//知识点6.2: Library Functions (cmath, cctype, cstdlib, ctime)
//知识点6.3: User-Defined Functions
//知识点6.4: Data Exchange (pass-by-value, pass-by-reference)
//知识点6.5: More About Parameters (default, overloading)
//知识点6.6: Scope and Lifetime (local, global, static)

/**
 * 知识点6.1: Function Definition, Declaration, and Call
 */
// Function declaration (prototype)
int add(int a, int b);
void printMessage(string msg);
int factorial(int n);

// Function definition
int add(int a, int b) {
    return a + b;
}

void printMessage(string msg) {
    cout << msg << endl;
}

int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

void functionsIntroDemo() {
    cout << "\n=== 知识点6.1: Function Definition, Declaration, Call ===" << endl;
    
    // Function call
    int sum = add(10, 20);
    cout << "Sum of 10 and 20: " << sum << endl;
    
    printMessage("Hello from a function!");
    
    cout << "Factorial of 5: " << factorial(5) << endl;
}

/**
 * 知识点6.2: Library Functions
 */
void libraryFunctionsDemo() {
    cout << "\n=== 知识点6.2: Library Functions ===" << endl;
    
    // <cmath> mathematical functions (知识点6.2.1)
    cout << "===== <cmath> Mathematical Functions =====" << endl;
    cout << "abs(-10): " << abs(-10) << endl;
    cout << "sqrt(25): " << sqrt(25) << endl;
    cout << "pow(2, 3): " << pow(2, 3) << endl;
    cout << "floor(3.7): " << floor(3.7) << endl;
    cout << "ceil(3.2): " << ceil(3.2) << endl;
    cout << "log(100): " << log(100) << endl;
    cout << "log10(100): " << log10(100) << endl;
    cout << "exp(1): " << exp(1) << endl;
    
    // Trigonometric functions
    const double PI = 3.141592653589793;
    double angle = PI / 4;  // 45 degrees
    cout << "sin(45°): " << sin(angle) << endl;
    cout << "cos(45°): " << cos(angle) << endl;
    cout << "tan(45°): " << tan(angle) << endl;
    
    // Quadratic equation solver
    double a, b, c;
    cout << "\nQuadratic equation solver (ax^2 + bx + c = 0)" << endl;
    cout << "Enter a, b, c: ";
    cin >> a >> b >> c;
    
    double discriminant = pow(b, 2) - 4 * a * c;
    if (discriminant < 0) {
        cout << "No real roots" << endl;
    } else if (discriminant == 0) {
        double root = -b / (2 * a);
        cout << "One root: " << root << endl;
    } else {
        double root1 = (-b + sqrt(discriminant)) / (2 * a);
        double root2 = (-b - sqrt(discriminant)) / (2 * a);
        cout << "Two roots: " << root1 << " and " << root2 << endl;
    }
    
    // <cctype> character functions (知识点6.2.2)
    cout << "\n===== <cctype> Character Functions =====" << endl;
    char ch = 'a';
    cout << "isalpha('a'): " << isalpha(ch) << endl;
    cout << "isdigit('5'): " << isdigit('5') << endl;
    cout << "isupper('A'): " << isupper('A') << endl;
    cout << "islower('a'): " << islower('a') << endl;
    cout << "toupper('a'): " << (char)toupper('a') << endl;
    cout << "tolower('A'): " << (char)tolower('A') << endl;
    
    // <cstdlib> random number functions (知识点6.2.4)
    cout << "\n===== <cstdlib> Random Numbers =====" << endl;
    srand(time(0));  // Seed random number generator
    
    cout << "Random numbers between 1 and 100: ";
    for (int i = 0; i < 5; i++) {
        int randNum = rand() % 100 + 1;
        cout << randNum << " ";
    }
    cout << endl;
}

/**
 * 知识点6.3: User-Defined Functions - Four Categories
 */
// 1. Void function with no parameters
void printGreeting() {
    cout << "*******************" << endl;
    cout << "* Hello Friends *" << endl;
    cout << "*******************" << endl;
}

// 2. Void function with parameters
void printPattern(int size, char symbol) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << symbol;
        }
        cout << endl;
    }
}

// 3. Value-returning function with no parameters
int getPositiveNumber() {
    int num;
    do {
        cout << "Enter a positive integer: ";
        cin >> num;
    } while (num <= 0);
    return num;
}

// 4. Value-returning function with parameters
int findMaximum(int first, int second) {
    return (first > second) ? first : second;
}

void userDefinedFunctionsDemo() {
    cout << "\n=== 知识点6.3: User-Defined Functions ===" << endl;
    
    // Void with no parameters
    printGreeting();
    
    // Void with parameters
    cout << "\nPattern of size 3:" << endl;
    printPattern(3, '*');
    
    // Value-returning with no parameters
    int positive = getPositiveNumber();
    cout << "You entered: " << positive << endl;
    
    // Value-returning with parameters
    int max = findMaximum(15, 27);
    cout << "Maximum of 15 and 27: " << max << endl;
}

/**
 * 知识点6.4: Data Exchange - Pass-by-value vs Pass-by-reference
 */
// Pass-by-value (copy)
void incrementByValue(int x) {
    x++;  // Only affects local copy
    cout << "Inside function (by value): x = " << x << endl;
}

// Pass-by-reference (alias)
void incrementByReference(int& x) {
    x++;  // Affects original variable
    cout << "Inside function (by reference): x = " << x << endl;
}

// Pass-by-pointer
void incrementByPointer(int* x) {
    (*x)++;  // Affects original variable via pointer
    cout << "Inside function (by pointer): x = " << *x << endl;
}

// Swap function using pass-by-reference
void swapValues(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void dataExchangeDemo() {
    cout << "\n=== 知识点6.4: Data Exchange (Pass-by-value vs Reference) ===" << endl;
    
    // Pass-by-value demonstration
    int num1 = 10;
    cout << "Before function (by value): num1 = " << num1 << endl;
    incrementByValue(num1);
    cout << "After function (by value): num1 = " << num1 << " (unchanged!)" << endl;
    
    // Pass-by-reference demonstration
    int num2 = 10;
    cout << "\nBefore function (by reference): num2 = " << num2 << endl;
    incrementByReference(num2);
    cout << "After function (by reference): num2 = " << num2 << " (changed!)" << endl;
    
    // Pass-by-pointer demonstration
    int num3 = 10;
    cout << "\nBefore function (by pointer): num3 = " << num3 << endl;
    incrementByPointer(&num3);
    cout << "After function (by pointer): num3 = " << num3 << " (changed!)" << endl;
    
    // Swap function
    int x = 5, y = 10;
    cout << "\nBefore swap: x=" << x << ", y=" << y << endl;
    swapValues(x, y);
    cout << "After swap: x=" << x << ", y=" << y << endl;
}

/**
 * 知识点6.5: More About Parameters - Default and Overloading
 */
// Default parameters
double calculatePay(double hourlyRate, double hours = 40.0) {
    return hourlyRate * hours;
}

// Function overloading
int max(int a, int b) {
    return (a > b) ? a : b;
}

double max(double a, double b) {
    return (a > b) ? a : b;
}

int max(int a, int b, int c) {
    return max(max(a, b), c);
}

void parametersDemo() {
    cout << "\n=== 知识点6.5: Default Parameters and Overloading ===" << endl;
    
    // Default parameters
    cout << "Pay with 40 hours (default): $" << calculatePay(25.0) << endl;
    cout << "Pay with 35 hours: $" << calculatePay(25.0, 35.0) << endl;
    
    // Function overloading
    cout << "max(5, 10): " << max(5, 10) << endl;
    cout << "max(3.14, 2.71): " << max(3.14, 2.71) << endl;
    cout << "max(5, 10, 7): " << max(5, 10, 7) << endl;
}

/**
 * 知识点6.6: Scope and Lifetime
 */
int globalVar = 100;  // Global variable

void scopeDemo() {
    cout << "\n=== 知识点6.6: Scope and Lifetime ===" << endl;
    
    // Local scope
    int localVar = 50;
    cout << "Local variable: " << localVar << endl;
    cout << "Global variable: " << globalVar << endl;
    
    // Block scope
    {
        int blockVar = 30;
        cout << "Block variable: " << blockVar << endl;
        // localVar is still accessible here
        cout << "Local variable inside block: " << localVar << endl;
    }
    // blockVar not accessible here
    
    // Shadowing - local shadows global
    int globalVar = 200;  // Local variable with same name
    cout << "Local globalVar (shadows global): " << globalVar << endl;
    cout << "Actual global (using ::): " << ::globalVar << endl;
    
    // Static local variable - retains value between calls
    static int callCount = 0;
    callCount++;
    cout << "This function has been called " << callCount << " time(s)" << endl;
}

// ============================================================================
// SECTION 7: CHAPTER 7 - CLASSES (OBJECT-ORIENTED PROGRAMMING)
// ============================================================================
//知识点7.1: Introduction to OOP (types, instances, attributes, behaviors)
//知识点7.2: Classes (definition, data members, member functions)
//知识点7.3: Constructors and Destructors
//知识点7.4: Instance Members
//知识点7.5: Static Members
//知识点7.6: Object-Oriented Programming
//知识点7.7: Designing Classes

/**
 * 知识点7.2: Circle Class - Demonstrates basic class concepts
 * A circle has a radius (attribute) and can provide area and perimeter (behaviors)
 */
class Circle {
private:
    double radius;  // Private data member (attribute)
    
public:
    // Constructors (知识点7.3)
    Circle() : radius(0.0) {
        cout << "Default constructor called" << endl;
    }
    
    Circle(double r) : radius(r) {
        cout << "Parameter constructor called with radius " << radius << endl;
        // Validate invariant: radius must be positive
        if (radius < 0) {
            cout << "Error: Radius cannot be negative!" << endl;
            assert(false);
        }
    }
    
    // Copy constructor
    Circle(const Circle& other) : radius(other.radius) {
        cout << "Copy constructor called" << endl;
    }
    
    // Destructor (知识点7.3)
    ~Circle() {
        cout << "Destructor called for circle with radius " << radius << endl;
    }
    
    // Accessor (getter) functions - const because they don't modify object (知识点7.4)
    double getRadius() const { return radius; }
    double getArea() const { return 3.14159 * radius * radius; }
    double getPerimeter() const { return 2 * 3.14159 * radius; }
    
    // Mutator (setter) function (知识点7.4)
    void setRadius(double r) {
        if (r >= 0) {
            radius = r;
        } else {
            cout << "Invalid radius!" << endl;
        }
    }
    
    // Print function
    void print() const {
        cout << "Circle: radius=" << radius 
             << ", area=" << fixed << setprecision(2) << getArea()
             << ", perimeter=" << getPerimeter() << endl;
    }
};

/**
 * 知识点7.5: Static Members - Class with static counter
 * Demonstrates static data members and static member functions
 */
class Counter {
private:
    static int instanceCount;  // Static data member - shared by all instances
    int id;
    
public:
    Counter() {
        instanceCount++;
        id = instanceCount;
        cout << "Counter #" << id << " created. Total instances: " << instanceCount << endl;
    }
    
    ~Counter() {
        cout << "Counter #" << id << " destroyed. ";
        instanceCount--;
        cout << "Remaining instances: " << instanceCount << endl;
    }
    
    // Static member function - can be called without an object
    static int getInstanceCount() {
        return instanceCount;
    }
    
    int getId() const { return id; }
};

// Initialize static data member (must be done outside class)
int Counter::instanceCount = 0;

/**
 * 知识点7.4: Rectangle Class - Demonstrates class invariants
 */
class Rectangle {
private:
    double length;
    double width;
    
    // Private helper function for validation
    bool isValid() const {
        return (length > 0 && width > 0);
    }
    
public:
    // Parameter constructor with validation
    Rectangle(double len, double wid) : length(len), width(wid) {
        if (!isValid()) {
            cout << "Error: Invalid rectangle dimensions!" << endl;
            assert(false);
        }
        cout << "Rectangle created: " << length << " x " << width << endl;
    }
    
    // Default constructor
    Rectangle() : length(1.0), width(1.0) {
        cout << "Default rectangle created: 1 x 1" << endl;
    }
    
    // Copy constructor
    Rectangle(const Rectangle& other) : length(other.length), width(other.width) {
        cout << "Rectangle copied: " << length << " x " << width << endl;
    }
    
    ~Rectangle() {
        cout << "Rectangle destroyed: " << length << " x " << width << endl;
    }
    
    // Accessor functions
    double getLength() const { return length; }
    double getWidth() const { return width; }
    double getArea() const { return length * width; }
    double getPerimeter() const { return 2 * (length + width); }
    
    // Mutator functions
    void setLength(double len) {
        if (len > 0) {
            length = len;
        }
    }
    
    void setWidth(double wid) {
        if (wid > 0) {
            width = wid;
        }
    }
    
    void print() const {
        cout << "Rectangle: " << length << " x " << width 
             << ", area=" << fixed << setprecision(2) << getArea()
             << ", perimeter=" << getPerimeter() << endl;
    }
};

/**
 * 知识点7.2-7.6: Student Class - Comprehensive example
 */
class Student {
private:
    string name;
    int id;
    double gpa;
    static int nextId;  // Static member for auto-generating IDs
    
public:
    // Parameter constructor
    Student(string n, double g) : name(n), gpa(g) {
        id = nextId++;
        cout << "Student created: " << name << " (ID: " << id << ", GPA: " << gpa << ")" << endl;
    }
    
    // Default constructor
    Student() : name("Unknown"), gpa(0.0) {
        id = nextId++;
        cout << "Default student created: " << name << " (ID: " << id << ")" << endl;
    }
    
    // Copy constructor
    Student(const Student& other) : name(other.name), gpa(other.gpa) {
        id = nextId++;
        cout << "Student copied: " << name << " (ID: " << id << ")" << endl;
    }
    
    ~Student() {
        cout << "Student destroyed: " << name << " (ID: " << id << ")" << endl;
    }
    
    // Accessors
    string getName() const { return name; }
    int getId() const { return id; }
    double getGpa() const { return gpa; }
    
    // Mutators
    void setName(string n) { name = n; }
    void setGpa(double g) { 
        if (g >= 0.0 && g <= 4.0) {
            gpa = g;
        }
    }
    
    // Static member function
    static int getNextId() { return nextId; }
    
    void print() const {
        cout << "Student: " << name << " (ID: " << id << ", GPA: " << fixed << setprecision(2) << gpa << ")" << endl;
    }
    
    // Determine letter grade
    char getLetterGrade() const {
        if (gpa >= 3.5) return 'A';
        if (gpa >= 2.5) return 'B';
        if (gpa >= 1.5) return 'C';
        if (gpa >= 0.7) return 'D';
        return 'F';
    }
};

// Initialize static member
int Student::nextId = 1000;

void classesDemo() {
    cout << "\n=== SECTION 7: CLASSES (Object-Oriented Programming) ===" << endl;
    
    // Circle class demonstration (知识点7.2-7.4)
    cout << "\n--- Circle Class Demo ---" << endl;
    Circle circle1;                    // Default constructor
    Circle circle2(5.0);              // Parameter constructor
    Circle circle3(circle2);          // Copy constructor
    
    circle1.setRadius(3.0);
    cout << "Circle1 radius: " << circle1.getRadius() << endl;
    cout << "Circle1 area: " << circle1.getArea() << endl;
    cout << "Circle1 perimeter: " << circle1.getPerimeter() << endl;
    
    circle2.print();
    circle3.print();
    
    // Array of objects
    cout << "\n--- Array of Circles ---" << endl;
    Circle circles[3] = {Circle(1.0), Circle(2.0), Circle(3.0)};
    for (int i = 0; i < 3; i++) {
        circles[i].print();
    }
    
    // Static members demonstration (知识点7.5)
    cout << "\n--- Static Members Demo ---" << endl;
    cout << "Initial instance count: " << Counter::getInstanceCount() << endl;
    
    Counter c1, c2, c3;
    cout << "After creating 3 counters: " << Counter::getInstanceCount() << endl;
    
    // Rectangle class (知识点7.4 - class invariants)
    cout << "\n--- Rectangle Class Demo ---" << endl;
    Rectangle rect1(5.0, 3.0);
    Rectangle rect2;  // Default 1x1
    Rectangle rect3(rect1);  // Copy
    
    rect1.print();
    rect2.print();
    rect3.print();
    
    // Student class (comprehensive)
    cout << "\n--- Student Class Demo ---" << endl;
    Student s1("Alice", 3.8);
    Student s2("Bob", 2.9);
    Student s3("Charlie", 1.5);
    
    s1.print();
    s2.print();
    s3.print();
    
    cout << "Next available student ID: " << Student::getNextId() << endl;
    cout << "Alice's letter grade: " << s1.getLetterGrade() << endl;
    cout << "Bob's letter grade: " << s2.getLetterGrade() << endl;
}

// ============================================================================
// SECTION 8: CHAPTER 8 - ARRAYS
// ============================================================================
//知识点8.1: One-Dimensional Arrays
//知识点8.2: More on Arrays (operations, searching, sorting)
//知识点8.3: Multidimensional Arrays
//知识点8.4: Program Design (frequency array, histogram)

/**
 * 知识点8.1: One-Dimensional Arrays
 */
void oneDimensionalArraysDemo() {
    cout << "\n=== 知识点8.1: One-Dimensional Arrays ===" << endl;
    
    // Array declaration and initialization
    const int CAPACITY = 10;
    int numbers[CAPACITY] = {5, 12, 7, 23, 45, 18, 9, 31, 14, 27};
    
    // Accessing array elements
    cout << "Array elements: ";
    for (int i = 0; i < CAPACITY; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;
    
    // Partial initialization (rest are zero-initialized)
    int partial[10] = {1, 2, 3};
    cout << "Partial array: ";
    for (int i = 0; i < 10; i++) {
        cout << partial[i] << " ";
    }
    cout << " (elements 3-9 are 0)" << endl;
    
    // Implicit size initialization
    int implicit[] = {10, 20, 30, 40, 50};
    int size = sizeof(implicit) / sizeof(implicit[0]);
    cout << "Implicit size array (" << size << " elements): ";
    for (int i = 0; i < size; i++) {
        cout << implicit[i] << " ";
    }
    cout << endl;
    
    // Reading into array
    int userArray[5];
    cout << "Enter 5 integers: ";
    for (int i = 0; i < 5; i++) {
        cin >> userArray[i];
    }
    
    // Printing in reverse order
    cout << "Array in reverse order: ";
    for (int i = 4; i >= 0; i--) {
        cout << userArray[i] << " ";
    }
    cout << endl;
    
    // Array of strings
    string names[3] = {"Alice", "Bob", "Charlie"};
    cout << "Names: ";
    for (int i = 0; i < 3; i++) {
        cout << names[i] << " ";
    }
    cout << endl;
}

/**
 * 知识点8.2: Array Operations - Sum, average, min, max, search
 */
void arrayOperationsDemo() {
    cout << "\n=== 知识点8.2: Array Operations ===" << endl;
    
    int numbers[] = {23, 45, 12, 67, 34, 89, 56, 78, 91, 43};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    
    // Find sum and average
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += numbers[i];
    }
    double average = static_cast<double>(sum) / size;
    cout << "Sum: " << sum << ", Average: " << fixed << setprecision(2) << average << endl;
    
    // Find minimum and maximum
    int minVal = numbers[0];
    int maxVal = numbers[0];
    for (int i = 1; i < size; i++) {
        if (numbers[i] < minVal) minVal = numbers[i];
        if (numbers[i] > maxVal) maxVal = numbers[i];
    }
    cout << "Minimum: " << minVal << ", Maximum: " << maxVal << endl;
    
    // Linear search
    int searchValue;
    cout << "Enter a value to search for: ";
    cin >> searchValue;
    
    int foundIndex = -1;
    for (int i = 0; i < size; i++) {
        if (numbers[i] == searchValue) {
            foundIndex = i;
            break;
        }
    }
    
    if (foundIndex != -1) {
        cout << searchValue << " found at index " << foundIndex << endl;
    } else {
        cout << searchValue << " not found in array" << endl;
    }
    
    // Array reversal using swap
    cout << "Original array: ";
    for (int i = 0; i < size; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;
    
    // Reverse the array
    for (int i = 0; i < size / 2; i++) {
        int temp = numbers[i];
        numbers[i] = numbers[size - 1 - i];
        numbers[size - 1 - i] = temp;
    }
    
    cout << "Reversed array: ";
    for (int i = 0; i < size; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;
}

/**
 * 知识点8.2: Passing arrays to functions
 */
void printArray(const int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void multiplyArray(int arr[], int size, int factor) {
    for (int i = 0; i < size; i++) {
        arr[i] *= factor;
    }
}

void arrayFunctionsDemo() {
    cout << "\n=== Passing Arrays to Functions ===" << endl;
    
    int numbers[] = {1, 2, 3, 4, 5};
    int size = 5;
    
    cout << "Original array: ";
    printArray(numbers, size);
    
    multiplyArray(numbers, size, 2);
    cout << "After multiplying by 2: ";
    printArray(numbers, size);
}

/**
 * 知识点8.3: Multidimensional Arrays (2D)
 */
void multidimensionalArraysDemo() {
    cout << "\n=== 知识点8.3: Multidimensional Arrays ===" << endl;
    
    // 2D array declaration and initialization
    int matrix[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    
    // Accessing elements
    cout << "2D Array (3x4):" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            cout << setw(4) << matrix[i][j];
        }
        cout << endl;
    }
    
    // Calculate row sums
    cout << "\nRow sums: ";
    for (int i = 0; i < 3; i++) {
        int rowSum = 0;
        for (int j = 0; j < 4; j++) {
            rowSum += matrix[i][j];
        }
        cout << rowSum << " ";
    }
    cout << endl;
    
    // Calculate column sums
    cout << "Column sums: ";
    for (int j = 0; j < 4; j++) {
        int colSum = 0;
        for (int i = 0; i < 3; i++) {
            colSum += matrix[i][j];
        }
        cout << colSum << " ";
    }
    cout << endl;
    
    // 2D array for test scores (students x tests)
    const int NUM_STUDENTS = 4;
    const int NUM_TESTS = 3;
    int scores[NUM_STUDENTS][NUM_TESTS] = {
        {85, 90, 88},
        {78, 82, 80},
        {92, 95, 94},
        {70, 75, 72}
    };
    
    cout << "\nTest Scores:" << endl;
    cout << "Student\tTest1\tTest2\tTest3\tAverage" << endl;
    for (int i = 0; i < NUM_STUDENTS; i++) {
        int studentSum = 0;
        cout << i + 1 << "\t";
        for (int j = 0; j < NUM_TESTS; j++) {
            cout << scores[i][j] << "\t";
            studentSum += scores[i][j];
        }
        double avg = static_cast<double>(studentSum) / NUM_TESTS;
        cout << fixed << setprecision(1) << avg << endl;
    }
}

/**
 * 知识点8.4: Frequency Array and Histogram
 */
void frequencyArrayDemo() {
    cout << "\n=== 知识点8.4: Frequency Array and Histogram ===" << endl;
    
    // Sample data: test scores between 0-100
    int scores[] = {85, 92, 78, 85, 91, 85, 78, 92, 88, 85, 
                    91, 78, 85, 92, 88, 85, 91, 78, 85, 92};
    int dataSize = sizeof(scores) / sizeof(scores[0]);
    
    // Frequency array for scores 0-100
    const int RANGE = 101;
    int frequency[RANGE] = {0};
    
    // Count frequencies
    for (int i = 0; i < dataSize; i++) {
        frequency[scores[i]]++;
    }
    
    // Display frequency distribution
    cout << "Score\tFrequency\tHistogram" << endl;
    cout << "-----\t---------\t---------" << endl;
    
    for (int i = 0; i < RANGE; i++) {
        if (frequency[i] > 0) {
            cout << i << "\t" << frequency[i] << "\t\t";
            for (int j = 0; j < frequency[i]; j++) {
                cout << "*";
            }
            cout << endl;
        }
    }
    
    // Grade distribution using ranges
    int gradeRanges[11] = {0};  // 0-9, 10-19, ..., 90-100
    
    for (int i = 0; i < dataSize; i++) {
        gradeRanges[scores[i] / 10]++;
    }
    
    cout << "\nGrade Distribution:" << endl;
    cout << "Range\tCount\tHistogram" << endl;
    for (int i = 0; i < 10; i++) {
        if (gradeRanges[i] > 0) {
            cout << i * 10 << "-" << i * 10 + 9 << "\t" << gradeRanges[i] << "\t";
            for (int j = 0; j < gradeRanges[i]; j++) {
                cout << "#";
            }
            cout << endl;
        }
    }
    cout << "90-100\t" << gradeRanges[10] << "\t";
    for (int j = 0; j < gradeRanges[10]; j++) {
        cout << "#";
    }
    cout << endl;
}

/**
 * 知识点8.4: Parallel Arrays
 */
void parallelArraysDemo() {
    cout << "\n=== Parallel Arrays ===" << endl;
    
    // Parallel arrays to store student information
    const int NUM_STUDENTS = 5;
    string names[NUM_STUDENTS] = {"Alice", "Bob", "Charlie", "Diana", "Eve"};
    int scores[NUM_STUDENTS] = {88, 76, 92, 85, 79};
    char grades[NUM_STUDENTS];
    
    // Calculate grades based on scores
    for (int i = 0; i < NUM_STUDENTS; i++) {
        if (scores[i] >= 90) grades[i] = 'A';
        else if (scores[i] >= 80) grades[i] = 'B';
        else if (scores[i] >= 70) grades[i] = 'C';
        else if (scores[i] >= 60) grades[i] = 'D';
        else grades[i] = 'F';
    }
    
    // Display using parallel arrays
    cout << left << setw(10) << "Name" << setw(8) << "Score" << "Grade" << endl;
    cout << string(25, '-') << endl;
    for (int i = 0; i < NUM_STUDENTS; i++) {
        cout << left << setw(10) << names[i] 
             << setw(8) << scores[i] 
             << grades[i] << endl;
    }
    
    // Find student with highest score
    int maxIndex = 0;
    for (int i = 1; i < NUM_STUDENTS; i++) {
        if (scores[i] > scores[maxIndex]) {
            maxIndex = i;
        }
    }
    cout << "\nHighest score: " << names[maxIndex] << " with " << scores[maxIndex] << endl;
}

// ============================================================================
// MAIN FUNCTION - Comprehensive Demo
// ============================================================================

int main() {
    cout << "╔══════════════════════════════════════════════════════════════════╗" << endl;
    cout << "║     C++ PROGRAMMING DEMO - Chapters 1-8 Comprehensive Learning   ║" << endl;
    cout << "║     Based on Forouzan & Gilberg - Object-Oriented Approach       ║" << endl;
    cout << "╚══════════════════════════════════════════════════════════════════╝" << endl;
    
    // Section 1: Introduction
    proceduralExample();
    
    // Section 2: C++ Basics
    firstProgramDemo();
    variablesAndConstantsDemo();
    dataTypesDemo();
    
    // Section 3: Expressions and Statements
    expressionsDemo();
    typeConversionDemo();
    precedenceAndAssociativityDemo();
    overflowUnderflowDemo();
    formattingDemo();
    statementsDemo();
    
    // Section 4: Selection
    relationalEqualityDemo();
    ifStatementDemo();
    ifElseStatementDemo();
    logicalOperatorsDemo();
    switchStatementDemo();
    conditionalExpressionDemo();
    
    // Section 5: Repetition
    incrementDecrementDemo();
    whileLoopDemo();
    forLoopDemo();
    doWhileLoopDemo();
    nestedLoopsDemo();
    loopControlStatementsDemo();
    
    // Section 6: Functions
    functionsIntroDemo();
    libraryFunctionsDemo();
    userDefinedFunctionsDemo();
    dataExchangeDemo();
    parametersDemo();
    scopeDemo();
    
    // Section 7: Classes
    classesDemo();
    
    // Section 8: Arrays
    oneDimensionalArraysDemo();
    arrayOperationsDemo();
    arrayFunctionsDemo();
    multidimensionalArraysDemo();
    frequencyArrayDemo();
    parallelArraysDemo();
    
    // Demonstrate algorithm (知识点1.4.2)
    int testArray[] = {13, 7, 19, 29, 23};
    int largest = findLargest(testArray, 5);
    cout << "\n=== Algorithm Demo ===" << endl;
    cout << "Largest number in {13, 7, 19, 29, 23}: " << largest << endl;
    
    cout << "\n╔══════════════════════════════════════════════════════════════════╗" << endl;
    cout << "║                    Demo Completed Successfully!                   ║" << endl;
    cout << "║              All major topics from Chapters 1-8 covered           ║" << endl;
    cout << "╚══════════════════════════════════════════════════════════════════╝" << endl;
    
    return 0;
}