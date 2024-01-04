#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 25
#define LARGE_STATE_COUNT 6
#define SYMBOL_COUNT 43
#define ALIAS_COUNT 0
#define TOKEN_COUNT 27
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 1
#define MAX_ALIAS_SEQUENCE_LENGTH 4
#define PRODUCTION_ID_COUNT 3

enum {
  sym__minus_operator = 1,
  sym__not_keyword = 2,
  aux_sym_decimal_literal_token1 = 3,
  sym_binary_literal = 4,
  sym_octal_literal = 5,
  sym_hex_literal = 6,
  sym_character_literal = 7,
  anon_sym_BSLASH_SQUOTE = 8,
  anon_sym_BSLASH_DQUOTE = 9,
  anon_sym_BSLASHx = 10,
  aux_sym_ascii_escape_token1 = 11,
  aux_sym_ascii_escape_token2 = 12,
  anon_sym_BSLASHn = 13,
  anon_sym_BSLASHr = 14,
  anon_sym_BSLASHt = 15,
  anon_sym_BSLASH_BSLASH = 16,
  anon_sym_BSLASH0 = 17,
  aux_sym_unicode_escape_token1 = 18,
  aux_sym_string_literal_token1 = 19,
  sym__string_sigil = 20,
  sym_escape_sequence = 21,
  sym__string_continuation = 22,
  sym__boolean_true = 23,
  sym__boolean_false = 24,
  sym_float_exponent = 25,
  sym__float_decimal_point = 26,
  sym_root = 27,
  sym__item = 28,
  sym_expression = 29,
  sym__primary_expression = 30,
  sym_unary_expression = 31,
  sym_negation_expression = 32,
  sym_not_expression = 33,
  sym_literal = 34,
  sym_integer_literal = 35,
  sym_decimal_literal = 36,
  sym_string_literal = 37,
  sym_boolean_literal = 38,
  sym__decimal_literal = 39,
  sym_float_literal = 40,
  aux_sym_root_repeat1 = 41,
  aux_sym_string_literal_repeat1 = 42,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym__minus_operator] = "_minus_operator",
  [sym__not_keyword] = "_not_keyword",
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
  [sym__minus_operator] = sym__minus_operator,
  [sym__not_keyword] = sym__not_keyword,
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
  [sym__minus_operator] = {
    .visible = false,
    .named = true,
  },
  [sym__not_keyword] = {
    .visible = false,
    .named = true,
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
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_exponent] = "exponent",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 1},
  [2] = {.index = 1, .length = 1},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_exponent, 2},
  [1] =
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
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(31);
      if (lookahead == '"') ADVANCE(68);
      if (lookahead == '\'') ADVANCE(4);
      if (lookahead == '-') ADVANCE(32);
      if (lookahead == '.') ADVANCE(79);
      if (lookahead == '0') ADVANCE(36);
      if (lookahead == '\\') ADVANCE(45);
      if (lookahead == 'f') ADVANCE(47);
      if (lookahead == 'n') ADVANCE(14);
      if (lookahead == 't') ADVANCE(15);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(46);
      if (lookahead == '8' ||
          lookahead == '9') ADVANCE(34);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      if (('1' <= lookahead && lookahead <= '7')) ADVANCE(34);
      if (('A' <= lookahead && lookahead <= 'd')) ADVANCE(44);
      END_STATE();
    case 1:
      if (lookahead == '\n') SKIP(2)
      if (lookahead == '"') ADVANCE(68);
      if (lookahead == '\\') ADVANCE(20);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(67);
      if (lookahead != 0) ADVANCE(66);
      END_STATE();
    case 2:
      if (lookahead == '\n') SKIP(2)
      if (lookahead == '"') ADVANCE(68);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(67);
      if (lookahead != 0 &&
          lookahead != '\\') ADVANCE(66);
      END_STATE();
    case 3:
      if (lookahead == '\'') ADVANCE(40);
      END_STATE();
    case 4:
      if (lookahead == '\'') ADVANCE(40);
      if (lookahead == '\\') ADVANCE(18);
      if (lookahead != 0) ADVANCE(3);
      END_STATE();
    case 5:
      if (lookahead == '_') ADVANCE(5);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(38);
      END_STATE();
    case 6:
      if (lookahead == '_') ADVANCE(6);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(39);
      END_STATE();
    case 7:
      if (lookahead == '_') ADVANCE(8);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(8);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(78);
      END_STATE();
    case 8:
      if (lookahead == '_') ADVANCE(8);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(78);
      END_STATE();
    case 9:
      if (lookahead == '_') ADVANCE(9);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(37);
      END_STATE();
    case 10:
      if (lookahead == 'a') ADVANCE(13);
      END_STATE();
    case 11:
      if (lookahead == 'e') ADVANCE(76);
      END_STATE();
    case 12:
      if (lookahead == 'e') ADVANCE(77);
      END_STATE();
    case 13:
      if (lookahead == 'l') ADVANCE(16);
      END_STATE();
    case 14:
      if (lookahead == 'o') ADVANCE(17);
      END_STATE();
    case 15:
      if (lookahead == 'r') ADVANCE(19);
      END_STATE();
    case 16:
      if (lookahead == 's') ADVANCE(12);
      END_STATE();
    case 17:
      if (lookahead == 't') ADVANCE(33);
      END_STATE();
    case 18:
      if (lookahead == 'u') ADVANCE(21);
      if (lookahead == 'x') ADVANCE(28);
      if (lookahead != 0) ADVANCE(3);
      END_STATE();
    case 19:
      if (lookahead == 'u') ADVANCE(11);
      END_STATE();
    case 20:
      if (lookahead == 'u') ADVANCE(27);
      if (lookahead == 'x') ADVANCE(29);
      if (lookahead != 0) ADVANCE(69);
      END_STATE();
    case 21:
      if (lookahead == '{') ADVANCE(25);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(24);
      END_STATE();
    case 22:
      if (lookahead == '}') ADVANCE(3);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(22);
      END_STATE();
    case 23:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(3);
      END_STATE();
    case 24:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(28);
      END_STATE();
    case 25:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(22);
      END_STATE();
    case 26:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(69);
      END_STATE();
    case 27:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(74);
      END_STATE();
    case 28:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(23);
      END_STATE();
    case 29:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(26);
      END_STATE();
    case 30:
      if (eof) ADVANCE(31);
      if (lookahead == '"') ADVANCE(68);
      if (lookahead == '\'') ADVANCE(4);
      if (lookahead == '-') ADVANCE(32);
      if (lookahead == '.') ADVANCE(79);
      if (lookahead == '0') ADVANCE(35);
      if (lookahead == 'f') ADVANCE(10);
      if (lookahead == 'n') ADVANCE(14);
      if (lookahead == 't') ADVANCE(15);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(7);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(30)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(34);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(sym__minus_operator);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(sym__not_keyword);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(aux_sym_decimal_literal_token1);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(34);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(aux_sym_decimal_literal_token1);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(34);
      if (lookahead == 'b') ADVANCE(9);
      if (lookahead == 'o') ADVANCE(5);
      if (lookahead == 'x') ADVANCE(6);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(aux_sym_decimal_literal_token1);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(34);
      if (lookahead == 'o') ADVANCE(5);
      if (lookahead == 'x') ADVANCE(6);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(sym_binary_literal);
      if (lookahead == '_') ADVANCE(37);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(37);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(sym_octal_literal);
      if (lookahead == '_') ADVANCE(38);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(38);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(sym_hex_literal);
      if (lookahead == '_') ADVANCE(39);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(39);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(sym_character_literal);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(anon_sym_BSLASH_SQUOTE);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(anon_sym_BSLASH_DQUOTE);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(anon_sym_BSLASHx);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(aux_sym_ascii_escape_token2);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(aux_sym_ascii_escape_token2);
      if (lookahead == '\n') ADVANCE(75);
      if (lookahead == '"') ADVANCE(42);
      if (lookahead == '\'') ADVANCE(41);
      if (lookahead == '0') ADVANCE(52);
      if (lookahead == '\\') ADVANCE(51);
      if (lookahead == 'n') ADVANCE(48);
      if (lookahead == 'r') ADVANCE(49);
      if (lookahead == 't') ADVANCE(50);
      if (lookahead == 'u') ADVANCE(65);
      if (lookahead == 'x') ADVANCE(43);
      END_STATE();
    case 46:
      ACCEPT_TOKEN(aux_sym_ascii_escape_token2);
      if (lookahead == '_') ADVANCE(8);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(8);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(78);
      END_STATE();
    case 47:
      ACCEPT_TOKEN(aux_sym_ascii_escape_token2);
      if (lookahead == 'a') ADVANCE(13);
      END_STATE();
    case 48:
      ACCEPT_TOKEN(anon_sym_BSLASHn);
      END_STATE();
    case 49:
      ACCEPT_TOKEN(anon_sym_BSLASHr);
      END_STATE();
    case 50:
      ACCEPT_TOKEN(anon_sym_BSLASHt);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(anon_sym_BSLASH_BSLASH);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(anon_sym_BSLASH0);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(aux_sym_unicode_escape_token1);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(aux_sym_unicode_escape_token1);
      if (lookahead == '_') ADVANCE(54);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(aux_sym_unicode_escape_token1);
      if (lookahead == '_') ADVANCE(54);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(53);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(aux_sym_unicode_escape_token1);
      if (lookahead == '_') ADVANCE(56);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(53);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(aux_sym_unicode_escape_token1);
      if (lookahead == '_') ADVANCE(56);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(55);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(aux_sym_unicode_escape_token1);
      if (lookahead == '_') ADVANCE(58);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(55);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(aux_sym_unicode_escape_token1);
      if (lookahead == '_') ADVANCE(58);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(57);
      END_STATE();
    case 60:
      ACCEPT_TOKEN(aux_sym_unicode_escape_token1);
      if (lookahead == '_') ADVANCE(60);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(57);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(aux_sym_unicode_escape_token1);
      if (lookahead == '_') ADVANCE(60);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(59);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(aux_sym_unicode_escape_token1);
      if (lookahead == '_') ADVANCE(62);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(59);
      END_STATE();
    case 63:
      ACCEPT_TOKEN(aux_sym_unicode_escape_token1);
      if (lookahead == '_') ADVANCE(62);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(61);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(aux_sym_unicode_escape_token1);
      if (lookahead == '_') ADVANCE(64);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(61);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(aux_sym_unicode_escape_token1);
      if (lookahead == '_') ADVANCE(64);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(63);
      END_STATE();
    case 66:
      ACCEPT_TOKEN(aux_sym_string_literal_token1);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(aux_sym_string_literal_token1);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(67);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '"' &&
          lookahead != '\\') ADVANCE(66);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(sym__string_sigil);
      END_STATE();
    case 69:
      ACCEPT_TOKEN(sym_escape_sequence);
      END_STATE();
    case 70:
      ACCEPT_TOKEN(sym_escape_sequence);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(69);
      END_STATE();
    case 71:
      ACCEPT_TOKEN(sym_escape_sequence);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(70);
      END_STATE();
    case 72:
      ACCEPT_TOKEN(sym_escape_sequence);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(71);
      END_STATE();
    case 73:
      ACCEPT_TOKEN(sym_escape_sequence);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(72);
      END_STATE();
    case 74:
      ACCEPT_TOKEN(sym_escape_sequence);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(73);
      END_STATE();
    case 75:
      ACCEPT_TOKEN(sym__string_continuation);
      END_STATE();
    case 76:
      ACCEPT_TOKEN(sym__boolean_true);
      END_STATE();
    case 77:
      ACCEPT_TOKEN(sym__boolean_false);
      END_STATE();
    case 78:
      ACCEPT_TOKEN(sym_float_exponent);
      if (lookahead == '_') ADVANCE(78);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(78);
      END_STATE();
    case 79:
      ACCEPT_TOKEN(sym__float_decimal_point);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 30},
  [2] = {.lex_state = 30},
  [3] = {.lex_state = 30},
  [4] = {.lex_state = 30},
  [5] = {.lex_state = 30},
  [6] = {.lex_state = 30},
  [7] = {.lex_state = 30},
  [8] = {.lex_state = 30},
  [9] = {.lex_state = 30},
  [10] = {.lex_state = 30},
  [11] = {.lex_state = 30},
  [12] = {.lex_state = 30},
  [13] = {.lex_state = 30},
  [14] = {.lex_state = 30},
  [15] = {.lex_state = 30},
  [16] = {.lex_state = 30},
  [17] = {.lex_state = 30},
  [18] = {.lex_state = 30},
  [19] = {.lex_state = 30},
  [20] = {.lex_state = 1},
  [21] = {.lex_state = 1},
  [22] = {.lex_state = 1},
  [23] = {.lex_state = 0},
  [24] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym__minus_operator] = ACTIONS(1),
    [sym__not_keyword] = ACTIONS(1),
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
    [sym_root] = STATE(23),
    [sym__item] = STATE(2),
    [sym_expression] = STATE(2),
    [sym__primary_expression] = STATE(10),
    [sym_unary_expression] = STATE(10),
    [sym_negation_expression] = STATE(11),
    [sym_not_expression] = STATE(11),
    [sym_literal] = STATE(10),
    [sym_integer_literal] = STATE(9),
    [sym_decimal_literal] = STATE(15),
    [sym_string_literal] = STATE(9),
    [sym_boolean_literal] = STATE(9),
    [sym__decimal_literal] = STATE(24),
    [sym_float_literal] = STATE(9),
    [aux_sym_root_repeat1] = STATE(2),
    [ts_builtin_sym_end] = ACTIONS(3),
    [sym__minus_operator] = ACTIONS(5),
    [sym__not_keyword] = ACTIONS(7),
    [aux_sym_decimal_literal_token1] = ACTIONS(9),
    [sym_binary_literal] = ACTIONS(11),
    [sym_octal_literal] = ACTIONS(11),
    [sym_hex_literal] = ACTIONS(11),
    [sym_character_literal] = ACTIONS(13),
    [sym__string_sigil] = ACTIONS(15),
    [sym__boolean_true] = ACTIONS(17),
    [sym__boolean_false] = ACTIONS(17),
  },
  [2] = {
    [sym__item] = STATE(3),
    [sym_expression] = STATE(3),
    [sym__primary_expression] = STATE(10),
    [sym_unary_expression] = STATE(10),
    [sym_negation_expression] = STATE(11),
    [sym_not_expression] = STATE(11),
    [sym_literal] = STATE(10),
    [sym_integer_literal] = STATE(9),
    [sym_decimal_literal] = STATE(15),
    [sym_string_literal] = STATE(9),
    [sym_boolean_literal] = STATE(9),
    [sym__decimal_literal] = STATE(24),
    [sym_float_literal] = STATE(9),
    [aux_sym_root_repeat1] = STATE(3),
    [ts_builtin_sym_end] = ACTIONS(19),
    [sym__minus_operator] = ACTIONS(5),
    [sym__not_keyword] = ACTIONS(7),
    [aux_sym_decimal_literal_token1] = ACTIONS(9),
    [sym_binary_literal] = ACTIONS(11),
    [sym_octal_literal] = ACTIONS(11),
    [sym_hex_literal] = ACTIONS(11),
    [sym_character_literal] = ACTIONS(13),
    [sym__string_sigil] = ACTIONS(15),
    [sym__boolean_true] = ACTIONS(17),
    [sym__boolean_false] = ACTIONS(17),
  },
  [3] = {
    [sym__item] = STATE(3),
    [sym_expression] = STATE(3),
    [sym__primary_expression] = STATE(10),
    [sym_unary_expression] = STATE(10),
    [sym_negation_expression] = STATE(11),
    [sym_not_expression] = STATE(11),
    [sym_literal] = STATE(10),
    [sym_integer_literal] = STATE(9),
    [sym_decimal_literal] = STATE(15),
    [sym_string_literal] = STATE(9),
    [sym_boolean_literal] = STATE(9),
    [sym__decimal_literal] = STATE(24),
    [sym_float_literal] = STATE(9),
    [aux_sym_root_repeat1] = STATE(3),
    [ts_builtin_sym_end] = ACTIONS(21),
    [sym__minus_operator] = ACTIONS(23),
    [sym__not_keyword] = ACTIONS(26),
    [aux_sym_decimal_literal_token1] = ACTIONS(29),
    [sym_binary_literal] = ACTIONS(32),
    [sym_octal_literal] = ACTIONS(32),
    [sym_hex_literal] = ACTIONS(32),
    [sym_character_literal] = ACTIONS(35),
    [sym__string_sigil] = ACTIONS(38),
    [sym__boolean_true] = ACTIONS(41),
    [sym__boolean_false] = ACTIONS(41),
  },
  [4] = {
    [sym_expression] = STATE(12),
    [sym__primary_expression] = STATE(10),
    [sym_unary_expression] = STATE(10),
    [sym_negation_expression] = STATE(11),
    [sym_not_expression] = STATE(11),
    [sym_literal] = STATE(10),
    [sym_integer_literal] = STATE(9),
    [sym_decimal_literal] = STATE(15),
    [sym_string_literal] = STATE(9),
    [sym_boolean_literal] = STATE(9),
    [sym__decimal_literal] = STATE(24),
    [sym_float_literal] = STATE(9),
    [sym__minus_operator] = ACTIONS(5),
    [sym__not_keyword] = ACTIONS(7),
    [aux_sym_decimal_literal_token1] = ACTIONS(9),
    [sym_binary_literal] = ACTIONS(11),
    [sym_octal_literal] = ACTIONS(11),
    [sym_hex_literal] = ACTIONS(11),
    [sym_character_literal] = ACTIONS(13),
    [sym__string_sigil] = ACTIONS(15),
    [sym__boolean_true] = ACTIONS(17),
    [sym__boolean_false] = ACTIONS(17),
  },
  [5] = {
    [sym_expression] = STATE(13),
    [sym__primary_expression] = STATE(10),
    [sym_unary_expression] = STATE(10),
    [sym_negation_expression] = STATE(11),
    [sym_not_expression] = STATE(11),
    [sym_literal] = STATE(10),
    [sym_integer_literal] = STATE(9),
    [sym_decimal_literal] = STATE(15),
    [sym_string_literal] = STATE(9),
    [sym_boolean_literal] = STATE(9),
    [sym__decimal_literal] = STATE(24),
    [sym_float_literal] = STATE(9),
    [sym__minus_operator] = ACTIONS(5),
    [sym__not_keyword] = ACTIONS(7),
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
  [0] = 4,
    ACTIONS(46), 1,
      aux_sym_decimal_literal_token1,
    ACTIONS(49), 1,
      sym_float_exponent,
    STATE(8), 1,
      sym__decimal_literal,
    ACTIONS(44), 10,
      ts_builtin_sym_end,
      sym__minus_operator,
      sym__not_keyword,
      sym_binary_literal,
      sym_octal_literal,
      sym_hex_literal,
      sym_character_literal,
      sym__string_sigil,
      sym__boolean_true,
      sym__boolean_false,
  [22] = 3,
    ACTIONS(53), 1,
      aux_sym_decimal_literal_token1,
    ACTIONS(55), 1,
      sym__float_decimal_point,
    ACTIONS(51), 10,
      ts_builtin_sym_end,
      sym__minus_operator,
      sym__not_keyword,
      sym_binary_literal,
      sym_octal_literal,
      sym_hex_literal,
      sym_character_literal,
      sym__string_sigil,
      sym__boolean_true,
      sym__boolean_false,
  [41] = 3,
    ACTIONS(59), 1,
      aux_sym_decimal_literal_token1,
    ACTIONS(61), 1,
      sym_float_exponent,
    ACTIONS(57), 10,
      ts_builtin_sym_end,
      sym__minus_operator,
      sym__not_keyword,
      sym_binary_literal,
      sym_octal_literal,
      sym_hex_literal,
      sym_character_literal,
      sym__string_sigil,
      sym__boolean_true,
      sym__boolean_false,
  [60] = 2,
    ACTIONS(65), 1,
      aux_sym_decimal_literal_token1,
    ACTIONS(63), 10,
      ts_builtin_sym_end,
      sym__minus_operator,
      sym__not_keyword,
      sym_binary_literal,
      sym_octal_literal,
      sym_hex_literal,
      sym_character_literal,
      sym__string_sigil,
      sym__boolean_true,
      sym__boolean_false,
  [76] = 2,
    ACTIONS(69), 1,
      aux_sym_decimal_literal_token1,
    ACTIONS(67), 10,
      ts_builtin_sym_end,
      sym__minus_operator,
      sym__not_keyword,
      sym_binary_literal,
      sym_octal_literal,
      sym_hex_literal,
      sym_character_literal,
      sym__string_sigil,
      sym__boolean_true,
      sym__boolean_false,
  [92] = 2,
    ACTIONS(73), 1,
      aux_sym_decimal_literal_token1,
    ACTIONS(71), 10,
      ts_builtin_sym_end,
      sym__minus_operator,
      sym__not_keyword,
      sym_binary_literal,
      sym_octal_literal,
      sym_hex_literal,
      sym_character_literal,
      sym__string_sigil,
      sym__boolean_true,
      sym__boolean_false,
  [108] = 2,
    ACTIONS(77), 1,
      aux_sym_decimal_literal_token1,
    ACTIONS(75), 10,
      ts_builtin_sym_end,
      sym__minus_operator,
      sym__not_keyword,
      sym_binary_literal,
      sym_octal_literal,
      sym_hex_literal,
      sym_character_literal,
      sym__string_sigil,
      sym__boolean_true,
      sym__boolean_false,
  [124] = 2,
    ACTIONS(81), 1,
      aux_sym_decimal_literal_token1,
    ACTIONS(79), 10,
      ts_builtin_sym_end,
      sym__minus_operator,
      sym__not_keyword,
      sym_binary_literal,
      sym_octal_literal,
      sym_hex_literal,
      sym_character_literal,
      sym__string_sigil,
      sym__boolean_true,
      sym__boolean_false,
  [140] = 2,
    ACTIONS(85), 1,
      aux_sym_decimal_literal_token1,
    ACTIONS(83), 10,
      ts_builtin_sym_end,
      sym__minus_operator,
      sym__not_keyword,
      sym_binary_literal,
      sym_octal_literal,
      sym_hex_literal,
      sym_character_literal,
      sym__string_sigil,
      sym__boolean_true,
      sym__boolean_false,
  [156] = 2,
    ACTIONS(89), 1,
      aux_sym_decimal_literal_token1,
    ACTIONS(87), 10,
      ts_builtin_sym_end,
      sym__minus_operator,
      sym__not_keyword,
      sym_binary_literal,
      sym_octal_literal,
      sym_hex_literal,
      sym_character_literal,
      sym__string_sigil,
      sym__boolean_true,
      sym__boolean_false,
  [172] = 2,
    ACTIONS(93), 1,
      aux_sym_decimal_literal_token1,
    ACTIONS(91), 10,
      ts_builtin_sym_end,
      sym__minus_operator,
      sym__not_keyword,
      sym_binary_literal,
      sym_octal_literal,
      sym_hex_literal,
      sym_character_literal,
      sym__string_sigil,
      sym__boolean_true,
      sym__boolean_false,
  [188] = 2,
    ACTIONS(97), 1,
      aux_sym_decimal_literal_token1,
    ACTIONS(95), 10,
      ts_builtin_sym_end,
      sym__minus_operator,
      sym__not_keyword,
      sym_binary_literal,
      sym_octal_literal,
      sym_hex_literal,
      sym_character_literal,
      sym__string_sigil,
      sym__boolean_true,
      sym__boolean_false,
  [204] = 2,
    ACTIONS(101), 1,
      aux_sym_decimal_literal_token1,
    ACTIONS(99), 10,
      ts_builtin_sym_end,
      sym__minus_operator,
      sym__not_keyword,
      sym_binary_literal,
      sym_octal_literal,
      sym_hex_literal,
      sym_character_literal,
      sym__string_sigil,
      sym__boolean_true,
      sym__boolean_false,
  [220] = 2,
    ACTIONS(105), 1,
      aux_sym_decimal_literal_token1,
    ACTIONS(103), 10,
      ts_builtin_sym_end,
      sym__minus_operator,
      sym__not_keyword,
      sym_binary_literal,
      sym_octal_literal,
      sym_hex_literal,
      sym_character_literal,
      sym__string_sigil,
      sym__boolean_true,
      sym__boolean_false,
  [236] = 3,
    ACTIONS(109), 1,
      sym__string_sigil,
    STATE(21), 1,
      aux_sym_string_literal_repeat1,
    ACTIONS(107), 2,
      aux_sym_string_literal_token1,
      sym_escape_sequence,
  [247] = 3,
    ACTIONS(114), 1,
      sym__string_sigil,
    STATE(21), 1,
      aux_sym_string_literal_repeat1,
    ACTIONS(111), 2,
      aux_sym_string_literal_token1,
      sym_escape_sequence,
  [258] = 3,
    ACTIONS(118), 1,
      sym__string_sigil,
    STATE(20), 1,
      aux_sym_string_literal_repeat1,
    ACTIONS(116), 2,
      aux_sym_string_literal_token1,
      sym_escape_sequence,
  [269] = 1,
    ACTIONS(120), 1,
      ts_builtin_sym_end,
  [273] = 1,
    ACTIONS(122), 1,
      sym__float_decimal_point,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(6)] = 0,
  [SMALL_STATE(7)] = 22,
  [SMALL_STATE(8)] = 41,
  [SMALL_STATE(9)] = 60,
  [SMALL_STATE(10)] = 76,
  [SMALL_STATE(11)] = 92,
  [SMALL_STATE(12)] = 108,
  [SMALL_STATE(13)] = 124,
  [SMALL_STATE(14)] = 140,
  [SMALL_STATE(15)] = 156,
  [SMALL_STATE(16)] = 172,
  [SMALL_STATE(17)] = 188,
  [SMALL_STATE(18)] = 204,
  [SMALL_STATE(19)] = 220,
  [SMALL_STATE(20)] = 236,
  [SMALL_STATE(21)] = 247,
  [SMALL_STATE(22)] = 258,
  [SMALL_STATE(23)] = 269,
  [SMALL_STATE(24)] = 273,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_root, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(7),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [19] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_root, 1),
  [21] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_root_repeat1, 2),
  [23] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_root_repeat1, 2), SHIFT_REPEAT(4),
  [26] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_root_repeat1, 2), SHIFT_REPEAT(5),
  [29] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_root_repeat1, 2), SHIFT_REPEAT(7),
  [32] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_root_repeat1, 2), SHIFT_REPEAT(15),
  [35] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_root_repeat1, 2), SHIFT_REPEAT(9),
  [38] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_root_repeat1, 2), SHIFT_REPEAT(22),
  [41] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_root_repeat1, 2), SHIFT_REPEAT(16),
  [44] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_float_literal, 2),
  [46] = {.entry = {.count = 2, .reusable = false}}, REDUCE(sym_float_literal, 2), SHIFT(8),
  [49] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [51] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_decimal_literal, 1),
  [53] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_decimal_literal, 1),
  [55] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__decimal_literal, 1),
  [57] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_float_literal, 3),
  [59] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_float_literal, 3),
  [61] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [63] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_literal, 1),
  [65] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_literal, 1),
  [67] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_expression, 1),
  [69] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_expression, 1),
  [71] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_unary_expression, 1),
  [73] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_unary_expression, 1),
  [75] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_negation_expression, 2),
  [77] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_negation_expression, 2),
  [79] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_not_expression, 2),
  [81] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_not_expression, 2),
  [83] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_literal, 2),
  [85] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_string_literal, 2),
  [87] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_integer_literal, 1),
  [89] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_integer_literal, 1),
  [91] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_boolean_literal, 1),
  [93] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_boolean_literal, 1),
  [95] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_literal, 3),
  [97] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_string_literal, 3),
  [99] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_float_literal, 3, .production_id = 1),
  [101] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_float_literal, 3, .production_id = 1),
  [103] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_float_literal, 4, .production_id = 2),
  [105] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_float_literal, 4, .production_id = 2),
  [107] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [109] = {.entry = {.count = 1, .reusable = false}}, SHIFT(17),
  [111] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_string_literal_repeat1, 2), SHIFT_REPEAT(21),
  [114] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_string_literal_repeat1, 2),
  [116] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [118] = {.entry = {.count = 1, .reusable = false}}, SHIFT(14),
  [120] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [122] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
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
