const KEYWORDS = {
  LET: "let",
  DEF: "def",
  RETURN: "return",
  TRUE: "true",
  FALSE: "false",
  NOT: "not",
  MUTABLE: "mutable",
  AND: "and",
  OR: "or",
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
  DOT: ".",
  AMPERSAND: "&",
  PIPE: "|",
  CARET: "^",
  DOUBLE_RIGHT_ANGLE: ">>",
  DOUBLE_LEFT_ANGLE: "<<",
  GREATER_THAN_EQUALS: ">=",
  LESS_THAN_EQUALS: "<=",
  DOUBLE_EQUALS: "==",
  NOT_EQUALS: "!=",
};

// Borrowed from Rust
const PRECEDENCE = {
  CLOSURE: -1,
  ASSIGN: 0,
  RANGE: 1,
  OR: 2,
  AND: 3,
  COMPARATIVE: 4,
  BITWISE_OR: 5,
  BITWISE_XOR: 6,
  BITWISE_AND: 7,
  SHIFT: 8,
  ADD: 9,
  SUBTRACT: 10,
  MULTIPLY: 11,
  DIVIDE: 12,
  POWER: 13,
  CAST: 14,
  UNARY: 15,
  TRY: 16,
  FIELD: 17,
  CALL: 18,
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

  // https://github.com/tree-sitter/tree-sitter/issues/328
  // The "word" rule being set to an undefined rule causes a weird error when running `tree-sitter generate`
  // word: ($) => $.identifier,

  // Conflicts:
  conflicts: ($) => [[$.float_literal]],

  rules: {
    root: ($) => repeat($._item),

    _item: ($) => choice($.expression),

    expression: ($) =>
      choice($._primary_expression, $.unary_expression, $.binary_expression),

    /************** Expressions *************/
    _primary_expression: ($) => choice($.literal),

    /************** Unary expressions: `-expr`, `not expr` *************/
    unary_expression: ($) => choice($.negation_expression, $.not_expression),

    negation_expression: ($) =>
      prec(PRECEDENCE.UNARY, seq(SYMBOLS.MINUS, $.expression)),
    // _minus_operator: (_) => SYMBOLS.MINUS,

    not_expression: ($) =>
      prec(PRECEDENCE.UNARY, seq(KEYWORDS.NOT, $.expression)),
    // _not_keyword: (_) => KEYWORDS.NOT,

    /*********** Binary expressions ************/
    binary_expression: ($) => {
      const prec_op_map = [
        [PRECEDENCE.AND, KEYWORDS.AND],
        [PRECEDENCE.OR, KEYWORDS.OR],
        [PRECEDENCE.BITWISE_AND, SYMBOLS.AMPERSAND],
        [PRECEDENCE.BITWISE_OR, SYMBOLS.PIPE],
        [PRECEDENCE.BITWISE_XOR, SYMBOLS.CARET],
        [PRECEDENCE.ADD, SYMBOLS.PLUS],
        [PRECEDENCE.SUBTRACT, SYMBOLS.MINUS],
        [PRECEDENCE.MULTIPLY, SYMBOLS.STAR],
        [PRECEDENCE.DIVIDE, SYMBOLS.SLASH],
        [PRECEDENCE.DIVIDE, SYMBOLS.PERCENT],
        [PRECEDENCE.POWER, SYMBOLS.DOUBLE_STAR],

        [
          PRECEDENCE.SHIFT,
          choice(SYMBOLS.DOUBLE_RIGHT_ANGLE, SYMBOLS.DOUBLE_LEFT_ANGLE),
        ],

        [
          PRECEDENCE.COMPARATIVE,
          choice(
            SYMBOLS.LEFT_ANGLE,
            SYMBOLS.RIGHT_ANGLE,
            SYMBOLS.DOUBLE_EQUALS,
            SYMBOLS.NOT_EQUALS,
            SYMBOLS.GREATER_THAN_EQUALS,
            SYMBOLS.LESS_THAN_EQUALS
          ),
        ],
      ];

      return choice(
        ...prec_op_map.map(([precedence, operator]) =>
          prec.left(
            precedence,
            seq(
              field("left", $.expression),
              field("operator", operator),
              field("right", $.expression)
            )
          )
        )
      );
    },

    /*********** Literals ************/
    literal: ($) =>
      choice(
        $.integer_literal,
        $.character_literal,
        $.string_literal,
        $.boolean_literal,
        $.float_literal
      ),

    // TODO: byte literals, byte string literals, raw string literals

    // Integer literals, borrowed from Rust: https://doc.rust-lang.org/reference/tokens.html#integer-literals
    integer_literal: ($) =>
      seq(
        choice(
          $.decimal_literal,
          $.binary_literal,
          $.octal_literal,
          $.hex_literal
        )
      ),

    decimal_literal: ($) => /[0-9]([0-9]|_)*/,
    binary_literal: ($) => /0b([0-1]|_)*[0-1]([0-1]|_)*/,
    octal_literal: ($) => /0o([0-7]|_)*[0-7]([0-7]|_)*/,
    hex_literal: ($) => /0x([0-9a-fA-F]|_)*[0-9a-fA-F]([0-9a-fA-F]|_)*/,

    // Character literals, borrowed from Rust: https://doc.rust-lang.org/reference/tokens.html#character-literals
    character_literal: (_) =>
      token(
        seq(
          SYMBOLS.SINGLE_QUOTE,
          optional(
            choice(
              seq(
                "\\",
                choice(
                  /[^xu]/,
                  /u[0-9a-fA-F]{4}/,
                  /u{[0-9a-fA-F]+}/,
                  /x[0-9a-fA-F]{2}/
                )
              ),
              /[^\\']/
            )
          ),
          SYMBOLS.SINGLE_QUOTE
        )
      ),

    quote_escape: ($) => choice("\\'", '\\"'),
    ascii_escape: ($) =>
      choice(
        seq("\\x", /[0-7]/, /[0-9a-fA-f]/),
        "\\n",
        "\\r",
        "\\t",
        "\\\\",
        "\\0"
      ),
    unicode_escape: ($) => /\\u([0-9a-fA-F]|_*){1,6}/,

    // String literals, borrowed from Rust: https://github.com/tree-sitter/tree-sitter-rust/blob/master/grammar.js
    string_literal: ($) =>
      // token(
      seq(
        // TODO: binary and/or C strings?:  alias(/[bc]?"/, '"'),
        // /[^\"\\\n]/,
        // $._quote_escape,
        // $._ascii_escape,
        // $._unicode_escape,
        // $._string_continuation
        $._string_sigil,
        repeat(choice($.escape_sequence, /[^\"\\\n]/)),
        $._string_sigil
      ),

    // Hidden quote mark rule to prevent the dot showing as an explicit child of string_literal
    _string_sigil: (_) => SYMBOLS.DOUBLE_QUOTE,

    escape_sequence: (_) =>
      token.immediate(
        seq(
          "\\",
          choice(
            /[^xu]/,
            /u[0-9a-fA-F]{1,6}/,
            // /u{[0-9a-fA-F]+}/,
            /x[0-9a-fA-F]{2}/
          )
        )
      ),

    string_content: (_) => choice(/[^\"\\\n]/),
    _string_continuation: ($) => /\\\n/,

    // Hidden versions of the esacapes:
    _quote_escape: ($) => choice("\\'", '\\"'),
    _ascii_escape: ($) =>
      choice(
        seq("\\x", /[0-7]/, /[0-9a-fA-f]/),
        "\\n",
        "\\r",
        "\\t",
        "\\\\",
        "\\0"
      ),
    _unicode_escape: ($) => /\\u([0-9a-fA-F]|_*){1,6}/,

    // Boolean literals
    boolean_literal: ($) => choice($._boolean_true, $._boolean_false),

    // Prevent an explicit "true"/"false" showing as a child of boolean_literal
    _boolean_true: (_) => "true",
    _boolean_false: (_) => "false",

    // Float literals
    // Hidden version of decimal_literal for use in parsing floats
    _decimal_literal: ($) => /[0-9]([0-9]|_)*/,

    float_exponent: ($) => /[eE][+-]?([0-9]|_)*[0-9]([0-9]|_)*/,
    float_literal: ($) =>
      choice(
        seq($._decimal_literal, $._float_decimal_point),
        seq($._decimal_literal, $._float_decimal_point, $._decimal_literal),
        seq(
          $._decimal_literal,
          $._float_decimal_point,
          optional($._decimal_literal),
          field("exponent", $.float_exponent)
        )
      ),

    // Hidden "." rule to prevent the dot showing as an explicit child of float_literal
    _float_decimal_point: (_) => SYMBOLS.DOT,
  },
});
