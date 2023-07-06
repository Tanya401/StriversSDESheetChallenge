bool isValidParenthesis(string expression)
{
    // Write your code here.
    if(expression.empty()) return true;
    stack<char> st;
    int n = expression.size();
    for(int i=0;i<n;i++){
  if(expression[i]=='(' || expression[i]=='{' || expression[i]=='[') st.push(expression[i]);
  else{
      if(expression[i]==')'){
          if(st.empty() || st.top()!='(') return false;
          st.pop();
      }
      else if(expression[i]=='}'){
          if(st.empty() || st.top()!='{') return false;
          st.pop();
      }
      else if(expression[i]==']'){
          if(st.empty() || st.top()!='[') return false;
          st.pop();
      }
  }
    }
    if(!st.empty()) return false;
    return true;
}