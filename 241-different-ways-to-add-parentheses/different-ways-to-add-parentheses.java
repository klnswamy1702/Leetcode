import java.util.*;

class Solution {
    Map<String, List<Integer>> memo = new HashMap<>();
    
    public List<Integer> diffWaysToCompute(String expression) {
        // Check if already computed
        if (memo.containsKey(expression)) {
            return memo.get(expression);
        }
        
        List<Integer> result = new ArrayList<>();
        
        // Try splitting at each operator
        for (int i = 0; i < expression.length(); i++) {
            char c = expression.charAt(i);
            
            if (c == '+' || c == '-' || c == '*') {
                // Divide: split into left and right parts
                String leftPart = expression.substring(0, i);
                String rightPart = expression.substring(i + 1);
                
                // Conquer: recursively compute all results
                List<Integer> leftResults = diffWaysToCompute(leftPart);
                List<Integer> rightResults = diffWaysToCompute(rightPart);
                
                // Combine: apply operator to all combinations
                for (int left : leftResults) {
                    for (int right : rightResults) {
                        int value = 0;
                        switch (c) {
                            case '+':
                                value = left + right;
                                break;
                            case '-':
                                value = left - right;
                                break;
                            case '*':
                                value = left * right;
                                break;
                        }
                        result.add(value);
                    }
                }
            }
        }
        
        // Base case: no operators found, expression is just a number
        if (result.isEmpty()) {
            result.add(Integer.parseInt(expression));
        }
        
        // Memoize and return
        memo.put(expression, result);
        return result;
    }
}
