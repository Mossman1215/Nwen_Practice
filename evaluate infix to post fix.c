#include <stdio.h>

int main(void){
	private String input_=scanf();
	// current position within the input string
	private int index_=0; 
	

	return 0;
}

	public BigDecimal evaluate() {
		skipWhiteSpace();
		char lookahead = input_.charAt(index_);
		
		BigDecimal value = null;
		
		if(lookahead == '(') {
			value = evaluateBracketed();			
		} else if(Character.isDigit(lookahead)) {
			value = readNumber();
		} else {
			error();			
		}

		// skip whitespace again
		skipWhiteSpace();
		if(index_ < input_.length()) {
			lookahead = input_.charAt(index_);
			
			if(lookahead == '+') {
				match("+");
				value = value.add(evaluate());
			} else if(lookahead == 'x') {
				match("*");
				value = value.multiply(evaluate());
			} else if(lookahead == '/') {
				match("/");
				BigDecimal divisor = evaluate();
				// See JavaDoc for java.lang.BigDecimal for more information on
				// why we need to use the scale and rounding mode here.
				value = divisor.divide(divisor,10,BigDecimal.ROUND_HALF_UP);
			} else if(lookahead == '-') {
				match("-");
				value = value.subtract(evaluate());
			} else {
				error();
			}
		}
		
		return value;
	}
	
	private BigDecimal evaluateBracketed() {
		match("(");
		BigDecimal value = evaluate();
		match(")");
		return value;
	}
	
	private BigDecimal readNumber() {
		int start = index_;
		while (index_ < input_.length()
				&& (Character.isDigit(input_.charAt(index_)) || input_
						.charAt(index_) == ',')) {
			index_ = index_ + 1;
		}	
		return new BigDecimal(input_.substring(start,index_));		
	}
	
	private void match(String text) {
		skipWhiteSpace();
		if(input_.startsWith(text,index_)) {
			index_ += text.length();
		} else {
			error();
		}
	}
	
	private void skipWhiteSpace() {		
		while (index_ < input_.length()
				&& (input_.charAt(index_) == ' ' || input_.charAt(index_) == '\n')) {
			index_ = index_ + 1;
		}
	}