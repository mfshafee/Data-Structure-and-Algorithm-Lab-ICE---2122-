#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

// Check if character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Get precedence of operators
int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

// Check if operator is right associative
bool isRightAssociative(char op) {
    return (op == '^');
}

// ===========================================
// PREFIX TO INFIX CONVERSION
// ===========================================
string prefixToInfix(string prefix) {
    stack<string> s;
    
    // Scan from right to left
    for (int i = prefix.length() - 1; i >= 0; i--) {
        char c = prefix[i];
        
        // Skip spaces
        if (c == ' ') continue;
        
        // If operand, push to stack
        if (isalnum(c)) {
            s.push(string(1, c));
        }
        // If operator, pop two operands and create infix expression
        else if (isOperator(c)) {
            if (s.size() < 2) {
                return "Invalid Expression";
            }
            string op1 = s.top(); s.pop();
            string op2 = s.top(); s.pop();
            string temp = "(" + op1 + c + op2 + ")";
            s.push(temp);
        }
    }
    
    if (s.size() != 1) {
        return "Invalid Expression";
    }
    return s.top();
}

// ===========================================
// INFIX TO PREFIX CONVERSION
// ===========================================
string infixToPrefix(string infix) {
    stack<char> operators;
    stack<string> operands;
    
    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];
        
        // Skip spaces
        if (c == ' ') continue;
        
        // If operand, push to operands stack
        if (isalnum(c)) {
            operands.push(string(1, c));
        }
        // If opening parenthesis, push to operators stack
        else if (c == '(') {
            operators.push(c);
        }
        // If closing parenthesis, pop until opening parenthesis
        else if (c == ')') {
            while (!operators.empty() && operators.top() != '(') {
                if (operands.size() < 2) {
                    return "Invalid Expression";
                }
                string op2 = operands.top(); operands.pop();
                string op1 = operands.top(); operands.pop();
                char op = operators.top(); operators.pop();
                
                string temp = op + op1 + op2;
                operands.push(temp);
            }
            if (!operators.empty()) operators.pop(); // Remove '('
        }
        // If operator
        else if (isOperator(c)) {
            while (!operators.empty() && operators.top() != '(' &&
                   ((isRightAssociative(c) && precedence(c) < precedence(operators.top())) ||
                    (!isRightAssociative(c) && precedence(c) <= precedence(operators.top())))) {
                if (operands.size() < 2) {
                    return "Invalid Expression";
                }
                string op2 = operands.top(); operands.pop();
                string op1 = operands.top(); operands.pop();
                char op = operators.top(); operators.pop();
                
                string temp = op + op1 + op2;
                operands.push(temp);
            }
            operators.push(c);
        }
    }
    
    // Pop remaining operators
    while (!operators.empty()) {
        if (operands.size() < 2) {
            return "Invalid Expression";
        }
        string op2 = operands.top(); operands.pop();
        string op1 = operands.top(); operands.pop();
        char op = operators.top(); operators.pop();
        
        string temp = op + op1 + op2;
        operands.push(temp);
    }
    
    if (operands.size() != 1) {
        return "Invalid Expression";
    }
    return operands.top();
}

// ===========================================
// POSTFIX TO INFIX CONVERSION
// ===========================================
string postfixToInfix(string postfix) {
    stack<string> s;
    
    for (int i = 0; i < postfix.length(); i++) {
        char c = postfix[i];
        
        // Skip spaces
        if (c == ' ') continue;
        
        // If operand, push to stack
        if (isalnum(c)) {
            s.push(string(1, c));
        }
        // If operator, pop two operands and create infix expression
        else if (isOperator(c)) {
            if (s.size() < 2) {
                return "Invalid Expression";
            }
            string op2 = s.top(); s.pop();
            string op1 = s.top(); s.pop();
            string temp = "(" + op1 + c + op2 + ")";
            s.push(temp);
        }
    }
    
    if (s.size() != 1) {
        return "Invalid Expression";
    }
    return s.top();
}

// ===========================================
// INFIX TO POSTFIX CONVERSION
// ===========================================
string infixToPostfix(string infix) {
    stack<char> s;
    string postfix = "";
    
    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];
        
        // Skip spaces
        if (c == ' ') continue;
        
        // If operand, add to output
        if (isalnum(c)) {
            postfix += c;
        }
        // If opening parenthesis, push to stack
        else if (c == '(') {
            s.push(c);
        }
        // If closing parenthesis, pop until opening parenthesis
        else if (c == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            if (!s.empty()) s.pop(); // Remove '('
        }
        // If operator
        else if (isOperator(c)) {
            while (!s.empty() && s.top() != '(' &&
                   ((isRightAssociative(c) && precedence(c) < precedence(s.top())) ||
                    (!isRightAssociative(c) && precedence(c) <= precedence(s.top())))) {
                postfix += s.top();
                s.pop();
            }
            s.push(c);
        }
    }
    
    // Pop remaining operators
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }
    
    return postfix;
}

// ===========================================
// PREFIX TO POSTFIX CONVERSION
// ===========================================
string prefixToPostfix(string prefix) {
    stack<string> s;
    
    // Scan from right to left
    for (int i = prefix.length() - 1; i >= 0; i--) {
        char c = prefix[i];
        
        // Skip spaces
        if (c == ' ') continue;
        
        // If operand, push to stack
        if (isalnum(c)) {
            s.push(string(1, c));
        }
        // If operator, pop two operands and create postfix expression
        else if (isOperator(c)) {
            if (s.size() < 2) {
                return "Invalid Expression";
            }
            string op1 = s.top(); s.pop();
            string op2 = s.top(); s.pop();
            string temp = op1 + op2 + c;
            s.push(temp);
        }
    }
    
    if (s.size() != 1) {
        return "Invalid Expression";
    }
    return s.top();
}

// ===========================================
// POSTFIX TO PREFIX CONVERSION
// ===========================================
string postfixToPrefix(string postfix) {
    stack<string> s;
    
    for (int i = 0; i < postfix.length(); i++) {
        char c = postfix[i];
        
        // Skip spaces
        if (c == ' ') continue;
        
        // If operand, push to stack
        if (isalnum(c)) {
            s.push(string(1, c));
        }
        // If operator, pop two operands and create prefix expression
        else if (isOperator(c)) {
            if (s.size() < 2) {
                return "Invalid Expression";
            }
            string op2 = s.top(); s.pop();
            string op1 = s.top(); s.pop();
            string temp = c + op1 + op2;
            s.push(temp);
        }
    }
    
    if (s.size() != 1) {
        return "Invalid Expression";
    }
    return s.top();
}

// ===========================================
// MAIN FUNCTION WITH MENU
// ===========================================
int main() {
    int choice;
    string expression, result;
    
    cout << "\n========================================\n";
    cout << "   ARITHMETIC EXPRESSION CONVERTER\n";
    cout << "========================================\n";
    
    do {
        cout << "\n--- CONVERSION MENU ---\n";
        cout << "1. Prefix to Infix\n";
        cout << "2. Infix to Prefix\n";
        cout << "3. Postfix to Infix\n";
        cout << "4. Infix to Postfix\n";
        cout << "5. Prefix to Postfix\n";
        cout << "6. Postfix to Prefix\n";
        cout << "0. Exit\n";
        cout << "\nEnter your choice: ";
        cin >> choice;
        cin.ignore(); // Clear the newline character
        
        if (choice == 0) break;
        
        if (choice < 1 || choice > 6) {
            cout << "Invalid choice! Please try again.\n";
            continue;
        }
        
        cout << "Enter expression (no spaces for operands): ";
        getline(cin, expression);
        
        switch (choice) {
            case 1:
                result = prefixToInfix(expression);
                cout << "Prefix to Infix: " << result << endl;
                break;
            case 2:
                result = infixToPrefix(expression);
                cout << "Infix to Prefix: " << result << endl;
                break;
            case 3:
                result = postfixToInfix(expression);
                cout << "Postfix to Infix: " << result << endl;
                break;
            case 4:
                result = infixToPostfix(expression);
                cout << "Infix to Postfix: " << result << endl;
                break;
            case 5:
                result = prefixToPostfix(expression);
                cout << "Prefix to Postfix: " << result << endl;
                break;
            case 6:
                result = postfixToPrefix(expression);
                cout << "Postfix to Prefix: " << result << endl;
                break;
        }
        
        cout << "\n";
        
    } while (choice != 0);
    
    cout << "\nThank you for using the Expression Converter!\n";
    
    return 0;
}