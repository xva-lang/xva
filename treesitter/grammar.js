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

const SUFFIX_NO_E = /[a-df-zA-DF-Z_][a-zA-Z0-9_]*/;

module.exports = grammar({
  name: "xva",

  // https://github.com/tree-sitter/tree-sitter/issues/328
  // The "word" rule being set to an undefined rule causes a weird error when running `tree-sitter generate`
  // word: ($) => $.identifier,

  rules: {
    source_file: ($) => repeat($._item),

    _item: ($) => choice($.expression),

    expression: ($) => choice($._primary_expression),

    /************** Primary expressions *************/
    _primary_expression: ($) => choice($.literal),

    literal: ($) =>
      choice(
        $.integer_literal,
        $.character_literal,
        $.string_literal,
        $.boolean_literal
      ),

    // TODO: byte literals, byte string literals, raw string literals

    /*********** Literals ************/
    // Integer literals, borrowed from Rust: https://doc.rust-lang.org/reference/tokens.html#integer-literals
    integer_literal: ($) =>
      seq(
        choice(
          $.decimal_literal,
          $.binary_literal,
          $.octal_literal,
          $.hex_literal
        ),
        field("suffix", optional($.suffix_no_e))
      ),
    suffix_no_e: ($) => SUFFIX_NO_E,

    decimal_literal: ($) => /[0-9]([0-9]|_)*/,
    binary_literal: ($) => /0b([0-1]|_)*[0-1]([0-1]|_)*/,
    octal_literal: ($) => /0o([0-7]|_)*[0-7]([0-7]|_)*/,
    hex_literal: ($) => /0x([0-9a-fA-F]|_)*[0-9a-fA-F]([0-9a-fA-F]|_)*/,

    // Character literals, borrowed from Rust: https://doc.rust-lang.org/reference/tokens.html#character-literals
    character_literal: ($) =>
      seq(
        SYMBOLS.SINGLE_QUOTE,
        choice(
          /[^\'\\(\\n)(\\r)(\\t)]/,
          $.quote_escape,
          $.ascii_escape,
          $.unicode_escape
        ),
        SYMBOLS.SINGLE_QUOTE
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

    // String literals, borrowed from Rust: https://doc.rust-lang.org/reference/tokens.html#string-literals
    string_literal: ($) =>
      seq(
        SYMBOLS.DOUBLE_QUOTE,
        repeat(
          choice(
            /[^\"\\\n]/,
            $._quote_escape,
            $._ascii_escape,
            $._unicode_escape,
            $._string_continuation
          )
        ),
        SYMBOLS.DOUBLE_QUOTE
      ),

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
    _unicode_escape: ($) => /\\u\{([0-9a-fA-F]|_*){1,6}\}/,

    _string_continuation: ($) => /\\\n/,

    boolean_literal: ($) => choice("true", "false"),
    /*********** Literals ************/
  },
});
