//-------------------------------------------------------------------------------------------------------------
// Group names: Gonong, Theo and Henderson, Kevin and Le, Anthony
// Assignment : No.2
// Due date : 9/18/24
// Purpose: this program reads an expression in postfix form, evaluates the
// expression and displays its value
//-----------------------------------------------------------------------------------------------------------------
#include <iostream>     // For input/output
#include <stack>        // For stack data structure
#include <string>       // For string manipulation
#include <sstream>      // For string stream
#include <unordered_map>        // For hash map
#include <cctype>       // For isdigit

int main() {
    while (true) {
        std::string expression;
        std::stack<int> stack;
        std::unordered_map<std::string, int> variables;
        char cont;
        
        std::cout << "Enter a postfix expression with a $ at the end:" << std::endl;
        std::getline(std::cin, expression);  // Read the entire line for expression
        
        std::stringstream ss(expression);
        std::string token;
        
        // Process the postfix expression
        while (ss >> token) {
            if (token == "$") {
                break;
            } else if (token == "+" || token == "-" || token == "*") {
                // Handle operators
                int top = stack.top();
                stack.pop();
                int bottom = stack.top();
                stack.pop();
                
                if (token == "+") {
                    stack.push(bottom + top);
                } else if (token == "-") {
                    stack.push(bottom - top);
                } else if (token == "*") {
                    stack.push(bottom * top);
                }
            } else {
                // Handle numbers and variables
                if (isdigit(token[0]) || (token[0] == '-' && token.size() > 1 && isdigit(token[1]))) {
                    // If the token is an integer 
                    stack.push(std::stoi(token));
                } else {
                    // If token is a variable
                    if (variables.find(token) == variables.end()) {
                        // Prompt for the variable's value 
                        int value;
                        std::cout << "Enter the value of " << token << ": ";
                        std::cin >> value;
                        variables[token] = value;
                    }
                    stack.push(variables[token]);
                }
            }
        }
        
        // Display the final result
        int final_value = stack.top();
        std::cout << "Expression's value is " << final_value << std::endl;
        
        // Ask for continuation
        std::cout << "CONTINUE(y/n)? ";
        std::cin >> cont;
        std::cin.ignore(); // To handle the newline after the input
        if (cont == 'n') {
            break;
        }
    }
    
    return 0;
}
