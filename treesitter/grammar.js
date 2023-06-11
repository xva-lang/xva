const KEYWORDS = {
  LET: "let",
  DEF: "def",
  RETURN: "return",
  TRUE: "true",
  FALSE: "false",
  NOT: "not",
  MUTABLE: "mutable",
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
  EQUALS: "=",
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

const BUILT_IN_TYPES = [
  "byte",
  "ushort",
  "uint",
  "ulong",
  "sbyte",
  "short",
  "int",
  "long",
  "float",
  "double",
  "boolean",
  "char",
];

module.exports = grammar({
  name: "xva",

  word: ($) => $.identifier,

  rules: {
    source_file: ($) => repeat($._statement),

    _statement: ($) => choice($._declaration_statement, $._expression),

    _declaration_statement: ($) => choice($.let_declaration),
    let_declaration: ($) =>
      seq(
        $._let_keyword,
        $.identifier,
        optional($.type_annotation),
        $.assignment
      ),
    assignment: ($) => seq($._equals_symbol, $._expression),

    type_annotation: ($) =>
      seq($._colon_symbol, optional($.mutable_modifier), $.type),

    mutable_modifier: ($) => KEYWORDS.MUTABLE,

    type: ($) => choice($.built_in_type, $.identifier),
    _colon_symbol: ($) => SYMBOLS.COLON,
    _equals_symbol: ($) => SYMBOLS.EQUALS,
    _let_keyword: ($) => KEYWORDS.LET,
    built_in_type: ($) => choice(...BUILT_IN_TYPES),
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
