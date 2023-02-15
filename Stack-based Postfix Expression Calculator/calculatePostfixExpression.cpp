#include <string>
#include <stack>

using namespace std;

// Calculates a postfix expression with integer operands using a stack
// The expression is represented using an array of strings
// Each string is either an operand or operator symbol
// Operator symbols:
//   "+" addition
//   "-" subtraction
//   "*" multiplication
//   "/" divison
//   "%" remainder
// Example expression: "8", "5", "-" evaluates to a result of 3:
//   1: push 8, 2: push 5,
//   3: "-"-> pop top two values, earlier value is the left-side operand: 8 - 5
//   The result of the operation (8-5) is 3, push 3 onto stack
// After evaluation of the expression, the final result should be
// the only value on the stack, return 0 if the stack is
// non-empty after popping the result
// Return 0 if expression is zero-length or if there are insufficient operands
// for an operation
// The STL Stack class can be used
// To easily convert a numeric string to an int you may use the stoi() function
// which takes a string as a parameter and returns a string
int calculatePostfixExpression(string expression[], int length)
{
    // Create a stack to hold the operands
    stack<int> operands;

    // Iterate through the expression array, processing each token one at a time
    for (int i = 0; i < length; i++) {
        string token = expression[i];

        // If the token is an operator, pop the top two operands from the stack,
        // perform the corresponding operation, and push the result back onto the stack
        if (token == "+") {
            if (operands.size() < 2) return 0;
            int right_operand = operands.top(); operands.pop();
            int left_operand = operands.top(); operands.pop();
            operands.push(left_operand + right_operand);
        } else if (token == "-") {
            if (operands.size() < 2) return 0;
            int right_operand = operands.top(); operands.pop();
            int left_operand = operands.top(); operands.pop();
            operands.push(left_operand - right_operand);
        } else if (token == "*") {
            if (operands.size() < 2) return 0;
            int right_operand = operands.top(); operands.pop();
            int left_operand = operands.top(); operands.pop();
            operands.push(left_operand * right_operand);
        } else if (token == "/") {
            if (operands.size() < 2) return 0;
            int right_operand = operands.top(); operands.pop();
            int left_operand = operands.top(); operands.pop();
            if (right_operand == 0) return 0; // division by zero
            operands.push(left_operand / right_operand);
        } else if (token == "%") {
            if (operands.size() < 2) return 0;
            int right_operand = operands.top(); operands.pop();
            int left_operand = operands.top(); operands.pop();
            if (right_operand == 0) return 0; // modulo by zero
            operands.push(left_operand % right_operand);
        } else {
            // If the token is an operand (i.e., a numeric string),
            // convert it to an integer using the stoi function and push it onto the stack
            int operand = stoi(token);
            operands.push(operand);
        }
    }

    // After processing all tokens, the final result should be the only value
    // left on the stack. If there is more than one
    // value on the stack, or if the stack is empty, return 0.
    if (operands.size() != 1) return 0;

    // Otherwise, return the final result
    return operands.top();
}