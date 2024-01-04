#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 20
#define LARGE_STATE_COUNT 4
#define SYMBOL_COUNT 39
#define ALIAS_COUNT 0
#define TOKEN_COUNT 26
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 1
#define MAX_ALIAS_SEQUENCE_LENGTH 4
#define PRODUCTION_ID_COUNT 3

enum {
  anon_sym_DASH = 1,
  aux_sym_decimal_literal_token1 = 2,
  sym_binary_literal = 3,
  sym_octal_literal = 4,
  sym_hex_literal = 5,
  sym_character_literal = 6,
  anon_sym_BSLASH_SQUOTE = 7,
  anon_sym_BSLASH_DQUOTE = 8,
  anon_sym_BSLASHx = 9,
  aux_sym_ascii_escape_token1 = 10,
  aux_sym_ascii_escape_token2 = 11,
  anon_sym_BSLASHn = 12,
  anon_sym_BSLASHr = 13,
  anon_sym_BSLASHt = 14,
  anon_sym_BSLASH_BSLASH = 15,
  anon_sym_BSLASH0 = 16,
  aux_sym_unicode_escape_token1 = 17,
  aux_sym_string_literal_token1 = 18,
  sym__string_sigil = 19,
  sym_escape_sequence = 20,
  sym__string_continuation = 21,
  sym__boolean_true = 22,
  sym__boolean_false = 23,
  sym_float_exponent = 24,
  sym__float_decimal_point = 25,
  sym_root = 26,
  sym__item = 27,
  sym_expression = 28,
  sym__primary_expression = 29,
  sym_literal = 30,
  sym_integer_literal = 31,
  sym_decimal_literal = 32,
  sym_string_literal = 33,
  sym_boolean_literal = 34,
  sym__decimal_literal = 35,
  sym_float_literal = 36,
  aux_sym_root_repeat1 = 37,
  aux_sym_string_literal_repeat1 = 38,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_DASH] = "-",
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
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(29);
      if (lookahead == '"') ADVANCE(65);
      if (lookahead == '\'') ADVANCE(4);
      if (lookahead == '-') ADVANCE(30);
      if (lookahead == '.') ADVANCE(76);
      if (lookahead == '0') ADVANCE(33);
      if (lookahead == '\\') ADVANCE(42);
      if (lookahead == 'f') ADVANCE(44);
      if (lookahead == 't') ADVANCE(14);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(43);
      if (lookahead == '8' ||
          lookahead == '9') ADVANCE(31);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      if (('1' <= lookahead && lookahead <= '7')) ADVANCE(31);
      if (('A' <= lookahead && lookahead <= 'd')) ADVANCE(41);
      END_STATE();
    case 1:
      if (lookahead == '\n') SKIP(2)
      if (lookahead == '"') ADVANCE(65);
      if (lookahead == '\\') ADVANCE(18);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(64);
      if (lookahead != 0) ADVANCE(63);
      END_STATE();
    case 2:
      if (lookahead == '\n') SKIP(2)
      if (lookahead == '"') ADVANCE(65);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(64);
      if (lookahead != 0 &&
          lookahead != '\\') ADVANCE(63);
      END_STATE();
    case 3:
      if (lookahead == '\'') ADVANCE(37);
      END_STATE();
    case 4:
      if (lookahead == '\'') ADVANCE(37);
      if (lookahead == '\\') ADVANCE(16);
      if (lookahead != 0) ADVANCE(3);
      END_STATE();
    case 5:
      if (lookahead == '_') ADVANCE(5);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(35);
      END_STATE();
    case 6:
      if (lookahead == '_') ADVANCE(6);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(36);
      END_STATE();
    case 7:
      if (lookahead == '_') ADVANCE(8);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(8);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(75);
      END_STATE();
    case 8:
      if (lookahead == '_') ADVANCE(8);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(75);
      END_STATE();
    case 9:
      if (lookahead == '_') ADVANCE(9);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(34);
      END_STATE();
    case 10:
      if (lookahead == 'a') ADVANCE(13);
      END_STATE();
    case 11:
      if (lookahead == 'e') ADVANCE(73);
      END_STATE();
    case 12:
      if (lookahead == 'e') ADVANCE(74);
      END_STATE();
    case 13:
      if (lookahead == 'l') ADVANCE(15);
      END_STATE();
    case 14:
      if (lookahead == 'r') ADVANCE(17);
      END_STATE();
    case 15:
      if (lookahead == 's') ADVANCE(12);
      END_STATE();
    case 16:
      if (lookahead == 'u') ADVANCE(19);
      if (lookahead == 'x') ADVANCE(26);
      if (lookahead != 0) ADVANCE(3);
      END_STATE();
    case 17:
      if (lookahead == 'u') ADVANCE(11);
      END_STATE();
    case 18:
      if (lookahead == 'u') ADVANCE(25);
      if (lookahead == 'x') ADVANCE(27);
      if (lookahead != 0) ADVANCE(66);
      END_STATE();
    case 19:
      if (lookahead == '{') ADVANCE(23);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(22);
      END_STATE();
    case 20:
      if (lookahead == '}') ADVANCE(3);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(20);
      END_STATE();
    case 21:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(3);
      END_STATE();
    case 22:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(26);
      END_STATE();
    case 23:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(20);
      END_STATE();
    case 24:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(66);
      END_STATE();
    case 25:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(71);
      END_STATE();
    case 26:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(21);
      END_STATE();
    case 27:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(24);
      END_STATE();
    case 28:
      if (eof) ADVANCE(29);
      if (lookahead == '"') ADVANCE(65);
      if (lookahead == '\'') ADVANCE(4);
      if (lookahead == '.') ADVANCE(76);
      if (lookahead == '0') ADVANCE(32);
      if (lookahead == 'f') ADVANCE(10);
      if (lookahead == 't') ADVANCE(14);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(7);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(28)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(31);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(anon_sym_DASH);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(aux_sym_decimal_literal_token1);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(31);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(aux_sym_decimal_literal_token1);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(31);
      if (lookahead == 'b') ADVANCE(9);
      if (lookahead == 'o') ADVANCE(5);
      if (lookahead == 'x') ADVANCE(6);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(aux_sym_decimal_literal_token1);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(31);
      if (lookahead == 'o') ADVANCE(5);
      if (lookahead == 'x') ADVANCE(6);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(sym_binary_literal);
      if (lookahead == '_') ADVANCE(34);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(34);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(sym_octal_literal);
      if (lookahead == '_') ADVANCE(35);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(35);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(sym_hex_literal);
      if (lookahead == '_') ADVANCE(36);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(36);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(sym_character_literal);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(anon_sym_BSLASH_SQUOTE);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(anon_sym_BSLASH_DQUOTE);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(anon_sym_BSLASHx);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(aux_sym_ascii_escape_token2);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(aux_sym_ascii_escape_token2);
      if (lookahead == '\n') ADVANCE(72);
      if (lookahead == '"') ADVANCE(39);
      if (lookahead == '\'') ADVANCE(38);
      if (lookahead == '0') ADVANCE(49);
      if (lookahead == '\\') ADVANCE(48);
      if (lookahead == 'n') ADVANCE(45);
      if (lookahead == 'r') ADVANCE(46);
      if (lookahead == 't') ADVANCE(47);
      if (lookahead == 'u') ADVANCE(62);
      if (lookahead == 'x') ADVANCE(40);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(aux_sym_ascii_escape_token2);
      if (lookahead == '_') ADVANCE(8);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(8);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(75);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(aux_sym_ascii_escape_token2);
      if (lookahead == 'a') ADVANCE(13);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(anon_sym_BSLASHn);
      END_STATE();
    case 46:
      ACCEPT_TOKEN(anon_sym_BSLASHr);
      END_STATE();
    case 47:
      ACCEPT_TOKEN(anon_sym_BSLASHt);
      END_STATE();
    case 48:
      ACCEPT_TOKEN(anon_sym_BSLASH_BSLASH);
      END_STATE();
    case 49:
      ACCEPT_TOKEN(anon_sym_BSLASH0);
      END_STATE();
    case 50:
      ACCEPT_TOKEN(aux_sym_unicode_escape_token1);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(aux_sym_unicode_escape_token1);
      if (lookahead == '_') ADVANCE(51);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(aux_sym_unicode_escape_token1);
      if (lookahead == '_') ADVANCE(51);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(50);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(aux_sym_unicode_escape_token1);
      if (lookahead == '_') ADVANCE(53);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(50);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(aux_sym_unicode_escape_token1);
      if (lookahead == '_') ADVANCE(53);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(52);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(aux_sym_unicode_escape_token1);
      if (lookahead == '_') ADVANCE(55);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(52);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(aux_sym_unicode_escape_token1);
      if (lookahead == '_') ADVANCE(55);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(54);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(aux_sym_unicode_escape_token1);
      if (lookahead == '_') ADVANCE(57);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(54);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(aux_sym_unicode_escape_token1);
      if (lookahead == '_') ADVANCE(57);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(56);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(aux_sym_unicode_escape_token1);
      if (lookahead == '_') ADVANCE(59);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(56);
      END_STATE();
    case 60:
      ACCEPT_TOKEN(aux_sym_unicode_escape_token1);
      if (lookahead == '_') ADVANCE(59);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(58);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(aux_sym_unicode_escape_token1);
      if (lookahead == '_') ADVANCE(61);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(58);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(aux_sym_unicode_escape_token1);
      if (lookahead == '_') ADVANCE(61);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(60);
      END_STATE();
    case 63:
      ACCEPT_TOKEN(aux_sym_string_literal_token1);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(aux_sym_string_literal_token1);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(64);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '"' &&
          lookahead != '\\') ADVANCE(63);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(sym__string_sigil);
      END_STATE();
    case 66:
      ACCEPT_TOKEN(sym_escape_sequence);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(sym_escape_sequence);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(66);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(sym_escape_sequence);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(67);
      END_STATE();
    case 69:
      ACCEPT_TOKEN(sym_escape_sequence);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(68);
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
      ACCEPT_TOKEN(sym__string_continuation);
      END_STATE();
    case 73:
      ACCEPT_TOKEN(sym__boolean_true);
      END_STATE();
    case 74:
      ACCEPT_TOKEN(sym__boolean_false);
      END_STATE();
    case 75:
      ACCEPT_TOKEN(sym_float_exponent);
      if (lookahead == '_') ADVANCE(75);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(75);
      END_STATE();
    case 76:
      ACCEPT_TOKEN(sym__float_decimal_point);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 28},
  [2] = {.lex_state = 28},
  [3] = {.lex_state = 28},
  [4] = {.lex_state = 28},
  [5] = {.lex_state = 28},
  [6] = {.lex_state = 28},
  [7] = {.lex_state = 28},
  [8] = {.lex_state = 28},
  [9] = {.lex_state = 28},
  [10] = {.lex_state = 28},
  [11] = {.lex_state = 28},
  [12] = {.lex_state = 28},
  [13] = {.lex_state = 28},
  [14] = {.lex_state = 28},
  [15] = {.lex_state = 1},
  [16] = {.lex_state = 1},
  [17] = {.lex_state = 1},
  [18] = {.lex_state = 0},
  [19] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_DASH] = ACTIONS(1),
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
    [sym_root] = STATE(18),
    [sym__item] = STATE(2),
    [sym_expression] = STATE(2),
    [sym__primary_expression] = STATE(10),
    [sym_literal] = STATE(10),
    [sym_integer_literal] = STATE(8),
    [sym_decimal_literal] = STATE(7),
    [sym_string_literal] = STATE(8),
    [sym_boolean_literal] = STATE(8),
    [sym__decimal_literal] = STATE(19),
    [sym_float_literal] = STATE(8),
    [aux_sym_root_repeat1] = STATE(2),
    [ts_builtin_sym_end] = ACTIONS(3),
    [aux_sym_decimal_literal_token1] = ACTIONS(5),
    [sym_binary_literal] = ACTIONS(7),
    [sym_octal_literal] = ACTIONS(7),
    [sym_hex_literal] = ACTIONS(7),
    [sym_character_literal] = ACTIONS(9),
    [sym__string_sigil] = ACTIONS(11),
    [sym__boolean_true] = ACTIONS(13),
    [sym__boolean_false] = ACTIONS(13),
  },
  [2] = {
    [sym__item] = STATE(3),
    [sym_expression] = STATE(3),
    [sym__primary_expression] = STATE(10),
    [sym_literal] = STATE(10),
    [sym_integer_literal] = STATE(8),
    [sym_decimal_literal] = STATE(7),
    [sym_string_literal] = STATE(8),
    [sym_boolean_literal] = STATE(8),
    [sym__decimal_literal] = STATE(19),
    [sym_float_literal] = STATE(8),
    [aux_sym_root_repeat1] = STATE(3),
    [ts_builtin_sym_end] = ACTIONS(15),
    [aux_sym_decimal_literal_token1] = ACTIONS(5),
    [sym_binary_literal] = ACTIONS(7),
    [sym_octal_literal] = ACTIONS(7),
    [sym_hex_literal] = ACTIONS(7),
    [sym_character_literal] = ACTIONS(9),
    [sym__string_sigil] = ACTIONS(11),
    [sym__boolean_true] = ACTIONS(13),
    [sym__boolean_false] = ACTIONS(13),
  },
  [3] = {
    [sym__item] = STATE(3),
    [sym_expression] = STATE(3),
    [sym__primary_expression] = STATE(10),
    [sym_literal] = STATE(10),
    [sym_integer_literal] = STATE(8),
    [sym_decimal_literal] = STATE(7),
    [sym_string_literal] = STATE(8),
    [sym_boolean_literal] = STATE(8),
    [sym__decimal_literal] = STATE(19),
    [sym_float_literal] = STATE(8),
    [aux_sym_root_repeat1] = STATE(3),
    [ts_builtin_sym_end] = ACTIONS(17),
    [aux_sym_decimal_literal_token1] = ACTIONS(19),
    [sym_binary_literal] = ACTIONS(22),
    [sym_octal_literal] = ACTIONS(22),
    [sym_hex_literal] = ACTIONS(22),
    [sym_character_literal] = ACTIONS(25),
    [sym__string_sigil] = ACTIONS(28),
    [sym__boolean_true] = ACTIONS(31),
    [sym__boolean_false] = ACTIONS(31),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 4,
    ACTIONS(36), 1,
      aux_sym_decimal_literal_token1,
    ACTIONS(39), 1,
      sym_float_exponent,
    STATE(6), 1,
      sym__decimal_literal,
    ACTIONS(34), 8,
      ts_builtin_sym_end,
      sym_binary_literal,
      sym_octal_literal,
      sym_hex_literal,
      sym_character_literal,
      sym__string_sigil,
      sym__boolean_true,
      sym__boolean_false,
  [20] = 3,
    ACTIONS(43), 1,
      aux_sym_decimal_literal_token1,
    ACTIONS(45), 1,
      sym__float_decimal_point,
    ACTIONS(41), 8,
      ts_builtin_sym_end,
      sym_binary_literal,
      sym_octal_literal,
      sym_hex_literal,
      sym_character_literal,
      sym__string_sigil,
      sym__boolean_true,
      sym__boolean_false,
  [37] = 3,
    ACTIONS(49), 1,
      aux_sym_decimal_literal_token1,
    ACTIONS(51), 1,
      sym_float_exponent,
    ACTIONS(47), 8,
      ts_builtin_sym_end,
      sym_binary_literal,
      sym_octal_literal,
      sym_hex_literal,
      sym_character_literal,
      sym__string_sigil,
      sym__boolean_true,
      sym__boolean_false,
  [54] = 2,
    ACTIONS(55), 1,
      aux_sym_decimal_literal_token1,
    ACTIONS(53), 8,
      ts_builtin_sym_end,
      sym_binary_literal,
      sym_octal_literal,
      sym_hex_literal,
      sym_character_literal,
      sym__string_sigil,
      sym__boolean_true,
      sym__boolean_false,
  [68] = 2,
    ACTIONS(59), 1,
      aux_sym_decimal_literal_token1,
    ACTIONS(57), 8,
      ts_builtin_sym_end,
      sym_binary_literal,
      sym_octal_literal,
      sym_hex_literal,
      sym_character_literal,
      sym__string_sigil,
      sym__boolean_true,
      sym__boolean_false,
  [82] = 2,
    ACTIONS(63), 1,
      aux_sym_decimal_literal_token1,
    ACTIONS(61), 8,
      ts_builtin_sym_end,
      sym_binary_literal,
      sym_octal_literal,
      sym_hex_literal,
      sym_character_literal,
      sym__string_sigil,
      sym__boolean_true,
      sym__boolean_false,
  [96] = 2,
    ACTIONS(67), 1,
      aux_sym_decimal_literal_token1,
    ACTIONS(65), 8,
      ts_builtin_sym_end,
      sym_binary_literal,
      sym_octal_literal,
      sym_hex_literal,
      sym_character_literal,
      sym__string_sigil,
      sym__boolean_true,
      sym__boolean_false,
  [110] = 2,
    ACTIONS(71), 1,
      aux_sym_decimal_literal_token1,
    ACTIONS(69), 8,
      ts_builtin_sym_end,
      sym_binary_literal,
      sym_octal_literal,
      sym_hex_literal,
      sym_character_literal,
      sym__string_sigil,
      sym__boolean_true,
      sym__boolean_false,
  [124] = 2,
    ACTIONS(75), 1,
      aux_sym_decimal_literal_token1,
    ACTIONS(73), 8,
      ts_builtin_sym_end,
      sym_binary_literal,
      sym_octal_literal,
      sym_hex_literal,
      sym_character_literal,
      sym__string_sigil,
      sym__boolean_true,
      sym__boolean_false,
  [138] = 2,
    ACTIONS(79), 1,
      aux_sym_decimal_literal_token1,
    ACTIONS(77), 8,
      ts_builtin_sym_end,
      sym_binary_literal,
      sym_octal_literal,
      sym_hex_literal,
      sym_character_literal,
      sym__string_sigil,
      sym__boolean_true,
      sym__boolean_false,
  [152] = 2,
    ACTIONS(83), 1,
      aux_sym_decimal_literal_token1,
    ACTIONS(81), 8,
      ts_builtin_sym_end,
      sym_binary_literal,
      sym_octal_literal,
      sym_hex_literal,
      sym_character_literal,
      sym__string_sigil,
      sym__boolean_true,
      sym__boolean_false,
  [166] = 3,
    ACTIONS(87), 1,
      sym__string_sigil,
    STATE(16), 1,
      aux_sym_string_literal_repeat1,
    ACTIONS(85), 2,
      aux_sym_string_literal_token1,
      sym_escape_sequence,
  [177] = 3,
    ACTIONS(91), 1,
      sym__string_sigil,
    STATE(17), 1,
      aux_sym_string_literal_repeat1,
    ACTIONS(89), 2,
      aux_sym_string_literal_token1,
      sym_escape_sequence,
  [188] = 3,
    ACTIONS(96), 1,
      sym__string_sigil,
    STATE(17), 1,
      aux_sym_string_literal_repeat1,
    ACTIONS(93), 2,
      aux_sym_string_literal_token1,
      sym_escape_sequence,
  [199] = 1,
    ACTIONS(98), 1,
      ts_builtin_sym_end,
  [203] = 1,
    ACTIONS(100), 1,
      sym__float_decimal_point,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(4)] = 0,
  [SMALL_STATE(5)] = 20,
  [SMALL_STATE(6)] = 37,
  [SMALL_STATE(7)] = 54,
  [SMALL_STATE(8)] = 68,
  [SMALL_STATE(9)] = 82,
  [SMALL_STATE(10)] = 96,
  [SMALL_STATE(11)] = 110,
  [SMALL_STATE(12)] = 124,
  [SMALL_STATE(13)] = 138,
  [SMALL_STATE(14)] = 152,
  [SMALL_STATE(15)] = 166,
  [SMALL_STATE(16)] = 177,
  [SMALL_STATE(17)] = 188,
  [SMALL_STATE(18)] = 199,
  [SMALL_STATE(19)] = 203,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_root, 0),
  [5] = {.entry = {.count = 1, .reusable = false}}, SHIFT(5),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [15] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_root, 1),
  [17] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_root_repeat1, 2),
  [19] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_root_repeat1, 2), SHIFT_REPEAT(5),
  [22] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_root_repeat1, 2), SHIFT_REPEAT(7),
  [25] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_root_repeat1, 2), SHIFT_REPEAT(8),
  [28] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_root_repeat1, 2), SHIFT_REPEAT(15),
  [31] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_root_repeat1, 2), SHIFT_REPEAT(9),
  [34] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_float_literal, 2),
  [36] = {.entry = {.count = 2, .reusable = false}}, REDUCE(sym_float_literal, 2), SHIFT(6),
  [39] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [41] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_decimal_literal, 1),
  [43] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_decimal_literal, 1),
  [45] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__decimal_literal, 1),
  [47] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_float_literal, 3),
  [49] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_float_literal, 3),
  [51] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [53] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_integer_literal, 1),
  [55] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_integer_literal, 1),
  [57] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_literal, 1),
  [59] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_literal, 1),
  [61] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_boolean_literal, 1),
  [63] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_boolean_literal, 1),
  [65] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_expression, 1),
  [67] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_expression, 1),
  [69] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_literal, 2),
  [71] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_string_literal, 2),
  [73] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_literal, 3),
  [75] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_string_literal, 3),
  [77] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_float_literal, 3, .production_id = 1),
  [79] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_float_literal, 3, .production_id = 1),
  [81] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_float_literal, 4, .production_id = 2),
  [83] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_float_literal, 4, .production_id = 2),
  [85] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [87] = {.entry = {.count = 1, .reusable = false}}, SHIFT(11),
  [89] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [91] = {.entry = {.count = 1, .reusable = false}}, SHIFT(12),
  [93] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_string_literal_repeat1, 2), SHIFT_REPEAT(17),
  [96] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_string_literal_repeat1, 2),
  [98] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [100] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
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
