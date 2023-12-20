#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 27
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 41
#define ALIAS_COUNT 0
#define TOKEN_COUNT 24
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 1
#define MAX_ALIAS_SEQUENCE_LENGTH 3
#define PRODUCTION_ID_COUNT 2

enum {
  sym_suffix_no_e = 1,
  sym_decimal_literal = 2,
  sym_binary_literal = 3,
  sym_octal_literal = 4,
  sym_hex_literal = 5,
  anon_sym_SQUOTE = 6,
  aux_sym_character_literal_token1 = 7,
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
  anon_sym_DQUOTE = 19,
  aux_sym_string_literal_token1 = 20,
  sym__string_continuation = 21,
  anon_sym_true = 22,
  anon_sym_false = 23,
  sym_source_file = 24,
  sym__item = 25,
  sym_expression = 26,
  sym__primary_expression = 27,
  sym_literal = 28,
  sym_integer_literal = 29,
  sym_character_literal = 30,
  sym_quote_escape = 31,
  sym_ascii_escape = 32,
  sym_unicode_escape = 33,
  sym_string_literal = 34,
  sym__quote_escape = 35,
  sym__ascii_escape = 36,
  sym__unicode_escape = 37,
  sym_boolean_literal = 38,
  aux_sym_source_file_repeat1 = 39,
  aux_sym_string_literal_repeat1 = 40,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
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
  [anon_sym_true] = "true",
  [anon_sym_false] = "false",
  [sym_source_file] = "source_file",
  [sym__item] = "_item",
  [sym_expression] = "expression",
  [sym__primary_expression] = "_primary_expression",
  [sym_literal] = "literal",
  [sym_integer_literal] = "integer_literal",
  [sym_character_literal] = "character_literal",
  [sym_quote_escape] = "quote_escape",
  [sym_ascii_escape] = "ascii_escape",
  [sym_unicode_escape] = "unicode_escape",
  [sym_string_literal] = "string_literal",
  [sym__quote_escape] = "_quote_escape",
  [sym__ascii_escape] = "_ascii_escape",
  [sym__unicode_escape] = "_unicode_escape",
  [sym_boolean_literal] = "boolean_literal",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
  [aux_sym_string_literal_repeat1] = "string_literal_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
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
  [anon_sym_true] = anon_sym_true,
  [anon_sym_false] = anon_sym_false,
  [sym_source_file] = sym_source_file,
  [sym__item] = sym__item,
  [sym_expression] = sym_expression,
  [sym__primary_expression] = sym__primary_expression,
  [sym_literal] = sym_literal,
  [sym_integer_literal] = sym_integer_literal,
  [sym_character_literal] = sym_character_literal,
  [sym_quote_escape] = sym_quote_escape,
  [sym_ascii_escape] = sym_ascii_escape,
  [sym_unicode_escape] = sym_unicode_escape,
  [sym_string_literal] = sym_string_literal,
  [sym__quote_escape] = sym__quote_escape,
  [sym__ascii_escape] = sym__ascii_escape,
  [sym__unicode_escape] = sym__unicode_escape,
  [sym_boolean_literal] = sym_boolean_literal,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
  [aux_sym_string_literal_repeat1] = aux_sym_string_literal_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
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
  [anon_sym_true] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_false] = {
    .visible = true,
    .named = false,
  },
  [sym_source_file] = {
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
  [sym_boolean_literal] = {
    .visible = true,
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
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(34);
      if (lookahead == '"') ADVANCE(61);
      if (lookahead == '\'') ADVANCE(47);
      if (lookahead == '0') ADVANCE(53);
      if (lookahead == 't') ADVANCE(39);
      if (lookahead == '8' ||
          lookahead == '9') ADVANCE(43);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      if (lookahead == 'E' ||
          ('[' <= lookahead && lookahead <= '^') ||
          lookahead == '`' ||
          lookahead == 'e') ADVANCE(54);
      if (('1' <= lookahead && lookahead <= '7')) ADVANCE(43);
      if (('g' <= lookahead && lookahead <= 'z')) ADVANCE(42);
      if (('A' <= lookahead && lookahead <= 'f')) ADVANCE(42);
      END_STATE();
    case 1:
      if (lookahead == '\n') SKIP(1)
      if (lookahead == '"') ADVANCE(61);
      if (lookahead == '\\') ADVANCE(2);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(63);
      if (lookahead != 0) ADVANCE(62);
      END_STATE();
    case 2:
      if (lookahead == '\n') ADVANCE(64);
      if (lookahead == '"') ADVANCE(51);
      if (lookahead == '\'') ADVANCE(50);
      if (lookahead == '0') ADVANCE(59);
      if (lookahead == '\\') ADVANCE(58);
      if (lookahead == 'n') ADVANCE(55);
      if (lookahead == 'r') ADVANCE(56);
      if (lookahead == 't') ADVANCE(57);
      if (lookahead == 'u') ADVANCE(28);
      if (lookahead == 'x') ADVANCE(52);
      END_STATE();
    case 3:
      if (lookahead == '"') ADVANCE(51);
      if (lookahead == '\'') ADVANCE(50);
      if (lookahead == '0') ADVANCE(59);
      if (lookahead == '\\') ADVANCE(58);
      if (lookahead == 'n') ADVANCE(55);
      if (lookahead == 'r') ADVANCE(56);
      if (lookahead == 't') ADVANCE(57);
      if (lookahead == 'u') ADVANCE(28);
      if (lookahead == 'x') ADVANCE(52);
      END_STATE();
    case 4:
      if (lookahead == '\\') ADVANCE(3);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(49);
      if (lookahead != 0 &&
          (lookahead < '\'' || ')' < lookahead) &&
          lookahead != 'n' &&
          lookahead != 'r' &&
          lookahead != 't') ADVANCE(48);
      END_STATE();
    case 5:
      if (lookahead == '_') ADVANCE(5);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(44);
      END_STATE();
    case 6:
      if (lookahead == '_') ADVANCE(6);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(45);
      END_STATE();
    case 7:
      if (lookahead == '_') ADVANCE(7);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(46);
      END_STATE();
    case 8:
      if (lookahead == '_') ADVANCE(8);
      if (lookahead == '}') ADVANCE(60);
      END_STATE();
    case 9:
      if (lookahead == '_') ADVANCE(8);
      if (lookahead == '}') ADVANCE(60);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(29);
      END_STATE();
    case 10:
      if (lookahead == '_') ADVANCE(10);
      if (lookahead == '}') ADVANCE(60);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(29);
      END_STATE();
    case 11:
      if (lookahead == '_') ADVANCE(10);
      if (lookahead == '}') ADVANCE(60);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(9);
      END_STATE();
    case 12:
      if (lookahead == '_') ADVANCE(12);
      if (lookahead == '}') ADVANCE(60);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(9);
      END_STATE();
    case 13:
      if (lookahead == '_') ADVANCE(12);
      if (lookahead == '}') ADVANCE(60);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(11);
      END_STATE();
    case 14:
      if (lookahead == '_') ADVANCE(14);
      if (lookahead == '}') ADVANCE(60);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(11);
      END_STATE();
    case 15:
      if (lookahead == '_') ADVANCE(14);
      if (lookahead == '}') ADVANCE(60);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(13);
      END_STATE();
    case 16:
      if (lookahead == '_') ADVANCE(16);
      if (lookahead == '}') ADVANCE(60);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(13);
      END_STATE();
    case 17:
      if (lookahead == '_') ADVANCE(16);
      if (lookahead == '}') ADVANCE(60);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(15);
      END_STATE();
    case 18:
      if (lookahead == '_') ADVANCE(18);
      if (lookahead == '}') ADVANCE(60);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(15);
      END_STATE();
    case 19:
      if (lookahead == '_') ADVANCE(18);
      if (lookahead == '}') ADVANCE(60);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(17);
      END_STATE();
    case 20:
      if (lookahead == 'a') ADVANCE(24);
      END_STATE();
    case 21:
      if (lookahead == 'b') ADVANCE(5);
      if (lookahead == 'o') ADVANCE(6);
      if (lookahead == 'x') ADVANCE(7);
      END_STATE();
    case 22:
      if (lookahead == 'e') ADVANCE(65);
      END_STATE();
    case 23:
      if (lookahead == 'e') ADVANCE(67);
      END_STATE();
    case 24:
      if (lookahead == 'l') ADVANCE(26);
      END_STATE();
    case 25:
      if (lookahead == 'r') ADVANCE(27);
      END_STATE();
    case 26:
      if (lookahead == 's') ADVANCE(23);
      END_STATE();
    case 27:
      if (lookahead == 'u') ADVANCE(22);
      END_STATE();
    case 28:
      if (lookahead == '{') ADVANCE(19);
      END_STATE();
    case 29:
      if (lookahead == '}') ADVANCE(60);
      END_STATE();
    case 30:
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(30)
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(53);
      END_STATE();
    case 31:
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(31)
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'f')) ADVANCE(54);
      END_STATE();
    case 32:
      if (eof) ADVANCE(34);
      if (lookahead == '"') ADVANCE(61);
      if (lookahead == '\'') ADVANCE(47);
      if (lookahead == '0') ADVANCE(21);
      if (lookahead == 'f') ADVANCE(20);
      if (lookahead == 't') ADVANCE(25);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(32)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(43);
      END_STATE();
    case 33:
      if (eof) ADVANCE(34);
      if (lookahead == '"') ADVANCE(61);
      if (lookahead == '\'') ADVANCE(47);
      if (lookahead == '0') ADVANCE(21);
      if (lookahead == 'f') ADVANCE(35);
      if (lookahead == 't') ADVANCE(39);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(33)
      if (('1' <= lookahead && lookahead <= '9')) ADVANCE(43);
      if (('A' <= lookahead && lookahead <= 'D') ||
          ('F' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'd') ||
          ('g' <= lookahead && lookahead <= 'z')) ADVANCE(42);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(sym_suffix_no_e);
      if (lookahead == 'a') ADVANCE(38);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(42);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(sym_suffix_no_e);
      if (lookahead == 'e') ADVANCE(66);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(42);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(sym_suffix_no_e);
      if (lookahead == 'e') ADVANCE(68);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(42);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(sym_suffix_no_e);
      if (lookahead == 'l') ADVANCE(40);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(42);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(sym_suffix_no_e);
      if (lookahead == 'r') ADVANCE(41);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(42);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(sym_suffix_no_e);
      if (lookahead == 's') ADVANCE(37);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(42);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(sym_suffix_no_e);
      if (lookahead == 'u') ADVANCE(36);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(42);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(sym_suffix_no_e);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(42);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(sym_decimal_literal);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_') ADVANCE(43);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(sym_binary_literal);
      if (lookahead == '_') ADVANCE(44);
      if (lookahead == '0' ||
          lookahead == '1') ADVANCE(44);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(sym_octal_literal);
      if (lookahead == '_') ADVANCE(45);
      if (('0' <= lookahead && lookahead <= '7')) ADVANCE(45);
      END_STATE();
    case 46:
      ACCEPT_TOKEN(sym_hex_literal);
      if (lookahead == '_') ADVANCE(46);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(46);
      END_STATE();
    case 47:
      ACCEPT_TOKEN(anon_sym_SQUOTE);
      END_STATE();
    case 48:
      ACCEPT_TOKEN(aux_sym_character_literal_token1);
      END_STATE();
    case 49:
      ACCEPT_TOKEN(aux_sym_character_literal_token1);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(49);
      if (lookahead != 0 &&
          (lookahead < '\'' || ')' < lookahead) &&
          lookahead != '\\' &&
          lookahead != 'n' &&
          lookahead != 'r' &&
          lookahead != 't') ADVANCE(48);
      END_STATE();
    case 50:
      ACCEPT_TOKEN(anon_sym_BSLASH_SQUOTE);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(anon_sym_BSLASH_DQUOTE);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(anon_sym_BSLASHx);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(aux_sym_ascii_escape_token1);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(aux_sym_ascii_escape_token2);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(anon_sym_BSLASHn);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(anon_sym_BSLASHr);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(anon_sym_BSLASHt);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(anon_sym_BSLASH_BSLASH);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(anon_sym_BSLASH0);
      END_STATE();
    case 60:
      ACCEPT_TOKEN(aux_sym_unicode_escape_token1);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(aux_sym_string_literal_token1);
      END_STATE();
    case 63:
      ACCEPT_TOKEN(aux_sym_string_literal_token1);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(63);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '"' &&
          lookahead != '\\') ADVANCE(62);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(sym__string_continuation);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(anon_sym_true);
      END_STATE();
    case 66:
      ACCEPT_TOKEN(anon_sym_true);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(42);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(anon_sym_false);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(anon_sym_false);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(42);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 32},
  [2] = {.lex_state = 32},
  [3] = {.lex_state = 32},
  [4] = {.lex_state = 1},
  [5] = {.lex_state = 1},
  [6] = {.lex_state = 1},
  [7] = {.lex_state = 4},
  [8] = {.lex_state = 1},
  [9] = {.lex_state = 33},
  [10] = {.lex_state = 32},
  [11] = {.lex_state = 32},
  [12] = {.lex_state = 32},
  [13] = {.lex_state = 32},
  [14] = {.lex_state = 32},
  [15] = {.lex_state = 32},
  [16] = {.lex_state = 32},
  [17] = {.lex_state = 0},
  [18] = {.lex_state = 30},
  [19] = {.lex_state = 0},
  [20] = {.lex_state = 0},
  [21] = {.lex_state = 31},
  [22] = {.lex_state = 31},
  [23] = {.lex_state = 0},
  [24] = {.lex_state = 30},
  [25] = {.lex_state = 0},
  [26] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym_suffix_no_e] = ACTIONS(1),
    [sym_decimal_literal] = ACTIONS(1),
    [anon_sym_SQUOTE] = ACTIONS(1),
    [aux_sym_ascii_escape_token1] = ACTIONS(1),
    [aux_sym_ascii_escape_token2] = ACTIONS(1),
    [anon_sym_DQUOTE] = ACTIONS(1),
    [anon_sym_true] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(17),
    [sym__item] = STATE(2),
    [sym_expression] = STATE(2),
    [sym__primary_expression] = STATE(12),
    [sym_literal] = STATE(12),
    [sym_integer_literal] = STATE(13),
    [sym_character_literal] = STATE(13),
    [sym_string_literal] = STATE(13),
    [sym_boolean_literal] = STATE(13),
    [aux_sym_source_file_repeat1] = STATE(2),
    [ts_builtin_sym_end] = ACTIONS(3),
    [sym_decimal_literal] = ACTIONS(5),
    [sym_binary_literal] = ACTIONS(5),
    [sym_octal_literal] = ACTIONS(5),
    [sym_hex_literal] = ACTIONS(5),
    [anon_sym_SQUOTE] = ACTIONS(7),
    [anon_sym_DQUOTE] = ACTIONS(9),
    [anon_sym_true] = ACTIONS(11),
    [anon_sym_false] = ACTIONS(11),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 8,
    ACTIONS(7), 1,
      anon_sym_SQUOTE,
    ACTIONS(9), 1,
      anon_sym_DQUOTE,
    ACTIONS(13), 1,
      ts_builtin_sym_end,
    ACTIONS(11), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(12), 2,
      sym__primary_expression,
      sym_literal,
    STATE(3), 3,
      sym__item,
      sym_expression,
      aux_sym_source_file_repeat1,
    ACTIONS(5), 4,
      sym_decimal_literal,
      sym_binary_literal,
      sym_octal_literal,
      sym_hex_literal,
    STATE(13), 4,
      sym_integer_literal,
      sym_character_literal,
      sym_string_literal,
      sym_boolean_literal,
  [35] = 8,
    ACTIONS(15), 1,
      ts_builtin_sym_end,
    ACTIONS(20), 1,
      anon_sym_SQUOTE,
    ACTIONS(23), 1,
      anon_sym_DQUOTE,
    ACTIONS(26), 2,
      anon_sym_true,
      anon_sym_false,
    STATE(12), 2,
      sym__primary_expression,
      sym_literal,
    STATE(3), 3,
      sym__item,
      sym_expression,
      aux_sym_source_file_repeat1,
    ACTIONS(17), 4,
      sym_decimal_literal,
      sym_binary_literal,
      sym_octal_literal,
      sym_hex_literal,
    STATE(13), 4,
      sym_integer_literal,
      sym_character_literal,
      sym_string_literal,
      sym_boolean_literal,
  [70] = 5,
    ACTIONS(31), 1,
      anon_sym_BSLASHx,
    ACTIONS(33), 1,
      anon_sym_DQUOTE,
    ACTIONS(35), 1,
      aux_sym_string_literal_token1,
    STATE(6), 4,
      sym__quote_escape,
      sym__ascii_escape,
      sym__unicode_escape,
      aux_sym_string_literal_repeat1,
    ACTIONS(29), 9,
      anon_sym_BSLASH_SQUOTE,
      anon_sym_BSLASH_DQUOTE,
      anon_sym_BSLASHn,
      anon_sym_BSLASHr,
      anon_sym_BSLASHt,
      anon_sym_BSLASH_BSLASH,
      anon_sym_BSLASH0,
      aux_sym_unicode_escape_token1,
      sym__string_continuation,
  [97] = 5,
    ACTIONS(40), 1,
      anon_sym_BSLASHx,
    ACTIONS(43), 1,
      anon_sym_DQUOTE,
    ACTIONS(45), 1,
      aux_sym_string_literal_token1,
    STATE(5), 4,
      sym__quote_escape,
      sym__ascii_escape,
      sym__unicode_escape,
      aux_sym_string_literal_repeat1,
    ACTIONS(37), 9,
      anon_sym_BSLASH_SQUOTE,
      anon_sym_BSLASH_DQUOTE,
      anon_sym_BSLASHn,
      anon_sym_BSLASHr,
      anon_sym_BSLASHt,
      anon_sym_BSLASH_BSLASH,
      anon_sym_BSLASH0,
      aux_sym_unicode_escape_token1,
      sym__string_continuation,
  [124] = 5,
    ACTIONS(31), 1,
      anon_sym_BSLASHx,
    ACTIONS(50), 1,
      anon_sym_DQUOTE,
    ACTIONS(52), 1,
      aux_sym_string_literal_token1,
    STATE(5), 4,
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
  [151] = 6,
    ACTIONS(54), 1,
      aux_sym_character_literal_token1,
    ACTIONS(58), 1,
      anon_sym_BSLASHx,
    ACTIONS(62), 1,
      aux_sym_unicode_escape_token1,
    ACTIONS(56), 2,
      anon_sym_BSLASH_SQUOTE,
      anon_sym_BSLASH_DQUOTE,
    STATE(19), 3,
      sym_quote_escape,
      sym_ascii_escape,
      sym_unicode_escape,
    ACTIONS(60), 5,
      anon_sym_BSLASHn,
      anon_sym_BSLASHr,
      anon_sym_BSLASHt,
      anon_sym_BSLASH_BSLASH,
      anon_sym_BSLASH0,
  [177] = 2,
    ACTIONS(66), 1,
      aux_sym_string_literal_token1,
    ACTIONS(64), 11,
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
  [194] = 3,
    ACTIONS(70), 1,
      sym_suffix_no_e,
    ACTIONS(72), 2,
      anon_sym_true,
      anon_sym_false,
    ACTIONS(68), 7,
      ts_builtin_sym_end,
      sym_decimal_literal,
      sym_binary_literal,
      sym_octal_literal,
      sym_hex_literal,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
  [211] = 1,
    ACTIONS(74), 9,
      ts_builtin_sym_end,
      sym_decimal_literal,
      sym_binary_literal,
      sym_octal_literal,
      sym_hex_literal,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      anon_sym_true,
      anon_sym_false,
  [223] = 1,
    ACTIONS(76), 9,
      ts_builtin_sym_end,
      sym_decimal_literal,
      sym_binary_literal,
      sym_octal_literal,
      sym_hex_literal,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      anon_sym_true,
      anon_sym_false,
  [235] = 1,
    ACTIONS(78), 9,
      ts_builtin_sym_end,
      sym_decimal_literal,
      sym_binary_literal,
      sym_octal_literal,
      sym_hex_literal,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      anon_sym_true,
      anon_sym_false,
  [247] = 1,
    ACTIONS(80), 9,
      ts_builtin_sym_end,
      sym_decimal_literal,
      sym_binary_literal,
      sym_octal_literal,
      sym_hex_literal,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      anon_sym_true,
      anon_sym_false,
  [259] = 1,
    ACTIONS(82), 9,
      ts_builtin_sym_end,
      sym_decimal_literal,
      sym_binary_literal,
      sym_octal_literal,
      sym_hex_literal,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      anon_sym_true,
      anon_sym_false,
  [271] = 1,
    ACTIONS(84), 9,
      ts_builtin_sym_end,
      sym_decimal_literal,
      sym_binary_literal,
      sym_octal_literal,
      sym_hex_literal,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      anon_sym_true,
      anon_sym_false,
  [283] = 1,
    ACTIONS(86), 9,
      ts_builtin_sym_end,
      sym_decimal_literal,
      sym_binary_literal,
      sym_octal_literal,
      sym_hex_literal,
      anon_sym_SQUOTE,
      anon_sym_DQUOTE,
      anon_sym_true,
      anon_sym_false,
  [295] = 1,
    ACTIONS(88), 1,
      ts_builtin_sym_end,
  [299] = 1,
    ACTIONS(90), 1,
      aux_sym_ascii_escape_token1,
  [303] = 1,
    ACTIONS(92), 1,
      anon_sym_SQUOTE,
  [307] = 1,
    ACTIONS(94), 1,
      anon_sym_SQUOTE,
  [311] = 1,
    ACTIONS(96), 1,
      aux_sym_ascii_escape_token2,
  [315] = 1,
    ACTIONS(98), 1,
      aux_sym_ascii_escape_token2,
  [319] = 1,
    ACTIONS(100), 1,
      anon_sym_SQUOTE,
  [323] = 1,
    ACTIONS(102), 1,
      aux_sym_ascii_escape_token1,
  [327] = 1,
    ACTIONS(104), 1,
      anon_sym_SQUOTE,
  [331] = 1,
    ACTIONS(106), 1,
      anon_sym_SQUOTE,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 35,
  [SMALL_STATE(4)] = 70,
  [SMALL_STATE(5)] = 97,
  [SMALL_STATE(6)] = 124,
  [SMALL_STATE(7)] = 151,
  [SMALL_STATE(8)] = 177,
  [SMALL_STATE(9)] = 194,
  [SMALL_STATE(10)] = 211,
  [SMALL_STATE(11)] = 223,
  [SMALL_STATE(12)] = 235,
  [SMALL_STATE(13)] = 247,
  [SMALL_STATE(14)] = 259,
  [SMALL_STATE(15)] = 271,
  [SMALL_STATE(16)] = 283,
  [SMALL_STATE(17)] = 295,
  [SMALL_STATE(18)] = 299,
  [SMALL_STATE(19)] = 303,
  [SMALL_STATE(20)] = 307,
  [SMALL_STATE(21)] = 311,
  [SMALL_STATE(22)] = 315,
  [SMALL_STATE(23)] = 319,
  [SMALL_STATE(24)] = 323,
  [SMALL_STATE(25)] = 327,
  [SMALL_STATE(26)] = 331,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [13] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1),
  [15] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2),
  [17] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(9),
  [20] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(7),
  [23] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(4),
  [26] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(11),
  [29] = {.entry = {.count = 1, .reusable = false}}, SHIFT(6),
  [31] = {.entry = {.count = 1, .reusable = false}}, SHIFT(18),
  [33] = {.entry = {.count = 1, .reusable = false}}, SHIFT(10),
  [35] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [37] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_string_literal_repeat1, 2), SHIFT_REPEAT(5),
  [40] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_string_literal_repeat1, 2), SHIFT_REPEAT(18),
  [43] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_string_literal_repeat1, 2),
  [45] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_string_literal_repeat1, 2), SHIFT_REPEAT(5),
  [48] = {.entry = {.count = 1, .reusable = false}}, SHIFT(5),
  [50] = {.entry = {.count = 1, .reusable = false}}, SHIFT(15),
  [52] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [54] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [56] = {.entry = {.count = 1, .reusable = false}}, SHIFT(26),
  [58] = {.entry = {.count = 1, .reusable = false}}, SHIFT(24),
  [60] = {.entry = {.count = 1, .reusable = false}}, SHIFT(23),
  [62] = {.entry = {.count = 1, .reusable = false}}, SHIFT(20),
  [64] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__ascii_escape, 3),
  [66] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__ascii_escape, 3),
  [68] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_integer_literal, 1),
  [70] = {.entry = {.count = 1, .reusable = false}}, SHIFT(14),
  [72] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_integer_literal, 1),
  [74] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_literal, 2),
  [76] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_boolean_literal, 1),
  [78] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_expression, 1),
  [80] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_literal, 1),
  [82] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_integer_literal, 2, .production_id = 1),
  [84] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_literal, 3),
  [86] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_character_literal, 3),
  [88] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [90] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [92] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [94] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_unicode_escape, 1),
  [96] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [98] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [100] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_ascii_escape, 1),
  [102] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [104] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_ascii_escape, 3),
  [106] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_quote_escape, 1),
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
