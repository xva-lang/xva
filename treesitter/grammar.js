const KEYWORDS = {
  DEF: "def",
  RETURN: "return",
  TRUE: "true",
  FALSE: "false",
  NOT: "not",
};

const SYMBOLS = {
  OPEN_PARENTHESIS: "(",
  CLOSE_PARENTHESIS: ")",
  OPEN_BRACE: "{",
  CLOSE_BRACE: "}",
  COLON: ":",
  COMMA: ",",
  DOUBLE_QUOTE: '"',
  SINGLE_QUOTE: "'",
  PLUS: "+",
  MINUS: "-",
  STAR: "*",
  SLASH: "/",
  PERCENT: "%",
  DOUBLE_STAR: "**",
};

const PRECEDENCE = {
  ASSIGNMENT: 1,
  LAMBDA: 2,
  TERNARY: 3,
  OR: 4,
  AND: 5,
  NOT: 6,
  COMPARISION: 7,
  BIT_OR: 8,
  BIT_XOR: 9,
  BIT_AND: 10,
  BIT_SHIFT: 11,
  ADD_SUB: 12,
  MUL_DIV_MOD: 13,
  NEGATE: 14,
  EXPONENT: 15,
  AWAIT: 16,
  CALL: 17,
  PARENTHESISED: 18,
};

module.exports = grammar({
  name: "xva",

  word: ($) => $.identifier,

  rules: {
    source_file: ($) => repeat($._expression),

    // _definition: ($) =>
    //   choice(
    //     $.function_definition
    //     // TODO: other kinds of definitions
    //   ),

    // function_return_type: ($) => seq(SYMBOLS.COLON, $.identifier),

    // function_definition: ($) =>
    //   seq(
    //     KEYWORDS.DEF,
    //     $.identifier,
    //     $.parameter_list,
    //     optional($.function_return_type),
    //     $.block
    //   ),

    // function_parameter_definition: ($) =>
    //   seq($.identifier, SYMBOLS.COLON, $.identifier),

    // parameter_list: ($) =>
    //   choice(
    //     seq(SYMBOLS.OPEN_PARENTHESIS, SYMBOLS.CLOSE_PARENTHESIS)
    //     // seq(
    //     //   SYMBOLS.OPEN_PARENTHESIS,
    //     //   choice(
    //     //     $.function_parameter_definition,
    //     //     seq(
    //     //       $.function_definition,
    //     //       SYMBOLS.COMMA,
    //     //       repeat(seq(SYMBOLS.COMMA, $.function_definition))
    //     //     )
    //     //   ),
    //     //   SYMBOLS.CLOSE_PARENTHESIS
    //     // )
    //   ),
    // _type: ($) =>
    //   choice(
    //     "bool"
    //     // TODO: other kinds of types
    //   ),

    // block: ($) =>
    //   seq(SYMBOLS.OPEN_BRACE, repeat($._statement), SYMBOLS.CLOSE_BRACE),

    // _statement: ($) =>
    //   choice(
    //     $.return_statement
    //     // TODO: other kinds of statements
    //   ),

    // return_statement: ($) => seq(KEYWORDS.RETURN, $._expression),

    _expression: ($) =>
      choice($.literal, $.identifier, $.unary_expression, $.binary_expression),

    unary_expression: ($) =>
      prec(
        2,
        choice(
          seq(SYMBOLS.MINUS, $._expression),
          seq(KEYWORDS.NOT, $._expression)
        )
      ),

    binary_expression: ($) =>
      choice(
        prec.left(
          PRECEDENCE.ADD_SUB,
          seq($._expression, SYMBOLS.PLUS, $._expression)
        ),
        prec.left(
          PRECEDENCE.ADD_SUB,
          seq($._expression, SYMBOLS.MINUS, $._expression)
        ),
        prec.left(
          PRECEDENCE.MUL_DIV_MOD,
          seq($._expression, SYMBOLS.STAR, $._expression)
        ),
        prec.left(
          PRECEDENCE.MUL_DIV_MOD,
          seq($._expression, SYMBOLS.SLASH, $._expression)
        ),
        prec.left(
          PRECEDENCE.MUL_DIV_MOD,
          seq($._expression, SYMBOLS.PERCENT, $._expression)
        ),
        prec.left(
          PRECEDENCE.EXPONENT,
          seq($._expression, SYMBOLS.DOUBLE_STAR, $._expression)
        )
      ),

    hex_literal: ($) => /0[xX][a-fA-F0-9](?:_?[a-fA-F0-9])/,
    octal_literal: ($) => /0[oO][0-7](?:_?[0-7])/,
    binary_literal: ($) => /0[bB][01](?:_?[01])/,
    decimal_literal: ($) => /(?:0|[1-9](?:_*[0-9])*)/,
    boolean_literal: ($) => /true|false/,
    string_literal: ($) =>
      seq(
        SYMBOLS.DOUBLE_QUOTE,
        repeat($.character_literal),
        SYMBOLS.DOUBLE_QUOTE
      ),

    // character_literal, character_literal_unescaped and escape_sequence were all borrowed from
    // tree-sitter-csharp: https://github.com/tree-sitter/tree-sitter-c-sharp/
    character_literal: ($) =>
      seq(
        SYMBOLS.SINGLE_QUOTE,
        choice($.character_literal_unescaped, $.escape_sequence),
        SYMBOLS.SINGLE_QUOTE
      ),

    character_literal_unescaped: ($) => token.immediate(/[^'\\]/),

    escape_sequence: ($) =>
      token(
        choice(
          /\\x[0-9a-fA-F][0-9a-fA-F]?[0-9a-fA-F]?[0-9a-fA-F]?/,
          /\\u[0-9a-fA-F][0-9a-fA-F][0-9a-fA-F][0-9a-fA-F]/,
          /\\U[0-9a-fA-F][0-9a-fA-F][0-9a-fA-F][0-9a-fA-F][0-9a-fA-F][0-9a-fA-F][0-9a-fA-F][0-9a-fA-F]/,
          /\\[^xuU]/
        )
      ),

    literal: ($) =>
      choice(
        $.hex_literal,
        $.octal_literal,
        $.binary_literal,
        $.decimal_literal,
        $.boolean_literal,
        $.character_literal,
        $.string_literal
      ),

    identifier: ($) => /[a-zA-Z_][a-zA-Z0-9_]*/,
  },
});
