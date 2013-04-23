public class Calculator {
        private String input_;

        // current position within the input string
        private int index_; 
        /**
         * constructor for calculator objects
         * @param input The string the user enters.
         * @return Calculator object
         */
        public Calculator(String input) {
                this.input_ = input;
                this.index_ = 0;
        }
        /**
         * calls the methods that calculate the final answer
         * @return the evaluated answer
         */
        public BigDecimal evaluate() {
                //input_.toLowerCase(); could be used to lower command errors but decreases number of variables
                skipWhiteSpace();
                char lookahead = input_.charAt(index_);
                // find set x 1.23 before error()
                BigDecimal value = null;
                if(input_.startsWith("set ")){
                        // set a variable with value of strings and doubles i.e a map
                }else if(lookahead == '(') {
                        value = evaluateBracketed();                    
                        
                }else if(Character.isDigit(lookahead)) {
                        value = readNumber();
                } else {
                        error();                        
                }

                skipWhiteSpace();// skip whitespace again. Had to add in later 
                if(index_ < input_.length()) {
                        lookahead = input_.charAt(index_);
                        System.out.println("look a head is "+lookahead); // for testing
                        if(lookahead == '+') {
                                match("+");
                                value = value.add(evaluate());
                        } else if(lookahead == '*') { //Typo x instead of *
                                match("*");
                                value = value.multiply(evaluate());
                        } else if(lookahead == '/') {
                                match("/");
                                BigDecimal divisor = evaluate();
                                // See JavaDoc for java.lang.BigDecimal for more information on
                                // why we need to use the scale and rounding mode here.
                                value = value.divide(divisor,10,BigDecimal.ROUND_HALF_UP);// got corrected
                        } else if(lookahead == '-') {
                                match("-");
                                value = value.subtract(evaluate());
                        }else if(lookahead ==')'){
                                //catches ending brackets and   allows program to continue
                        }else {
                                error();
                        }
                }
                
                return value;
        }
        
        /**
         * Does the stuff in the brackets and returns the result
         * @return BigDecimal
         */
        private BigDecimal evaluateBracketed() {
                match("(");
                BigDecimal value = evaluate();
                match(")");
                return value;
        }
        /**
         * Finds a number in the entered input string
         * @return BigDecimal
         */
        private BigDecimal readNumber() {
                int start = index_;
                while (index_ < input_.length()
                                && (Character.isDigit(input_.charAt(index_)) || input_
                                                .charAt(index_) == '.')) { // there was a typo a comma instead of decimal point was place here
                        index_ = index_ + 1;
                }       
                return new BigDecimal(input_.substring(start,index_));          
        }
        /**
         * trys to find a matching character in the input 
         * @param text 
         */
        private void match(String text) {
                skipWhiteSpace();
                if(input_.startsWith(text,index_)) {
                        index_ += text.length();
                } else {
                        error();
                }
        }
        /**
         * skips white spaces and condenses the string
         */
        private void skipWhiteSpace() {         
                while (index_ < input_.length() 
                                && (input_.charAt(index_) == ' ' || input_.charAt(index_) == '\n')) {
                        index_ = index_ + 1;
                }
        }       
        /**
         * error catcher
         */
        private void error() {
                final String msg = "Cannot parse character '"
                        + input_.charAt(index_)
                    + "' at position " + index_ + " of input '" + input_ + "'\n";
                throw new RuntimeException(msg);                
        }
}