#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 23
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 41
#define ALIAS_COUNT 0
#define TOKEN_COUNT 25
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
  anon_sym_DQUOTE = 18,
  aux_sym_string_literal_token1 = 19,
  sym__string_continuation = 20,
  anon_sym_true = 21,
  anon_sym_false = 22,
  sym_float_exponent = 23,
  anon_sym_DOT = 24,
  sym_root = 25,
  sym__item = 26,
  sym_expression = 27,
  sym__primary_expression = 28,
  sym_literal = 29,
  sym_integer_literal = 30,
  sym_decimal_literal = 31,
  sym_string_literal = 32,
  sym__quote_escape = 33,
  sym__ascii_escape = 34,
  sym__unicode_escape = 35,
  sym_boolean_literal = 36,
  sym__decimal_literal = 37,
  sym_float_literal = 38,
  aux_sym_root_repeat1 = 39,
  aux_sym_string_literal_repeat1 = 40,
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
  [anon_sym_DQUOTE] = "\"",
  [aux_sym_string_literal_token1] = "string_literal_token1",
  [sym__string_continuation] = "_string_continuation",
  [anon_sym_true] = "true",
  [anon_sym_false] = "false",
  [sym_float_exponent] = "float_exponent",
  [anon_sym_DOT] = ".",
  [sym_root] = "root",
  [sym__item] = "_item",
  [sym_expression] = "expression",
  [sym__primary_expression] = "_primary_expression",
  [sym_literal] = "literal",
  [sym_integer_literal] = "integer_literal",
  [sym_decimal_literal] = "decimal_literal",
  [sym_string_literal] = "string_literal",
  [sym__quote_escape] = "_quote_escape",
  [sym__ascii_escape] = "_ascii_escape",
  [sym__unicode_escape] = "_unicode_escape",
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
  [anon_sym_DQUOTE] = anon_sym_DQUOTE,
  [aux_sym_string_literal_token1] = aux_sym_string_literal_token1,
  [sym__string_continuation] = sym__string_continuation,
  [anon_sym_true] = anon_sym_true,
  [anon_sym_false] = anon_sym_false,
  [sym_float_exponent] = sym_float_exponent,
  [anon_sym_DOT] = anon_sym_DOT,
  [sym_root] = sym_root,
  [sym__item] = sym__item,
  [sym_expression] = sym_expression,
  [sym__primary_expression] = sym__primary_expression,
  [sym_literal] = sym_literal,
  [sym_integer_literal] = sym_integer_literal,
  [sym_decimal_literal] = sym_decimal_literal,
  [sym_string_literal] = sym_string_literal,
  [sym__quote_escape] = sym__quote_escape,
  [sym__ascii_escape] = sym__ascii_escape,
  [sym__unicode_escape] = sym__unicode_escape,
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
  [anon_sym_true] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_false] = {
    .visible = true,
    .named = false,
  },
  [sym_float_exponent] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_DOT] = {
    .visible = true,
    .named = false,
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
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(27);
      if (lookahead == '"') ADVANCE(58);
      if (lookahead == '\'') ADVANCE(4);
      if (lookahead == '-') ADVANCE(28);
      if (lookahead == '.') ADVANCE(65);
      if (lookahead == 't') ADVANCE(14);
      if (lookahead == '8' ||
          lookahead == '9') ADVANCE(29);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(29);
      if (('A' <= lookahead && lookahead <= 'f')) ADVANCE(39);
      END_STATE();
    case 1:
      if (lookahead == '\n') SKIP(1)
      if (lookahead == '"') ADVANCE(58);
      if (lookahead == '\\') ADVANCE(2);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(60);
      if (lookahead != 0) ADVANCE(59);
      END_STATE();
    case 2:
      if (lookahead == '\n') ADVANCE(61);
      if (lookahead == '"') ADVANCE(36);
      if (lookahead == '\'') ADVANCE(35);
      if (lookahead == '0') ADVANCE(44);
      if (lookahead == '\\') ADVANCE(43);
      if (lookahead == 'n') ADVANCE(40);
      if (lookahead == 'r') ADVANCE(41);
      if (lookahead == 't') ADVANCE(42);
      if (lookahead == 'u') ADVANCE(57);
      if (lookahead == 'x') ADVANCE(37);
      END_STATE();
    case 3:
      if (lookahead == '\'') ADVANCE(34);
      END_STATE();
    case 4:
      if (lookahead == '\'') ADVANCE(34);
      if (lookahead == '\\') ADVANCE(16);
      if (lookahead != 0) ADVANCE(3);
      END_STATE();
    case 5:
      if (lookahead == '_') ADVANCE(5);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(31);
      END_STATE();
    case 6:
      if (lookahead == '_') ADVANCE(6);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(32);
      END_STATE();
    case 7:
      if (lookahead == '_') ADVANCE(7);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(33);
      END_STATE();
    case 8:
      if (lookahead == '_') ADVANCE(9);
      if (lookahead == '+' ||
          lookahead == '-') ADVANCE(9);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(64);
      END_STATE();
    case 9:
      if (lookahead == '_') ADVANCE(9);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(64);
      END_STATE();
    case 10:
      if (lookahead == 'a') ADVANCE(13);
      END_STATE();
    case 11:
      if (lookahead == 'e') ADVANCE(62);
      END_STATE();
    case 12:
      if (lookahead == 'e') ADVANCE(63);
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
      if (lookahead == 'u') ADVANCE(18);
      if (lookahead == 'x') ADVANCE(25);
      if (lookahead != 0) ADVANCE(3);
      END_STATE();
    case 17:
      if (lookahead == 'u') ADVANCE(11);
      END_STATE();
    case 18:
      if (lookahead == '{') ADVANCE(24);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(23);
      END_STATE();
    case 19:
      if (lookahead == '}') ADVANCE(3);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(19);
      END_STATE();
    case 20:
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(20)
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(38);
      END_STATE();
    case 21:
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(21)
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'f')) ADVANCE(39);
      END_STATE();
    case 22:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(3);
      END_STATE();
    case 23:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(25);
      END_STATE();
    case 24:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(19);
      END_STATE();
    case 25:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(22);
      END_STATE();
    case 26:
      if (eof) ADVANCE(27);
      if (lookahead == '"') ADVANCE(58);
      if (lookahead == '\'') ADVANCE(4);
      if (lookahead == '.') ADVANCE(65);
      if (lookahead == '0') ADVANCE(30);
      if (lookahead == 'f') ADVANCE(10);
      if (lookahead == 't') ADVANCE(14);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(8);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(26)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(29);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(anon_sym_DASH);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(aux_sym_decimal_literal_token1);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(29);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(aux_sym_decimal_literal_token1);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(29);
      if (lookahead == 'b') ADVANCE(5);
      if (lookahead == 'o') ADVANCE(6);
      if (lookahead == 'x') ADVANCE(7);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(sym_binary_literal);
      if (lookahead == '_') ADVANCE(31);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(31);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(sym_octal_literal);
      if (lookahead == '_') ADVANCE(32);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(32);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(sym_hex_literal);
      if (lookahead == '_') ADVANCE(33);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(33);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(sym_character_literal);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(anon_sym_BSLASH_SQUOTE);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(anon_sym_BSLASH_DQUOTE);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(anon_sym_BSLASHx);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(aux_sym_ascii_escape_token1);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(aux_sym_ascii_escape_token2);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(anon_sym_BSLASHn);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(anon_sym_BSLASHr);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(anon_sym_BSLASHt);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(anon_sym_BSLASH_BSLASH);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(anon_sym_BSLASH0);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(aux_sym_unicode_escape_token1);
      END_STATE();
    case 46:
      ACCEPT_TOKEN(aux_sym_unicode_escape_token1);
      if (lookahead == '_') ADVANCE(46);
      END_STATE();
    case 47:
      ACCEPT_TOKEN(aux_sym_unicode_escape_token1);
      if (lookahead == '_') ADVANCE(46);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(45);
      END_STATE();
    case 48:
      ACCEPT_TOKEN(aux_sym_unicode_escape_token1);
      if (lookahead == '_') ADVANCE(48);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(45);
      END_STATE();
    case 49:
      ACCEPT_TOKEN(aux_sym_unicode_escape_token1);
      if (lookahead == '_') ADVANCE(48);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(47);
      END_STATE();
    case 50:
      ACCEPT_TOKEN(aux_sym_unicode_escape_token1);
      if (lookahead == '_') ADVANCE(50);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(47);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(aux_sym_unicode_escape_token1);
      if (lookahead == '_') ADVANCE(50);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(49);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(aux_sym_unicode_escape_token1);
      if (lookahead == '_') ADVANCE(52);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(49);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(aux_sym_unicode_escape_token1);
      if (lookahead == '_') ADVANCE(52);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(51);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(aux_sym_unicode_escape_token1);
      if (lookahead == '_') ADVANCE(54);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(51);
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
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(aux_sym_string_literal_token1);
      END_STATE();
    case 60:
      ACCEPT_TOKEN(aux_sym_string_literal_token1);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(60);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '"' &&
          lookahead != '\\') ADVANCE(59);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(sym__string_continuation);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(anon_sym_true);
      END_STATE();
    case 63:
      ACCEPT_TOKEN(anon_sym_false);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(sym_float_exponent);
      if (lookahead == '_') ADVANCE(64);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(64);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(anon_sym_DOT);
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
  [4] = {.lex_state = 1},
  [5] = {.lex_state = 1},
  [6] = {.lex_state = 1},
  [7] = {.lex_state = 1},
  [8] = {.lex_state = 26},
  [9] = {.lex_state = 26},
  [10] = {.lex_state = 26},
  [11] = {.lex_state = 26},
  [12] = {.lex_state = 26},
  [13] = {.lex_state = 26},
  [14] = {.lex_state = 26},
  [15] = {.lex_state = 26},
  [16] = {.lex_state = 26},
  [17] = {.lex_state = 26},
  [18] = {.lex_state = 26},
  [19] = {.lex_state = 0},
  [20] = {.lex_state = 0},
  [21] = {.lex_state = 20},
  [22] = {.lex_state = 21},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_DASH] = ACTIONS(1),
    [aux_sym_decimal_literal_token1] = ACTIONS(1),
    [sym_character_literal] = ACTIONS(1),
    [aux_sym_ascii_escape_token1] = ACTIONS(1),
    [aux_sym_ascii_escape_token2] = ACTIONS(1),
    [anon_sym_DQUOTE] = ACTIONS(1),
    [anon_sym_true] = ACTIONS(1),
    [anon_sym_DOT] = ACTIONS(1),
  },
  [1] = {
    [sym_root] = STATE(19),
    [sym__item] = STATE(3),
    [sym_expression] = STATE(3),
    [sym__primary_expression] = STATE(14),
    [sym_literal] = STATE(14),
    [sym_integer_literal] = STATE(12),
    [sym_decimal_literal] = STATE(11),
    [sym_string_literal] = STATE(12),
    [sym_boolean_literal] = STATE(12),
    [sym__decimal_literal] = STATE(20),
    [sym_float_literal] = STATE(12),
    [aux_sym_root_repeat1] = STATE(3),
    [ts_builtin_sym_end] = ACTIONS(3),
    [aux_sym_decimal_literal_token1] = ACTIONS(5),
    [sym_binary_literal] = ACTIONS(7),
    [sym_octal_literal] = ACTIONS(7),
    [sym_hex_literal] = ACTIONS(7),
    [sym_character_literal] = ACTIONS(9),
    [anon_sym_DQUOTE] = ACTIONS(11),
    [anon_sym_true] = ACTIONS(13),
    [anon_sym_false] = ACTIONS(13),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 11,
    ACTIONS(15), 1,
      ts_builtin_sym_end,
    ACTIONS(17), 1,
      aux_sym_decimal_literal_token1,
    ACTIONS(23), 1,
      sym_character_literal,
    ACTIONS(26), 1,
      anon_sym_DQUOTE,
    STATE(11), 1,
      sym_decimal_literal,
    STATE(20), 1,
      sym__decimal_literal,
    ACTIONS(29), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(14), 2,
      sym__primary_expression,
      sym_literal,
    ACTIONS(20), 3,
      sym_binary_literal,
      sym_octal_literal,
      sym_hex_literal,
    STATE(2), 3,
      sym__item,
      sym_expression,
      aux_sym_root_repeat1,
    STATE(12), 4,
      sym_integer_literal,
      sym_string_literal,
      sym_boolean_literal,
      sym_float_literal,
  [43] = 11,
    ACTIONS(5), 1,
      aux_sym_decimal_literal_token1,
    ACTIONS(9), 1,
      sym_character_literal,
    ACTIONS(11), 1,
      anon_sym_DQUOTE,
    ACTIONS(32), 1,
      ts_builtin_sym_end,
    STATE(11), 1,
      sym_decimal_literal,
    STATE(20), 1,
      sym__decimal_literal,
    ACTIONS(13), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(14), 2,
      sym__primary_expression,
      sym_literal,
    ACTIONS(7), 3,
      sym_binary_literal,
      sym_octal_literal,
      sym_hex_literal,
    STATE(2), 3,
      sym__item,
      sym_expression,
      aux_sym_root_repeat1,
    STATE(12), 4,
      sym_integer_literal,
      sym_string_literal,
      sym_boolean_literal,
      sym_float_literal,
  [86] = 5,
    ACTIONS(36), 1,
      anon_sym_BSLASHx,
    ACTIONS(38), 1,
      anon_sym_DQUOTE,
    ACTIONS(40), 1,
      aux_sym_string_literal_token1,
    STATE(5), 4,
      sym__quote_escape,
      sym__ascii_escape,
      sym__unicode_escape,
      aux_sym_string_literal_repeat1,
    ACTIONS(34), 9,
      anon_sym_BSLASH_SQUOTE,
      anon_sym_BSLASH_DQUOTE,
      anon_sym_BSLASHn,
      anon_sym_BSLASHr,
      anon_sym_BSLASHt,
      anon_sym_BSLASH_BSLASH,
      anon_sym_BSLASH0,
      aux_sym_unicode_escape_token1,
      sym__string_continuation,
  [113] = 5,
    ACTIONS(36), 1,
      anon_sym_BSLASHx,
    ACTIONS(44), 1,
      anon_sym_DQUOTE,
    ACTIONS(46), 1,
      aux_sym_string_literal_token1,
    STATE(6), 4,
      sym__quote_escape,
      sym__ascii_escape,
      sym__unicode_escape,
      aux_sym_string_literal_repeat1,
    ACTIONS(42), 9,
      anon_sym_BSLASH_SQUOTE,
      anon_sym_BSLASH_DQUOTE,
      anon_sym_BSLASHn,
      anon_sym_BSLASHr,
      anon_sym_BSLASHt,
      anon_sym_BSLASH_BSLASH,
      anon_sym_BSLASH0,
      aux_sym_unicode_escape_token1,
      sym__string_continuation,
  [140] = 5,
    ACTIONS(51), 1,
      anon_sym_BSLASHx,
    ACTIONS(54), 1,
      anon_sym_DQUOTE,
    ACTIONS(56), 1,
      aux_sym_string_literal_token1,
    STATE(6), 4,
      sym__quote_escape,
      sym__ascii_escape,
      sym__unicode_escape,
      aux_sym_string_literal_repeat1,
    ACTIONS(48), 9,
      anon_sym_BSLASH_SQUOTE,
      anon_sym_BSLASH_DQUOTE,
      anon_sym_BSLASHn,
      anon_sym_BSLASHr,
      anon_sym_BSLASHt,
      anon_sym_BSLASH_BSLASH,
      anon_sym_BSLASH0,
      aux_sym_unicode_escape_token1,
      sym__string_continuation,
  [167] = 2,
    ACTIONS(61), 1,
      aux_sym_string_literal_token1,
    ACTIONS(59), 11,
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
  [184] = 4,
    ACTIONS(65), 1,
      aux_sym_decimal_literal_token1,
    ACTIONS(68), 1,
      sym_float_exponent,
    STATE(10), 1,
      sym__decimal_literal,
    ACTIONS(63), 8,
      ts_builtin_sym_end,
      sym_binary_literal,
      sym_octal_literal,
      sym_hex_literal,
      sym_character_literal,
      anon_sym_DQUOTE,
      anon_sym_true,
      anon_sym_false,
  [204] = 3,
    ACTIONS(72), 1,
      aux_sym_decimal_literal_token1,
    ACTIONS(74), 1,
      anon_sym_DOT,
    ACTIONS(70), 8,
      ts_builtin_sym_end,
      sym_binary_literal,
      sym_octal_literal,
      sym_hex_literal,
      sym_character_literal,
      anon_sym_DQUOTE,
      anon_sym_true,
      anon_sym_false,
  [221] = 3,
    ACTIONS(78), 1,
      aux_sym_decimal_literal_token1,
    ACTIONS(80), 1,
      sym_float_exponent,
    ACTIONS(76), 8,
      ts_builtin_sym_end,
      sym_binary_literal,
      sym_octal_literal,
      sym_hex_literal,
      sym_character_literal,
      anon_sym_DQUOTE,
      anon_sym_true,
      anon_sym_false,
  [238] = 2,
    ACTIONS(84), 1,
      aux_sym_decimal_literal_token1,
    ACTIONS(82), 8,
      ts_builtin_sym_end,
      sym_binary_literal,
      sym_octal_literal,
      sym_hex_literal,
      sym_character_literal,
      anon_sym_DQUOTE,
      anon_sym_true,
      anon_sym_false,
  [252] = 2,
    ACTIONS(88), 1,
      aux_sym_decimal_literal_token1,
    ACTIONS(86), 8,
      ts_builtin_sym_end,
      sym_binary_literal,
      sym_octal_literal,
      sym_hex_literal,
      sym_character_literal,
      anon_sym_DQUOTE,
      anon_sym_true,
      anon_sym_false,
  [266] = 2,
    ACTIONS(92), 1,
      aux_sym_decimal_literal_token1,
    ACTIONS(90), 8,
      ts_builtin_sym_end,
      sym_binary_literal,
      sym_octal_literal,
      sym_hex_literal,
      sym_character_literal,
      anon_sym_DQUOTE,
      anon_sym_true,
      anon_sym_false,
  [280] = 2,
    ACTIONS(96), 1,
      aux_sym_decimal_literal_token1,
    ACTIONS(94), 8,
      ts_builtin_sym_end,
      sym_binary_literal,
      sym_octal_literal,
      sym_hex_literal,
      sym_character_literal,
      anon_sym_DQUOTE,
      anon_sym_true,
      anon_sym_false,
  [294] = 2,
    ACTIONS(100), 1,
      aux_sym_decimal_literal_token1,
    ACTIONS(98), 8,
      ts_builtin_sym_end,
      sym_binary_literal,
      sym_octal_literal,
      sym_hex_literal,
      sym_character_literal,
      anon_sym_DQUOTE,
      anon_sym_true,
      anon_sym_false,
  [308] = 2,
    ACTIONS(104), 1,
      aux_sym_decimal_literal_token1,
    ACTIONS(102), 8,
      ts_builtin_sym_end,
      sym_binary_literal,
      sym_octal_literal,
      sym_hex_literal,
      sym_character_literal,
      anon_sym_DQUOTE,
      anon_sym_true,
      anon_sym_false,
  [322] = 2,
    ACTIONS(108), 1,
      aux_sym_decimal_literal_token1,
    ACTIONS(106), 8,
      ts_builtin_sym_end,
      sym_binary_literal,
      sym_octal_literal,
      sym_hex_literal,
      sym_character_literal,
      anon_sym_DQUOTE,
      anon_sym_true,
      anon_sym_false,
  [336] = 2,
    ACTIONS(112), 1,
      aux_sym_decimal_literal_token1,
    ACTIONS(110), 8,
      ts_builtin_sym_end,
      sym_binary_literal,
      sym_octal_literal,
      sym_hex_literal,
      sym_character_literal,
      anon_sym_DQUOTE,
      anon_sym_true,
      anon_sym_false,
  [350] = 1,
    ACTIONS(114), 1,
      ts_builtin_sym_end,
  [354] = 1,
    ACTIONS(116), 1,
      anon_sym_DOT,
  [358] = 1,
    ACTIONS(118), 1,
      aux_sym_ascii_escape_token1,
  [362] = 1,
    ACTIONS(120), 1,
      aux_sym_ascii_escape_token2,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 43,
  [SMALL_STATE(4)] = 86,
  [SMALL_STATE(5)] = 113,
  [SMALL_STATE(6)] = 140,
  [SMALL_STATE(7)] = 167,
  [SMALL_STATE(8)] = 184,
  [SMALL_STATE(9)] = 204,
  [SMALL_STATE(10)] = 221,
  [SMALL_STATE(11)] = 238,
  [SMALL_STATE(12)] = 252,
  [SMALL_STATE(13)] = 266,
  [SMALL_STATE(14)] = 280,
  [SMALL_STATE(15)] = 294,
  [SMALL_STATE(16)] = 308,
  [SMALL_STATE(17)] = 322,
  [SMALL_STATE(18)] = 336,
  [SMALL_STATE(19)] = 350,
  [SMALL_STATE(20)] = 354,
  [SMALL_STATE(21)] = 358,
  [SMALL_STATE(22)] = 362,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_root, 0),
  [5] = {.entry = {.count = 1, .reusable = false}}, SHIFT(9),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [15] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_root_repeat1, 2),
  [17] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_root_repeat1, 2), SHIFT_REPEAT(9),
  [20] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_root_repeat1, 2), SHIFT_REPEAT(11),
  [23] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_root_repeat1, 2), SHIFT_REPEAT(12),
  [26] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_root_repeat1, 2), SHIFT_REPEAT(4),
  [29] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_root_repeat1, 2), SHIFT_REPEAT(13),
  [32] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_root, 1),
  [34] = {.entry = {.count = 1, .reusable = false}}, SHIFT(5),
  [36] = {.entry = {.count = 1, .reusable = false}}, SHIFT(21),
  [38] = {.entry = {.count = 1, .reusable = false}}, SHIFT(15),
  [40] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [42] = {.entry = {.count = 1, .reusable = false}}, SHIFT(6),
  [44] = {.entry = {.count = 1, .reusable = false}}, SHIFT(16),
  [46] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [48] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_string_literal_repeat1, 2), SHIFT_REPEAT(6),
  [51] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_string_literal_repeat1, 2), SHIFT_REPEAT(21),
  [54] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_string_literal_repeat1, 2),
  [56] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_string_literal_repeat1, 2), SHIFT_REPEAT(6),
  [59] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__ascii_escape, 3),
  [61] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__ascii_escape, 3),
  [63] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_float_literal, 2),
  [65] = {.entry = {.count = 2, .reusable = false}}, REDUCE(sym_float_literal, 2), SHIFT(10),
  [68] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [70] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_decimal_literal, 1),
  [72] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_decimal_literal, 1),
  [74] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__decimal_literal, 1),
  [76] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_float_literal, 3),
  [78] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_float_literal, 3),
  [80] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [82] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_integer_literal, 1),
  [84] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_integer_literal, 1),
  [86] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_literal, 1),
  [88] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_literal, 1),
  [90] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_boolean_literal, 1),
  [92] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_boolean_literal, 1),
  [94] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_expression, 1),
  [96] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_expression, 1),
  [98] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_literal, 2),
  [100] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_string_literal, 2),
  [102] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_literal, 3),
  [104] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_string_literal, 3),
  [106] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_float_literal, 3, .production_id = 1),
  [108] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_float_literal, 3, .production_id = 1),
  [110] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_float_literal, 4, .production_id = 2),
  [112] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_float_literal, 4, .production_id = 2),
  [114] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [116] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [118] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [120] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
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
