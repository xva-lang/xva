grammar xva;
module: (statement | simpleFunction | complexFunction | controlBlock) * EOF;

builtInType: INTEGER_TYPE | FLOAT_TYPE | STRING_TYPE | BOOLEAN_TYPE;
typeAnnotation: ':' MUTABLE? (builtInType | IDENTIFIER);
declaration: (LET IDENTIFIER typeAnnotation? ASSIGNMENT_OPERATOR expression) | simpleFunction ;
assignment: IDENTIFIER ASSIGNMENT_OPERATOR expression;


statement: 
    (declaration 
    | assignment 
    | functionCall 
    | BREAK) 
    SEMICOLON;


// Functions
functionParameter: IDENTIFIER typeAnnotation;
returnType: typeAnnotation | ':' VOID;
parameterList: '(' functionParameter* ')';
simpleFunction: DEF IDENTIFIER parameterList returnType FAT_ARROW expression;
complexFunction: DEF IDENTIFIER parameterList returnType statement* END;
lambdaExpr: DEF parameterList returnType? FAT_ARROW expression;
anonymousFunction: DEF parameterList returnType? statement* END;




// Constant rules
integerConstant: 
    INTEGER_CONSTANT_DECIMAL | 
    INTEGER_CONSTANT_OCTAL | 
    INTEGER_CONSTANT_HEXADECIMAL | 
    INTEGER_CONSTANT_BINARY
    ;

floatConstant: 
    FLOAT_CONSTANT | 
    DOUBLE_CONSTANT | 
    PRECISE_CONSTANT;

stringConstant: STRING_CONSTANT;
charConstant: CHAR_CONSTANT;

booleanConstant: TRUE | FALSE;

// Expressions
expression: 
    integerConstant             #IntegerExpresssion
    | booleanConstant           #BooleanExpression
    | floatConstant             #FloatExpression
    | charConstant              #CharExpression
    | stringConstant            #StringExpression
    | anonymousFunction         #AnonymousFunctionExpression
    | lambdaExpr                #LambdaExpression
    | parenthesisedExpr         #ParenthesisedExpression         
    | expression IF expression ELSE expression               #TernaryExpression
    | IDENTIFIER                #IdentifierExpression
    ;

parenthesisedExpr: '(' expression ')';


functionCall: IDENTIFIER '(' expression* ')';

// Blocks
controlBlock: 
    ifBlock
    | loopBlock
    | whileBlock;

ifBlock: 
    (IF expression statement*)
    (ELSE_IF expression statement*)*
    (ELSE statement*) 
    END
    ;

loopBlock:
    LOOP statement* END;

whileBlock: 
    WHILE expression statement* END;

// Keywords
LET: 'let';
MUTABLE: 'mutable';
NULL: 'null';
DEFAULT: 'default';
TRUE: 'true';
FALSE: 'false';
DEF: 'def';
VOID: 'void';
END: 'end';
IF: 'if';
ELSE: 'else';
ELSE_IF: 'else if';
LOOP: 'loop';
BREAK: 'break';
WHILE: 'while';


// Operators
ASSIGNMENT_OPERATOR: '=';
LOWER_THAN_OPERATOR: '<';
LOWER_THAN_EQUAL_OPERATOR: '<=';
GREATER_THAN_OPERATOR: '>';
GREATER_THAN_EQUAL_OPERATOR: '>=';
EQUALITY_OPERATOR: '==';
IS_OPERATOR: 'is';

// Constant tokens
INTEGER_CONSTANT_DECIMAL: '-'? [0-9]+;
INTEGER_CONSTANT_OCTAL : '0o' [0-7]*;
INTEGER_CONSTANT_HEXADECIMAL : '0x' ([a-fA-F0-9])+;
INTEGER_CONSTANT_BINARY: '0b' [0-1]+;

FLOAT_CONSTANT: '-'? [0-9]+ '.' [0-9]+ ;
DOUBLE_CONSTANT: '-'? [0-9]+ '.' [0-9]+ 'd' ;
PRECISE_CONSTANT: '-'? [0-9]+ '.' [0-9]+ 'p' ;

CHAR_CONSTANT: SINGLE_QUOTE ('\u0000'..'\uFFFe' | EMOTICONS) SINGLE_QUOTE ;
STRING_CONSTANT: DOUBLE_QUOTE ('\u0000'..'\uFFFe' | EMOTICONS)* DOUBLE_QUOTE;

// Identifiers
IDENTIFIER: [a-zA-Z_][a-zA-Z0-9_]*;
INTEGER_TYPE: 'byte' | 'short' | 'int' | 'long' | 'ubyte' | 'ushort' | 'uint' | 'ulong' ;
FLOAT_TYPE: 'float' | 'double' | 'precise';
STRING_TYPE: 'char' | 'string';
BOOLEAN_TYPE: 'boolean';

// TYPE: 'boolean' | ''
// Symbols
SEMICOLON: ';';
COLON: ':';
FAT_ARROW: '=>';
SINGLE_QUOTE: '\'';
DOUBLE_QUOTE: '"';
EMOTICONS : ('\u{1F600}' | '\u{1F602}' | '\u{1F615}') ;

// Whitespace
WS: [ \t\r\n]+ -> skip;
