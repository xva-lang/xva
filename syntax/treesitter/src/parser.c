#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 34
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 77
#define ALIAS_COUNT 0
#define TOKEN_COUNT 53
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 1
#define MAX_ALIAS_SEQUENCE_LENGTH 3
#define PRODUCTION_ID_COUNT 2

enum {
  sym_identifier = 1,
  anon_sym_LBRACE = 2,
  anon_sym_RBRACE = 3,
  anon_sym_COLON = 4,
  anon_sym_LPAREN = 5,
  anon_sym_COMMA = 6,
  anon_sym_RPAREN = 7,
  anon_sym_def = 8,
  sym__fat_arrow = 9,
  sym_mutable_modifier = 10,
  sym__equals_symbol = 11,
  sym__let_keyword = 12,
  anon_sym_byte = 13,
  anon_sym_ushort = 14,
  anon_sym_uint = 15,
  anon_sym_ulong = 16,
  anon_sym_sbyte = 17,
  anon_sym_short = 18,
  anon_sym_int = 19,
  anon_sym_long = 20,
  anon_sym_float = 21,
  anon_sym_double = 22,
  anon_sym_boolean = 23,
  anon_sym_char = 24,
  anon_sym_PLUS_PLUS = 25,
  anon_sym_DASH_DASH = 26,
  anon_sym_DASH = 27,
  anon_sym_PLUS = 28,
  anon_sym_STAR = 29,
  anon_sym_SLASH = 30,
  anon_sym_PERCENT = 31,
  sym_suffix_no_e = 32,
  sym_decimal_literal = 33,
  sym_binary_literal = 34,
  sym_octal_literal = 35,
  sym_hex_literal = 36,
  anon_sym_SQUOTE = 37,
  aux_sym_character_literal_token1 = 38,
  anon_sym_BSLASH_SQUOTE = 39,
  anon_sym_BSLASH_DQUOTE = 40,
  anon_sym_BSLASHx = 41,
  aux_sym_ascii_escape_token1 = 42,
  aux_sym_ascii_escape_token2 = 43,
  anon_sym_BSLASHn = 44,
  anon_sym_BSLASHr = 45,
  anon_sym_BSLASHt = 46,
  anon_sym_BSLASH_BSLASH = 47,
  anon_sym_BSLASH0 = 48,
  aux_sym_unicode_escape_token1 = 49,
  anon_sym_DQUOTE = 50,
  aux_sym_string_literal_token1 = 51,
  sym__string_continuation = 52,
  sym_source_file = 53,
  sym__statement = 54,
  sym__expression = 55,
  sym__primary_expression = 56,
  sym__literal = 57,
  sym__unary_expression = 58,
  sym_prefix_expression = 59,
  sym_prefix_unary_operator = 60,
  sym__binary_expression = 61,
  sym_multiplicative_expression = 62,
  sym_additive_expression = 63,
  sym_multiplicative_operator = 64,
  sym_additive_operator = 65,
  sym_integer_literal = 66,
  sym_character_literal = 67,
  sym_quote_escape = 68,
  sym_ascii_escape = 69,
  sym_unicode_escape = 70,
  sym_string_literal = 71,
  sym__quote_escape = 72,
  sym__ascii_escape = 73,
  sym__unicode_escape = 74,
  aux_sym_source_file_repeat1 = 75,
  aux_sym_string_literal_repeat1 = 76,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_identifier] = "identifier",
  [anon_sym_LBRACE] = "{",
  [anon_sym_RBRACE] = "}",
  [anon_sym_COLON] = ":",
  [anon_sym_LPAREN] = "(",
  [anon_sym_COMMA] = ",",
  [anon_sym_RPAREN] = ")",
  [anon_sym_def] = "def",
  [sym__fat_arrow] = "_fat_arrow",
  [sym_mutable_modifier] = "mutable_modifier",
  [sym__equals_symbol] = "_equals_symbol",
  [sym__let_keyword] = "_let_keyword",
  [anon_sym_byte] = "byte",
  [anon_sym_ushort] = "ushort",
  [anon_sym_uint] = "uint",
  [anon_sym_ulong] = "ulong",
  [anon_sym_sbyte] = "sbyte",
  [anon_sym_short] = "short",
  [anon_sym_int] = "int",
  [anon_sym_long] = "long",
  [anon_sym_float] = "float",
  [anon_sym_double] = "double",
  [anon_sym_boolean] = "boolean",
  [anon_sym_char] = "char",
  [anon_sym_PLUS_PLUS] = "++",
  [anon_sym_DASH_DASH] = "--",
  [anon_sym_DASH] = "-",
  [anon_sym_PLUS] = "+",
  [anon_sym_STAR] = "*",
  [anon_sym_SLASH] = "/",
  [anon_sym_PERCENT] = "%",
  [sym_suffix_no_e] = "suffix_no_e",
  [sym_decimal_literal] = "decimal_literal",
  [sym_binary_literal] = "binary_literal",
  [sym_octal_literal] = "octal_literal",
  [sym_hex_literal] = "hex_literal",
  [anon_sym_SQUOTE] = "'",
  [aux_sym_character_literal_token1] = "character_literal_token1",
  [anon_sym_BSLASH_SQUOTE] = "\\'",
  [anon_sym_BSLASH_DQUOTE] = "\\\"",
  [anon_sym_BSLASHx] = "\\x",
  [aux_sym_ascii_escape_token1] = "ascii_escape_token1",
  [aux_sym_ascii_escape_token2] = "ascii_escape_token2",
  [anon_sym_BSLASHn] = "\\n",
  [anon_sym_BSLASHr] = "\\r",
  [anon_sym_BSLASHt] = "\\t",
  [anon_sym_BSLASH_BSLASH] = "\\\\",
  [anon_sym_BSLASH0] = "\\0",
  [aux_sym_unicode_escape_token1] = "unicode_escape_token1",
  [anon_sym_DQUOTE] = "\"",
  [aux_sym_string_literal_token1] = "string_literal_token1",
  [sym__string_continuation] = "_string_continuation",
  [sym_source_file] = "source_file",
  [sym__statement] = "_statement",
  [sym__expression] = "_expression",
  [sym__primary_expression] = "_primary_expression",
  [sym__literal] = "_literal",
  [sym__unary_expression] = "_unary_expression",
  [sym_prefix_expression] = "prefix_expression",
  [sym_prefix_unary_operator] = "prefix_unary_operator",
  [sym__binary_expression] = "_binary_expression",
  [sym_multiplicative_expression] = "multiplicative_expression",
  [sym_additive_expression] = "additive_expression",
  [sym_multiplicative_operator] = "multiplicative_operator",
  [sym_additive_operator] = "additive_operator",
  [sym_integer_literal] = "integer_literal",
  [sym_character_literal] = "character_literal",
  [sym_quote_escape] = "quote_escape",
  [sym_ascii_escape] = "ascii_escape",
  [sym_unicode_escape] = "unicode_escape",
  [sym_string_literal] = "string_literal",
  [sym__quote_escape] = "_quote_escape",
  [sym__ascii_escape] = "_ascii_escape",
  [sym__unicode_escape] = "_unicode_escape",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
  [aux_sym_string_literal_repeat1] = "string_literal_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym_identifier] = sym_identifier,
  [anon_sym_LBRACE] = anon_sym_LBRACE,
  [anon_sym_RBRACE] = anon_sym_RBRACE,
  [anon_sym_COLON] = anon_sym_COLON,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [anon_sym_def] = anon_sym_def,
  [sym__fat_arrow] = sym__fat_arrow,
  [sym_mutable_modifier] = sym_mutable_modifier,
  [sym__equals_symbol] = sym__equals_symbol,
  [sym__let_keyword] = sym__let_keyword,
  [anon_sym_byte] = anon_sym_byte,
  [anon_sym_ushort] = anon_sym_ushort,
  [anon_sym_uint] = anon_sym_uint,
  [anon_sym_ulong] = anon_sym_ulong,
  [anon_sym_sbyte] = anon_sym_sbyte,
  [anon_sym_short] = anon_sym_short,
  [anon_sym_int] = anon_sym_int,
  [anon_sym_long] = anon_sym_long,
  [anon_sym_float] = anon_sym_float,
  [anon_sym_double] = anon_sym_double,
  [anon_sym_boolean] = anon_sym_boolean,
  [anon_sym_char] = anon_sym_char,
  [anon_sym_PLUS_PLUS] = anon_sym_PLUS_PLUS,
  [anon_sym_DASH_DASH] = anon_sym_DASH_DASH,
  [anon_sym_DASH] = anon_sym_DASH,
  [anon_sym_PLUS] = anon_sym_PLUS,
  [anon_sym_STAR] = anon_sym_STAR,
  [anon_sym_SLASH] = anon_sym_SLASH,
  [anon_sym_PERCENT] = anon_sym_PERCENT,
  [sym_suffix_no_e] = sym_suffix_no_e,
  [sym_decimal_literal] = sym_decimal_literal,
  [sym_binary_literal] = sym_binary_literal,
  [sym_octal_literal] = sym_octal_literal,
  [sym_hex_literal] = sym_hex_literal,
  [anon_sym_SQUOTE] = anon_sym_SQUOTE,
  [aux_sym_character_literal_token1] = aux_sym_character_literal_token1,
  [anon_sym_BSLASH_SQUOTE] = anon_sym_BSLASH_SQUOTE,
  [anon_sym_BSLASH_DQUOTE] = anon_sym_BSLASH_DQUOTE,
  [anon_sym_BSLASHx] = anon_sym_BSLASHx,
  [aux_sym_ascii_escape_token1] = aux_sym_ascii_escape_token1,
  [aux_sym_ascii_escape_token2] = aux_sym_ascii_escape_token2,
  [anon_sym_BSLASHn] = anon_sym_BSLASHn,
  [anon_sym_BSLASHr] = anon_sym_BSLASHr,
  [anon_sym_BSLASHt] = anon_sym_BSLASHt,
  [anon_sym_BSLASH_BSLASH] = anon_sym_BSLASH_BSLASH,
  [anon_sym_BSLASH0] = anon_sym_BSLASH0,
  [aux_sym_unicode_escape_token1] = aux_sym_unicode_escape_token1,
  [anon_sym_DQUOTE] = anon_sym_DQUOTE,
  [aux_sym_string_literal_token1] = aux_sym_string_literal_token1,
  [sym__string_continuation] = sym__string_continuation,
  [sym_source_file] = sym_source_file,
  [sym__statement] = sym__statement,
  [sym__expression] = sym__expression,
  [sym__primary_expression] = sym__primary_expression,
  [sym__literal] = sym__literal,
  [sym__unary_expression] = sym__unary_expression,
  [sym_prefix_expression] = sym_prefix_expression,
  [sym_prefix_unary_operator] = sym_prefix_unary_operator,
  [sym__binary_expression] = sym__binary_expression,
  [sym_multiplicative_expression] = sym_multiplicative_expression,
  [sym_additive_expression] = sym_additive_expression,
  [sym_multiplicative_operator] = sym_multiplicative_operator,
  [sym_additive_operator] = sym_additive_operator,
  [sym_integer_literal] = sym_integer_literal,
  [sym_character_literal] = sym_character_literal,
  [sym_quote_escape] = sym_quote_escape,
  [sym_ascii_escape] = sym_ascii_escape,
  [sym_unicode_escape] = sym_unicode_escape,
  [sym_string_literal] = sym_string_literal,
  [sym__quote_escape] = sym__quote_escape,
  [sym__ascii_escape] = sym__ascii_escape,
  [sym__unicode_escape] = sym__unicode_escape,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
  [aux_sym_string_literal_repeat1] = aux_sym_string_literal_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [sym_identifier] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_LBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COLON] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COMMA] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_def] = {
    .visible = true,
    .named = false,
  },
  [sym__fat_arrow] = {
    .visible = false,
    .named = true,
  },
  [sym_mutable_modifier] = {
    .visible = true,
    .named = true,
  },
  [sym__equals_symbol] = {
    .visible = false,
    .named = true,
  },
  [sym__let_keyword] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_byte] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_ushort] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_uint] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_ulong] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_sbyte] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_short] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_int] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_long] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_float] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_double] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_boolean] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_char] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PLUS_PLUS] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DASH_DASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PLUS] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_STAR] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SLASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PERCENT] = {
    .visible = true,
    .named = false,
  },
  [sym_suffix_no_e] = {
    .visible = true,
    .named = true,
  },
  [sym_decimal_literal] = {
    .visible = true,
    .named = true,
  },
  [sym_binary_literal] = {
    .visible = true,
    .named = true,
  },
  [sym_octal_literal] = {
    .visible = true,
    .named = true,
  },
  [sym_hex_literal] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_SQUOTE] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_character_literal_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_BSLASH_SQUOTE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_BSLASH_DQUOTE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_BSLASHx] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_ascii_escape_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_ascii_escape_token2] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_BSLASHn] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_BSLASHr] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_BSLASHt] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_BSLASH_BSLASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_BSLASH0] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_unicode_escape_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_DQUOTE] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_string_literal_token1] = {
    .visible = false,
    .named = false,
  },
  [sym__string_continuation] = {
    .visible = false,
    .named = true,
  },
  [sym_source_file] = {
    .visible = true,
    .named = true,
  },
  [sym__statement] = {
    .visible = false,
    .named = true,
  },
  [sym__expression] = {
    .visible = false,
    .named = true,
  },
  [sym__primary_expression] = {
    .visible = false,
    .named = true,
  },
  [sym__literal] = {
    .visible = false,
    .named = true,
  },
  [sym__unary_expression] = {
    .visible = false,
    .named = true,
  },
  [sym_prefix_expression] = {
    .visible = true,
    .named = true,
  },
  [sym_prefix_unary_operator] = {
    .visible = true,
    .named = true,
  },
  [sym__binary_expression] = {
    .visible = false,
    .named = true,
  },
  [sym_multiplicative_expression] = {
    .visible = true,
    .named = true,
  },
  [sym_additive_expression] = {
    .visible = true,
    .named = true,
  },
  [sym_multiplicative_operator] = {
    .visible = true,
    .named = true,
  },
  [sym_additive_operator] = {
    .visible = true,
    .named = true,
  },
  [sym_integer_literal] = {
    .visible = true,
    .named = true,
  },
  [sym_character_literal] = {
    .visible = true,
    .named = true,
  },
  [sym_quote_escape] = {
    .visible = true,
    .named = true,
  },
  [sym_ascii_escape] = {
    .visible = true,
    .named = true,
  },
  [sym_unicode_escape] = {
    .visible = true,
    .named = true,
  },
  [sym_string_literal] = {
    .visible = true,
    .named = true,
  },
  [sym__quote_escape] = {
    .visible = false,
    .named = true,
  },
  [sym__ascii_escape] = {
    .visible = false,
    .named = true,
  },
  [sym__unicode_escape] = {
    .visible = false,
    .named = true,
  },
  [aux_sym_source_file_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_string_literal_repeat1] = {
    .visible = false,
    .named = false,
  },
};

enum {
  field_suffix = 1,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_suffix] = "suffix",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 1},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_suffix, 1},
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 3,
  [4] = 4,
  [5] = 5,
  [6] = 6,
  [7] = 7,
  [8] = 8,
  [9] = 9,
  [10] = 10,
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 14,
  [15] = 15,
  [16] = 16,
  [17] = 17,
  [18] = 18,
  [19] = 19,
  [20] = 20,
  [21] = 21,
  [22] = 22,
  [23] = 23,
  [24] = 24,
  [25] = 25,
  [26] = 26,
  [27] = 27,
  [28] = 28,
  [29] = 29,
  [30] = 30,
  [31] = 31,
  [32] = 32,
  [33] = 33,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(27);
      if (lookahead == '"') ADVANCE(63);
      if (lookahead == '%') ADVANCE(42);
      if (lookahead == '\'') ADVANCE(48);
      if (lookahead == '(') ADVANCE(31);
      if (lookahead == ')') ADVANCE(33);
      if (lookahead == '*') ADVANCE(40);
      if (lookahead == '+') ADVANCE(39);
      if (lookahead == ',') ADVANCE(32);
      if (lookahead == '-') ADVANCE(38);
      if (lookahead == '/') ADVANCE(41);
      if (lookahead == '0') ADVANCE(54);
      if (lookahead == ':') ADVANCE(30);
      if (lookahead == '=') ADVANCE(35);
      if (lookahead == '{') ADVANCE(28);
      if (lookahead == '}') ADVANCE(29);
      if (lookahead == '8' ||
          lookahead == '9') ADVANCE(44);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      if (('[' <= lookahead && lookahead <= '^') ||
          lookahead == '`') ADVANCE(55);
      if (('1' <= lookahead && lookahead <= '7')) ADVANCE(44);
      if (('g' <= lookahead && lookahead <= 'z')) ADVANCE(67);
      if (('A' <= lookahead && lookahead <= 'f')) ADVANCE(56);
      END_STATE();
    case 1:
      if (lookahead == '\n') SKIP(1)
      if (lookahead == '"') ADVANCE(63);
      if (lookahead == '\\') ADVANCE(2);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(65);
      if (lookahead != 0) ADVANCE(64);
      END_STATE();
    case 2:
      if (lookahead == '\n') ADVANCE(66);
      if (lookahead == '"') ADVANCE(52);
      if (lookahead == '\'') ADVANCE(51);
      if (lookahead == '0') ADVANCE(61);
      if (lookahead == '\\') ADVANCE(60);
      if (lookahead == 'n') ADVANCE(57);
      if (lookahead == 'r') ADVANCE(58);
      if (lookahead == 't') ADVANCE(59);
      if (lookahead == 'u') ADVANCE(21);
      if (lookahead == 'x') ADVANCE(53);
      END_STATE();
    case 3:
      if (lookahead == '"') ADVANCE(52);
      if (lookahead == '\'') ADVANCE(51);
      if (lookahead == '0') ADVANCE(61);
      if (lookahead == '\\') ADVANCE(60);
      if (lookahead == 'n') ADVANCE(57);
      if (lookahead == 'r') ADVANCE(58);
      if (lookahead == 't') ADVANCE(59);
      if (lookahead == 'u') ADVANCE(21);
      if (lookahead == 'x') ADVANCE(53);
      END_STATE();
    case 4:
      if (lookahead == '\\') ADVANCE(3);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(50);
      if (lookahead != 0 &&
          (lookahead < '\'' || ')' < lookahead) &&
          lookahead != 'n' &&
          lookahead != 'r' &&
          lookahead != 't') ADVANCE(49);
      END_STATE();
    case 5:
      if (lookahead == '_') ADVANCE(5);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(45);
      END_STATE();
    case 6:
      if (lookahead == '_') ADVANCE(6);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(46);
      END_STATE();
    case 7:
      if (lookahead == '_') ADVANCE(7);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(47);
      END_STATE();
    case 8:
      if (lookahead == '_') ADVANCE(8);
      if (lookahead == '}') ADVANCE(62);
      END_STATE();
    case 9:
      if (lookahead == '_') ADVANCE(8);
      if (lookahead == '}') ADVANCE(62);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(22);
      END_STATE();
    case 10:
      if (lookahead == '_') ADVANCE(10);
      if (lookahead == '}') ADVANCE(62);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(22);
      END_STATE();
    case 11:
      if (lookahead == '_') ADVANCE(10);
      if (lookahead == '}') ADVANCE(62);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(9);
      END_STATE();
    case 12:
      if (lookahead == '_') ADVANCE(12);
      if (lookahead == '}') ADVANCE(62);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(9);
      END_STATE();
    case 13:
      if (lookahead == '_') ADVANCE(12);
      if (lookahead == '}') ADVANCE(62);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(11);
      END_STATE();
    case 14:
      if (lookahead == '_') ADVANCE(14);
      if (lookahead == '}') ADVANCE(62);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(11);
      END_STATE();
    case 15:
      if (lookahead == '_') ADVANCE(14);
      if (lookahead == '}') ADVANCE(62);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(13);
      END_STATE();
    case 16:
      if (lookahead == '_') ADVANCE(16);
      if (lookahead == '}') ADVANCE(62);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(13);
      END_STATE();
    case 17:
      if (lookahead == '_') ADVANCE(16);
      if (lookahead == '}') ADVANCE(62);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(15);
      END_STATE();
    case 18:
      if (lookahead == '_') ADVANCE(18);
      if (lookahead == '}') ADVANCE(62);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(15);
      END_STATE();
    case 19:
      if (lookahead == '_') ADVANCE(18);
      if (lookahead == '}') ADVANCE(62);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(17);
      END_STATE();
    case 20:
      if (lookahead == 'b') ADVANCE(5);
      if (lookahead == 'o') ADVANCE(6);
      if (lookahead == 'x') ADVANCE(7);
      END_STATE();
    case 21:
      if (lookahead == '{') ADVANCE(19);
      END_STATE();
    case 22:
      if (lookahead == '}') ADVANCE(62);
      END_STATE();
    case 23:
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(23)
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'f')) ADVANCE(55);
      END_STATE();
    case 24:
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(24)
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(54);
      END_STATE();
    case 25:
      if (eof) ADVANCE(27);
      if (lookahead == '"') ADVANCE(63);
      if (lookahead == '%') ADVANCE(42);
      if (lookahead == '\'') ADVANCE(48);
      if (lookahead == '*') ADVANCE(40);
      if (lookahead == '+') ADVANCE(39);
      if (lookahead == '-') ADVANCE(38);
      if (lookahead == '/') ADVANCE(41);
      if (lookahead == '0') ADVANCE(20);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(67);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(25)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(44);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(43);
      END_STATE();
    case 26:
      if (eof) ADVANCE(27);
      if (lookahead == '"') ADVANCE(63);
      if (lookahead == '%') ADVANCE(42);
      if (lookahead == '\'') ADVANCE(48);
      if (lookahead == '*') ADVANCE(40);
      if (lookahead == '+') ADVANCE(39);
      if (lookahead == '-') ADVANCE(38);
      if (lookahead == '/') ADVANCE(41);
      if (lookahead == '0') ADVANCE(20);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(26)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(44);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(67);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(sym__fat_arrow);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(sym__equals_symbol);
      if (lookahead == '>') ADVANCE(34);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(anon_sym_PLUS_PLUS);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(anon_sym_DASH_DASH);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(anon_sym_DASH);
      if (lookahead == '-') ADVANCE(37);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(anon_sym_PLUS);
      if (lookahead == '+') ADVANCE(36);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(anon_sym_STAR);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(anon_sym_SLASH);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(anon_sym_PERCENT);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(sym_suffix_no_e);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(43);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(sym_decimal_literal);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(44);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(sym_binary_literal);
      if (lookahead == '_') ADVANCE(45);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(45);
      END_STATE();
    case 46:
      ACCEPT_TOKEN(sym_octal_literal);
      if (lookahead == '_') ADVANCE(46);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(46);
      END_STATE();
    case 47:
      ACCEPT_TOKEN(sym_hex_literal);
      if (lookahead == '_') ADVANCE(47);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(47);
      END_STATE();
    case 48:
      ACCEPT_TOKEN(anon_sym_SQUOTE);
      END_STATE();
    case 49:
      ACCEPT_TOKEN(aux_sym_character_literal_token1);
      END_STATE();
    case 50:
      ACCEPT_TOKEN(aux_sym_character_literal_token1);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(50);
      if (lookahead != 0 &&
          (lookahead < '\'' || ')' < lookahead) &&
          lookahead != '\\' &&
          lookahead != 'n' &&
          lookahead != 'r' &&
          lookahead != 't') ADVANCE(49);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(anon_sym_BSLASH_SQUOTE);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(anon_sym_BSLASH_DQUOTE);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(anon_sym_BSLASHx);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(aux_sym_ascii_escape_token1);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(aux_sym_ascii_escape_token2);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(aux_sym_ascii_escape_token2);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(67);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(anon_sym_BSLASHn);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(anon_sym_BSLASHr);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(anon_sym_BSLASHt);
      END_STATE();
    case 60:
      ACCEPT_TOKEN(anon_sym_BSLASH_BSLASH);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(anon_sym_BSLASH0);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(aux_sym_unicode_escape_token1);
      END_STATE();
    case 63:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(aux_sym_string_literal_token1);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(aux_sym_string_literal_token1);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(65);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '"' &&
          lookahead != '\\') ADVANCE(64);
      END_STATE();
    case 66:
      ACCEPT_TOKEN(sym__string_continuation);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(sym_identifier);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(67);
      END_STATE();
    default:
      return false;
  }
}

static bool ts_lex_keywords(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (lookahead == 'b') ADVANCE(1);
      if (lookahead == 'c') ADVANCE(2);
      if (lookahead == 'd') ADVANCE(3);
      if (lookahead == 'f') ADVANCE(4);
      if (lookahead == 'i') ADVANCE(5);
      if (lookahead == 'l') ADVANCE(6);
      if (lookahead == 'm') ADVANCE(7);
      if (lookahead == 's') ADVANCE(8);
      if (lookahead == 'u') ADVANCE(9);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      END_STATE();
    case 1:
      if (lookahead == 'o') ADVANCE(10);
      if (lookahead == 'y') ADVANCE(11);
      END_STATE();
    case 2:
      if (lookahead == 'h') ADVANCE(12);
      END_STATE();
    case 3:
      if (lookahead == 'e') ADVANCE(13);
      if (lookahead == 'o') ADVANCE(14);
      END_STATE();
    case 4:
      if (lookahead == 'l') ADVANCE(15);
      END_STATE();
    case 5:
      if (lookahead == 'n') ADVANCE(16);
      END_STATE();
    case 6:
      if (lookahead == 'e') ADVANCE(17);
      if (lookahead == 'o') ADVANCE(18);
      END_STATE();
    case 7:
      if (lookahead == 'u') ADVANCE(19);
      END_STATE();
    case 8:
      if (lookahead == 'b') ADVANCE(20);
      if (lookahead == 'h') ADVANCE(21);
      END_STATE();
    case 9:
      if (lookahead == 'i') ADVANCE(22);
      if (lookahead == 'l') ADVANCE(23);
      if (lookahead == 's') ADVANCE(24);
      END_STATE();
    case 10:
      if (lookahead == 'o') ADVANCE(25);
      END_STATE();
    case 11:
      if (lookahead == 't') ADVANCE(26);
      END_STATE();
    case 12:
      if (lookahead == 'a') ADVANCE(27);
      END_STATE();
    case 13:
      if (lookahead == 'f') ADVANCE(28);
      END_STATE();
    case 14:
      if (lookahead == 'u') ADVANCE(29);
      END_STATE();
    case 15:
      if (lookahead == 'o') ADVANCE(30);
      END_STATE();
    case 16:
      if (lookahead == 't') ADVANCE(31);
      END_STATE();
    case 17:
      if (lookahead == 't') ADVANCE(32);
      END_STATE();
    case 18:
      if (lookahead == 'n') ADVANCE(33);
      END_STATE();
    case 19:
      if (lookahead == 't') ADVANCE(34);
      END_STATE();
    case 20:
      if (lookahead == 'y') ADVANCE(35);
      END_STATE();
    case 21:
      if (lookahead == 'o') ADVANCE(36);
      END_STATE();
    case 22:
      if (lookahead == 'n') ADVANCE(37);
      END_STATE();
    case 23:
      if (lookahead == 'o') ADVANCE(38);
      END_STATE();
    case 24:
      if (lookahead == 'h') ADVANCE(39);
      END_STATE();
    case 25:
      if (lookahead == 'l') ADVANCE(40);
      END_STATE();
    case 26:
      if (lookahead == 'e') ADVANCE(41);
      END_STATE();
    case 27:
      if (lookahead == 'r') ADVANCE(42);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(anon_sym_def);
      END_STATE();
    case 29:
      if (lookahead == 'b') ADVANCE(43);
      END_STATE();
    case 30:
      if (lookahead == 'a') ADVANCE(44);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(anon_sym_int);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(sym__let_keyword);
      END_STATE();
    case 33:
      if (lookahead == 'g') ADVANCE(45);
      END_STATE();
    case 34:
      if (lookahead == 'a') ADVANCE(46);
      END_STATE();
    case 35:
      if (lookahead == 't') ADVANCE(47);
      END_STATE();
    case 36:
      if (lookahead == 'r') ADVANCE(48);
      END_STATE();
    case 37:
      if (lookahead == 't') ADVANCE(49);
      END_STATE();
    case 38:
      if (lookahead == 'n') ADVANCE(50);
      END_STATE();
    case 39:
      if (lookahead == 'o') ADVANCE(51);
      END_STATE();
    case 40:
      if (lookahead == 'e') ADVANCE(52);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(anon_sym_byte);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(anon_sym_char);
      END_STATE();
    case 43:
      if (lookahead == 'l') ADVANCE(53);
      END_STATE();
    case 44:
      if (lookahead == 't') ADVANCE(54);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(anon_sym_long);
      END_STATE();
    case 46:
      if (lookahead == 'b') ADVANCE(55);
      END_STATE();
    case 47:
      if (lookahead == 'e') ADVANCE(56);
      END_STATE();
    case 48:
      if (lookahead == 't') ADVANCE(57);
      END_STATE();
    case 49:
      ACCEPT_TOKEN(anon_sym_uint);
      END_STATE();
    case 50:
      if (lookahead == 'g') ADVANCE(58);
      END_STATE();
    case 51:
      if (lookahead == 'r') ADVANCE(59);
      END_STATE();
    case 52:
      if (lookahead == 'a') ADVANCE(60);
      END_STATE();
    case 53:
      if (lookahead == 'e') ADVANCE(61);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(anon_sym_float);
      END_STATE();
    case 55:
      if (lookahead == 'l') ADVANCE(62);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(anon_sym_sbyte);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(anon_sym_short);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(anon_sym_ulong);
      END_STATE();
    case 59:
      if (lookahead == 't') ADVANCE(63);
      END_STATE();
    case 60:
      if (lookahead == 'n') ADVANCE(64);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(anon_sym_double);
      END_STATE();
    case 62:
      if (lookahead == 'e') ADVANCE(65);
      END_STATE();
    case 63:
      ACCEPT_TOKEN(anon_sym_ushort);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(anon_sym_boolean);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(sym_mutable_modifier);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 26},
  [2] = {.lex_state = 26},
  [3] = {.lex_state = 26},
  [4] = {.lex_state = 26},
  [5] = {.lex_state = 26},
  [6] = {.lex_state = 26},
  [7] = {.lex_state = 26},
  [8] = {.lex_state = 26},
  [9] = {.lex_state = 26},
  [10] = {.lex_state = 26},
  [11] = {.lex_state = 1},
  [12] = {.lex_state = 25},
  [13] = {.lex_state = 1},
  [14] = {.lex_state = 1},
  [15] = {.lex_state = 26},
  [16] = {.lex_state = 26},
  [17] = {.lex_state = 26},
  [18] = {.lex_state = 26},
  [19] = {.lex_state = 4},
  [20] = {.lex_state = 1},
  [21] = {.lex_state = 26},
  [22] = {.lex_state = 26},
  [23] = {.lex_state = 26},
  [24] = {.lex_state = 0},
  [25] = {.lex_state = 0},
  [26] = {.lex_state = 23},
  [27] = {.lex_state = 23},
  [28] = {.lex_state = 24},
  [29] = {.lex_state = 0},
  [30] = {.lex_state = 0},
  [31] = {.lex_state = 24},
  [32] = {.lex_state = 0},
  [33] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym_identifier] = ACTIONS(1),
    [anon_sym_LBRACE] = ACTIONS(1),
    [anon_sym_RBRACE] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [anon_sym_def] = ACTIONS(1),
    [sym__fat_arrow] = ACTIONS(1),
    [sym_mutable_modifier] = ACTIONS(1),
    [sym__equals_symbol] = ACTIONS(1),
    [sym__let_keyword] = ACTIONS(1),
    [anon_sym_byte] = ACTIONS(1),
    [anon_sym_ushort] = ACTIONS(1),
    [anon_sym_uint] = ACTIONS(1),
    [anon_sym_ulong] = ACTIONS(1),
    [anon_sym_sbyte] = ACTIONS(1),
    [anon_sym_short] = ACTIONS(1),
    [anon_sym_int] = ACTIONS(1),
    [anon_sym_long] = ACTIONS(1),
    [anon_sym_float] = ACTIONS(1),
    [anon_sym_double] = ACTIONS(1),
    [anon_sym_boolean] = ACTIONS(1),
    [anon_sym_char] = ACTIONS(1),
    [anon_sym_PLUS_PLUS] = ACTIONS(1),
    [anon_sym_DASH_DASH] = ACTIONS(1),
    [anon_sym_DASH] = ACTIONS(1),
    [anon_sym_PLUS] = ACTIONS(1),
    [anon_sym_STAR] = ACTIONS(1),
    [anon_sym_SLASH] = ACTIONS(1),
    [anon_sym_PERCENT] = ACTIONS(1),
    [sym_decimal_literal] = ACTIONS(1),
    [anon_sym_SQUOTE] = ACTIONS(1),
    [aux_sym_ascii_escape_token1] = ACTIONS(1),
    [aux_sym_ascii_escape_token2] = ACTIONS(1),
    [anon_sym_DQUOTE] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(25),
    [sym__statement] = STATE(3),
    [sym__expression] = STATE(7),
    [sym__primary_expression] = STATE(7),
    [sym__literal] = STATE(7),
    [sym__unary_expression] = STATE(7),
    [sym_prefix_expression] = STATE(7),
    [sym_prefix_unary_operator] = STATE(4),
    [sym__binary_expression] = STATE(7),
    [sym_multiplicative_expression] = STATE(7),
    [sym_additive_expression] = STATE(7),
    [sym_integer_literal] = STATE(7),
    [sym_character_literal] = STATE(7),
    [sym_string_literal] = STATE(7),
    [aux_sym_source_file_repeat1] = STATE(3),
    [ts_builtin_sym_end] = ACTIONS(3),
    [sym_identifier] = ACTIONS(5),
    [anon_sym_PLUS_PLUS] = ACTIONS(7),
    [anon_sym_DASH_DASH] = ACTIONS(7),
    [anon_sym_DASH] = ACTIONS(9),
    [anon_sym_PLUS] = ACTIONS(9),
    [sym_decimal_literal] = ACTIONS(11),
    [sym_binary_literal] = ACTIONS(11),
    [sym_octal_literal] = ACTIONS(11),
    [sym_hex_literal] = ACTIONS(11),
    [anon_sym_SQUOTE] = ACTIONS(13),
    [anon_sym_DQUOTE] = ACTIONS(15),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 10,
    ACTIONS(17), 1,
      ts_builtin_sym_end,
    ACTIONS(19), 1,
      sym_identifier,
    ACTIONS(31), 1,
      anon_sym_SQUOTE,
    ACTIONS(34), 1,
      anon_sym_DQUOTE,
    STATE(4), 1,
      sym_prefix_unary_operator,
    ACTIONS(22), 2,
      anon_sym_PLUS_PLUS,
      anon_sym_DASH_DASH,
    ACTIONS(25), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    STATE(2), 2,
      sym__statement,
      aux_sym_source_file_repeat1,
    ACTIONS(28), 4,
      sym_decimal_literal,
      sym_binary_literal,
      sym_octal_literal,
      sym_hex_literal,
    STATE(7), 11,
      sym__expression,
      sym__primary_expression,
      sym__literal,
      sym__unary_expression,
      sym_prefix_expression,
      sym__binary_expression,
      sym_multiplicative_expression,
      sym_additive_expression,
      sym_integer_literal,
      sym_character_literal,
      sym_string_literal,
  [47] = 10,
    ACTIONS(5), 1,
      sym_identifier,
    ACTIONS(13), 1,
      anon_sym_SQUOTE,
    ACTIONS(15), 1,
      anon_sym_DQUOTE,
    ACTIONS(37), 1,
      ts_builtin_sym_end,
    STATE(4), 1,
      sym_prefix_unary_operator,
    ACTIONS(7), 2,
      anon_sym_PLUS_PLUS,
      anon_sym_DASH_DASH,
    ACTIONS(9), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    STATE(2), 2,
      sym__statement,
      aux_sym_source_file_repeat1,
    ACTIONS(11), 4,
      sym_decimal_literal,
      sym_binary_literal,
      sym_octal_literal,
      sym_hex_literal,
    STATE(7), 11,
      sym__expression,
      sym__primary_expression,
      sym__literal,
      sym__unary_expression,
      sym_prefix_expression,
      sym__binary_expression,
      sym_multiplicative_expression,
      sym_additive_expression,
      sym_integer_literal,
      sym_character_literal,
      sym_string_literal,
  [94] = 8,
    ACTIONS(13), 1,
      anon_sym_SQUOTE,
    ACTIONS(15), 1,
      anon_sym_DQUOTE,
    ACTIONS(39), 1,
      sym_identifier,
    STATE(4), 1,
      sym_prefix_unary_operator,
    ACTIONS(7), 2,
      anon_sym_PLUS_PLUS,
      anon_sym_DASH_DASH,
    ACTIONS(9), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(11), 4,
      sym_decimal_literal,
      sym_binary_literal,
      sym_octal_literal,
      sym_hex_literal,
    STATE(10), 11,
      sym__expression,
      sym__primary_expression,
      sym__literal,
      sym__unary_expression,
      sym_prefix_expression,
      sym__binary_expression,
      sym_multiplicative_expression,
      sym_additive_expression,
      sym_integer_literal,
      sym_character_literal,
      sym_string_literal,
  [134] = 8,
    ACTIONS(13), 1,
      anon_sym_SQUOTE,
    ACTIONS(15), 1,
      anon_sym_DQUOTE,
    ACTIONS(41), 1,
      sym_identifier,
    STATE(4), 1,
      sym_prefix_unary_operator,
    ACTIONS(7), 2,
      anon_sym_PLUS_PLUS,
      anon_sym_DASH_DASH,
    ACTIONS(9), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(11), 4,
      sym_decimal_literal,
      sym_binary_literal,
      sym_octal_literal,
      sym_hex_literal,
    STATE(9), 11,
      sym__expression,
      sym__primary_expression,
      sym__literal,
      sym__unary_expression,
      sym_prefix_expression,
      sym__binary_expression,
      sym_multiplicative_expression,
      sym_additive_expression,
      sym_integer_literal,
      sym_character_literal,
      sym_string_literal,
  [174] = 8,
    ACTIONS(13), 1,
      anon_sym_SQUOTE,
    ACTIONS(15), 1,
      anon_sym_DQUOTE,
    ACTIONS(43), 1,
      sym_identifier,
    STATE(4), 1,
      sym_prefix_unary_operator,
    ACTIONS(7), 2,
      anon_sym_PLUS_PLUS,
      anon_sym_DASH_DASH,
    ACTIONS(9), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(11), 4,
      sym_decimal_literal,
      sym_binary_literal,
      sym_octal_literal,
      sym_hex_literal,
    STATE(8), 11,
      sym__expression,
      sym__primary_expression,
      sym__literal,
      sym__unary_expression,
      sym_prefix_expression,
      sym__binary_expression,
      sym_multiplicative_expression,
      sym_additive_expression,
      sym_integer_literal,
      sym_character_literal,
      sym_string_literal,
  [214] = 5,
    STATE(5), 1,
      sym_multiplicative_operator,
    STATE(6), 1,
      sym_additive_operator,
    ACTIONS(47), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(49), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(45), 10,
      ts_builtin_sym_end,
      anon_sym_PLUS_PLUS,
      anon_sym_DASH_DASH,
      sym_decimal_literal,
      sym_binary_literal,
      sym_octal_literal,
      sym_hex_literal,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      sym_identifier,
  [242] = 5,
    STATE(5), 1,
      sym_multiplicative_operator,
    STATE(6), 1,
      sym_additive_operator,
    ACTIONS(53), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(49), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(51), 10,
      ts_builtin_sym_end,
      anon_sym_PLUS_PLUS,
      anon_sym_DASH_DASH,
      sym_decimal_literal,
      sym_binary_literal,
      sym_octal_literal,
      sym_hex_literal,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      sym_identifier,
  [270] = 4,
    STATE(5), 1,
      sym_multiplicative_operator,
    STATE(6), 1,
      sym_additive_operator,
    ACTIONS(57), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(55), 13,
      ts_builtin_sym_end,
      anon_sym_PLUS_PLUS,
      anon_sym_DASH_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      sym_decimal_literal,
      sym_binary_literal,
      sym_octal_literal,
      sym_hex_literal,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      sym_identifier,
  [296] = 5,
    STATE(5), 1,
      sym_multiplicative_operator,
    STATE(6), 1,
      sym_additive_operator,
    ACTIONS(47), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(49), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(59), 10,
      ts_builtin_sym_end,
      anon_sym_PLUS_PLUS,
      anon_sym_DASH_DASH,
      sym_decimal_literal,
      sym_binary_literal,
      sym_octal_literal,
      sym_hex_literal,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      sym_identifier,
  [324] = 5,
    ACTIONS(63), 1,
      anon_sym_BSLASHx,
    ACTIONS(65), 1,
      anon_sym_DQUOTE,
    ACTIONS(67), 1,
      aux_sym_string_literal_token1,
    STATE(14), 4,
      sym__quote_escape,
      sym__ascii_escape,
      sym__unicode_escape,
      aux_sym_string_literal_repeat1,
    ACTIONS(61), 9,
      anon_sym_BSLASH_SQUOTE,
      anon_sym_BSLASH_DQUOTE,
      anon_sym_BSLASHn,
      anon_sym_BSLASHr,
      anon_sym_BSLASHt,
      anon_sym_BSLASH_BSLASH,
      anon_sym_BSLASH0,
      aux_sym_unicode_escape_token1,
      sym__string_continuation,
  [351] = 3,
    ACTIONS(73), 1,
      sym_suffix_no_e,
    ACTIONS(71), 3,
      anon_sym_DASH,
      anon_sym_PLUS,
      sym_identifier,
    ACTIONS(69), 12,
      ts_builtin_sym_end,
      anon_sym_PLUS_PLUS,
      anon_sym_DASH_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      sym_decimal_literal,
      sym_binary_literal,
      sym_octal_literal,
      sym_hex_literal,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
  [374] = 5,
    ACTIONS(78), 1,
      anon_sym_BSLASHx,
    ACTIONS(81), 1,
      anon_sym_DQUOTE,
    ACTIONS(83), 1,
      aux_sym_string_literal_token1,
    STATE(13), 4,
      sym__quote_escape,
      sym__ascii_escape,
      sym__unicode_escape,
      aux_sym_string_literal_repeat1,
    ACTIONS(75), 9,
      anon_sym_BSLASH_SQUOTE,
      anon_sym_BSLASH_DQUOTE,
      anon_sym_BSLASHn,
      anon_sym_BSLASHr,
      anon_sym_BSLASHt,
      anon_sym_BSLASH_BSLASH,
      anon_sym_BSLASH0,
      aux_sym_unicode_escape_token1,
      sym__string_continuation,
  [401] = 5,
    ACTIONS(63), 1,
      anon_sym_BSLASHx,
    ACTIONS(88), 1,
      anon_sym_DQUOTE,
    ACTIONS(90), 1,
      aux_sym_string_literal_token1,
    STATE(13), 4,
      sym__quote_escape,
      sym__ascii_escape,
      sym__unicode_escape,
      aux_sym_string_literal_repeat1,
    ACTIONS(86), 9,
      anon_sym_BSLASH_SQUOTE,
      anon_sym_BSLASH_DQUOTE,
      anon_sym_BSLASHn,
      anon_sym_BSLASHr,
      anon_sym_BSLASHt,
      anon_sym_BSLASH_BSLASH,
      anon_sym_BSLASH0,
      aux_sym_unicode_escape_token1,
      sym__string_continuation,
  [428] = 2,
    ACTIONS(94), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(92), 13,
      ts_builtin_sym_end,
      anon_sym_PLUS_PLUS,
      anon_sym_DASH_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      sym_decimal_literal,
      sym_binary_literal,
      sym_octal_literal,
      sym_hex_literal,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      sym_identifier,
  [448] = 2,
    ACTIONS(98), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(96), 13,
      ts_builtin_sym_end,
      anon_sym_PLUS_PLUS,
      anon_sym_DASH_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      sym_decimal_literal,
      sym_binary_literal,
      sym_octal_literal,
      sym_hex_literal,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      sym_identifier,
  [468] = 2,
    ACTIONS(102), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(100), 13,
      ts_builtin_sym_end,
      anon_sym_PLUS_PLUS,
      anon_sym_DASH_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      sym_decimal_literal,
      sym_binary_literal,
      sym_octal_literal,
      sym_hex_literal,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      sym_identifier,
  [488] = 2,
    ACTIONS(106), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(104), 13,
      ts_builtin_sym_end,
      anon_sym_PLUS_PLUS,
      anon_sym_DASH_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      sym_decimal_literal,
      sym_binary_literal,
      sym_octal_literal,
      sym_hex_literal,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      sym_identifier,
  [508] = 6,
    ACTIONS(108), 1,
      aux_sym_character_literal_token1,
    ACTIONS(112), 1,
      anon_sym_BSLASHx,
    ACTIONS(116), 1,
      aux_sym_unicode_escape_token1,
    ACTIONS(110), 2,
      anon_sym_BSLASH_SQUOTE,
      anon_sym_BSLASH_DQUOTE,
    STATE(33), 3,
      sym_quote_escape,
      sym_ascii_escape,
      sym_unicode_escape,
    ACTIONS(114), 5,
      anon_sym_BSLASHn,
      anon_sym_BSLASHr,
      anon_sym_BSLASHt,
      anon_sym_BSLASH_BSLASH,
      anon_sym_BSLASH0,
  [534] = 2,
    ACTIONS(120), 1,
      aux_sym_string_literal_token1,
    ACTIONS(118), 11,
      anon_sym_BSLASH_SQUOTE,
      anon_sym_BSLASH_DQUOTE,
      anon_sym_BSLASHx,
      anon_sym_BSLASHn,
      anon_sym_BSLASHr,
      anon_sym_BSLASHt,
      anon_sym_BSLASH_BSLASH,
      anon_sym_BSLASH0,
      aux_sym_unicode_escape_token1,
      anon_sym_DQUOTE,
      sym__string_continuation,
  [551] = 2,
    ACTIONS(124), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(122), 9,
      anon_sym_PLUS_PLUS,
      anon_sym_DASH_DASH,
      sym_decimal_literal,
      sym_binary_literal,
      sym_octal_literal,
      sym_hex_literal,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      sym_identifier,
  [567] = 2,
    ACTIONS(128), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(126), 9,
      anon_sym_PLUS_PLUS,
      anon_sym_DASH_DASH,
      sym_decimal_literal,
      sym_binary_literal,
      sym_octal_literal,
      sym_hex_literal,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      sym_identifier,
  [583] = 2,
    ACTIONS(132), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(130), 9,
      anon_sym_PLUS_PLUS,
      anon_sym_DASH_DASH,
      sym_decimal_literal,
      sym_binary_literal,
      sym_octal_literal,
      sym_hex_literal,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      sym_identifier,
  [599] = 1,
    ACTIONS(134), 1,
      anon_sym_SQUOTE,
  [603] = 1,
    ACTIONS(136), 1,
      ts_builtin_sym_end,
  [607] = 1,
    ACTIONS(138), 1,
      aux_sym_ascii_escape_token2,
  [611] = 1,
    ACTIONS(140), 1,
      aux_sym_ascii_escape_token2,
  [615] = 1,
    ACTIONS(142), 1,
      aux_sym_ascii_escape_token1,
  [619] = 1,
    ACTIONS(144), 1,
      anon_sym_SQUOTE,
  [623] = 1,
    ACTIONS(146), 1,
      anon_sym_SQUOTE,
  [627] = 1,
    ACTIONS(148), 1,
      aux_sym_ascii_escape_token1,
  [631] = 1,
    ACTIONS(150), 1,
      anon_sym_SQUOTE,
  [635] = 1,
    ACTIONS(152), 1,
      anon_sym_SQUOTE,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 47,
  [SMALL_STATE(4)] = 94,
  [SMALL_STATE(5)] = 134,
  [SMALL_STATE(6)] = 174,
  [SMALL_STATE(7)] = 214,
  [SMALL_STATE(8)] = 242,
  [SMALL_STATE(9)] = 270,
  [SMALL_STATE(10)] = 296,
  [SMALL_STATE(11)] = 324,
  [SMALL_STATE(12)] = 351,
  [SMALL_STATE(13)] = 374,
  [SMALL_STATE(14)] = 401,
  [SMALL_STATE(15)] = 428,
  [SMALL_STATE(16)] = 448,
  [SMALL_STATE(17)] = 468,
  [SMALL_STATE(18)] = 488,
  [SMALL_STATE(19)] = 508,
  [SMALL_STATE(20)] = 534,
  [SMALL_STATE(21)] = 551,
  [SMALL_STATE(22)] = 567,
  [SMALL_STATE(23)] = 583,
  [SMALL_STATE(24)] = 599,
  [SMALL_STATE(25)] = 603,
  [SMALL_STATE(26)] = 607,
  [SMALL_STATE(27)] = 611,
  [SMALL_STATE(28)] = 615,
  [SMALL_STATE(29)] = 619,
  [SMALL_STATE(30)] = 623,
  [SMALL_STATE(31)] = 627,
  [SMALL_STATE(32)] = 631,
  [SMALL_STATE(33)] = 635,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(21),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [17] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2),
  [19] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(7),
  [22] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(21),
  [25] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(21),
  [28] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(12),
  [31] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(19),
  [34] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(11),
  [37] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1),
  [39] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [41] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [43] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [45] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__statement, 1),
  [47] = {.entry = {.count = 1, .reusable = false}}, SHIFT(22),
  [49] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [51] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_additive_expression, 3),
  [53] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_additive_expression, 3),
  [55] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_multiplicative_expression, 3),
  [57] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_multiplicative_expression, 3),
  [59] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_prefix_expression, 2),
  [61] = {.entry = {.count = 1, .reusable = false}}, SHIFT(14),
  [63] = {.entry = {.count = 1, .reusable = false}}, SHIFT(28),
  [65] = {.entry = {.count = 1, .reusable = false}}, SHIFT(18),
  [67] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [69] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_integer_literal, 1),
  [71] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_integer_literal, 1),
  [73] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [75] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_string_literal_repeat1, 2), SHIFT_REPEAT(13),
  [78] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_string_literal_repeat1, 2), SHIFT_REPEAT(28),
  [81] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_string_literal_repeat1, 2),
  [83] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_string_literal_repeat1, 2), SHIFT_REPEAT(13),
  [86] = {.entry = {.count = 1, .reusable = false}}, SHIFT(13),
  [88] = {.entry = {.count = 1, .reusable = false}}, SHIFT(16),
  [90] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [92] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_integer_literal, 2, .production_id = 1),
  [94] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_integer_literal, 2, .production_id = 1),
  [96] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_literal, 3),
  [98] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_string_literal, 3),
  [100] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_character_literal, 3),
  [102] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_character_literal, 3),
  [104] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_literal, 2),
  [106] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_string_literal, 2),
  [108] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [110] = {.entry = {.count = 1, .reusable = false}}, SHIFT(24),
  [112] = {.entry = {.count = 1, .reusable = false}}, SHIFT(31),
  [114] = {.entry = {.count = 1, .reusable = false}}, SHIFT(30),
  [116] = {.entry = {.count = 1, .reusable = false}}, SHIFT(29),
  [118] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__ascii_escape, 3),
  [120] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__ascii_escape, 3),
  [122] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_prefix_unary_operator, 1),
  [124] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_prefix_unary_operator, 1),
  [126] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_additive_operator, 1),
  [128] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_additive_operator, 1),
  [130] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_multiplicative_operator, 1),
  [132] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_multiplicative_operator, 1),
  [134] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quote_escape, 1),
  [136] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [138] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [140] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [142] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [144] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_unicode_escape, 1),
  [146] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_ascii_escape, 1),
  [148] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [150] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_ascii_escape, 3),
  [152] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef _WIN32
#define extern __declspec(dllexport)
#endif

extern const TSLanguage *tree_sitter_xva(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .field_names = ts_field_names,
    .field_map_slices = ts_field_map_slices,
    .field_map_entries = ts_field_map_entries,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .keyword_lex_fn = ts_lex_keywords,
    .keyword_capture_token = sym_identifier,
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
