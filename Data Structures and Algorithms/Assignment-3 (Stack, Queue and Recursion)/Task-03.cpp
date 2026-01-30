#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <cmath>
#include <algorithm>
using namespace std;

// Function to check if a character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Function to get precedence of operators
int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

// Function to perform arithmetic operation
double applyOperation(double a, double b, char op) {
    switch(op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': 
            if (b == 0) {
                cout << "Error: Division by zero!" << endl;
                return 0;
            }
            return a / b;
        case '^': return pow(a, b);
        default: return 0;
    }
}

// Function to convert infix to postfix
string infixToPostfix(string infix) {
    stack<char> st;
    string postfix = "";
    
    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];
        
        // Skip spaces
        if (c == ' ') continue;
        
        // If character is operand, add to output
        if (isalnum(c) || c == '.') {
            postfix += c;
        }
        // If character is '(', push to stack
        else if (c == '(') {
            postfix += ' ';
            st.push(c);
        }
        // If character is ')', pop until '(' is found
        else if (c == ')') {
            postfix += ' ';
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                postfix += ' ';
                st.pop();
            }
            if (!st.empty()) st.pop(); // Remove '('
        }
        // If character is operator
        else if (isOperator(c)) {
            postfix += ' ';
            while (!st.empty() && precedence(st.top()) >= precedence(c) && st.top() != '(') {
                postfix += st.top();
                postfix += ' ';
                st.pop();
            }
            st.push(c);
        }
    }
    
    postfix += ' ';
    // Pop remaining operators
    while (!st.empty()) {
        postfix += st.top();
        postfix += ' ';
        st.pop();
    }
    
    return postfix;
}

// Function to evaluate postfix expression
double evaluatePostfix(string postfix) {
    stack<double> st;
    string num = "";
    
    for (int i = 0; i < postfix.length(); i++) {
        char c = postfix[i];
        
        // Build number (including decimals)
        if (isdigit(c) || c == '.') {
            num += c;
        }
        else if (c == ' ') {
            if (!num.empty()) {
                st.push(stod(num));
                num = "";
            }
        }
        // If character is operator
        else if (isOperator(c)) {
            if (st.size() < 2) {
                cout << "Error: Invalid postfix expression!" << endl;
                return 0;
            }
            double b = st.top(); st.pop();
            double a = st.top(); st.pop();
            st.push(applyOperation(a, b, c));
        }
    }
    
    if (st.size() != 1) {
        cout << "Error: Invalid postfix expression!" << endl;
        return 0;
    }
    
    return st.top();
}

// Function to evaluate prefix expression
double evaluatePrefix(string prefix) {
    stack<double> st;
    string num = "";
    
    // Process from right to left
    for (int i = prefix.length() - 1; i >= 0; i--) {
        char c = prefix[i];
        
        // Build number (including decimals) - reverse order
        if (isdigit(c) || c == '.') {
            num = c + num;
            if (i == 0 || (!isdigit(prefix[i-1]) && prefix[i-1] != '.')) {
                st.push(stod(num));
                num = "";
            }
        }
        else if (c == ' ') {
            continue;
        }
        // If character is operator
        else if (isOperator(c)) {
            if (st.size() < 2) {
                cout << "Error: Invalid prefix expression!" << endl;
                return 0;
            }
            double a = st.top(); st.pop();
            double b = st.top(); st.pop();
            st.push(applyOperation(a, b, c));
        }
    }
    
    if (st.size() != 1) {
        cout << "Error: Invalid prefix expression!" << endl;
        return 0;
    }
    
    return st.top();
}

// Function to evaluate infix expression
double evaluateInfix(string infix) {
    string postfix = infixToPostfix(infix);
    cout << "Converted to Postfix: " << postfix << endl;
    return evaluatePostfix(postfix);
}

// Display menu
void displayMenu() {
    cout << "\n========================================" << endl;
    cout << "   EXPRESSION EVALUATOR USING STACK" << endl;
    cout << "========================================" << endl;
    cout << "1. Evaluate Infix Expression" << endl;
    cout << "2. Evaluate Postfix Expression" << endl;
    cout << "3. Evaluate Prefix Expression" << endl;
    cout << "4. Convert Infix to Postfix" << endl;
    cout << "5. Exit" << endl;
    cout << "========================================" << endl;
    cout << "Enter your choice: ";
}

int main() {
    int choice;
    string expression;
    double result;
    
    cout << "\n*** ARITHMETIC EXPRESSION EVALUATOR ***\n";
    cout << "Supported operators: +, -, *, /, ^(power)\n";
    cout << "Use spaces between operators and operands for prefix/postfix\n";
    
    do {
        displayMenu();
        cin >> choice;
        cin.ignore(); // Clear newline from buffer
        
        switch(choice) {
            case 1:
                cout << "\nEnter Infix Expression (e.g., (3+5)*2): ";
                getline(cin, expression);
                cout << "\nEvaluating Infix Expression: " << expression << endl;
                result = evaluateInfix(expression);
                cout << "Result: " << result << endl;
                break;
                
            case 2:
                cout << "\nEnter Postfix Expression (e.g., 3 5 + 2 *): ";
                getline(cin, expression);
                cout << "\nEvaluating Postfix Expression: " << expression << endl;
                result = evaluatePostfix(expression);
                cout << "Result: " << result << endl;
                break;
                
            case 3:
                cout << "\nEnter Prefix Expression (e.g., * + 3 5 2): ";
                getline(cin, expression);
                cout << "\nEvaluating Prefix Expression: " << expression << endl;
                result = evaluatePrefix(expression);
                cout << "Result: " << result << endl;
                break;
                
            case 4:
                cout << "\nEnter Infix Expression (e.g., (3+5)*2): ";
                getline(cin, expression);
                cout << "\nInfix Expression: " << expression << endl;
                cout << "Postfix Expression: " << infixToPostfix(expression) << endl;
                break;
                
            case 5:
                cout << "\nThank you for using Expression Evaluator!" << endl;
                break;
                
            default:
                cout << "\nInvalid choice! Please try again." << endl;
        }
        
        if (choice != 5) {
            cout << "\nPress Enter to continue...";
            cin.get();
        }
        
    } while(choice != 5);
    
    return 0;
}