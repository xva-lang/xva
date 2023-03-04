const KEYWORDS = {
  DEF: "def",
  RETURN: "return",
  TRUE: "true",
  FALSE: "false",
};

const SYMBOLS = {
  OPEN_PARENTHESIS: "(",
  CLOSE_PARENTHESIS: ")",
  OPEN_BRACE: "{",
  CLOSE_BRACE: "}",
  COLON: ":",
  COMMA: ",",
};

module.exports = grammar({
  name: "xva",

  word: ($) => $.identifier,

  rules: {
    source_file: ($) => repeat($.expression),

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

    expression: ($) =>
      choice(
        prec(1, $.literal),
        $.identifier

        // TODO: other kinds of expressions
      ),

    hex_literal: ($) => /0[xX][a-fA-F0-9](?:_?[a-fA-F0-9])/,
    octal_literal: ($) => /0[oO][0-7](?:_?[0-7])/,
    binary_literal: ($) => /0[bB][01](?:_?[01])/,
    decimal_literal: ($) => /(?:0|[1-9](?:_*[0-9])*)/,
    boolean_literal: ($) => /true|false/,
    literal: ($) =>
      choice(
        $.hex_literal,
        $.octal_literal,
        $.binary_literal,
        $.decimal_literal,
        $.boolean_literal
      ),

    identifier: ($) => /[a-zA-Z_][a-zA-Z0-9_]*/,
  },
});
