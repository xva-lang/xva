#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 44
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 62
#define ALIAS_COUNT 0
#define TOKEN_COUNT 45
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 4
#define MAX_ALIAS_SEQUENCE_LENGTH 4
#define PRODUCTION_ID_COUNT 4

enum {
  anon_sym_DASH = 1,
  anon_sym_not = 2,
  anon_sym_and = 3,
  anon_sym_or = 4,
  anon_sym_AMP = 5,
  anon_sym_PIPE = 6,
  anon_sym_CARET = 7,
  anon_sym_PLUS = 8,
  anon_sym_STAR = 9,
  anon_sym_SLASH = 10,
  anon_sym_STAR_STAR = 11,
  anon_sym_PERCENT = 12,
  anon_sym_GT_GT = 13,
  anon_sym_LT_LT = 14,
  anon_sym_LT = 15,
  anon_sym_GT = 16,
  anon_sym_EQ_EQ = 17,
  anon_sym_BANG_EQ = 18,
  anon_sym_GT_EQ = 19,
  anon_sym_LT_EQ = 20,
  aux_sym_decimal_literal_token1 = 21,
  sym_binary_literal = 22,
  sym_octal_literal = 23,
  sym_hex_literal = 24,
  sym_character_literal = 25,
  anon_sym_BSLASH_SQUOTE = 26,
  anon_sym_BSLASH_DQUOTE = 27,
  anon_sym_BSLASHx = 28,
  aux_sym_ascii_escape_token1 = 29,
  aux_sym_ascii_escape_token2 = 30,
  anon_sym_BSLASHn = 31,
  anon_sym_BSLASHr = 32,
  anon_sym_BSLASHt = 33,
  anon_sym_BSLASH_BSLASH = 34,
  anon_sym_BSLASH0 = 35,
  aux_sym_unicode_escape_token1 = 36,
  aux_sym_string_literal_token1 = 37,
  sym__string_sigil = 38,
  sym_escape_sequence = 39,
  sym__string_continuation = 40,
  sym__boolean_true = 41,
  sym__boolean_false = 42,
  sym_float_exponent = 43,
  sym__float_decimal_point = 44,
  sym_root = 45,
  sym__item = 46,
  sym_expression = 47,
  sym__primary_expression = 48,
  sym_unary_expression = 49,
  sym_negation_expression = 50,
  sym_not_expression = 51,
  sym_binary_expression = 52,
  sym_literal = 53,
  sym_integer_literal = 54,
  sym_decimal_literal = 55,
  sym_string_literal = 56,
  sym_boolean_literal = 57,
  sym__decimal_literal = 58,
  sym_float_literal = 59,
  aux_sym_root_repeat1 = 60,
  aux_sym_string_literal_repeat1 = 61,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_DASH] = "-",
  [anon_sym_not] = "not",
  [anon_sym_and] = "and",
  [anon_sym_or] = "or",
  [anon_sym_AMP] = "&",
  [anon_sym_PIPE] = "|",
  [anon_sym_CARET] = "^",
  [anon_sym_PLUS] = "+",
  [anon_sym_STAR] = "*",
  [anon_sym_SLASH] = "/",
  [anon_sym_STAR_STAR] = "**",
  [anon_sym_PERCENT] = "%",
  [anon_sym_GT_GT] = ">>",
  [anon_sym_LT_LT] = "<<",
  [anon_sym_LT] = "<",
  [anon_sym_GT] = ">",
  [anon_sym_EQ_EQ] = "==",
  [anon_sym_BANG_EQ] = "!=",
  [anon_sym_GT_EQ] = ">=",
  [anon_sym_LT_EQ] = "<=",
  [aux_sym_decimal_literal_token1] = "decimal_literal_token1",
  [sym_binary_literal] = "binary_literal",
  [sym_octal_literal] = "octal_literal",
  [sym_hex_literal] = "hex_literal",
  [sym_character_literal] = "character_literal",
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
  [aux_sym_string_literal_token1] = "string_literal_token1",
  [sym__string_sigil] = "_string_sigil",
  [sym_escape_sequence] = "escape_sequence",
  [sym__string_continuation] = "_string_continuation",
  [sym__boolean_true] = "_boolean_true",
  [sym__boolean_false] = "_boolean_false",
  [sym_float_exponent] = "float_exponent",
  [sym__float_decimal_point] = "_float_decimal_point",
  [sym_root] = "root",
  [sym__item] = "_item",
  [sym_expression] = "expression",
  [sym__primary_expression] = "_primary_expression",
  [sym_unary_expression] = "unary_expression",
  [sym_negation_expression] = "negation_expression",
  [sym_not_expression] = "not_expression",
  [sym_binary_expression] = "binary_expression",
  [sym_literal] = "literal",
  [sym_integer_literal] = "integer_literal",
  [sym_decimal_literal] = "decimal_literal",
  [sym_string_literal] = "string_literal",
  [sym_boolean_literal] = "boolean_literal",
  [sym__decimal_literal] = "_decimal_literal",
  [sym_float_literal] = "float_literal",
  [aux_sym_root_repeat1] = "root_repeat1",
  [aux_sym_string_literal_repeat1] = "string_literal_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_DASH] = anon_sym_DASH,
  [anon_sym_not] = anon_sym_not,
  [anon_sym_and] = anon_sym_and,
  [anon_sym_or] = anon_sym_or,
  [anon_sym_AMP] = anon_sym_AMP,
  [anon_sym_PIPE] = anon_sym_PIPE,
  [anon_sym_CARET] = anon_sym_CARET,
  [anon_sym_PLUS] = anon_sym_PLUS,
  [anon_sym_STAR] = anon_sym_STAR,
  [anon_sym_SLASH] = anon_sym_SLASH,
  [anon_sym_STAR_STAR] = anon_sym_STAR_STAR,
  [anon_sym_PERCENT] = anon_sym_PERCENT,
  [anon_sym_GT_GT] = anon_sym_GT_GT,
  [anon_sym_LT_LT] = anon_sym_LT_LT,
  [anon_sym_LT] = anon_sym_LT,
  [anon_sym_GT] = anon_sym_GT,
  [anon_sym_EQ_EQ] = anon_sym_EQ_EQ,
  [anon_sym_BANG_EQ] = anon_sym_BANG_EQ,
  [anon_sym_GT_EQ] = anon_sym_GT_EQ,
  [anon_sym_LT_EQ] = anon_sym_LT_EQ,
  [aux_sym_decimal_literal_token1] = aux_sym_decimal_literal_token1,
  [sym_binary_literal] = sym_binary_literal,
  [sym_octal_literal] = sym_octal_literal,
  [sym_hex_literal] = sym_hex_literal,
  [sym_character_literal] = sym_character_literal,
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
  [aux_sym_string_literal_token1] = aux_sym_string_literal_token1,
  [sym__string_sigil] = sym__string_sigil,
  [sym_escape_sequence] = sym_escape_sequence,
  [sym__string_continuation] = sym__string_continuation,
  [sym__boolean_true] = sym__boolean_true,
  [sym__boolean_false] = sym__boolean_false,
  [sym_float_exponent] = sym_float_exponent,
  [sym__float_decimal_point] = sym__float_decimal_point,
  [sym_root] = sym_root,
  [sym__item] = sym__item,
  [sym_expression] = sym_expression,
  [sym__primary_expression] = sym__primary_expression,
  [sym_unary_expression] = sym_unary_expression,
  [sym_negation_expression] = sym_negation_expression,
  [sym_not_expression] = sym_not_expression,
  [sym_binary_expression] = sym_binary_expression,
  [sym_literal] = sym_literal,
  [sym_integer_literal] = sym_integer_literal,
  [sym_decimal_literal] = sym_decimal_literal,
  [sym_string_literal] = sym_string_literal,
  [sym_boolean_literal] = sym_boolean_literal,
  [sym__decimal_literal] = sym__decimal_literal,
  [sym_float_literal] = sym_float_literal,
  [aux_sym_root_repeat1] = aux_sym_root_repeat1,
  [aux_sym_string_literal_repeat1] = aux_sym_string_literal_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_DASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_not] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_and] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_or] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_AMP] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PIPE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_CARET] = {
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
  [anon_sym_STAR_STAR] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PERCENT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_GT_GT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LT_LT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_GT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_EQ_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_BANG_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_GT_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LT_EQ] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_decimal_literal_token1] = {
    .visible = false,
    .named = false,
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
  [sym_character_literal] = {
    .visible = true,
    .named = true,
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
  [aux_sym_string_literal_token1] = {
    .visible = false,
    .named = false,
  },
  [sym__string_sigil] = {
    .visible = false,
    .named = true,
  },
  [sym_escape_sequence] = {
    .visible = true,
    .named = true,
  },
  [sym__string_continuation] = {
    .visible = false,
    .named = true,
  },
  [sym__boolean_true] = {
    .visible = false,
    .named = true,
  },
  [sym__boolean_false] = {
    .visible = false,
    .named = true,
  },
  [sym_float_exponent] = {
    .visible = true,
    .named = true,
  },
  [sym__float_decimal_point] = {
    .visible = false,
    .named = true,
  },
  [sym_root] = {
    .visible = true,
    .named = true,
  },
  [sym__item] = {
    .visible = false,
    .named = true,
  },
  [sym_expression] = {
    .visible = true,
    .named = true,
  },
  [sym__primary_expression] = {
    .visible = false,
    .named = true,
  },
  [sym_unary_expression] = {
    .visible = true,
    .named = true,
  },
  [sym_negation_expression] = {
    .visible = true,
    .named = true,
  },
  [sym_not_expression] = {
    .visible = true,
    .named = true,
  },
  [sym_binary_expression] = {
    .visible = true,
    .named = true,
  },
  [sym_literal] = {
    .visible = true,
    .named = true,
  },
  [sym_integer_literal] = {
    .visible = true,
    .named = true,
  },
  [sym_decimal_literal] = {
    .visible = true,
    .named = true,
  },
  [sym_string_literal] = {
    .visible = true,
    .named = true,
  },
  [sym_boolean_literal] = {
    .visible = true,
    .named = true,
  },
  [sym__decimal_literal] = {
    .visible = false,
    .named = true,
  },
  [sym_float_literal] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_root_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_string_literal_repeat1] = {
    .visible = false,
    .named = false,
  },
};

enum {
  field_exponent = 1,
  field_left = 2,
  field_operator = 3,
  field_right = 4,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_exponent] = "exponent",
  [field_left] = "left",
  [field_operator] = "operator",
  [field_right] = "right",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 3},
  [2] = {.index = 3, .length = 1},
  [3] = {.index = 4, .length = 1},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_left, 0},
    {field_operator, 1},
    {field_right, 2},
  [3] =
    {field_exponent, 2},
  [4] =
    {field_exponent, 3},
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
  [34] = 34,
  [35] = 35,
  [36] = 36,
  [37] = 37,
  [38] = 38,
  [39] = 39,
  [40] = 40,
  [41] = 41,
  [42] = 42,
  [43] = 43,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(36);
      if (lookahead == '!') ADVANCE(5);
      if (lookahead == '"') ADVANCE(92);
      if (lookahead == '%') ADVANCE(48);
      if (lookahead == '&') ADVANCE(41);
      if (lookahead == '\'') ADVANCE(4);
      if (lookahead == '*') ADVANCE(45);
      if (lookahead == '+') ADVANCE(44);
      if (lookahead == '-') ADVANCE(37);
      if (lookahead == '.') ADVANCE(103);
      if (lookahead == '/') ADVANCE(46);
      if (lookahead == '0') ADVANCE(59);
      if (lookahead == '<') ADVANCE(51);
      if (lookahead == '=') ADVANCE(6);
      if (lookahead == '>') ADVANCE(52);
      if (lookahead == '\\') ADVANCE(68);
      if (lookahead == '^') ADVANCE(43);
      if (lookahead == 'a') ADVANCE(71);
      if (lookahead == 'f') ADVANCE(70);
      if (lookahead == 'n') ADVANCE(18);
      if (lookahead == 'o') ADVANCE(19);
      if (lookahead == 't') ADVANCE(20);
      if (lookahead == '|') ADVANCE(42);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(69);
      if (lookahead == '8' ||
          lookahead == '9') ADVANCE(57);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      if (('1' <= lookahead && lookahead <= '7')) ADVANCE(57);
      if (('A' <= lookahead && lookahead <= 'd')) ADVANCE(67);
      END_STATE();
    case 1:
      if (lookahead == '\n') SKIP(2)
      if (lookahead == '"') ADVANCE(92);
      if (lookahead == '\\') ADVANCE(25);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(91);
      if (lookahead != 0) ADVANCE(90);
      END_STATE();
    case 2:
      if (lookahead == '\n') SKIP(2)
      if (lookahead == '"') ADVANCE(92);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(91);
      if (lookahead != 0 &&
          lookahead != '\\') ADVANCE(90);
      END_STATE();
    case 3:
      if (lookahead == '\'') ADVANCE(63);
      END_STATE();
    case 4:
      if (lookahead == '\'') ADVANCE(63);
      if (lookahead == '\\') ADVANCE(23);
      if (lookahead != 0) ADVANCE(3);
      END_STATE();
    case 5:
      if (lookahead == '=') ADVANCE(54);
      END_STATE();
    case 6:
      if (lookahead == '=') ADVANCE(53);
      END_STATE();
    case 7:
      if (lookahead == '_') ADVANCE(7);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(61);
      END_STATE();
    case 8:
      if (lookahead == '_') ADVANCE(8);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(62);
      END_STATE();
    case 9:
      if (lookahead == '_') ADVANCE(10);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(10);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(102);
      END_STATE();
    case 10:
      if (lookahead == '_') ADVANCE(10);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(102);
      END_STATE();
    case 11:
      if (lookahead == '_') ADVANCE(11);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(60);
      END_STATE();
    case 12:
      if (lookahead == 'a') ADVANCE(16);
      END_STATE();
    case 13:
      if (lookahead == 'd') ADVANCE(39);
      END_STATE();
    case 14:
      if (lookahead == 'e') ADVANCE(100);
      END_STATE();
    case 15:
      if (lookahead == 'e') ADVANCE(101);
      END_STATE();
    case 16:
      if (lookahead == 'l') ADVANCE(21);
      END_STATE();
    case 17:
      if (lookahead == 'n') ADVANCE(13);
      END_STATE();
    case 18:
      if (lookahead == 'o') ADVANCE(22);
      END_STATE();
    case 19:
      if (lookahead == 'r') ADVANCE(40);
      END_STATE();
    case 20:
      if (lookahead == 'r') ADVANCE(24);
      END_STATE();
    case 21:
      if (lookahead == 's') ADVANCE(15);
      END_STATE();
    case 22:
      if (lookahead == 't') ADVANCE(38);
      END_STATE();
    case 23:
      if (lookahead == 'u') ADVANCE(26);
      if (lookahead == 'x') ADVANCE(33);
      if (lookahead != 0) ADVANCE(3);
      END_STATE();
    case 24:
      if (lookahead == 'u') ADVANCE(14);
      END_STATE();
    case 25:
      if (lookahead == 'u') ADVANCE(32);
      if (lookahead == 'x') ADVANCE(34);
      if (lookahead != 0) ADVANCE(93);
      END_STATE();
    case 26:
      if (lookahead == '{') ADVANCE(30);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(29);
      END_STATE();
    case 27:
      if (lookahead == '}') ADVANCE(3);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(27);
      END_STATE();
    case 28:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(3);
      END_STATE();
    case 29:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(33);
      END_STATE();
    case 30:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(27);
      END_STATE();
    case 31:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(93);
      END_STATE();
    case 32:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(98);
      END_STATE();
    case 33:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(28);
      END_STATE();
    case 34:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(31);
      END_STATE();
    case 35:
      if (eof) ADVANCE(36);
      if (lookahead == '!') ADVANCE(5);
      if (lookahead == '"') ADVANCE(92);
      if (lookahead == '%') ADVANCE(48);
      if (lookahead == '&') ADVANCE(41);
      if (lookahead == '\'') ADVANCE(4);
      if (lookahead == '*') ADVANCE(45);
      if (lookahead == '+') ADVANCE(44);
      if (lookahead == '-') ADVANCE(37);
      if (lookahead == '.') ADVANCE(103);
      if (lookahead == '/') ADVANCE(46);
      if (lookahead == '0') ADVANCE(58);
      if (lookahead == '<') ADVANCE(51);
      if (lookahead == '=') ADVANCE(6);
      if (lookahead == '>') ADVANCE(52);
      if (lookahead == '^') ADVANCE(43);
      if (lookahead == 'a') ADVANCE(17);
      if (lookahead == 'f') ADVANCE(12);
      if (lookahead == 'n') ADVANCE(18);
      if (lookahead == 'o') ADVANCE(19);
      if (lookahead == 't') ADVANCE(20);
      if (lookahead == '|') ADVANCE(42);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(9);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(35)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(57);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(anon_sym_DASH);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(anon_sym_not);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(anon_sym_and);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(anon_sym_or);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(anon_sym_AMP);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(anon_sym_PIPE);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(anon_sym_CARET);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(anon_sym_PLUS);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(anon_sym_STAR);
      if (lookahead == '*') ADVANCE(47);
      END_STATE();
    case 46:
      ACCEPT_TOKEN(anon_sym_SLASH);
      END_STATE();
    case 47:
      ACCEPT_TOKEN(anon_sym_STAR_STAR);
      END_STATE();
    case 48:
      ACCEPT_TOKEN(anon_sym_PERCENT);
      END_STATE();
    case 49:
      ACCEPT_TOKEN(anon_sym_GT_GT);
      END_STATE();
    case 50:
      ACCEPT_TOKEN(anon_sym_LT_LT);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(anon_sym_LT);
      if (lookahead == '<') ADVANCE(50);
      if (lookahead == '=') ADVANCE(56);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(anon_sym_GT);
      if (lookahead == '=') ADVANCE(55);
      if (lookahead == '>') ADVANCE(49);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(anon_sym_EQ_EQ);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(anon_sym_BANG_EQ);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(anon_sym_GT_EQ);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(anon_sym_LT_EQ);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(aux_sym_decimal_literal_token1);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(57);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(aux_sym_decimal_literal_token1);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(57);
      if (lookahead == 'b') ADVANCE(11);
      if (lookahead == 'o') ADVANCE(7);
      if (lookahead == 'x') ADVANCE(8);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(aux_sym_decimal_literal_token1);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(57);
      if (lookahead == 'o') ADVANCE(7);
      if (lookahead == 'x') ADVANCE(8);
      END_STATE();
    case 60:
      ACCEPT_TOKEN(sym_binary_literal);
      if (lookahead == '_') ADVANCE(60);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(60);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(sym_octal_literal);
      if (lookahead == '_') ADVANCE(61);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(61);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(sym_hex_literal);
      if (lookahead == '_') ADVANCE(62);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(62);
      END_STATE();
    case 63:
      ACCEPT_TOKEN(sym_character_literal);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(anon_sym_BSLASH_SQUOTE);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(anon_sym_BSLASH_DQUOTE);
      END_STATE();
    case 66:
      ACCEPT_TOKEN(anon_sym_BSLASHx);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(aux_sym_ascii_escape_token2);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(aux_sym_ascii_escape_token2);
      if (lookahead == '\n') ADVANCE(99);
      if (lookahead == '"') ADVANCE(65);
      if (lookahead == '\'') ADVANCE(64);
      if (lookahead == '0') ADVANCE(76);
      if (lookahead == '\\') ADVANCE(75);
      if (lookahead == 'n') ADVANCE(72);
      if (lookahead == 'r') ADVANCE(73);
      if (lookahead == 't') ADVANCE(74);
      if (lookahead == 'u') ADVANCE(89);
      if (lookahead == 'x') ADVANCE(66);
      END_STATE();
    case 69:
      ACCEPT_TOKEN(aux_sym_ascii_escape_token2);
      if (lookahead == '_') ADVANCE(10);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(10);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(102);
      END_STATE();
    case 70:
      ACCEPT_TOKEN(aux_sym_ascii_escape_token2);
      if (lookahead == 'a') ADVANCE(16);
      END_STATE();
    case 71:
      ACCEPT_TOKEN(aux_sym_ascii_escape_token2);
      if (lookahead == 'n') ADVANCE(13);
      END_STATE();
    case 72:
      ACCEPT_TOKEN(anon_sym_BSLASHn);
      END_STATE();
    case 73:
      ACCEPT_TOKEN(anon_sym_BSLASHr);
      END_STATE();
    case 74:
      ACCEPT_TOKEN(anon_sym_BSLASHt);
      END_STATE();
    case 75:
      ACCEPT_TOKEN(anon_sym_BSLASH_BSLASH);
      END_STATE();
    case 76:
      ACCEPT_TOKEN(anon_sym_BSLASH0);
      END_STATE();
    case 77:
      ACCEPT_TOKEN(aux_sym_unicode_escape_token1);
      END_STATE();
    case 78:
      ACCEPT_TOKEN(aux_sym_unicode_escape_token1);
      if (lookahead == '_') ADVANCE(78);
      END_STATE();
    case 79:
      ACCEPT_TOKEN(aux_sym_unicode_escape_token1);
      if (lookahead == '_') ADVANCE(78);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(77);
      END_STATE();
    case 80:
      ACCEPT_TOKEN(aux_sym_unicode_escape_token1);
      if (lookahead == '_') ADVANCE(80);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(77);
      END_STATE();
    case 81:
      ACCEPT_TOKEN(aux_sym_unicode_escape_token1);
      if (lookahead == '_') ADVANCE(80);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(79);
      END_STATE();
    case 82:
      ACCEPT_TOKEN(aux_sym_unicode_escape_token1);
      if (lookahead == '_') ADVANCE(82);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(79);
      END_STATE();
    case 83:
      ACCEPT_TOKEN(aux_sym_unicode_escape_token1);
      if (lookahead == '_') ADVANCE(82);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(81);
      END_STATE();
    case 84:
      ACCEPT_TOKEN(aux_sym_unicode_escape_token1);
      if (lookahead == '_') ADVANCE(84);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(81);
      END_STATE();
    case 85:
      ACCEPT_TOKEN(aux_sym_unicode_escape_token1);
      if (lookahead == '_') ADVANCE(84);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(83);
      END_STATE();
    case 86:
      ACCEPT_TOKEN(aux_sym_unicode_escape_token1);
      if (lookahead == '_') ADVANCE(86);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(83);
      END_STATE();
    case 87:
      ACCEPT_TOKEN(aux_sym_unicode_escape_token1);
      if (lookahead == '_') ADVANCE(86);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(85);
      END_STATE();
    case 88:
      ACCEPT_TOKEN(aux_sym_unicode_escape_token1);
      if (lookahead == '_') ADVANCE(88);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(85);
      END_STATE();
    case 89:
      ACCEPT_TOKEN(aux_sym_unicode_escape_token1);
      if (lookahead == '_') ADVANCE(88);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(87);
      END_STATE();
    case 90:
      ACCEPT_TOKEN(aux_sym_string_literal_token1);
      END_STATE();
    case 91:
      ACCEPT_TOKEN(aux_sym_string_literal_token1);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(91);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '"' &&
          lookahead != '\\') ADVANCE(90);
      END_STATE();
    case 92:
      ACCEPT_TOKEN(sym__string_sigil);
      END_STATE();
    case 93:
      ACCEPT_TOKEN(sym_escape_sequence);
      END_STATE();
    case 94:
      ACCEPT_TOKEN(sym_escape_sequence);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(93);
      END_STATE();
    case 95:
      ACCEPT_TOKEN(sym_escape_sequence);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(94);
      END_STATE();
    case 96:
      ACCEPT_TOKEN(sym_escape_sequence);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(95);
      END_STATE();
    case 97:
      ACCEPT_TOKEN(sym_escape_sequence);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(96);
      END_STATE();
    case 98:
      ACCEPT_TOKEN(sym_escape_sequence);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(97);
      END_STATE();
    case 99:
      ACCEPT_TOKEN(sym__string_continuation);
      END_STATE();
    case 100:
      ACCEPT_TOKEN(sym__boolean_true);
      END_STATE();
    case 101:
      ACCEPT_TOKEN(sym__boolean_false);
      END_STATE();
    case 102:
      ACCEPT_TOKEN(sym_float_exponent);
      if (lookahead == '_') ADVANCE(102);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(102);
      END_STATE();
    case 103:
      ACCEPT_TOKEN(sym__float_decimal_point);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 35},
  [2] = {.lex_state = 35},
  [3] = {.lex_state = 35},
  [4] = {.lex_state = 35},
  [5] = {.lex_state = 35},
  [6] = {.lex_state = 35},
  [7] = {.lex_state = 35},
  [8] = {.lex_state = 35},
  [9] = {.lex_state = 35},
  [10] = {.lex_state = 35},
  [11] = {.lex_state = 35},
  [12] = {.lex_state = 35},
  [13] = {.lex_state = 35},
  [14] = {.lex_state = 35},
  [15] = {.lex_state = 35},
  [16] = {.lex_state = 35},
  [17] = {.lex_state = 35},
  [18] = {.lex_state = 35},
  [19] = {.lex_state = 35},
  [20] = {.lex_state = 35},
  [21] = {.lex_state = 35},
  [22] = {.lex_state = 35},
  [23] = {.lex_state = 35},
  [24] = {.lex_state = 35},
  [25] = {.lex_state = 35},
  [26] = {.lex_state = 35},
  [27] = {.lex_state = 35},
  [28] = {.lex_state = 35},
  [29] = {.lex_state = 35},
  [30] = {.lex_state = 35},
  [31] = {.lex_state = 35},
  [32] = {.lex_state = 35},
  [33] = {.lex_state = 35},
  [34] = {.lex_state = 35},
  [35] = {.lex_state = 35},
  [36] = {.lex_state = 35},
  [37] = {.lex_state = 35},
  [38] = {.lex_state = 35},
  [39] = {.lex_state = 1},
  [40] = {.lex_state = 1},
  [41] = {.lex_state = 1},
  [42] = {.lex_state = 0},
  [43] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_DASH] = ACTIONS(1),
    [anon_sym_not] = ACTIONS(1),
    [anon_sym_and] = ACTIONS(1),
    [anon_sym_or] = ACTIONS(1),
    [anon_sym_AMP] = ACTIONS(1),
    [anon_sym_PIPE] = ACTIONS(1),
    [anon_sym_CARET] = ACTIONS(1),
    [anon_sym_PLUS] = ACTIONS(1),
    [anon_sym_STAR] = ACTIONS(1),
    [anon_sym_SLASH] = ACTIONS(1),
    [anon_sym_STAR_STAR] = ACTIONS(1),
    [anon_sym_PERCENT] = ACTIONS(1),
    [anon_sym_GT_GT] = ACTIONS(1),
    [anon_sym_LT_LT] = ACTIONS(1),
    [anon_sym_LT] = ACTIONS(1),
    [anon_sym_GT] = ACTIONS(1),
    [anon_sym_EQ_EQ] = ACTIONS(1),
    [anon_sym_BANG_EQ] = ACTIONS(1),
    [anon_sym_GT_EQ] = ACTIONS(1),
    [anon_sym_LT_EQ] = ACTIONS(1),
    [aux_sym_decimal_literal_token1] = ACTIONS(1),
    [sym_octal_literal] = ACTIONS(1),
    [sym_hex_literal] = ACTIONS(1),
    [sym_character_literal] = ACTIONS(1),
    [anon_sym_BSLASH_SQUOTE] = ACTIONS(1),
    [anon_sym_BSLASH_DQUOTE] = ACTIONS(1),
    [anon_sym_BSLASHx] = ACTIONS(1),
    [aux_sym_ascii_escape_token1] = ACTIONS(1),
    [aux_sym_ascii_escape_token2] = ACTIONS(1),
    [anon_sym_BSLASHn] = ACTIONS(1),
    [anon_sym_BSLASHr] = ACTIONS(1),
    [anon_sym_BSLASHt] = ACTIONS(1),
    [anon_sym_BSLASH_BSLASH] = ACTIONS(1),
    [anon_sym_BSLASH0] = ACTIONS(1),
    [aux_sym_unicode_escape_token1] = ACTIONS(1),
    [sym__string_sigil] = ACTIONS(1),
    [sym__string_continuation] = ACTIONS(1),
    [sym__boolean_true] = ACTIONS(1),
    [sym__boolean_false] = ACTIONS(1),
    [sym_float_exponent] = ACTIONS(1),
    [sym__float_decimal_point] = ACTIONS(1),
  },
  [1] = {
    [sym_root] = STATE(43),
    [sym__item] = STATE(27),
    [sym_expression] = STATE(10),
    [sym__primary_expression] = STATE(11),
    [sym_unary_expression] = STATE(11),
    [sym_negation_expression] = STATE(12),
    [sym_not_expression] = STATE(12),
    [sym_binary_expression] = STATE(11),
    [sym_literal] = STATE(11),
    [sym_integer_literal] = STATE(23),
    [sym_decimal_literal] = STATE(6),
    [sym_string_literal] = STATE(23),
    [sym_boolean_literal] = STATE(23),
    [sym__decimal_literal] = STATE(42),
    [sym_float_literal] = STATE(23),
    [aux_sym_root_repeat1] = STATE(27),
    [ts_builtin_sym_end] = ACTIONS(3),
    [anon_sym_DASH] = ACTIONS(5),
    [anon_sym_not] = ACTIONS(7),
    [aux_sym_decimal_literal_token1] = ACTIONS(9),
    [sym_binary_literal] = ACTIONS(11),
    [sym_octal_literal] = ACTIONS(11),
    [sym_hex_literal] = ACTIONS(11),
    [sym_character_literal] = ACTIONS(13),
    [sym__string_sigil] = ACTIONS(15),
    [sym__boolean_true] = ACTIONS(17),
    [sym__boolean_false] = ACTIONS(17),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 5,
    ACTIONS(23), 1,
      aux_sym_decimal_literal_token1,
    ACTIONS(26), 1,
      sym_float_exponent,
    STATE(3), 1,
      sym__decimal_literal,
    ACTIONS(21), 3,
      anon_sym_STAR,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(19), 25,
      ts_builtin_sym_end,
      anon_sym_DASH,
      anon_sym_not,
      anon_sym_and,
      anon_sym_or,
      anon_sym_AMP,
      anon_sym_PIPE,
      anon_sym_CARET,
      anon_sym_PLUS,
      anon_sym_SLASH,
      anon_sym_STAR_STAR,
      anon_sym_PERCENT,
      anon_sym_GT_GT,
      anon_sym_LT_LT,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      sym_binary_literal,
      sym_octal_literal,
      sym_hex_literal,
      sym_character_literal,
      sym__string_sigil,
      sym__boolean_true,
      sym__boolean_false,
  [42] = 3,
    ACTIONS(32), 1,
      sym_float_exponent,
    ACTIONS(30), 4,
      anon_sym_STAR,
      anon_sym_LT,
      anon_sym_GT,
      aux_sym_decimal_literal_token1,
    ACTIONS(28), 25,
      ts_builtin_sym_end,
      anon_sym_DASH,
      anon_sym_not,
      anon_sym_and,
      anon_sym_or,
      anon_sym_AMP,
      anon_sym_PIPE,
      anon_sym_CARET,
      anon_sym_PLUS,
      anon_sym_SLASH,
      anon_sym_STAR_STAR,
      anon_sym_PERCENT,
      anon_sym_GT_GT,
      anon_sym_LT_LT,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      sym_binary_literal,
      sym_octal_literal,
      sym_hex_literal,
      sym_character_literal,
      sym__string_sigil,
      sym__boolean_true,
      sym__boolean_false,
  [79] = 3,
    ACTIONS(38), 1,
      sym__float_decimal_point,
    ACTIONS(36), 4,
      anon_sym_STAR,
      anon_sym_LT,
      anon_sym_GT,
      aux_sym_decimal_literal_token1,
    ACTIONS(34), 25,
      ts_builtin_sym_end,
      anon_sym_DASH,
      anon_sym_not,
      anon_sym_and,
      anon_sym_or,
      anon_sym_AMP,
      anon_sym_PIPE,
      anon_sym_CARET,
      anon_sym_PLUS,
      anon_sym_SLASH,
      anon_sym_STAR_STAR,
      anon_sym_PERCENT,
      anon_sym_GT_GT,
      anon_sym_LT_LT,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      sym_binary_literal,
      sym_octal_literal,
      sym_hex_literal,
      sym_character_literal,
      sym__string_sigil,
      sym__boolean_true,
      sym__boolean_false,
  [116] = 11,
    ACTIONS(44), 1,
      anon_sym_AMP,
    ACTIONS(46), 1,
      anon_sym_PIPE,
    ACTIONS(48), 1,
      anon_sym_CARET,
    ACTIONS(50), 1,
      anon_sym_STAR,
    ACTIONS(60), 1,
      aux_sym_decimal_literal_token1,
    ACTIONS(42), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(54), 2,
      anon_sym_GT_GT,
      anon_sym_LT_LT,
    ACTIONS(56), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(52), 3,
      anon_sym_SLASH,
      anon_sym_STAR_STAR,
      anon_sym_PERCENT,
    ACTIONS(58), 4,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(40), 11,
      ts_builtin_sym_end,
      anon_sym_not,
      anon_sym_and,
      anon_sym_or,
      sym_binary_literal,
      sym_octal_literal,
      sym_hex_literal,
      sym_character_literal,
      sym__string_sigil,
      sym__boolean_true,
      sym__boolean_false,
  [168] = 2,
    ACTIONS(64), 4,
      anon_sym_STAR,
      anon_sym_LT,
      anon_sym_GT,
      aux_sym_decimal_literal_token1,
    ACTIONS(62), 25,
      ts_builtin_sym_end,
      anon_sym_DASH,
      anon_sym_not,
      anon_sym_and,
      anon_sym_or,
      anon_sym_AMP,
      anon_sym_PIPE,
      anon_sym_CARET,
      anon_sym_PLUS,
      anon_sym_SLASH,
      anon_sym_STAR_STAR,
      anon_sym_PERCENT,
      anon_sym_GT_GT,
      anon_sym_LT_LT,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      sym_binary_literal,
      sym_octal_literal,
      sym_hex_literal,
      sym_character_literal,
      sym__string_sigil,
      sym__boolean_true,
      sym__boolean_false,
  [202] = 2,
    ACTIONS(68), 4,
      anon_sym_STAR,
      anon_sym_LT,
      anon_sym_GT,
      aux_sym_decimal_literal_token1,
    ACTIONS(66), 25,
      ts_builtin_sym_end,
      anon_sym_DASH,
      anon_sym_not,
      anon_sym_and,
      anon_sym_or,
      anon_sym_AMP,
      anon_sym_PIPE,
      anon_sym_CARET,
      anon_sym_PLUS,
      anon_sym_SLASH,
      anon_sym_STAR_STAR,
      anon_sym_PERCENT,
      anon_sym_GT_GT,
      anon_sym_LT_LT,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      sym_binary_literal,
      sym_octal_literal,
      sym_hex_literal,
      sym_character_literal,
      sym__string_sigil,
      sym__boolean_true,
      sym__boolean_false,
  [236] = 2,
    ACTIONS(72), 4,
      anon_sym_STAR,
      anon_sym_LT,
      anon_sym_GT,
      aux_sym_decimal_literal_token1,
    ACTIONS(70), 25,
      ts_builtin_sym_end,
      anon_sym_DASH,
      anon_sym_not,
      anon_sym_and,
      anon_sym_or,
      anon_sym_AMP,
      anon_sym_PIPE,
      anon_sym_CARET,
      anon_sym_PLUS,
      anon_sym_SLASH,
      anon_sym_STAR_STAR,
      anon_sym_PERCENT,
      anon_sym_GT_GT,
      anon_sym_LT_LT,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      sym_binary_literal,
      sym_octal_literal,
      sym_hex_literal,
      sym_character_literal,
      sym__string_sigil,
      sym__boolean_true,
      sym__boolean_false,
  [270] = 2,
    ACTIONS(76), 4,
      anon_sym_STAR,
      anon_sym_LT,
      anon_sym_GT,
      aux_sym_decimal_literal_token1,
    ACTIONS(74), 25,
      ts_builtin_sym_end,
      anon_sym_DASH,
      anon_sym_not,
      anon_sym_and,
      anon_sym_or,
      anon_sym_AMP,
      anon_sym_PIPE,
      anon_sym_CARET,
      anon_sym_PLUS,
      anon_sym_SLASH,
      anon_sym_STAR_STAR,
      anon_sym_PERCENT,
      anon_sym_GT_GT,
      anon_sym_LT_LT,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      sym_binary_literal,
      sym_octal_literal,
      sym_hex_literal,
      sym_character_literal,
      sym__string_sigil,
      sym__boolean_true,
      sym__boolean_false,
  [304] = 13,
    ACTIONS(44), 1,
      anon_sym_AMP,
    ACTIONS(46), 1,
      anon_sym_PIPE,
    ACTIONS(48), 1,
      anon_sym_CARET,
    ACTIONS(50), 1,
      anon_sym_STAR,
    ACTIONS(80), 1,
      anon_sym_and,
    ACTIONS(82), 1,
      anon_sym_or,
    ACTIONS(84), 1,
      aux_sym_decimal_literal_token1,
    ACTIONS(42), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(54), 2,
      anon_sym_GT_GT,
      anon_sym_LT_LT,
    ACTIONS(56), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(52), 3,
      anon_sym_SLASH,
      anon_sym_STAR_STAR,
      anon_sym_PERCENT,
    ACTIONS(58), 4,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(78), 9,
      ts_builtin_sym_end,
      anon_sym_not,
      sym_binary_literal,
      sym_octal_literal,
      sym_hex_literal,
      sym_character_literal,
      sym__string_sigil,
      sym__boolean_true,
      sym__boolean_false,
  [360] = 2,
    ACTIONS(88), 4,
      anon_sym_STAR,
      anon_sym_LT,
      anon_sym_GT,
      aux_sym_decimal_literal_token1,
    ACTIONS(86), 25,
      ts_builtin_sym_end,
      anon_sym_DASH,
      anon_sym_not,
      anon_sym_and,
      anon_sym_or,
      anon_sym_AMP,
      anon_sym_PIPE,
      anon_sym_CARET,
      anon_sym_PLUS,
      anon_sym_SLASH,
      anon_sym_STAR_STAR,
      anon_sym_PERCENT,
      anon_sym_GT_GT,
      anon_sym_LT_LT,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      sym_binary_literal,
      sym_octal_literal,
      sym_hex_literal,
      sym_character_literal,
      sym__string_sigil,
      sym__boolean_true,
      sym__boolean_false,
  [394] = 2,
    ACTIONS(92), 4,
      anon_sym_STAR,
      anon_sym_LT,
      anon_sym_GT,
      aux_sym_decimal_literal_token1,
    ACTIONS(90), 25,
      ts_builtin_sym_end,
      anon_sym_DASH,
      anon_sym_not,
      anon_sym_and,
      anon_sym_or,
      anon_sym_AMP,
      anon_sym_PIPE,
      anon_sym_CARET,
      anon_sym_PLUS,
      anon_sym_SLASH,
      anon_sym_STAR_STAR,
      anon_sym_PERCENT,
      anon_sym_GT_GT,
      anon_sym_LT_LT,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      sym_binary_literal,
      sym_octal_literal,
      sym_hex_literal,
      sym_character_literal,
      sym__string_sigil,
      sym__boolean_true,
      sym__boolean_false,
  [428] = 9,
    ACTIONS(44), 1,
      anon_sym_AMP,
    ACTIONS(46), 1,
      anon_sym_PIPE,
    ACTIONS(48), 1,
      anon_sym_CARET,
    ACTIONS(50), 1,
      anon_sym_STAR,
    ACTIONS(42), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(54), 2,
      anon_sym_GT_GT,
      anon_sym_LT_LT,
    ACTIONS(52), 3,
      anon_sym_SLASH,
      anon_sym_STAR_STAR,
      anon_sym_PERCENT,
    ACTIONS(60), 3,
      anon_sym_LT,
      anon_sym_GT,
      aux_sym_decimal_literal_token1,
    ACTIONS(40), 15,
      ts_builtin_sym_end,
      anon_sym_not,
      anon_sym_and,
      anon_sym_or,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      sym_binary_literal,
      sym_octal_literal,
      sym_hex_literal,
      sym_character_literal,
      sym__string_sigil,
      sym__boolean_true,
      sym__boolean_false,
  [476] = 5,
    ACTIONS(50), 1,
      anon_sym_STAR,
    ACTIONS(42), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(52), 3,
      anon_sym_SLASH,
      anon_sym_STAR_STAR,
      anon_sym_PERCENT,
    ACTIONS(60), 3,
      anon_sym_LT,
      anon_sym_GT,
      aux_sym_decimal_literal_token1,
    ACTIONS(40), 20,
      ts_builtin_sym_end,
      anon_sym_not,
      anon_sym_and,
      anon_sym_or,
      anon_sym_AMP,
      anon_sym_PIPE,
      anon_sym_CARET,
      anon_sym_GT_GT,
      anon_sym_LT_LT,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      sym_binary_literal,
      sym_octal_literal,
      sym_hex_literal,
      sym_character_literal,
      sym__string_sigil,
      sym__boolean_true,
      sym__boolean_false,
  [516] = 2,
    ACTIONS(96), 4,
      anon_sym_STAR,
      anon_sym_LT,
      anon_sym_GT,
      aux_sym_decimal_literal_token1,
    ACTIONS(94), 25,
      ts_builtin_sym_end,
      anon_sym_DASH,
      anon_sym_not,
      anon_sym_and,
      anon_sym_or,
      anon_sym_AMP,
      anon_sym_PIPE,
      anon_sym_CARET,
      anon_sym_PLUS,
      anon_sym_SLASH,
      anon_sym_STAR_STAR,
      anon_sym_PERCENT,
      anon_sym_GT_GT,
      anon_sym_LT_LT,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      sym_binary_literal,
      sym_octal_literal,
      sym_hex_literal,
      sym_character_literal,
      sym__string_sigil,
      sym__boolean_true,
      sym__boolean_false,
  [550] = 2,
    ACTIONS(100), 4,
      anon_sym_STAR,
      anon_sym_LT,
      anon_sym_GT,
      aux_sym_decimal_literal_token1,
    ACTIONS(98), 25,
      ts_builtin_sym_end,
      anon_sym_DASH,
      anon_sym_not,
      anon_sym_and,
      anon_sym_or,
      anon_sym_AMP,
      anon_sym_PIPE,
      anon_sym_CARET,
      anon_sym_PLUS,
      anon_sym_SLASH,
      anon_sym_STAR_STAR,
      anon_sym_PERCENT,
      anon_sym_GT_GT,
      anon_sym_LT_LT,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      sym_binary_literal,
      sym_octal_literal,
      sym_hex_literal,
      sym_character_literal,
      sym__string_sigil,
      sym__boolean_true,
      sym__boolean_false,
  [584] = 2,
    ACTIONS(104), 4,
      anon_sym_STAR,
      anon_sym_LT,
      anon_sym_GT,
      aux_sym_decimal_literal_token1,
    ACTIONS(102), 25,
      ts_builtin_sym_end,
      anon_sym_DASH,
      anon_sym_not,
      anon_sym_and,
      anon_sym_or,
      anon_sym_AMP,
      anon_sym_PIPE,
      anon_sym_CARET,
      anon_sym_PLUS,
      anon_sym_SLASH,
      anon_sym_STAR_STAR,
      anon_sym_PERCENT,
      anon_sym_GT_GT,
      anon_sym_LT_LT,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      sym_binary_literal,
      sym_octal_literal,
      sym_hex_literal,
      sym_character_literal,
      sym__string_sigil,
      sym__boolean_true,
      sym__boolean_false,
  [618] = 2,
    ACTIONS(60), 4,
      anon_sym_STAR,
      anon_sym_LT,
      anon_sym_GT,
      aux_sym_decimal_literal_token1,
    ACTIONS(40), 25,
      ts_builtin_sym_end,
      anon_sym_DASH,
      anon_sym_not,
      anon_sym_and,
      anon_sym_or,
      anon_sym_AMP,
      anon_sym_PIPE,
      anon_sym_CARET,
      anon_sym_PLUS,
      anon_sym_SLASH,
      anon_sym_STAR_STAR,
      anon_sym_PERCENT,
      anon_sym_GT_GT,
      anon_sym_LT_LT,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      sym_binary_literal,
      sym_octal_literal,
      sym_hex_literal,
      sym_character_literal,
      sym__string_sigil,
      sym__boolean_true,
      sym__boolean_false,
  [652] = 7,
    ACTIONS(44), 1,
      anon_sym_AMP,
    ACTIONS(50), 1,
      anon_sym_STAR,
    ACTIONS(42), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(54), 2,
      anon_sym_GT_GT,
      anon_sym_LT_LT,
    ACTIONS(52), 3,
      anon_sym_SLASH,
      anon_sym_STAR_STAR,
      anon_sym_PERCENT,
    ACTIONS(60), 3,
      anon_sym_LT,
      anon_sym_GT,
      aux_sym_decimal_literal_token1,
    ACTIONS(40), 17,
      ts_builtin_sym_end,
      anon_sym_not,
      anon_sym_and,
      anon_sym_or,
      anon_sym_PIPE,
      anon_sym_CARET,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      sym_binary_literal,
      sym_octal_literal,
      sym_hex_literal,
      sym_character_literal,
      sym__string_sigil,
      sym__boolean_true,
      sym__boolean_false,
  [696] = 8,
    ACTIONS(44), 1,
      anon_sym_AMP,
    ACTIONS(48), 1,
      anon_sym_CARET,
    ACTIONS(50), 1,
      anon_sym_STAR,
    ACTIONS(42), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(54), 2,
      anon_sym_GT_GT,
      anon_sym_LT_LT,
    ACTIONS(52), 3,
      anon_sym_SLASH,
      anon_sym_STAR_STAR,
      anon_sym_PERCENT,
    ACTIONS(60), 3,
      anon_sym_LT,
      anon_sym_GT,
      aux_sym_decimal_literal_token1,
    ACTIONS(40), 16,
      ts_builtin_sym_end,
      anon_sym_not,
      anon_sym_and,
      anon_sym_or,
      anon_sym_PIPE,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      sym_binary_literal,
      sym_octal_literal,
      sym_hex_literal,
      sym_character_literal,
      sym__string_sigil,
      sym__boolean_true,
      sym__boolean_false,
  [742] = 6,
    ACTIONS(50), 1,
      anon_sym_STAR,
    ACTIONS(42), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(54), 2,
      anon_sym_GT_GT,
      anon_sym_LT_LT,
    ACTIONS(52), 3,
      anon_sym_SLASH,
      anon_sym_STAR_STAR,
      anon_sym_PERCENT,
    ACTIONS(60), 3,
      anon_sym_LT,
      anon_sym_GT,
      aux_sym_decimal_literal_token1,
    ACTIONS(40), 18,
      ts_builtin_sym_end,
      anon_sym_not,
      anon_sym_and,
      anon_sym_or,
      anon_sym_AMP,
      anon_sym_PIPE,
      anon_sym_CARET,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      sym_binary_literal,
      sym_octal_literal,
      sym_hex_literal,
      sym_character_literal,
      sym__string_sigil,
      sym__boolean_true,
      sym__boolean_false,
  [784] = 12,
    ACTIONS(44), 1,
      anon_sym_AMP,
    ACTIONS(46), 1,
      anon_sym_PIPE,
    ACTIONS(48), 1,
      anon_sym_CARET,
    ACTIONS(50), 1,
      anon_sym_STAR,
    ACTIONS(60), 1,
      aux_sym_decimal_literal_token1,
    ACTIONS(80), 1,
      anon_sym_and,
    ACTIONS(42), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(54), 2,
      anon_sym_GT_GT,
      anon_sym_LT_LT,
    ACTIONS(56), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(52), 3,
      anon_sym_SLASH,
      anon_sym_STAR_STAR,
      anon_sym_PERCENT,
    ACTIONS(58), 4,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(40), 10,
      ts_builtin_sym_end,
      anon_sym_not,
      anon_sym_or,
      sym_binary_literal,
      sym_octal_literal,
      sym_hex_literal,
      sym_character_literal,
      sym__string_sigil,
      sym__boolean_true,
      sym__boolean_false,
  [838] = 2,
    ACTIONS(108), 4,
      anon_sym_STAR,
      anon_sym_LT,
      anon_sym_GT,
      aux_sym_decimal_literal_token1,
    ACTIONS(106), 25,
      ts_builtin_sym_end,
      anon_sym_DASH,
      anon_sym_not,
      anon_sym_and,
      anon_sym_or,
      anon_sym_AMP,
      anon_sym_PIPE,
      anon_sym_CARET,
      anon_sym_PLUS,
      anon_sym_SLASH,
      anon_sym_STAR_STAR,
      anon_sym_PERCENT,
      anon_sym_GT_GT,
      anon_sym_LT_LT,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      sym_binary_literal,
      sym_octal_literal,
      sym_hex_literal,
      sym_character_literal,
      sym__string_sigil,
      sym__boolean_true,
      sym__boolean_false,
  [872] = 4,
    ACTIONS(50), 1,
      anon_sym_STAR,
    ACTIONS(52), 3,
      anon_sym_SLASH,
      anon_sym_STAR_STAR,
      anon_sym_PERCENT,
    ACTIONS(60), 3,
      anon_sym_LT,
      anon_sym_GT,
      aux_sym_decimal_literal_token1,
    ACTIONS(40), 22,
      ts_builtin_sym_end,
      anon_sym_DASH,
      anon_sym_not,
      anon_sym_and,
      anon_sym_or,
      anon_sym_AMP,
      anon_sym_PIPE,
      anon_sym_CARET,
      anon_sym_PLUS,
      anon_sym_GT_GT,
      anon_sym_LT_LT,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      sym_binary_literal,
      sym_octal_literal,
      sym_hex_literal,
      sym_character_literal,
      sym__string_sigil,
      sym__boolean_true,
      sym__boolean_false,
  [910] = 2,
    ACTIONS(112), 4,
      anon_sym_STAR,
      anon_sym_LT,
      anon_sym_GT,
      aux_sym_decimal_literal_token1,
    ACTIONS(110), 25,
      ts_builtin_sym_end,
      anon_sym_DASH,
      anon_sym_not,
      anon_sym_and,
      anon_sym_or,
      anon_sym_AMP,
      anon_sym_PIPE,
      anon_sym_CARET,
      anon_sym_PLUS,
      anon_sym_SLASH,
      anon_sym_STAR_STAR,
      anon_sym_PERCENT,
      anon_sym_GT_GT,
      anon_sym_LT_LT,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      sym_binary_literal,
      sym_octal_literal,
      sym_hex_literal,
      sym_character_literal,
      sym__string_sigil,
      sym__boolean_true,
      sym__boolean_false,
  [944] = 15,
    ACTIONS(114), 1,
      ts_builtin_sym_end,
    ACTIONS(116), 1,
      anon_sym_DASH,
    ACTIONS(119), 1,
      anon_sym_not,
    ACTIONS(122), 1,
      aux_sym_decimal_literal_token1,
    ACTIONS(128), 1,
      sym_character_literal,
    ACTIONS(131), 1,
      sym__string_sigil,
    STATE(6), 1,
      sym_decimal_literal,
    STATE(10), 1,
      sym_expression,
    STATE(42), 1,
      sym__decimal_literal,
    ACTIONS(134), 2,
      sym__boolean_true,
      sym__boolean_false,
    STATE(12), 2,
      sym_negation_expression,
      sym_not_expression,
    STATE(26), 2,
      sym__item,
      aux_sym_root_repeat1,
    ACTIONS(125), 3,
      sym_binary_literal,
      sym_octal_literal,
      sym_hex_literal,
    STATE(11), 4,
      sym__primary_expression,
      sym_unary_expression,
      sym_binary_expression,
      sym_literal,
    STATE(23), 4,
      sym_integer_literal,
      sym_string_literal,
      sym_boolean_literal,
      sym_float_literal,
  [1001] = 15,
    ACTIONS(5), 1,
      anon_sym_DASH,
    ACTIONS(7), 1,
      anon_sym_not,
    ACTIONS(9), 1,
      aux_sym_decimal_literal_token1,
    ACTIONS(13), 1,
      sym_character_literal,
    ACTIONS(15), 1,
      sym__string_sigil,
    ACTIONS(137), 1,
      ts_builtin_sym_end,
    STATE(6), 1,
      sym_decimal_literal,
    STATE(10), 1,
      sym_expression,
    STATE(42), 1,
      sym__decimal_literal,
    ACTIONS(17), 2,
      sym__boolean_true,
      sym__boolean_false,
    STATE(12), 2,
      sym_negation_expression,
      sym_not_expression,
    STATE(26), 2,
      sym__item,
      aux_sym_root_repeat1,
    ACTIONS(11), 3,
      sym_binary_literal,
      sym_octal_literal,
      sym_hex_literal,
    STATE(11), 4,
      sym__primary_expression,
      sym_unary_expression,
      sym_binary_expression,
      sym_literal,
    STATE(23), 4,
      sym_integer_literal,
      sym_string_literal,
      sym_boolean_literal,
      sym_float_literal,
  [1058] = 13,
    ACTIONS(5), 1,
      anon_sym_DASH,
    ACTIONS(7), 1,
      anon_sym_not,
    ACTIONS(9), 1,
      aux_sym_decimal_literal_token1,
    ACTIONS(13), 1,
      sym_character_literal,
    ACTIONS(15), 1,
      sym__string_sigil,
    STATE(6), 1,
      sym_decimal_literal,
    STATE(14), 1,
      sym_expression,
    STATE(42), 1,
      sym__decimal_literal,
    ACTIONS(17), 2,
      sym__boolean_true,
      sym__boolean_false,
    STATE(12), 2,
      sym_negation_expression,
      sym_not_expression,
    ACTIONS(11), 3,
      sym_binary_literal,
      sym_octal_literal,
      sym_hex_literal,
    STATE(11), 4,
      sym__primary_expression,
      sym_unary_expression,
      sym_binary_expression,
      sym_literal,
    STATE(23), 4,
      sym_integer_literal,
      sym_string_literal,
      sym_boolean_literal,
      sym_float_literal,
  [1108] = 13,
    ACTIONS(5), 1,
      anon_sym_DASH,
    ACTIONS(7), 1,
      anon_sym_not,
    ACTIONS(9), 1,
      aux_sym_decimal_literal_token1,
    ACTIONS(13), 1,
      sym_character_literal,
    ACTIONS(15), 1,
      sym__string_sigil,
    STATE(6), 1,
      sym_decimal_literal,
    STATE(13), 1,
      sym_expression,
    STATE(42), 1,
      sym__decimal_literal,
    ACTIONS(17), 2,
      sym__boolean_true,
      sym__boolean_false,
    STATE(12), 2,
      sym_negation_expression,
      sym_not_expression,
    ACTIONS(11), 3,
      sym_binary_literal,
      sym_octal_literal,
      sym_hex_literal,
    STATE(11), 4,
      sym__primary_expression,
      sym_unary_expression,
      sym_binary_expression,
      sym_literal,
    STATE(23), 4,
      sym_integer_literal,
      sym_string_literal,
      sym_boolean_literal,
      sym_float_literal,
  [1158] = 13,
    ACTIONS(5), 1,
      anon_sym_DASH,
    ACTIONS(7), 1,
      anon_sym_not,
    ACTIONS(9), 1,
      aux_sym_decimal_literal_token1,
    ACTIONS(13), 1,
      sym_character_literal,
    ACTIONS(15), 1,
      sym__string_sigil,
    STATE(6), 1,
      sym_decimal_literal,
    STATE(15), 1,
      sym_expression,
    STATE(42), 1,
      sym__decimal_literal,
    ACTIONS(17), 2,
      sym__boolean_true,
      sym__boolean_false,
    STATE(12), 2,
      sym_negation_expression,
      sym_not_expression,
    ACTIONS(11), 3,
      sym_binary_literal,
      sym_octal_literal,
      sym_hex_literal,
    STATE(11), 4,
      sym__primary_expression,
      sym_unary_expression,
      sym_binary_expression,
      sym_literal,
    STATE(23), 4,
      sym_integer_literal,
      sym_string_literal,
      sym_boolean_literal,
      sym_float_literal,
  [1208] = 13,
    ACTIONS(5), 1,
      anon_sym_DASH,
    ACTIONS(7), 1,
      anon_sym_not,
    ACTIONS(9), 1,
      aux_sym_decimal_literal_token1,
    ACTIONS(13), 1,
      sym_character_literal,
    ACTIONS(15), 1,
      sym__string_sigil,
    STATE(6), 1,
      sym_decimal_literal,
    STATE(18), 1,
      sym_expression,
    STATE(42), 1,
      sym__decimal_literal,
    ACTIONS(17), 2,
      sym__boolean_true,
      sym__boolean_false,
    STATE(12), 2,
      sym_negation_expression,
      sym_not_expression,
    ACTIONS(11), 3,
      sym_binary_literal,
      sym_octal_literal,
      sym_hex_literal,
    STATE(11), 4,
      sym__primary_expression,
      sym_unary_expression,
      sym_binary_expression,
      sym_literal,
    STATE(23), 4,
      sym_integer_literal,
      sym_string_literal,
      sym_boolean_literal,
      sym_float_literal,
  [1258] = 13,
    ACTIONS(5), 1,
      anon_sym_DASH,
    ACTIONS(7), 1,
      anon_sym_not,
    ACTIONS(9), 1,
      aux_sym_decimal_literal_token1,
    ACTIONS(13), 1,
      sym_character_literal,
    ACTIONS(15), 1,
      sym__string_sigil,
    STATE(6), 1,
      sym_decimal_literal,
    STATE(19), 1,
      sym_expression,
    STATE(42), 1,
      sym__decimal_literal,
    ACTIONS(17), 2,
      sym__boolean_true,
      sym__boolean_false,
    STATE(12), 2,
      sym_negation_expression,
      sym_not_expression,
    ACTIONS(11), 3,
      sym_binary_literal,
      sym_octal_literal,
      sym_hex_literal,
    STATE(11), 4,
      sym__primary_expression,
      sym_unary_expression,
      sym_binary_expression,
      sym_literal,
    STATE(23), 4,
      sym_integer_literal,
      sym_string_literal,
      sym_boolean_literal,
      sym_float_literal,
  [1308] = 13,
    ACTIONS(5), 1,
      anon_sym_DASH,
    ACTIONS(7), 1,
      anon_sym_not,
    ACTIONS(9), 1,
      aux_sym_decimal_literal_token1,
    ACTIONS(13), 1,
      sym_character_literal,
    ACTIONS(15), 1,
      sym__string_sigil,
    STATE(6), 1,
      sym_decimal_literal,
    STATE(20), 1,
      sym_expression,
    STATE(42), 1,
      sym__decimal_literal,
    ACTIONS(17), 2,
      sym__boolean_true,
      sym__boolean_false,
    STATE(12), 2,
      sym_negation_expression,
      sym_not_expression,
    ACTIONS(11), 3,
      sym_binary_literal,
      sym_octal_literal,
      sym_hex_literal,
    STATE(11), 4,
      sym__primary_expression,
      sym_unary_expression,
      sym_binary_expression,
      sym_literal,
    STATE(23), 4,
      sym_integer_literal,
      sym_string_literal,
      sym_boolean_literal,
      sym_float_literal,
  [1358] = 13,
    ACTIONS(5), 1,
      anon_sym_DASH,
    ACTIONS(7), 1,
      anon_sym_not,
    ACTIONS(9), 1,
      aux_sym_decimal_literal_token1,
    ACTIONS(13), 1,
      sym_character_literal,
    ACTIONS(15), 1,
      sym__string_sigil,
    STATE(6), 1,
      sym_decimal_literal,
    STATE(21), 1,
      sym_expression,
    STATE(42), 1,
      sym__decimal_literal,
    ACTIONS(17), 2,
      sym__boolean_true,
      sym__boolean_false,
    STATE(12), 2,
      sym_negation_expression,
      sym_not_expression,
    ACTIONS(11), 3,
      sym_binary_literal,
      sym_octal_literal,
      sym_hex_literal,
    STATE(11), 4,
      sym__primary_expression,
      sym_unary_expression,
      sym_binary_expression,
      sym_literal,
    STATE(23), 4,
      sym_integer_literal,
      sym_string_literal,
      sym_boolean_literal,
      sym_float_literal,
  [1408] = 13,
    ACTIONS(5), 1,
      anon_sym_DASH,
    ACTIONS(7), 1,
      anon_sym_not,
    ACTIONS(9), 1,
      aux_sym_decimal_literal_token1,
    ACTIONS(13), 1,
      sym_character_literal,
    ACTIONS(15), 1,
      sym__string_sigil,
    STATE(6), 1,
      sym_decimal_literal,
    STATE(22), 1,
      sym_expression,
    STATE(42), 1,
      sym__decimal_literal,
    ACTIONS(17), 2,
      sym__boolean_true,
      sym__boolean_false,
    STATE(12), 2,
      sym_negation_expression,
      sym_not_expression,
    ACTIONS(11), 3,
      sym_binary_literal,
      sym_octal_literal,
      sym_hex_literal,
    STATE(11), 4,
      sym__primary_expression,
      sym_unary_expression,
      sym_binary_expression,
      sym_literal,
    STATE(23), 4,
      sym_integer_literal,
      sym_string_literal,
      sym_boolean_literal,
      sym_float_literal,
  [1458] = 13,
    ACTIONS(5), 1,
      anon_sym_DASH,
    ACTIONS(7), 1,
      anon_sym_not,
    ACTIONS(9), 1,
      aux_sym_decimal_literal_token1,
    ACTIONS(13), 1,
      sym_character_literal,
    ACTIONS(15), 1,
      sym__string_sigil,
    STATE(5), 1,
      sym_expression,
    STATE(6), 1,
      sym_decimal_literal,
    STATE(42), 1,
      sym__decimal_literal,
    ACTIONS(17), 2,
      sym__boolean_true,
      sym__boolean_false,
    STATE(12), 2,
      sym_negation_expression,
      sym_not_expression,
    ACTIONS(11), 3,
      sym_binary_literal,
      sym_octal_literal,
      sym_hex_literal,
    STATE(11), 4,
      sym__primary_expression,
      sym_unary_expression,
      sym_binary_expression,
      sym_literal,
    STATE(23), 4,
      sym_integer_literal,
      sym_string_literal,
      sym_boolean_literal,
      sym_float_literal,
  [1508] = 13,
    ACTIONS(5), 1,
      anon_sym_DASH,
    ACTIONS(7), 1,
      anon_sym_not,
    ACTIONS(9), 1,
      aux_sym_decimal_literal_token1,
    ACTIONS(13), 1,
      sym_character_literal,
    ACTIONS(15), 1,
      sym__string_sigil,
    STATE(6), 1,
      sym_decimal_literal,
    STATE(24), 1,
      sym_expression,
    STATE(42), 1,
      sym__decimal_literal,
    ACTIONS(17), 2,
      sym__boolean_true,
      sym__boolean_false,
    STATE(12), 2,
      sym_negation_expression,
      sym_not_expression,
    ACTIONS(11), 3,
      sym_binary_literal,
      sym_octal_literal,
      sym_hex_literal,
    STATE(11), 4,
      sym__primary_expression,
      sym_unary_expression,
      sym_binary_expression,
      sym_literal,
    STATE(23), 4,
      sym_integer_literal,
      sym_string_literal,
      sym_boolean_literal,
      sym_float_literal,
  [1558] = 13,
    ACTIONS(5), 1,
      anon_sym_DASH,
    ACTIONS(7), 1,
      anon_sym_not,
    ACTIONS(9), 1,
      aux_sym_decimal_literal_token1,
    ACTIONS(13), 1,
      sym_character_literal,
    ACTIONS(15), 1,
      sym__string_sigil,
    STATE(6), 1,
      sym_decimal_literal,
    STATE(16), 1,
      sym_expression,
    STATE(42), 1,
      sym__decimal_literal,
    ACTIONS(17), 2,
      sym__boolean_true,
      sym__boolean_false,
    STATE(12), 2,
      sym_negation_expression,
      sym_not_expression,
    ACTIONS(11), 3,
      sym_binary_literal,
      sym_octal_literal,
      sym_hex_literal,
    STATE(11), 4,
      sym__primary_expression,
      sym_unary_expression,
      sym_binary_expression,
      sym_literal,
    STATE(23), 4,
      sym_integer_literal,
      sym_string_literal,
      sym_boolean_literal,
      sym_float_literal,
  [1608] = 3,
    ACTIONS(142), 1,
      sym__string_sigil,
    STATE(39), 1,
      aux_sym_string_literal_repeat1,
    ACTIONS(139), 2,
      aux_sym_string_literal_token1,
      sym_escape_sequence,
  [1619] = 3,
    ACTIONS(146), 1,
      sym__string_sigil,
    STATE(39), 1,
      aux_sym_string_literal_repeat1,
    ACTIONS(144), 2,
      aux_sym_string_literal_token1,
      sym_escape_sequence,
  [1630] = 3,
    ACTIONS(150), 1,
      sym__string_sigil,
    STATE(40), 1,
      aux_sym_string_literal_repeat1,
    ACTIONS(148), 2,
      aux_sym_string_literal_token1,
      sym_escape_sequence,
  [1641] = 1,
    ACTIONS(152), 1,
      sym__float_decimal_point,
  [1645] = 1,
    ACTIONS(154), 1,
      ts_builtin_sym_end,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 42,
  [SMALL_STATE(4)] = 79,
  [SMALL_STATE(5)] = 116,
  [SMALL_STATE(6)] = 168,
  [SMALL_STATE(7)] = 202,
  [SMALL_STATE(8)] = 236,
  [SMALL_STATE(9)] = 270,
  [SMALL_STATE(10)] = 304,
  [SMALL_STATE(11)] = 360,
  [SMALL_STATE(12)] = 394,
  [SMALL_STATE(13)] = 428,
  [SMALL_STATE(14)] = 476,
  [SMALL_STATE(15)] = 516,
  [SMALL_STATE(16)] = 550,
  [SMALL_STATE(17)] = 584,
  [SMALL_STATE(18)] = 618,
  [SMALL_STATE(19)] = 652,
  [SMALL_STATE(20)] = 696,
  [SMALL_STATE(21)] = 742,
  [SMALL_STATE(22)] = 784,
  [SMALL_STATE(23)] = 838,
  [SMALL_STATE(24)] = 872,
  [SMALL_STATE(25)] = 910,
  [SMALL_STATE(26)] = 944,
  [SMALL_STATE(27)] = 1001,
  [SMALL_STATE(28)] = 1058,
  [SMALL_STATE(29)] = 1108,
  [SMALL_STATE(30)] = 1158,
  [SMALL_STATE(31)] = 1208,
  [SMALL_STATE(32)] = 1258,
  [SMALL_STATE(33)] = 1308,
  [SMALL_STATE(34)] = 1358,
  [SMALL_STATE(35)] = 1408,
  [SMALL_STATE(36)] = 1458,
  [SMALL_STATE(37)] = 1508,
  [SMALL_STATE(38)] = 1558,
  [SMALL_STATE(39)] = 1608,
  [SMALL_STATE(40)] = 1619,
  [SMALL_STATE(41)] = 1630,
  [SMALL_STATE(42)] = 1641,
  [SMALL_STATE(43)] = 1645,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_root, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(4),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [19] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_float_literal, 2),
  [21] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_float_literal, 2),
  [23] = {.entry = {.count = 2, .reusable = false}}, REDUCE(sym_float_literal, 2), SHIFT(3),
  [26] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [28] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_float_literal, 3),
  [30] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_float_literal, 3),
  [32] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [34] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_decimal_literal, 1),
  [36] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_decimal_literal, 1),
  [38] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__decimal_literal, 1),
  [40] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_binary_expression, 3, .production_id = 1),
  [42] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [44] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [46] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [48] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [50] = {.entry = {.count = 1, .reusable = false}}, SHIFT(31),
  [52] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [54] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [56] = {.entry = {.count = 1, .reusable = false}}, SHIFT(29),
  [58] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [60] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_binary_expression, 3, .production_id = 1),
  [62] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_integer_literal, 1),
  [64] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_integer_literal, 1),
  [66] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_float_literal, 4, .production_id = 3),
  [68] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_float_literal, 4, .production_id = 3),
  [70] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_boolean_literal, 1),
  [72] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_boolean_literal, 1),
  [74] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_float_literal, 3, .production_id = 2),
  [76] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_float_literal, 3, .production_id = 2),
  [78] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__item, 1),
  [80] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [82] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [84] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__item, 1),
  [86] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_expression, 1),
  [88] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_expression, 1),
  [90] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_unary_expression, 1),
  [92] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_unary_expression, 1),
  [94] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_negation_expression, 2),
  [96] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_negation_expression, 2),
  [98] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_not_expression, 2),
  [100] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_not_expression, 2),
  [102] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_literal, 2),
  [104] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_string_literal, 2),
  [106] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_literal, 1),
  [108] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_literal, 1),
  [110] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_literal, 3),
  [112] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_string_literal, 3),
  [114] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_root_repeat1, 2),
  [116] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_root_repeat1, 2), SHIFT_REPEAT(30),
  [119] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_root_repeat1, 2), SHIFT_REPEAT(38),
  [122] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_root_repeat1, 2), SHIFT_REPEAT(4),
  [125] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_root_repeat1, 2), SHIFT_REPEAT(6),
  [128] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_root_repeat1, 2), SHIFT_REPEAT(23),
  [131] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_root_repeat1, 2), SHIFT_REPEAT(41),
  [134] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_root_repeat1, 2), SHIFT_REPEAT(8),
  [137] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_root, 1),
  [139] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_string_literal_repeat1, 2), SHIFT_REPEAT(39),
  [142] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_string_literal_repeat1, 2),
  [144] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [146] = {.entry = {.count = 1, .reusable = false}}, SHIFT(25),
  [148] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [150] = {.entry = {.count = 1, .reusable = false}}, SHIFT(17),
  [152] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [154] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
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
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
