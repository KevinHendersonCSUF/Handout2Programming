//-------------------------------------------------------------------------------------------------------------
// Group names: Gonong, Theo and Henderson, Kevin and Le, Anthony
// Assignment : No.2
// Due date : 9/18/24
// Purpose: this program reads an expression in postfix form, evaluates the
// expression and displays its value
//-----------------------------------------------------------------------------------------------------------------
#include <cstdlib>
#include <iostream>
#include <stack>
#include <string>

int main() {
  while (true) {
    std::string expression;
    std::stack<int> stack;
    char cont;
    std::cout << "Enter a postfix expression with a $ at the end:" << std::endl;
    std::cin >> expression;
    for (int i = 0; i < expression.size(); i++) {
    std::string temp;
    int temp_value = 0;
    bool contains_letter = false;
    //   if (expression[i] == '1' || expression[i] == '2' ||
    //       expression[i] == '3' || expression[i] == '4' ||
    //       expression[i] == '5' || expression[i] == '6' ||
    //       expression[i] == '7' || expression[i] == '8' ||
    //       expression[i] == '9' || expression[i] == '0') {

    //   }
    if (expression[i] != ' ' && expression[i] != '+' && expression[i] != '-' && expression[i] != '*' && expression[i] != '$') {
        temp.push_back(expression[i]);
    }
    else {
        for (int j = 0; j < temp.size(); j++) {
            if(j < '0' && j > '9') {
            contains_letter = true;
            break;
            }
        }
    if(contains_letter == true) {
        std::cout << "\n Enter the value of " << temp << ": ";
        std::cin >> temp_value;
        stack.push(temp_value);
        temp.clear();
        contains_letter = false;
    }
    else if(contains_letter == false) {
        temp_value = stoi(temp);
        stack.push(temp_value);
    }
    }
    if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*') {
        if(expression[i] == '+')
        {
            int top = stack.top();
            stack.pop();
            int bottom = stack.top();
            stack.pop();
            int sum = bottom + top;
            stack.push(sum);
        }
        if(expression[i] == '-')
        {
            int top = stack.top();
            stack.pop();
            int bottom = stack.top();
            stack.pop();
            int sub = bottom - top;
            stack.push(sub);
        }
        if(expression[i] == '*')
        {
            int top = stack.top();
            stack.pop();
            int bottom = stack.top();
            stack.pop();
            int multi = bottom * top;
            stack.push(multi);
        }
    }
   else {
        int final_value = stack.top();
        std::cout << "Expression's value is " << final_value << std::endl;
        break; 
    }
    }
    std::cout << "CONTINUE(y/n)?";
    std::cin >> cont;
    if (cont == 'n') {
        break;
    }
    if(cont != 'n' && cont != 'y') {
        std::cout << "invalid input, terminating program" << std::endl;
    }
  }
  return 0;
}
