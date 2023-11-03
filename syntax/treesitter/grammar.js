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
  LEFT_ANGLE: "<",
  RIGHT_ANGLE: ">",
  INCREMENT: "++",
  DECREMENT: "--",
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

const sepBy1 = (sep, rule) => seq(rule, repeat(seq(sep, rule)));
const sepBy = (sep, rule) => optional(sepBy1(sep, rule));

module.exports = grammar({
  name: "xva",

  word: ($) => $.identifier,

  rules: {
    source_file: ($) => repeat($._statement),

    _statement: ($) => choice($._expression),

    _declaration_statement: ($) => choice($.let_declaration, $.function),
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

    block: ($) =>
      seq(
        SYMBOLS.OPEN_BRACE,
        repeat(choice($._declaration_statement, $._expression)),
        SYMBOLS.CLOSE_BRACE
      ),

    // parameters: $ => seq(
    //   '(',
    //   sepBy(',', seq(
    //     optional($.attribute_item),
    //     choice(
    //       $.parameter,
    //       $.self_parameter,
    //       $.variadic_parameter,
    //       '_',
    //       $._type
    //     ))),
    //   optional(','),
    //   ')'
    // ),
    parameter: ($) => seq($.identifier, SYMBOLS.COLON, $.type),
    parameters: ($) =>
      seq(
        SYMBOLS.OPEN_PARENTHESIS,
        sepBy(",", $.parameter),
        SYMBOLS.CLOSE_PARENTHESIS
      ),

    function: ($) =>
      seq(
        KEYWORDS.DEF,
        field("name", $.identifier),
        $.parameters,
        optional(field("return_type", $.type_annotation)),
        field("body", choice($.block, $.arrow_function_body))
      ),

    _fat_arrow: ($) => "=>",
    arrow_function_body: ($) => seq($._fat_arrow, $._expression),
    mutable_modifier: ($) => KEYWORDS.MUTABLE,

    type: ($) => choice($.built_in_type, $.identifier),
    _colon_symbol: ($) => SYMBOLS.COLON,
    _equals_symbol: ($) => SYMBOLS.EQUALS,
    _let_keyword: ($) => KEYWORDS.LET,
    built_in_type: ($) => choice(...BUILT_IN_TYPES),

    _expression: ($) =>
      choice($._primary_expression, $._unary_expression, $._binary_expression),

    /************** Primary expressions *************/
    _primary_expression: ($) => choice($.identifier, $._literal_constant),

    _literal_constant: ($) =>
      choice(
        $.boolean_literal,
        $.decimal_literal,
        $.hex_literal,
        $.binary_literal,
        $.octal_literal,
        $.character_literal,
        $.string_literal
      ),

    /************* Unary expressions **************/
    _unary_expression: ($) => choice($.prefix_expression),

    prefix_expression: ($) =>
      prec.right(seq(choice($.prefix_unary_operator), $._expression)),

    prefix_unary_operator: ($) =>
      choice(SYMBOLS.INCREMENT, SYMBOLS.DECREMENT, SYMBOLS.MINUS, SYMBOLS.PLUS),

    /************* Binary expressions **************/
    _binary_expression: ($) =>
      choice($.multiplicative_expression, $.additive_expression),

    multiplicative_expression: ($) =>
      prec.left(
        PRECEDENCE.MUL_DIV_MOD,
        seq($._expression, $.multiplicative_operator, $._expression)
      ),

    additive_expression: ($) =>
      prec.left(
        PRECEDENCE.ADD_SUB,
        seq($._expression, $.additive_operator, $._expression)
      ),

    /********** Operators ************/
    multiplicative_operator: ($) =>
      choice(SYMBOLS.STAR, SYMBOLS.SLASH, SYMBOLS.PERCENT),

    additive_operator: ($) => choice(SYMBOLS.PLUS, SYMBOLS.MINUS),

    /*********** Literals ************/
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

    identifier: ($) => /[a-zA-Z_][a-zA-Z0-9_]*/,
  },
});
